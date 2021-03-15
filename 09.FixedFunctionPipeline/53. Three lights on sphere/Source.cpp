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
bool bLight = false;

GLfloat lightAmbientZero[] = { 0.0f,0.0f,0.0f,1.0f }; //Gray Color
GLfloat lightDiffuseZero[] = { 1.0f,0.0f,0.0f,1.0f }; //Red Light
GLfloat lightSpecularZero[] = { 1.0f,0.0f,0.0f,1.0f }; //Red 
GLfloat lightPositionZero[] = { 0.0f,0.0f,0.0f,1.0f }; // Positional Light

GLfloat lightAmbientOne[] = { 0.0f,0.0f,0.0f,1.0f }; //Gray Color
GLfloat lightDiffuseOne[] = { 0.0f,1.0f,0.0f,1.0f }; //Green Light
GLfloat lightSpecularOne[] = { 0.0f,1.0f,0.0f,1.0f }; //Green
GLfloat lightPositionOne[] = { 0.0f,0.0f,0.0f,1.0f }; // Positional Light

GLfloat lightAmbientTwo[] = { 0.0f,0.0f,0.0f,1.0f }; //Gray Color
GLfloat lightDiffuseTwo[] = { 0.0f,0.0f,1.0f,1.0f }; //Blue Light
GLfloat lightSpecularTwo[] = { 0.0f,0.0f,1.0f,1.0f }; //Blue
GLfloat lightPositionTwo[] = { 0.0f,0.0f,0.0f,1.0f }; // Positional Light

GLfloat materialAmbient[] = { 0.0f,0.0f,0.0f,1.0f }; //Black
GLfloat materialDiffuse[] = { 1.0f,1.0f,1.0f,1.0f }; //White
GLfloat materialSpecular[] = { 1.0f,1.0f,1.0f,1.0f };
GLfloat materialShinness = 50.0;

GLfloat LightAngle0 = 0.0f;
GLfloat LightAngle1 = 0.0f;
GLfloat LightAngle2 = 0.0f;

GLUquadric* quadric = NULL;

//WinMain()
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int iCmdShow)
{
	//function declaration
	void Display(void);

	//variable declarations
	WNDCLASSEX wndclass;
	HWND hwnd;
	MSG msg;
	TCHAR szAppName[] = TEXT("My window2926");
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
		TEXT("Aniket Kadam - Three Lights On Sephere"),
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
		case 'L':
		case 'l':
			if (bLight == true)
			{
				bLight = false;
				glDisable(GL_LIGHTING);
			}
			else
			{
				bLight = true;
				glEnable(GL_LIGHTING);
			}
			break;
		}
	default:
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

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	glLightfv(GL_LIGHT0, GL_AMBIENT, lightAmbientZero);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, lightDiffuseZero);
	glLightfv(GL_LIGHT0, GL_SPECULAR, lightSpecularZero);
	glEnable(GL_LIGHT0);

	glLightfv(GL_LIGHT1, GL_AMBIENT, lightAmbientOne);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, lightDiffuseOne);
	glLightfv(GL_LIGHT1, GL_SPECULAR, lightSpecularOne);
	glEnable(GL_LIGHT1);

	glLightfv(GL_LIGHT2, GL_AMBIENT, lightAmbientTwo);
	glLightfv(GL_LIGHT2, GL_DIFFUSE, lightDiffuseTwo);
	glLightfv(GL_LIGHT2, GL_SPECULAR, lightSpecularTwo);
	glEnable(GL_LIGHT2);

	glMaterialfv(GL_FRONT, GL_AMBIENT, materialAmbient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, materialDiffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, materialSpecular);
	glMaterialf(GL_FRONT, GL_SHININESS, materialShinness);

	//warmup Resize call as
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
	void update(void);

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glPushMatrix();
	gluLookAt(0.0f, 0.0f, 2.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);

	glPushMatrix();
	glRotatef(LightAngle0, 1.0f, 0.0f, 0.0f);

	lightPositionZero[1] = LightAngle0;
	glLightfv(GL_LIGHT0, GL_POSITION, lightPositionZero);
	glPopMatrix();

	glPushMatrix();
	glRotatef(LightAngle1, 0.0f, 1.0f, 0.0f);

	lightPositionOne[0] = LightAngle1;
	glLightfv(GL_LIGHT1, GL_POSITION, lightPositionOne);
	glPopMatrix();

	glPushMatrix();
	glRotatef(LightAngle2, 0.0f, 0.0f, 1.0f);

	lightPositionTwo[0] = LightAngle2;
	glLightfv(GL_LIGHT2, GL_POSITION, lightPositionTwo);
	glPopMatrix();

	glTranslatef(0.0f, 0.0f, -1.0f);

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	quadric = gluNewQuadric();
	gluSphere(quadric, 0.2f, 30, 30);

	//Normals are Calculated by glu library. we do not calculate normal explicitely.
	glPopMatrix();

	update();

	SwapBuffers(ghdc);
}
void update(void)
{
	LightAngle0 = LightAngle0 + 0.02f;
	if (LightAngle0 >= 360.0f)
		LightAngle0 = 0.0f;

	LightAngle1 = LightAngle1 + 0.02f;
	if (LightAngle1 >= 360.0f)
		LightAngle1 = 0.0f;

	LightAngle2 = LightAngle2 + 0.02f;
	if (LightAngle2 >= 360.0f)
		LightAngle2 = 0.0f;
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
	if (quadric)
	{
		gluDeleteQuadric(quadric);
		quadric = NULL;
	}

	if (gpFile != NULL)
	{
		fclose(gpFile);
		gpFile = NULL;
	}
}





