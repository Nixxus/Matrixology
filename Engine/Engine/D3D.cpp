#include "D3D.h"

//Globals
IDXGISwapChain *swapChain;			//Pointer to the swapchain interface
ID3D11Device *dev;					//Pointer to the Direct3D Device interface
ID3D11DeviceContext *devcon;		//Pointer to the Direct3D Device context
ID3D11RenderTargetView *backBuffer;

//Launch Direct3D
void InitD3D(HWND hWnd)
{
	//Create a Struct to hold swapchain information
	DXGI_SWAP_CHAIN_DESC scd;

	//clear out the struct ready for use
	ZeroMemory(&scd, sizeof(DXGI_SWAP_CHAIN_DESC));

	// Fill the Swap Chain description Struct
	scd.BufferCount = 1;									//single backbuffer
	scd.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;		//use 32-bit colour
	scd.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;		//How the swap chain is to be used
	scd.OutputWindow = hWnd;								//The Window to be used
	scd.SampleDesc.Count = 4;								//How many multisamples
	scd.Windowed = true;									// Windowed/Fullscreen

	//Create a device, Device context and Swapchain using the information in scd struct
	D3D11CreateDeviceAndSwapChain(NULL,
                                  D3D_DRIVER_TYPE_HARDWARE,
                                  NULL,
                                  NULL,
                                  NULL,
                                  NULL,
                                  D3D11_SDK_VERSION,
                                  &scd,
                                  &swapChain,
                                  &dev,
                                  NULL,
                                  &devcon);

	//Get address of the back buffer
	ID3D11Texture2D *pBackBuffer = NULL;
	swapChain->GetBuffer(0,__uuidof(ID3D11Texture2D), (LPVOID*)&pBackBuffer);

	//Use the backbuffer address to create a render target
	dev->CreateRenderTargetView(pBackBuffer, NULL, &backBuffer);
	pBackBuffer->Release();

	//set the render target as the back buffer
	devcon->OMSetRenderTargets(1, &backBuffer, NULL);

	//Set Viewport
	D3D11_VIEWPORT viewport;
	ZeroMemory(&viewport, sizeof(D3D11_VIEWPORT));

	viewport.TopLeftX = 0;
	viewport.TopLeftY = 0;
	viewport.Width = 800;
	viewport.Height = 800;

	devcon->RSSetViewports(1, &viewport);
}

void CleanD3D()
{
	//Close and release all COM Objects
	swapChain->Release();
	backBuffer->Release();
	dev->Release();
	devcon->Release();
}

void RenderFrame(void)
{
	//clear the back buffer to a colour (blue)
	devcon->ClearRenderTargetView(backBuffer, D3DXCOLOR(0.0f, 0.2f, 0.4f, 10.f));

	//Do 3D rendering on the backbuffer here

	//switch the back and front buffer
	swapChain->Present(0,0);

}