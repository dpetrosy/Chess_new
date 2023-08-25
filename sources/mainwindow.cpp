#include <QCoreApplication>
#include <QMessageBox>
#include <QDebug>

#include "mainwindow.hpp"
#include "mainmenu.hpp"
#include "settingsmenu.hpp"
#include "data_collector.hpp"
#include "utils.hpp"
#include "paths.hpp"

MainWindow::MainWindow()
{
    // Set window size
    this->setFixedSize((int)MainWindowProps::windowSizeW, (int)MainWindowProps::windowSizeH);

    // Init class members
    init();

    setBackgroundImage(_dataCollector->getBgImage());

    // Make StackedWidget
    makeMenusStackedWidget();

    // Set MainMenu when program start
    setCentralWidget(this->_MenusStackedWidget);
    switchMenu(this, Menus::MainMenu);
}

MainWindow::~MainWindow()
{
    delete _dataCollector;

    // Menus Widgets
    delete _MainMenuWidget;
    //delete _PVPMenuWidget;
    delete _SettingsMenuWidget;

    // Chess game attributes
    //delete _GameWidget;

    // StackedWidgets
    delete _MenusStackedWidget;
}

// Singlton pattern realization
MainWindow *MainWindow::_mainWindow = nullptr;

MainWindow *MainWindow::GetInstance()
{
    if(_mainWindow == nullptr)
        _mainWindow = new MainWindow();

    return _mainWindow;
}

void MainWindow::init()
{
    _dataCollector = DataCollector::GetInstance();

    // Menus Widgets
    _MainMenuWidget = new MainMenu(this);
    //_PVPMenuWidget = new PVPMenu();
    _SettingsMenuWidget = new SettingsMenu();

    // Menus StackedWidget
    _MenusStackedWidget = new QStackedWidget(this);

    // Chess game attributes
    //_GameWidget = GameWidget::GetInstance(this);
}

// Public functions
void MainWindow::setBackgroundImage(const BgImages& bgImage)
{
    QString image = getBgImageStrByNumber(bgImage);
    image = replaceSpaceInString(image);
    _backgroundImage.load(ImagesPaths::BackgroundsPath + image + BgImagesStr::Extencion);
    _backgroundImage = _backgroundImage.scaled(this->size(), Qt::IgnoreAspectRatio);
    _palette.setBrush(QPalette::Window, _backgroundImage);
    this->setPalette(_palette);
}

void MainWindow::showQuitWindow()
{
    auto language = _dataCollector->getLanguage();

    if (language == Languages::Armenian)
    {
        if (QMessageBox::question(this, "Լքման հաստատում", "Դուք վստահ եք, որ ցանկանում եք դուրս գալ?", QMessageBox::Yes|QMessageBox::Cancel, QMessageBox::Cancel) == QMessageBox::Yes)
            exitFromProgram(0);
    }
    else if (language == Languages::Russian)
    {
        if (QMessageBox::question(this, "Подтверждение выхода", "Вы уверены, что хотите выйти?", QMessageBox::Yes|QMessageBox::Cancel, QMessageBox::Cancel) == QMessageBox::Yes)
            exitFromProgram(0);
    }
    else // Endlish US
    {
        if (QMessageBox::question(this, "Quit confirmation", "Are you sure you want to quit?", QMessageBox::Yes|QMessageBox::Cancel, QMessageBox::Cancel) == QMessageBox::Yes)
            exitFromProgram(0);
    }
}

// Getters
MainMenu* MainWindow::getMainMenu()
{
    return _MainMenuWidget;
}

SettingsMenu* MainWindow::getSettingsMenu()
{
    return _SettingsMenuWidget;
}

QStackedWidget* MainWindow::getStackedWidget()
{
    return _MenusStackedWidget;
}

// Private functions
void MainWindow::exitFromProgram(int signal)
{
    QCoreApplication::exit(signal);
}

void MainWindow::makeMenusStackedWidget()
{
    makeStackedWidget(_MenusStackedWidget, _MainMenuWidget, _SettingsMenuWidget); //, _PVPMenuWidget, , _GameWidget);
}

// Util functions
void switchMenu(MainWindow* mainWindow, Menus toMenu)
{
    if (toMenu == Menus::MainMenu)
        mainWindow->getMainMenu()->makeMenuBeforeSwitch(mainWindow);
    else if (toMenu == Menus::SettingsMenu)
        mainWindow->getSettingsMenu()->makeMenuBeforeSwitch();
    else if (toMenu == Menus::QuitMenu)
        mainWindow->showQuitWindow();

    if (toMenu != Menus::QuitMenu)
        mainWindow->getStackedWidget()->setCurrentIndex((int)toMenu);
}
