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
////This file serves as the implementation file of the GUI for the 'Duplicate
////Finder' functionality of the program 'FolderControl'.
////
////The GUI controls all aspects related to the view and inherits from the base
////class 'Tab'. It overrides virtual functions only and extends non-virtual
////functions.
////
////This file is a work in progress.

#include "duplicatefile.h"

//Qt Libs:

#include <QFileDialog>
#include <QMessageBox>
#include <QHeaderView>
//#include <QMessageBox>
//#include <QFileInfo>

//Constructor.
DuplicateFile::DuplicateFile(QObject *parent) : Tab(parent)
{
    //Setup Tab:

    init();

    return;
}

//Initializes the objects that will be used in the view.
//Extends the functions of the base class implementations.
void DuplicateFile::createObjects()
{
    leDirectory = new QLineEdit();
    leIgnore = new QLineEdit();

    rbAppend = new QRadioButton("Append");
    rbClear = new QRadioButton("Clear");

    rbActionAsk = new QRadioButton("Ask");
    rbActionDelete = new QRadioButton("Delete");
    rbActionMove = new QRadioButton("Move To...");

    rbFromBoth = new QRadioButton("Both");
    rbFromGroup1 = new QRadioButton("Group 1");
    rbFromGroup2 = new QRadioButton("Group 2");

    rbCompAll = new QRadioButton("All");
    rbCompDiffGroup = new QRadioButton("Different Groups");
    rbCompDiffFolder = new QRadioButton("Different Folders");
    rbCompGroup1 = new QRadioButton("Group 1 To Group 2");
    rbCompGroup2 = new QRadioButton("Group 2 To Group 1");

    cbSubfolder = new QCheckBox("Include Subfolders");
    cbCompMd = new QCheckBox("MD5");
    cbCompSha = new QCheckBox("SHA1");
    cbCompCrc = new QCheckBox("CRC32");

    teGroup1 = new QTextEdit();
    teGroup2 = new QTextEdit();
    teIgnore = new QTextEdit();

    pbStart = new QPushButton("Start");
    pbClear = new QPushButton("Clear");
    pbCopy = new QPushButton("Copy");
    pbSelect = new QPushButton("...");
    pbAddGroup1 = new QPushButton("Add");
    pbAddGroup2 = new QPushButton("Add");
    pbRemoveGroup1 = new QPushButton("Remove");
    pbRemoveGroup2 = new QPushButton("Remove");
    pbIgnore = new QPushButton("...");
    pbDirDrop = new QPushButton("");
    pbIgnDrop = new QPushButton("");
    pbTreeList = new QPushButton("");

    glDirectory = new QGridLayout();
    glOutput = new QGridLayout();
    glSetting = new QGridLayout();
    glAction = new QGridLayout();
    glFrom = new QGridLayout();
    glCompare = new QGridLayout();
    glHash = new QGridLayout();
    glIgnore = new QGridLayout();

    hblDirectory = new QHBoxLayout();
    hblIgnore = new QHBoxLayout();
    hblDirDrop = new QHBoxLayout();
    hblIgnDrop = new QHBoxLayout();

    gbDirectory = new QGroupBox("Directories:");
    gbOutput = new QGroupBox("Duplicates:");
    gbSetting = new QGroupBox("Settings:");
    gbAction = new QGroupBox("Action:");
    gbFrom = new QGroupBox("From:");
    gbCompare = new QGroupBox("Compare:");
    gbHash = new QGroupBox("Hash:");
    gbIgnore = new QGroupBox("Ignore:");

    fDirectory = new QFrame();
    fIgnore = new QFrame();

    tvDirectory = new QTreeView();
    tvIgnore = new QTreeView();
    tvOutput = new QTreeView();

    lvOutput = new QListView();

    fsmDirectory = new QFileSystemModel();
    fsmIgnore = new QFileSystemModel();

    pbStatus = new QProgressBar();

    return;
}

