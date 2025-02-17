#ifndef PYTHONPROGRESSDIALOG_H
#define PYTHONPROGRESSDIALOG_H

#include <QDialog>
#include <QMutex>

class QPlainTextEdit;
class QProgressBar;

class PythonProgressDialog : public QDialog
{
    Q_OBJECT

private:
    explicit PythonProgressDialog(QWidget* parent =0);
    ~PythonProgressDialog();
    static PythonProgressDialog *theInstance;  
  
public:
    static PythonProgressDialog *getInstance(QWidget *parent = 0);  

    void appendText(const QString text);

    void appendInfoMessage(const QString text);

    void appendErrorMessage(const QString text);

    void setVisibility(bool visible);

    void setProgressBarValue(const int val);
    void setProgressBarRange(const int start,const int end);

    void hideAfterElapsedTime(int sec);

    QProgressBar *getProgressBar() const;

public slots:
    void showProgressBar(void);
    void hideProgressBar(void);
    void handleCloseButtonPress();
    void handleClearButtonPress();
    void clear(void);

signals:
    void showDialog(bool);

private:

    QPlainTextEdit* progressTextEdit;

    QString cleanUpText(const QString text);

    QProgressBar* progressBar;

    QMutex* mutex;

    QString getTimestamp(void);

};

#endif // PYTHONPROGRESSDIALOG_H
