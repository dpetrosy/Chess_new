#include <QApplication>
#include <QDebug>

#include "mainwindow.hpp"

int main(int argc, char *argv[])
{
    QString logoImagePath = ":/images/logos/logo.png";

    QApplication app(argc, argv);
    app.setWindowIcon(QIcon(logoImagePath));

    MainWindow* w = MainWindow::GetInstance();
    w->setWindowIcon(QIcon(logoImagePath));
    w->show();

    auto retValue = app.exec();

    delete w;

    return retValue;
}
