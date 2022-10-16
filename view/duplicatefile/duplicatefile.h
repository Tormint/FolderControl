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

//Duplicate Finder Interface
//
////This file serves as the definition file of the GUI for the 'Duplicate
////Finder' functionality of the program 'FolderControl'.
////
////The GUI controls all aspects related to the view and inherits from the base
////class 'Tab'. It overrides virtual functions only and extends non-virtual
////functions.
////
////This file is a work in progress.

#ifndef DUPLICATEFILE_H
#define DUPLICATEFILE_H

//Base Class:

#include "../tab.h"

//Qt Libs:

#include <QObject>
//#include <QProperty>
#include <QLabel>
#include <QGroupBox>
#include <QLineEdit>
#include <QPushButton>
#include <QTextEdit>
#include <QTreeView>
#include <QListView>
#include <QLineEdit>
#include <QFileSystemModel>
#include <QGridLayout>
//#include <QHBoxLayout>
#include <QCheckBox>
#include <QRadioButton>
#include <QFrame>
//#include <QGraphicsOpacityEffect>
#include <QProgressBar>

//'Duplicate Finder' tab interface.
class DuplicateFile : public Tab
{
    Q_OBJECT

public:

    //Constructor.
    DuplicateFile(QObject* parent = NULL);

    //Destructor.
    ~DuplicateFile();

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

    QLineEdit *leDirectory,
              *leGroup1,
              *leGroup2,
              *leIgnore;

    QRadioButton *rbAppend,
                 *rbClear,
                 *rbActionAsk,
                 *rbActionMove,
                 *rbActionDelete,
                 *rbFromBoth,
                 *rbFromGroup1,
                 *rbFromGroup2,
                 *rbCompAll,
                 *rbCompDiffGroup,
                 *rbCompDiffFolder,
                 *rbCompGroup1,
                 *rbCompGroup2;

    QCheckBox *cbSubfolder,
              *cbCompMd,
              *cbCompSha,
              *cbCompCrc;

    QTextEdit *teGroup1,
              *teGroup2,
              *teIgnore;

    QPushButton *pbStart,
                *pbClear,
                *pbCopy,
                *pbSelect,
                *pbAddGroup1,
                *pbAddGroup2,
                *pbRemoveGroup1,
                *pbRemoveGroup2,
                *pbIgnore,
                *pbDirDrop,
                *pbIgnDrop,
                *pbTreeList;

    QGridLayout *glDirectory,
                *glGroup,
                *glSetting,
                *glAction,
                *glFrom,
                *glCompare,
                *glHash,
                *glIgnore,
                *glOutput;

    QHBoxLayout *hblDirectory,
                *hblIgnore,
                *hblDirDrop,
                *hblIgnDrop;

    QGroupBox *gbDirectory,
              *gbIgnore,
              *gbSetting,
              *gbAction,
              *gbFrom,
              *gbCompare,
              *gbHash,
              *gbOutput;

    QFrame *fDirectory,
           *fIgnore;

    QTreeView *tvDirectory,
              *tvIgnore,
              *tvOutput;

    QListView *lvOutput;

    QFileSystemModel *fsmDirectory,
                     *fsmIgnore;

    QProgressBar *pbStatus;

public slots:

    //File selection dialog.
    //Triggered by clicking the Import button.
    void selectFile();

    //Folder selection dialog.
    //Triggered by clicking the Select button.
    void selectFolder();

    //Implementation that adjusts the preconfigured selection based on current settings.
    //Triggered by changing settings.
    ////index(int): refers to the index that will be applied.
    void updatePreset(const int index) override;

    //Copies a folder structure into the view.
    //Triggered by clicking the 'Copy' button.
    void copyLayout();

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

    //Makes the Ignore Tree View widget visible.
    //Triggered by clicking the expand button.
    void expandIgnore();

    //Sets the Directory Tree View to match the Line Edit address.
    //Triggered by changing the Line Edit text.
    void updateDirModelLocation();

    //Sets the Directory Tree View to match the Line Edit address.
    //Triggered by changing the Line Edit text.
    void updateIgnModelLocation();

    //Sets the Directory Line Edit to match the Tree View address.
    //Triggered by changing the Tree View selection.
    void updateDirectory();

    //Sets the Ignore Line Edit to match the Tree View address.
    //Triggered by changing the Tree View selection.
    void updateIgnore();

    //Toggle between different view types.
    //Triggered by clicking the view icon.
    ////checked(bool): refers to the checked state of the toggle button.
    void toggleTreeList(const bool checked);

    //Add selection to Group 1.
    //Triggered by clicking Add.
    void addGroup1();

    //Add selection to Group 2.
    //Triggered by clicking Add.
    void addGroup2();

    //Remove selection from Group 1.
    //Triggered by clicking Remove.
    void removeGroup1();

    //Remove selection from Group 2.
    //Triggered by clicking Remove.
    void removeGroup2();

};

#endif // DUPLICATEFILE_H
