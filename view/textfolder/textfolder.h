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

#include "../tab.h"

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

class TextFolder : public Tab
{
    Q_OBJECT

public:

    TextFolder(QObject* parent = NULL);
    ~TextFolder();

protected:

    void createObjects();
    void configureObjects();
    void placeObjects();
    void connectObjects();

    void createPreset(const int index) override;
    void removePreset(const int index) override;

private:

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

    void selectFile();
    void selectFolder();
    void updatePreset(const int index) override;
    void copyLayout();
    void startProcess();
    void clearSettings();
    void updateSettings();
    void expandDirectory();
    void expandImport();
    void updateDirModelLocation();
    void updateImpModelLocation();
    void updateDirectory();
    void updateImport();

};

#endif // TEXTFOLDER_H
