
#ifndef QT5_FINDDIALOG_H
#define QT5_FINDDIALOG_H

#include <QDialog>

class QAction;

class QCheckBox;

class QLabel;

class QLineEdit;

class QPushButton;

class FindDialog : public QDialog {
Q_OBJECT
public:
    FindDialog(QWidget *parent = 0);

    ~FindDialog();

signals:

    void findNext(const QString &str, Qt::CaseSensitivity cs);

    void findPrevious(const QString &str, Qt::CaseSensitivity cs);

private slots:

    void findClicked();

    void enableFindButton(const QString &text);

private:
    QAction *openAction;
    QLabel *label;
    QLineEdit *lineEdit;
    QCheckBox *caseCheckBox;
    QCheckBox *backwardCheckBox;
    QPushButton *findButton;
    QPushButton *closeButton;
};

#endif //QT5_FINDDIALOG_H
