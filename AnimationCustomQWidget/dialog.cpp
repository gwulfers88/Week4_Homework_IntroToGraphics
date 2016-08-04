#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    scene = new QGraphicsScene(this);
    ui->scene->setScene(scene);

    //anti aliasing
    ui->scene->setRenderHint(QPainter::Antialiasing);

    scene->setSceneRect(-150, -150, 300, 300);

    QLineF topLine (scene->sceneRect().topLeft(),
                    scene->sceneRect().topRight());
    QLineF leftLine (scene->sceneRect().topLeft(),
                     scene->sceneRect().bottomLeft());
    QLineF rightLine (scene->sceneRect().topRight(),
                      scene->sceneRect().bottomRight());
    QLineF bottomLine (scene->sceneRect().bottomLeft(),
                       scene->sceneRect().bottomRight());

    QPen mypen = QPen(Qt::red);

    scene->addLine(topLine, mypen);
    scene->addLine(leftLine, mypen);
    scene->addLine(rightLine, mypen);
    scene->addLine(bottomLine, mypen);

    scene->addItem(new MyItem);
    scene->addItem(new MyItem);
    scene->addItem(new MyItem);
    scene->addItem(new MyItem);

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()),
            scene, SLOT(advance()));
    timer->start(100);
}

Dialog::~Dialog()
{
    delete ui;
}