//Configures the objects that will be used in the view.
//Extends the functions of the base class implementations.
void DuplicateFile::configureObjects()
{
    leDirectory->setPlaceholderText("Enter directory to scan here...");
    leIgnore->setPlaceholderText("Enter file or folder to import here...");

    rbAppend->setChecked(true);
    rbActionAsk->setChecked(true);
    rbFromBoth->setChecked(true);
    rbCompAll->setChecked(true);

    cbSubfolder->setChecked(true);
    cbCompMd->setChecked(true);
    cbCompSha->setChecked(true);
    cbCompCrc->setChecked(true);

    teGroup1->setEnabled(true);
    teGroup1->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    teGroup1->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);

    teGroup1->setPlaceholderText("Group 1..."
                                 "\n"
                                 "\nFolders in Group 1 are listed here.");

    teGroup2->setEnabled(true);
    teGroup2->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    teGroup2->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);

    teGroup2->setPlaceholderText("Group 2..."
                                 "\n"
                                 "\nFolders in Group 1 are listed here.");

    teIgnore->setEnabled(true);
    teIgnore->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    teIgnore->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);

    teIgnore->setPlaceholderText("Files and folders to ignore/exclude..."
                                 "\n"
                                 "\nIgnored files will be diregarded."
                                 "\n"
                                 "\nExample:"
                                 "\n"
                                 "\nDesktop.ini, Desktop.*, *.ini"
                                 "\nThumbs.db"
                                 "\nC:/Example/New1"
                                 "\nC:/Example/*"
                                 "\nC:\\Foo\\Bar\\New"
                                 "\n"
                                 "\n(Supports Wildcards [*].)");

    pbStart->setMaximumWidth(80);
    pbClear->setMaximumWidth(80);
    pbCopy->setMaximumWidth(80);

    pbStart->setMinimumWidth(80);
    pbClear->setMinimumWidth(80);
    pbCopy->setMinimumWidth(80);

    pbAddGroup1->setMaximumWidth(60);
    pbAddGroup1->setMinimumWidth(60);

    pbAddGroup2->setMaximumWidth(60);
    pbAddGroup2->setMinimumWidth(60);

    pbRemoveGroup1->setMaximumWidth(60);
    pbRemoveGroup1->setMinimumWidth(60);

    pbRemoveGroup2->setMaximumWidth(60);
    pbRemoveGroup2->setMinimumWidth(60);

    pbSelect->setMaximumWidth(40);
    pbSelect->setMinimumWidth(40);

    pbIgnore->setMaximumWidth(40);
    pbIgnore->setMinimumWidth(40);

    pbTreeList->setMaximumWidth(40);

    pbDirDrop->setFlat(true);
    pbIgnDrop->setFlat(true);
    pbTreeList->setFlat(true);

    pbDirDrop->setIcon(pbDirDrop->style()->standardIcon(QStyle::SP_TitleBarUnshadeButton));
    pbIgnDrop->setIcon(pbDirDrop->style()->standardIcon(QStyle::SP_TitleBarUnshadeButton));
    pbTreeList->setIcon(pbTreeList->style()->standardIcon(QStyle::SP_FileDialogDetailedView));

    pbTreeList->setCheckable(true);
    pbTreeList->setChecked(false);

    pbStatus->setValue(0);
    pbStatus->setVisible(false);

    fDirectory->setFrameShape(QFrame::NoFrame);

    fDirectory->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::MinimumExpanding);

    fDirectory->setVisible(false);

    fDirectory->sizePolicy().setRetainSizeWhenHidden(false);

    fIgnore->setFrameShape(QFrame::NoFrame);

    fIgnore->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::MinimumExpanding);

    fIgnore->setVisible(false);

    fIgnore->sizePolicy().setRetainSizeWhenHidden(false);

    tvDirectory->setModel(fsmDirectory);
    tvIgnore->setModel(fsmIgnore);

    fsmDirectory->setRootPath(QDir::root().path());
    fsmIgnore->setRootPath(QDir::root().path());

    tvDirectory->hideColumn(1);
    tvDirectory->hideColumn(2);
    tvDirectory->hideColumn(3);

    tvDirectory->setSizePolicy(QSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Preferred));
    //tvDirectory->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
    tvDirectory->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    tvDirectory->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);

    tvDirectory->header()->setSectionHidden(1, true);
    tvDirectory->header()->setSectionHidden(2, true);
    tvDirectory->header()->setSectionHidden(3, true);

    tvDirectory->setHeaderHidden(true);

    tvDirectory->header()->setSectionResizeMode(QHeaderView::ResizeToContents);

    tvDirectory->setSelectionBehavior(QAbstractItemView::SelectItems);

    tvIgnore->hideColumn(1);
    tvIgnore->hideColumn(2);
    tvIgnore->hideColumn(3);

    tvIgnore->setSizePolicy(QSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Preferred));
    //tvIgnore->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
    tvIgnore->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    tvIgnore->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);

    tvIgnore->header()->setSectionHidden(1, true);
    tvIgnore->header()->setSectionHidden(2, true);
    tvIgnore->header()->setSectionHidden(3, true);

    tvIgnore->setHeaderHidden(true);

    tvIgnore->header()->setSectionResizeMode(QHeaderView::ResizeToContents);

    tvIgnore->setSelectionBehavior(QAbstractItemView::SelectItems);

    lvOutput->setVisible(false);

    tvOutput->setModel(fsmDirectory);
    lvOutput->setModel(fsmDirectory);

    tvOutput->setHeaderHidden(true);

    tvOutput->hideColumn(1);
    tvOutput->hideColumn(2);
    tvOutput->hideColumn(3);

    tvOutput->header()->setSectionHidden(1, true);
    tvOutput->header()->setSectionHidden(2, true);
    tvOutput->header()->setSectionHidden(3, true);

    fsmDirectory->setFilter(QDir::AllDirs | QDir::NoDotAndDotDot);

    fsmDirectory->sort(0, Qt::AscendingOrder);

    return;
}

