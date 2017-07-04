#include "glscratchqt.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    GlScratchQt w;
    w.show();
    return a.exec();
}
