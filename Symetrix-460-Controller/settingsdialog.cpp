#include "settingsdialog.h"
#include "ui_settingsdialog.h"

SettingsDialog::SettingsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SettingsDialog)
{
    ui->setupUi(this);


    fillPortBox();
    readSettings();
    this->setModal(true);

    connect(ui->buttonBox, &QDialogButtonBox::accepted, this, &SettingsDialog::applySettings);
    connect(ui->refreshButton, &QPushButton::pressed, this, &SettingsDialog::fillPortBox);
}

SettingsDialog::~SettingsDialog()
{
    delete ui;
}

void SettingsDialog::applySettings()
{
    saveSettings();
}

void SettingsDialog::fillPortBox()
{
    ui->portBox->clear();
    const auto ports = QSerialPortInfo::availablePorts();
    for(const QSerialPortInfo &port : ports){
        ui->portBox->addItem(port.portName());
    }
}

void SettingsDialog::saveSettings()
{
    QSettings settings(QCoreApplication::organizationName(), QCoreApplication::applicationName());
    settings.beginGroup("serial");
    settings.setValue("port", ui->portBox->currentText());
    settings.setValue("baudrate", ui->baudRateBox->currentText());
    settings.endGroup();
}

void SettingsDialog::readSettings()
{
    QSettings settings(QCoreApplication::organizationName(), QCoreApplication::applicationName());
    settings.beginGroup("serial");
    ui->portBox->setCurrentText(settings.value("port").toString());
    ui->baudRateBox->setCurrentText(settings.value("baudrate").toString());
    settings.endGroup();
}
