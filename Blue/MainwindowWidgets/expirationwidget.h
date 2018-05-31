#ifndef EXPIRATIONWIDGET_H
#define EXPIRATIONWIDGET_H

#include <QWidget>
#include <QTimer>
#include <QDateTime>

namespace Ui {
class ExpirationWidget;
}

class ExpirationWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ExpirationWidget(QWidget *parent = 0);
    ~ExpirationWidget();

    void setExpiration(const QDateTime &d);
    QDateTime getExpiration();

    void setEnabled(bool enable);

    void checkExpiration();
    bool isExpired();
    bool isExpirable();

signals:
    void stateChanged();
    void expired();
    
private:
    Ui::ExpirationWidget *ui;
    QDateTime _expiration;
    bool _isEnabled = false;
    bool _isExpired = false;
    QTimer *autoCheck = nullptr;
};

#endif // EXPIRATIONWIDGET_H
