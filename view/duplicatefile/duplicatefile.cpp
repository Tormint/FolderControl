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

#include <QPixmap>
#include <QLabel>

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
    return;
}

//Configures the objects that will be used in the view.
//Extends the functions of the base class implementations.
void DuplicateFile::configureObjects()
{
    return;
}

//Places the view objects in their perspective layouts and sets the layouts.
//Extends the functions of the base class implementations.
void DuplicateFile::placeObjects()
{
    return;
}

//Connects the objects to their functional and managing code sources.
//Extends the functions of the base class implementations.
void DuplicateFile::connectObjects()
{
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

//Implementation that adjusts the preconfigured selection based on current settings.
//Triggered by changing settings.
////index(int): refers to the index that will be applied.
void DuplicateFile::updatePreset(const int index)
{
    return;
}

//Destructor.
DuplicateFile::~DuplicateFile()
{
    return;
}
