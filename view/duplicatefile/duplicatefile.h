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

#include "../tab.h"

#include <QObject>
#include <QProperty>

class DuplicateFile : public Tab
{
    Q_OBJECT

public:

    DuplicateFile(QObject* parent = NULL);
    ~DuplicateFile();

protected:

    void createObjects();
    void configureObjects();
    void placeObjects();
    void connectObjects();

    void createPreset(int index) override;
    void removePreset(int index) override;

private:



public slots:

    void updatePreset(int index) override;

};

#endif // DUPLICATEFILE_H
