#ifndef SETTINGSDIALOG_H
#define SETTINGSDIALOG_H

#include <QDialog>
#include <QSettings>
#include <QSerialPortInfo>

namespace Ui {
class SettingsDialog;
}

class SettingsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SettingsDialog(QWidget *parent = nullptr);
    ~SettingsDialog();
public slots:
    void applySettings();
    void fillPortBox();

private:
    Ui::SettingsDialog *ui;
    //void fillPortBox();
    void saveSettings();
    void readSettings();
};

#endif // SETTINGSDIALOG_H
