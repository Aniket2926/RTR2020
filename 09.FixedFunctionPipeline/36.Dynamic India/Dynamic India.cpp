#include "window.h"
#include<windows.h>

#include<stdio.h>
#include<gl/gl.h>


#pragma comment(lib,"opengl32.lib")
#pragma comment(lib,"glu32.lib") // 2nd change in prespective
#pragma comment(lib, "winmm.lib")

#include<gl/glu.h>   // 1st change in prespective 
#include<math.h>
// standard template doublebuffer


//new macros
#define MY_ICON 2926
#define WIN_WIDTH 800
#define WIN_HEIGHT 600
#define MY_SONG2 103

// global function declartions

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
FILE* gpfile = NULL;

//for fading of D
GLfloat red = 0.0f;
GLfloat green = 0.0f;
GLfloat blue = 0.0f;
GLfloat green2 = 0.0f;
GLfloat red0 = 0.0f;




//for static  india  dynamic too

void I1(void);
void N(void);
void D(void);
void I2(void);
void A(void);


//global variable for fullScreen

DWORD dwStyle; // interally long ahe
WINDOWPLACEMENT wpPrev = { sizeof(WINDOWPLACEMENT) }; // initialization(inline)
bool gbFullScreen = false; // our variable g is for global, by default ti adhi fullscreen nahi
bool gbActiveWindow = false;

HWND ghwnd = NULL;
HDC ghdc = NULL;
HGLRC ghrc;

int time = 1;



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
		TEXT("Dynamic India 2926"),
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

	// for song
	PlaySound(MAKEINTRESOURCE(MY_SONG3), GetModuleHandle(NULL), SND_RESOURCE | SND_ASYNC);

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
	// flights
	void line(void);
	void flight1(void);
	void flight2(void);
	void flight3(void);

	// static declare
	/*
	static GLfloat flightmove = -+70.0f;

	static GLfloat flight2move = +70.0f;

	static GLfloat flight3move = -60.0f;

	static GLfloat linemove = 60.0f;
	static GLfloat linespeed = 0.1f;

	*/
	static GLfloat flightmove = -+180.0f;

	static GLfloat flight2move = +180.0f;

	static GLfloat flight3move = -170.0f;

	static GLfloat linemove = 170.0f;
	static GLfloat linespeed = 0.1f;

	/////////////............

	// I1
	static GLfloat x = -2.0f;
	static GLfloat speed = 0.01f;
	//N

	static GLfloat y = 3.5f;
	static GLfloat yspeed = 0.01f;

	//D
	static GLfloat z = -0.0f;
	static GLfloat zspeed = 0.01f;

	//I2
	static GLfloat y1 = -3.5f;
	static GLfloat y1speed = 0.01f;

	//A

	static GLfloat x1 = 1.7f;
	static GLfloat x1speed = 0.01f;


	//code

	glClear(GL_COLOR_BUFFER_BIT); //third call


	glMatrixMode(GL_MODELVIEW); //ortho prespective change 3rd change 

	glLoadIdentity();

	glTranslatef(x, 0.0f, -5.5f);
	//glTranslatef(moveX, 0.0f, -2.5f);

	I1();

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	//glTranslatef(-0.35f, 0.0, -5.5f);
	glTranslatef(-0.35f, y, -5.5f);

	N();

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	//glTranslatef(-0.045f, 0.0f, -3.5f);
	glTranslatef(-0.40f, 0.0f, -6.0f);
	//glScalef(z, z, z);
	D();

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	//glTranslatef(0.25f, 0.0f, -5.5f);
	glTranslatef(0.25f, y1, -5.5f);
	I2();

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	//glTranslatef(0.4f, 0.0f, -5.5f);
	glTranslatef(x1, 0.0f, -5.5f);
	A();

	//////////////////////////////////////////.......flights

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(+flightmove, -flightmove, -50);


	flight1();
	///........

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(+flightmove, -flight2move, -50);
	flight2();
	///..........

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(flight3move, 0.0f, -50);
	flight3();

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(-linemove, 0.0f, -50);
	line();


	/////.........

	flightmove = flightmove + 0.1f;

	flight2move = flight2move - 0.1f;

	flight3move = flight3move + 0.1f;//middle

	linemove = linemove - linespeed;
	if (linemove < -16.0f)
		linespeed = 0.0f;




	/*

	//I1

	x = x + speed;
	if (x > -0.7f)
		speed = 0.0f;

	//N
	
		y = y - yspeed;
		if (y <0.0f)
			yspeed = 0.0f;
	

	//I2
	
	y1 = y1 + y1speed;
	if (y1 > 0.0f)
		y1speed = 0.0f;
	
	

	//A
	x1 = x1 - speed;
	if (x1 < 0.24f)
		x1speed = 0.0f;
	


	//D

	if (red <= 1.0f)
		red = red + 0.005f;

	if (green <= 1.0f)
		green = green + 0.005f;

	if (green2 <= 0.5f)
		green2 = green2 + 0.005f;
		*/
		//I1

	if (x = x + speed)
	{
		if (x > -0.7f)
			speed = 0.0f;
	}
	//N
	if (speed == 0.0f)
	{
		y = y - yspeed;
		if (y < 0.0f)
			yspeed = 0.0f;

	}
	//I2
	if (yspeed == 0.0f)
	{

		y1 = y1 + y1speed;
		if (y1 > 0.0f)
			y1speed = 0.0f;

	}

	//a

	x1 = x1 - speed;
	if (x1 < 0.24f)
		x1speed = 0.0f;



	//D

	if (red <= 1.0f)
		red = red + 0.0005f;

	if (green <= 1.0f)
		green = green + 0.0005f;

	if (green2 <= 0.5f)
		green2 = green2 + 0.0005f;



	SwapBuffers(ghdc);//for double buffer



}

