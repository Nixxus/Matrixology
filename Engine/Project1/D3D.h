#ifndef D3DH
#define D3DH

//Direct3D Code based off a tutorial at http://www.directxtutorial.com
// include Windows and DirectX headers
#include <Windows.h>
#include <windowsx.h>
#include <D3D11.h>
#include <D3DX11.h>
#include <D3DX10.h>

//include Direct3D Libs
#pragma comment (lib, "d3d11.lib")
#pragma comment (lib, "d3dx11.lib")
#pragma comment (lib, "d3dx10.lib")

//function prototypes
void InitD3D(HWND hWnd);  //Setup and Initilaization of Direct3D
void CleanD3D(void);	  //closes Direct3D and Releases Memory
void RenderFrame(void);	  //Renders the scene

//WindowProc function prototype
LRESULT CALLBACK WindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lparam);

#endif