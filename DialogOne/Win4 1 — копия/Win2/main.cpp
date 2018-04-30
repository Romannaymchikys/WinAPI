#include <Windows.h> 
#include "resource.h"

#define IDC_RICHEDIT21 1001
BOOL CALLBACK MainDlgProc(HWND hWnd, UINT uMsg,
	WPARAM wParam, LPARAM lParam)
{
	RECT rect;
	static HWND hEdit;
	switch (uMsg)
	{
	case WM_INITDIALOG:
		hEdit = GetDlgItem(hWnd, IDC_RICHEDIT21);
		
	case WM_SIZE:
		GetClientRect(hWnd, &rect);
		MoveWindow(hEdit, 0, 0, rect.right, rect.bottom, true);
		return true;
	case WM_COMMAND:

		return true;
	case WM_TIMER:

		return true;
	case WM_CLOSE:
		DestroyWindow(hWnd);
		PostQuitMessage(0);
		return true;
	}
	return false;
}
	

INT WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR cmdArgs, int nCmdShow) {
	LoadLibrary(L"riched32.dll");
	// втрое окно 
	HWND hWnd = CreateDialog(hInst, MAKEINTRESOURCE(101), NULL,
		                                 (DLGPROC)MainDlgProc);
	ShowWindow(hWnd, 1);
	MSG msg;
	while (GetMessage(&msg, 0, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return msg.wParam;
}