void line(void)
{
	glLineWidth(2);
	glBegin(GL_LINES);

	// orange lie
	glColor3f(1.0f, 0.5f, 0.0f);	//Orange color
	glVertex3f(-7.0f, 0.5, 0.0f); // i1

	glVertex3f(-4.0f, 0.5f, 0.0f); //J1


	// white line
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-7.0f, 0.0f, 0.0f); //k1

	glVertex3f(-4.0f, 0.0f, 0.0f);//z

	// Green line 
	glColor3f(0.0f, 1.0f, 0.0f);	//Green color
	glVertex3f(-7.0f, -0.5f, 0.0f);//L1
	glVertex3f(-4.0f, -0.5f, 0.0f);//M1
	glEnd();


}

void I1(void)
{
	glLineWidth(8.0f);
	glBegin(GL_LINES);
	glColor3f(1.0f, 0.5f, 0.0f);
	glVertex3f(-0.9f, 0.9f, 0.0f);

	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(-0.9f, -0.9f, 0.0f);

	glEnd();



}

void N(void)
{
	glLineWidth(8.0f);
	glBegin(GL_LINES);
	//Left line of N
	glColor3f(1.0f, 0.5f, 0.0f);	//Orange color
	glVertex3f(-0.85f, 0.9f, 0.0f);

	glColor3f(0.0f, 1.0f, 0.0f);	//Green color
	glVertex3f(-0.85f, -0.9f, 0.0f);

	//Right line of N
	glColor3f(1.0f, 0.5f, 0.0f);
	glVertex3f(-0.4f, 0.9f, 0.0f);

	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(-0.4f, -0.9f, 0.0f);

	//Diagonal line of N
	glColor3f(1.0f, 0.5f, 0.0f);
	glVertex3f(-0.85f, 0.9f, 0.0f);

	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(-0.4f, -0.9f, 0.0f);

	glEnd();
}


