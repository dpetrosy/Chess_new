#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>
#include <QStackedWidget>

#include "helpers.hpp"
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
    void             setBackgroundImage(const QString& image);
    void             showQuitWindow();

    // Getters
    MainMenu*        getMainMenu();
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

    // Images
    QPixmap         _backgroundImage;
    QPalette        _palette;

    DataCollector*  _dataCollector;

    // Menus Widgets
    MainMenu*       _MainMenuWidget;
    //PVPMenu*        _PVPMenuWidget;
    //SettingsMenu*   _SettingsMenuWidget;
    QStackedWidget* _MenusStackedWidget;

    // Chess game Widgets
    //GameWidget*     _GameWidget;
};

// Util functions
void switchMenu(MainWindow* mainWindow, Menus toMenu);

#endif // MAINWINDOW_HPP
