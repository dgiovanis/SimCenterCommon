#ifndef SURROGATE_DOE_INPUT_WIDGET_H
#define SURROGATE_DOE_INPUT_WIDGET_H

/* *****************************************************************************
Copyright (c) 2016-2017, The Regents of the University of California (Regents).
All rights reserved.

Redistribution and use in source and binary forms, with or without 
modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright notice, this
   list of conditions and the following disclaimer.
2. Redistributions in binary form must reproduce the above copyright notice,
   this list of conditions and the following disclaimer in the documentation
   and/or other materials provided with the distribution.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR
ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

The views and conclusions contained in the software and documentation are those
of the authors and should not be interpreted as representing official policies,
either expressed or implied, of the FreeBSD Project.

REGENTS SPECIFICALLY DISCLAIMS ANY WARRANTIES, INCLUDING, BUT NOT LIMITED TO, 
THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
THE SOFTWARE AND ACCOMPANYING DOCUMENTATION, IF ANY, PROVIDED HEREUNDER IS 
PROVIDED "AS IS". REGENTS HAS NO OBLIGATION TO PROVIDE MAINTENANCE, SUPPORT, 
UPDATES, ENHANCEMENTS, OR MODIFICATIONS.

*************************************************************************** */

// Written: fmckenna

#include <UQ_Method.h>
class QLineEdit;
class QComboBox;
class QCheckBox;
class QLabel;
class QPushButton;
class QFrame;
class QRadioButton;

class SurrogateDoEInputWidget : public UQ_Method
{
    Q_OBJECT
public:
    explicit SurrogateDoEInputWidget(QWidget *parent = 0);
    ~SurrogateDoEInputWidget();

    bool outputToJSON(QJsonObject &rvObject);
    bool inputFromJSON(QJsonObject &rvObject);
    bool copyFiles(QString &fileDir);
    void clear(void);

    int getNumberTasks(void);
    void setRV_Defaults(void);


private:


    void createLineEdits(QLineEdit *&a, QString defaultVal, QString type, QString toolTipText, double wid, QString placeholderText="");
    void createComboBox(QComboBox *&a, QStringList items, QString toolTipText, double wid, int curIdx);

    QWidget *theGpAdvancedWidgetGroup;
    QWidget *theExistingWidgetGroup;
    QLineEdit *randomSeed;
    QLineEdit *numSamples;
    QLineEdit *accuracyMeasure;
    QLineEdit *timeMeasure;
    QLineEdit *numSampToBeRepl, *numRepl;
    QCheckBox *parallelCheckBox;
    QComboBox *gpKernel;
    QCheckBox *theLinearCheckBox;
    QCheckBox *theGpAdvancedCheckBox;
    QCheckBox *theExistingCheckBox;
    QCheckBox *theLogtCheckBox;

    QLabel * theAdvancedTitle;
    QLabel * theExistingTitle;
    QLabel * errMSG;
    QLabel * theNuggetMsg;
    QLabel * theNuggetLabel;
    QLabel * repLabelA, *repLabelB;
    QComboBox * theNuggetSelection;
    QLineEdit * theNuggetVals;
    QLabel * theDoEMsg;
    QLabel * theDoELabel;
    QComboBox * theDoESelection;
    QLineEdit *initialDoE;

    QPushButton *chooseOutFile;
    QPushButton *chooseInpFile;

    QLineEdit * inpFileDir;
    QLineEdit * outFileDir;
    QLabel * repMsg;
    int numSims;

private slots:
    void doAdvancedGP(bool tog);
    void doExistingGP(bool tog);
    void checkValidityData(QString name1);
    void showNuggetBox(int idx);
    void showDoEBox(int idx);
    void updateSimNumber(QString tte);

};

#endif // SURROGATE_DOE_INPUT_WIDGET_H
