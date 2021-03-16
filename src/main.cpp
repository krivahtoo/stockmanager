#include "stock_manager.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    stock_manager w;
    w.show();

    return app.exec();
}

