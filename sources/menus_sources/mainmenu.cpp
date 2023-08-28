#include "mainmenu.hpp"
#include "mainwindow.hpp"
#include "menus_helpers.hpp"
#include "data_collector.hpp"
#include "paths.hpp"
#include "utils.hpp"

MainMenu::MainMenu(MainWindow *mainWindow)
{
    // Init class members
    init();

    // Make MainMenu
    makeMainMenu(mainWindow);
}

MainMenu::~MainMenu()
{
    delete _PVPButton;
    delete _PVCButton;
    delete _InstrButton;
    delete _SettingsButton;
    delete _QuitButton;
    delete _verLayout;
    delete _horLayout;
    delete _versionTextLabel;
    delete _widgetForVerLayout;
    delete _widgetForHorLayout;
}

// Public funtions
void MainMenu::makeMenuBeforeSwitch(MainWindow* mainWindow)
{
    auto dataCollector = DataCollector::GetInstance();
    auto language = dataCollector->getLanguage();

    // Set bkg image
    mainWindow->setBackgroundImage(dataCollector->getBgImage());

    if (language == Languages::Armenian)
    {
        _PVPButton->setText("Խաղալ ընկերոջ հետ");
        _PVCButton->setText("Խաղալ համակարգչի հետ");
        _InstrButton->setText("Կանոններ");
        _SettingsButton->setText("Կարգավորումներ");
        _QuitButton->setText("Լքել");
        _versionTextLabel->setText("Տարբերակ: 1.2.4");
        _versionTextLabel->move((int)MainMenuProps::VersionTextLabelX - 20, (int)MainMenuProps::VersionTextLabelY);
    }
    else if (language == Languages::Russian)
    {
        _PVPButton->setText("Сыграть с Другом");
        _PVCButton->setText("Сыграть с Компьютером");
        _InstrButton->setText("Правила");
        _SettingsButton->setText("Настройки");
        _QuitButton->setText("Выйти");
        _versionTextLabel->setText("Версия: 1.2.4");
        _versionTextLabel->move((int)MainMenuProps::VersionTextLabelX, (int)MainMenuProps::VersionTextLabelY);
    }
    else // English US
    {
        _PVPButton->setText("Player vs Player");
        _PVCButton->setText("Player vs Computer");
        _InstrButton->setText("Instructions");
        _SettingsButton->setText("Settings");
        _QuitButton->setText("Quit");
        _versionTextLabel->setText("Version: 1.2.4");
        _versionTextLabel->move((int)MainMenuProps::VersionTextLabelX, (int)MainMenuProps::VersionTextLabelY);
    }
}

// Private functions
void MainMenu::init()
{
    // Widgets
    _widgetForVerLayout = new QWidget(this);
    _widgetForHorLayout = new QWidget(this);

    // Layouts
    _verLayout = new QVBoxLayout(_widgetForVerLayout);
    _horLayout = new QHBoxLayout(_widgetForHorLayout);

    // Push Buttons
    _PVPButton = new QPushButton();
    _PVCButton = new QPushButton();
    _InstrButton = new QPushButton();
    _SettingsButton = new QPushButton();
    _QuitButton = new QPushButton();

    // Version text label
    _versionTextLabel = new QLabel(this);
}

void MainMenu::makeMainMenu(MainWindow* mainWindow)
{
    // Set buttons sizes
    setPushButtonSize(_PVPButton, (int)MainMenuProps::verLayoutButtonsW, (int)MainMenuProps::verLayoutButtonsH);
    setPushButtonSize(_PVCButton, (int)MainMenuProps::verLayoutButtonsW, (int)MainMenuProps::verLayoutButtonsH);
    setPushButtonSize(_InstrButton, (int)MainMenuProps::verLayoutButtonsW, (int)MainMenuProps::verLayoutButtonsH);
    setPushButtonSize(_SettingsButton, (int)MainMenuProps::horLayoutButtonsW, (int)MainMenuProps::horLayoutButtonsH);
    setPushButtonSize(_QuitButton, (int)MainMenuProps::horLayoutButtonsW, (int)MainMenuProps::horLayoutButtonsH);

    // Set buttons fonts
    setPushButtonFont(_PVPButton, (int)MainMenuProps::verLayoutButtonsFont);
    setPushButtonFont(_PVCButton, (int)MainMenuProps::verLayoutButtonsFont);
    setPushButtonFont(_InstrButton, (int)MainMenuProps::verLayoutButtonsFont);
    setPushButtonFont(_SettingsButton, (int)MainMenuProps::horLayoutButtonsFont);
    setPushButtonFont(_QuitButton, (int)MainMenuProps::horLayoutButtonsFont);

    // Set buttons styles
    ::setStyleSheet(_PVPButton, StylesPaths::MainMenuButtonStyle);
    ::setStyleSheet(_PVCButton, StylesPaths::MainMenuButtonStyle);
    ::setStyleSheet(_InstrButton, StylesPaths::MainMenuButtonStyle);
    ::setStyleSheet(_SettingsButton, StylesPaths::MainMenuButtonStyle);
    ::setStyleSheet(_QuitButton, StylesPaths::MainMenuButtonStyle);

    // Add buttons to layouts
    _verLayout->addWidget(_PVPButton);
    _verLayout->addWidget(_PVCButton);
    _verLayout->addWidget(_InstrButton);
    _horLayout->addWidget(_SettingsButton);
    _horLayout->addWidget(_QuitButton);

    // Set geometry for layouts
    QRect rect((int)MainMenuProps::verLayoutX, (int)MainMenuProps::verLayoutY, (int)MainMenuProps::verLayoutW, (int)MainMenuProps::verLayoutH);
    _widgetForVerLayout->setGeometry(rect);
    rect.setRect((int)MainMenuProps::horLayoutX, (int)MainMenuProps::horLayoutY, (int)MainMenuProps::horLayoutW, (int)MainMenuProps::horLayoutH);
    _widgetForHorLayout->setGeometry(rect);

    // Version text label
    _versionTextLabel->setGeometry((int)MainMenuProps::VersionTextLabelX, (int)MainMenuProps::VersionTextLabelY, (int)MainMenuProps::VersionTextLabelW, (int)MainMenuProps::VersionTextLabelH);
    ::setStyleSheet(_versionTextLabel, StylesPaths::VersionTextStyle);
    _versionTextLabel->setText("Version: 1.2.4");

    // Make connects
    connect(_PVPButton, &QPushButton::clicked, mainWindow, std::bind(switchMenu, mainWindow, Menus::PVPMenu));
    //connect(_PVCButton, &QPushButton::clicked, mainWindow, std::bind(switchMenu, mainWindow, Menus::PVCMenu));
    //connect(_InstrButton, &QPushButton::clicked, mainWindow, std::bind(switchMenu, mainWindow, Menus::InstructionsMenu));
    connect(_SettingsButton, &QPushButton::clicked, mainWindow, std::bind(switchMenu, mainWindow, Menus::SettingsMenu));
    connect(_QuitButton, &QPushButton::clicked, mainWindow, std::bind(switchMenu, mainWindow, Menus::QuitMenu));
}
