#ifndef GL_SCRATCH_H
#define GL_SCRATCH_H

#include <QGLFormat>

class GlScratchWidget : public QGLWidget
{
    Q_OBJECT

public:
    GlScratchWidget(QWidget *parent = 0);
    ~GlScratchWidget() {};

protected:
    std::string readShaderCode(std::string fname);
    void sendDataToOpenGl();
    bool checkShaderStatus(GLuint shaderId);
    bool checkProgramStatus(GLuint programId);

    void installShaders();
    void initializeGL() override;
    void paintGL() override;

};

#endif