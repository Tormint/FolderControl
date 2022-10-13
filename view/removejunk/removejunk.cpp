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
////This file serves as the implementation file of the GUI for the 'Remove Junk
////Files' functionality of the program 'FolderControl'.
////
////The GUI controls all aspects related to the view and inherits from the base
////class 'Tab'. It overrides virtual functions only and extends non-virtual
////functions.
////
////This file is a work in progress.

#include "removejunk.h"

//Qt Libs:

#include <QFileDialog>
#include <QHeaderView>
#include <QMessageBox>
#include <QFileInfo>
#include <QRect>

//Constructor.
RemoveJunk::RemoveJunk()
{
    //Setup Tab:

    init();

    return;
}

//Initializes the objects that will be used in the view.
//Extends the functions of the base class implementations.
void RemoveJunk::createObjects()
{
    lRemove = new QLabel("Remove List:");

    lHelp = new QLabel("Format 1: \t\"file.jpg, *.avi, file.*" //HTML tags break QLabel.
                       "\n"
                       "\nFormat 2: \t\"file.jpg\""
                       "\n\t\t\"*.avi\""
                       "\n\t\t\"file.*\""
                       "\n"
                       "\n(Supports Wildcards [*].)");

    leDirectory = new QLineEdit();

    cbSubFolder = new QCheckBox("Include Subfolders");

    teJunk = new QTextEdit();
    teOutput = new QTextEdit();

    pbStart = new QPushButton("Start");
    pbClear = new QPushButton("Clear");
    pbSelect = new QPushButton("...");
    pbDirDrop = new QPushButton("");
    pbHelp = new QPushButton("");

    gbDirectory = new QGroupBox("Directory:");
    gbSetting = new QGroupBox("Settings:");
    gbOutput = new QGroupBox("Output:");

    glDirectory = new QGridLayout();
    glSetting = new QGridLayout();
    glHelp = new QGridLayout();

    hblDirectory = new QHBoxLayout();
    hblDirDrop = new QHBoxLayout();
    hblOutput = new QHBoxLayout();

    fDirectory = new QFrame();
    fHelp = new QFrame();

    tvDirectory = new QTreeView();

    fsmDirectory = new QFileSystemModel();

    pbStatus = new QProgressBar();

    return;
}

//Configures the objects that will be used in the view.
//Extends the functions of the base class implementations.
void RemoveJunk::configureObjects()
{
    leDirectory->setPlaceholderText("Enter directory to scan here...");

    leDirectory->setEnabled(true);

    teJunk->setEnabled(true);
    teJunk->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    teJunk->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);

    teOutput->setPlaceholderText("Filters..."
                                 "\n"
                                 "\nExample 1: Desktop.ini, *.ini, temp.*"
                                 "\n"
                                 "\nExample 2:\tDesktop.ini"
                                 "\n\t\t*.ini"
                                 "\n\t\ttemp.*"
                                 "\n"
                                 "\n(Supports Wildcards [*].)");

    teOutput->setEnabled(false);
    teOutput->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    teOutput->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);

    cbSubFolder->setChecked(true);

    pbSelect->setMaximumWidth(40);

    pbSelect->setMinimumWidth(40);

    pbStart->setMaximumWidth(80);
    pbClear->setMaximumWidth(80);

    pbStart->setMinimumWidth(80);
    pbClear->setMinimumWidth(80);

    pbDirDrop->setFlat(true);
    pbHelp->setFlat(true);

    pbDirDrop->setIcon(pbDirDrop->style()->standardIcon(QStyle::SP_TitleBarUnshadeButton));
    pbHelp->setIcon(pbHelp->style()->standardIcon(QStyle::SP_MessageBoxQuestion));

    pbStatus->setValue(0);
    pbStatus->setVisible(false);

    fDirectory->setFrameShape(QFrame::NoFrame);

    fDirectory->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::MinimumExpanding);
    fHelp->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);

    fDirectory->setVisible(false);
    fHelp->setVisible(false);

    fDirectory->sizePolicy().setRetainSizeWhenHidden(false);
    fHelp->sizePolicy().setRetainSizeWhenHidden(false);

    fHelp->setFrameShape(QFrame::Panel);
    fHelp->setFrameShadow(QFrame::Sunken);

    tvDirectory->setModel(fsmDirectory);

    fsmDirectory->setRootPath(QDir::root().path());

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

    fsmDirectory->setFilter(QDir::AllDirs | QDir::NoDotAndDotDot);

    fsmDirectory->sort(0, Qt::AscendingOrder);

    return;
}

//Places the view objects in their perspective layouts and sets the layouts.
//Extends the functions of the base class implementations.
void RemoveJunk::placeObjects()
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

    glHelp->addWidget(lHelp, 0, 0, 7, 2);

    fHelp->setLayout(glHelp);

    glSetting->addWidget(lRemove, 0, 0, 1, 1);
    glSetting->addWidget(pbHelp, 0, 1, 1, 1);

    glSetting->addWidget(teJunk, 8, 0, 10, 2);
    glSetting->addWidget(cbSubFolder, 18, 0, 1, 2);

    gbSetting->setLayout(glSetting);

    glMainLayout->addWidget(gbSetting, 4, 0, 10, 2);

    hblOutput->addWidget(teOutput);

    gbOutput->setLayout(hblOutput);

    glMainLayout->addWidget(gbOutput, 4, 2, 10, 4);

    glMainLayout->addWidget(lOutput, 14, 0, 1, 4);
    glMainLayout->addWidget(pbStatus, 14, 0, 1, 4);
    glMainLayout->addWidget(pbClear, 14, 4, 1, 1);
    glMainLayout->addWidget(pbStart, 14, 5, 1, 1);

    return;
}

