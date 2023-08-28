#include <QDebug>
#include <QRandomGenerator>

#include "paths.hpp"
#include "pvpmenu.hpp"
#include "start_game_button.hpp"
#include "mainwindow.hpp"
#include "toggle_switch.hpp"
#include "data_collector.hpp"
#include "defaults.hpp"
#include "utils.hpp"

PVPMenu::PVPMenu()
{
    // Init class members
    init();

    // Make PVPMenu
    makePVPMenu();
}

PVPMenu::~PVPMenu()
{
    delete _bgLabel;
    delete _topTextLabel;

    // Game Variant
    delete _gameVariantTextLabel;
    delete _gameVariantComboBox;

    // Time Control
    delete _timeControlBgLabel;
    delete _timeControlTextLabel;
    delete _timeControlToggleSwitch;
    delete _minutesSliderTextLabel;
    delete _minutesSliderNumberLabel;
    delete _incSecondsTextLabel;
    delete _incSecondsNumberLabel;
    delete _minutesSlider;
    delete _incSecondsSlider;

    // Quick Games
    delete _quickGamesTextLabel;
    delete _bullet1MButton;
    delete _blitz3MButton;
    delete _blitz3MInc2SecButton;
    delete _blitz5MButton;
    delete _blitz10MButton;
    delete _rapid15MButton;

    // Color buttons
    delete _whiteColorButton;
    delete _blackColorButton;
    delete _randomColorButton;

    // Return button
    delete _returnButton;
}

// Init
void PVPMenu::init()
{
    _bgLabel = new QLabel(this);
    _topTextLabel = new QLabel(this);

    // Game Variant
    _gameVariantTextLabel = new QLabel(this);
    _gameVariantComboBox = new QComboBox(this);

    // Time Control
    _timeControlBgLabel = new QLabel(this);
    _timeControlTextLabel = new QLabel(this);
    _timeControlToggleSwitch = new ToggleSwitch(this);
    _minutesSliderTextLabel = new QLabel(this);
    _minutesSliderNumberLabel = new QLabel(this);
    _incSecondsTextLabel = new QLabel(this);
    _incSecondsNumberLabel = new QLabel(this);
    _minutesSlider = new QSlider(Qt::Horizontal, this);
    _incSecondsSlider = new QSlider(Qt::Horizontal, this);
    _isTimeOn = DefaultData::isTimeOn;

    // Quick Games
    _quickGamesTextLabel = new QLabel(this);
    _bullet1MButton = new StartGameButton(this, StartGameButtons::Bullet1M);
    _blitz3MButton = new StartGameButton(this, StartGameButtons::Blitz3M);
    _blitz3MInc2SecButton = new StartGameButton(this, StartGameButtons::Blitz3MInc2Sec);
    _blitz5MButton = new StartGameButton(this, StartGameButtons::Blitz5M);
    _blitz10MButton = new StartGameButton(this, StartGameButtons::Blitz10M);
    _rapid15MButton = new StartGameButton(this, StartGameButtons::Rapid15M);

    // Color buttons
    _whiteColorButton = new StartGameButton(this, StartGameButtons::WhiteColor);
    _blackColorButton = new StartGameButton(this, StartGameButtons::BlackColor);
    _randomColorButton = new StartGameButton(this, StartGameButtons::RandomColor);

    // Return button
    _returnButton = new ClickableLabel(this);
}

// Public slots
void PVPMenu::variantComboBoxIndexChanged(int index)
{
    DataCollector::GetInstance()->setGameVariant(static_cast<GameVariants>(index));
}

void PVPMenu::swapTimeControl()
{
    auto dataCollector = DataCollector::GetInstance();
    bool isTimeOn = dataCollector->isTimeOn();

    if (isTimeOn)
    {
        dataCollector->setTime(false);
        _minutesSlider->setEnabled(false);
        _incSecondsSlider->setEnabled(false);
        _minutesSlider->setCursor(Qt::ForbiddenCursor);
        _incSecondsSlider->setCursor(Qt::ForbiddenCursor);
    }
    else
    {
        dataCollector->setTime(true);
        _minutesSlider->setEnabled(true);
        _incSecondsSlider->setEnabled(true);
        _minutesSlider->setCursor(Qt::PointingHandCursor);
        _incSecondsSlider->setCursor(Qt::PointingHandCursor);
    }
}

