#include "bluedialog.h"
#include "ui_bluedialog.h"

BlueDialog::BlueDialog(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BlueDialog)
{
    ui->setupUi(this);

    //Disable top bar with close/reduce buttons
    setWindowFlag(Qt::FramelessWindowHint);

    QObject::connect(ui->close, SIGNAL(clicked(bool)), this, SLOT(close()));
    QObject::connect(ui->ok, SIGNAL(clicked(bool)), this, SLOT(close()));

    QObject::connect(ui->close, SIGNAL(clicked(bool)), this, SIGNAL(closeClicked()));
    QObject::connect(ui->ok, SIGNAL(clicked(bool)), this, SIGNAL(okClicked()));
}

//Set the QLabel title
void BlueDialog::setTitle(const QString &text)
{
    ui->label->setText(text);
}

//Set the QPlainText message
void BlueDialog::setMessage(const QString &text)
{
    ui->plainTextEdit->setPlainText(text);
}

BlueDialog::~BlueDialog()
{
    delete ui;
}
