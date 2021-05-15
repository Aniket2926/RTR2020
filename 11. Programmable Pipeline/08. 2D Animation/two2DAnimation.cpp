#include <windows.h>
#include <stdio.h> 

#include<gl\glew.h>  // always on top of gl\gl.h

#include <gl\GL.h> 

#include "vmath.h" // red book barobr aleli file 8th edition and with super bible 

#pragma comment(lib, "glew32.lib") 
#pragma comment(lib, "opengL32.lib") 

#define WIN_WIDTH 800 
#define WIN_HEIGHT 600 
#define MY_ICON 2926

//new lib

using namespace vmath;

// One vertex which is having all this properties 
enum
{
	AK_ATTRIBUTE_POSITION = 0,
	AK_ATTRIBUTE_COLOR,
	AK_ATTRIBUTE_NORMAL,
	AK_ATTRIBUTE_TEXTURECOORD,
};

//Prototype Of WndProc() declared Globally 

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

//Global variable declarations 

FILE* gpFile = NULL;
HWND ghwnd = NULL;
HDC ghdc = NULL;
HGLRC ghrc = NULL;

DWORD dwStyle;
WINDOWPLACEMENT wpPrev = { sizeof(WINDOWPLACEMENT) };

bool gbActiveWindow = false;
bool gbEscapeKeyIsPressed = false;
bool gbFullscreen = false;




GLuint gVertexShaderObject;
GLuint gFragmentShaderObject;
GLuint gShaderProgramObject;

// ortho

GLuint vao;// vertex array objects
GLuint vbo_position; // vertex buffer objects
GLuint mvpUniform;

// color
GLuint vbo_color;

// Change 1 for shapes 

GLuint vbo_Triangle_Position;
GLuint vbo_Triangle_Color;
GLuint vao_Triangle;

GLuint vao_Square;
GLuint vbo_Square_Color;
GLuint vbo_Square_Position;

// Animation rotation  ........change 1

GLfloat angletriangle = 0.0f;
GLfloat anglesquare = 0.0f;





mat4 PerspectiveProjectionMatrix; // change 1 
mat4 TranslateMatrix;




//main() 
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int iCmdShow)
{
	//function prototype 
	void initialize(void);
	void uninitialize(void);
	void display(void);
	void Update(void);


	//variable declaration 

	WNDCLASSEX wndclass;
	HWND hwnd;
	MSG msg;
	TCHAR szClassName[] = TEXT("OpenGLPP");
	bool bDone = false;

	//code 

	if (fopen_s(&gpFile, "Log.txt", "w") != 0)
	{
		MessageBox(NULL, TEXT("Log File Can Not Be Created\nExitting ..."), TEXT("Error"), MB_OK | MB_TOPMOST | MB_ICONSTOP);
		exit(0);
	}
	else
	{

		fprintf(gpFile, "Log File Is Successfully Opened.\n");

	}

	wndclass.cbSize = sizeof(WNDCLASSEX);
	wndclass.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
	wndclass.cbClsExtra = 0;
	wndclass.cbWndExtra = 0;
	wndclass.hInstance = hInstance;
	wndclass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	wndclass.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(MY_ICON));
	wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndclass.hIconSm = LoadIcon(hInstance, MAKEINTRESOURCE(MY_ICON));
	wndclass.lpfnWndProc = WndProc;
	wndclass.lpszClassName = szClassName;
	wndclass.lpszMenuName = NULL;

	RegisterClassEx(&wndclass);


	hwnd = CreateWindowEx(WS_EX_APPWINDOW,
		szClassName,
		TEXT("OpenGL Programmable Pipeline : MultiColor Triangle"),
		WS_OVERLAPPEDWINDOW | WS_CLIPCHILDREN | WS_CLIPSIBLINGS | WS_VISIBLE,
		100,
		100,
		WIN_WIDTH,
		WIN_HEIGHT,
		NULL,
		NULL,
		hInstance,
		NULL);

	ghwnd = hwnd;


	ShowWindow(hwnd, iCmdShow);
	SetForegroundWindow(hwnd);
	SetFocus(hwnd);
	initialize();

	// game loop

	while (bDone == false)

	{

		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))

		{

			if (msg.message == WM_QUIT)
				bDone = true;

			else

			{
				TranslateMessage(&msg);
				DispatchMessage(&msg);

			}

		}

		else

		{
			display();

			// Update for rotation
			Update();

			if (gbActiveWindow == true)
			{
				if (gbEscapeKeyIsPressed == true)
					bDone = true;

			}

		}

	}

	uninitialize();
	return((int)msg.wParam);
}



