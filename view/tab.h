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

class Tab : public QObject
{
    Q_OBJECT

public:

    Tab(QObject *parent = NULL);
    QScrollArea* getTab();
    QGridLayout* getLayout();
    ~Tab();

protected:

    QGridLayout *glMainLayout;

    QLabel *lOutput;

    QComboBox *cbPreset;

    virtual void createObjects();
    virtual void configureObjects();
    virtual void placeObjects();
    virtual void connectObjects();

    virtual void createPreset(int index) = 0;
    virtual void removePreset(int index) = 0;

    void updateOutput(QString output);

private:

    QFrame *fView;

    QScrollArea *saView;

    QGraphicsOpacityEffect *goeFade;

    QPushButton *pbSave,
                *pbDelete;

    QGroupBox *gbPreset;

    QHBoxLayout *hblPreset;

public slots:

    void savePreset();
    void deletePreset();
    virtual void updatePreset(int index) = 0;
};

#endif // TAB_H
