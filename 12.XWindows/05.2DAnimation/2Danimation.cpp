#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

#include<GL/gl.h>
#include<GL/glx.h>

#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/XKBlib.h>
#include <X11/keysym.h>

#include <GL/glu.h>

//namespaces
using namespace std;

//Global Variable Declarations
bool bFullscreen=false;
Display *gpDisplay=NULL;
XVisualInfo *gpXVisualInfo=NULL;
Colormap gColormap;
Window gWindow;

GLXContext gGLXContext;

int giwindowWidth=800;
int giWindowHeight=600;



//entery-point function
int main(void)
{
    //function prototypes
    void CreateWindow(void);
    void ToggleFullscreen(void);
    void uninitialize();
    
    void Initialize(void);
    void Resize(int,int);
    void Draw(void);
        
    //variable declarations
    int winWidth=giwindowWidth;
    int winHeight=giWindowHeight;
    
    bool bDone = false;
    
    
    //code
    CreateWindow();
    Initialize();
    
    //message Loop
    XEvent event;
    KeySym keysym;
    
    while(bDone == false)
    {
        while(XPending(gpDisplay))
            {
               XNextEvent(gpDisplay,&event);
                  switch(event.type)
                   {
                        case MapNotify:
                        break;
                        case KeyPress:
                        keysym=XkbKeycodeToKeysym(gpDisplay,event.xkey.keycode,0,0);
                        switch(keysym)
                        {
                             case XK_Escape:
                                          bDone = true;
                                   
                             case XK_F:
                             case XK_f:
                                        if(bFullscreen==false)
                                        {
                                             ToggleFullscreen();
                                             bFullscreen=true;
                                        }
                                        else
                                        {
                                              ToggleFullscreen();
                                              bFullscreen=false;
                                        }
                                        break;
                                  default:
                                        break;
                       }
                       break;
                            case ButtonPress:
                                 switch(event.xbutton.button)
                                      {
                                               case 1:
                                                    break;
                                               case 2:
                                                    break;
                                               case 3:
                                                    break;
                                               default:
                                                    break;
                                      }
                                    break;
                            case MotionNotify:
                                break;
                            case ConfigureNotify:
                                winWidth=event.xconfigure.width;
                                winHeight=event.xconfigure.height;
                                
                                Resize(winWidth,winHeight);
                                break;
                            case Expose:
                                break;
                            case DestroyNotify:
                                break;
                            case 33:
                                bDone = true ;
                    
                            default:
                                break;
                  }
          }
           Draw();
        
    }                     
     uninitialize();
     return(0);
}

void CreateWindow(void)
{
    //function prototytpes
    void uninitialize(void);
    
    //variable declarations
    XSetWindowAttributes winAttribs;
    int defaultScreen;
    int DefaultDepth;
    int styleMask;
    
    static int FramBufferAttribut[] = { GLX_DOUBLEBUFFER,True,
                                        GLX_RGBA,
                                        GLX_RED_SIZE,8,
                                        GLX_GREEN_SIZE,8,
                                        GLX_BLUE_SIZE,8,
                                        GLX_ALPHA_SIZE,8,
                                        None
                                       };
    
    //code
    gpDisplay=XOpenDisplay(NULL);
    if(gpDisplay==NULL)
    {
        printf("ERROR : Unable To Open X Display.\nExitting Now...\n");
        uninitialize();
        exit(1);
    }
    
    defaultScreen=XDefaultScreen(gpDisplay);
    
    gpXVisualInfo = glXChooseVisual(gpDisplay,defaultScreen,FramBufferAttribut);
    
    //gpXVisualInfo=(XVisualInfo *)malloc(sizeof(XVisualInfo));
    /*if(gpXVisualInfo==NULL)
    {
        printf("ERROR : Unable To Allocate Merrory For Visual Info.\nExitting Now...\n");
        uninitialize();
        exit(1);
    }
    
   XMatchVisualInfo(gpDisplay,defaultScreen,DefaultDepth,TrueColor,gpXVisualInfo);
    if(gpXVisualInfo==NULL)
    {
        printf("ERROR : Unable To Get A Visual. \nExitting Now...\n");
        uninitialize();
        exit(1);
    }
    */
    winAttribs.border_pixel=0;
    winAttribs.background_pixmap=0;
    winAttribs.colormap=XCreateColormap(gpDisplay,
                                       RootWindow(gpDisplay,gpXVisualInfo->screen),
                                       gpXVisualInfo->visual,
                                       AllocNone);
    gColormap=winAttribs.colormap;
         
     winAttribs.background_pixel=BlackPixel(gpDisplay,defaultScreen);
     
     winAttribs.event_mask=ExposureMask | VisibilityChangeMask | ButtonPressMask | KeyPressMask | PointerMotionMask | 
     StructureNotifyMask;
     
     styleMask=CWBorderPixel | CWBackPixel | CWEventMask | CWColormap;
     
     gWindow=XCreateWindow(gpDisplay,
                           RootWindow(gpDisplay,gpXVisualInfo->screen),
             0,
             0,
             giwindowWidth,
             giWindowHeight,
             0,
             gpXVisualInfo->depth,
             InputOutput,
             gpXVisualInfo->visual,
             styleMask,
             &winAttribs);
     if(!gWindow)
     {
         printf("ERROE : Failed To Create Main Window.\nExitting Now...\n");
         uninitialize();
         exit(1);
     }
     
     XStoreName(gpDisplay,gWindow,"Aniket: 2D Animation XWindow");
     
     Atom windowManagerDelet=XInternAtom(gpDisplay,"WM_DELETE_WINDOW",True);
     XSetWMProtocols(gpDisplay,gWindow,&windowManagerDelet,1);
     
     XMapWindow(gpDisplay,gWindow);
}

