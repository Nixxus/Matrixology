#include "Window.h"

HWND NewWindow (HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	//Window Handle
	HWND hWnd;
	//Struct for window class info
	WNDCLASSEX wc;

	//clear window class
	ZeroMemory(&wc, sizeof(WNDCLASSEX));

	//fill struct
	wc.cbSize = sizeof(WNDCLASSEX);
	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.lpfnWndProc = WindowProc;
	wc.hInstance = hInstance;
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
	wc.lpszClassName = "WindowClass1";

	//Register Window Class
	RegisterClassEx(&wc);

	//createWindow and use result as handle
	hWnd = CreateWindowEx(NULL,
						  "WindowClass1",		//Name of Window Class
						  "Engine Window",		//Window Title
						  WS_OVERLAPPEDWINDOW,	//Window Style
						  300,					//X position of window
						  300,					//Y position of window
						  800,					//Width of window
						  800,					//Height of Window
						  NULL,					//Parent Window
						  NULL,					//Window Menus
						  hInstance,			//Application handle
						  NULL);

	//Display Window
	ShowWindow(hWnd, nCmdShow);
	return hWnd;
}

//Message Handler
LRESULT CALLBACK WindowProc (HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch(message)
	{
	case WM_DESTROY:
		{
			//Close application
			PostQuitMessage(0);
			return 0;
		}break;
	}

	//Handle other messages
	return DefWindowProc (hWnd, message, wParam, lParam);
}