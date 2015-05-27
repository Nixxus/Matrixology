//Test Main file
#include <conio.h>
#include "D3D.h"
using namespace std;

#define KEY_UP 22

int main()
{
	HWND hWnd = NULL;

	InitD3D(hWnd);
	while (_getch() != KEY_UP)
	{
		RenderFrame();
	}
	return 0;
}