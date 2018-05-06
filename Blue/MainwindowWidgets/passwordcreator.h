#ifndef PASSWORDCREATOR_H
#define PASSWORDCREATOR_H

#include <QWidget>
#include "Tools/zxcppvbn/zxcppvbn.hpp"
#include "Tools/diceware/diceware.h"

namespace Ui {
class PasswordCreator;
}

class PasswordCreator : public QWidget
{
    Q_OBJECT

public:
    explicit PasswordCreator(QWidget *parent = 0);
    ~PasswordCreator();

    QString returnPassword();
    void clear();

public slots:
    void evaluateSubject(QString subject);
    void switchEcho(bool isChecked);
    void switchGeneratorVisibility(bool visible);
    void uncheckAll(bool checked);

    void generatePassword();
    void generatePassphrase();

signals:
    void sizeChanged(bool expanded);

protected:
    QString generateRandomString(const QString &chars, int length);

private:
    Ui::PasswordCreator *ui;
    zxcppvbn passwordChecker;

};

#endif // PASSWORDCREATOR_H