//Places the view objects in their perspective layouts and sets the layouts.
//Extends the functions of the base class implementations.
void DuplicateFile::placeObjects()
{
    hblDirectory->addWidget(leDirectory);
    hblDirectory->addWidget(pbSelect);

    glDirectory->addLayout(hblDirectory, 0, 0, 1, 6);

    hblDirDrop->addWidget(tvDirectory);

    fDirectory->setLayout(hblDirDrop);

    glDirectory->addWidget(fDirectory, 1, 0, 5, 6);

    glDirectory->addWidget(pbDirDrop, 6, 0, 1, 6);

    glDirectory->addWidget(teGroup1, 7, 0, 3, 3);
    glDirectory->addWidget(teGroup2, 7, 3, 3, 3);

    glDirectory->addWidget(pbAddGroup1, 10, 0, 1, 1, Qt::AlignRight);
    glDirectory->addWidget(pbRemoveGroup1, 10, 1, 1, 1, Qt::AlignLeft);
    glDirectory->addWidget(pbAddGroup2, 10, 4, 1, 1, Qt::AlignRight);
    glDirectory->addWidget(pbRemoveGroup2, 10, 5, 1, 1, Qt::AlignLeft);

    glDirectory->addWidget(cbSubfolder, 10, 2, 1, 2, Qt::AlignCenter);

    gbDirectory->setLayout(glDirectory);

    glMainLayout->addWidget(gbDirectory, 2, 0, 5, 6);

    hblIgnore->addWidget(leIgnore);
    hblIgnore->addWidget(pbIgnore);

    glIgnore->addLayout(hblIgnore, 0, 0, 1, 6);
    glIgnore->addWidget(teIgnore, 1, 0, 3, 3);
    glIgnore->addWidget(rbAppend, 1, 3, 1, 3);
    glIgnore->addWidget(rbClear, 2, 3, 1, 3);
    glIgnore->addWidget(pbCopy, 3, 5, 1, 1);
    glIgnore->addWidget(pbIgnDrop, 4, 0, 1, 6);

    hblIgnDrop->addWidget(tvIgnore);

    fIgnore->setLayout(hblIgnDrop);

    glIgnore->addWidget(fIgnore, 5, 0, 5, 6);

    gbIgnore->setLayout(glIgnore);

    glMainLayout->addWidget(gbIgnore, 7, 0, 5, 6);

    glAction->addWidget(rbActionAsk, 0, 0, 1, 1);
    glAction->addWidget(rbActionDelete, 1, 0, 1, 1);
    glAction->addWidget(rbActionMove, 2, 0, 1, 1);

    gbAction->setLayout(glAction);

    glFrom->addWidget(rbFromBoth, 0, 0, 1, 1);
    glFrom->addWidget(rbFromGroup1, 1, 0, 1, 1);
    glFrom->addWidget(rbFromGroup2, 2, 0, 1, 1);

    gbFrom->setLayout(glFrom);

    glCompare->addWidget(rbCompAll, 0, 0, 1, 1);
    glCompare->addWidget(rbCompDiffGroup, 1, 0, 1, 1);
    glCompare->addWidget(rbCompDiffFolder, 2, 0, 1, 1);
    glCompare->addWidget(rbCompGroup1, 3, 0, 1, 1);
    glCompare->addWidget(rbCompGroup2, 4, 0, 1, 1);

    gbCompare->setLayout(glCompare);

    glHash->addWidget(cbCompMd, 0, 0, 1, 1);
    glHash->addWidget(cbCompSha, 1, 0, 1, 1);
    glHash->addWidget(cbCompCrc, 2, 0, 1, 1);

    gbHash->setLayout(glHash);

    glSetting->addWidget(gbAction, 0, 0, 5, 1);
    glSetting->addWidget(gbFrom, 0, 1, 5, 1);
    glSetting->addWidget(gbCompare, 0, 2, 5, 1);
    glSetting->addWidget(gbHash, 0, 3, 5, 1);

    gbSetting->setLayout(glSetting);

    glMainLayout->addWidget(gbSetting, 12, 0, 5, 6);

    glOutput->addWidget(tvOutput, 0, 0, 10, 6);
    glOutput->addWidget(lvOutput, 0, 0, 10, 6);
    glOutput->addWidget(pbTreeList, 11, 0, 1, 6, Qt::AlignCenter);

    gbOutput->setLayout(glOutput);

    glMainLayout->addWidget(gbOutput, 17, 0, 10, 6);

    glMainLayout->addWidget(lOutput, 27, 0, 1, 4);
    glMainLayout->addWidget(pbStatus, 27, 0, 1, 4);
    glMainLayout->addWidget(pbClear, 27, 4, 1, 1);
    glMainLayout->addWidget(pbStart, 27, 5, 1, 1);

    return;
}

