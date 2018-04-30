#include <Windows.h> 
#include "resource.h"
#include <vector>
#include <conio.h>

#define VEC_SIZE  6
#define ID_CAT1   102
#define ID_DOG1   109
#define ID_STATIC 1003

#define ID_START  1001
#define ID_FINISH 1002 

#define ID_DOGS   3000
#define ID_CATS   3001
#define ID_FIRST  3002
#define ID_SLOW   3003


std::vector<HBITMAP> vecHbitmapDogs;
std::vector<HBITMAP> vecHbitmapCats;


void ImageCreation(HWND hPicture,
	               const std::vector<HBITMAP>& vecHbitmap){
	// отпровляем сообщение на перерисовку bitmap
	SendMessage(hPicture, STM_SETIMAGE, (WPARAM)IMAGE_BITMAP,
		(LPARAM)vecHbitmap.at(rand() % VEC_SIZE));
}


bool ChoiceActionImageCreation(HWND hPicture ,HWND hWnd,
	                           HWND hDogs, HWND hCats,
	                           HWND scrollingSpeed){
	if (SendMessage(scrollingSpeed, BM_GETSTATE, 0, 0)) {
		if (SendMessage(hDogs, BM_GETCHECK, 0, 0) &&
			SendMessage(hCats, BM_GETCHECK, 0, 0)) {
			if (rand() % 2) {
				ImageCreation(hPicture,vecHbitmapCats);
				return true;
			}
			else {
				ImageCreation(hPicture,vecHbitmapDogs);
				return true;
			}
		}
		else if (SendMessage(hDogs, BM_GETCHECK, 0, 0)) {
			ImageCreation(hPicture ,vecHbitmapDogs);
			return true;
		}
		else if (SendMessage(GetDlgItem(hWnd, ID_CATS),
			BM_GETCHECK, 0, 0)) {
			ImageCreation(hPicture ,vecHbitmapCats);
			return true;
		}
	}
	return true;
}


BOOL CALLBACK MainDlgProc(HWND hWnd, UINT uMsg,
	                      WPARAM wParam, LPARAM lParam) 
{
	static HWND hDogs, hCats, hFirst, hSlow,
		           hStar, hFinish, hPicture;
	static unsigned int SCROLING_SPEED_FIRST,
		                 SCROLING_SPEED_SLOW;
	switch (uMsg)
	{
	case WM_INITDIALOG:
		SCROLING_SPEED_FIRST = 500;
        SCROLING_SPEED_SLOW  = 2000;
		hPicture = GetDlgItem(hWnd, ID_STATIC);
		hStar    = GetDlgItem(hWnd, ID_START);
		hFinish  = GetDlgItem(hWnd, ID_FINISH);
		hDogs = CreateWindow(L"BUTTON", L"dogs",
			WS_CHILD | WS_VISIBLE | BS_AUTOCHECKBOX,
			20, 20, 80, 30, hWnd, (HMENU)ID_DOGS,
			GetModuleHandle(NULL), NULL);

		hCats = CreateWindow(L"BUTTON", L"cats",
			WS_CHILD | WS_VISIBLE | BS_AUTOCHECKBOX,
			20, 50, 80, 30, hWnd, (HMENU)ID_CATS,
			GetModuleHandle(NULL), NULL);

		hFirst = CreateWindow(L"BUTTON", L"first",
			WS_CHILD | WS_VISIBLE | BS_AUTORADIOBUTTON,
			20, 150, 80, 30, hWnd, (HMENU)ID_FIRST,
			GetModuleHandle(NULL), NULL);

		hSlow = CreateWindow(L"BUTTON", L"slow",
			WS_CHILD | WS_VISIBLE | BS_AUTORADIOBUTTON,
			20, 180, 80, 30, hWnd, (HMENU)ID_SLOW,
			GetModuleHandle(NULL), NULL);
		// вектор кошек
		for (int i(ID_CAT1); i <= ID_CAT1 + VEC_SIZE; i++) {
			vecHbitmapCats.push_back(LoadBitmap(GetModuleHandle(NULL),
				MAKEINTRESOURCE(i)));
		}
		// вектор собак
		for (int i(ID_DOG1); i < ID_DOG1 + VEC_SIZE; i++) {
			vecHbitmapDogs.push_back(LoadBitmap(GetModuleHandle(NULL),
				MAKEINTRESOURCE(i)));
		}
		// почемуто не видит инициализацию
		SetTimer(hWnd, 1, SCROLING_SPEED_FIRST, NULL);
		SetTimer(hWnd, 2, 2400, NULL);
		return true;
	case WM_COMMAND:
		switch (wParam)
		{
		case ID_START:
			if (SendMessage(hStar, BM_GETSTATE, 0, 0)) {
				SendMessage(hStar, BM_SETSTATE, TRUE, 0);
				return true;
			}
		case ID_FINISH:
			if (SendMessage(hFinish, BM_GETSTATE, 0, 0)) {
				SendMessage(hStar, BM_SETSTATE, FALSE, 0);
				return true;
			}
		}
		return true;
	case WM_TIMER:
		if (SendMessage(hStar, BM_GETSTATE, 0, 0)) {
			switch (wParam)
			 {
			  case(1): ChoiceActionImageCreation(hPicture, hWnd, hDogs, hCats, hFirst);
			     return true;
			  case(2): ChoiceActionImageCreation(hPicture, hWnd, hDogs, hCats,  hSlow);
				 return true;
		     }
		    }
			return true;
	case WM_CLOSE:
			KillTimer(hWnd, 1);
			KillTimer(hWnd, 2);
			DestroyWindow(hWnd);
			PostQuitMessage(0);
			return true;
		}
	return false;
	}
	

INT WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR
	cmdArgs, int nCmdShow) {
	HWND hWnd = CreateDialog(hInst, MAKEINTRESOURCE(101), NULL,
		                                 (DLGPROC)MainDlgProc);
	ShowWindow(hWnd, 1);
	MSG msg;
	while (GetMessage(&msg, 0, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return (INT)msg.wParam;
}
