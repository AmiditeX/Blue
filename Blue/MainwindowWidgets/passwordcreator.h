#ifndef PASSWORDCREATOR_H
#define PASSWORDCREATOR_H
#include "Tools/zxcppvbn/zxcppvbn.hpp"

#include <QWidget>

namespace Ui {
class PasswordCreator;
}

class PasswordCreator : public QWidget
{
    Q_OBJECT

public:
    explicit PasswordCreator(QWidget *parent = 0);
    ~PasswordCreator();

public slots:
    void evaluateSubject(QString subject);
    void switchEcho(bool isChecked);

private:
    Ui::PasswordCreator *ui;
    zxcppvbn passwordChecker;

};

#endif // PASSWORDCREATOR_H