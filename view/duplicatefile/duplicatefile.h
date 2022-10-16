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
////This file serves as the definition file of the GUI for the 'Duplicate
////Finder' functionality of the program 'FolderControl'.
////
////The GUI controls all aspects related to the view and inherits from the base
////class 'Tab'. It overrides virtual functions only and extends non-virtual
////functions.
////
////This file is a work in progress.

#ifndef DUPLICATEFILE_H
#define DUPLICATEFILE_H

//Base Class:

#include "../tab.h"

//Qt Libs:

#include <QObject>
//#include <QProperty>

//'Duplicate Finder' tab interface.
class DuplicateFile : public Tab
{
    Q_OBJECT

public:

    //Constructor.
    DuplicateFile(QObject* parent = NULL);

    //Destructor.
    ~DuplicateFile();

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
    ////index(int): refers to the new preset value.
    void createPreset(const int index) override;

    //Removes and deletes preconfigurations.
    //Overrides base class implementation.
    ////index(int): refers to the value of the preset to be removed.
    void removePreset(const int index) override;

private:



public slots:

    //Implementation that adjusts the preconfigured selection based on current settings.
    //Triggered by changing settings.
    ////index(int): refers to the index that will be applied.
    void updatePreset(const int index) override;

};

#endif // DUPLICATEFILE_H
