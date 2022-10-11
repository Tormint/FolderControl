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

#ifndef WINDOW_H
#define WINDOW_H

#include "tab.h"

#include <QObject>
#include <QDialog>
#include <QGridLayout>
#include <QPushButton>
#include <QScrollArea>
#include <QFrame>

class Window : public QObject
{
    Q_OBJECT

public:

    Window(QObject* parent = NULL);
    ~Window();

protected:

    QDialog *dWindow;

    QGridLayout *glMainLayout;

    QPushButton *pbOk;

    virtual void createObjects();
    virtual void configureObjects();
    virtual void placeObjects();
    virtual void connectObjects();
    virtual void disconnectObjects();

private:

    QGridLayout *glMain;

    QFrame *fView;

    QScrollArea *saView;

public slots:

    void show();
    void close();
};

#endif // WINDOW_H