//Connects the objects to their functional and managing code sources.
//Extends the functions of the base class implementations.
void DuplicateFile::connectObjects()
{
    QObject::connect(pbSelect, SIGNAL(clicked(bool)), this, SLOT(selectFolder()));
    QObject::connect(pbIgnore, SIGNAL(clicked(bool)), this, SLOT(selectFile()));

    QObject::connect(pbCopy, SIGNAL(clicked(bool)), this, SLOT(copyLayout()));

    QObject::connect(pbStart, SIGNAL(clicked(bool)), this, SLOT(startProcess()));
    QObject::connect(pbClear, SIGNAL(clicked(bool)), this, SLOT(clearSettings()));

    QObject::connect(leDirectory, SIGNAL(editingFinished()), this, SLOT(updateSettings()));
    QObject::connect(leIgnore, SIGNAL(editingFinished()), this, SLOT(updateSettings()));

    QObject::connect(pbDirDrop, SIGNAL(clicked(bool)), this, SLOT(expandDirectory()));
    QObject::connect(pbIgnDrop, SIGNAL(clicked(bool)), this, SLOT(expandIgnore()));

    QObject::connect(tvDirectory->selectionModel(), SIGNAL(selectionChanged(QItemSelection,QItemSelection)), this, SLOT(updateDirectory()));
    QObject::connect(tvIgnore->selectionModel(), SIGNAL(selectionChanged(QItemSelection,QItemSelection)), this, SLOT(updateIgnore()));

    QObject::connect(leDirectory, SIGNAL(editingFinished()), this, SLOT(updateDirModelLocation()));
    QObject::connect(leIgnore, SIGNAL(editingFinished()), this, SLOT(updateIgnModelLocation()));

    QObject::connect(pbTreeList, SIGNAL(toggled(bool)), this, SLOT(toggleTreeList(bool)));

    QObject::connect(pbAddGroup1, SIGNAL(clicked(bool)), this, SLOT(addGroup1()));
    QObject::connect(pbAddGroup2, SIGNAL(clicked(bool)), this, SLOT(addGroup2()));

    QObject::connect(pbRemoveGroup1, SIGNAL(clicked(bool)), this, SLOT(removeGroup1()));
    QObject::connect(pbRemoveGroup2, SIGNAL(clicked(bool)), this, SLOT(removeGroup2()));

    return;
}

