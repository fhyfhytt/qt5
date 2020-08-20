//#include <QApplication>
//#include <QWidget>
//#include <QSpinBox>
//#include <QSlider>
//#include <QHBoxLayout>
///*研究学习qt5*/
//int main(int argc, char *argv[])
//{
//    QApplication app(argc, argv);
//    QWidget *window = new QWidget;
//    window->setWindowTitle("Enter your age");
//    QSpinBox *spinBox = new QSpinBox; //信号槽上下控件
//    QSlider *slider = new QSlider(Qt::Horizontal);
//    spinBox->setRange(0, 130);
//    slider->setRange(0, 130);
//    QObject::connect(slider, SIGNAL(valueChanged(int)), spinBox, SLOT(setValue(int)));//信号槽
//    QObject::connect(spinBox, SIGNAL(valueChanged(int)), slider, SLOT(setValue(int)));
//    spinBox->setValue(35);
//    QHBoxLayout *layout = new QHBoxLayout;
//    layout->addWidget(spinBox);
//    layout->addWidget(slider);
//    window->setLayout(layout);
//    //HBoxLayout- 按照水平方向从左到右布局；
//    //QVBoxLayout- 按照竖直方向从上到下布局；
//    //QGridLayout- 在一个网格中进行布局，类似于 HTML 的 table。
//    window->show();
//    return app.exec();
//}
/*引入弹窗*/
//#include <QApplication>
//#include "finddialog.h"
//
//int main(int argc, char *argv[])
//{
//    QApplication app(argc, argv);
//    FindDialog *dialog = new FindDialog;
//    dialog->show();
//    return app.exec();
//}


//引入MyMainWindow
#include <QApplication>
#include "MyMainWindow.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    MyMainWindow w;
    w.setWindowTitle("MyMainWindow");
    w.show();

    app.exec();
}