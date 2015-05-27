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

	//Set Client size and adjust window Size
	RECT wr = {0, 0, 800, 800}; // Set Size
	AdjustWindowRect (&wr, WS_OVERLAPPEDWINDOW, FALSE); // adjust size

	//createWindow and use result as handle
	hWnd = CreateWindowEx(NULL,
						  "WindowClass1",		//Name of Window Class
						  "Engine Window",		//Window Title
						  WS_OVERLAPPEDWINDOW,	//Window Style
						  100,					//X position of window
						  100,					//Y position of window
						  wr.right - wr.left,	//Width of window
						  wr.bottom - wr.top,	//Height of Window
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