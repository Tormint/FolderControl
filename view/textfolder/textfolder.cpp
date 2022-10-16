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
////This file serves as the implementation file of the GUI for the 'Text To
////Folder' functionality of the program 'FolderControl'.
////
////The GUI controls all aspects related to the view and inherits from the base
////class 'Tab'. It overrides virtual functions only and extends non-virtual
////functions.
////
////This file is a work in progress.

#include "textfolder.h"

//Qt Libs:

#include <QFileDialog>
#include <QMessageBox>
#include <QHeaderView>
#include <QMessageBox>
#include <QFileInfo>

//Constructor.
TextFolder::TextFolder(QObject *parent) : Tab(parent)
{
    //Setup Tab:

    init();

    return;
}

//Initializes the objects that will be used in the view.
//Extends the functions of the base class implementations.
void TextFolder::createObjects()
{
    leDirectory = new QLineEdit();

    leImport = new QLineEdit();

    rbAppend = new QRadioButton("Append");
    rbClear = new QRadioButton("Clear");

    teFolder = new QTextEdit();

    pbStart = new QPushButton("Start");
    pbClear = new QPushButton("Clear");
    pbSelect = new QPushButton("...");
    pbSave = new QPushButton("Save");
    pbDelete = new QPushButton("Delete");
    pbImport = new QPushButton("...");
    pbCopy = new QPushButton("Copy");
    pbDirDrop = new QPushButton("");
    pbImpDrop = new QPushButton("");

    glDirectory = new QGridLayout();
    glImport = new QGridLayout();

    hblDirectory = new QHBoxLayout();
    hblImport = new QHBoxLayout();
    hblFolder = new QHBoxLayout();
    hblDirDrop = new QHBoxLayout();
    hblImpDrop = new QHBoxLayout();

    gbDirectory = new QGroupBox("Directory:");
    gbImport = new QGroupBox("Import List:");
    gbFolder = new QGroupBox("Folders:");

    fDirectory = new QFrame();
    fImport = new QFrame();

    tvDirectory = new QTreeView();
    tvImport = new QTreeView();

    fsmDirectory = new QFileSystemModel();
    fsmImport = new QFileSystemModel();

    pbStatus = new QProgressBar();

    return;
}

//Configures the objects that will be used in the view.
//Extends the functions of the base class implementations.
void TextFolder::configureObjects()
{
    leDirectory->setPlaceholderText("Enter destination directory here...");
    leImport->setPlaceholderText("Enter file or folder to import here...");

    leDirectory->setEnabled(true);
    leImport->setEnabled(true);

    teFolder->setEnabled(true);
    teFolder->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    teFolder->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);

    teFolder->setPlaceholderText("Folders to create..."
                                 "\n"
                                 "\nExample:"
                                 "\n"
                                 "\nC:/Example/New1"
                                 "\nC:/Example/New2"
                                 "\nC:\\Foo\\Bar\\New"
                                 "\n");

    pbSelect->setMaximumWidth(40);
    pbImport->setMaximumWidth(40);

    pbSelect->setMinimumWidth(40);
    pbImport->setMinimumWidth(40);

    pbStart->setMaximumWidth(80);
    pbClear->setMaximumWidth(80);
    pbSave->setMaximumWidth(80);
    pbDelete->setMaximumWidth(80);
    pbCopy->setMaximumWidth(80);

    pbStart->setMinimumWidth(80);
    pbClear->setMinimumWidth(80);
    pbSave->setMinimumWidth(80);
    pbDelete->setMinimumWidth(80);
    pbCopy->setMaximumWidth(80);

    pbDirDrop->setFlat(true);
    pbImpDrop->setFlat(true);

    pbDirDrop->setIcon(pbDirDrop->style()->standardIcon(QStyle::SP_TitleBarUnshadeButton));
    pbImpDrop->setIcon(pbImpDrop->style()->standardIcon(QStyle::SP_TitleBarUnshadeButton));

    rbAppend->setChecked(true);

    pbStatus->setValue(0);
    pbStatus->setVisible(false);

    fDirectory->setFrameShape(QFrame::NoFrame);
    fImport->setFrameShape(QFrame::NoFrame);

    fDirectory->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::MinimumExpanding);
    fImport->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::MinimumExpanding);

    fDirectory->setVisible(false);
    fImport->setVisible(false);

    fDirectory->sizePolicy().setRetainSizeWhenHidden(false);
    fImport->sizePolicy().setRetainSizeWhenHidden(false);

    tvDirectory->setModel(fsmDirectory);
    tvImport->setModel(fsmImport);

    fsmDirectory->setRootPath(QDir::root().path());
    fsmImport->setRootPath(QDir::root().path());

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

    tvImport->hideColumn(1);
    tvImport->hideColumn(2);
    tvImport->hideColumn(3);

    tvImport->setSizePolicy(QSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Preferred));
    //tvImport->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
    tvImport->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    tvImport->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);

    tvImport->header()->setSectionHidden(1, true);
    tvImport->header()->setSectionHidden(2, true);
    tvImport->header()->setSectionHidden(3, true);

    tvImport->setHeaderHidden(true);

    tvImport->header()->setSectionResizeMode(QHeaderView::ResizeToContents);

    tvDirectory->setSelectionBehavior(QAbstractItemView::SelectItems);
    tvImport->setSelectionBehavior(QAbstractItemView::SelectItems);

    fsmDirectory->setFilter(QDir::AllDirs | QDir::NoDotAndDotDot);
    fsmImport->setFilter(QDir::NoDotAndDotDot | QDir::AllDirs | QDir::Files);

    fsmDirectory->sort(0, Qt::AscendingOrder);
    fsmImport->sort(0, Qt::AscendingOrder);

    return;
}

