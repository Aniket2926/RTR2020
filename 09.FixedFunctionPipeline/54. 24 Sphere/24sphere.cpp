// Headers
#include<windows.h>
#include<stdio.h>
#include"Windows.h"
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

GLfloat lightAmbient[] = { 0.0f,0.0f,0.0f,1.0f }; //Gray Color
GLfloat lightDiffuse[] = { 1.0f,1.0f,1.0f,1.0f }; //White Light
GLfloat lightPosition[] = { 0.0f,3.0f,3.0f,0.0f };

GLfloat LIGHT_MODEL_AMBIENT[] = { 0.2f,0.2f,0.2f,1.0f };
GLfloat LIGHT_MODEL_LOCAL_VIEWER[] = { 0.0f };


GLfloat AngleForX_Rotation = 0.0f;
GLfloat AngleForY_Rotation = 0.0f;
GLfloat AngleForZ_Rotation = 0.0f;

GLUquadric* quadric[24];

GLint KeyPress = 0.0f;

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
	if (fopen_s(&gpFile, "code.txt", "w") != 0)
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
		TEXT(" My Application"),
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
		case 'X':
		case 'x':
			KeyPress = 1;
			AngleForX_Rotation = 0.0f;
			break;
		case 'Y':
		case 'y':
			KeyPress = 2;
			AngleForY_Rotation = 0.0f;
			break;
		case 'Z':
		case 'z':
			KeyPress = 3;
			AngleForZ_Rotation = 0.0f;
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
	glClearColor(0.25f, 0.25f, 0.25f, 1.0f);
	glShadeModel(GL_SMOOTH);
	glClearDepth(1.0f);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

	glEnable(GL_AUTO_NORMAL);
	glEnable(GL_NORMALIZE);

	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, LIGHT_MODEL_AMBIENT);
	glLightModelfv(GL_LIGHT_MODEL_LOCAL_VIEWER, LIGHT_MODEL_LOCAL_VIEWER);



	glLightfv(GL_LIGHT0, GL_AMBIENT, lightAmbient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, lightDiffuse);
	glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
	glEnable(GL_LIGHT0);

	for (int i= 0.0f; i <= 24; i++)
	{
		quadric[i] = gluNewQuadric();
	}

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
	if (width <= height)
	{
		glOrtho(0.0f,
			15.0f,
			0.0f,
			15.0f * ((GLfloat)height / (GLfloat)width),
			-10.0f,
			10.f);
	}
	else
	{
		glOrtho(0.0f,
			15.0f * ((GLfloat)width / (GLfloat)height),
			0.0f,
			15.0f,
			-10.0f,
			10.f);
	}

}
void Display(void)
{


	void Update(void);
	void Draw24Sphere(void);
	//code
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);

	glLoadIdentity();

	Draw24Sphere();
	Update();

	SwapBuffers(ghdc);
}
void Draw24Sphere(void)
{
	GLfloat materialAmbient[4];
	GLfloat materialDiffuse[4];
	GLfloat materialSpecular[4];
	GLfloat materialShininess[1];

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	//code

	// ***** 1st sphere on 1st row, emerald *****

	 // Ambient material
	materialAmbient[0] = 0.0215; // r
	materialAmbient[1] = 0.1745; // g
	materialAmbient[2] = 0.0215; // b
	materialAmbient[3] = 1.0f;   // a
	glMaterialfv(GL_FRONT, GL_AMBIENT, materialAmbient);

	// diffuse material
	materialDiffuse[0] = 0.07568; // r
	materialDiffuse[1] = 0.61424; // g
	materialDiffuse[2] = 0.07568; // b
	materialDiffuse[3] = 1.0f;    // a
	glMaterialfv(GL_FRONT, GL_DIFFUSE, materialDiffuse);

	// specular material
	materialSpecular[0] = 0.633;    // r
	materialSpecular[1] = 0.727811; // g
	materialSpecular[2] = 0.633;    // b
	materialSpecular[3] = 1.0f;     // a
	glMaterialfv(GL_FRONT, GL_SPECULAR, materialSpecular);

	// shininess
	materialShininess[0] = 0.6 * 128;
	glMaterialfv(GL_FRONT, GL_SHININESS, materialShininess);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(1.5f, 14.0f, 0.0f);
	gluSphere(quadric[0], 1.0f, 30, 30);

	// ***** 2nd sphere on 1st row, jade *****

	// Ambient material
	materialAmbient[0] = 0.135;  // r
	materialAmbient[1] = 0.2225; // g
	materialAmbient[2] = 0.1575; // b
	materialAmbient[3] = 1.0f;   // a
	glMaterialfv(GL_FRONT, GL_AMBIENT, materialAmbient);

	// diffuse material
	materialDiffuse[0] = 0.54; // r
	materialDiffuse[1] = 0.89; // g
	materialDiffuse[2] = 0.63; // b
	materialDiffuse[3] = 1.0f; // a
	glMaterialfv(GL_FRONT, GL_DIFFUSE, materialDiffuse);

	// specular material
	materialSpecular[0] = 0.316228; // r
	materialSpecular[1] = 0.316228; // g
	materialSpecular[2] = 0.316228; // b
	materialSpecular[3] = 1.0f;     // a
	glMaterialfv(GL_FRONT, GL_SPECULAR, materialSpecular);

	// shininess
	materialShininess[0] = 0.1 * 128;
	glMaterialfv(GL_FRONT, GL_SHININESS, materialShininess);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(5.5f, 14.0f, 0.0f);
	gluSphere(quadric[1], 1.0f, 30, 30);

	// ***** 3rd sphere on 1st row, obsidian *****

	// Ambient material

	materialAmbient[0] = 0.05375; // r
	materialAmbient[1] = 0.05;    // g
	materialAmbient[2] = 0.06625; // b
	materialAmbient[3] = 1.0f;    // a
	glMaterialfv(GL_FRONT, GL_AMBIENT, materialAmbient);

	// diffuse material
	materialDiffuse[0] = 0.18275; // r
	materialDiffuse[1] = 0.17;    // g
	materialDiffuse[2] = 0.22525; // b
	materialDiffuse[3] = 1.0f; // a
	glMaterialfv(GL_FRONT, GL_DIFFUSE, materialDiffuse);

	// specular material
	materialSpecular[0] = 0.332741; // r
	materialSpecular[1] = 0.328634; // g
	materialSpecular[2] = 0.346435; // b
	materialSpecular[3] = 1.0f;     // a
	glMaterialfv(GL_FRONT, GL_SPECULAR, materialSpecular);

	// shininess
	materialShininess[0] = 0.3 * 128;
	glMaterialfv(GL_FRONT, GL_SHININESS, materialShininess);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(10.0f, 14.0f, 0.0f);
	gluSphere(quadric[2], 1.0f, 30, 30);

	// ***** 4th sphere on 1st row, pearl *****

	// Ambient material
	materialAmbient[0] = 0.25; //r
	materialAmbient[1] = 0.20725; // g
	materialAmbient[2] = 0.20725; // b
	materialAmbient[3] = 1.0f;    // a
	glMaterialfv(GL_FRONT, GL_AMBIENT, materialAmbient);

	// diffuse material
	materialDiffuse[0] = 1.0;   // r
	materialDiffuse[1] = 0.829; // g
	materialDiffuse[2] = 0.829; // b
	materialDiffuse[3] = 1.0f;  // a
	glMaterialfv(GL_FRONT, GL_DIFFUSE, materialDiffuse);

	// specular material
	materialSpecular[0] = 0.296648; // r
	materialSpecular[1] = 0.296648; // g
	materialSpecular[2] = 0.296648; // b
	materialSpecular[3] = 1.0;      // a
	glMaterialfv(GL_FRONT, GL_SPECULAR, materialSpecular);

	// shininess
	materialShininess[0] = 0.088 * 128;
	glMaterialfv(GL_FRONT, GL_SHININESS, materialShininess);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(14.5f, 14.0f, 0.0f);
	gluSphere(quadric[3], 1.0f, 30, 30);

	// ***** 5th sphere on 1st row, ruby *****

	// ambient material
	materialAmbient[0] = 0.1745;  // r
	materialAmbient[1] = 0.01175; // g
	materialAmbient[2] = 0.01175; // b
	materialAmbient[3] = 1.0f;    // a

	glMaterialfv(GL_FRONT, GL_AMBIENT, materialAmbient);

	// diffuse material
	materialDiffuse[0] = 0.61424; // r
	materialDiffuse[1] = 0.04136; // g
	materialDiffuse[2] = 0.04136; // b
	materialDiffuse[3] = 1.0f;    // a

	glMaterialfv(GL_FRONT, GL_DIFFUSE, materialDiffuse);

	// specular material
	materialSpecular[0] = 0.727811; // r
	materialSpecular[1] = 0.626959; // g
	materialSpecular[2] = 0.626959; // b
	materialSpecular[3] = 1.0f;   // a

	glMaterialfv(GL_FRONT, GL_SPECULAR, materialSpecular);

	// shininess
	materialShininess[0] = 0.6 * 128;
	glMaterialfv(GL_FRONT, GL_SHININESS, materialShininess);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(19.0f, 14.0f, 0.0f);
	gluSphere(quadric[4], 1.0f, 30, 30);

	// ***** 6th sphere on 1st column, turquoise *****

	// Ambient material
	materialAmbient[0] = 0.1;     // r
	materialAmbient[1] = 0.18725; // g
	materialAmbient[2] = 0.1745;  // b
	materialAmbient[3] = 1.0f;    // a
	glMaterialfv(GL_FRONT, GL_AMBIENT, materialAmbient);

	// diffuse material
	materialDiffuse[0] = 0.396;   // r
	materialDiffuse[1] = 0.74151; // g
	materialDiffuse[2] = 0.69102; // b
	materialDiffuse[3] = 1.0f;    // a
	glMaterialfv(GL_FRONT, GL_DIFFUSE, materialDiffuse);

	// specular material
	materialSpecular[0] = 0.297254; // r
	materialSpecular[1] = 0.30829;  // g
	materialSpecular[2] = 0.306678; // b
	materialSpecular[3] = 1.0f;     // a
	glMaterialfv(GL_FRONT, GL_SPECULAR, materialSpecular);

	// shininess
	materialShininess[0] = 0.1 * 128;
	glMaterialfv(GL_FRONT, GL_SHININESS, materialShininess);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(23.5f, 14.0f, 0.0f);
	gluSphere(quadric[5], 1.0f, 30, 30);

	// ***** 1st sphere on 2nd row, brass *****

	// Ambient material
	materialAmbient[0] = 0.329412; // r
	materialAmbient[1] = 0.223529; // g
	materialAmbient[2] = 0.027451; // b
	materialAmbient[3] = 1.0f;     // a
	glMaterialfv(GL_FRONT, GL_AMBIENT, materialAmbient);

	// diffuse material
	materialDiffuse[0] = 0.780392; // r
	materialDiffuse[1] = 0.568627; // g
	materialDiffuse[2] = 0.113725; // b
	materialDiffuse[3] = 1.0f;     // a
	glMaterialfv(GL_FRONT, GL_DIFFUSE, materialDiffuse);

	// specular material
	materialSpecular[0] = 0.992157; // r
	materialSpecular[1] = 0.941176; // g
	materialSpecular[2] = 0.807843; // b
	materialSpecular[3] = 1.0f;     // a
	glMaterialfv(GL_FRONT, GL_SPECULAR, materialSpecular);

	// shininess
	materialShininess[0] = 0.21794872 * 128;
	glMaterialfv(GL_FRONT, GL_SHININESS, materialShininess);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(1.5f, 10.0f, 0.0f);
	gluSphere(quadric[6], 1.0f, 30, 30);

	// ***** 2nd sphere on 2nd row, bronze *****

	// Ambient material
	materialAmbient[0] = 0.2125; // r
	materialAmbient[1] = 0.1275; // g
	materialAmbient[2] = 0.054;  // b
	materialAmbient[3] = 1.0f;   // a
	glMaterialfv(GL_FRONT, GL_AMBIENT, materialAmbient);

	// diffuse material
	materialDiffuse[0] = 0.714;   // r
	materialDiffuse[1] = 0.4284;  // g
	materialDiffuse[2] = 0.18144; // b
	materialDiffuse[3] = 1.0f;    // a
	glMaterialfv(GL_FRONT, GL_DIFFUSE, materialDiffuse);

	// specular material
	materialSpecular[0] = 0.393548; // r
	materialSpecular[1] = 0.271906; // g
	materialSpecular[2] = 0.166721; // b
	materialSpecular[3] = 1.0f;     // a
	glMaterialfv(GL_FRONT, GL_SPECULAR, materialSpecular);

	// shininess
	materialShininess[0] = 0.2 * 128;
	glMaterialfv(GL_FRONT, GL_SHININESS, materialShininess);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(5.5f, 10.0f, 0.0f);
	gluSphere(quadric[7], 1.0f, 30, 30);

	// ***** 3rd sphere on 2nd row, chrome *****

	// Ambient material
	materialAmbient[0] = 0.25; // r
	materialAmbient[1] = 0.25; // g
	materialAmbient[2] = 0.25; // b
	materialAmbient[3] = 1.0f; // a
	glMaterialfv(GL_FRONT, GL_AMBIENT, materialAmbient);

	// diffuse material
	materialDiffuse[0] = 0.4;  // r
	materialDiffuse[1] = 0.4;  // g
	materialDiffuse[2] = 0.4;  // b
	materialDiffuse[3] = 1.0f; // a
	glMaterialfv(GL_FRONT, GL_DIFFUSE, materialDiffuse);

	// specular material
	materialSpecular[0] = 0.774597; // r
	materialSpecular[1] = 0.774597; // g
	materialSpecular[2] = 0.774597; // b
	materialSpecular[3] = 1.0f;     // a
	glMaterialfv(GL_FRONT, GL_SPECULAR, materialSpecular);

	// shininess
	materialShininess[0] = 0.6 * 128;
	glMaterialfv(GL_FRONT, GL_SHININESS, materialShininess);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(10.0f, 10.0f, 0.0f);
	gluSphere(quadric[8], 1.0f, 30, 30);

	// ***** 4th sphere on 2nd row, copper *****

	// Ambient material
	materialAmbient[0] = 0.19125; // r
	materialAmbient[1] = 0.0735;  // g
	materialAmbient[2] = 0.0225;  // b
	materialAmbient[3] = 1.0f;    // a
	glMaterialfv(GL_FRONT, GL_AMBIENT, materialAmbient);

	// diffuse material
	materialDiffuse[0] = 0.7038;  // r
	materialDiffuse[1] = 0.27048; // g
	materialDiffuse[2] = 0.0828;  // b
	materialDiffuse[3] = 1.0f;    // a
	glMaterialfv(GL_FRONT, GL_DIFFUSE, materialDiffuse);

	// specular material
	materialSpecular[0] = 0.256777; // r
	materialSpecular[1] = 0.137622; // g
	materialSpecular[2] = 0.086014; // b
	materialSpecular[3] = 1.0f;     // a
	glMaterialfv(GL_FRONT, GL_SPECULAR, materialSpecular);

	// shininess
	materialShininess[0] = 0.1 * 128;
	glMaterialfv(GL_FRONT, GL_SHININESS, materialShininess);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(14.5f, 10.0f, 0.0f);
	gluSphere(quadric[9], 1.0f, 30, 30);

	// ***** 5th sphere on 2nd row, gold *****
	// Ambient material
	materialAmbient[0] = 0.24725; // r
	materialAmbient[1] = 0.1995;  // g
	materialAmbient[2] = 0.0745;  // b
	materialAmbient[3] = 1.0f;    // a
	glMaterialfv(GL_FRONT, GL_AMBIENT, materialAmbient);

	// diffuse material
	materialDiffuse[0] = 0.75164; // r
	materialDiffuse[1] = 0.60648; // g
	materialDiffuse[2] = 0.22648; // b
	materialDiffuse[3] = 1.0f;    // a
	glMaterialfv(GL_FRONT, GL_DIFFUSE, materialDiffuse);

	// specular material
	materialSpecular[0] = 0.628281; // r
	materialSpecular[1] = 0.555802; // g
	materialSpecular[2] = 0.366065; // b
	materialSpecular[3] = 1.0f;     // a
	glMaterialfv(GL_FRONT, GL_SPECULAR, materialSpecular);

	// shininess
	materialShininess[0] = 0.4 * 128;
	glMaterialfv(GL_FRONT, GL_SHININESS, materialShininess);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(19.0f, 10.0f, 0.0f);
	gluSphere(quadric[10], 1.0f, 30, 30);

	// ***** 6th sphere on 2nd row, silver *****

	// Ambient material
	materialAmbient[0] = 0.19225; // r
	materialAmbient[1] = 0.19225; // g
	materialAmbient[2] = 0.19225; // b
	materialAmbient[3] = 1.0f;    // a
	glMaterialfv(GL_FRONT, GL_AMBIENT, materialAmbient);

	// diffuse material
	materialDiffuse[0] = 0.50754; // r
	materialDiffuse[1] = 0.50754; // g
	materialDiffuse[2] = 0.50754; // b
	materialDiffuse[3] = 1.0f;     // a
	glMaterialfv(GL_FRONT, GL_DIFFUSE, materialDiffuse);

	// specular material
	materialSpecular[0] = 0.508273; // r
	materialSpecular[1] = 0.508273; // g
	materialSpecular[2] = 0.508273; // b
	materialSpecular[3] = 1.0f;     // a
	glMaterialfv(GL_FRONT, GL_SPECULAR, materialSpecular);

	// shininess
	materialShininess[0] = 0.4 * 128;
	glMaterialfv(GL_FRONT, GL_SHININESS, materialShininess);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(23.5f, 10.0f, 0.0f);
	gluSphere(quadric[11], 1.0f, 30, 30);


	// ***** 1st sphere on 3rd row, black *****

	// Ambient material
	materialAmbient[0] = 0.0;  // r
	materialAmbient[1] = 0.0;  // g
	materialAmbient[2] = 0.0;  // b
	materialAmbient[3] = 1.0;  // a
	glMaterialfv(GL_FRONT, GL_AMBIENT, materialAmbient);

	// diffuse material
	materialDiffuse[0] = 0.01; // r
	materialDiffuse[1] = 0.01; // g
	materialDiffuse[2] = 0.01; // b
	materialDiffuse[3] = 1.00; // a
	glMaterialfv(GL_FRONT, GL_DIFFUSE, materialDiffuse);

	// specular material
	materialSpecular[0] = 0.50; // r
	materialSpecular[1] = 0.50; // r
	materialSpecular[2] = 0.50; // r
	materialSpecular[3] = 1.0f; // a
	glMaterialfv(GL_FRONT, GL_SPECULAR, materialSpecular);

	// shininess 
	materialShininess[0] = 0.25 * 128;
	glMaterialfv(GL_FRONT, GL_SHININESS, materialShininess);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(1.5f, 6.0f, 0.0f);
	gluSphere(quadric[12], 1.0f, 30, 30);

	// ***** 2nd sphere on 3rd row, cyan *****

	// Ambient material
	materialAmbient[0] = 0.0;  // r
	materialAmbient[1] = 0.1;  // g
	materialAmbient[2] = 0.06; // b
	materialAmbient[3] = 1.0f; // a
	glMaterialfv(GL_FRONT, GL_AMBIENT, materialAmbient);

	// diffuse material
	materialDiffuse[0] = 0.0;        // r
	materialDiffuse[1] = 0.50980392; // g
	materialDiffuse[2] = 0.50980392; // g
	materialDiffuse[3] = 1.0f;       // a
	glMaterialfv(GL_FRONT, GL_DIFFUSE, materialDiffuse);

	// specular material
	materialSpecular[0] = 0.50196078; // r
	materialSpecular[1] = 0.50196078; // r
	materialSpecular[2] = 0.50196078; // r
	materialSpecular[3] = 1.0f;       // a
	glMaterialfv(GL_FRONT, GL_SPECULAR, materialSpecular);

	// shininess
	materialShininess[0] = 0.25 * 128;
	glMaterialfv(GL_FRONT, GL_SHININESS, materialShininess);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(5.5f, 6.0f, 0.0f);
	gluSphere(quadric[13], 1.0f, 30, 30);

	// ***** 3rd sphere on 2nd column, green *****

	// Ambient material
	materialAmbient[0] = 0.0;  // r
	materialAmbient[1] = 0.0;  // g
	materialAmbient[2] = 0.0;  // b
	materialAmbient[3] = 1.0;  // a
	glMaterialfv(GL_FRONT, GL_AMBIENT, materialAmbient);

	// diffuse material
	materialDiffuse[0] = 0.1;  // r
	materialDiffuse[1] = 0.35; // g
	materialDiffuse[2] = 0.1;  // b
	materialDiffuse[3] = 1.0f; // a
	glMaterialfv(GL_FRONT, GL_DIFFUSE, materialDiffuse);

	// specular material
	materialSpecular[0] = 0.45; // r
	materialSpecular[1] = 0.55; // g
	materialSpecular[2] = 0.45; // b
	materialSpecular[3] = 1.0f; // a
	glMaterialfv(GL_FRONT, GL_SPECULAR, materialSpecular);

	// shininess
	materialShininess[0] = 0.25 * 128;
	glMaterialfv(GL_FRONT, GL_SHININESS, materialShininess);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(10.0f, 6.0f, 0.0f);
	gluSphere(quadric[14], 1.0f, 30, 30);

	// ***** 4th sphere on 3rd row, red *****

	// Ambient material
	materialAmbient[0] = 0.0;  // r
	materialAmbient[1] = 0.0;  // g
	materialAmbient[2] = 0.0;  // b
	materialAmbient[3] = 1.0f;  // a
	glMaterialfv(GL_FRONT, GL_AMBIENT, materialAmbient);

	// diffuse material
	materialDiffuse[0] = 0.5;  // r
	materialDiffuse[1] = 0.0;  // g
	materialDiffuse[2] = 0.0;  // b
	materialDiffuse[3] = 1.0f;  // a
	glMaterialfv(GL_FRONT, GL_DIFFUSE, materialDiffuse);

	// specular material
	materialSpecular[0] = 0.7;  // r
	materialSpecular[1] = 0.6;  // g
	materialSpecular[2] = 0.6;  // b
	materialSpecular[3] = 1.0f; // a
	glMaterialfv(GL_FRONT, GL_SPECULAR, materialSpecular);

	// shininess
	materialShininess[0] = 0.25 * 128;
	glMaterialfv(GL_FRONT, GL_SHININESS, materialShininess);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(14.5f, 6.0f, 0.0f);
	gluSphere(quadric[15], 1.0f, 30, 30);

	// ***** 5th sphere on 3rd row, white *****

	// Ambient material
	materialAmbient[0] = 0.0;  // r
	materialAmbient[1] = 0.0;  // g
	materialAmbient[2] = 0.0;  // b
	materialAmbient[3] = 1.0;  // a
	glMaterialfv(GL_FRONT, GL_AMBIENT, materialAmbient);

	// diffuse material
	materialDiffuse[0] = 0.55; // r
	materialDiffuse[1] = 0.55; // g
	materialDiffuse[2] = 0.55; // b
	materialDiffuse[3] = 1.0f; // a
	glMaterialfv(GL_FRONT, GL_DIFFUSE, materialDiffuse);

	// specular material
	materialSpecular[0] = 0.70; // r
	materialSpecular[1] = 0.70; // g
	materialSpecular[2] = 0.70; // b
	materialSpecular[3] = 1.0f; // a
	glMaterialfv(GL_FRONT, GL_SPECULAR, materialSpecular);

	// shininess
	materialShininess[0] = 0.25 * 128;
	glMaterialfv(GL_FRONT, GL_SHININESS, materialShininess);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(19.0f, 6.0f, 0.0f);
	gluSphere(quadric[16], 1.0f, 30, 30);

	// ***** 6th sphere on 3rd row, yellow plastic *****

	// Ambient material
	materialAmbient[0] = 0.0;  // r
	materialAmbient[1] = 0.0;  // g
	materialAmbient[2] = 0.0;  // b
	materialAmbient[3] = 1.0f;  // a
	glMaterialfv(GL_FRONT, GL_AMBIENT, materialAmbient);

	// diffuse material
	materialDiffuse[0] = 0.5;  // r
	materialDiffuse[1] = 0.5;  // g
	materialDiffuse[2] = 0.0;  // b
	materialDiffuse[3] = 1.0f; // a
	glMaterialfv(GL_FRONT, GL_DIFFUSE, materialDiffuse);

	// specular material
	materialSpecular[0] = 0.60; // r
	materialSpecular[1] = 0.60; // g
	materialSpecular[2] = 0.50; // b
	materialSpecular[3] = 1.0f;  //a
	glMaterialfv(GL_FRONT, GL_SPECULAR, materialSpecular);

	// shininess
	materialShininess[0] = 0.25 * 128;
	glMaterialfv(GL_FRONT, GL_SHININESS, materialShininess);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(23.5f, 6.0f, 0.0f);
	gluSphere(quadric[17], 1.0f, 30, 30);

	// ***** 1st sphere on 4th row, black *****

	// Ambient material
	materialAmbient[0] = 0.02; // r
	materialAmbient[1] = 0.02; // g
	materialAmbient[2] = 0.02; // b
	materialAmbient[3] = 1.0f; // a
	glMaterialfv(GL_FRONT, GL_AMBIENT, materialAmbient);

	// diffuse material
	materialDiffuse[0] = 0.01; // r
	materialDiffuse[1] = 0.01; // g
	materialDiffuse[2] = 0.01; // b
	materialDiffuse[3] = 1.0f; // a
	glMaterialfv(GL_FRONT, GL_DIFFUSE, materialDiffuse);

	// specular material
	materialSpecular[0] = 0.4;  // r
	materialSpecular[1] = 0.4;  // g
	materialSpecular[2] = 0.4;  // b
	materialSpecular[3] = 1.0f; // a
	glMaterialfv(GL_FRONT, GL_SPECULAR, materialSpecular);

	// shininess
	materialShininess[0] = 0.078125 * 128;
	glMaterialfv(GL_FRONT, GL_SHININESS, materialShininess);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(1.5f, 2.0f, 0.0f);
	gluSphere(quadric[18], 1.0f, 30, 30);

	// ***** 2nd sphere on 4th row, cyan *****

	// Ambient material
	materialAmbient[0] = 0.0;  // r
	materialAmbient[1] = 0.05; // g
	materialAmbient[2] = 0.05; // b
	materialAmbient[3] = 1.0f; // a
	glMaterialfv(GL_FRONT, GL_AMBIENT, materialAmbient);

	// diffuse material
	materialDiffuse[0] = 0.4;  // r
	materialDiffuse[1] = 0.5;  // g
	materialDiffuse[2] = 0.5;  // b
	materialDiffuse[3] = 1.0f;  // a
	glMaterialfv(GL_FRONT, GL_DIFFUSE, materialDiffuse);

	// specular material
	materialSpecular[0] = 0.04; // r
	materialSpecular[1] = 0.7;  // g
	materialSpecular[2] = 0.7;  // b
	materialSpecular[3] = 1.0f;  // a
	glMaterialfv(GL_FRONT, GL_SPECULAR, materialSpecular);

	// shininess
	materialShininess[0] = 0.078125 * 128;
	glMaterialfv(GL_FRONT, GL_SHININESS, materialShininess);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(5.5f, 2.0f, 0.0f);
	gluSphere(quadric[19], 1.0f, 30, 30);

	// ***** 3rd sphere on 4th row, green *****

	// Ambient material
	materialAmbient[0] = 0.0;  // r
	materialAmbient[1] = 0.05; // g
	materialAmbient[2] = 0.0;  // b
	materialAmbient[3] = 1.0f; // a
	glMaterialfv(GL_FRONT, GL_AMBIENT, materialAmbient);

	// diffuse material
	materialDiffuse[0] = 0.4;  // r
	materialDiffuse[1] = 0.5;  // g
	materialDiffuse[2] = 0.4;  // b
	materialDiffuse[3] = 1.0f; // a
	glMaterialfv(GL_FRONT, GL_DIFFUSE, materialDiffuse);

	// specular material
	materialSpecular[0] = 0.04; // r
	materialSpecular[1] = 0.7;  // g
	materialSpecular[2] = 0.04; // b
	materialSpecular[3] = 1.0f; // a
	glMaterialfv(GL_FRONT, GL_SPECULAR, materialSpecular);

	// shininess
	materialShininess[0] = 0.078125 * 128;
	glMaterialfv(GL_FRONT, GL_SHININESS, materialShininess);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(10.0f, 2.0f, 0.0f);
	gluSphere(quadric[20], 1.0f, 30, 30);

	// ***** 4th sphere on 4th row, red *****

	// Ambient material
	materialAmbient[0] = 0.05; // r
	materialAmbient[1] = 0.0;  // g
	materialAmbient[2] = 0.0;  // b
	materialAmbient[3] = 1.0f;  // a
	glMaterialfv(GL_FRONT, GL_AMBIENT, materialAmbient);

	// diffuse material
	materialDiffuse[0] = 0.5;  // r
	materialDiffuse[1] = 0.4;  // g
	materialDiffuse[2] = 0.4;  // b
	materialDiffuse[3] = 1.0f; // a
	glMaterialfv(GL_FRONT, GL_DIFFUSE, materialDiffuse);

	// specular material
	materialSpecular[0] = 0.7;  // r
	materialSpecular[1] = 0.04; // g
	materialSpecular[2] = 0.04; // b
	materialSpecular[3] = 1.0f; // a
	glMaterialfv(GL_FRONT, GL_SPECULAR, materialSpecular);

	// shininess
	materialShininess[0] = 0.078125 * 128;
	glMaterialfv(GL_FRONT, GL_SHININESS, materialShininess);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(14.5f, 2.0f, 0.0f);
	gluSphere(quadric[21], 1.0f, 30, 30);

	// ***** 5th sphere on 4th row, white *****

	// Ambient material
	materialAmbient[0] = 0.05; // r
	materialAmbient[1] = 0.05; // g
	materialAmbient[2] = 0.05; // b
	materialAmbient[3] = 1.0f; // a
	glMaterialfv(GL_FRONT, GL_AMBIENT, materialAmbient);

	// diffuse material
	materialDiffuse[0] = 0.5;  // r
	materialDiffuse[1] = 0.5;  // g
	materialDiffuse[2] = 0.5;  // b
	materialDiffuse[3] = 1.0f; // a
	glMaterialfv(GL_FRONT, GL_DIFFUSE, materialDiffuse);

	// specular material
	materialSpecular[0] = 0.7;  // r
	materialSpecular[1] = 0.7;  // g
	materialSpecular[2] = 0.7;  // b
	materialSpecular[3] = 1.0f; // a
	glMaterialfv(GL_FRONT, GL_SPECULAR, materialSpecular);

	// shininess
	materialShininess[0] = 0.078125 * 128;
	glMaterialfv(GL_FRONT, GL_SHININESS, materialShininess);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(19.0f, 2.0f, 0.0f);
	gluSphere(quadric[22], 1.0f, 30, 30);

	// ***** 6th sphere on 4th row, yellow rubber *****

	// Ambient material
	materialAmbient[0] = 0.05; // r
	materialAmbient[1] = 0.05; // g
	materialAmbient[2] = 0.0;  // b
	materialAmbient[3] = 1.0;  // a
	glMaterialfv(GL_FRONT, GL_AMBIENT, materialAmbient);

	// diffuse material
	materialDiffuse[0] = 0.5;  // r
	materialDiffuse[1] = 0.5;  // g
	materialDiffuse[2] = 0.4;  // b
	materialDiffuse[3] = 1.0f;  // a
	glMaterialfv(GL_FRONT, GL_DIFFUSE, materialDiffuse);

	// specular material
	materialSpecular[0] = 0.7;  // r
	materialSpecular[1] = 0.7;  // g
	materialSpecular[2] = 0.04; // b
	materialSpecular[3] = 1.0f; // a
	glMaterialfv(GL_FRONT, GL_SPECULAR, materialSpecular);

	// shininess
	materialShininess[0] = 0.078125 * 128;
	glMaterialfv(GL_FRONT, GL_SHININESS, materialShininess);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(23.5f, 2.0f, 0.0f);
	gluSphere(quadric[23], 1.0f, 30, 30);

}
void Update(void)
{
	if (KeyPress == 1)
	{
		glRotatef(AngleForX_Rotation, 1.0f, 0.0f, 0.0f);
		lightPosition[1] = AngleForX_Rotation;
		AngleForX_Rotation = AngleForX_Rotation + 1.0f;
		if (AngleForX_Rotation >= 360.0f)
			AngleForX_Rotation = 0.0f;
	}
	else if (KeyPress == 2)
	{
		glRotatef(AngleForY_Rotation, 0.0f, 1.0f, 0.0f);
		lightPosition[2] = AngleForY_Rotation;
		AngleForY_Rotation = AngleForY_Rotation + 1.0f;
		if (AngleForY_Rotation >= 360.0f)
			AngleForY_Rotation = 0.0f;
	}
	else if (KeyPress == 3)
	{
		glRotatef(AngleForZ_Rotation, 0.0f, 0.0f, 1.0f);
		lightPosition[0] = AngleForZ_Rotation;
		AngleForZ_Rotation = AngleForZ_Rotation + 1.0f;
		if (AngleForZ_Rotation >= 360.0f)
			AngleForZ_Rotation = 0.0f;
	}
	glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
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
	for (int i = 0.0f; i <= 24; i++)
		if (quadric[i])
		{
			gluDeleteQuadric(quadric[i]);
			quadric[i] = NULL;
		}

	if (gpFile != NULL)
	{
		fclose(gpFile);
		gpFile = NULL;
	}
}




