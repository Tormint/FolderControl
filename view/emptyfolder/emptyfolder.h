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

#include "../tab.h"

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

class EmptyFolder : public Tab
{
    Q_OBJECT

public:
    EmptyFolder(QObject* parent = NULL);
    ~EmptyFolder();

protected:

    void createObjects();
    void configureObjects();
    void placeObjects();
    void connectObjects();

    void createPreset(int index) override;
    void removePreset(int index) override;

private:

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

    void selectFile();
    void selectFolder();
    void updatePreset(int index) override;
    void copyLayout();
    void startProcess();
    void clearSettings();
    void updateSettings();
    void expandDirectory();
    void expandIgnore();
    void updateDirModelLocation();
    void updateIgnModelLocation();
    void updateDirectory();
    void updateIgnore();
    void toggleTreeList(bool checked);
};

#endif // EMPTYFOLDER_H
