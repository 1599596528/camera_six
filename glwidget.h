#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <GL/glu.h>
#include <QtOpenGL/QtOpenGL>
#include <GL/gl.h>
#include <QWidget>


class GLWidget : public QGLWidget
{
    Q_OBJECT
public:
       GLWidget(QWidget *parent = 0, const QGLWidget * shareWidget = 0, Qt::WindowFlags f = 0);
       ~GLWidget();
   signals:

   public slots:

   protected:
       void initializeGL();
       void paintGL();
       void resizeGL(int width, int height);
       void mouseDoubleClickEvent( QMouseEvent *event );
       void keyPressEvent(QKeyEvent *e);
       void timerEvent( QTimerEvent * );
   private:
       GLfloat Point[5][3];

};

#endif // GLWIDGET_H