void D(void)
{
	glLineWidth(8.0f);
	glBegin(GL_LINES);

	//Top line of D

	//glColor3f(1.0f, 0.5f, 0.0f);	//Orange color
	glColor3f(red, green2, blue);

	glVertex3f(0.0f, 1.0f, 0.0f);
	glVertex3f(0.2f, 1.0f, 0.0f);

	glVertex3f(0.2f, 1.0f, 0.0f);
	glVertex3f(0.4f, 0.8f, 0.0f);


	//Bottom line of D

	//glColor3f(0.0f, 1.0f, 0.0f);	//Green color
	glColor3f(red0, green, blue);

	glVertex3f(0.0f, -1.0f, 0.0f);
	glVertex3f(0.2f, -1.0f, 0.0f);

	glVertex3f(0.4f, -0.8f, 0.0f);
	glVertex3f(0.2f, -1.0f, 0.0f);


	//Left line of D

	//glColor3f(1.0f, 0.5f, 0.0f);

	glColor3f(red, green2, blue);



	glVertex3f(0.0f, 1.0f, 0.0f);

	//glColor3f(0.0f, 1.0f, 0.0f);

	glColor3f(red0, green, blue);

	glVertex3f(0.0f, -1.0f, 0.0f);

	//Right line of D

	//glColor3f(1.0f, 0.5f, 0.0f);

	glColor3f(red, green2, blue);

	glVertex3f(0.4f, 0.8f, 0.0f);

	//glColor3f(0.0f, 1.0f, 0.0f);
	glColor3f(red0, green, blue);

	glVertex3f(0.4f, -0.8f, 0.0f);

	//
	glEnd();


}

void I2(void)
{
	glLineWidth(8.0f);
	glBegin(GL_LINES);
	glColor3f(1.0f, 0.5f, 0.0f);
	glVertex3f(0.2f, 0.9f, 0.0f);

	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(0.2f, -0.9f, 0.0f);

	glEnd();
}

void A(void)
{
	glLineWidth(8.0f);
	glBegin(GL_LINES);

	//Left line of A

	glColor3f(1.0f, 0.5f, 0.0f);
	glVertex3f(0.75f, 0.9f, 0.0f);

	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(0.3f, -0.9f, 0.0f);

	//Right line of A

	glColor3f(1.0f, 0.5f, 0.0f);
	glVertex3f(0.75f, 0.9f, 0.0f);

	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(1.2f, -0.9f, 0.0f);

	
	/*

	// India tri color line....Center line A


	glLineWidth(8.0f);

	//Orange line
	glColor3f(1.0f, 0.5f, 0.0f);	//Orange color
	glVertex3f(0.528f, 0.02f, 0.0f);
	glVertex3f(0.974f, 0.02f, 0.0f);

	//................................White line
	glColor3f(1.0f, 1.0f, 1.0f);	//White
	glVertex3f(0.52f, 0.0f, 0.0f);
	glVertex3f(0.98f, 0.0f, 0.0f);

	//...............................Green line
	glColor3f(0.0f, 1.0f, 0.0f);	//Green color
	glVertex3f(0.513f, -0.02f, 0.0f);
	glVertex3f(0.985f, -0.02f, 0.0f);
	*/

	glEnd();
	
}







