#include "glscratchqt.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    GlScratchWidget w;
    w.show();
    return a.exec();
}
