#include <windows.h>
#include <tchar.h>
#define WIDTH 500
#define HEGHT 400
#include "resource.h"
#include <time.h>
#include <stdlib.h>
//srand(time(NULL));

#define CALCULATION_STEP(value)	++j; ++i; sum += i;                   \
                            if (value) {                              \
	                           if (i % 2) { step = -1 * (range_w); }  \
	                           else { step = 0; }                     \
                               }                                      \
                            else {                                    \
	                           if (i % 2) { step = 0; }               \
	                           else { step = -1 * (range_h); }        \
                              }                                       \

LRESULT CALLBACK WndProc(HWND hWnd, UINT uMessage, WPARAM wParam, LPARAM lParam)
{
	HDC hdс;// ссылка на поверхность приложение
	PAINTSTRUCT ps;// структура для рисования
	RECT rect;// структура содержит координаты окна 
	TEXTMETRIC tm;// Структура с настройками шрифта
	// static для того чтобы int des_x от запуска к запуску сохраняла свои значение
	//KillTimer(hWnd, 1);
	static int des_x;
	static int des_y;
	
	static int step_vertical = 0;
	static int step_horizontal = 0;
	static bool selector = false;
	static int step = 0;
	static size_t i(2), sum(3), j(1);
	static int range_h(0);
	static int range_w(0);
	//создание ссылки на новое  окно
	HWND hST;
	switch (uMessage)
	{
		//SystemParametersInfo создает структуру  каардинат
	case WM_CREATE: SystemParametersInfo(SPI_GETWORKAREA, 0, &rect, 0);
		des_x = rect.right;
		des_y = rect.bottom;
		
		hST = CreateWindowEx(NULL, TEXT("STATIC"), TEXT("Hello"),
			WS_CHILD | WS_VISIBLE, 100, 20, 100, 40, hWnd, NULL,
			GetModuleHandle(NULL), NULL);
		SetTimer(hWnd, 1, 10, NULL);
		SetTimer(hWnd, 2, 10, NULL);
		range_h = rect.bottom - HEGHT;
		range_w = rect.right  - WIDTH;
		step_horizontal = rect.right - WIDTH;
		// перемещать в правый верхний угол если нажат интер
		//SendMassage(hwnd, WM_CLOSE, 0, 0);
		//break;

	case WM_KEYDOWN:
		if (wParam == VK_RETURN) {
			MoveWindow(hWnd, des_x - WIDTH, 0, WIDTH, HEGHT, true);
			selector = true;
		}
    
	case WM_TIMER: 
	// проверять wParam
		switch (wParam)
		{
		case(1):
			SetClassLong(hWnd, GCL_HBRBACKGROUND,
				(LONG)CreateSolidBrush(RGB(rand() % 100, rand() % 100, rand() % 100)));
			InvalidateRect(hWnd, NULL, true);
			break;
		case(2):
		{
			if (selector) {
				++step;
				if (j % 2) {
					//  мы идем или вверх или в низ
					if (range_h != abs(step) && abs(step) != 0) {
						step_vertical = abs(step);
					}
					else {
						CALCULATION_STEP(!(sum % 2));
					}
				}
				else {
					if (range_w != abs(step) && abs(step) != 0) {
						step_horizontal = abs(step);
					}
					else {
						CALCULATION_STEP(sum % 2);
					}

				}
				SystemParametersInfo(SPI_GETWORKAREA, 0, &rect, 0);
				SetClassLong(hWnd, GCL_HBRBACKGROUND,
					MoveWindow(hWnd, step_horizontal, step_vertical, WIDTH, HEGHT, true));
				InvalidateRect(hWnd, NULL, true);
			}
			break;
		default: break;
		}
	}
	case WM_PAINT:
		hdс = BeginPaint(hWnd, &ps); // получение hdc
		GetClientRect(hWnd, &rect);  // получение координат
									 // Рисование
		EndPaint(hWnd, &ps); // освобождение hdc
		break;

	case WM_SYSKEYDOWN:
		if (wParam == VK_DOWN) {
			ShowWindow(hWnd, SW_SHOWMAXIMIZED);
		}
		else if (wParam == VK_UP) {
			ShowWindow(hWnd, SW_SHOWMINIMIZED);
		}
		else if (wParam == VK_LEFT || wParam == VK_RIGHT) {
			ShowWindow(hWnd, SW_NORMAL);
		}
		break;
	case WM_CHAR:
		if (wParam == 'Q' || wParam == 'q') {
			MessageBox(NULL, TEXT("Sorry... :("), TEXT("Error"), MB_OK | MB_ICONERROR);
		}
	case WM_LBUTTONDBLCLK:
		SetClassLong(hWnd, GCL_HCURSOR, (LONG)LoadCursor(GetModuleHandle(NULL), MAKEINTRESOURCE(102)));//
		break;
	case WM_LBUTTONDOWN:
		SetClassLong(hWnd, GCL_HCURSOR, (LONG)LoadCursor(NULL, IDC_ARROW));// меняем курсор на стандартный
		break;
	case WM_CLOSE:
		if (MessageBox(hWnd, TEXT("Вы действительно хотите завершить работу приложения?"),
			TEXT("Информация"), MB_YESNO) == IDYES) {
			DestroyWindow(hWnd);
		}
		break;
	
	case WM_DESTROY:
		KillTimer(hWnd, 1);
		KillTimer(hWnd, 2);
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, uMessage, wParam, lParam);
	}
	return 0;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInst, LPSTR lpszCmdLine, int nCmdShow)
{
	
	WNDCLASSEX wnd;

	wnd.cbSize = sizeof(wnd);
	wnd.lpszClassName = TEXT("Window");
	wnd.style = CS_HREDRAW | CS_VREDRAW;
	wnd.lpfnWndProc = WndProc;
	wnd.cbClsExtra = 0;
	wnd.cbWndExtra = 0;
	wnd.hInstance = hInstance;
	//hInstance - 
	wnd.hCursor = LoadCursor(hInstance, MAKEINTRESOURCE(102));
	wnd.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_ICON1));// IDI_ICON1
	wnd.hbrBackground = (HBRUSH)GetStockObject(WHITE_PEN);//фон
	wnd.lpszMenuName = NULL;
	wnd.hIconSm = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_ICON1));

	if (!RegisterClassEx(&wnd)) {
		MessageBox(NULL, TEXT("Sorry :("), TEXT("Error"), MB_OK | MB_ICONERROR);
		return 0;
	}
	// функция создание окна
	HWND hWnd = CreateWindowEx(WS_EX_WINDOWEDGE,
		TEXT("Window"),
		TEXT("Hello"),
		WS_OVERLAPPEDWINDOW ^ WS_MINIMIZEBOX ^ WS_MAXIMIZEBOX,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		WIDTH,
		HEGHT,
		NULL, 
		NULL,
		hInstance,
		NULL);// HWND_DESKTOP

	if (!hWnd) {
		MessageBox(NULL, TEXT("Sorry... :("), TEXT("Error"), MB_OK | MB_ICONERROR);
		return 0;
	}

	ShowWindow(hWnd, 1);
	UpdateWindow(hWnd);

	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return msg.wParam;
}

// АКСЕЛЕРАТОР - добавление в проект тоблицы горячих клавиш
// битмап - картинка в приложении
// 
// -1 - оперативка длинну строки определяет сома
/*BOOL MoveWindow(

HWND hWnd,    // дескриптор окна
int x,        // позиция по горизонтали
int y,        // позиция по вертикали
int nWidth,   // ширина
int nHeight,  // высота
BOOL bRepaint // флажок перекраски


BOOL GetWindowRect(
HWND hWnd,     // дескриптор окна
LPRECT lpRect  // адрес структуры для координат окна
);
);*/