#ifndef MAINMENU_HPP
#define MAINMENU_HPP

#include <QWidget>
#include <QDebug>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>

#include "predefined_classes.hpp"

class MainMenu : public QWidget
{
    Q_OBJECT

public:
    explicit MainMenu(MainWindow* mainWindow);
    virtual ~MainMenu();

    void makeMenuBeforeSwitch(MainWindow* mainWindow);

private:
    void init();
    void makeMainMenu(MainWindow* mainWindow);

private:
    // Widgets
    QWidget* _widgetForVerLayout;
    QWidget* _widgetForHorLayout;

    // Layouts
    QVBoxLayout* _verLayout;
    QHBoxLayout* _horLayout;

    // PushButtons
    QPushButton* _PVPButton;
    QPushButton* _PVCButton;
    QPushButton* _InstrButton;
    QPushButton* _SettingsButton;
    QPushButton* _QuitButton;

    // Version text label
    QLabel*      _versionTextLabel;
};

#endif // MAINMENU_HPP
