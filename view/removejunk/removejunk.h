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

//Remove Junk Files Interface
//
////This file serves as the definition file of the GUI for the 'Remove Junk
////Files' functionality of the program 'FolderControl'.
////
////The GUI controls all aspects related to the view and inherits from the base
////class 'Tab'. It overrides virtual functions only and extends non-virtual
////functions.
////
////This file is a work in progress.

#ifndef REMOVEJUNK_H
#define REMOVEJUNK_H

#include "../tab.h"

#include <QObject>
//#include <QProperty>
#include <QTextEdit>
#include <QLineEdit>
#include <QPushButton>
#include <QGroupBox>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QCheckBox>
#include <QProgressBar>
#include <QLabel>
#include <QGraphicsOpacityEffect>
#include <QFrame>
#include <QTreeView>
#include <QFileSystemModel>

class RemoveJunk : public Tab
{
    Q_OBJECT

public:

    RemoveJunk();
    ~RemoveJunk();

protected:

    void createObjects();
    void configureObjects();
    void placeObjects();
    void connectObjects();

    void createPreset(int index) override;
    void removePreset(int index) override;

private:

    QLabel *lRemove,
           *lHelp;

    QLineEdit *leDirectory;

    QCheckBox *cbSubFolder;

    QTextEdit *teJunk,
              *teOutput;

    QPushButton *pbStart,
                *pbClear,
                *pbSelect,
                *pbDirDrop,
                *pbHelp;

    QGroupBox *gbDirectory,
              *gbSetting,
              *gbOutput;

    QGridLayout *glDirectory,
                *glSetting,
                *glHelp;

    QHBoxLayout *hblDirectory,
                *hblDirDrop,
                *hblOutput;

    QFrame *fDirectory,
           *fHelp;

    QTreeView *tvDirectory;

    QFileSystemModel *fsmDirectory;

    QProgressBar *pbStatus;

public slots:

    void selectFolder();
    void updatePreset(int index) override;
    void startProcess();
    void clearSettings();
    void updateSettings();
    void expandDirectory();
    void expandHelp();
    void updateDirModelLocation();
    void updateDirectory();

};

#endif // REMOVEJUNK_H