void PVPMenu::minutesSliderValueChanged(int index)
{
    double value = 0;

    if (index == 0)
        value = 0.25;
    else if (index >= 1 && index < 4)
        value = 0.25 * (index + 1);
    else if (index == 3)
        value = 1;
    else if (index == 4)
        value = 1.5;
    else if (index >= 5 && index <= 23)
        value = index - 3;
    else if (index >= 24 && index <= 27)
        value = (index % 23) * 5 + 20;
    else
        value = (index % 28) * 15 + 45;

    DataCollector::GetInstance()->setGameMinutes(value);
    _minutesSliderNumberLabel->setText(QString::number(value));
}

void PVPMenu::incSecondsSliderValueChanged(int index)
{
    int value = 0;

    if (index == 0)
        value = 0;
    else if (index >= 1 && index <= 20)
        value = index;
    else if (index >= 21 && index <= 25)
        value = (index % 20) * 5 + 20;
    else if (index == 26)
        value = 60;
    else
        value = (index % 26) * 30 + 60;

    DataCollector::GetInstance()->setGameIncSeconds(value);
    _incSecondsNumberLabel->setText(QString::number(value));
}

void PVPMenu::returnToMainMenu()
{
    switchMenu(MainWindow::GetInstance(), Menus::MainMenu);
}

