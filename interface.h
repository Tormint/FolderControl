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
////This file serves as the definition file of the GUI for the main window,
////called 'Interface' of the program 'FolderControl'.
////
////The GUI controls all aspects related to the view.
////
////This file is a work in progress.

#ifndef INTERFACE_H
#define INTERFACE_H

//Qt Libs:

#include <QMainWindow>
#include <QTabWidget>
#include <QMenuBar>
#include <QMenu>
#include <QAction>

//My Libs:

#include "view/duplicatefile/duplicatefile.h"
#include "view/emptyfolder/emptyfolder.h"
#include "view/textfolder/textfolder.h"
#include "view/removejunk/removejunk.h"

#include "view/about/about.h"
#include "view/about/aboutqt.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Interface; }
QT_END_NAMESPACE

//The main home screen window.
class Interface : public QMainWindow
{
    Q_OBJECT

public:

    //Constructor.
    Interface(QWidget *parent = nullptr);

    //Destructor.
    ~Interface();

    //Initializes the objects that will be used in the view.
    void createObjects();

    //Configures the objects that will be used in the view.
    void configureObjects();

    //Places the view objects in their perspective layouts and sets the layouts.
    void placeObjects();

    //Connects the objects to their functional and managing code sources.
    void connectObjects();

private:

    //Default UI pointer.
    Ui::Interface *ui;

    //Menu Objects:

    QMenuBar *mbMenu;

    QMenu *mFile,
          *mEdit,
          *mView,
          *mTab,
          *mHelp;

    QAction *aExit,
            *aSetting,
            *aDupe,
            *aEmpty,
            *aText,
            *aJunk,
            *aAbout,
            *aAboutQt;

    About *abAbout;

    AboutQt *aqAbout;

    //View Objects:

    ////The central widget and only widget in the main view.
    QTabWidget *twMain;

    //Tabs:

    DuplicateFile *tabDupe;

    EmptyFolder *tabEmpty;

    TextFolder *tabText;

    RemoveJunk *tabJunk;

};
#endif // INTERFACE_H