//WndProc()

LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)

{

	//function prototype

	void resize(int, int);
	void ToggleFullscreen(void);
	void uninitialize(void);


	//code

	switch (iMsg)
	{

	case WM_ACTIVATE:
		if (HIWORD(wParam) == 0)

			gbActiveWindow = true;

		else

			gbActiveWindow = false;

		break;

	case WM_ERASEBKGND:

		return(0);

	case WM_SIZE:

		resize(LOWORD(lParam), HIWORD(lParam));

		break;

	case WM_KEYDOWN:

		switch (wParam)
		{
		case VK_ESCAPE:

			gbEscapeKeyIsPressed = true;

			break;

		case 0x46:

			if (gbFullscreen == false)
			{

				ToggleFullscreen();
				gbFullscreen = true;
			}

			else
			{

				ToggleFullscreen();
				gbFullscreen = false;
			}

			break;

		default:

			break;

		}

		break;

	case WM_LBUTTONDOWN:

		break;

	case WM_CLOSE:

		uninitialize();

		break;

	case WM_DESTROY:

		PostQuitMessage(0);

		break;

	default:

		break;
	}



	return(DefWindowProc(hwnd, iMsg, wParam, lParam));

}


void ToggleFullscreen(void)

{

	//variable declarations

	MONITORINFO mi;

	//code

	if (gbFullscreen == false)
	{
		dwStyle = GetWindowLong(ghwnd, GWL_STYLE);

		if (dwStyle & WS_OVERLAPPEDWINDOW)
		{

			mi = { sizeof(MONITORINFO) };

			if (GetWindowPlacement(ghwnd, &wpPrev) && GetMonitorInfo(MonitorFromWindow(ghwnd, MONITORINFOF_PRIMARY), &mi))
			{

				SetWindowLong(ghwnd, GWL_STYLE, dwStyle & ~WS_OVERLAPPEDWINDOW);
				SetWindowPos(ghwnd, HWND_TOP, mi.rcMonitor.left,
					mi.rcMonitor.top, mi.rcMonitor.right - mi.rcMonitor.left, mi.rcMonitor.bottom - mi.rcMonitor.top, SWP_NOZORDER | SWP_FRAMECHANGED);
			}

		}

		ShowCursor(FALSE);

	}



	else
	{

		//code

		SetWindowLong(ghwnd, GWL_STYLE, dwStyle | WS_OVERLAPPEDWINDOW);

		SetWindowPlacement(ghwnd, &wpPrev);

		SetWindowPos(ghwnd, HWND_TOP, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE | SWP_NOOWNERZORDER | SWP_NOZORDER | SWP_FRAMECHANGED);
		ShowCursor(TRUE);

	}

}


void initialize(void)

