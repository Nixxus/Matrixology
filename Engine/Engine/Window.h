#ifndef WINDOWH
#define WINDOWH

//include windows header files
#include <Windows.h>
#include <windowsx.h>

//Windowproc function prototype
LRESULT CALLBACK WindowProc(HWND hWnd,
							UINT message,
							WPARAM wParam,
							LPARAM lParam);

HWND NewWindow (HINSTANCE hInstance,
			   HINSTANCE hPrevInstance,
			   LPSTR lpCmdLine,
			   int nCmdShow);

#endif