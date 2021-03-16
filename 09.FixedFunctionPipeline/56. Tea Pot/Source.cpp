// Headers
#include<windows.h>
#include<stdio.h>
#include"window.h"
#include<gl/GL.h>
#include<gl/GLU.h>
#include"Teapot.h"

#define WIN_WIDTH 800
#define WIN_HEIGHT 600

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

bool bTexture = false;
GLuint marble_Texture;

bool bLight = false;
GLfloat lightAmbient[] = { 0.0f,0.0f,0.0f,1.0f };
GLfloat lightDiffuse[] = { 1.0f,1.0f,1.0f,1.0f };
GLfloat lightSpecular[] = { 1.0f,1.0f,1.0f,1.0f };
GLfloat lightPosition[] = { 100.0f,100.0f,100.0f,1.0f };

GLfloat materialAmbient[] = { 0.0f,0.0f,0.0f,1.0f };
GLfloat materialDiffuse[] = { 1.0f,1.0f,1.0f,1.0f };
GLfloat materialSpecular[] = { 1.0f,1.0f,1.0f,1.0f };
GLfloat materialShininess = 50.0f;

bool bAnimation = false;
static GLfloat Angle = 0.0f;

//WinMain()
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int iCmdShow)
{
	//function declaration
	void Display(void);


	//variable declarations
	WNDCLASSEX wndclass;
	HWND hwnd;
	MSG msg;
	TCHAR szAppName[] = TEXT("My App");
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
		TEXT("Aniket Kadam Toggle Tea Pot A-Animate,T-Texture, L-Light"),
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
		case 'T':
		case 't':
			if (bTexture == true)
			{
				bTexture = false;
				glDisable(GL_TEXTURE_2D); //Texture Enable
			}
			else
			{
				bTexture = true;
				glEnable(GL_TEXTURE_2D); //Texture Enable
			}
			break;
		case 'L':
		case'l':
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
		case'A':
		case'a':
			if (bAnimation == true)
			{
				bAnimation = false;
			}
			else
			{
				bAnimation = true;
			}
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
	bool loadGLTexture(GLuint*, TCHAR[]);

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
	//Depth Enable Code
	glShadeModel(GL_SMOOTH);
	glClearDepth(1.0f);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	glLightfv(GL_LIGHT0, GL_AMBIENT, lightAmbient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, lightDiffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, lightSpecular);
	glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
	glEnable(GL_LIGHT0);

	glMaterialfv(GL_FRONT, GL_AMBIENT, materialAmbient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, materialDiffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, materialSpecular);
	glMaterialf(GL_FRONT, GL_SHININESS, materialShininess);

	//Loading Texture call
	loadGLTexture(&marble_Texture, MAKEINTRESOURCE(MARBLE));

	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	//warmup Resize call as
	Resize(WIN_WIDTH, WIN_HEIGHT);
}
bool loadGLTexture(GLuint* Texture, TCHAR resourceID[])
{
	// variable declaration
	bool bResult = false;
	HBITMAP hBitmap = NULL;
	BITMAP bmp;

	//code
	hBitmap = (HBITMAP)LoadImage(GetModuleHandle(NULL), resourceID, IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION);
	if (hBitmap)
	{
		bResult = TRUE;
		GetObject(hBitmap, sizeof(BITMAP), &bmp);

		//From Here OpenGL Texture  code Start
		glPixelStorei(GL_UNPACK_ALIGNMENT, 4);
		glGenTextures(1, Texture);
		glBindTexture(GL_TEXTURE_2D, *Texture);

		//Setting Texture Parameter

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);

		//Following Call Will Push The Data Into Graphic  Memmory With Graphic Driver
		gluBuild2DMipmaps(GL_TEXTURE_2D, 3, bmp.bmWidth, bmp.bmHeight, GL_BGR_EXT, GL_UNSIGNED_BYTE, bmp.bmBits);
		DeleteObject(hBitmap);
	}
	return bResult;
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

	void update(void);

	//code
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glTranslatef(0.0f, 0.0f, -1.0f);
	glRotatef(Angle, 0.0f, 1.0f, 0.0f);

	glBindTexture(GL_TEXTURE_2D, marble_Texture);
	glBegin(GL_TRIANGLES);
	for (int i = 0; i <= sizeof(face_indicies) / sizeof(face_indicies[0]); i++)
	{
		for (int j = 0; j < 3; j++)
		{
			int Vi = face_indicies[i][j];
			int Ni = face_indicies[i][j + 3];
			int Ti = face_indicies[i][j + 6];

			glNormal3f(normals[Ni][0], normals[Ni][1], normals[Ni][2]);
			glTexCoord2f(textures[Ti][0], textures[Ti][1]);
			glVertex3f(vertices[Vi][0], vertices[Vi][1], vertices[Vi][2]);
		}
	}

	glEnd();


	update();

	SwapBuffers(ghdc);
}
void update(void)
{
	if (bAnimation == true)
	{
		Angle = Angle + 0.1f;
		if (Angle >= 360.0f)
			Angle = 0.0f;
	}
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
	glDeleteTextures(1, &marble_Texture);

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