void flight1(void)
{

	GLfloat angle;




	glBegin(GL_QUADS);

	//fuselage
	//3 / 0.4 / 0.7
	glColor3f(0.3f, 0.4f, 0.6f);



	glVertex3f(-2.5f, 0.5f, 0.0f); //a

	glVertex3f(2.0f, 0.5f, 0.0f); //b

	glVertex3f(2.0f, -0.5f, 0.0f);//c

	glVertex3f(-2.5f, -0.5f, 0.0f);//d

	////aero blade box

	glVertex3f(2.0f, 0.2f, 0.0f); //E

	glVertex3f(2.2f, 0.2f, 0.0f);//f

	glVertex3f(2.2f, -0.2f, 0.0f);//G

	glVertex3f(2.0f, -0.2f, 0.0f); //H

	////

	/// Wings

	glColor3f(0.3f, 0.4f, 0.5f);

	glVertex3f(1.0f, 0.5, 0.0f); // N

	glVertex3f(1.0f, 4.0f, 0.0f); //0

	glVertex3f(0.0f, 4.0f, 0.0f); //p

	glVertex3f(-1.0071384771295f, 0.5f, 0.0f); //Q
	/////

	glVertex3f(1.0f, -0.5, 0.0f); //R

	glVertex3f(1.0f, -4.0f, 0.0f); //s

	glVertex3f(0.0f, -4.0f, 0.0f); //t

	glVertex3f(-1.0071384771295f, -0.5f, 0.0f);



	glEnd();

	glPointSize(2.0);

	glBegin(GL_POINTS);

	glColor3f(0.9f, 0.7f, 0.0f);

	for (angle = 0.0f; angle < 2 * 3.14159; angle += 0.001f)
	{
		glVertex2f(0.318035f * cosf(angle), 0.318035f * sinf(angle) - 1.99f);
	}

	glColor3f(1.0f, 1.0f, 1.0f);

	for (angle = 0.0f; angle < 2 * 3.14159; angle += 0.001f)
	{
		glVertex2f(0.218035f * cosf(angle), 0.218035f * sinf(angle) - 1.99f);
	}

	glColor3f(0.4f, 0.6f, 0.5f);  //0.4/0.6/0.5

	for (angle = 0.0f; angle < 2 * 3.14159; angle += 0.001f)
	{
		glVertex2f(0.118035f * cosf(angle), 0.118035f * sinf(angle) - 1.99f);
	}

	//

	glColor3f(0.9f, 0.7f, 0.0f);

	for (angle = 0.0f; angle < 2 * 3.14159; angle += 0.001f)
	{
		glVertex2f(0.318035f * cosf(angle), 0.318035f * sinf(angle) + 1.99f);
	}

	glColor3f(1.0f, 1.0f, 1.0f);

	for (angle = 0.0f; angle < 2 * 3.14159; angle += 0.001f)
	{
		glVertex2f(0.218035f * cosf(angle), 0.218035f * sinf(angle) + 1.99f);
	}

	glColor3f(0.4f, 0.6f, 0.5f);  //0.4/0.6/0.5

	for (angle = 0.0f; angle < 2 * 3.14159; angle += 0.001f)
	{
		glVertex2f(0.118035f * cosf(angle), 0.118035f * sinf(angle) + 1.99f);
	}



	glEnd();





	// Aero Blades

	glBegin(GL_TRIANGLES);



	glColor3f(0.3f, 0.4f, 0.6f);

	// Vertical Sabilizer 
	glVertex3f(-2.5f, 0.5f, 0.0f); //a

	glVertex3f(-2.5f, -0.5f, 0.0f);//d

	glVertex3f(-4.0f, 0.0f, 0.0f);//z


	// turbo blades
	glVertex3f(2.2f, 1.0f, 0.0f); //I

	glVertex3f(2.4f, 1.0f, 0.0f); //J

	glVertex3f(2.2f, 0.2f, 0.0f);//f


	glVertex3f(2.2f, -1.0f, 0.0f); //k

	glVertex3f(2.4f, -1.0f, 0.0f); //L

	glVertex3f(2.2f, -0.2f, 0.0f);//g

	//

	//Turbo blades

	glVertex3f(2.2f, 0.2f, 0.0f);//f

	glVertex3f(2.4f, 0.0f, 0.0f);//M

	glVertex3f(2.2f, -0.2f, 0.0f);//g





	glEnd();






	/////////////////

	glBegin(GL_POLYGON);

	// ELEVATORS

	glColor3f(0.3f, 0.4f, 0.5f);


	glVertex3f(-2.5f, 0.5f, 0.0f); //a

	glVertex3f(-2.5f, -0.5f, 0.0f);//d

	//
	glVertex3f(-3.0f, -2.0f, 0.0f); // b1

	glVertex3f(-4.0f, -2.0f, 0.0f); //a1

	glVertex3f(-4.0f, 0.0f, 0.0f);//z

	glVertex3f(-4.0f, 2.0f, 0.0f); //w
	glVertex3f(-3.0f, 2.0f, 0.0f); //v

	glEnd();




	// Vertical Stabilizer


	glBegin(GL_TRIANGLES);
	glColor3f(0.3f, 0.4f, 0.6f);


	glVertex3f(-2.5f, 0.5f, 0.0f); //a

	glVertex3f(-2.5f, -0.5f, 0.0f);//d

	glVertex3f(-4.0f, 0.0f, 0.0f);//z

	glEnd();

	glLineWidth(2);
	glBegin(GL_LINES);

	// orange lie
	glColor3f(1.0f, 0.5f, 0.0f);	//Orange color
	glVertex3f(-8.0f, 0.5, 0.0f); // i1

	glVertex3f(-4.0f, 0.5f, 0.0f); //J1
	

	// white line
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-8.0f, 0.0f, 0.0f); //k1

	glVertex3f(-4.0f, 0.0f, 0.0f);//z

	// Green line 
	glColor3f(0.0f, 1.0f, 0.0f);	//Green color
	glVertex3f(-8.0f, -0.5f, 0.0f);//L1
	glVertex3f(-4.0f, -0.5f, 0.0f);//M1

	glEnd();
	// aircraft body lines

	glLineWidth(0.05);
	glBegin(GL_LINES);


	glColor3f(0.5f, 0.6f, 0.6f);
	glVertex3f(1.0f, 0.5f, 0.0f); // N0.5/0.6/0.9   0.4/0.5/0.6

	glVertex3f(1.0f, -0.5f, 0.0f); //R


	//

	glVertex3f(0.0f, 0.5f, 0.0f); //R1

	glVertex3f(0.0f, -0.5f, 0.0f); //s1

	//
	glVertex3f(0.0f, 0.0f, 0.0f); //t1

	glVertex3f(-2.5f, 0.0f, 0.0f); //u1

	//
	glVertex3f(-3.5f, 1.0f, 0.0f); 

	glVertex3f(-3.0f, 1.0f, 0.0f); 

	glVertex3f(-3.5f, -1.0f, 0.0f);

	glVertex3f(-3.0f, -1.0f, 0.0f);

	glEnd();

}