//File selection dialog.
//Triggered by clicking the Import button.
void DuplicateFile::selectFile()
{
    //To select both files and folders will require a custom implementation
    //of QInputDialog. So for now, the item selection using a dialog is limited
    //to files only.

    updateOutput("Selecting File...");

    QString tmp = QFileDialog::getOpenFileName(nullptr, "Import", leIgnore->text(), "All Files (*.*)");

    if (tmp.length() != 0)
    {
        leIgnore->blockSignals(true);
        leIgnore->setText(tmp);
        leIgnore->blockSignals(false);
    }

    updateIgnModelLocation();

    updateOutput("File Selected!");

    return;
}

//Folder selection dialog.
//Triggered by clicking the Select button.
void DuplicateFile::selectFolder()
{
    updateOutput("Selecting Folder...");

    QString tmp = QFileDialog::getExistingDirectory(nullptr, "Select Folder", leDirectory->text(), QFileDialog::ShowDirsOnly);

    if (tmp.length() != 0)
    {
        leDirectory->blockSignals(true);
        leDirectory->setText(tmp);
        leDirectory->blockSignals(false);
    }

    updateDirModelLocation();

    updateOutput("Folder Selected!");

    return;
}

//Implementation that adjusts the preconfigured selection based on current settings.
//Triggered by changing settings.
////index(int): refers to the index that will be applied.
void DuplicateFile::updatePreset(const int index) //Duplicate
{
    updateOutput("Loading Settings...");

    //cbPreset->blockSignals(true);

    //control code

    //cbPreset->blockSignals(false);

    updateOutput("Settings Loaded!");

    return;
}

//Copies a folder structure into the view.
//Triggered by clicking the 'Copy' button.
void DuplicateFile::copyLayout()
{
    updateOutput("Copying Layout...");

    if (QFileInfo(leIgnore->text()).isDir())
    {
        //connect control
    }
    else if (QFileInfo(leIgnore->text()).isFile())
    {
        //connect control
    }
    else
    {
        QMessageBox warning(QMessageBox::Warning,
                            QString("Invalid Directory!"),
                            QString("The specified directory cannot be found!"
                                    "\n"
                                    "\nPlease enter a valid directory- or file-name"
                                    "\nto copy the folder-tree structure or import"
                                    "\na list of folders."),
                            QMessageBox::Ok,
                            cbPreset);

        warning.exec();
    }

    updateOutput("Layout Copied!");

    return;
}

