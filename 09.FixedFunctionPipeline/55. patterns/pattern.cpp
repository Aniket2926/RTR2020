// Headers
#include<windows.h>
#include<stdio.h>
#include"windows.h"
#include<gl/GL.h>
#include<gl/GLU.h>

#define WIN_WIDTH 800
#define WIN_HEIGHT 600
#define MY_ICON 2926


#pragma comment(lib,"OpenGL32.lib")
#pragma comment(lib,"GLU32.lib")

//global function declarations
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
FILE* gpFile = NULL;
void Initialize(void);


//global variable declaration
DWORD dwStyle;
WINDOWPLACEMENT wpPreve = { sizeof(WINDOWPLACEMENT) };
bool gbFullScreen = false;
HWND ghwnd = NULL;
bool gbActiveWindow = false;
HDC ghdc = NULL;
HGLRC ghlrc = NULL;

//WinMain()
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int iCmdShow)
{
	//function declaration
	void Display(void);

	//variable declarations
	WNDCLASSEX wndclass;
	HWND hwnd;
	MSG msg;
	TCHAR szAppName[] = TEXT("MyApp");
	if (fopen_s(&gpFile, "coder.txt", "w") != 0)
	{
		MessageBox(NULL, TEXT("Can Not Creat Desired File"), TEXT("ERRORS"), MB_OK);
		exit(0);
	}
	bool BDone = false;

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

	//register above class
	RegisterClassEx(&wndclass);

	//GetSystemMetrics
	int x = GetSystemMetrics(SM_CXSCREEN);
	int y = GetSystemMetrics(SM_CYSCREEN);

	//create window
	hwnd = CreateWindowEx(WS_EX_APPWINDOW, szAppName,
		TEXT(" Aniket Kadam - Patterns"),
		WS_OVERLAPPEDWINDOW | WS_CLIPCHILDREN | WS_CLIPSIBLINGS | WS_VISIBLE,
		100,
		100,
		800,
		600,
		NULL,
		NULL,
		hInstance,
		NULL);

	ghwnd = hwnd;
	Initialize();

	ShowWindow(hwnd, iCmdShow);
	SetForegroundWindow(hwnd);
	SetFocus(hwnd);

	//message loop
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
				Display();
			}
		}

	}
	return((int)msg.wParam);
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	//Local function declarations
	void ToggleFullscreen(void);
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
		case 0x46:
		case 0x66:
			ToggleFullscreen();
			break;
		default:
			break;
		}
		break;
	case WM_CLOSE:
		DestroyWindow(hwnd);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	}
	return(DefWindowProc(hwnd, iMsg, wParam, lParam));
}
void ToggleFullscreen(void)
{
	// Local variable declarations
	MONITORINFO mi = { sizeof(MONITORINFO) };

	if (gbFullScreen == false)
	{
		dwStyle = GetWindowLong(ghwnd, GWL_STYLE);
		if (dwStyle & WS_OVERLAPPEDWINDOW)
		{
			if (GetWindowPlacement(ghwnd, &wpPreve) && GetMonitorInfo(MonitorFromWindow(ghwnd, MONITORINFOF_PRIMARY), &mi))
			{
				SetWindowLong(ghwnd, GWL_STYLE, dwStyle & (~WS_OVERLAPPEDWINDOW));
				SetWindowPos(ghwnd, HWND_TOP, mi.rcMonitor.left, mi.rcMonitor.top, mi.rcMonitor.right - mi.rcMonitor.left, mi.rcMonitor.bottom - mi.rcMonitor.top, SWP_NOZORDER | SWP_FRAMECHANGED);
			}
		}
		ShowCursor(FALSE);
		gbFullScreen = true;
	}
	else
	{
		SetWindowLong(ghwnd, GWL_STYLE, dwStyle | WS_OVERLAPPEDWINDOW);
		SetWindowPos(ghwnd, HWND_TOP, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE | SWP_NOOWNERZORDER | SWP_FRAMECHANGED | SWP_NOZORDER);
		SetWindowPlacement(ghwnd, &wpPreve);
		ShowCursor(TRUE);
		gbFullScreen = false;
	}
}

