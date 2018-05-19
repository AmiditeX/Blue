#ifndef CONTAINERCREATOR_H
#define CONTAINERCREATOR_H

#include <QWidget>
#include <QDialog>
#include <QColorDialog>

namespace Ui {
class ContainerCreator;
}

class ContainerCreator : public QDialog
{
    Q_OBJECT

    struct ReturnObject
    {
        QString name, colorBackground, colorText;
    };

public:
    explicit ContainerCreator(QWidget *parent = 0);
    ReturnObject returnParams();
    void clear();
    void setModify();

    void setTitle(const QString &title);
    void setColor(const QString &color);
    void setTitleColor(const QString &color);

    ~ContainerCreator();

public slots:
    void processEdit();

    void slotColorBackground(QColor color);
    void slotColorText(QColor color);

signals:
    void okPressed();

private:
    Ui::ContainerCreator *ui;
    QString _selectedColor = "background-color: rgb(59, 118, 239);";
    QString _selectedColorText = "color: rgb(255, 255, 255);";

    bool modify = false;

    QColorDialog *backDiag = nullptr;
    QColorDialog *textDiag = nullptr;
};

#endif // CONTAINERCREATOR_H
