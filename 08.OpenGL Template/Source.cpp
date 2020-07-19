// Headers

#include"window.h"
#include<windows.h>
#include<stdio.h>



//new macros
#define MY_ICON 2926
#define WIN_WIDTH 800
#define WIN_HEIGHT 600


// global function declartions

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
FILE* gpfile = NULL;

//global variable for fullScreen

DWORD dwStyle; // interally long ahe
WINDOWPLACEMENT wpPrev = { sizeof(WINDOWPLACEMENT) }; // initialization(inline)
bool gbFullScreen = false; // our variable g is for global, by default ti adhi fullscreen nahi
bool gbActiveWindow = false;

HWND ghwnd = NULL;




//WinMain()

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int iCmdShow)
{
	//function

	void initialize(void);
	void display(void);

	//local variable declarations
	WNDCLASSEX wndclass;
	HWND hwnd;
	MSG msg;
	TCHAR szAppName[] = TEXT("My Window2926");
	bool BDone = false;
	// file IO
	if (fopen_s(&gpfile, "coder.txt", "w") != 0)
	{
		MessageBox(NULL, TEXT("can not create desired file"), TEXT("error"), MB_OK);
		exit(0);

	}



	//code
	//initialization of WNDCLASSEX
	wndclass.cbSize = sizeof(WNDCLASSEX);
	wndclass.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
	wndclass.cbClsExtra = 0;
	wndclass.cbWndExtra = 0;
	wndclass.lpfnWndProc = WndProc;
	wndclass.hInstance = hInstance;
	wndclass.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(MY_ICON));
	wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndclass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	wndclass.lpszClassName = szAppName;
	wndclass.lpszMenuName = NULL;
	wndclass.hIconSm = LoadIcon(hInstance, MAKEINTRESOURCE(MY_ICON));


	// register above class
	RegisterClassEx(&wndclass);

	//centering window
	int x = GetSystemMetrics(SM_CXSCREEN);
	int y = GetSystemMetrics(SM_CYSCREEN);


	// create window

	hwnd = CreateWindowEx(WS_EX_APPWINDOW, szAppName,
		TEXT("My Window2926"),
		WS_OVERLAPPEDWINDOW | WS_CLIPCHILDREN | WS_CLIPSIBLINGS | WS_VISIBLE,
		(x / 2) - (800 / 2),
		(y / 2) - (600 / 2),
		WIN_WIDTH,
		WIN_HEIGHT,
		NULL,
		NULL,
		hInstance,
		NULL);

	ghwnd = hwnd; // for fullscreen(its not null now)

	initialize();

	ShowWindow(hwnd, iCmdShow);

	SetForegroundWindow(hwnd);
	SetFocus(hwnd);


	// messgae loop


	while (BDone == false)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			if (msg.message == WM_QUIT)
				BDone = true;
			else
			{

				TranslateMessage(&msg);
				DispatchMessage(&msg);

			}

		}
		else
		{
			if (gbActiveWindow == true)
			{
				//call updatefuntion


				//call dispaly funtion
				display();
			}

		}
	}




	return((int)msg.wParam);

}

LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)


{
	//function declare
	void ToggleFullScreen(void);
	void Resize(int, int);
	void Uninitialize(void);

	switch (iMsg)
	{
	case WM_SETFOCUS:
		gbActiveWindow = true;
		break;
	case WM_KILLFOCUS:
		gbActiveWindow = false;
		break;
	case WM_ERASEBKGND:
		return(0);
	case WM_SIZE:
		Resize(LOWORD(lParam), HIWORD(lParam));
		break;
	case WM_KEYDOWN:

		switch (wParam)
		{
		case VK_ESCAPE:
			DestroyWindow(hwnd);
			break;

		case 0x46:    //x for hexa
		case 0x66:   //f=66,F=46
			ToggleFullScreen(); // calling Func.
			break;
		default:
			break;
		}
		break;

	case WM_CREATE:
		fprintf(gpfile, "India is my country.\n");
		break;

	case WM_CLOSE:
		DestroyWindow(hwnd);
		break;



	case WM_DESTROY:
		fprintf(gpfile, "Jay Hind\n");

		Uninitialize();
		PostQuitMessage(0);
		break;

	}
	return(DefWindowProc(hwnd, iMsg, wParam, lParam));

}


// Function Declartion

void ToggleFullScreen(void)

{
	//local Variable declartion
	MONITORINFO mi = { sizeof(MONITORINFO) };

	//code
	if (gbFullScreen == false)
	{
		dwStyle = GetWindowLong(ghwnd, GWL_STYLE); //getwindowlong:get style,get from OS
		if (dwStyle & WS_OVERLAPPEDWINDOW);
		{
			if (GetWindowPlacement(ghwnd, &wpPrev) && GetMonitorInfo(MonitorFromWindow(ghwnd, MONITORINFOF_PRIMARY), &mi))// calling internally
			{
				SetWindowLong(ghwnd, GWL_STYLE, dwStyle & ~WS_OVERLAPPEDWINDOW); //call
				SetWindowPos(ghwnd, HWND_TOP, mi.rcMonitor.left, mi.rcMonitor.top, mi.rcMonitor.right - mi.rcMonitor.left, mi.rcMonitor.bottom - mi.rcMonitor.top,
					SWP_NOZORDER | SWP_FRAMECHANGED); //call
			}
		}
		ShowCursor(FALSE);//SDK wala false
		gbFullScreen = true;

	}
	else
	{
		SetWindowLong(ghwnd, GWL_STYLE, dwStyle | WS_OVERLAPPEDWINDOW);
		SetWindowPlacement(ghwnd, &wpPrev);
		SetWindowPos(ghwnd, HWND_TOP, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE | SWP_NOOWNERZORDER | SWP_NOZORDER | SWP_FRAMECHANGED);
		ShowCursor(TRUE);
		gbFullScreen = FALSE;
	}


}

void initialize(void)
{
	//funtion declare
	void Resize(int, int);

	// variable declaration

	//code

	Resize(WIN_WIDTH, WIN_HEIGHT);      //warm up resize


}
void Resize(int width, int height)
{
	//code
	if (height == 0)
		height = 1;
}

void display(void)
{
	//code


}

void Uninitialize(void)
{
	if (gpfile)
	{
		fclose(gpfile);
		gpfile = NULL;
	}


	gpfile = NULL;

}