//Places the view objects in their perspective layouts and sets the layouts.
//Extends the functions of the base class implementations.
void TextFolder::placeObjects()
{
    hblDirectory->addWidget(leDirectory);
    hblDirectory->addWidget(pbSelect);

    glDirectory->addLayout(hblDirectory, 0, 0, 1, 6);

    hblDirDrop->addWidget(tvDirectory);

    fDirectory->setLayout(hblDirDrop);

    glDirectory->addWidget(fDirectory, 1, 0, 5, 6);

    glDirectory->addWidget(pbDirDrop, 6, 0, 1, 6);

    gbDirectory->setLayout(glDirectory);

    glMainLayout->addWidget(gbDirectory, 2, 0, 2, 6);

    hblImport->addWidget(leImport);
    hblImport->addWidget(pbImport);

    glImport->addLayout(hblImport, 0, 0, 1, 6);

    glImport->addWidget(rbAppend, 1, 1, 1, 1);
    glImport->addWidget(rbClear, 1, 2, 1, 1);
    glImport->addWidget(pbCopy, 1, 5, 1, 1);

    hblImpDrop->addWidget(tvImport);

    fImport->setLayout(hblImpDrop);

    glImport->addWidget(fImport, 2, 0, 5, 6);

    glImport->addWidget(pbImpDrop, 7, 0, 1, 6);

    gbImport->setLayout(glImport);

    glMainLayout->addWidget(gbImport, 4, 0, 2, 6);

    hblFolder->addWidget(teFolder);

    gbFolder->setLayout(hblFolder);

    glMainLayout->addWidget(gbFolder, 7, 0, 10, 6);

    glMainLayout->addWidget(lOutput, 17, 0, 1, 4);
    glMainLayout->addWidget(pbStatus, 17, 0, 1, 4);
    glMainLayout->addWidget(pbClear, 17, 4, 1, 1);
    glMainLayout->addWidget(pbStart, 17, 5, 1, 1);

    return;
}

//Connects the objects to their functional and managing code sources.
//Extends the functions of the base class implementations.
void TextFolder::connectObjects()
{
    QObject::connect(pbSelect, SIGNAL(clicked(bool)), this, SLOT(selectFolder()));
    QObject::connect(pbImport, SIGNAL(clicked(bool)), this, SLOT(selectFile()));

    QObject::connect(pbCopy, SIGNAL(clicked(bool)), this, SLOT(copyLayout()));

    QObject::connect(pbStart, SIGNAL(clicked(bool)), this, SLOT(startProcess()));
    QObject::connect(pbClear, SIGNAL(clicked(bool)), this, SLOT(clearSettings()));

    QObject::connect(leDirectory, SIGNAL(editingFinished()), this, SLOT(updateSettings()));
    QObject::connect(leImport, SIGNAL(editingFinished()), this, SLOT(updateSettings()));
    QObject::connect(rbAppend, SIGNAL(toggled(bool)), this, SLOT(updateSettings()));
    QObject::connect(teFolder, SIGNAL(textChanged()), this, SLOT(updateSettings()));

    QObject::connect(pbDirDrop, SIGNAL(clicked(bool)), this, SLOT(expandDirectory()));
    QObject::connect(pbImpDrop, SIGNAL(clicked(bool)), this, SLOT(expandImport()));

    QObject::connect(tvDirectory->selectionModel(), SIGNAL(selectionChanged(QItemSelection,QItemSelection)), this, SLOT(updateDirectory()));
    QObject::connect(tvImport->selectionModel(), SIGNAL(selectionChanged(QItemSelection,QItemSelection)), this, SLOT(updateImport()));

    QObject::connect(leDirectory, SIGNAL(editingFinished()), this, SLOT(updateDirModelLocation()));
    QObject::connect(leImport, SIGNAL(editingFinished()), this, SLOT(updateImpModelLocation()));

    return;
}

//Creates and stores preconfigurations.
//Overrides base class implementation.
////index(int): refers to the new preset value.
void TextFolder::createPreset(const int index)
{
    return;
}

