#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtWidgets/QMainWindow>
#include <QtWidgets/QSystemTrayIcon>
#include <QtCore>
#ifdef Q_WS_MAEMO_5
    #include <QDesktopWidget>
#endif
#include "munadiengine.h"
#include "settingsdialog.h"

namespace Ui
{
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    Q_CLASSINFO("D-Bus Interface", "org.indt.munadi")

public:

    MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    MunadiEngine * munadi;
    settingsDialog * addCity;
    QTimer * timer;
    bool closeWindow;
    void loadSettings();
    void saveSettings();
    bool eventFilter(QObject *, QEvent *);
    QSystemTrayIcon * tray;
    QMenu * trayMenu;
    void createTrayMenu();
protected:
    void showEvent(QShowEvent *);
    void changeEvent(QEvent *);


private slots:
    void on_actionNew_City_triggered();
    void updateDisplay();
    void toggleView(){ isVisible() ? hide() : show(); }
    void on_actionE_xit_triggered();
    void on_actionAbout_Munadi_triggered();
    void on_actionPlay_Stop_Athan_triggered();
    void on_actionShow_On_Athan_triggered();
    void iconActivated(QSystemTrayIcon::ActivationReason reason);
    void on_actionStart_with_PC_triggered(bool checked);
    void on_actionCompact_mode_triggered(bool checked);
    void on_actionCheck_for_updates_triggered(bool checked);

public slots:
    Q_SCRIPTABLE int top_application();
};

#endif // MAINWINDOW_H
