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

//Tab Base Class
//
////This file serves as the implementation file of the base class for the 'Tab'
////which describes the basic structure of all tabs on the main interface of
////the program 'FolderControl'.
////
////The GUI controls all aspects related to the tab structure. Creating a
////uniform structure.
////
////This file is a work in progress.

#include "tab.h"

//Qt Libs:

#include <QInputDialog>
#include <QMessageBox>

//Constructor.
Tab::Tab(QObject *parent) : QObject(parent)
{
    //Setup Tab:

    init();

    return;
}

//Returns a tab widget(pointer) to be inserted into a view.
QScrollArea* Tab::getTab()
{
    return saView;
}

//Returns a layout(pointer) to add widgets onto the tab.
QGridLayout* Tab::getLayout()
{
    return glMainLayout;
}

//Initializes the derived class.
void Tab::init()
{
    //Setup Derived Class:

    createObjects();
    configureObjects();
    placeObjects();
    connectObjects();

    return;
}

//Initializes the objects that will be used in the view.
//Provides some function.
//Should be used along with its derived implementations.
void Tab::createObjects()
{
    fView = new QFrame();

    saView = new QScrollArea();

    glMainLayout = new QGridLayout();

    lOutput = new QLabel("");

    goeFade = new QGraphicsOpacityEffect();

    cbPreset = new QComboBox();

    pbSave = new QPushButton("Save");
    pbDelete = new QPushButton("Delete");

    gbPreset = new QGroupBox("Preset:");

    hblPreset = new QHBoxLayout();

    gbPreset = new QGroupBox();

    hblPreset = new QHBoxLayout();

    return;
}

//Configures the objects that will be used in the view.
//Provides some function.
//Should be used along with its derived implementations.
void Tab::configureObjects()
{
    fView->setFrameShape(QFrame::NoFrame);
    fView->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);

    glMainLayout->setSizeConstraint(QLayout::SetMinimumSize);

    lOutput = new QLabel("Press \"Start\" to begin...");

    goeFade->setOpacity(0.4);

    lOutput->setGraphicsEffect(goeFade);

    cbPreset->setEditable(false);
    cbPreset->addItem("<Custom>");

    pbSave->setMaximumWidth(80);
    pbDelete->setMaximumWidth(80);

    pbSave->setMinimumWidth(80);
    pbDelete->setMinimumWidth(80);

    saView->setWidgetResizable(true);
    saView->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    saView->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    saView->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);

    return;
}

//Places the view objects in their perspective layouts and sets the layouts.
//Provides some function.
//Should be used along with its derived implementations.
void Tab::placeObjects()
{
    saView->setWidget(fView);

    fView->setLayout(glMainLayout);

    hblPreset->addWidget(cbPreset);
    hblPreset->addWidget(pbDelete);
    hblPreset->addWidget(pbSave);

    gbPreset->setLayout(hblPreset);

    glMainLayout->addWidget(gbPreset, 0, 0, 2, 6);

    return;
}

//Connects the objects to their functional and managing code sources.
//Provides some function.
//Should be used along with its derived implementations.
void Tab::connectObjects()
{
    QObject::connect(cbPreset, SIGNAL(currentIndexChanged(int)), this, SLOT(updatePreset(int)));

    QObject::connect(pbSave, SIGNAL(clicked(bool)), this, SLOT(savePreset()));
    QObject::connect(pbDelete, SIGNAL(clicked(bool)), this, SLOT(deletePreset()));

    return;
}

//Slot for the Save button being clicked.
void Tab::savePreset()
{
    updateOutput("Saving Preset...");

    cbPreset->blockSignals(true);

    bool ok = false;

    QString tmp = QInputDialog::getText(nullptr, "Enter Name", "Please enter a name for this preset?", QLineEdit::Normal, QString(), &ok);

    if (ok && !(tmp.isEmpty()))
    {
        cbPreset->addItem(tmp);

        int index = (cbPreset->count() - 1);

        cbPreset->setCurrentIndex(index);

        createPreset(index);
    }
    else
    {
        QMessageBox warning(QMessageBox::Warning,
                            QString("Cannot Save Preset!"),
                            QString("The Preset could not be saved!"),
                            QMessageBox::Ok,
                            cbPreset);

        warning.exec();
    }

    cbPreset->blockSignals(false);

    updateOutput("Settings Saved!");

    return;
}

//Slot for the Delete button being clicked.
void Tab::deletePreset()
{
    updateOutput("Deleting Preset...");

    cbPreset->blockSignals(true);

    int index = cbPreset->currentIndex();

    if (index == 0)
    {
        QMessageBox warning(QMessageBox::Warning,
                            QString("Cannot Delete!"),
                            QString("Cannot delete default preset."),
                            QMessageBox::Ok,
                            cbPreset);

        warning.exec();

        updateOutput("Could Not Delete Preset!");
    }
    else
    {
        removePreset(index);

        cbPreset->removeItem(cbPreset->currentIndex());

        updateOutput("Preset Deleted!");

        cbPreset->setCurrentIndex(0);
    }

    cbPreset->blockSignals(false);

    return;
}

//Provides a standard method to provide program feedback.
void Tab::updateOutput(QString output)
{
    lOutput->setText(output);

    return;
}

//DEstructor.
Tab::~Tab()
{
    return;
}
