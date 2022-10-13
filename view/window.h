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

//Qt Libs:

#include <QObject>
#include <QDialog>
#include <QGridLayout>
#include <QPushButton>
#include <QScrollArea>
#include <QFrame>

//Base class for all dialog windows.
class Window : public QObject
{
    Q_OBJECT

public:

    //Constructor.
    Window(QObject* parent = NULL);

    //Destructor.
    ~Window();

protected:

    //Inheritance Objects:

    //The window itself.
    //Used to set window properties.
    QDialog *dWindow;

    //The main layout of the window.
    //Used to modify the appearance of the window.
    QGridLayout *glMainLayout;

    //Member Functions:

    //Initializes the objects that will be used in the view.
    virtual void createObjects();

    //Configures the objects that will be used in the view.
    virtual void configureObjects();

    //Places the view objects in their perspective layouts and sets the layouts.
    virtual void placeObjects();

    //Connects the objects to their functional and managing code sources.
    virtual void connectObjects();

    //Disconnects objects from their functional and managing code sources.
    virtual void disconnectObjects();

    //Sets the window icon to the selected file.
    void setIcon(QString file);

private:

    //Structural Objects:

    //Central layout of the view.
    QGridLayout *glMain;

    //Frame to enable QScrollArea to function correctly.
    QFrame *fView;

    //Scroll Area to make the view adapt to any interface configuration.
    QScrollArea *saView;

    //Confirmation button that also closes the window.
    QPushButton *pbOk;

public slots:

    //Initializes and shows the window.
    void show();

    //Closes and destroys the window.
    void close();
};

#endif // WINDOW_H
