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

//Empty Folder Remover Interface
//
////This file serves as the definition file of the GUI for the 'Empty Folder
////Remover' functionality of the program 'FolderControl'.
////
////The GUI controls all aspects related to the view and inherits from the base
////class 'Tab'. It overrides virtual functions only and extends non-virtual
////functions.
////
////This file is a work in progress.

#ifndef EMPTYFOLDER_H
#define EMPTYFOLDER_H

//Base Class:

#include "../tab.h"

//Qt Libs:

#include <QObject>
//#include <QProperty>
#include <QTreeView>
#include <QPushButton>
#include <QGroupBox>
#include <QRadioButton>
#include <QTextEdit>
#include <QLineEdit>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QTreeView>
#include <QListView>
#include <QFileSystemModel>
#include <QProgressBar>
#include <QGraphicsOpacityEffect>

//'Empty Folder Remover' tab interface.
class EmptyFolder : public Tab
{
    Q_OBJECT

public:

    //Constructor.
    EmptyFolder(QObject* parent = NULL);

    //Destructor.
    ~EmptyFolder();

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
    void createPreset(int index) override;

    //Removes and deletes preconfigurations.
    //Overrides base class implementation.
    void removePreset(int index) override;

private:

    //View Objects:

    QLineEdit *leDirectory,
              *leIgnore;

    QRadioButton *rbAppend,
                 *rbClear;

    QTextEdit *teIgnore;

    QPushButton *pbStart,
                *pbClear,
                *pbSelect,
                *pbCopy,
                *pbIgnore,
                *pbDirDrop,
                *pbIgnDrop,
                *pbTreeList;

    QGridLayout *glDirectory,
                *glOutput,
                *glIgnore;

    QHBoxLayout *hblDirectory,
                *hblIgnore,
                *hblDirDrop,
                *hblIgnDrop;

    QGroupBox *gbDirectory,
              *gbOutput,
              *gbIgnore;

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
    void updatePreset(int index) override;

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
    void toggleTreeList(bool checked);

};

#endif // EMPTYFOLDER_H
