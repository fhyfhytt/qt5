#ifndef MYMAINWINDOW_H
#define MYMAINWINDOW_H

#include <QMainWindow>
//为了让系统告诉你剩下可操作的空间在哪里？
#include "MyView.h"
#include<QSystemTrayIcon>   //系统托盘图标


//QMainWindow继承自QWidget

class MyMainWindow : public QMainWindow {
Q_OBJECT
public:
    explicit MyMainWindow(QWidget *parent = 0);

    MyView *_view;
    QMenu *_menu;
    QSystemTrayIcon *_icon;      //托盘

    void mousePressEvent(QMouseEvent *);

signals:

public slots:

    void slotOpen();

    void slotActivated(QSystemTrayIcon::ActivationReason);
};

#endif // MYMAINWINDOW_H