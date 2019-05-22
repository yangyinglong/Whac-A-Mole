#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->score = 0;
    this->myScene = new MyScene;
    this->ui->gv_main->setScene(myScene);
    connect(this->ui->btn_start, SIGNAL(clicked(bool)), this, SLOT(startGame()));
    connect(this->ui->btn_pause, SIGNAL(clicked(bool)), this, SLOT(pauseGame()));
    connect(this->ui->btn_stop, SIGNAL(clicked(bool)), this, SLOT(stopGame()));
    Handler * handler = Handler::getInstance();
    connect(handler, SIGNAL(beatMole()), this, SLOT(updateScore()));

    this->ui->btn_start->setEnabled(true);
    this->ui->btn_pause->setEnabled(false);
    this->ui->btn_stop->setEnabled(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    int ret = QMessageBox::question(this, "Close", "Are you sure close it", "Yes", "No");
    if (1 == ret)
    {
        event->ignore();
    }
}

void MainWindow::startGame()
{
    this->ui->btn_start->setEnabled(false);
    this->ui->btn_pause->setEnabled(true);
    this->ui->btn_stop->setEnabled(true);
    this->myScene->startGame();
}


void MainWindow::pauseGame()
{
    if (this->ui->btn_pause->text() == "暂停")
    {
        this->ui->btn_pause->setText("继续");
        this->myScene->pauseGame(true);
    }
    else if(this->ui->btn_pause->text() == "继续")
    {
        this->ui->btn_pause->setText("暂停");
        this->myScene->pauseGame(false);
    }
}

void MainWindow::stopGame()
{
    this->ui->btn_start->setEnabled(true);
    this->ui->btn_pause->setEnabled(false);
    this->ui->btn_stop->setEnabled(false);
    this->myScene->stopGame();
    this->ui->btn_pause->setText("暂停");
    this->score = 0;
    this->ui->lcd_score->display(this->score);
}

void MainWindow::updateScore()
{
    this->score = this->score + 10;
    this->ui->lcd_score->display(this->score);
}