{
	//function prototypes

	void uninitialize(void);
	void resize(int, int);

	//variable declarations

	PIXELFORMATDESCRIPTOR pfd;

	int iPixelFormatIndex;



	//code

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
	pfd.cDepthBits = 32;

	ghdc = GetDC(ghwnd);

	iPixelFormatIndex = ChoosePixelFormat(ghdc, &pfd);

	if (iPixelFormatIndex == 0)
	{
		ReleaseDC(ghwnd, ghdc);
		ghdc = NULL;
	}

	if (SetPixelFormat(ghdc, iPixelFormatIndex, &pfd) == false)

	{

		ReleaseDC(ghwnd, ghdc);

		ghdc = NULL;

	}




	ghrc = wglCreateContext(ghdc);


	if (ghrc == NULL)

	{

		ReleaseDC(ghwnd, ghdc);
		ghdc = NULL;

	}




	if (wglMakeCurrent(ghdc, ghrc) == false)


	{
		wglDeleteContext(ghrc);
		ghrc = NULL;
		ReleaseDC(ghwnd, ghdc);
		ghdc = NULL;

	}

	GLenum glew_error = glewInit();


	if (glew_error != GLEW_OK)
	{
		wglDeleteContext(ghrc);
		ghrc = NULL;
		ReleaseDC(ghwnd, ghdc);
		ghdc = NULL;

	}

	// OpenGL Extension Log file 

	fprintf(gpFile, "OpenGL Vendor: %s\n", glGetString(GL_VENDOR));
	fprintf(gpFile, "OpenGL Render:%s\n", glGetString(GL_RENDERER));
	fprintf(gpFile, "OpenGL version:%s\n", glGetString(GL_VERSION));
	fprintf(gpFile, "GLSL version:%s\n", glGetString(GL_SHADING_LANGUAGE_VERSION));

	//OpenGL Enabled extesion 

	GLint numExt;

	glGetIntegerv(GL_NUM_EXTENSIONS, &numExt);		// Returns the number of available extensions



	for (int i = 0; i < numExt; i++)
	{
		fprintf(gpFile, " %s\n", glGetStringi(GL_EXTENSIONS, i));
	}
	fprintf(gpFile, "\n");


	//major change


  // *** VERTEX SHADER ***

  // create shader

	gVertexShaderObject = glCreateShader(GL_VERTEX_SHADER);

	// provide source code to shader  // change 2 vcolor, in and out
	const GLchar* vertexShaderSourceCode =

		"#version 450 core" \
		"\n" \
		"in vec4 vPosition;" \
		"in vec4 vColor;"\
		"out vec4 out_color;"\

		"uniform mat4 u_mvpmatrix;" \
		"void main(void)" \

		"{"\
		"gl_Position =u_mvpmatrix * vPosition;" \
		"out_color = vColor;"\

		"}";

	glShaderSource(gVertexShaderObject, 1, (const GLchar**)&vertexShaderSourceCode, NULL);



	// compile shader 

	glCompileShader(gVertexShaderObject);

	GLint iInfoLogLength = 0;
	GLint iShaderCompiledStatus = 0;
	char* szInfoLog = NULL;

	glGetShaderiv(gVertexShaderObject, GL_COMPILE_STATUS, &iShaderCompiledStatus);
	if (iShaderCompiledStatus == GL_FALSE)
	{
		glGetShaderiv(gVertexShaderObject, GL_INFO_LOG_LENGTH, &iInfoLogLength);

		if (iInfoLogLength > 0);
		{
			szInfoLog = (char*)malloc(iInfoLogLength);

			if (szInfoLog != NULL)
			{
				GLsizei written;
				glGetShaderInfoLog(gVertexShaderObject, iInfoLogLength, &written, szInfoLog);
				free(szInfoLog);
				DestroyWindow(ghwnd);
			}
		}
	}





	// *** FRAGMENT SHADER ***


	// create shader
	gFragmentShaderObject = glCreateShader(GL_FRAGMENT_SHADER);

	// provide source code to shader

	const GLchar* fragmentShaderSourceCode =
		"#version 450 core " \
		"\n" \
		"in vec4 out_color;" \
		"out vec4 FragColor;" \
		"void main(void)" \
		"\n" \
		"{" \
		"FragColor = out_color;" \
		"}";

	// change 3 fragcolor=


	glShaderSource(gFragmentShaderObject, 1, (const GLchar**)&fragmentShaderSourceCode, NULL);

	// compile shader frag

	glCompileShader(gFragmentShaderObject);


	iInfoLogLength = 0;
	iShaderCompiledStatus = 0;
	szInfoLog = NULL;

	glGetShaderiv(gVertexShaderObject, GL_COMPILE_STATUS, &iShaderCompiledStatus);
	if (iShaderCompiledStatus == GL_FALSE)
	{
		glGetShaderiv(gVertexShaderObject, GL_INFO_LOG_LENGTH, &iInfoLogLength);

		if (iInfoLogLength > 0);
		{
			szInfoLog = (char*)malloc(iInfoLogLength);

			if (szInfoLog != NULL)
			{
				GLsizei written;
				glGetShaderInfoLog(gVertexShaderObject, iInfoLogLength, &written, szInfoLog);
				fprintf(gpFile, "Fragment Shader Compilation Log : %s\n", szInfoLog);
				free(szInfoLog);
				DestroyWindow(ghwnd);
			}
		}
	}






	// *** SHADER PROGRAM ***

	// create
	gShaderProgramObject = glCreateProgram();

	// attach vertex shader to shader program
	glAttachShader(gShaderProgramObject, gVertexShaderObject);

	// attach fragment shader to shader program
	glAttachShader(gShaderProgramObject, gFragmentShaderObject);


	// pre linker binding of shader program object with vertex shader position

	glBindAttribLocation(gShaderProgramObject, AK_ATTRIBUTE_POSITION, "vPosition"); // maximum error from this

	// Change no. 4
	glBindAttribLocation(gShaderProgramObject, AK_ATTRIBUTE_COLOR, "vColor");

	// link shader

	glLinkProgram(gShaderProgramObject);

	GLint iShaderProgramLinkStatus = 0;
	glGetProgramiv(gShaderProgramObject, GL_LINK_STATUS, &iShaderProgramLinkStatus);

	if (iShaderProgramLinkStatus == GL_FALSE)
	{
		glGetProgramiv(gShaderProgramObject, GL_INFO_LOG_LENGTH, &iInfoLogLength);

		if (iInfoLogLength > 0)
		{
			szInfoLog = (char*)malloc(iInfoLogLength);
			if (szInfoLog != NULL)
			{
				GLsizei written;
				glGetShaderInfoLog(gShaderProgramObject, iInfoLogLength, &written, szInfoLog);
				fprintf(gpFile, "Shader Program Link Log: %s\n", szInfoLog);
				free(szInfoLog);
				DestroyWindow;

			}
		}
	}

	// get MVP uniform location
	mvpUniform = glGetUniformLocation(gShaderProgramObject, "u_mvpmatrix");

	// ** vertices, colors, shader, attribs , vbo , vao initialization ***

	const GLfloat triangleVertices[] =
	{
		0.0f,1.0f,0.0f, //apex       // 2nd cahnge 
		-1.0f,-1.0f,0.0f, //left bottom
		1.0f,-1.0f,0.0f // right bottom

	};

	// change no.5

	const GLfloat triangleColors[] =
	{							// Perspective triangle colors
		1.0f, 0.0f, 0.0f,		// Red apex
		0.0f, 1.0f, 0.0f,		// Green left bottom
		0.0f, 0.0f, 1.0f,		// Blue right bottom
	};


	// change 2


	const GLfloat squareVertices[] =
	{							// Perspective square
		1.0f, 1.0f, 0.0f,
		-1.0f, 1.0f, 0.0f,
		-1.0f, -1.0f, 0.0f,
		1.0f, -1.0f, 0.0f,
	};

	const GLfloat squareColors[] =
	{							//  color
		0.258824f, 0.258824f, 0.435294f,
		0.258824f, 0.258824f, 0.435294f,
		0.258824f, 0.258824f, 0.435294f,
		0.258824f, 0.258824f, 0.435294f
	};


	//change 3

	glGenVertexArrays(1, &vao_Triangle);
	glBindVertexArray(vao_Triangle);



	glGenBuffers(1, &vbo_Triangle_Position);
	glBindBuffer(GL_ARRAY_BUFFER, vbo_Triangle_Position); // color texture are kept here 
	glBufferData(GL_ARRAY_BUFFER, sizeof(triangleVertices), triangleVertices, GL_STATIC_DRAW);
	glVertexAttribPointer(AK_ATTRIBUTE_POSITION, 3, GL_FLOAT, GL_FALSE, 0, NULL);

	glEnableVertexAttribArray(AK_ATTRIBUTE_POSITION);

	// change no.6 .... color sathi same 
	glGenBuffers(1, &vbo_Triangle_Color);					// Buffer to store vertex colors
	glBindBuffer(GL_ARRAY_BUFFER, vbo_Triangle_Color);		// Find that named object in memory
	glBufferData(GL_ARRAY_BUFFER, sizeof(triangleColors), triangleColors, GL_STATIC_DRAW);	// Takes data from CPU to GPU

	glVertexAttribPointer(AK_ATTRIBUTE_COLOR, 3, GL_FLOAT, GL_FALSE, 0, NULL);
	glEnableVertexAttribArray(AK_ATTRIBUTE_COLOR);


	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);



	// Square 
	glGenBuffers(1, &vbo_Square_Position);
	glBindBuffer(GL_ARRAY_BUFFER, vbo_Square_Position);		// Find that named object in memory
	glBufferData(GL_ARRAY_BUFFER, sizeof(squareVertices), squareVertices, GL_STATIC_DRAW);	// Takes data from CPU to GPU

	glVertexAttribPointer(AK_ATTRIBUTE_POSITION, 3, GL_FLOAT, GL_FALSE, 0, NULL);
	glEnableVertexAttribArray(AK_ATTRIBUTE_POSITION);

	// Release the buffer for vertices:
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	//  COLORS
	glGenBuffers(1, &vbo_Square_Color);
	glBindBuffer(GL_ARRAY_BUFFER, vbo_Square_Color);
	glBufferData(GL_ARRAY_BUFFER, sizeof(squareColors), squareColors, GL_STATIC_DRAW);	// Takes data from CPU to GPU

	glVertexAttribPointer(AK_ATTRIBUTE_COLOR, 3, GL_FLOAT, GL_FALSE, 0, NULL);
	glEnableVertexAttribArray(AK_ATTRIBUTE_COLOR);


	// Release the buffer for colors:
	glBindBuffer(GL_ARRAY_BUFFER, 0);


	// romantic lines



	glShadeModel(GL_SMOOTH);
	//setup depth buffer

	glClearDepth(1.0f);

	// enable depth testing

	glEnable(GL_DEPTH_TEST);

	// depth test to do

	glDepthFunc(GL_LEQUAL);

	// set really nice preceptive calculation 

	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

	// for better performance 

	glEnable(GL_CULL_FACE);


	// background color
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f); // blue 

	resize(WIN_WIDTH, WIN_HEIGHT);
}