//Starts the scan.
//Triggered by clicking the 'Start'/'Scan' button.
void DuplicateFile::startProcess()
{
    updateOutput("Started...");

    if (QFileInfo(leDirectory->text()).isDir())
    {
        //connect control
    }
    else
    {
        QMessageBox warning(QMessageBox::Warning,
                            QString("Invalid Directory!"),
                            QString("The specified directory cannot be found!\n\nPlease enter a valid directory name to copy the folder tree structure."),
                            QMessageBox::Ok,
                            cbPreset);

        warning.exec();
    }

    updateOutput("Finished!");

    return;
}

//Restores default settings.
//Triggered by clicking the 'Clear' button.
void DuplicateFile::clearSettings()
{
    updateOutput("Clearing Settings...");

    cbPreset->blockSignals(true);
    leDirectory->blockSignals(true);
    tvDirectory->blockSignals(true);
    fsmDirectory->blockSignals(true);
    fsmIgnore->blockSignals(true);
    tvOutput->blockSignals(true);
    lvOutput->blockSignals(true);

    rbAppend->setChecked(true);
    rbActionAsk->setChecked(true);
    rbFromBoth->setChecked(true);
    rbCompAll->setChecked(true);

    cbCompMd->setChecked(true);
    cbCompSha->setChecked(true);
    cbCompCrc->setChecked(true);

    cbSubfolder->setChecked(true);

    tvDirectory->selectionModel()->clear();
    tvIgnore->selectionModel()->clear();

    leDirectory->clear();
    leIgnore->clear();

    //Clear tvOutput and lvOutput

    cbPreset->setCurrentIndex(0);

    cbPreset->blockSignals(false);
    leDirectory->blockSignals(false);
    tvDirectory->blockSignals(false);
    fsmDirectory->blockSignals(false);
    fsmIgnore->blockSignals(false);
    tvOutput->blockSignals(false);
    lvOutput->blockSignals(false);

    updateOutput("Settings Cleared!");

    return;
}

//Changes the settings.
//Triggered by a change in preset selection.
void DuplicateFile::updateSettings()
{
    updateOutput("Updating Settings...");

    cbPreset->blockSignals(true);

    //Finnish

    cbPreset->blockSignals(false);

    updateOutput("Settings Updated!");

    return;
}

//Makes the Directory Tree View widget visible.
//Triggered by clicking the expand button.
void DuplicateFile::expandDirectory()
{
    if (fDirectory->isVisible())
    {
        fDirectory->setVisible(false);

        pbDirDrop->setIcon(pbDirDrop->style()->standardIcon(QStyle::SP_TitleBarUnshadeButton));
    }
    else
    {
        fDirectory->setVisible(true);

        pbDirDrop->setIcon(pbDirDrop->style()->standardIcon(QStyle::SP_TitleBarShadeButton));
    }

    return;
}

//Makes the Ignore Tree View widget visible.
//Triggered by clicking the expand button.
void DuplicateFile::expandIgnore()
{
    if (fIgnore->isVisible())
    {
        fIgnore->setVisible(false);

        pbIgnDrop->setIcon(pbIgnDrop->style()->standardIcon(QStyle::SP_TitleBarUnshadeButton));
    }
    else
    {
        fIgnore->setVisible(true);

        pbIgnDrop->setIcon(pbIgnDrop->style()->standardIcon(QStyle::SP_TitleBarShadeButton));
    }

    return;
}

//Sets the Directory Tree View to match the Line Edit address.
//Triggered by changing the Line Edit text.
void DuplicateFile::updateDirModelLocation()
{
    leDirectory->blockSignals(true);
    tvDirectory->blockSignals(true);
    fsmDirectory->blockSignals(true);

    QModelIndex index = fsmDirectory->index(leDirectory->text(), 0);

    tvDirectory->selectionModel()->clear();
    tvDirectory->selectionModel()->setCurrentIndex(index, QItemSelectionModel::Select);

    leDirectory->blockSignals(false);
    tvDirectory->blockSignals(false);
    fsmDirectory->blockSignals(false);

    return;
}

