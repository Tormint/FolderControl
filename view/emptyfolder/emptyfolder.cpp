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
////This file serves as the implementation file of the GUI for the 'Empty
////Folder Remover' functionality of the program 'FolderControl'.
////
////The GUI controls all aspects related to the view and inherits from the base
////class 'Tab'. It overrides virtual functions only and extends non-virtual
////functions.
////
////This file is a work in progress.

#include "emptyfolder.h"

//Qt Libs:

#include <QFileDialog>
#include <QMessageBox>
#include <QHeaderView>
#include <QMessageBox>
#include <QFileInfo>

//Constructor.
EmptyFolder::EmptyFolder(QObject *parent) : Tab(parent)
{
    //Setup Tab:

    init();

    return;
}

//Initializes the objects that will be used in the view.
//Extends the functions of the base class implementations.
void EmptyFolder::createObjects()
{
    leDirectory = new QLineEdit();
    leIgnore = new QLineEdit();

    rbAppend = new QRadioButton("Append");
    rbClear = new QRadioButton("Clear");

    teIgnore = new QTextEdit();

    pbStart = new QPushButton("Start");
    pbClear = new QPushButton("Clear");
    pbSelect = new QPushButton("...");
    pbCopy = new QPushButton("Copy");
    pbIgnore = new QPushButton("...");
    pbDirDrop = new QPushButton("");
    pbIgnDrop = new QPushButton("");
    pbTreeList = new QPushButton("");

    glDirectory = new QGridLayout();
    glIgnore = new QGridLayout();
    glOutput = new QGridLayout();

    hblDirectory = new QHBoxLayout();
    hblIgnore = new QHBoxLayout();
    hblDirDrop = new QHBoxLayout();
    hblIgnDrop = new QHBoxLayout();

    gbDirectory = new QGroupBox("Directory:");
    gbOutput = new QGroupBox("Folders:");
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
void EmptyFolder::configureObjects()
{
    rbAppend->setChecked(true);

    leDirectory->setPlaceholderText("Enter directory to scan here...");
    leIgnore->setPlaceholderText("Enter file or folder to import here...");

    leDirectory->setEnabled(true);

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

    pbSelect->setMaximumWidth(40);
    pbSelect->setMinimumWidth(40);

    pbIgnore->setMaximumWidth(40);
    pbIgnore->setMinimumWidth(40);

    pbStart->setMaximumWidth(80);
    pbClear->setMaximumWidth(80);
    pbCopy->setMaximumWidth(80);

    pbStart->setMinimumWidth(80);
    pbClear->setMinimumWidth(80);
    pbCopy->setMaximumWidth(80);

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
void EmptyFolder::placeObjects()
{
    hblDirectory->addWidget(leDirectory);
    hblDirectory->addWidget(pbSelect);

    glDirectory->addLayout(hblDirectory, 0, 0, 1, 6);

    hblDirDrop->addWidget(tvDirectory);

    fDirectory->setLayout(hblDirDrop);

    glDirectory->addWidget(fDirectory, 1, 0, 5, 6);

    glDirectory->addWidget(pbDirDrop, 6, 0, 1, 6);

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

    glOutput->addWidget(tvOutput, 0, 0, 10, 6);
    glOutput->addWidget(lvOutput, 0, 0, 10, 6);
    glOutput->addWidget(pbTreeList, 11, 0, 1, 6, Qt::AlignCenter);

    gbOutput->setLayout(glOutput);

    glMainLayout->addWidget(gbOutput, 12, 0, 10, 6);

    glMainLayout->addWidget(lOutput, 22, 0, 1, 4);
    glMainLayout->addWidget(pbStatus, 22, 0, 1, 4);
    glMainLayout->addWidget(pbClear, 22, 4, 1, 1);
    glMainLayout->addWidget(pbStart, 22, 5, 1, 1);

    return;
}

//Connects the objects to their functional and managing code sources.
//Extends the functions of the base class implementations.
void EmptyFolder::connectObjects()
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

    return;
}

//Creates and stores preconfigurations.
//Overrides base class implementation.
void EmptyFolder::createPreset(int index)
{
    return;
}

//Removes and deletes preconfigurations.
//Overrides base class implementation.
void EmptyFolder::removePreset(int index)
{
    return;
}

//File selection dialog.
//Triggered by clicking the Import button.
void EmptyFolder::selectFile()
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
void EmptyFolder::selectFolder()
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
void EmptyFolder::updatePreset(int index) //Duplicate
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
void EmptyFolder::copyLayout()
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
void EmptyFolder::startProcess()
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
void EmptyFolder::clearSettings()
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
void EmptyFolder::updateSettings()
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
void EmptyFolder::expandDirectory()
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
void EmptyFolder::expandIgnore()
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
void EmptyFolder::updateDirModelLocation()
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
void EmptyFolder::updateIgnModelLocation()
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
void EmptyFolder::updateDirectory()
{
    leDirectory->blockSignals(true);

    QModelIndex index = tvDirectory->currentIndex();

    leDirectory->setText(fsmDirectory->filePath(index));

    leDirectory->blockSignals(false);

    return;
}

//Sets the Ignore Line Edit to match the Tree View address.
//Triggered by changing the Tree View selection.
void EmptyFolder::updateIgnore()
{
    leIgnore->blockSignals(true);

    QModelIndex index = tvIgnore->currentIndex();

    leIgnore->setText(fsmIgnore->filePath(index));

    leIgnore->blockSignals(false);

    return;
}

//Toggle between different view types.
//Triggered by clicking the view icon.
void EmptyFolder::toggleTreeList(bool checked)
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

//Destructor.
EmptyFolder::~EmptyFolder()
{
    return;
}
