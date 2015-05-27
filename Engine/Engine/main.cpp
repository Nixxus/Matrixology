//Test Main file
#include <conio.h>
#include "D3D.h"
#include "Window.h"
using namespace std;

int WINAPI WinMain(HINSTANCE hInstance,
                   HINSTANCE hPrevInstance,
                   LPSTR lpCmdLine,
                   int nCmdShow)
{
	//Create Window
	HWND hWnd = NewWindow(hInstance, hPrevInstance, lpCmdLine, nCmdShow);

	//Start Direct3D
	InitD3D(hWnd);

	MSG msg; // windows message storage

	//Wait for the next message then store in msg
	while (GetMessage(&msg, NULL, 0, 0))
	{
		//Translate message to correct format
		TranslateMessage(&msg);

		//Send Message to message Handler
		DispatchMessage(&msg);

		//Render a new D3D frame
		RenderFrame();
	}

	return msg.wParam;
}