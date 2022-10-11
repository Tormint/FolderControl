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

Window::Window(QObject* parent) : QObject(parent)
{
    return;
}

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

void Window::configureObjects()
{
    dWindow->setWindowFlags(Qt::Dialog);

    dWindow->setAttribute(Qt::WA_DeleteOnClose);

    pbOk->setMinimumWidth(80);
    pbOk->setMaximumWidth(80);

    fView->setFrameShape(QFrame::NoFrame);
    fView->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);

    saView->setWidgetResizable(true);
    saView->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    saView->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    saView->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
    saView->setFrameStyle(QFrame::NoFrame);

    return;
}

void Window::placeObjects()
{
    saView->setWidget(fView);

    fView->setLayout(glMainLayout);

    glMain->addWidget(saView, 0, 0, 5, 6, Qt::AlignCenter);

    glMain->addWidget(pbOk, 5, 2, 1, 6, Qt::AlignCenter);

    dWindow->setLayout(glMain);

    return;
}

void Window::connectObjects()
{
    QObject::connect(dWindow, dWindow->destroyed, [this]()
    {
        dWindow = nullptr;
    });

    QObject::connect(pbOk, SIGNAL(clicked()), this, SLOT(close()));

    return;
}

void Window::disconnectObjects()
{
    QObject::connect(dWindow, dWindow->destroyed, [this]()
    {
        dWindow = nullptr;
    });

    QObject::disconnect(pbOk, SIGNAL(clicked()), this, SLOT(close()));

    return;
}

void Window::show()
{
    createObjects();
    configureObjects();
    placeObjects();
    connectObjects();

    dWindow->exec();

    return;
}

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

Window::~Window()
{
    return;
}
