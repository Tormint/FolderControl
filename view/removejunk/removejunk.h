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

//Base Class:

#include "../tab.h"

//Qt Libs:

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

//'Remove Junk Files' tab interface.
class RemoveJunk : public Tab
{
    Q_OBJECT

public:

    //Constructor.
    RemoveJunk();

    //Destructor.
    ~RemoveJunk();

protected:

    //Initializes the objects that will be used in the view.
    //Extends the functions of the base class implementations.
    void createObjects();

    //Configures the objects that will be used in the view.
    //Extends the functions of the base class implementations.
    void configureObjects();

    //Places the view objects in their perspective layouts and sets the layouts.
    //Extends the functions of the base class implementations.
    void placeObjects();

    //Connects the objects to their functional and managing code sources.
    //Extends the functions of the base class implementations.
    void connectObjects();

    //Creates and stores preconfigurations.
    //Overrides base class implementation.
    ////index(int): refers to the new preset value.
    void createPreset(const int index) override;

    //Removes and deletes preconfigurations.
    //Overrides base class implementation.
    ////index(int): refers to the value of the preset to be removed.
    void removePreset(const int index) override;

private:

    //View Objects:

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

    //Folder selection dialog.
    //Triggered by clicking the Select button.
    void selectFolder();

    //Implementation that adjusts the preconfigured selection based on current settings.
    //Triggered by changing settings.
    ////index(int): refers to the index that will be applied.
    void updatePreset(const int index) override;

    //Starts the scan.
    //Triggered by clicking the 'Start'/'Scan' button.
    void startProcess();

    //Restores default settings.
    //Triggered by clicking the 'Clear' button.
    void clearSettings();

    //Changes the settings.
    //Triggered by a change in preset selection.
    void updateSettings();

    //Makes the Directory Tree View widget visible.
    //Triggered by clicking the expand button.
    void expandDirectory();

    //Expands the help section.
    //Triggered by clicking the help icon.
    void expandHelp();

    //Sets the Directory Tree View to match the Line Edit address.
    //Triggered by changing the Line Edit text.
    void updateDirModelLocation();

    //Sets the Import Line Edit to match the Tree View address.
    //Triggered by changing the Tree View selection.
    void updateDirectory();

};

#endif // REMOVEJUNK_H