//Sets the Directory Tree View to match the Line Edit address.
//Triggered by changing the Line Edit text.
void DuplicateFile::updateIgnModelLocation()
{
    leIgnore->blockSignals(true);
    tvIgnore->blockSignals(true);
    fsmIgnore->blockSignals(true);

    QModelIndex index = fsmIgnore->index(leIgnore->text(), 0);

    tvIgnore->selectionModel()->clear();
    tvIgnore->selectionModel()->setCurrentIndex(index, QItemSelectionModel::Select);

    leIgnore->blockSignals(false);
    tvIgnore->blockSignals(false);
    fsmIgnore->blockSignals(false);

    return;
}

//Sets the Directory Line Edit to match the Tree View address.
//Triggered by changing the Tree View selection.
void DuplicateFile::updateDirectory()
{
    leDirectory->blockSignals(true);

    QModelIndex index = tvDirectory->currentIndex();

    leDirectory->setText(fsmDirectory->filePath(index));

    leDirectory->blockSignals(false);

    return;
}

//Sets the Ignore Line Edit to match the Tree View address.
//Triggered by changing the Tree View selection.
void DuplicateFile::updateIgnore()
{
    leIgnore->blockSignals(true);

    QModelIndex index = tvIgnore->currentIndex();

    leIgnore->setText(fsmIgnore->filePath(index));

    leIgnore->blockSignals(false);

    return;
}

//Toggle between different view types.
//Triggered by clicking the view icon.
////checked(bool): refers to the checked state of the toggle button.
void DuplicateFile::toggleTreeList(const bool checked)
{
    if (checked)
    {
        tvOutput->setVisible(false);
        lvOutput->setVisible(true);
    }
    else
    {
        lvOutput->setVisible(false);
        tvOutput->setVisible(true);
    }

    return;
}

//Creates and stores preconfigurations.
//Overrides base class implementation.
////index(int): refers to the new preset value.
void DuplicateFile::createPreset(const int index)
{
    return;
}

//Removes and deletes preconfigurations.
//Overrides base class implementation.
////index(int): refers to the value of the preset to be removed.
void DuplicateFile::removePreset(const int index)
{
    return;
}

//Add selection to Group 1.
//Triggered by clicking Add.
void DuplicateFile::addGroup1()
{
    QString tmp = leDirectory->text();

    QFileInfo file(tmp);

    if (file.isDir())
    {
        teGroup1->append(tmp);
    }
    else
    {
        QMessageBox warning(QMessageBox::Warning,
                            QString("Invalid Directory!"),
                            QString("The specified directory cannot be found!"
                                    "\n"
                                    "\nPlease enter a valid directory for Group 1."),
                            QMessageBox::Ok,
                            cbPreset);

        warning.exec();
    }

    return;
}

//Add selection to Group 2.
//Triggered by clicking Add.
void DuplicateFile::addGroup2()
{
    QString tmp = leDirectory->text();

    QFileInfo file(tmp);

    if (file.isDir())
    {
        teGroup2->append(tmp);
    }
    else
    {
        QMessageBox warning(QMessageBox::Warning,
                            QString("Invalid Directory!"),
                            QString("The specified directory cannot be found!"
                                    "\n"
                                    "\nPlease enter a valid directory for Group 2."),
                            QMessageBox::Ok,
                            cbPreset);

        warning.exec();
    }

    return;
}

//Remove selection from Group 1.
//Triggered by clicking Remove.
void DuplicateFile::removeGroup1()
{


    return;
}

//Remove selection from Group 2.
//Triggered by clicking Remove.
void DuplicateFile::removeGroup2()
{
    return;
}

//Destructor.
DuplicateFile::~DuplicateFile()
{
    return;
}