// Public util functions
void PVPMenu::makeMenuBeforeSwitch()
{
    auto dataCollector = DataCollector::GetInstance();
    bool isDarkTheme = dataCollector->isDarkTheme();
    Languages language = dataCollector->getLanguage();

    // Background label
    setStyleSheetByTheme(_bgLabel, StylesPaths::lightThemeBgLabelStyle, StylesPaths::darkThemeBgLabelStyle, isDarkTheme);

    // Top text label
    setStyleSheetByTheme(_topTextLabel, StylesPaths::lightTopTextStyle, StylesPaths::darkTopTextStyle, isDarkTheme);

    // Text for game variant
    setStyleSheetByTheme(_gameVariantTextLabel, StylesPaths::lightDimTextStyle, StylesPaths::darkDimTextStyle, isDarkTheme);

    // Game variant combobox
    setStyleSheetByTheme(_gameVariantComboBox, StylesPaths::lightVariantComboboxStyle, StylesPaths::darkVariantComboboxStyle, isDarkTheme);
    //_gameVariantComboBox->GameWidget::GetInstance()->setGameVariant(variant);

    // Time Control background label
    setStyleSheetByTheme(_timeControlBgLabel, StylesPaths::lightTimeControlBgLabelStyle, StylesPaths::darkTimeControlBgLabelStyle, isDarkTheme);

    // Text for time control
    setStyleSheetByTheme(_timeControlTextLabel, StylesPaths::lightDimTextStyle, StylesPaths::darkDimTextStyle, isDarkTheme);

    // Text for minutes slider
    setStyleSheetByTheme(_minutesSliderTextLabel, StylesPaths::lightDimTextStyle, StylesPaths::darkDimTextStyle, isDarkTheme);

    // Text for minutes slider number
    setStyleSheetByTheme(_minutesSliderNumberLabel, StylesPaths::lightBoldDimTextStyle, StylesPaths::darkBoldDimTextStyle, isDarkTheme);

    // Minutes slider
    setStyleSheetByTheme(_minutesSlider, StylesPaths::lightSliderStyle, StylesPaths::darkSliderStyle, isDarkTheme);

    // Text for increment seconds
    setStyleSheetByTheme(_incSecondsTextLabel, StylesPaths::lightDimTextStyle, StylesPaths::darkDimTextStyle, isDarkTheme);

    // Text for increment seconds number
    setStyleSheetByTheme(_incSecondsNumberLabel, StylesPaths::lightBoldDimTextStyle, StylesPaths::darkBoldDimTextStyle, isDarkTheme);

    // Increment seconds slider
    setStyleSheetByTheme(_incSecondsSlider, StylesPaths::lightSliderStyle, StylesPaths::darkSliderStyle, isDarkTheme);

    // Text for quick games
    setStyleSheetByTheme(_quickGamesTextLabel, StylesPaths::lightQuickGamesTextStyle, StylesPaths::darkQuickGamesTextStyle, isDarkTheme);

    // Bullet 1M button
    setStyleSheetByTheme(_bullet1MButton, StylesPaths::lightQuickGamesButtonStyle, StylesPaths::darkQuickGamesButtonStyle, isDarkTheme);
    setQLabelImageByTheme(_bullet1MButton, ImagesPaths::LightBullet1MButton, ImagesPaths::DarkBullet1MButton, isDarkTheme);

    // Blitz 3M button
    setStyleSheetByTheme(_blitz3MButton, StylesPaths::lightQuickGamesButtonStyle, StylesPaths::darkQuickGamesButtonStyle, isDarkTheme);
    setQLabelImageByTheme(_blitz3MButton, ImagesPaths::LightBlitz3MButton, ImagesPaths::DarkBlitz3MButton, isDarkTheme);

    // Blitz 3M increment 2sec button
    setStyleSheetByTheme(_blitz3MInc2SecButton, StylesPaths::lightQuickGamesButtonStyle, StylesPaths::darkQuickGamesButtonStyle, isDarkTheme);
    setQLabelImageByTheme(_blitz3MInc2SecButton, ImagesPaths::LightBlitz3MInc2SecButton, ImagesPaths::DarkBlitz3MInc2SecButton, isDarkTheme);

    // Blitz 5M button
    setStyleSheetByTheme(_blitz5MButton, StylesPaths::lightQuickGamesButtonStyle, StylesPaths::darkQuickGamesButtonStyle, isDarkTheme);
    setQLabelImageByTheme(_blitz5MButton, ImagesPaths::LightBlitz5MButton, ImagesPaths::DarkBlitz5MButton, isDarkTheme);

    // Blitz 10M button
    setStyleSheetByTheme(_blitz10MButton, StylesPaths::lightQuickGamesButtonStyle, StylesPaths::darkQuickGamesButtonStyle, isDarkTheme);
    setQLabelImageByTheme(_blitz10MButton, ImagesPaths::LightBlitz10MButton, ImagesPaths::DarkBlitz10MButton, isDarkTheme);

    // Rapid 15M button
    setStyleSheetByTheme(_rapid15MButton, StylesPaths::lightQuickGamesButtonStyle, StylesPaths::darkQuickGamesButtonStyle, isDarkTheme);
    setQLabelImageByTheme(_rapid15MButton, ImagesPaths::LightRapid15MButton, ImagesPaths::DarkRapid15MButton, isDarkTheme);

    // White color button
    setStyleSheetByTheme(_whiteColorButton, StylesPaths::lightQuickGamesButtonStyle, StylesPaths::darkColorButtonStyle, isDarkTheme);
    setQLabelImageByTheme(_whiteColorButton, ImagesPaths::LightWhiteColorButton, ImagesPaths::DarkWhiteColorButton, isDarkTheme);

    // Black color button
    setStyleSheetByTheme(_blackColorButton, StylesPaths::lightQuickGamesButtonStyle, StylesPaths::darkColorButtonStyle, isDarkTheme);
    setQLabelImageByTheme(_blackColorButton, ImagesPaths::LightBlackColorButton, ImagesPaths::DarkBlackColorButton, isDarkTheme);

    // Random color button
    setStyleSheetByTheme(_randomColorButton, StylesPaths::lightQuickGamesButtonStyle, StylesPaths::darkColorButtonStyle, isDarkTheme);
    setQLabelImageByTheme(_randomColorButton, ImagesPaths::LightRandomColorButton, ImagesPaths::DarkRandomColorButton, isDarkTheme);

    // Return button
    setQLabelImageByTheme(_returnButton, ImagesPaths::LightReturnButton, ImagesPaths::DarkReturnButton, isDarkTheme);

    if (language == Languages::Armenian)
    {
        _topTextLabel->setText("Խաղալ ընկերոջ հետ");
        _gameVariantTextLabel->setText("Տարբերակ");
        _gameVariantTextLabel->move((int)PVPMenuProps::GameVariantTextLabelX - 28, (int)PVPMenuProps::GameVariantTextLabelY);
        _timeControlTextLabel->setText("Ժամակարգ");
        _minutesSliderTextLabel->setText("Րոպեներ ամեն կողմի համար։ ");
        _minutesSliderTextLabel->move((int)PVPMenuProps::MinutesTextLabelX - 40, (int)PVPMenuProps::MinutesTextLabelY);
        _minutesSliderNumberLabel->setGeometry((int)PVPMenuProps::MinutesNumberLabelX + 60, (int)PVPMenuProps::MinutesNumberLabelY,
                                         (int)PVPMenuProps::MinutesNumberLabelW, (int)PVPMenuProps::MinutesNumberLabelH);
        _incSecondsTextLabel->setText("Ավելացումը ըստ վայրկյանների: ");
        _incSecondsTextLabel->move((int)PVPMenuProps::IncSecondsTextLabelX - 40, (int)PVPMenuProps::IncSecondsTextLabelY);
        _incSecondsNumberLabel->setGeometry((int)PVPMenuProps::IncSecondsNumberLabelX + 45, (int)PVPMenuProps::IncSecondsNumberLabelY,
                                         (int)PVPMenuProps::IncSecondsNumberLabelW, (int)PVPMenuProps::IncSecondsNumberLabelH);
        _quickGamesTextLabel->setText("Արագ սկիզբ");
    }
    else if (language == Languages::Russian)
    {
        _topTextLabel->setText("Сыграть с другом");
        _gameVariantTextLabel->setText("Вариант");
        _gameVariantTextLabel->move((int)PVPMenuProps::GameVariantTextLabelX - 10, (int)PVPMenuProps::GameVariantTextLabelY);
        _timeControlTextLabel->setText("Время");
        _timeControlTextLabel->setGeometry((int)PVPMenuProps::TimeControlTextLabelX + 38, (int)PVPMenuProps::TimeControlTextLabelY, 100, 20);
        _minutesSliderTextLabel->setText("Минут на партию: ");
        _minutesSliderTextLabel->move((int)PVPMenuProps::MinutesTextLabelX + 10, (int)PVPMenuProps::MinutesTextLabelY);
        _minutesSliderNumberLabel->setGeometry((int)PVPMenuProps::MinutesNumberLabelX + 23, (int)PVPMenuProps::MinutesNumberLabelY,
                                         (int)PVPMenuProps::MinutesNumberLabelW, (int)PVPMenuProps::MinutesNumberLabelH);
        _incSecondsTextLabel->setText("Добавление секунд на ход: ");
        _incSecondsTextLabel->move((int)PVPMenuProps::IncSecondsTextLabelX - 13, (int)PVPMenuProps::IncSecondsTextLabelY);
        _incSecondsNumberLabel->setGeometry((int)PVPMenuProps::IncSecondsNumberLabelX + 33, (int)PVPMenuProps::IncSecondsNumberLabelY,
                                         (int)PVPMenuProps::IncSecondsNumberLabelW, (int)PVPMenuProps::IncSecondsNumberLabelH);
        _quickGamesTextLabel->setText("Быстрый Старт");
    }
    else // English
    {
        _topTextLabel->setText("Play with a friend");
        _gameVariantTextLabel->setText("Variant");
        _gameVariantTextLabel->move((int)PVPMenuProps::GameVariantTextLabelX, (int)PVPMenuProps::GameVariantTextLabelY);
        _timeControlTextLabel->setText("Time control");
        _timeControlTextLabel->setGeometry((int)PVPMenuProps::TimeControlTextLabelX, (int)PVPMenuProps::TimeControlTextLabelY, 100, 20);
        _timeControlToggleSwitch->move((int)PVPMenuProps::TimeControlToggleSwitchX, (int)PVPMenuProps::TimeControlToggleSwitchY);
        _minutesSliderTextLabel->setText("Minutes per side: ");
        _minutesSliderTextLabel->move((int)PVPMenuProps::MinutesTextLabelX, (int)PVPMenuProps::MinutesTextLabelY);
        _minutesSliderNumberLabel->setGeometry((int)PVPMenuProps::MinutesNumberLabelX, (int)PVPMenuProps::MinutesNumberLabelY,
                                         (int)PVPMenuProps::MinutesNumberLabelW, (int)PVPMenuProps::MinutesNumberLabelH);
        _incSecondsTextLabel->setText("Increment in seconds: ");
        _incSecondsTextLabel->move((int)PVPMenuProps::IncSecondsTextLabelX, (int)PVPMenuProps::IncSecondsTextLabelY);
        _incSecondsNumberLabel->setGeometry((int)PVPMenuProps::IncSecondsNumberLabelX, (int)PVPMenuProps::IncSecondsNumberLabelY,
                                         (int)PVPMenuProps::IncSecondsNumberLabelW, (int)PVPMenuProps::IncSecondsNumberLabelH);
        _quickGamesTextLabel->setText("Quick Start");
    }
}

