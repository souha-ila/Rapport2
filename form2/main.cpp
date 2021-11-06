#include "mainwindow.h"
#include <QMainWindow>
#include <QFormLayout>
#include <QLabel>
#include <QLineEdit>
#include <QApplication>
#include <QVBoxLayout>
#include <QPushButton>
#include <QCheckBox>


int main(int argc, char* argv[])
{
  QApplication app(argc, argv);

 QWidget* window = new QWidget();
  //FORM 2
 window->setWindowTitle("Nested Layout Test");
 // le champ de texte
 QLineEdit *Name = new QLineEdit;
 QFormLayout *formLayout = new QFormLayout;
 formLayout->addRow(" &Name", Name);
 //les CheckBoxs
 QCheckBox *butt1 = new QCheckBox("Match case");
  QCheckBox *butt2 = new QCheckBox("Search backward");
  //creation de leftlayout
 QVBoxLayout *layoutleft = new QVBoxLayout;
//ajouter form et widgets
 layoutleft->addLayout(formLayout);
 layoutleft->addWidget(butt1);
 layoutleft->addWidget(butt2);
 // creer le 2 eme Layout
  QVBoxLayout *layoutright = new QVBoxLayout;
  QPushButton *bouton1 = new QPushButton("Search");
  QPushButton *bouton2 = new QPushButton("Close");
 layoutright->addWidget(bouton1);
layoutright->addWidget(bouton2);
QSpacerItem *addSpacer =new QSpacerItem(1,1);
layoutright->addStretch(0);
layoutright->addSpacerItem(addSpacer);
//creer MainLayout
 QHBoxLayout *layoutMain = new QHBoxLayout;
 layoutMain->addLayout(layoutleft);
 layoutMain->addLayout(layoutright);
 window->setLayout(layoutMain);
 window->show();

  return app.exec();

}
