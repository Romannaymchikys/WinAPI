// рисуем окно
// полосы скролинга
// немодальное - может весеть отдельно от гланого
// модальное
#include <Windows.h> 
// CALBACK - только вызывается операционное системой


int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int);
//hwnd - каму пришло сообщениеб  .message .wParam 
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam){
	HDC hdс;// ссылка на поверхность
	PAINTSTRUCT ps;
	RECT rect;
	switch (message){
	case WM_PAINT:
		hdс = BeginPaint(hWnd, &ps);
	    GetClientRect(hWnd, &rect);
		// -1 длинна автоматтический;
	    DrawText(hdс, L"Hello, Step", -1, &rect, DT_CENTER |
			                                 DT_SINGLELINE | DT_VCENTER);
	    EndPaint(hWnd, &ps);
	    break;
    case WM_DESTROY:PostQuitMessage(0);
	    break;
	default:return DefWindowProc(hWnd, message, wParam, lParam); }
	return 0;
}
// факультотивно
// гланое меню
//инициализации
//HINSTANCE hInstance - индефикатор окна
//
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{   //лутше имена занести в переменную
	//------------------------------------------------------------------
	LPWSTR szClassName = L"MyWindowClass"; // название класса
	LPWSTR szTitleName = L"Myfirst window"; // надпись в оглавление окна
	//--------------------------------------------------
	WNDCLASSEX wndclass; // 
	wndclass.cbSize = sizeof(wndclass);
	wndclass.lpszClassName = szClassName;
	wndclass.style = CS_HREDRAW | CS_VREDRAW;// РАЗМЕРЫ ОКНА //CS_DBLCLKS - двойной счелчок мыши 
	wndclass.lpfnWndProc = WndProc;// имя
	wndclass.cbClsExtra = 0;
	wndclass.cbWndExtra = 0;
	wndclass.hInstance = hInstance; // индефекатор
	// берем курсор из виндовс NULL - откудаб . IDC_ARROW- кaкой
	wndclass.hCursor = LoadCursor(NULL, IDC_NO);
	//иконка в вернем левом углу
	// берем иконка из виндовс NULL - откудаб . IDI_APPLICATION- кaкой
	wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	// устанавливаем фон
	wndclass.hbrBackground = (HBRUSH)GetStockObject(WHITE_PEN);
	// или CreateSolidBrush(RGB(0,0,0));
	// дескриптор меню
	wndclass.lpszMenuName = NULL;
	//иконка в меню
	wndclass.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
	if (!RegisterClassEx(&wndclass)) {
		// MessageBox - окно сообщение, 
		MessageBox(NULL, L"1", L"Eroor", MB_OK);
		return false;
	}
	HWND hWnd = CreateWindowEx(
	 // стиль окна если есть  CreateWindowEx конец Ex - расширенный стиль экзмпляра окна
		// WS_EX основная для этого
		WS_EX_TOPMOST,
		//название класса
		szClassName,
		//заголовак окна
		szTitleName,
		// стиль
		WS_OVERLAPPEDWINDOW,
		// кординаты от верхнего левого угла 0 0 и размеры окна 150 150 в пикселях
		800, 500, 150, 150,
		// четвертый пораметор с окна это дескриптор радителя
		// родитель если нет NULL
		NULL,
		NULL,
		// главное меню
		hInstance,
		NULL);
	if (!hWnd) {
		// Null - родитель 
		MessageBox(NULL, L"1", L"Eroor", MB_OK);
		return false;
	}
	//MessageBox(NULL, L"1", L"Eroor", MB_YESNO | MB_ICONWARNING );
	// рисуем окно
	ShowWindow(hWnd, SW_NORMAL);
	UpdateWindow(hWnd);	

	MSG msg;
	// 0 0 если хотим все обрабатывать
	while (GetMessage(&msg, NULL, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);

	}
	return msg.wParam;
}