//void PVPMenu::setDataBeforeStartGame(double minutes, int incSeconds, PiecesColors color)
//{
//    auto gameWidget = GameWidget::GetInstance();

//    // Quick game button clicked
//    if (minutes != 0 || incSeconds != 0)
//    {
//        gameWidget->setIsTimeAvailable(true);
//        gameWidget->setGameMinutes(minutes);
//        gameWidget->setIncrementSeconds(incSeconds);
//        gameWidget->setGameVariant(GameVariants::Standard);
//    }

//    if (color == PiecesColors::Random)
//    {
//        if (QRandomGenerator::global()->bounded(0, 2) == 0)
//            color = PiecesColors::Black;
//        else
//            color = PiecesColors::White;
//    }

//    gameWidget->setBelowPlayerColor(color);
//}

// Private functions
void PVPMenu::makePVPMenu()
{
    bool isDarkTheme = DataCollector::GetInstance()->isDarkTheme();

    // Background label
    setStyleSheetByTheme(_bgLabel, StylesPaths::lightThemeBgLabelStyle, StylesPaths::darkThemeBgLabelStyle, isDarkTheme);
    _bgLabel->setGeometry((int)PVPMenuProps::BgLabelX, (int)PVPMenuProps::BgLabelY, (int)PVPMenuProps::BgLabelW, (int)PVPMenuProps::BgLabelH);

    // Top text label
    _topTextLabel->setGeometry((int)PVPMenuProps::TopTextLabelX, (int)PVPMenuProps::TopTextLabelY,
                              (int)PVPMenuProps::TopTextLabelW, (int)PVPMenuProps::TopTextLabelH);
    setStyleSheetByTheme(_topTextLabel, StylesPaths::lightTopTextStyle, StylesPaths::darkTopTextStyle, isDarkTheme);
    _topTextLabel->setText("Play with a friend");
    _topTextLabel->setAlignment(Qt::AlignCenter);

    // Text for game variant
    _gameVariantTextLabel->setGeometry((int)PVPMenuProps::GameVariantTextLabelX, (int)PVPMenuProps::GameVariantTextLabelY,
                                      (int)PVPMenuProps::GameVariantTextLabelW, (int)PVPMenuProps::GameVariantTextLabelH);
    setStyleSheetByTheme(_gameVariantTextLabel, StylesPaths::lightDimTextStyle, StylesPaths::darkDimTextStyle, isDarkTheme);
    _gameVariantTextLabel->setText("Variant");

    // Game variant combobox
    _gameVariantComboBox->setGeometry((int)PVPMenuProps::GameVariantComboBoxX, (int)PVPMenuProps::GameVariantComboBoxY,
                                     (int)PVPMenuProps::GameVariantComboBoxW, (int)PVPMenuProps::GameVariantComboBoxH);
    setStyleSheetByTheme(_gameVariantComboBox, StylesPaths::lightVariantComboboxStyle, StylesPaths::darkVariantComboboxStyle, isDarkTheme);
    _gameVariantComboBox->addItem(GameVariantsStr::Standard);
    _gameVariantComboBox->addItem(GameVariantsStr::Chess960);
    _gameVariantComboBox->addItem(GameVariantsStr::KingOfTheHill);
    _gameVariantComboBox->addItem(GameVariantsStr::ThreeCheck);
    _gameVariantComboBox->addItem(GameVariantsStr::Horde);
    _gameVariantComboBox->addItem(GameVariantsStr::FromPosition);
    _gameVariantComboBox->setCurrentIndex((int)DefaultData::GameVariant);
    connect(_gameVariantComboBox, &QComboBox::currentIndexChanged, this, &PVPMenu::variantComboBoxIndexChanged);

    // Time Control background label
    setStyleSheetByTheme(_timeControlBgLabel, StylesPaths::lightTimeControlBgLabelStyle, StylesPaths::darkTimeControlBgLabelStyle, isDarkTheme);
    _timeControlBgLabel->setGeometry((int)PVPMenuProps::TimeControlBgLabelX, (int)PVPMenuProps::TimeControlBgLabelY,
                                    (int)PVPMenuProps::TimeControlBgLabelW, (int)PVPMenuProps::TimeControlBgLabelH);

    // Text for time control
    _timeControlTextLabel->setGeometry((int)PVPMenuProps::TimeControlTextLabelX, (int)PVPMenuProps::TimeControlTextLabelY,
                                      (int)PVPMenuProps::TimeControlTextLabelW, (int)PVPMenuProps::TimeControlTextLabelH);
    setStyleSheetByTheme(_timeControlTextLabel, StylesPaths::lightDimTextStyle, StylesPaths::darkDimTextStyle, isDarkTheme);
    _timeControlTextLabel->setText("Time control");

    // Time control toggle switch
    _timeControlToggleSwitch->move((int)PVPMenuProps::TimeControlToggleSwitchX, (int)PVPMenuProps::TimeControlToggleSwitchY);
    _timeControlToggleSwitch->setChecked(DefaultData::isTimeOn);
     connect(_timeControlToggleSwitch, &QCheckBox::clicked, this, &PVPMenu::swapTimeControl);

    // Text for minutes slider
    _minutesSliderTextLabel->setGeometry((int)PVPMenuProps::MinutesTextLabelX, (int)PVPMenuProps::MinutesTextLabelY,
                                  (int)PVPMenuProps::MinutesTextLabelW, (int)PVPMenuProps::MinutesTextLabelH);
    setStyleSheetByTheme(_minutesSliderTextLabel, StylesPaths::lightDimTextStyle, StylesPaths::darkDimTextStyle, isDarkTheme);
    _minutesSliderTextLabel->setText("Minutes per side: ");

    // Text for minutes slider number
    _minutesSliderNumberLabel->setGeometry((int)PVPMenuProps::MinutesNumberLabelX, (int)PVPMenuProps::MinutesNumberLabelY,
                                          (int)PVPMenuProps::MinutesNumberLabelW, (int)PVPMenuProps::MinutesNumberLabelH);
    setStyleSheetByTheme(_minutesSliderNumberLabel, StylesPaths::lightBoldDimTextStyle, StylesPaths::darkBoldDimTextStyle, isDarkTheme);
    _minutesSliderNumberLabel->setText(DefaultData::MinutesSliderNumberStr);

    // Minutes slider
    _minutesSlider->setGeometry((int)PVPMenuProps::MinutesSliderX, (int)PVPMenuProps::MinutesSliderY,
                               (int)PVPMenuProps::MinutesSliderW, (int)PVPMenuProps::MinutesSliderH);
    setStyleSheetByTheme(_minutesSlider, StylesPaths::lightSliderStyle, StylesPaths::darkSliderStyle, isDarkTheme);
    _minutesSlider->setCursor(Qt::PointingHandCursor);
    _minutesSlider->setRange(0, 37);
    _minutesSlider->setEnabled(DefaultData::isTimeOn);
    _minutesSlider->setValue(DefaultData::MinutesSliderIndex);
    connect(_minutesSlider, &QSlider::valueChanged, this, &PVPMenu::minutesSliderValueChanged);

    // Text for increment seconds slider
    _incSecondsTextLabel->setGeometry((int)PVPMenuProps::IncSecondsTextLabelX, (int)PVPMenuProps::IncSecondsTextLabelY,
                                     (int)PVPMenuProps::IncSecondsTextLabelW, (int)PVPMenuProps::IncSecondsTextLabelH);
    setStyleSheetByTheme(_incSecondsTextLabel, StylesPaths::lightDimTextStyle, StylesPaths::darkDimTextStyle, isDarkTheme);
    _incSecondsTextLabel->setText("Increment in seconds: ");

    // Text for increment seconds slider number
    _incSecondsNumberLabel->setGeometry((int)PVPMenuProps::IncSecondsNumberLabelX, (int)PVPMenuProps::IncSecondsNumberLabelY,
                                       (int)PVPMenuProps::IncSecondsNumberLabelW, (int)PVPMenuProps::IncSecondsNumberLabelH);
    setStyleSheetByTheme(_incSecondsNumberLabel, StylesPaths::lightBoldDimTextStyle, StylesPaths::darkBoldDimTextStyle, isDarkTheme);
    _incSecondsNumberLabel->setText(DefaultData::IncSecondsNumberStr);

    // Increment seconds slider
    _incSecondsSlider->setGeometry((int)PVPMenuProps::IncSecondsSliderX, (int)PVPMenuProps::IncSecondsSliderY,
                                  (int)PVPMenuProps::IncSecondsSliderW, (int)PVPMenuProps::IncSecondsSliderH);
    setStyleSheetByTheme(_incSecondsSlider, StylesPaths::lightSliderStyle, StylesPaths::darkSliderStyle, isDarkTheme);
    _incSecondsSlider->setCursor(Qt::PointingHandCursor);
    _incSecondsSlider->setRange(0, 30);
    _incSecondsSlider->setEnabled(DefaultData::isTimeOn);
    _incSecondsSlider->setValue(DefaultData::IncSecondsIndex);
    connect(_incSecondsSlider, &QSlider::valueChanged, this, &PVPMenu::incSecondsSliderValueChanged);

    // Text for quick games
    _quickGamesTextLabel->setGeometry((int)PVPMenuProps::QuickGamesTextLabelX, (int)PVPMenuProps::QuickGamesTextLabelY,
                                     (int)PVPMenuProps::QuickGamesTextLabelW, (int)PVPMenuProps::QuickGamesTextLabelH);
    setStyleSheetByTheme(_quickGamesTextLabel, StylesPaths::lightQuickGamesTextStyle, StylesPaths::darkQuickGamesTextStyle, isDarkTheme);
    _quickGamesTextLabel->setText("Quick Start");

    // Bullet 1M button
    _bullet1MButton->move((int)PVPMenuProps::Bullet1MButtonX, (int)PVPMenuProps::Bullet1MButtonY);
    setStyleSheetByTheme(_bullet1MButton, StylesPaths::lightQuickGamesButtonStyle, StylesPaths::darkQuickGamesButtonStyle, isDarkTheme);
    setQLabelImageByTheme(_bullet1MButton, ImagesPaths::LightBullet1MButton, ImagesPaths::DarkBullet1MButton, isDarkTheme);

    // Blitz 3M button
    _blitz3MButton->move((int)PVPMenuProps::Blitz3MButtonX, (int)PVPMenuProps::Blitz3MButtonY);
    setStyleSheetByTheme(_blitz3MButton, StylesPaths::lightQuickGamesButtonStyle, StylesPaths::darkQuickGamesButtonStyle, isDarkTheme);
    setQLabelImageByTheme(_blitz3MButton, ImagesPaths::LightBlitz3MButton, ImagesPaths::DarkBlitz3MButton, isDarkTheme);

    // Blitz 3M increment 2sec button
    _blitz3MInc2SecButton->move((int)PVPMenuProps::Blitz3MInc2SecButtonX, (int)PVPMenuProps::Blitz3MInc2SecButtonY);
    setStyleSheetByTheme(_blitz3MInc2SecButton, StylesPaths::lightQuickGamesButtonStyle, StylesPaths::darkQuickGamesButtonStyle, isDarkTheme);
    setQLabelImageByTheme(_blitz3MInc2SecButton, ImagesPaths::LightBlitz3MInc2SecButton, ImagesPaths::DarkBlitz3MInc2SecButton, isDarkTheme);

    // Blitz 5M button
    _blitz5MButton->move((int)PVPMenuProps::Blitz5MButtonX, (int)PVPMenuProps::Blitz5MButtonY);
    setStyleSheetByTheme(_blitz5MButton, StylesPaths::lightQuickGamesButtonStyle, StylesPaths::darkQuickGamesButtonStyle, isDarkTheme);
    setQLabelImageByTheme(_blitz5MButton, ImagesPaths::LightBlitz5MButton, ImagesPaths::DarkBlitz5MButton, isDarkTheme);

    // Blitz 10M button
    _blitz10MButton->move((int)PVPMenuProps::Blitz10MButtonX, (int)PVPMenuProps::Blitz10MButtonY);
    setStyleSheetByTheme(_blitz10MButton, StylesPaths::lightQuickGamesButtonStyle, StylesPaths::darkQuickGamesButtonStyle, isDarkTheme);
    setQLabelImageByTheme(_blitz10MButton, ImagesPaths::LightBlitz10MButton, ImagesPaths::DarkBlitz10MButton, isDarkTheme);

    // Rapid 15M button
    _rapid15MButton->move((int)PVPMenuProps::Rapid15MButtonX, (int)PVPMenuProps::Rapid15MButtonY);
    setStyleSheetByTheme(_rapid15MButton, StylesPaths::lightQuickGamesButtonStyle, StylesPaths::darkQuickGamesButtonStyle, isDarkTheme);
    setQLabelImageByTheme(_rapid15MButton, ImagesPaths::LightRapid15MButton, ImagesPaths::DarkRapid15MButton, isDarkTheme);

    // White color button
    _whiteColorButton->move((int)PVPMenuProps::WhiteColorButtonX, (int)PVPMenuProps::WhiteColorButtonY);
    setStyleSheetByTheme(_whiteColorButton, StylesPaths::lightQuickGamesButtonStyle, StylesPaths::darkColorButtonStyle, isDarkTheme);
    setQLabelImageByTheme(_whiteColorButton, ImagesPaths::LightWhiteColorButton, ImagesPaths::DarkWhiteColorButton, isDarkTheme);
    _whiteColorButton->setCursor(Qt::PointingHandCursor);

    // Black color button
    _blackColorButton->move((int)PVPMenuProps::BlackColorButtonX, (int)PVPMenuProps::BlackColorButtonY);
    setStyleSheetByTheme(_blackColorButton, StylesPaths::lightQuickGamesButtonStyle, StylesPaths::darkColorButtonStyle, isDarkTheme);
    setQLabelImageByTheme(_blackColorButton, ImagesPaths::LightBlackColorButton, ImagesPaths::DarkBlackColorButton, isDarkTheme);
    _blackColorButton->setCursor(Qt::PointingHandCursor);

    // Random color button
    _randomColorButton->move((int)PVPMenuProps::RandomColorButtonX, (int)PVPMenuProps::RandomColorButtonY);
    setStyleSheetByTheme(_randomColorButton, StylesPaths::lightQuickGamesButtonStyle, StylesPaths::darkColorButtonStyle, isDarkTheme);
    setQLabelImageByTheme(_randomColorButton, ImagesPaths::LightRandomColorButton, ImagesPaths::DarkRandomColorButton, isDarkTheme);
    _randomColorButton->setCursor(Qt::PointingHandCursor);

    // Return button
    _returnButton->move((int)PVPMenuProps::ReturnButtonX, (int)PVPMenuProps::ReturnButtonY);
    setQLabelImageByTheme(_returnButton, ImagesPaths::LightReturnButton, ImagesPaths::DarkReturnButton, isDarkTheme);
    _returnButton->setCursor(Qt::PointingHandCursor);
    connect(_returnButton, &ClickableLabel::clickedLeftButton, this, &PVPMenu::returnToMainMenu);
}