void Initialize(void)
{
	//function declaration

	void Resize(int, int);

	//variable declarations
	PIXELFORMATDESCRIPTOR pfd;
	int IPixelFormatIndex;

	//code
	void Resize(int width, int height);
	ghdc = GetDC(ghwnd);

	ZeroMemory(&pfd, sizeof(PIXELFORMATDESCRIPTOR));
	pfd.nSize = sizeof(PIXELFORMATDESCRIPTOR);
	pfd.nVersion = 1;
	pfd.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
	pfd.iPixelType = PFD_TYPE_RGBA;
	pfd.cColorBits = 32;
	pfd.cDepthBits = 32;
	pfd.cRedBits = 8;
	pfd.cGreenBits = 8;
	pfd.cBlueBits = 8;
	pfd.cAlphaBits = 8;

	IPixelFormatIndex = ChoosePixelFormat(ghdc, &pfd);
	if (IPixelFormatIndex == 0)
	{
		fprintf(gpFile, "ChoosePixelFormat()Failed\n");
		DestroyWindow(ghwnd);
	}
	if (SetPixelFormat(ghdc, IPixelFormatIndex, &pfd) == FALSE)
	{
		fprintf(gpFile, "SetPixelFormat() Failed\n");
		DestroyWindow(ghwnd);
	}
	ghlrc = wglCreateContext(ghdc);
	if (ghlrc == NULL)
	{
		fprintf(gpFile, "wglCreateContext() Failed\n");
		DestroyWindow(ghwnd);
	}
	if (wglMakeCurrent(ghdc, ghlrc) == FALSE)
	{
		fprintf(gpFile, "wglMakeCurren() Failed\n");
		DestroyWindow(ghwnd);
	}
	//SetClearColor

	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glShadeModel(GL_SMOOTH);
	glClearDepth(1.0f);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

	//warmup Resize 



	Resize(WIN_WIDTH, WIN_HEIGHT);
}
void Resize(int width, int height)
{
	//code
	if (height == 0)
		height = 1;
	glViewport(0, 0, (GLsizei)width, (GLsizei)height);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	gluPerspective(45.0f, (GLfloat)width / (GLfloat)height, 0.1f, 100.0f);
}
void Display(void)
{
	//code
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//Left Square 1

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glTranslatef(-1.0f, -0.20f, -2.0f);

	glBegin(GL_LINES);

	//Vertical Lines

	glVertex3f(0.30f, 0.80f, 0.0f);//1
	glVertex3f(0.30f, 0.50f, 0.0f);//10

	glVertex3f(0.15f, 0.80f, 0.0f);//2
	glVertex3f(0.15f, 0.50f, 0.0f);//9

	glVertex3f(0.0f, 0.80f, 0.0f);//3
	glVertex3f(0.0f, 0.50f, 0.0f);//8

	glVertex3f(-0.15f, 0.80f, 0.0f);//4
	glVertex3f(-0.15f, 0.50f, 0.0f);//7

	//Horizontal Lines
	glVertex3f(-0.15f, 0.70f, 0.0f);//5
	glVertex3f(0.30f, 0.70f, 0.0f);//12

	glVertex3f(-0.15f, 0.60f, 0.0f);//6
	glVertex3f(0.30f, 0.60f, 0.0f);//11

	glVertex3f(-0.15f, 0.50f, 0.0f);//7
	glVertex3f(0.30f, 0.50f, 0.0f);//10

	glVertex3f(-0.15f, 0.80f, 0.0f);//4
	glVertex3f(0.30f, 0.80f, 0.0f);//1

	glEnd();

	//Middle Square 2

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glTranslatef(0.0f, -0.20f, -2.0f);

	glBegin(GL_LINES);

	//Vertical Lines

	glVertex3f(0.15f, 0.80f, 0.0f);//2
	glVertex3f(0.15f, 0.50f, 0.0f);//9

	glVertex3f(0.0f, 0.80f, 0.0f);//3
	glVertex3f(0.0f, 0.50f, 0.0f);//8

	glVertex3f(-0.15f, 0.80f, 0.0f);//4
	glVertex3f(-0.15f, 0.50f, 0.0f);//7

	//Horizontal Lines

	glVertex3f(-0.15f, 0.80f, 0.0f);//4
	glVertex3f(0.30f, 0.80f, 0.0f);//1

	glVertex3f(-0.15f, 0.70f, 0.0f);//5
	glVertex3f(0.30f, 0.70f, 0.0f);//12

	glVertex3f(-0.15f, 0.60f, 0.0f);//6
	glVertex3f(0.30f, 0.60f, 0.0f);//11

	//Oblique Lines

	glVertex3f(0.0f, 0.80f, 0.0f);//3
	glVertex3f(-0.15f, 0.70f, 0.0f);//5

	glVertex3f(0.15f, 0.80f, 0.0f);//2
	glVertex3f(-0.15f, 0.60f, 0.0f);//6

	glVertex3f(0.30f, 0.80f, 0.0f);//1
	glVertex3f(-0.15f, 0.50f, 0.0f);//7

	glVertex3f(0.30f, 0.70f, 0.0f);//12
	glVertex3f(0.0f, 0.50f, 0.0f);//8

	glVertex3f(0.30f, 0.60f, 0.0f);//11
	glVertex3f(0.15f, 0.50f, 0.0f);//9

	glEnd();

	//Right Square 3

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glTranslatef(1.0f, -0.20f, -2.0f);

	glBegin(GL_LINES);

	//Vertical Lines

	glVertex3f(0.30f, 0.80f, 0.0f);//1
	glVertex3f(0.30f, 0.50f, 0.0f);//10

	glVertex3f(0.15f, 0.80f, 0.0f);//2
	glVertex3f(0.15f, 0.50f, 0.0f);//9

	glVertex3f(0.0f, 0.80f, 0.0f);//3
	glVertex3f(0.0f, 0.50f, 0.0f);//8

	glVertex3f(-0.15f, 0.80f, 0.0f);//4
	glVertex3f(-0.15f, 0.50f, 0.0f);//7

	//Horizontal Lines
	glVertex3f(-0.15f, 0.70f, 0.0f);//5
	glVertex3f(0.30f, 0.70f, 0.0f);//12

	glVertex3f(-0.15f, 0.60f, 0.0f);//6
	glVertex3f(0.30f, 0.60f, 0.0f);//11

	glVertex3f(-0.15f, 0.50f, 0.0f);//7
	glVertex3f(0.30f, 0.50f, 0.0f);//10

	glVertex3f(-0.15f, 0.80f, 0.0f);//4
	glVertex3f(0.30f, 0.80f, 0.0f);//1

	//Oblique Lines

	glVertex3f(0.0f, 0.80f, 0.0f);//3
	glVertex3f(-0.15f, 0.70f, 0.0f);//5

	glVertex3f(0.15f, 0.80f, 0.0f);//2
	glVertex3f(-0.15f, 0.60f, 0.0f);//6

	glVertex3f(0.30f, 0.80f, 0.0f);//1
	glVertex3f(-0.15f, 0.50f, 0.0f);//7

	glVertex3f(0.30f, 0.70f, 0.0f);//12
	glVertex3f(0.0f, 0.50f, 0.0f);//8

	glVertex3f(0.30f, 0.60f, 0.0f);//11
	glVertex3f(0.15f, 0.50f, 0.0f);//9

	glEnd();

	//Right Lower Square 4

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glTranslatef(1.0f, -1.0f, -2.0f);

	glBegin(GL_LINES);

	//Vertical Lines

	glVertex3f(0.30f, 0.80f, 0.0f);//1
	glVertex3f(0.30f, 0.50f, 0.0f);//10

	glVertex3f(-0.15f, 0.80f, 0.0f);//4
	glVertex3f(-0.15f, 0.50f, 0.0f);//7

	//Oblique Lines
	glVertex3f(-0.15f, 0.80f, 0.0f);//4
	glVertex3f(0.30f, 0.70f, 0.0f);//12

	glVertex3f(-0.15f, 0.80f, 0.0f);//4
	glVertex3f(0.30f, 0.60f, 0.0f);//11

	glVertex3f(-0.15f, 0.80f, 0.0f);//4
	glVertex3f(0.30f, 0.50f, 0.0f);//10

	glVertex3f(-0.15f, 0.80f, 0.0f);//4
	glVertex3f(0.15f, 0.50f, 0.0f);//9

	glVertex3f(-0.15f, 0.80f, 0.0f);//4
	glVertex3f(0.0f, 0.50f, 0.0f);//8

	//Horizontal Lines

	glVertex3f(-0.15f, 0.50f, 0.0f);//7
	glVertex3f(0.30f, 0.50f, 0.0f);//10

	glVertex3f(-0.15f, 0.80f, 0.0f);//4
	glVertex3f(0.30f, 0.80f, 0.0f);//1

	glEnd();


	//Middle Lower Square 5

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glTranslatef(0.0f, -1.0f, -2.0f);

	glBegin(GL_QUADS);

	glColor3f(0.0f, 0.0f, 1.0f);

	glVertex3f(0.30f, 0.80f, 0.0f);//1
	glVertex3f(0.15f, 0.80f, 0.0f);//2
	glVertex3f(0.15f, 0.50f, 0.0f);//9
	glVertex3f(0.30f, 0.50f, 0.0f);//10

	glEnd();

	glBegin(GL_QUADS);

	glColor3f(0.0f, 1.0f, 0.0f);

	glVertex3f(0.15f, 0.80f, 0.0f);//2
	glVertex3f(0.0f, 0.80f, 0.0f);//3
	glVertex3f(0.0f, 0.50f, 0.0f);//8
	glVertex3f(0.15f, 0.50f, 0.0f);//9

	glEnd();

	glBegin(GL_QUADS);

	glColor3f(1.0f, 0.0f, 0.0f);

	glVertex3f(0.0f, 0.80f, 0.0f);//3
	glVertex3f(-0.15f, 0.80f, 0.0f);//4
	glVertex3f(-0.15f, 0.50f, 0.0f);//7
	glVertex3f(0.0f, 0.50f, 0.0f);//8

	glEnd();

	glBegin(GL_LINES);

	//Vertical Lines

	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(0.30f, 0.80f, 0.0f);//1
	glVertex3f(0.30f, 0.50f, 0.0f);//10

	glVertex3f(0.15f, 0.80f, 0.0f);//2
	glVertex3f(0.15f, 0.50f, 0.0f);//9

	glVertex3f(0.0f, 0.80f, 0.0f);//3
	glVertex3f(0.0f, 0.50f, 0.0f);//8

	glVertex3f(-0.15f, 0.80f, 0.0f);//4
	glVertex3f(-0.15f, 0.50f, 0.0f);//7

	//Horizontal Lines
	glVertex3f(-0.15f, 0.70f, 0.0f);//5
	glVertex3f(0.30f, 0.70f, 0.0f);//12

	glVertex3f(-0.15f, 0.60f, 0.0f);//6
	glVertex3f(0.30f, 0.60f, 0.0f);//11

	glVertex3f(-0.15f, 0.50f, 0.0f);//7
	glVertex3f(0.30f, 0.50f, 0.0f);//10

	glVertex3f(-0.15f, 0.80f, 0.0f);//4
	glVertex3f(0.30f, 0.80f, 0.0f);//1

	glEnd();

	//Left Lower Square 6

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glTranslatef(-1.0f, -1.0f, -2.0f);

	glBegin(GL_POINTS);

	glVertex3f(0.30f, 0.80f, 0.0f);//1

	glVertex3f(0.15f, 0.80f, 0.0f);//2

	glVertex3f(0.0f, 0.80f, 0.0f);//3
	glVertex3f(-0.15f, 0.80f, 0.0f);//4
	glVertex3f(-0.15f, 0.70f, 0.0f);//5
	glVertex3f(-0.15f, 0.60f, 0.0f);//6
	glVertex3f(-0.15f, 0.50f, 0.0f);//7
	glVertex3f(0.0f, 0.50f, 0.0f);//8
	glVertex3f(0.15f, 0.50f, 0.0f);//9
	glVertex3f(0.30f, 0.50f, 0.0f);//10
	glVertex3f(0.30f, 0.60f, 0.0f);//11
	glVertex3f(0.30f, 0.70f, 0.0f);//12

	glVertex3f(0.15f, 0.70f, 0.0f);//
	glVertex3f(0.0f, 0.70f, 0.0f);//

	glVertex3f(0.0f, 0.60f, 0.0f);//
	glVertex3f(0.15f, 0.60f, 0.0f);//
	glEnd();

	SwapBuffers(ghdc);
}
void Uninitialize(void)
{
	//code
	if (gbFullScreen == true)
	{
		dwStyle = GetWindowLong(ghwnd, GWL_STYLE);
		SetWindowLong(ghwnd, GWL_STYLE, dwStyle | WS_OVERLAPPEDWINDOW);
		SetWindowPlacement(ghwnd, &wpPreve);
		SetWindowPos(ghwnd, HWND_TOP, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE | SWP_NOOWNERZORDER | SWP_FRAMECHANGED | SWP_NOZORDER);
		ShowCursor(TRUE);
	}
	if (wglGetCurrentContext() == ghlrc)
	{
		wglMakeCurrent(NULL, NULL);
	}
	if (ghlrc)
	{
		wglDeleteContext(ghlrc);
		ghlrc = NULL;
	}
	if (ghdc)
	{
		ReleaseDC(ghwnd, ghdc);
		ghdc = NULL;
	}

	if (gpFile != NULL)
	{
		fclose(gpFile);
		gpFile = NULL;
	}
}


