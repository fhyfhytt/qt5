#include "MyMainWindow.h"
#include<QApplication>
#include<QMenu>     //菜单类
#include<QMenuBar>  //菜单栏, MainWindow里边独有的
#include<QAction>   //每一个菜单项，快捷键也可以用
#include<QFileDialog>
#include<QFileInfo>
#include<qDebug>
#include<QToolBar>   //增加工具栏按钮
#include<QStatusBar>    //状态栏
#include<QLabel>
#include<QMouseEvent>
#include<QCursor>       //调整鼠标的位置为窗口的相对位置


MyMainWindow::MyMainWindow(QWidget *parent) : QMainWindow(parent) {
    //加菜单
    QMenuBar *pMenuBar = menuBar();
    QMenu *pmenu = pMenuBar->addMenu("File");   //增加一个File菜单
    _menu = pmenu;
    //为File菜单增加一个选项,名字open，添加到this窗口，调用一个槽函数，快捷键为Ctrl+O（window系统下）
    QAction *openAction = pmenu->addAction("&Open", this, SLOT(slotOpen()), QKeySequence::Open);
    pmenu->addSeparator();      //增加一条线
    QAction *closeAction = pmenu->addAction("&close", this, SLOT(close()), QKeySequence::Close);
    //设置消息提示
    closeAction->setToolTip("close window");


    //增加工具栏,工具栏和菜单栏实质差不多，只不过其表现方式有些不同，而且toolBar是可以浮动的
    QToolBar *toolBar = this->addToolBar("My Tool Bar...");
    toolBar->addAction(openAction);
    toolBar->addAction(closeAction);

    //status bar， 状态栏，显示在窗口的最下方
    QStatusBar *pstatusBar = this->statusBar();
    pstatusBar->addWidget(
            new QLabel("<font color= red  size = 16 style=font-style:italic style=font-weight:bold>Apple Lin</font>"));

    //别的空间占用了之后，剩下的区域都是centralWidget，也就是说，窗口中可操作的区间在MyView里边即可,别忘了this，将该view添加到该窗口中
    _view = new MyView;
    this->setCentralWidget(_view);


    //托盘,相当于在打开该应用程序的时候再桌面上有一个图标
    _icon = new QSystemTrayIcon;
    _icon->setIcon((QIcon("../icon.ico")));
    _icon->setToolTip("This is icon test");
    _icon->show();
    //将鼠标知道图标的位置会提示消息
    _icon->setContextMenu(_menu);

    //触发图标按钮
    connect(_icon, SIGNAL(activated(QSystemTrayIcon::ActivationReason)),
            this, SLOT(slotActivated(QSystemTrayIcon::ActivationReason)));


}

void MyMainWindow::slotActivated(QSystemTrayIcon::ActivationReason reason) {
    if (reason == QSystemTrayIcon::Trigger) {
        if (this->isHidden()) this->show();
        else this->hide();
    }
}

void MyMainWindow::mousePressEvent(QMouseEvent *ev) {
//此时鼠标跳出的位置是相对于电脑桌面的位置，而不是现对于窗口的位置
//    _menu->exec(ev->pos());
    if (ev->button() == Qt::RightButton)
        _menu->exec(QCursor::pos());
}

void MyMainWindow::slotOpen() {
    QString _dirFile;
    QString filename = QFileDialog::getOpenFileName(this, "Open", _dirFile, "File (*.doc *.pdf)");
    if (filename != "")
        qDebug() << filename;

    QFileInfo fileinfo(filename);
    _dirFile = fileinfo.filePath();

}