void display(void)

{

	//code

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


	// major change 

	// start using OpenGL program object
	glUseProgram(gShaderProgramObject);



	// OpenGL Triangle

	// set modelview & model viewprojection matrices to identity

	mat4 modelViewMatrix = mat4::identity();
	mat4 modelViewProjectionMatrix = mat4::identity();

	//rotation
	mat4 rotationMatrix = mat4::identity(); // ......change 2

	TranslateMatrix = translate(-1.5f, 0.0f, -6.0f);
	modelViewMatrix = TranslateMatrix;

	//rotationMatrix.........change 3

	rotationMatrix = vmath::rotate(angletriangle, 0.0f, 1.0f, 0.0f);

	//modelViewMatrix with the rotationMatrix .......change 3

	modelViewMatrix = modelViewMatrix * rotationMatrix;

	//multiply the modelview and orthographic matrix to get modelviewprojection

	modelViewProjectionMatrix = PerspectiveProjectionMatrix * modelViewMatrix; // order is important 

	glUniformMatrix4fv(mvpUniform, 1, GL_FALSE, modelViewProjectionMatrix);

	//**bind vao** // gl being

	glBindVertexArray(vao_Triangle);

	// draw either by glDrawTriangle() or glDrawArrays or glDrawElements()

	glDrawArrays(GL_TRIANGLES, 0, 3); // 3 each with its xyz vertex triangle vertex array

	// unbind vao

	glBindVertexArray(0);



	//Square

	// modelview and modelviewprojection matrices to identity 

	modelViewMatrix = mat4::identity();
	modelViewProjectionMatrix = mat4::identity();
	rotationMatrix = mat4::identity(); //.......change 4


	// Translate the modelViewMatrix along the z axis
	modelViewMatrix = translate(1.5f, 0.0f, -6.0f);

	// Rotate the rotationMatrix:
	rotationMatrix = rotate(anglesquare, 1.0f, 0.0f, 0.0f);

	modelViewMatrix = modelViewMatrix * rotationMatrix;  // change ... 5

	// Multiply the ModelView and Perspective Matrix to get modelviewprojection matrix
	modelViewProjectionMatrix = PerspectiveProjectionMatrix * modelViewMatrix;	// Order is important



	glUniformMatrix4fv(mvpUniform, 1, GL_FALSE, modelViewProjectionMatrix);

	// BIND vao
	glBindVertexArray(vao_Square);

	// Draw either by glDrawTraingles() or glDrawArrays() or glDrawElements()
	glDrawArrays(GL_TRIANGLE_FAN, 0, 4);	// 3(x, y, z) vertices in the squareVertices array

	// Unbind vao
	glBindVertexArray(0);



	// stop using OpenGL program object

	glUseProgram(0);





	// OpenGL Drawing
	SwapBuffers(ghdc);  //ghdc

}

