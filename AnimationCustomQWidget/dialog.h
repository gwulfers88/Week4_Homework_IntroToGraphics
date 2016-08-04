#ifndef DIALOG_H
#define DIALOG_H

#include "myitem.h"
#include <QDialog>
#include <QGraphicsView>
#include <QTimer>

namespace Ui
{
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

private:
    Ui::Dialog *ui;
    QGraphicsScene *scene;
    QTimer *timer;
};

#endif // DIALOG_H
