#include "mainwindow.h"
#include <QMainWindow>
#include <QFormLayout>
#include <QLabel>
#include <QLineEdit>
#include <QApplication>
#include <QVBoxLayout>
#include <QPushButton>

#include <QApplication>
int main(int argc, char* argv[])
{
  QApplication app(argc, argv);

  QWidget* window = new QWidget();
  window->setWindowTitle("QHBoxLayout Test");
   QLineEdit *Name = new QLineEdit;
   QFormLayout *formLayout = new QFormLayout;
      formLayout->addRow(" &Name", Name);
 QHBoxLayout *layoutt = new QHBoxLayout;
 layoutt->addLayout(formLayout);// Ajout du layout de formulaire
 QPushButton *bouton = new QPushButton("Search");  // Ajout du bouton
layoutt->addWidget(bouton);

 window->setLayout(layoutt);
  window->show();

  return app.exec();

}
