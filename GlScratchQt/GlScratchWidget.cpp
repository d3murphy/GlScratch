#include "gl/glew.h"
#include "GlScratchWidget.h"

#include <fstream>

GlScratchWidget::GlScratchWidget(QWidget *parent)
    : QGLWidget(parent)
{

}

void GlScratchWidget::sendDataToOpenGl()
{

    //Vertex data
    GLfloat verts[] =
    {
        +0.0f, +0.0f,
        +1.0f, +0.0f, +0.0f,

        +1.0f, +1.0f,
        +1.0f, +0.0f, +0.0f,

        -1.0f, +1.0f,
        +1.0f, +0.0f, +0.0f,

        -1.0f, -1.0f,
        +1.0f, +0.0f, +0.0f,

        +1.0f, -1.0f,
        +1.0f, +0.0f, +0.0f,
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
        0, 3, 4
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
    std::string contents;

    if (fileInput.fail())
    {
        return "";
    }

    return std::string(
        std::istreambuf_iterator<char>(fileInput),
        std::istreambuf_iterator<char>());
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

    //TODO: Check compile errors
    glCompileShader(vShaderId);
    glCompileShader(fShaderId);

    GLuint programId = glCreateProgram();
    glAttachShader(programId, vShaderId);
    glAttachShader(programId, fShaderId);

    //TODO: Check link errors
    glLinkProgram(programId);

    glUseProgram(programId);
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
