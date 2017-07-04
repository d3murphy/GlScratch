/********************************************************************************
** Form generated from reading UI file 'glscratchqt.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GLSCRATCHQT_H
#define UI_GLSCRATCHQT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include "GlScratchWidget.h"

QT_BEGIN_NAMESPACE

class Ui_GlScratchQtClass
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout_2;
    GlScratchWidget *widget;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *GlScratchQtClass)
    {
        if (GlScratchQtClass->objectName().isEmpty())
            GlScratchQtClass->setObjectName(QStringLiteral("GlScratchQtClass"));
        GlScratchQtClass->resize(1208, 658);
        centralWidget = new QWidget(GlScratchQtClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(centralWidget->sizePolicy().hasHeightForWidth());
        centralWidget->setSizePolicy(sizePolicy);
        gridLayout_2 = new QGridLayout(centralWidget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        widget = new GlScratchWidget(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy1);

        gridLayout_2->addWidget(widget, 0, 0, 1, 1);

        GlScratchQtClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(GlScratchQtClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1208, 27));
        GlScratchQtClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(GlScratchQtClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        GlScratchQtClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(GlScratchQtClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        GlScratchQtClass->setStatusBar(statusBar);

        retranslateUi(GlScratchQtClass);

        QMetaObject::connectSlotsByName(GlScratchQtClass);
    } // setupUi

    void retranslateUi(QMainWindow *GlScratchQtClass)
    {
        GlScratchQtClass->setWindowTitle(QApplication::translate("GlScratchQtClass", "GlScratchQt", 0));
    } // retranslateUi

};

namespace Ui {
    class GlScratchQtClass: public Ui_GlScratchQtClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GLSCRATCHQT_H
