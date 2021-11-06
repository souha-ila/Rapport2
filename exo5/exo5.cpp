#include "exo5.h"

exo5::exo5(QWidget *parent) : QWidget(parent)
{
createwidgets();
placewidgets();
Connexionwidgets();
}
void exo5::createwidgets(){
    b1= new QPushButton("7");
    b2= new QPushButton("8");
    b3= new QPushButton("9");
    b4= new QPushButton("4");
    b5= new QPushButton("5");
    b6= new QPushButton("6");
    b7= new QPushButton("1");
     b8= new QPushButton("2");
      b9= new QPushButton("3");
       b10= new QPushButton("0");
       b11= new QPushButton("Enter");
    grid = new QGridLayout;
    //window= new QWidget;
    number =new QLCDNumber;
   layout=new QVBoxLayout;
    setLayout(layout);
}
void exo5::placewidgets(){
number->setMinimumHeight(80);
    grid->addWidget(b1,0,0,1,1);
    grid->addWidget(b2,0,1,1,1);
        grid->addWidget(b3,0,2,1,1);
layout->addWidget(number);
        // 1st row
        grid->addWidget(b4,1,0,1,1);
        grid->addWidget(b5,1,1,1,1);
        grid->addWidget(b6,1,2,1,1);

        grid->addWidget(b7,2,0,1,1);
        grid->addWidget(b8,2,1,1,1);
        grid->addWidget(b9,2,2,1,1);
        grid->addWidget(b10,3,0,1,1);
        grid->addWidget(b11,3,1,1,2);

layout->addLayout(grid);
 setWindowTitle(tr("Numeric Keypad"));

}
void exo5::Connexionwidgets(){

}
