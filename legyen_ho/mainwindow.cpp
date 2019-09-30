#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    sc = new QGraphicsScene(0, 0, 779, 450);
    sc->setBackgroundBrush(Qt::black);
    ui->graphicsView->setScene(sc);
    populateSnowfall();
    ui->pushButton_2->setEnabled(false);
    ui->pushButton_3->setEnabled(false);
    timer = new QTimer(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    disconnect(timer, SIGNAL(timeout()), this, SLOT(endAnimation()));
    connect(timer, SIGNAL(timeout()), this, SLOT(advance()));
    timer->start(50);

    ui->pushButton->setEnabled(false);
    ui->pushButton_2->setEnabled(true);
    ui->pushButton_3->setEnabled(true);
}

void MainWindow::on_pushButton_2_clicked()
{
    disconnect(timer, SIGNAL(timeout()), this, SLOT(advance()));
    connect(timer, SIGNAL(timeout()), this, SLOT(endAnimation()));
    timer->start(50);
    ui->pushButton->setEnabled(true);
    ui->pushButton_2->setEnabled(false);
    ui->pushButton_3->setEnabled(false);
}

void MainWindow::on_pushButton_3_clicked()
{
    timer->stop();
    disconnect(timer, SIGNAL(timeout()), this, SLOT(advance()));
    disconnect(timer, SIGNAL(timeout()), this, SLOT(endAnimation()));
    reset();
    sc->clear();
    ui->pushButton->setEnabled(true);
    ui->pushButton_2->setEnabled(false);
    ui->pushButton_3->setEnabled(false);
}

void MainWindow::advance()
{
    sc->clear();
    for(vector<Snowflake>::iterator it = snowfall.begin(); it != snowfall.end(); ++it)
    {
        it->behavior();
        sc->addEllipse(it->getX(), it->getY(), it->getSize(), it->getSize(), QPen(Qt::white), QBrush(Qt::white));
        sc->update();
    }
}

void MainWindow::populateSnowfall()
{
    for(int i = 0; i < 700; i++)
    {
        int xCor = QRandomGenerator64::global()->bounded(0,779);
        int yCor = QRandomGenerator64::global()->bounded(-400, -60);
        int size = QRandomGenerator64::global()->bounded(2, 10);

        snowflake = new Snowflake(xCor, yCor, size);
        snowfall.push_back(*snowflake);
    }
}

void MainWindow::endAnimation()
{
    sc->clear();
    for(vector<Snowflake>::iterator it = snowfall.begin(); it != snowfall.end(); ++it)
    {
        it->dieDown();
        sc->addEllipse(it->getX(), it->getY(), it->getSize(), it->getSize(), QPen(Qt::white), QBrush(Qt::white));
        sc->update();
    }
}

void MainWindow::reset()
{
    sc->clear();
    for(vector<Snowflake>::iterator it = snowfall.begin(); it != snowfall.end(); ++it)
    {
        it->moveToBottom();
        sc->addEllipse(it->getX(), it->getY(), it->getSize(), it->getSize(), QPen(Qt::white), QBrush(Qt::white));
        sc->update();
    }
}
