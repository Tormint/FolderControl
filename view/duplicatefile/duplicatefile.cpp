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

DuplicateFile::DuplicateFile(QObject *parent) : Tab(parent)
{
    //Setup Tab:

    init();

    return;
}

void DuplicateFile::createObjects()
{
    return;
}

void DuplicateFile::configureObjects()
{
    return;
}

void DuplicateFile::placeObjects()
{
    return;
}

void DuplicateFile::connectObjects()
{
    return;
}

void DuplicateFile::createPreset(int index)
{
    return;
}

void DuplicateFile::removePreset(int index)
{
    return;
}

void DuplicateFile::updatePreset(int index)
{
    return;
}

DuplicateFile::~DuplicateFile()
{
    return;
}
