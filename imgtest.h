#ifndef IMGTEST_H
#define IMGTEST_H

#include <QtGui/QMainWindow>
class QLabel;
class QMessageBox;
class QPushButton;
class QDialog;
class QScrollArea;
class QScrollBar;

class imgtest : public QMainWindow
{
    Q_OBJECT
    
public:
    imgtest(QWidget *parent = 0);
    ~imgtest();
private:
    QLabel *imgLabel1;
    QLabel *imgLabel2;
    QPushButton *openBtn;
    QPushButton *closeBtn;
    QScrollArea *scrollArea;
    QScrollBar *scrollBar;

    void imgForm();
    void szWids();
    void connectSl();

    QString openImg;
    //QString saveImg;

private slots:

    void openSl();
    //void saveSl();
};

#endif // IMGTEST_H
