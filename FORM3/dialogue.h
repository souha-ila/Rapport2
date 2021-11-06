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
