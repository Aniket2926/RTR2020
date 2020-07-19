// Headers
#include<windows.h>

// global function declartions
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);


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

	int x = GetSystemMetrics(SM_CXSCREEN);
	int y = GetSystemMetrics(SM_CYSCREEN);


	// create window
	hwnd = CreateWindow(szAppName,
		TEXT("My Window2926"),
		WS_OVERLAPPEDWINDOW,
		(x / 2) - (800 / 2),
		(y / 2) - (600 / 2),
		800,
		600,
		NULL,
		NULL,
		hInstance,
		NULL);


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
	// variable Declarations for wm_paint

	HDC hdc;                         //Graphic card cha Os cha messenger 
	PAINTSTRUCT PS;                 // client rate cha smallest squre is colored by paintstruct
	RECT rc;                       // sdk rectangle draw karnara struct 
	TCHAR str[] = TEXT("Hello Aniket !!!");  // string 

	// code

	switch (iMsg)
	{

	case WM_PAINT:     // Window sathi 08 cases like move, drag etc  I want wm_paint send msg or post msg

		GetClientRect(hwnd, &rc);          // OS i need client rectangle hwnd and rc are parameter 
		
		hdc = BeginPaint(hwnd, &PS);      // I want to painting karaicha a I want a painting speaclist so call BeingPaint then for which window hwnd and smallest ps


		SetBkColor(hdc, RGB(0, 0, 0));    // Background color RGB is speacilist

		SetTextColor(hdc, RGB(0, 255, 255)); //text color

		DrawText(hdc, str, -1, &rc, DT_SINGLELINE|DT_CENTER|DT_VCENTER); // proper text draw kar, -1 means draw whole text centering of string or text 
		
		EndPaint(hwnd, &PS); // end of my painting hwnd 
		break;


	case WM_DESTROY:

		PostQuitMessage(0);
		break;

	}
	return(DefWindowProc(hwnd, iMsg, wParam, lParam));

}