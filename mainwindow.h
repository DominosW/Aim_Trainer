#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QTimer>

#include "reakcja.h"
#include "punkt.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    Reakcja *reakcja;
    Punkt *punkt;

    QTimer *timer;
    QTimer *timerr;
    qint64 time;

    int wyswietlone;
    int trafione;

private slots:
    void zmienPolozenie();
    void zmienTrafione();
    void onTimerTimeout();

    void on_actionZakoncz_triggered();
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
};
#endif // MAINWINDOW_H
