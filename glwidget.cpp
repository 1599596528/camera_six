#include "glwidget.h"



const GLfloat PI = 3.1415926536f;

GLWidget::GLWidget(QWidget * parent, const QGLWidget * shareWidget, Qt::WindowFlags f)
{
    parent=parent;
    shareWidget=shareWidget;
    f=f;
    setMinimumSize(320,240);
    resize(640,480);
    setWindowTitle(tr("第一个OpenGL程序"));
    short angle = 18;
    for(short i=0; i<5; i++) {
        Point[i][0] = cos(angle * PI/180);
        Point[i][1] = sin(angle * PI/180);
        Point[i][2] = 0.0;
        angle += 72;
    }

}
GLWidget::~GLWidget()
{
}
void GLWidget::initializeGL()
{
    glShadeModel(GL_SMOOTH);
    glClearColor(0.5f, 0.5f, 0.5f, 0.0f);
    glClearDepth(1.0);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(3, GL_FLOAT, 0, Point);
    startTimer(30);
}
void GLWidget::paintGL()
{
    qDebug()<<"----------paintGL---------";
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
    glLoadIdentity();

    glTranslatef( -1.5,  0.0, -6.0 );
    static float rQuad=0;
    glRotatef( rQuad,  1.0,  1.0,  1.0 );
    rQuad+=5;


    glBegin( GL_TRIANGLES );
        glColor3f( 1.0, 0.0, 0.0 );
        glVertex3f(  0.0,  1.0,  0.0 );
        glColor3f( 0.0, 1.0, 0.0 );
        glVertex3f( -1.0, -1.0,  0.0 );
        glColor3f( 0.0, 0.0, 1.0 );
        glVertex3f(  1.0, -1.0,  0.0 );
    glEnd();
    glTranslatef(  3.0,  0.0,  0.0 );

    //glDrawArrays(GL_LINE_LOOP, 0, 5);

    glBegin( GL_QUADS );
        glNormal3f( 0.0, 0.0, 1.0 );glColor3f( 1.0, 0.0, 0.0 );
        glTexCoord2f( 0.0, 0.0 ); glVertex3f( -1.0, -1.0,  1.0 );
        glTexCoord2f( 1.0, 0.0 ); glVertex3f(  1.0, -1.0,  1.0 );
        glTexCoord2f( 1.0, 1.0 ); glVertex3f(  1.0,  1.0,  1.0 );
        glTexCoord2f( 0.0, 1.0 ); glVertex3f( -1.0,  1.0,  1.0 );

        glNormal3f( 0.0, 0.0, -1.0 );glColor3f( 0.0, 1.0, 0.0 );
        glTexCoord2f( 1.0, 0.0 ); glVertex3f( -1.0, -1.0, -1.0 );
        glTexCoord2f( 1.0, 1.0 ); glVertex3f( -1.0,  1.0, -1.0 );
        glTexCoord2f( 0.0, 1.0 ); glVertex3f(  1.0,  1.0, -1.0 );
        glTexCoord2f( 0.0, 0.0 ); glVertex3f(  1.0, -1.0, -1.0 );

        glNormal3f( 0.0, 1.0, 0.0 );glColor3f( 0.0, 0.0, 1.0 );
        glTexCoord2f( 0.0, 1.0 ); glVertex3f( -1.0,  1.0, -1.0 );
        glTexCoord2f( 0.0, 0.0 ); glVertex3f( -1.0,  1.0,  1.0 );
        glTexCoord2f( 1.0, 0.0 ); glVertex3f(  1.0,  1.0,  1.0 );
        glTexCoord2f( 1.0, 1.0 ); glVertex3f(  1.0,  1.0, -1.0 );

        glNormal3f( 0.0, -1.0, 0.0 );glColor3f( 1.0, 1.0, 0.0 );
        glTexCoord2f( 1.0, 1.0 ); glVertex3f( -1.0, -1.0, -1.0 );
        glTexCoord2f( 0.0, 1.0 ); glVertex3f(  1.0, -1.0, -1.0 );
        glTexCoord2f( 0.0, 0.0 ); glVertex3f(  1.0, -1.0,  1.0 );
        glTexCoord2f( 1.0, 0.0 ); glVertex3f( -1.0, -1.0,  1.0 );

        glNormal3f( 1.0, 0.0, 0.0 );glColor3f( 1.0, 0.0, 1.0 );
        glTexCoord2f( 1.0, 0.0 ); glVertex3f(  1.0, -1.0, -1.0 );
        glTexCoord2f( 1.0, 1.0 ); glVertex3f(  1.0,  1.0, -1.0 );
        glTexCoord2f( 0.0, 1.0 ); glVertex3f(  1.0,  1.0,  1.0 );
        glTexCoord2f( 0.0, 0.0 ); glVertex3f(  1.0, -1.0,  1.0 );

        glNormal3f( -1.0, 0.0, 0.0 );glColor3f( 0.0, 1.0, 1.0 );
        glTexCoord2f( 0.0, 0.0 ); glVertex3f( -1.0, -1.0, -1.0 );
        glTexCoord2f( 1.0, 0.0 ); glVertex3f( -1.0, -1.0,  1.0 );
        glTexCoord2f( 1.0, 1.0 ); glVertex3f( -1.0,  1.0,  1.0 );
        glTexCoord2f( 0.0, 1.0 ); glVertex3f( -1.0,  1.0, -1.0 );
    glEnd();
}
void GLWidget::timerEvent(QTimerEvent*)
{
  updateGL();
}
void GLWidget::resizeGL(int width, int height)
{
    glViewport( 0, 0, (GLint)width, (GLint)height );
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();

    //gluPerspective( 45.0, (GLfloat)width/(GLfloat)height, 0.1, 100.0 );
    GLfloat zNear = 0.1;
    GLfloat zFar = 100.0;
    GLfloat aspect = (GLfloat)width/(GLfloat)height;

    GLfloat fH = tan(GLfloat(90.0/360.0*PI))*zNear;
    GLfloat fW = fH * aspect;
    glFrustum(-fW, fW, -fH, fH, zNear, zFar);


    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity();
}
void GLWidget::mouseDoubleClickEvent( QMouseEvent *event )
{
    if((*event).button()==Qt::MouseButton::LeftButton)
    {
        if(windowState() &  Qt::WindowFullScreen)
            showNormal();
        else
            showFullScreen();
    }
}
void GLWidget::keyPressEvent(QKeyEvent *e)
{
    if (e->key() == Qt::Key_Escape)
        close();
}