//Removes and deletes preconfigurations.
//Overrides base class implementation.
////index(int): refers to the value of the preset to be removed.
void TextFolder::removePreset(const int index)
{
    return;
}

//File selection dialog.
//Triggered by clicking the Import button.
void TextFolder::selectFile()
{
    //To select both files and folders will require a custom implementation
    //of QInputDialog. So for now, the item selection using a dialog is limited
    //to files only.

    updateOutput("Selecting File...");

    QString tmp = QFileDialog::getOpenFileName(nullptr, "Import", leImport->text(), "All Files (*.*)");

    if (tmp.length() != 0)
    {
        leImport->blockSignals(true);
        leImport->setText(tmp);
        leImport->blockSignals(false);
    }

    updateImpModelLocation();

    updateOutput("File Selected!");

    return;
}

//Folder selection dialog.
//Triggered by clicking the Select button.
void TextFolder::selectFolder()
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
void TextFolder::updatePreset(const int index) //Duplicate
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
void TextFolder::copyLayout()
{
    updateOutput("Copying Layout...");

    if (QFileInfo(leImport->text()).isDir())
    {
        //connect control
    }
    else if (QFileInfo(leImport->text()).isFile())
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
void TextFolder::startProcess()
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
                            QString("The specified directory cannot be found!"
                                    "\n"
                                    "\nPlease enter a valid directory name to copy"
                                    "\nthe folder tree structure."),
                            QMessageBox::Ok,
                            cbPreset);

        warning.exec();
    }

    updateOutput("Finished!");

    return;
}

//Restores default settings.
//Triggered by clicking the 'Clear' button.
void TextFolder::clearSettings()
{
    updateOutput("Clearing Settings...");

    cbPreset->blockSignals(true);
    leDirectory->blockSignals(true);
    leImport->blockSignals(true);
    tvDirectory->blockSignals(true);
    tvImport->blockSignals(true);
    fsmDirectory->blockSignals(true);
    fsmImport->blockSignals(true);
    teFolder->blockSignals(true);

    tvDirectory->selectionModel()->clear();
    tvImport->selectionModel()->clear();

    leDirectory->clear();
    leImport->clear();

    teFolder->clear();

    rbAppend->setChecked(true);

    cbPreset->setCurrentIndex(0);

    cbPreset->blockSignals(false);
    leDirectory->blockSignals(false);
    leImport->blockSignals(false);
    tvDirectory->blockSignals(false);
    tvImport->blockSignals(false);
    fsmDirectory->blockSignals(false);
    fsmImport->blockSignals(false);
    teFolder->blockSignals(false);

    updateOutput("Settings Cleared!");

    return;
}

//Changes the settings.
//Triggered by a change in preset selection.
void TextFolder::updateSettings()
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
void TextFolder::expandDirectory()
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

//Makes the Import Tree View widget visible.
//Triggered by clicking the expand button.
void TextFolder::expandImport()
{
    if (fImport->isVisible())
    {
        fImport->setVisible(false);

        pbImpDrop->setIcon(pbImpDrop->style()->standardIcon(QStyle::SP_TitleBarUnshadeButton));
    }
    else
    {
        fImport->setVisible(true);

        pbImpDrop->setIcon(pbImpDrop->style()->standardIcon(QStyle::SP_TitleBarShadeButton));
    }

    return;
}

//Sets the Directory Tree View to match the Line Edit address.
//Triggered by changing the Line Edit text.
void TextFolder::updateDirModelLocation()
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

//Sets the Import Tree View to match the Line Edit address.
//Triggered by changing the Line Edit text.
void TextFolder::updateImpModelLocation()
{
    leImport->blockSignals(true);
    tvImport->blockSignals(true);
    fsmImport->blockSignals(true);

    QModelIndex index = fsmImport->index(leImport->text(), 0);

    tvImport->selectionModel()->clear();
    tvImport->selectionModel()->setCurrentIndex(index, QItemSelectionModel::Select);

    leImport->blockSignals(false);
    tvImport->blockSignals(false);
    fsmImport->blockSignals(false);

    return;
}

//Sets the Directory Line Edit to match the Tree View address.
//Triggered by changing the Tree View selection.
void TextFolder::updateDirectory()
{
    leDirectory->blockSignals(true);

    QModelIndex index = tvDirectory->currentIndex();

    leDirectory->setText(fsmDirectory->filePath(index));

    leDirectory->blockSignals(false);

    return;
}

//Sets the Import Line Edit to match the Tree View address.
//Triggered by changing the Tree View selection.
void TextFolder::updateImport()
{
    leImport->blockSignals(true);

    QModelIndex index = tvImport->currentIndex();

    leImport->setText(fsmImport->filePath(index));

    leImport->blockSignals(false);

    return;
}

//Destructor.
TextFolder::~TextFolder()
{
    return;
}