void flight2(void)
{

	GLfloat angle;




	glBegin(GL_QUADS);

	//fuselage
	//3 / 0.4 / 0.7
	glColor3f(0.3f, 0.4f, 0.6f);



	glVertex3f(-2.5f, 0.5f, 0.0f); //a

	glVertex3f(2.0f, 0.5f, 0.0f); //b

	glVertex3f(2.0f, -0.5f, 0.0f);//c

	glVertex3f(-2.5f, -0.5f, 0.0f);//d

	////aero blade box

	glVertex3f(2.0f, 0.2f, 0.0f); //E

	glVertex3f(2.2f, 0.2f, 0.0f);//f

	glVertex3f(2.2f, -0.2f, 0.0f);//G

	glVertex3f(2.0f, -0.2f, 0.0f); //H

	////

	/// Wings

	glColor3f(0.3f, 0.4f, 0.5f);

	glVertex3f(1.0f, 0.5, 0.0f); // N

	glVertex3f(1.0f, 4.0f, 0.0f); //0

	glVertex3f(0.0f, 4.0f, 0.0f); //p

	glVertex3f(-1.0071384771295f, 0.5f, 0.0f); //Q
	/////

	glVertex3f(1.0f, -0.5, 0.0f); //R

	glVertex3f(1.0f, -4.0f, 0.0f); //s

	glVertex3f(0.0f, -4.0f, 0.0f); //t

	glVertex3f(-1.0071384771295f, -0.5f, 0.0f);



	glEnd();

	glPointSize(2.0);

	glBegin(GL_POINTS);

	glColor3f(0.9f, 0.7f, 0.0f);

	for (angle = 0.0f; angle < 2 * 3.14159; angle += 0.001f)
	{
		glVertex2f(0.318035f * cosf(angle), 0.318035f * sinf(angle) - 1.99f);
	}

	glColor3f(1.0f, 1.0f, 1.0f);

	for (angle = 0.0f; angle < 2 * 3.14159; angle += 0.001f)
	{
		glVertex2f(0.218035f * cosf(angle), 0.218035f * sinf(angle) - 1.99f);
	}

	glColor3f(0.4f, 0.6f, 0.5f);  //0.4/0.6/0.5

	for (angle = 0.0f; angle < 2 * 3.14159; angle += 0.001f)
	{
		glVertex2f(0.118035f * cosf(angle), 0.118035f * sinf(angle) - 1.99f);
	}

	//

	glColor3f(0.9f, 0.7f, 0.0f);

	for (angle = 0.0f; angle < 2 * 3.14159; angle += 0.001f)
	{
		glVertex2f(0.318035f * cosf(angle), 0.318035f * sinf(angle) + 1.99f);
	}

	glColor3f(1.0f, 1.0f, 1.0f);

	for (angle = 0.0f; angle < 2 * 3.14159; angle += 0.001f)
	{
		glVertex2f(0.218035f * cosf(angle), 0.218035f * sinf(angle) + 1.99f);
	}

	glColor3f(0.4f, 0.6f, 0.5f);  //0.4/0.6/0.5

	for (angle = 0.0f; angle < 2 * 3.14159; angle += 0.001f)
	{
		glVertex2f(0.118035f * cosf(angle), 0.118035f * sinf(angle) + 1.99f);
	}



	glEnd();





	// Aero Blades

	glBegin(GL_TRIANGLES);



	glColor3f(0.3f, 0.4f, 0.6f);

	// Vertical Sabilizer 
	glVertex3f(-2.5f, 0.5f, 0.0f); //a

	glVertex3f(-2.5f, -0.5f, 0.0f);//d

	glVertex3f(-4.0f, 0.0f, 0.0f);//z


	// turbo blades
	glVertex3f(2.2f, 1.0f, 0.0f); //I

	glVertex3f(2.4f, 1.0f, 0.0f); //J

	glVertex3f(2.2f, 0.2f, 0.0f);//f


	glVertex3f(2.2f, -1.0f, 0.0f); //k

	glVertex3f(2.4f, -1.0f, 0.0f); //L

	glVertex3f(2.2f, -0.2f, 0.0f);//g

	//

	//Turbo blades

	glVertex3f(2.2f, 0.2f, 0.0f);//f

	glVertex3f(2.4f, 0.0f, 0.0f);//M

	glVertex3f(2.2f, -0.2f, 0.0f);//g





	glEnd();






	/////////////////

	glBegin(GL_POLYGON);

	// ELEVATORS

	glColor3f(0.3f, 0.4f, 0.5f);


	glVertex3f(-2.5f, 0.5f, 0.0f); //a

	glVertex3f(-2.5f, -0.5f, 0.0f);//d

	//
	glVertex3f(-3.0f, -2.0f, 0.0f); // b1

	glVertex3f(-4.0f, -2.0f, 0.0f); //a1

	glVertex3f(-4.0f, 0.0f, 0.0f);//z

	glVertex3f(-4.0f, 2.0f, 0.0f); //w
	glVertex3f(-3.0f, 2.0f, 0.0f); //v

	glEnd();




	// Vertical Stabilizer


	glBegin(GL_TRIANGLES);
	glColor3f(0.3f, 0.4f, 0.6f);


	glVertex3f(-2.5f, 0.5f, 0.0f); //a

	glVertex3f(-2.5f, -0.5f, 0.0f);//d

	glVertex3f(-4.0f, 0.0f, 0.0f);//z

	glEnd();

	glLineWidth(2);
	glBegin(GL_LINES);

	// orange line
	glColor3f(1.0f, 0.5f, 0.0f);	//Orange color
	glVertex3f(-8.0f, 0.5, 0.0f); // i1

	glVertex3f(-4.0f, 0.5f, 0.0f); //J1


	// white line
	glColor3f(1.0f, 1.0f, 1.0f);	
	glVertex3f(-8.0f, 0.0f, 0.0f); //k1

	glVertex3f(-4.0f, 0.0f, 0.0f);//z

	// Green line 
	glColor3f(0.0f, 1.0f, 0.0f);	//Green color

	glVertex3f(-8.0f, -0.5f, 0.0f);//L1
	glVertex3f(-4.0f, -0.5f, 0.0f);//M1
	glEnd();

	glLineWidth(0.05);
	glBegin(GL_LINES);


	glColor3f(0.5f, 0.6f, 0.6f);
	glVertex3f(1.0f, 0.5f, 0.0f); // N0.5/0.6/0.9   0.4/0.5/0.6

	glVertex3f(1.0f, -0.5f, 0.0f); //R


	//

	glVertex3f(0.0f, 0.5f, 0.0f); //R1

	glVertex3f(0.0f, -0.5f, 0.0f); //s1

	//
	glVertex3f(0.0f, 0.0f, 0.0f); //t1

	glVertex3f(-2.5f, 0.0f, 0.0f); //u1

	//
	glVertex3f(-3.5f, 1.0f, 0.0f);

	glVertex3f(-3.0f, 1.0f, 0.0f);

	glVertex3f(-3.5f, -1.0f, 0.0f);

	glVertex3f(-3.0f, -1.0f, 0.0f);

	glEnd();




}

