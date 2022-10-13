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

//Tab Base Class
//
////This file serves as the definition file of the base class for the 'Window'
////which describes the basic structure of all tabs on the main interface of
////the program 'FolderControl'.
////
////The GUI controls all aspects related to the tab structure. Creating a
////uniform structure.
////
////This file is a work in progress.

#include "window.h"

//Qt Libs:

#include <QIcon>

//Constructor.
Window::Window(QObject* parent) : QObject(parent)
{
    return;
}

//Initializes the objects that will be used in the view.
void Window::createObjects()
{
    dWindow = new QDialog();

    glMain = new QGridLayout();

    pbOk = new QPushButton("OK");

    fView = new QFrame();

    saView = new QScrollArea();

    glMainLayout = new QGridLayout();

    return;
}

//Configures the objects that will be used in the view.
void Window::configureObjects()
{
    dWindow->setWindowFlags(Qt::Dialog);
    dWindow->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);

    dWindow->setAttribute(Qt::WA_DeleteOnClose);

    pbOk->setMinimumWidth(80);
    pbOk->setMaximumWidth(80);

    fView->setFrameShape(QFrame::NoFrame);
    fView->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);

    saView->setWidgetResizable(true);
    //saView->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    //saView->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    saView->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
    saView->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
    saView->setFrameStyle(QFrame::NoFrame);

    return;
}

//Places the view objects in their perspective layouts and sets the layouts.
void Window::placeObjects()
{
    saView->setWidget(fView);

    fView->setLayout(glMainLayout);

    glMain->addWidget(saView, 0, 0, 15, 15);

    glMain->addWidget(pbOk, 16, 7, 1, 1);

    dWindow->setLayout(glMain);

    return;
}

//Connects the objects to their functional and managing code sources.
void Window::connectObjects()
{
    QObject::connect(dWindow, dWindow->destroyed, [this]()
    {
        dWindow = nullptr;
    });

    QObject::connect(pbOk, SIGNAL(clicked()), this, SLOT(close()));

    return;
}

//Disconnects objects from their functional and managing code sources.
void Window::disconnectObjects()
{
    QObject::connect(dWindow, dWindow->destroyed, [this]()
    {
        dWindow = nullptr;
    });

    QObject::disconnect(pbOk, SIGNAL(clicked()), this, SLOT(close()));

    return;
}

//Sets the window icon to the selected file.
void Window::setIcon(QString file)
{
    QIcon icon(file);

    dWindow->setWindowIcon(icon);

    return;
}

//Initializes and shows the window.
void Window::show()
{
    createObjects();
    configureObjects();
    placeObjects();
    connectObjects();

    dWindow->exec();

    return;
}

//Closes and destroys the window.
void Window::close()
{
    if (dWindow != NULL)
    {
        dWindow->close();

        delete dWindow;
    }

    dWindow = nullptr;

    return;
}

//Destructor.
Window::~Window()
{
    return;
}
