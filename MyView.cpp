#include "MyView.h"
#include<QPixmap>
#include<QPainter>

MyView::MyView(QWidget *parent) : QWidget(parent) {

}

void MyView::paintEvent(QPaintEvent *) {
    QPainter painter(this);
    painter.drawPixmap(QPoint(0, 0), QPixmap("../pic.jpg"));
}