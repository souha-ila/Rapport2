#include <QApplication>
#include"exo5.h"
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
auto q= new exo5;
q->show();

    return app.exec();
}
