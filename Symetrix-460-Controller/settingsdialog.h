#ifndef SETTINGSDIALOG_H
#define SETTINGSDIALOG_H

#include <QDialog>
#include <QSettings>

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

private:
    Ui::SettingsDialog *ui;
    void saveSettings();
    void readSettings();
};

#endif // SETTINGSDIALOG_H
