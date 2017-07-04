#ifndef GL_SCRATCH_H
#define GL_SCRATCH_H

#include <QtOpenGL>
#include <QGLFormat>

class GlScratchWidget : public QGLWidget
{
    Q_OBJECT

public:
    GlScratchWidget(QWidget *parent = 0);
    ~GlScratchWidget() {};

};

#endif