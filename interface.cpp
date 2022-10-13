/******************************************************************************
 *******************************  Folder Control  *****************************
 ******************************************************************************
 *                                                                            *
 * Designed and written by LN du Rand (TorMint, the tormented peppermint).    *
 *                                                                            *
 * The source code is released under GNU General Public License v3.0.         *
 *                                                                            *
 * GitHub URL: https://github.com/Tormint/FolderControl                       *
 * Paypal URL: https://www.paypal.com/donate/?hosted_button_id=WCRQBGFZ2W8PY  *
 *                                                                            *
 ******************************************************************************/

//Main Interface
//
////This file serves as the implementation file of the GUI for the main window,
////called 'Interface' of the program 'FolderControl'.
////
////The GUI controls all aspects related to the view.
////
////This file is a work in progress.

#include "interface.h"
#include "./ui_interface.h"

//Contstructor.
Interface::Interface(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Interface)
{
    //Setup Window

    createObjects();
    configureObjects();
    placeObjects();
    connectObjects();

    return;
}

//Initializes the objects that will be used in the view.
void Interface::createObjects()
{
    //Setup UI:

    ui->setupUi(this);

    //Setup Widgets:

    ////Menu Objects:

    mbMenu = new QMenuBar();

    mFile = new QMenu("&File");
    mEdit = new QMenu("&Edit");
    mView = new QMenu("&View");
    mTab = new QMenu("Tab");
    mHelp = new QMenu("&Help");

    aExit = new QAction("Exit");

    aSetting = new QAction("Settings");

    aDupe = new QAction("Duplicate Finder");
    aEmpty = new QAction("Empty Folder Remover");
    aText = new QAction("Text To Folder");
    aJunk = new QAction("Remove Junk Files");

    aAbout = new QAction("About");
    aAboutQt = new QAction("About Qt");

    abAbout = new About();

    aqAbout = new AboutQt();

    ////View Objects:

    twMain = new QTabWidget(this);

    ////Tabs:

    tabDupe = new DuplicateFile();
    tabEmpty = new EmptyFolder();
    tabText = new TextFolder();
    tabJunk = new RemoveJunk();

    return;
}

//Configures the objects that will be used in the view.
void Interface::configureObjects()
{
    //Menu Objects:

    aExit->setMenuRole(QAction::QuitRole);

    aSetting->setMenuRole(QAction::PreferencesRole);

    aDupe->setMenuRole(QAction::ApplicationSpecificRole);
    aEmpty->setMenuRole(QAction::ApplicationSpecificRole);
    aText->setMenuRole(QAction::ApplicationSpecificRole);
    aJunk->setMenuRole(QAction::ApplicationSpecificRole);

    aAbout->setMenuRole(QAction::AboutRole);
    aAboutQt->setMenuRole(QAction::AboutQtRole);

    mFile->addAction(aExit);

    mEdit->addAction(aSetting);

    mView->addMenu(mTab);

    mTab->addAction(aDupe);
    mTab->addAction(aEmpty);
    mTab->addAction(aText);
    mTab->addAction(aJunk);

    mTab->setIcon(Interface::style()->standardIcon(QStyle::SP_DirClosedIcon));

    mHelp->addAction(aAbout);
    mHelp->addAction(aAboutQt);

    mbMenu->addMenu(mFile);
    mbMenu->addMenu(mEdit);
    mbMenu->addMenu(mView);
    mbMenu->addMenu(mHelp);

    aExit->setIcon(Interface::style()->standardIcon(QStyle::SP_TitleBarCloseButton));
    aSetting->setIcon(Interface::style()->standardIcon(QStyle::SP_ComputerIcon));
    aDupe->setIcon(Interface::style()->standardIcon(QStyle::SP_FileIcon));
    aEmpty->setIcon(Interface::style()->standardIcon(QStyle::SP_FileIcon));
    aText->setIcon(Interface::style()->standardIcon(QStyle::SP_FileIcon));
    aJunk->setIcon(Interface::style()->standardIcon(QStyle::SP_FileIcon));
    aAbout->setIcon(Interface::style()->standardIcon(QStyle::SP_MessageBoxQuestion));
    aAboutQt->setIcon(Interface::style()->standardIcon(QStyle::SP_MessageBoxQuestion));

    aExit->setShortcut(QKeySequence("Alt+F4", QKeySequence::NativeText));
    aSetting->setShortcut(QKeySequence("Ctrl+S", QKeySequence::NativeText));
    aDupe->setShortcut(QKeySequence("Ctrl+D", QKeySequence::NativeText));
    aEmpty->setShortcut(QKeySequence("Ctrl+E", QKeySequence::NativeText));
    aText->setShortcut(QKeySequence("Ctrl+T", QKeySequence::NativeText));
    aJunk->setShortcut(QKeySequence("Ctrl+J", QKeySequence::NativeText));
    aAbout->setShortcut(QKeySequence("Ctrl+A", QKeySequence::NativeText));
    aAboutQt->setShortcut(QKeySequence("Ctrl+Q", QKeySequence::NativeText));

    return;
}

//Places the view objects in their perspective layouts and sets the layouts.
void Interface::placeObjects()
{
    //Menu Objects:

    Interface::setMenuBar(mbMenu);

    //View Objects:

    Interface::setCentralWidget(twMain);

    twMain->addTab(tabDupe->getTab(), "Duplicate Finder");
    twMain->addTab(tabEmpty->getTab(), "Empty Folder Remover");
    twMain->addTab(tabText->getTab(), "Text To Folder");
    twMain->addTab(tabJunk->getTab(), "Remove Junk Files");

    return;
}

//Connects the objects to their functional and managing code sources.
void Interface::connectObjects()
{
    //Menu Objects:

    QObject::connect(aExit, SIGNAL(triggered(bool)), this, SLOT(close()));

    ////QObject::connect(aSetting, SIGNAL(triggered(bool)), this, SLOT());

    QObject::connect(aDupe, &QAction::triggered, [this]()
    {
        this->twMain->setCurrentIndex(0);
    });

    QObject::connect(aEmpty, &QAction::triggered, [this]()
    {
        this->twMain->setCurrentIndex(1);
    });

    QObject::connect(aText, &QAction::triggered, [this]()
    {
        this->twMain->setCurrentIndex(2);
    });

    QObject::connect(aJunk, &QAction::triggered, [this]()
    {
        this->twMain->setCurrentIndex(3);
    });

    QObject::connect(aAbout, SIGNAL(triggered(bool)), abAbout, SLOT(show()));
    QObject::connect(aAboutQt, SIGNAL(triggered(bool)), aqAbout, SLOT(show()));

    return;
}

//Destructor.
Interface::~Interface()
{
    delete ui;

    return;
}