void ToggleFullscreen(void)
{
    //variable declarations
    Atom wm_state;
    Atom fullscreen;
    XEvent xev={0};
    
    //code
    wm_state=XInternAtom(gpDisplay,"_NET_WM_STATE",False);
    memset(&xev,0,sizeof(xev));
    
    xev.type=ClientMessage;
    xev.xclient.window=gWindow;
    xev.xclient.message_type=wm_state;
    xev.xclient.format=32;
    xev.xclient.data.l[0]=bFullscreen ? 0 : 1;
     
     fullscreen=XInternAtom(gpDisplay,"_NET_WM_STATE_FULLSCREEN",False);
     xev.xclient.data.l[1]=fullscreen;
     
     XSendEvent(gpDisplay,
                RootWindow(gpDisplay,gpXVisualInfo->screen),
                False,
                StructureNotifyMask,
                &xev);
}
   void Initialize(void)
      {
          //function prototypes
          void Resize(int,int);
          
          //code
          gGLXContext = glXCreateContext(gpDisplay,gpXVisualInfo,NULL,GL_TRUE);
          glXMakeCurrent(gpDisplay,gWindow,gGLXContext);
          
          glClearColor(0.0f,0.0f,0.0f,0.0f);
          
          //warm up Resize Call
          Resize (giwindowWidth,giWindowHeight);
      }
      
      void Resize(int width, int height)
      {
          if(height == 0)
              height = 1;
              glViewport(0,0,(GLsizei)width,(GLsizei)height);
          
          glMatrixMode(GL_PROJECTION);
          glLoadIdentity();
          
          gluPerspective(45.0f, (GLfloat)width / (GLfloat)height, 0.1f, 100.0f);
      }
     
     void Draw (void)
     {
         
         static GLfloat TAngle = 0.0f;
         static GLfloat RAngle = 0.0f;

         glClear(GL_COLOR_BUFFER_BIT);
         
         glMatrixMode(GL_MODELVIEW);
	     glLoadIdentity();

	    glTranslatef(-1.5f, 0.0f,-6.0f);
        glRotatef(TAngle,1.0f,0.0f,0.0f);
        
	    glBegin(GL_TRIANGLES);
	    
        glColor3f(1.0f, 0.0f, 0.0f);
	    glVertex3f(0.0f, 1.0f, 0.0f); 

	    glColor3f(0.0f, 1.0f, 0.0f);
	    glVertex3f(-1.0f, -1.0f, 0.0f);

	    glColor3f(0.0f, 0.0f, 1.0f);
	    glVertex3f(1.0f, -1.0f, 0.0f);
	    
        glEnd();
        
        TAngle = TAngle + 1.0f;
	    if (TAngle >= 360.0f)
		TAngle = 0.0f;


	    glMatrixMode(GL_MODELVIEW);
	    glLoadIdentity();

	    glTranslatef(1.5f, 0.0f, -6.0f);
        glRotatef(RAngle,1.0f,0.0f,0.0f);

	    glBegin(GL_QUADS);
	
	    glColor3f(0.0f, 0.0f, 1.0f);
	
	    glVertex3f(1.0f, 1.0f, 0.0f);

	    glVertex3f(-1.0f, 1.0f, 0.0f);

	    glVertex3f(-1.0f, -1.0f, 0.0f);

	    glVertex3f(1.0f, -1.0f, 0.0f);
	    
        glEnd();
        
        RAngle = RAngle + 1.0f;
	    if (RAngle >= 360.0f)
		RAngle = 0.0f;


        glXSwapBuffers(gpDisplay,gWindow);
     }
     void uninitialize(void)
     {
         //Local Variable Declaration
         GLXContext CurrentglXContext;
         
         CurrentglXContext = glXGetCurrentContext();
         //code
         if(CurrentglXContext == gGLXContext)
         {
             glXMakeCurrent(gpDisplay,0,0);
         }
         if(gGLXContext)
         {
          glXDestroyContext(gpDisplay,gGLXContext);   
         }
         
         if(gWindow)
         {
             XDestroyWindow(gpDisplay,gWindow);
         }
         
         if(gColormap)
         {
             XFreeColormap(gpDisplay,gColormap);
         }
         
         if(gpXVisualInfo);
         {
             free(gpXVisualInfo);
             gpXVisualInfo=NULL;
         }
         
         if(gpDisplay)
         {
             XCloseDisplay(gpDisplay);
             gpDisplay=NULL;
         }
     }

     
     
             
         
        
    
    
    
    
    
    
    
