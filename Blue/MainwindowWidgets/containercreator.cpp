#include "containercreator.h"
#include "ui_containercreator.h"
#include <QDebug>

ContainerCreator::ContainerCreator(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ContainerCreator)
{
    ui->setupUi(this);

    //Disable top bar with close/reduce buttons
    setWindowFlag(Qt::FramelessWindowHint);

    QObject::connect(ui->close, SIGNAL(clicked(bool)), this, SLOT(hide()));
    QObject::connect(ui->ok, SIGNAL(clicked(bool)), this, SLOT(processEdit()));

    backDiag = new QColorDialog(this);
    connect(ui->colorSelector, &QPushButton::clicked, [=](){
        backDiag->open(this, SLOT(slotColorBackground(QColor)));
    });

    textDiag = new QColorDialog(this);
    connect(ui->colorSelectorText, &QPushButton::clicked, [=](){
        textDiag->open(this, SLOT(slotColorText(QColor)));
    });
}

ContainerCreator::ReturnObject ContainerCreator::returnParams()
{
    return ReturnObject{ui->containerTitle->text(), _selectedColor, _selectedColorText};
}

void ContainerCreator::clear()
{
    if(modify)
        return;

    ui->containerTitle->clear();
    _selectedColor = "background-color: rgb(59, 118, 239);";
    _selectedColorText = "color: rgb(255, 255, 255);";
    ui->colorLabel2->setStyleSheet(_selectedColor + " " + QString(_selectedColorText).replace("color", "background-color"));
}

void ContainerCreator::processEdit()
{
    emit okPressed();
}

void ContainerCreator::setModify()
{
    ui->ok->setText(tr("Modify"));
    modify = true;
}

void ContainerCreator::setTitle(const QString &title)
{
    ui->containerTitle->setText(title);
}

void ContainerCreator::setColor(const QString &color)
{
    ui->colorLabel->setStyleSheet(color);
    _selectedColor = QString(color).remove(0, 1) + ";";
}

void ContainerCreator::setTitleColor(const QString &color)
{
    ui->colorLabel2->setStyleSheet(QString(color).replace("color", "background-color"));
    _selectedColorText = QString(color).remove(0, 1) + ";";
}

void ContainerCreator::slotColorBackground(QColor color)
{
    QString style = "background-color: rgb(%1, %2, %3);";
    QString colors = style.arg(color.red()).arg(color.green()).arg(color.blue());
    ui->colorLabel->setStyleSheet(colors);
    _selectedColor = colors;
}

void ContainerCreator::slotColorText(QColor color)
{
    QString style = "color: rgb(%1, %2, %3);";
    QString colors = style.arg(color.red()).arg(color.green()).arg(color.blue());
    _selectedColorText = colors;
    ui->colorLabel2->setStyleSheet(colors.replace("color", "background-color"));
}

ContainerCreator::~ContainerCreator()
{
    delete ui;
}
