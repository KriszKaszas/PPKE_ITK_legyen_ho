#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QTimer>
#include <QElapsedTimer>
#include <QRandomGenerator64>
#include <iostream>
#include "snowflake.h"
#include <vector>
#include <iterator>

using namespace std;

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
    QGraphicsScene *sc;
    QTimer *timer;
    Snowflake *snowflake;
    vector<Snowflake> snowfall;
    void populateSnowfall();
    void reset();

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void advance();
    void endAnimation();

};
#endif // MAINWINDOW_H
