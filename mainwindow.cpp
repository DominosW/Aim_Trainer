#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QTimer>
#include <QDebug>
#include <QRandomGenerator>
#include <QtCore>
#include <QBrush>
#include <QPixmap>
#include <QMessageBox>

#include "reakcja.h"
#include "punkt.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);

    QGraphicsScene *scene = new QGraphicsScene();
    QPixmap m(":/tlo.png");

    scene->setBackgroundBrush(m.scaled(220,200,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));
    ui->graphicsView->setScene(scene);

    time = 0;
    timerr = new QTimer(this);
    connect(timerr, SIGNAL(timeout()), this, SLOT(onTimerTimeout()));
    timerr->start(1);

    punkt = new Punkt();
    punkt->setScale(0.2);

    scene->addItem(punkt);

    timer = new QTimer(this);
    timer->setInterval(1000);
    timer->start();

    wyswietlone=0;
    trafione=0;

    connect(timer, SIGNAL(timeout()), this, SLOT(zmienPolozenie()));
    connect(punkt, SIGNAL(mousePressSignal()), this, SLOT(zmienTrafione()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::zmienPolozenie()
{
    int x = QRandomGenerator::global()->bounded(700) - 350;
    int y = QRandomGenerator::global()->bounded(500) - 200;
    punkt->setPos(x,y);

    ui->wyswietlone->setText(QString::number(++wyswietlone));
}

void MainWindow::zmienTrafione()
{
    ui->trafione->setText(QString::number(++trafione));
}

void MainWindow::onTimerTimeout()
{
    time++;
    ui->Label10->setText(QDateTime::fromMSecsSinceEpoch(time, Qt::UTC).toString("mm:ss"));
}

void MainWindow::on_actionZakoncz_triggered()
{
    QMessageBox::StandardButton answer;
    answer = QMessageBox::warning(this, "Ostrzezenie", "Czy na pewno chcesz zamknąć?", QMessageBox::Yes | QMessageBox::No , QMessageBox::No);
    if(answer == QMessageBox::Yes)
        QApplication::exit();
}

void MainWindow::on_pushButton_clicked()
{
    ui->trafione->clear();
    trafione=0;
    ui->trafione->setText("0");
}

void MainWindow::on_pushButton_2_clicked()
{
    time = 0;
    timerr->start(1);
}

void MainWindow::on_pushButton_3_clicked()
{
    ui->trafione->clear();
    trafione=0;
    ui->trafione->setText("0");

    time = 0;
    timerr->start(1);

    wyswietlone=0;
    ui->wyswietlone->setText("0");
}
