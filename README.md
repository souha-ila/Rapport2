![logo](https://ueuromed.org/sites/default/files/2020-02/eidia.png)
# **RAPPORT DE TP: [FUN WITH LAYOUTS](https://anassbelcaid.github.io/CS311/forms/)**
## OBJECTIFS DE TP:
<ul>
  <li>Utilisez les connaissances acquises pour créer des formulaires.</li>
  <li>S'amuser avec layout</li>
</ul>


## INTRODUCTION: 
<p> Le moyen le plus simple de donner à vos widgets une bonne mise en page est d'utiliser
     les gestionnaires de Layout intégrés :</p>
<ul>
  <li>QHBoxLayout</li>
  <li>QVBoxLayout</li>
 <li>QGridLayout </li>
 <li>QFormLayout</li>
</ul>

<p> Ces classes héritent de QLayout,  qui à son tour dérive de QObject .
     Ils s'occupent de la gestion de la géométrie d'un ensemble de widgets, Pour créer des mises en page plus complexes, et bien sure vous pouvez imbriquer les gestionnaires de mise en page les uns dans les autres.</p>


##  Experimenting with [QHBOXLayout](https://doc.qt.io/qt-5/qhboxlayout.html)

 le but de cet exercice est atteindre le  ~~**resultat**~~  suivant:


![RESULTAT](https://raw.githubusercontent.com/souha-ila/test2/master/forme1.PNG)
<p>Pour montrer ce résultat  , nous avons écrit le code suivant dans Main :</p>

```cpp

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
```
 
## [NESTED LAYOUTS](https://doc.qt.io/qt-5/qtwidgets-tutorials-widgets-nestedlayouts-example.html)

 Le but de l'exercice 2 est d'apprendre à analyser la construction d'un formulaire puis de le coder 
donc nous avons besoin de realiser la forme de dialoge suivant :
![ Form2](https://raw.githubusercontent.com/souha-ila/test2/master/dialog.PNG)

Le code pour atteindre ce but est :

```cpp

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
```
=> ~~**LE RESULTAT**~~ :
![resultat](https://raw.githubusercontent.com/souha-ila/test2/master/Form2.PNG)

## [BUG REPORT FORM ](https://doc.qt.io/archives/qq/qq25-formlayout.html)
Notre tâche consiste à créer un formulaire  pour signaler le problème qui ce présente dans l'exercice.
      Voici la définition de la classe  dialogue:

```cpp

#ifndef DIALOGUE_H
#define DIALOGUE_H
#include<QDialog>
#include<QLineEdit>
#include<QCheckBox>
#include<QTextEdit>
#include<QFormLayout>
#include<QComboBox>
#include<QDialogButtonBox>


 class dialogue:
 public QDialog{
 public:
 dialogue(QWidget *parent = 0);
 private:
     QLineEdit*Name;
    QLineEdit *companyEdit;
      QLineEdit *phoneEdit;
     QLineEdit *emailEdit;
     QLineEdit *problemEdit;
     QTextEdit *summaryEdit;
     QComboBox * ComboBox;
     QFormLayout*layout;
             QDialogButtonBox *buttonBox;

 };



#endif // DIALOGUE_H

```
 
et ici le code qui existe dans **dialoge.cpp**


```cpp

#include "dialogue.h"
#include<QVBoxLayout>

dialogue::dialogue(QWidget *parent)
    : QDialog(parent)
 {
    Name = new QLineEdit;
    companyEdit = new QLineEdit;
    phoneEdit = new QLineEdit;
     emailEdit = new QLineEdit;
     problemEdit = new QLineEdit;
     summaryEdit = new QTextEdit;

     ComboBox = new QComboBox;
     ComboBox->addItem("Always");
       ComboBox->addItem("Sometimes");
      ComboBox->addItem("Rarely");

      buttonBox = new QDialogButtonBox;
       buttonBox->addButton(tr("Submit Bug Report"),
                                 QDialogButtonBox::AcceptRole);
        buttonBox->addButton(tr("Don't Submit"),
                                 QDialogButtonBox::RejectRole);
      buttonBox->addButton(QDialogButtonBox::Reset);
      QFormLayout *layout = new QFormLayout;
      layout->addRow("Name:", Name);
     layout->addRow("Company:", companyEdit);
     layout->addRow("Phone:", phoneEdit);
    layout->addRow("Email:", emailEdit);
   layout->addRow("Problem &Title:", problemEdit);
    layout->addRow("Summary Information:",
                                 summaryEdit);
                  layout->addRow("Reproducibility:",
                                 ComboBox);

                  QVBoxLayout *mainLayout = new QVBoxLayout;
                  mainLayout->addLayout(layout);
                  mainLayout->addWidget(buttonBox);
                  setLayout(mainLayout);

                  setWindowTitle(tr("Report Bug"));


  }


```
Et pour montrer le résultat, nous avons écrit dans la classe  **Main** le code suivant :
```cpp
#include <QApplication>
#include "dialogue.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
   dialogue *dialog=new dialogue;
     dialog->show();
    return a.exec();
}
```
Et voila ~~**le fruit**~~   de ce code:
![Form3](https://raw.githubusercontent.com/souha-ila/test2/master/forme3.PNG)


##  [GRID LAYOUT](https://doc.qt.io/qt-5/qgridlayout.html)

Pour notre dernier exercice, nous essayons de construire une calculatrice .
  Le code pour realiser cela est le suivant:
 Pour **exo5.h** :
```cpp
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
```
Pour **exo5.cpp**
```cpp
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
```
Pour le **main**
```cpp
#include <QApplication>
#include"exo5.h"
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
auto q= new exo5;
q->show();

    return app.exec();
}
```
   
   Si on compile le projet ,Voila le **RESULTAT** :  
     
 ![exo5](https://raw.githubusercontent.com/souha-ila/Rapport2/master/exo5/Capture.PNG)
 
 
 ## CONCLUSION:
 
  Pour conclure on peut dire que Qt fournit les mécanismes fondamentaux nécessaires au développement de puissantes applications multiplateformes.
 Ce que nous voyons maintenant dans notre rapport, c'est qu'il s'étend également progressivement pour fournir des API de niveau supérieur qui encapsulent des idiomes spécifiques à la plate-forme.
 
 
 
 
 
 
 
 ## > Realisé par: OUNAR Souhaila / SAIBARI Chaima


    
