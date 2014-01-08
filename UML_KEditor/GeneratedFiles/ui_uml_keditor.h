/********************************************************************************
** Form generated from reading UI file 'uml_keditor.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UML_KEDITOR_H
#define UI_UML_KEDITOR_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGraphicsView>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UML_KEditorClass
{
public:
    QAction *actionUseCase;
    QAction *actionClass;
    QAction *actionAssociation;
    QAction *actionComposition;
    QAction *actionGeneration;
    QAction *actionChoose;
    QAction *actionText;
    QAction *actionGroup;
    QAction *actionUnGroup;
    QWidget *centralWidget;
    QGraphicsView *graphicsView;
    QMenuBar *menuBar;
    QMenu *menuFile_F;
    QMenu *menuEdit_E;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *UML_KEditorClass)
    {
        if (UML_KEditorClass->objectName().isEmpty())
            UML_KEditorClass->setObjectName(QString::fromUtf8("UML_KEditorClass"));
        UML_KEditorClass->resize(600, 400);
        actionUseCase = new QAction(UML_KEditorClass);
        actionUseCase->setObjectName(QString::fromUtf8("actionUseCase"));
        actionUseCase->setCheckable(true);
        actionUseCase->setChecked(false);
        QIcon icon;
        icon.addFile(QString::fromUtf8("Resources/image/usercase.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon.addFile(QString::fromUtf8("Resources/image/usecase.png"), QSize(), QIcon::Normal, QIcon::On);
        actionUseCase->setIcon(icon);
        actionClass = new QAction(UML_KEditorClass);
        actionClass->setObjectName(QString::fromUtf8("actionClass"));
        actionClass->setCheckable(true);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("Resources/image/class.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionClass->setIcon(icon1);
        actionAssociation = new QAction(UML_KEditorClass);
        actionAssociation->setObjectName(QString::fromUtf8("actionAssociation"));
        actionAssociation->setCheckable(true);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8("Resources/image/associate.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAssociation->setIcon(icon2);
        actionComposition = new QAction(UML_KEditorClass);
        actionComposition->setObjectName(QString::fromUtf8("actionComposition"));
        actionComposition->setCheckable(true);
        QIcon icon3;
        icon3.addFile(QString::fromUtf8("Resources/image/composition.png"), QSize(), QIcon::Normal, QIcon::On);
        actionComposition->setIcon(icon3);
        actionGeneration = new QAction(UML_KEditorClass);
        actionGeneration->setObjectName(QString::fromUtf8("actionGeneration"));
        actionGeneration->setCheckable(true);
        QIcon icon4;
        icon4.addFile(QString::fromUtf8("Resources/image/generation.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionGeneration->setIcon(icon4);
        actionChoose = new QAction(UML_KEditorClass);
        actionChoose->setObjectName(QString::fromUtf8("actionChoose"));
        actionChoose->setCheckable(true);
        QIcon icon5;
        icon5.addFile(QString::fromUtf8("Resources/image/mouse.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionChoose->setIcon(icon5);
        actionText = new QAction(UML_KEditorClass);
        actionText->setObjectName(QString::fromUtf8("actionText"));
        actionText->setCheckable(true);
        QIcon icon6;
        icon6.addFile(QString::fromUtf8("Resources/image/Text.png"), QSize(), QIcon::Normal, QIcon::On);
        actionText->setIcon(icon6);
        actionGroup = new QAction(UML_KEditorClass);
        actionGroup->setObjectName(QString::fromUtf8("actionGroup"));
        actionGroup->setCheckable(true);
        QIcon icon7;
        icon7.addFile(QString::fromUtf8("Resources/image/group.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionGroup->setIcon(icon7);
        actionUnGroup = new QAction(UML_KEditorClass);
        actionUnGroup->setObjectName(QString::fromUtf8("actionUnGroup"));
        actionUnGroup->setCheckable(true);
        QIcon icon8;
        icon8.addFile(QString::fromUtf8("Resources/image/ungroup.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionUnGroup->setIcon(icon8);
        centralWidget = new QWidget(UML_KEditorClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        graphicsView = new QGraphicsView(centralWidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(0, 0, 1200, 1200));
        UML_KEditorClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(UML_KEditorClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 21));
        menuFile_F = new QMenu(menuBar);
        menuFile_F->setObjectName(QString::fromUtf8("menuFile_F"));
        menuEdit_E = new QMenu(menuBar);
        menuEdit_E->setObjectName(QString::fromUtf8("menuEdit_E"));
        UML_KEditorClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(UML_KEditorClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        UML_KEditorClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(UML_KEditorClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        UML_KEditorClass->setStatusBar(statusBar);

        menuBar->addAction(menuFile_F->menuAction());
        menuBar->addAction(menuEdit_E->menuAction());
        mainToolBar->addAction(actionUseCase);
        mainToolBar->addAction(actionClass);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionAssociation);
        mainToolBar->addAction(actionComposition);
        mainToolBar->addAction(actionGeneration);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionText);
        mainToolBar->addAction(actionChoose);
        mainToolBar->addAction(actionGroup);
        mainToolBar->addAction(actionUnGroup);

        retranslateUi(UML_KEditorClass);

        QMetaObject::connectSlotsByName(UML_KEditorClass);
    } // setupUi

    void retranslateUi(QMainWindow *UML_KEditorClass)
    {
        UML_KEditorClass->setWindowTitle(QApplication::translate("UML_KEditorClass", "UML_KEditorClass", 0, QApplication::UnicodeUTF8));
        actionUseCase->setText(QApplication::translate("UML_KEditorClass", "UseCase", 0, QApplication::UnicodeUTF8));
        actionClass->setText(QApplication::translate("UML_KEditorClass", "Class", 0, QApplication::UnicodeUTF8));
        actionAssociation->setText(QApplication::translate("UML_KEditorClass", "Association", 0, QApplication::UnicodeUTF8));
        actionComposition->setText(QApplication::translate("UML_KEditorClass", "Composition", 0, QApplication::UnicodeUTF8));
        actionGeneration->setText(QApplication::translate("UML_KEditorClass", "Generation", 0, QApplication::UnicodeUTF8));
        actionChoose->setText(QApplication::translate("UML_KEditorClass", "Choose", 0, QApplication::UnicodeUTF8));
        actionText->setText(QApplication::translate("UML_KEditorClass", "Text", 0, QApplication::UnicodeUTF8));
        actionGroup->setText(QApplication::translate("UML_KEditorClass", "Group", 0, QApplication::UnicodeUTF8));
        actionUnGroup->setText(QApplication::translate("UML_KEditorClass", "UnGroup", 0, QApplication::UnicodeUTF8));
        menuFile_F->setTitle(QApplication::translate("UML_KEditorClass", "File(&F)", 0, QApplication::UnicodeUTF8));
        menuEdit_E->setTitle(QApplication::translate("UML_KEditorClass", "Edit(&E)", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class UML_KEditorClass: public Ui_UML_KEditorClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UML_KEDITOR_H
