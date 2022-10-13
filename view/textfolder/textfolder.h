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

//Text To Folders Interface
//
////This file serves as the definition file of the GUI for the 'Text To Folder'
////functionality of the program 'FolderControl'.
////
////The GUI controls all aspects related to the view and inherits from the base
////class 'Tab'. It overrides virtual functions only and extends non-virtual
////functions.
////
////This file is a work in progress.

#ifndef TEXTFOLDER_H
#define TEXTFOLDER_H

//Base Class:

#include "../tab.h"

//Qt Libs:

#include <QObject>
//#include <QProperty>
#include <QLineEdit>
#include <QRadioButton>
#include <QTextEdit>
#include <QPushButton>
#include <QHBoxLayout>
#include <QString>
#include <QGroupBox>
#include <QGridLayout>
#include <QProgressBar>
#include <QFrame>
#include <QTreeView>
#include <QFileSystemModel>

//'Text To Folder' tab interface.
class TextFolder : public Tab
{
    Q_OBJECT

public:

    //Constructor.
    TextFolder(QObject* parent = NULL);

    //Destructor.
    ~TextFolder();

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
    void createPreset(const int index) override;

    //Removes and deletes preconfigurations.
    //Overrides base class implementation.
    void removePreset(const int index) override;

private:

    //View Objects:

    QLineEdit *leDirectory,
              *leImport;

    QRadioButton *rbAppend,
                 *rbClear;

    QTextEdit *teFolder;

    QPushButton *pbStart,
                *pbClear,
                *pbSelect,
                *pbSave,
                *pbDelete,
                *pbImport,
                *pbCopy,
                *pbDirDrop,
                *pbImpDrop;

    QGridLayout *glDirectory,
                *glImport;

    QHBoxLayout *hblDirectory,
                *hblImport,
                *hblFolder,
                *hblDirDrop,
                *hblImpDrop;

    QGroupBox *gbDirectory,
              *gbImport,
              *gbFolder;

    QFrame *fDirectory,
           *fImport;

    QTreeView *tvDirectory,
              *tvImport;

    QFileSystemModel *fsmDirectory,
                     *fsmImport;

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

    //Makes the Import Tree View widget visible.
    //Triggered by clicking the expand button.
    void expandImport();

    //Sets the Directory Tree View to match the Line Edit address.
    //Triggered by changing the Line Edit text.
    void updateDirModelLocation();

    //Sets the Import Tree View to match the Line Edit address.
    //Triggered by changing the Line Edit text.
    void updateImpModelLocation();

    //Sets the Directory Line Edit to match the Tree View address.
    //Triggered by changing the Tree View selection.
    void updateDirectory();

    //Sets the Import Line Edit to match the Tree View address.
    //Triggered by changing the Tree View selection.
    void updateImport();

};

#endif // TEXTFOLDER_H
