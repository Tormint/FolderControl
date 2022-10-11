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

#include <QMainWindow>
#include <QTabWidget>
#include <QMenuBar>
#include <QMenu>
#include <QAction>

#include "view/duplicatefile/duplicatefile.h"
#include "view/emptyfolder/emptyfolder.h"
#include "view/textfolder/textfolder.h"
#include "view/removejunk/removejunk.h"

#include "view/about/about.h"
#include "view/about/aboutqt.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Interface; }
QT_END_NAMESPACE

class Interface : public QMainWindow
{
    Q_OBJECT

public:

    Interface(QWidget *parent = nullptr);
    ~Interface();

    void createObjects();
    void configureObjects();
    void placeObjects();
    void connectObjects();

private:

    Ui::Interface *ui;

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

    QTabWidget *twMain;

    DuplicateFile *tabDupe;

    EmptyFolder *tabEmpty;

    TextFolder *tabText;

    RemoveJunk *tabJunk;

    About *abAbout;

    AboutQt *aqAbout;

};
#endif // INTERFACE_H