//Connects the objects to their functional and managing code sources.
//Extends the functions of the base class implementations.
void RemoveJunk::connectObjects()
{
    QObject::connect(pbSelect, SIGNAL(clicked(bool)), this, SLOT(selectFolder()));

    QObject::connect(pbStart, SIGNAL(clicked(bool)), this, SLOT(startProcess()));
    QObject::connect(pbClear, SIGNAL(clicked(bool)), this, SLOT(clearSettings()));

    QObject::connect(pbStart, SIGNAL(clicked(bool)), this, SLOT(startProcess()));
    QObject::connect(pbClear, SIGNAL(clicked(bool)), this, SLOT(clearSettings()));

    QObject::connect(leDirectory, SIGNAL(editingFinished()), this, SLOT(updateSettings()));
    QObject::connect(cbSubFolder, SIGNAL(toggled(bool)), this, SLOT(updateSettings()));
    QObject::connect(teJunk, SIGNAL(textChanged()), this, SLOT(updateSettings()));

    QObject::connect(pbDirDrop, SIGNAL(clicked(bool)), this, SLOT(expandDirectory()));

    QObject::connect(tvDirectory->selectionModel(), SIGNAL(selectionChanged(QItemSelection,QItemSelection)), this, SLOT(updateDirectory()));

    QObject::connect(leDirectory, SIGNAL(editingFinished()), this, SLOT(updateDirModelLocation()));

    QObject::connect(pbHelp, SIGNAL(clicked(bool)), this, SLOT(expandHelp()));

    return;
}

//Creates and stores preconfigurations.
//Overrides base class implementation.
void RemoveJunk::createPreset(int index)
{
    return;
}

//Removes and deletes preconfigurations.
//Overrides base class implementation.
void RemoveJunk::removePreset(int index)
{
    return;
}

//Folder selection dialog.
//Triggered by clicking the Select button.
void RemoveJunk::selectFolder()
{
    updateOutput("Selecting Folder...");

    QString tmp = QFileDialog::getExistingDirectory(nullptr, "Select Folder", leDirectory->text(), QFileDialog::ShowDirsOnly);

    if (tmp.length() != 0)
    {
        leDirectory->setText(tmp);
    }

    updateDirModelLocation();

    updateOutput("Folder Selected!");

    return;
}

//Implementation that adjusts the preconfigured selection based on current settings.
//Triggered by changing settings.
void RemoveJunk::updatePreset(int index)
{
    updateOutput("Loading Settings...");

    //cbPreset->blockSignals(true);

    //control code

    //cbPreset->blockSignals(false);

    updateOutput("Settings Loaded!");

    return;
}

//Starts the scan.
//Triggered by clicking the 'Start'/'Scan' button.
void RemoveJunk::startProcess()
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
                            QString("The specified directory cannot be found!\n\nPlease enter a valid directory name to scan for unwanted files."),
                            QMessageBox::Ok,
                            cbPreset);

        warning.exec();
    }

    updateOutput("Finished!");

    return;
}

//Restores default settings.
//Triggered by clicking the 'Clear' button.
void RemoveJunk::clearSettings()
{
    updateOutput("Clearing Settings...");

    cbPreset->blockSignals(true);
    leDirectory->blockSignals(true);
    tvDirectory->blockSignals(true);
    fsmDirectory->blockSignals(true);
    teJunk->blockSignals(true);
    teOutput->blockSignals(true);

    tvDirectory->selectionModel()->clear();

    leDirectory->clear();

    teJunk->clear();
    teOutput->clear();

    cbSubFolder->setChecked(true);

    cbPreset->setCurrentIndex(0);

    cbPreset->blockSignals(false);
    leDirectory->blockSignals(false);
    tvDirectory->blockSignals(false);
    fsmDirectory->blockSignals(false);
    teJunk->blockSignals(false);
    teOutput->blockSignals(false);

    updateOutput("Settings Cleared!");

    return;
}

//Changes the settings.
//Triggered by a change in preset selection.
void RemoveJunk::updateSettings()
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
void RemoveJunk::expandDirectory()
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

//Expands the help section.
//Triggered by clicking the help icon.
void RemoveJunk::expandHelp()
{
    if (fHelp->isVisible())
    {
        fHelp->setVisible(false);
        glSetting->removeWidget(fHelp);
    }
    else
    {
        fHelp->setVisible(true);
        glSetting->addWidget(fHelp, 1, 0, 7, 2);
    }

    return;
}

//Sets the Directory Tree View to match the Line Edit address.
//Triggered by changing the Line Edit text.
void RemoveJunk::updateDirModelLocation()
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

//Sets the Import Line Edit to match the Tree View address.
//Triggered by changing the Tree View selection.
void RemoveJunk::updateDirectory()
{
    leDirectory->blockSignals(true);

    QModelIndex index = tvDirectory->currentIndex();

    leDirectory->setText(fsmDirectory->filePath(index));

    leDirectory->blockSignals(false);

    return;
}

//Destructor.
RemoveJunk::~RemoveJunk()
{
    if (!fHelp->isVisible())
    {
        delete fHelp;
    }

    return;
}
