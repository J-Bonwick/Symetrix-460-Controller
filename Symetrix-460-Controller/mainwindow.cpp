#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , settingsDialog(new SettingsDialog)
{
    ui->setupUi(this);

    connect(ui->actionOptions, &QAction::triggered, settingsDialog, &SettingsDialog::show);
}

MainWindow::~MainWindow()
{
    delete ui;
}

