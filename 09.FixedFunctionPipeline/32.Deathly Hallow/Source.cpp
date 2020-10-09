// Headers

#include<windows.h>
#include<stdio.h>

#include<gl/gl.h>
#include<math.h>


#pragma comment(lib,"opengl32.lib")

#define PI 3.14159

#pragma comment(lib,"glu32.lib") // 2nd change in prespective

#include<gl/glu.h>   // 1st change in prespective 

// standard template doublebuffer


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
HDC ghdc = NULL;
HGLRC ghrc;




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


	while (BDone == false)  // game loop
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
		if (dwStyle & WS_OVERLAPPEDWINDOW)
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
	//function declare
	void Resize(int, int);

	// variable declaration

	PIXELFORMATDESCRIPTOR pfd;
	INT iPixelFormatIndex;

	//code
	ghdc = GetDC(ghwnd);

	ZeroMemory(&pfd, sizeof(PIXELFORMATDESCRIPTOR));

	pfd.nSize = sizeof(PIXELFORMATDESCRIPTOR);
	pfd.nVersion = 1;
	pfd.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
	pfd.iPixelType = PFD_TYPE_RGBA;
	pfd.cColorBits = 32;
	pfd.cRedBits = 8;
	pfd.cGreenBits = 8;
	pfd.cBlueBits = 8;
	pfd.cAlphaBits = 8;

	iPixelFormatIndex = ChoosePixelFormat(ghdc, &pfd);
	if (iPixelFormatIndex == 0)
	{
		fprintf(gpfile, "Choose Pixcel Format Funtion failed\n");
		DestroyWindow(ghwnd);
	}

	if (SetPixelFormat(ghdc, iPixelFormatIndex, &pfd) == FALSE)
	{
		fprintf(gpfile, "Set Pixcel Format Fail\n");
		DestroyWindow(ghwnd);
	}
	ghrc = wglCreateContext(ghdc);

	if (ghrc == NULL)
	{
		fprintf(gpfile, "Create context Fail\n");
		DestroyWindow(ghwnd);
	}
	if (wglMakeCurrent(ghdc, ghrc) == FALSE)
	{
		fprintf(gpfile, "Make Current Fail\n");
		DestroyWindow(ghwnd);
	}

	//Set clear color (1st opengl function)

	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);  // background change 

	Resize(WIN_WIDTH, WIN_HEIGHT);      //warm up resize call


}


void Resize(int width, int height)
{
	//code
	if (height == 0)
		height = 1;


	glViewport(0, 0, (GLsizei)width, (GLsizei)height); //second opengl call

	glMatrixMode(GL_PROJECTION); //ortho prespective change 3rd change 

	glLoadIdentity();

	gluPerspective(45.0f,
		(GLfloat)width / (GLfloat)height,
		0.1f,
		100.0f); // width and height ratio 



}

void display(void)
{   
	//code

	//cirlce
	GLfloat angle;

	GLfloat x1 = 0.0f;
	GLfloat y1 = 1.0f;//a

	GLfloat x2 = -1.0f;
    GLfloat y2 = -1.0f;//b

	GLfloat x3 = 1.0f;
	GLfloat y3 = -1.0f; //c


	//GLfloat x1 = 0.0f, x2 = -1.0f, x3 = 1.0f;
	//GLfloat y1 = 1.0f, y2 = -1.0f, y3 = -1.0f;

	//GLfloat x1 = 0.0f, y1 = 1.0f;
	///GLfloat x2 = -1.0f, y2 = -1.0f;
	//GLfloat x3 = 1.0f, y3 = 1.0f;
	
	

	// calculate distance

	GLfloat a = sqrt(((x3-x2) * (x3 - x2)) + ((y3 - y2)* (y3 - y2)));

    GLfloat b = sqrt(((x3-x1) * (x3 - x1)) + ((y3 - y1)* (y3 - y1)));

	GLfloat c = sqrt(((x2-x1) * (x2 - x1)) +( (y2 - y1)* (y2 - y1)));

	//semi perimeter

	GLfloat s = (a + b + c) / 2;

	// radius 

	GLfloat r = sqrt(s*(s-a) * (s - b) * (s - c))/s;

	//Incenter

	GLfloat centerX = ((a * x1) + (b * x2) + (c * x3)) / (a + b + c);

	GLfloat centerY = ((a*y1) + (b*y2) + (c*y3))/ (a + b + c);












	glClear(GL_COLOR_BUFFER_BIT); //third call


	glMatrixMode(GL_MODELVIEW); //ortho prespective change 3rd change 

	glLoadIdentity();



	glTranslatef(0.0f,0.0f, -3.0f);   // 4th change for prespective 

	glLineWidth(3);

	glBegin(GL_LINES);

	//Triangle 
	glColor3f(1.0f, 1.0f, 1.0f);

	glVertex3f(0.0f, 1.0f, 0.0f);
	glVertex3f(-1.0f, -1.0f, 0.0f); //

	glVertex3f(-1.0f, -1.0f, 0.0f);
	glVertex3f(1.0f, -1.0f, 0.0f); //

	glVertex3f(1.0f, -1.0f, 0.0f);
	glVertex3f(0.0f, 1.0f, 0.0f);
	

	//single line

	glVertex3f(0.0f, 1.0f, 0.0f);
	glVertex3f(0.0f, -1.0f, 0.0f);
	
	


	glEnd();


	

	/*

	glBegin(GL_POINTS);

	
	

	glColor3f(1.0f, 0.0f, 0.0f);


	
	for (angle = 0.0f; angle < 2 * 3.14159; angle += 0.001f)
	{
		glVertex2f(0.618035f*cosf(angle), 0.618035f*sinf(angle)-0.38f);
	}
	
	
	// coordinates 


	
	/*
	//GLint circle_points = 1000;
	
	
	glBegin(GL_LINE_LOOP);
	glColor3f(1.0f, 1.0f, 1.0f);
	for (angle = 0.0f; angle < 2 * 3.14159; angle += 0.001f)
	{
		glVertex2f(0.618035f * cos(angle), 0.618035f * sin(angle)-0.38f );
	}

	*/


	// Incircle
	glLoadIdentity();
	glTranslatef(centerX, centerY, -3.0f);
	
	glPointSize(3);
	
	glBegin(GL_POINTS);
	
	glColor3f(1.0f, 1.0f, 1.0f);



	for (angle = 0.0f; angle < 2 * 3.14159; angle += 0.001f)
	{
		glVertex3f( r*cosf(angle),r*sinf(angle),0.0f);
	}





	glEnd();





	SwapBuffers(ghdc);//for double buffer



}

void Uninitialize(void)

{
	//code
	if (gbFullScreen == true)
	{
		dwStyle = GetWindowLong(ghwnd, GWL_STYLE); //getwindowlong:get style,get from OS
		SetWindowLong(ghwnd, GWL_STYLE, dwStyle | WS_OVERLAPPEDWINDOW);
		SetWindowPlacement(ghwnd, &wpPrev);
		SetWindowPos(ghwnd, HWND_TOP, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE | SWP_NOOWNERZORDER | SWP_NOZORDER | SWP_FRAMECHANGED);
		ShowCursor(TRUE);


	}

	if (wglGetCurrentContext() == ghrc)
	{
		wglMakeCurrent(NULL, NULL);

	}

	if (ghrc)
	{
		wglDeleteContext(ghrc);
		ghrc = NULL;


	}

	if (ghdc)
	{
		ReleaseDC(ghwnd, ghdc);
		ghdc = NULL;
	}


	if (gpfile)
	{
		fclose(gpfile);
		gpfile = NULL;
	}




}