void flight3(void)
{

	GLfloat angle;




	glBegin(GL_QUADS);

	//fuselage
	//3 / 0.4 / 0.7
	glColor3f(0.3f, 0.4f, 0.6f);



	glVertex3f(-2.5f, 0.5f, 0.0f); //a

	glVertex3f(2.0f, 0.5f, 0.0f); //b

	glVertex3f(2.0f, -0.5f, 0.0f);//c

	glVertex3f(-2.5f, -0.5f, 0.0f);//d

	////aero blade box

	glVertex3f(2.0f, 0.2f, 0.0f); //E

	glVertex3f(2.2f, 0.2f, 0.0f);//f

	glVertex3f(2.2f, -0.2f, 0.0f);//G

	glVertex3f(2.0f, -0.2f, 0.0f); //H

	////

	/// Wings

	glColor3f(0.3f, 0.4f, 0.5f);

	glVertex3f(1.0f, 0.5, 0.0f); // N

	glVertex3f(1.0f, 4.0f, 0.0f); //0

	glVertex3f(0.0f, 4.0f, 0.0f); //p

	glVertex3f(-1.0071384771295f, 0.5f, 0.0f); //Q
	/////

	glVertex3f(1.0f, -0.5, 0.0f); //R

	glVertex3f(1.0f, -4.0f, 0.0f); //s

	glVertex3f(0.0f, -4.0f, 0.0f); //t

	glVertex3f(-1.0071384771295f, -0.5f, 0.0f);



	glEnd();

	glPointSize(2.0);

	glBegin(GL_POINTS);

	glColor3f(0.9f, 0.7f, 0.0f);

	for (angle = 0.0f; angle < 2 * 3.14159; angle += 0.001f)
	{
		glVertex2f(0.318035f * cosf(angle), 0.318035f * sinf(angle) - 1.99f);
	}

	glColor3f(1.0f, 1.0f, 1.0f);

	for (angle = 0.0f; angle < 2 * 3.14159; angle += 0.001f)
	{
		glVertex2f(0.218035f * cosf(angle), 0.218035f * sinf(angle) - 1.99f);
	}

	glColor3f(0.4f, 0.6f, 0.5f);  //0.4/0.6/0.5

	for (angle = 0.0f; angle < 2 * 3.14159; angle += 0.001f)
	{
		glVertex2f(0.118035f * cosf(angle), 0.118035f * sinf(angle) - 1.99f);
	}

	//

	glColor3f(0.9f, 0.7f, 0.0f);

	for (angle = 0.0f; angle < 2 * 3.14159; angle += 0.001f)
	{
		glVertex2f(0.318035f * cosf(angle), 0.318035f * sinf(angle) + 1.99f);
	}

	glColor3f(1.0f, 1.0f, 1.0f);

	for (angle = 0.0f; angle < 2 * 3.14159; angle += 0.001f)
	{
		glVertex2f(0.218035f * cosf(angle), 0.218035f * sinf(angle) + 1.99f);
	}

	glColor3f(0.4f, 0.6f, 0.5f);  //0.4/0.6/0.5

	for (angle = 0.0f; angle < 2 * 3.14159; angle += 0.001f)
	{
		glVertex2f(0.118035f * cosf(angle), 0.118035f * sinf(angle) + 1.99f);
	}



	glEnd();





	// Aero Blades

	glBegin(GL_TRIANGLES);



	glColor3f(0.3f, 0.4f, 0.6f);

	// Vertical Sabilizer 
	glVertex3f(-2.5f, 0.5f, 0.0f); //a

	glVertex3f(-2.5f, -0.5f, 0.0f);//d

	glVertex3f(-4.0f, 0.0f, 0.0f);//z


	// turbo blades
	glVertex3f(2.2f, 1.0f, 0.0f); //I

	glVertex3f(2.4f, 1.0f, 0.0f); //J

	glVertex3f(2.2f, 0.2f, 0.0f);//f


	glVertex3f(2.2f, -1.0f, 0.0f); //k

	glVertex3f(2.4f, -1.0f, 0.0f); //L

	glVertex3f(2.2f, -0.2f, 0.0f);//g

	//

	//Turbo blades

	glVertex3f(2.2f, 0.2f, 0.0f);//f

	glVertex3f(2.4f, 0.0f, 0.0f);//M

	glVertex3f(2.2f, -0.2f, 0.0f);//g





	glEnd();






	/////////////////

	glBegin(GL_POLYGON);

	// ELEVATORS

	glColor3f(0.3f, 0.4f, 0.5f);


	glVertex3f(-2.5f, 0.5f, 0.0f); //a

	glVertex3f(-2.5f, -0.5f, 0.0f);//d

	//
	glVertex3f(-3.0f, -2.0f, 0.0f); // b1

	glVertex3f(-4.0f, -2.0f, 0.0f); //a1

	glVertex3f(-4.0f, 0.0f, 0.0f);//z

	glVertex3f(-4.0f, 2.0f, 0.0f); //w
	glVertex3f(-3.0f, 2.0f, 0.0f); //v

	glEnd();




	// Vertical Stabilizer


	glBegin(GL_TRIANGLES);
	glColor3f(0.3f, 0.4f, 0.6f);


	glVertex3f(-2.5f, 0.5f, 0.0f); //a

	glVertex3f(-2.5f, -0.5f, 0.0f);//d

	glVertex3f(-4.0f, 0.0f, 0.0f);//z

	glEnd();

	glLineWidth(2);
	glBegin(GL_LINES);

	// orange lie
	glColor3f(1.0f, 0.5f, 0.0f);	//Orange color
	glVertex3f(-8.0f, 0.5, 0.0f); // i1

	glVertex3f(-4.0f, 0.5f, 0.0f); //J1


	// white line
	glColor3f(1.0f, 1.0f, 1.0f);	//Orange color
	glVertex3f(-8.0f, 0.0f, 0.0f); //k1

	glVertex3f(-4.0f, 0.0f, 0.0f);//z

	// Green line 
	glColor3f(0.0f, 1.0f, 0.0f);	//Green color
	
	glVertex3f(-8.0f, -0.5f, 0.0f);//L1
	glVertex3f(-4.0f, -0.5f, 0.0f);//M1
	glEnd();

	glLineWidth(0.05);
	glBegin(GL_LINES);


	glColor3f(0.5f, 0.6f, 0.6f);
	glVertex3f(1.0f, 0.5f, 0.0f); // N0.5/0.6/0.9   0.4/0.5/0.6

	glVertex3f(1.0f, -0.5f, 0.0f); //R


	//

	glVertex3f(0.0f, 0.5f, 0.0f); //R1

	glVertex3f(0.0f, -0.5f, 0.0f); //s1

	//
	glVertex3f(0.0f, 0.0f, 0.0f); //t1

	glVertex3f(-2.5f, 0.0f, 0.0f); //u1

	//
	glVertex3f(-3.5f, 1.0f, 0.0f);

	glVertex3f(-3.0f, 1.0f, 0.0f);

	glVertex3f(-3.5f, -1.0f, 0.0f);

	glVertex3f(-3.0f, -1.0f, 0.0f);

	glEnd();


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





