#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>
#include <QStackedWidget>

#include "helpers.hpp"
#include "menus_helpers.hpp"
#include "predefined_classes.hpp"

// Singleton pattern used
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    // Singleton pattern realization
    MainWindow(MainWindow &other) = delete;
    MainWindow& operator=(const MainWindow&) = delete;
    static MainWindow *GetInstance();
    virtual ~MainWindow();

public:
    void             setBackgroundImage(const BgImages& bgImage);
    void             showQuitWindow();

    // Getters
    MainMenu*        getMainMenu();
    PVPMenu*         getPVPMenu();
    SettingsMenu*    getSettingsMenu();
    QStackedWidget*  getStackedWidget();

private:
    explicit MainWindow();

    void init();
    void exitFromProgram(int signal);

    void makeMenusStackedWidget();

    // StackedWidget maker
    template <typename T, typename... Types>
    void makeStackedWidget(QStackedWidget *stackedWidget, T widget, Types... arg2)
    {
        stackedWidget->addWidget(widget);
        return makeStackedWidget(stackedWidget, arg2...);
    }

    // Template Specialization
    void makeStackedWidget(QStackedWidget *stackedWidget)
    {
        Q_UNUSED(stackedWidget)
        return;
    }

private:
    // Singleton pattern realization
    static MainWindow* _mainWindow;

    DataCollector*  _dataCollector;

    // Images
    QPixmap         _backgroundImage;
    QPalette        _palette;

    // Menus Widgets
    MainMenu*       _MainMenuWidget;
    PVPMenu*        _PVPMenuWidget;
    SettingsMenu*   _SettingsMenuWidget;
    QStackedWidget* _MenusStackedWidget;

    // Chess game Widgets
    //GameWidget*     _GameWidget;
};

// Util functions
void switchMenu(MainWindow* mainWindow, Menus toMenu);

#endif // MAINWINDOW_HPP
