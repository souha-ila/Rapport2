#ifndef EXO5_H
#define EXO5_H

#include <QWidget>
#include<QVBoxLayout>
#include<QPushButton>
#include<QGridLayout>
#include<QLCDNumber>
class exo5 : public QWidget
{
    Q_OBJECT
public:
    explicit exo5(QWidget *parent = nullptr);

protected:
    void createwidgets();
    void placewidgets();
    void Connexionwidgets();

QPushButton *b1;
QPushButton *b2;
QPushButton *b3;
QPushButton *b4;
QPushButton *b5;
QPushButton *b6;
QPushButton *b7;
QPushButton *b9;
QPushButton *b8;
QPushButton *b10;
QPushButton *b11;
QGridLayout *grid;
//QWidget *window;
QLCDNumber *number;
QVBoxLayout *layout;

};

#endif // EXO5_H
