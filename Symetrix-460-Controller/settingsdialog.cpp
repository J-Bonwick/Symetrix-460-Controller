#include "settingsdialog.h"
#include "ui_settingsdialog.h"

SettingsDialog::SettingsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SettingsDialog)
{
    ui->setupUi(this);
    readSettings();

    connect(ui->buttonBox, &QDialogButtonBox::accepted, this, &SettingsDialog::applySettings);
}

SettingsDialog::~SettingsDialog()
{
    delete ui;
}

void SettingsDialog::applySettings()
{
    saveSettings();
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
