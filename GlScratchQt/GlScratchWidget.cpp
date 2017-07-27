#include "gl/glew.h"
#include "GlScratchWidget.h"
#include <qmessagebox.h>

#include <fstream>
#include <iostream>

GlScratchWidget::GlScratchWidget(QWidget *parent)
    : QGLWidget(parent)
{

}

void GlScratchWidget::sendDataToOpenGl()
{

    //Vertex data
    GLfloat verts[] =
    {
        +0.0f, +1.0f,
        +1.0f, +0.0f, +0.0f,

        -1.0f, -1.0f,
        +0.0f, +1.0f, +0.0f,

        +1.0f, -1.0f,
        +0.0f, +0.0f, +1.0f
    };

    GLuint vertexBufferId;

    glGenBuffers(1, &vertexBufferId);
    glBindBuffer(GL_ARRAY_BUFFER, vertexBufferId);
    glBufferData(GL_ARRAY_BUFFER, sizeof(verts),
        verts, GL_STATIC_DRAW);

    //Enable position attribute
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE,
        5 * sizeof(float), 0);

    //Enable colour attribute
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE,
        5 * sizeof(float), (void *)(2 * sizeof(float)));

    //Indicate indices for triangles
    GLushort indices[] =
    {
        0, 1, 2,
    };

    GLuint indexBufferId;

    glGenBuffers(1, &indexBufferId);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBufferId);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices),
        indices, GL_STATIC_DRAW);
}

std::string GlScratchWidget::readShaderCode(std::string fname)
{
    std::ifstream fileInput(fname);

    if (fileInput.fail())
    {
        return "";
    }

    return std::string(
        std::istreambuf_iterator<char>(fileInput),
        std::istreambuf_iterator<char>());
}

bool GlScratchWidget::checkShaderStatus(GLuint shaderId)
{
    bool compileSuccess = true;
    GLint compileStatus;

    glGetShaderiv(shaderId, GL_COMPILE_STATUS, &compileStatus);
    if (compileStatus != GL_TRUE)
    {
        compileSuccess = false;
        GLint logLength;
        glGetShaderiv(shaderId, GL_INFO_LOG_LENGTH, &logLength);

        GLchar * buffer = new GLchar[logLength];
        GLsizei actualSize = 0;
        glGetShaderInfoLog(shaderId, logLength, &actualSize, buffer);

        QString message(buffer);
        QMessageBox box(this);
        box.setWindowTitle(QString("Compile Error!"));
        box.setText(message);
        box.exec();

        delete[] buffer;
    }

    return compileSuccess;
}

bool GlScratchWidget::checkProgramStatus(GLuint programId)
{
    bool linkSuccess = true;
    GLint status;

    glGetProgramiv(programId, GL_LINK_STATUS, &status);
    if (status != GL_TRUE)
    {
        linkSuccess = false;
        GLint logLength;
        glGetProgramiv(programId, GL_INFO_LOG_LENGTH, &logLength);

        GLchar * buffer = new GLchar[logLength];
        GLsizei actualSize = 0;
        glGetProgramInfoLog(programId, logLength, &actualSize, buffer);

        QString message(buffer);
        QMessageBox box(this);
        box.setWindowTitle(QString("Link Error!"));
        box.setText(message);
        box.exec();

        delete[] buffer;
    }

    return linkSuccess;
}



void GlScratchWidget::installShaders()
{
    std::string vertexShaderCode = readShaderCode("VertexShader.glsl");
    std::string fragmentShaderCode = readShaderCode("FragmentShader.glsl");

    GLuint vShaderId = glCreateShader(GL_VERTEX_SHADER);
    GLuint fShaderId = glCreateShader(GL_FRAGMENT_SHADER);

    const char * cStrPtr = vertexShaderCode.c_str();
    glShaderSource(vShaderId, 1, &cStrPtr, 0);

    cStrPtr = fragmentShaderCode.c_str();
    glShaderSource(fShaderId, 1, &cStrPtr, 0);
    
    glCompileShader(vShaderId);
    glCompileShader(fShaderId);


    if (!checkShaderStatus(vShaderId) ||
        !checkShaderStatus(fShaderId) )
    {
        return;
    }
    
    GLuint programId = glCreateProgram();
    glAttachShader(programId, vShaderId);
    glAttachShader(programId, fShaderId);

    glLinkProgram(programId);
    glUseProgram(programId);

    if (!checkProgramStatus(programId))
    {
        return;
    }
}


void GlScratchWidget::initializeGL()
{
    glewInit();

    installShaders();
    sendDataToOpenGl();
}

void GlScratchWidget::paintGL()
{
    QGLWidget::paintGL();

    glViewport(0, 0, width(), height());
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_SHORT, 0);

}
