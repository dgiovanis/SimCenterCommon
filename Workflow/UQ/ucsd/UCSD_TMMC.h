#ifndef UCSD_TMMC_H
#define UCSD_TMMC_H

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
class QGroupBox;
class QCheckBox;
class QLabel;
class QFrame;

class UCSD_TMMC : public UQ_Method
{
    Q_OBJECT
public:
    explicit UCSD_TMMC(QWidget *parent = 0);
    virtual ~UCSD_TMMC();

    bool outputToJSON(QJsonObject &rvObject);
    bool inputFromJSON(QJsonObject &rvObject);
    void clear(void);

    int getNumberTasks(void);

    bool copyFiles(QString &fileDir);
  
    int getNumExp(QString &calFileName);

    int numExperiments;

    void advancedOptionsSlotFunction(bool tog);

    int requiredSampleSize = 100;
    int recommendedSampleSize = 200;

    bool checkSampleSize(int sampleSize);

private:
  QLineEdit *numParticles;
  QLineEdit *logLikelihoodScript;
  QLineEdit *randomSeed;
  QLineEdit *calDataFileEdit;
  QGroupBox *requiredInputsGroupBox;
  QGroupBox *optionalInputsGroupBox;
  QCheckBox *readCovarianceDataCheckBox;
  QCheckBox *advancedOptionsCheckBox;
  QLabel *advancedOptionsTitle;
  QFrame *lineA;
  QLineEdit *numMCMCStepsMinimum;
  QLineEdit *numMCMCStepsMaximum;
  QLabel *numSamplesError;
  QLabel *numSamplesWarning;
  QLineEdit *maxRunTime;
};

#endif // UCSD_TMMC_H
