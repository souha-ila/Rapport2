#include <QApplication>
#include "dialogue.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
   dialogue *dialog=new dialogue;
     dialog->show();
    return a.exec();
}

