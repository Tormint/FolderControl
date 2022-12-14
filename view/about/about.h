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

//About Interface
//
////This file serves as the definition file of the GUI for the 'About' dialog
////of the program 'FolderControl'.
////
////The GUI controls all aspects related to the view and inherits from the base
////class 'Window'. It overrides virtual functions only and extends non-virtual
////functions.
////
////This file is a work in progress.

#ifndef ABOUT_H
#define ABOUT_H

//Base Class:

#include "../window.h"

//Qt Libs:

#include <QObject>
#include <QLabel>
#include <QPixmap>
#include <QPushButton>

//Dialog containing information about the program.
class About : public Window
{
    Q_OBJECT

public:

    //Constructor.
    About(QObject *parent = NULL);

    //Destructor.
    ~About();

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
    virtual void connectObjects();

    //Disconnects objects from their functional and managing code sources.
    //Extends the functions of the base class implementations.
    virtual void disconnectObjects();

private:

    //View Objects:

    QLabel *lIntro,
           *lDeveloperT,
           *lDeveloper,
           *lLicenseT,
           *lLicense,
           *lGithubT,
           *lGithub,
           *lMessage,
           *lPaypalT,
           *lPaypal,
           *lDonate,
           *lInfo;

    QPixmap *pDonate,
            *pInfo;

    QPushButton *pbDonate;

public slots:

    //Opens Paypal link in browser.
    void linkPaypal();

};

#endif // ABOUT_H
