#ifndef GLSCRATCHQT_H
#define GLSCRATCHQT_H

#include <QtWidgets/QMainWindow>
#include "ui_glscratchqt.h"
#include "GlScratchWidget.h"

class GlScratchQt : public QMainWindow
{
    Q_OBJECT

public:
    GlScratchQt(QWidget *parent = 0);
    ~GlScratchQt();

private:
    Ui::GlScratchQtClass ui;
};

#endif // GLSCRATCHQT_H
