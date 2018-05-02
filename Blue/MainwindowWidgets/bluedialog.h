#ifndef BLUEDIALOG_H
#define BLUEDIALOG_H

#include <QWidget>
#include <QDialog>
#include <QMouseEvent>

namespace Ui {
class BlueDialog;
}

class BlueDialog : public QDialog
{
    Q_OBJECT

public:
    explicit BlueDialog(QWidget *parent = 0);
    ~BlueDialog();

public slots:
    void setTitle(const QString &text);
    void setMessage(const QString &text);

signals:
    void okClicked();
    void closeClicked();

protected:
       void mousePressEvent(QMouseEvent *evt)
       {
           oldPos = evt->globalPos();
       }

       void mouseMoveEvent(QMouseEvent *evt)
       {
           const QPoint delta = evt->globalPos() - oldPos;
           move(x()+delta.x(), y()+delta.y());
           oldPos = evt->globalPos();
       }

private:
    Ui::BlueDialog *ui;
    QPoint oldPos;
};

#endif // BLUEDIALOG_H
