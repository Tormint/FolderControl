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
////This file serves as the definition file of the base class for the 'Tab'
////which describes the basic structure of all tabs on the main interface of
////the program 'FolderControl'.
////
////The GUI controls all aspects related to the tab structure. Creating a
////uniform structure.
////
////This file is a work in progress.

#ifndef TAB_H
#define TAB_H

//Qt Libs:

#include <QObject>
#include <QFrame>
#include <QScrollArea>
#include <QGridLayout>
#include <QLabel>
#include <QGraphicsOpacityEffect>
#include <QComboBox>
#include <QPushButton>
#include <QGroupBox>
#include <QHBoxLayout>
#include <QString>

//Base class for all tabs on the main interface.
class Tab : public QObject
{
    Q_OBJECT

public:

    //Constructor.
    Tab(QObject *parent = NULL);

    //Member Functions:

    //Returns a tab widget(pointer) to be inserted into a view.
    QScrollArea* getTab();

    //Returns a layout(pointer) to add widgets onto the tab.
    QGridLayout* getLayout();

    //Destructor.
    ~Tab();

protected:

    //Inheritance Objects:

    //The main layout of the tab.
    //Used to modify the appearance of the tab.
    QGridLayout *glMainLayout;

    //The output label used to provide feedback.
    //Used as a standard output interface.
    QLabel *lOutput;

    //The preverence selection.
    //Used to display and select preconfigured options.
    QComboBox *cbPreset;

    //Member Functions:

    //Initializes the derived class.
    virtual void init();

    //Initializes the objects that will be used in the view.
    //Provides some function.
    //Should be used along with its derived implementations.
    virtual void createObjects();

    //Configures the objects that will be used in the view.
    //Provides some function.
    //Should be used along with its derived implementations.
    virtual void configureObjects();

    //Places the view objects in their perspective layouts and sets the layouts.
    //Provides some function.
    //Should be used along with its derived implementations.
    virtual void placeObjects();

    //Connects the objects to their functional and managing code sources.
    //Provides some function.
    //Should be used along with its derived implementations.
    virtual void connectObjects();

    //Pure Virtual definition to create preconfigurations for derived classes.
    ////index(int): refers to the new preset value.
    virtual void createPreset(const int index) = 0;

    //Pure Virtual definition to remove preconfigurations for derived classes.
    ////index(int): refers to the value of the preset to be removed.
    virtual void removePreset(const int index) = 0;

    //Provides a standard method to provide program feedback.
    void updateOutput(QString output);

private:

    //Structural Objects:

    //Central object of the view.
    //Frame to enable QScrollArea to function correctly.
    QFrame *fView;

    //Scroll Area to make the view adapt to any interface configuration.
    QScrollArea *saView;

    //Graphic effect reducing the striking nature of the output label.
    QGraphicsOpacityEffect *goeFade;

    //Functional Objects:

    //Buttons for the Preset interface.
    QPushButton *pbSave,    //Save button to add new preconfigurations.
                *pbDelete;  //Delete button to remove preconfigurations.

    //Group Box to group all preconfiguration widgets.
    QGroupBox *gbPreset;

    //Layout for the preconfiguration group box.
    QHBoxLayout *hblPreset;

public slots:

    //Slot for the Save button being clicked.
    void savePreset();

    //Slot for the Delete button being clicked.
    void deletePreset();

    //Pure Virtual Slot that is triggered when the combo box selection is changed.
    ////index(int): refers to the index that will be applied.
    virtual void updatePreset(const int index) = 0;
};

#endif // TAB_H
