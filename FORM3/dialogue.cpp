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