//Update function

void Update(void)
{
	angletriangle = angletriangle + 0.1f;
	if (angletriangle >= 360.0f)
		angletriangle = 0.0f;

	anglesquare = anglesquare + 0.11f;
	if (anglesquare >= 360.0f)
		anglesquare = 0.0f;
}






void resize(int width, int height)

{

	//code

	if (height == 0)
		height = 1;

	glViewport(0, 0, (GLsizei)width, (GLsizei)height);

	// glPerspective(FOV, aspect ratio, near, far)

	PerspectiveProjectionMatrix = perspective(45.0f, ((GLfloat)width / (GLfloat)height), 0.1f, 100.0f);
}


void uninitialize(void)

{

	//code
	{
		if (gbFullscreen == true)
			dwStyle = GetWindowLong(ghwnd, GWL_STYLE);

		SetWindowLong(ghwnd, GWL_STYLE, dwStyle | WS_OVERLAPPEDWINDOW);

		SetWindowPlacement(ghwnd, &wpPrev);

		SetWindowPos(ghwnd, HWND_TOP, 0, 0, 0, 0, SWP_NOMOVE
			| SWP_NOSIZE |
			SWP_NOOWNERZORDER | SWP_NOZORDER | SWP_FRAMECHANGED);

		ShowCursor(TRUE);

	}

	// destroy vao

	if (vao_Triangle)
	{
		glDeleteVertexArrays(1, &vao_Triangle);
		vao_Triangle = 0;

	}

	// destroy vbo

	if (vbo_Triangle_Position)
	{
		glDeleteBuffers(1, &vbo_Triangle_Position);
		vbo_Triangle_Position = 0;
	}

	if (vbo_Triangle_Color)
	{
		glDeleteBuffers(1, &vbo_Triangle_Color);
		vbo_Triangle_Color = 0;
	}


	// Destroy square vao 
	if (vao_Square)
	{
		glDeleteVertexArrays(1, &vao_Square);
		vao_Square = 0;
	}

	// Destroy vbo for Square Position:
	if (vbo_Square_Position)
	{
		glDeleteBuffers(1, &vbo_Square_Position);
		vbo_Square_Position = 0;
	}


	// Destroy vbo for Square Color:
	if (vbo_Square_Color)
	{
		glDeleteBuffers(1, &vbo_Square_Color);
		vbo_Square_Color = 0;
	}



	// normal cleaner 

	// detach vertex shader from shader program object

	glDetachShader(gShaderProgramObject, gVertexShaderObject);

	// detach fragment shader from shader program object
	glDetachShader(gShaderProgramObject, gFragmentShaderObject);

	// delete vertex shader object
	glDeleteShader(gVertexShaderObject);

	gVertexShaderObject = 0;

	// delete fragment shader object
	glDeleteShader(gFragmentShaderObject);
	gFragmentShaderObject = 0;

	// delete shader program object
	glDeleteProgram(gShaderProgramObject);

	gShaderProgramObject = 0;

	// unlink shader program
	glUseProgram(0);








	/*

	// second type of safe cleaner

	if (gShaderProgramObject)
	{
		glUseProgram(gShaderProgramObject);

		GLsizei shadercount;
		glGetProgramiv(gShaderProgramObject, GL_ATTACHED_SHADERS, &shadercount);



		// pointer

		GLuint* PShader = NULL;

		//malloc
		PShader = (GLuint*)malloc(sizeof(GLuint) * shadercount);

		glGetAttachedShaders(gShaderProgramObject, shadercount, &shadercount, PShader);

		for (GLsizei = 0);
		i<
		*/


		//Deselect the rendering context

	wglMakeCurrent(NULL, NULL);

	//Delete the rendering context

	wglDeleteContext(ghrc);


	ghrc = NULL;

	ReleaseDC(ghwnd, ghdc);

	ghdc = NULL;

	if (gpFile)

	{
		fprintf(gpFile, "Log File Is Successfully Closed.\n");
		fclose(gpFile);
		gpFile = NULL;

	}
}























