// Headers
#include<windows.h>

// global function declartions
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

//global variable for fullScreen

DWORD dwStyle; // interally long ahe
WINDOWPLACEMENT wpPrev = { sizeof(WINDOWPLACEMENT) }; // initialization(inline)
bool gbFullScreen = false; // our variable g is for global, by default ti adhi fullscreen nahi 
HWND ghwnd = NULL;


//WinMain()

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int iCmdShow)
{
	//variable declarations
	WNDCLASSEX wndclass;
	HWND hwnd;
	MSG msg;
	TCHAR szAppName[] = TEXT("My Window2926");


	//code
	//initialization of WNDCLASSEX
	wndclass.cbSize = sizeof(WNDCLASSEX);
	wndclass.style = CS_HREDRAW | CS_VREDRAW;
	wndclass.cbClsExtra = 0;
	wndclass.cbWndExtra = 0;
	wndclass.lpfnWndProc = WndProc;
	wndclass.hInstance = hInstance;
	wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndclass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	wndclass.lpszClassName = szAppName;
	wndclass.lpszMenuName = NULL;
	wndclass.hIconSm = LoadIcon(NULL, IDI_APPLICATION);


	// register above class
	RegisterClassEx(&wndclass);

	//centering window
	int x = GetSystemMetrics(SM_CXSCREEN);
	int y = GetSystemMetrics(SM_CYSCREEN);


	// create window

	hwnd = CreateWindow(szAppName, 
		TEXT("My Window2926"),
		WS_OVERLAPPEDWINDOW,
		(x / 2) - (800 / 2),
		(y / 2) - (600 / 2),
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		NULL,
		NULL,
		hInstance,
		NULL);

	    ghwnd = hwnd; // for fullscreen(its not null now)

	ShowWindow(hwnd, iCmdShow);
	UpdateWindow(hwnd);


	// messgae loop
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);

	}

	return((int)msg.wParam);


}

LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)


{
	//function declare
	void ToggleFullScreen(void); 
	switch (iMsg)
		{
	       case WM_KEYDOWN:
		   {
			   switch (wParam)
			   {

			   case 0x46:    //x for hexa
			   case 0x66:   //f=66,F=46
				   ToggleFullScreen(); // calling Func.
				   break;
			   default:
				   break;
			   }
			   break;  // wm keydown break
			}
		   switch (iMsg)
		   {
		   case WM_DESTROY:
			   PostQuitMessage(0);
			   break;
		   }
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
		dwStyle = GetWindowLong(ghwnd,GWL_STYLE); //getwindowlong:get style,get from OS
		if (dwStyle & WS_OVERLAPPEDWINDOW);
		{
			if (GetWindowPlacement(ghwnd, &wpPrev) && GetMonitorInfo(MonitorFromWindow(ghwnd, MONITORINFOF_PRIMARY), &mi))// calling internally
			{
				SetWindowLong(ghwnd, GWL_STYLE, dwStyle & ~WS_OVERLAPPEDWINDOW); //call
				SetWindowPos(ghwnd,HWND_TOP, mi.rcMonitor.left, mi.rcMonitor.top, mi.rcMonitor.right - mi.rcMonitor.left, mi.rcMonitor.bottom - mi.rcMonitor.top,
					SWP_NOZORDER | SWP_FRAMECHANGED); //call
			}
		}
		ShowCursor(FALSE);//SDK wala false
		gbFullScreen=true;

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

