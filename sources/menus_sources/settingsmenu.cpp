#include <QDebug>

#include "settingsmenu.hpp"
#include "mainwindow.hpp"
#include "toggle_switch.hpp"
#include "data_collector.hpp"
//#include "gamewidget.hpp"
#include "paths.hpp"
#include "utils.hpp"

SettingsMenu::SettingsMenu(MainWindow* mainWindow)
{
    // Init class members
    init();

    // Make SettingsMenu
    makeSettingsMenu(mainWindow);
}

SettingsMenu::~SettingsMenu()
{
    delete _bgLabel;
    delete _boardLabel;
    delete _piecesLabel;

    // Background image
    delete _bgImageTextLabel;
    delete _bgImageComboBox;

    // Piece sets
    delete _pieceSetsTextLabel;
    delete _pieceSetsComboBox;

    // Board
    delete _boardTextLabel;
    delete _boardComboBox;

    // Language
    delete _languageTextLabel;
    delete _languageComboBox;

    // Sound
    delete _soundTextLabel;
    delete _soundToggleSwitch;

    // Theme
    delete _themeTextLabel;
    delete _themeToggleSwitch;

    // Buttons background label
    delete _buttonsBgLabel;

    // Confirm Buttons
    delete _savePushButton;
    delete _cancelPushButton;

    // Menu hide and show button
    delete _hideAndShowButton;
}

void SettingsMenu::init()
{
    initSettingsData();

    _bgLabel = new QLabel(this);
    _boardLabel = new QLabel(this);
    _piecesLabel = new QLabel(this);

    // Background image
    _bgImageTextLabel = new QLabel(this);
    _bgImageComboBox = new QComboBox(this);

    // Piece sets
    _pieceSetsTextLabel = new QLabel(this);
    _pieceSetsComboBox = new QComboBox(this);

    // Board
    _boardTextLabel = new QLabel(this);
    _boardComboBox = new QComboBox(this);

    // Language
    _languageTextLabel = new QLabel(this);
    _languageComboBox = new QComboBox(this);

    // Sound
    _soundTextLabel = new QLabel(this);
    _soundToggleSwitch = new ToggleSwitch(this);

    // Theme
    _themeTextLabel = new QLabel(this);
    _themeToggleSwitch = new ToggleSwitch(this);

    // Buttons background label
    _buttonsBgLabel = new QLabel(this);

    // Confirm Buttons
    _savePushButton = new QPushButton(this);
    _cancelPushButton = new QPushButton(this);

    // Menu hide and show button
    _isMenuVisible = true;
    _hideAndShowButton = new QPushButton(this);
}

void SettingsMenu::initSettingsData()
{
    auto dataCollector = DataCollector::GetInstance();

    _tempData.bgImage = dataCollector->getBgImage();
    _tempData.board = dataCollector->getBoard();
    _tempData.pieceSet = dataCollector->getPieceSet();
    _tempData.language = dataCollector->getLanguage();
    _tempData.isSoundOn = dataCollector->isSoundOn();
    _tempData.isDarkTheme = dataCollector->isDarkTheme();
}

//// Public slots
//void SettingsMenu::cancelButtonClicked()
//{
//    _tempData = _settingsData;
//    globalIsDarkTheme = _settingsData.isDarkTheme;
//    globalPieceSetPath = ImagesPaths::piecesPath + _settingsData.piecesSetStr + "/";
//    gLanguage = _settingsData.languageStr;
//    gSound = _settingsData.isSoundAvailable;

//    auto mainWindow = MainWindow::GetInstance();
//    mainWindow->setBackgroundImage(_settingsData.bkgImageStr);
//    mainWindow->switchMenu(Menus::MainMenu);
//}

//void SettingsMenu::saveButtonClicked()
//{
//    _settingsData = _tempData;
//    globalIsDarkTheme = _settingsData.isDarkTheme;
//    globalPieceSetPath = ImagesPaths::piecesPath + _settingsData.piecesSetStr + "/";
//    gLanguage = _settingsData.languageStr;
//    gSound = _settingsData.isSoundAvailable;

//    auto mainWindow = MainWindow::GetInstance();
//    auto gameWidget = GameWidget::GetInstance();

//    mainWindow->setBackgroundImage(_settingsData.bkgImageStr);
//    gameWidget->setPieceSet(_settingsData.piecesSetStr);
//    gameWidget->setBoard(_settingsData.boardStr);

//    mainWindow->switchMenu(Menus::MainMenu);
//}

//// Public functions
//bool SettingsMenu::getTheme()
//{
//    return _settingsData.isDarkTheme;
//}

//QPushButton* SettingsMenu::getPushButton(SettingsMenuPushButtons button)
//{
//    switch (button)
//    {
//        case SettingsMenuPushButtons::CancelButton: return _cancelPushButton;
//        case SettingsMenuPushButtons::SaveButton: return _savePushButton;
//        default: return _cancelPushButton;
//    }
//}

//void SettingsMenu::makeMenuBeforeSwitch()
//{
//    // Background image
//    _bgImageComboBox->setCurrentIndex(_settingsData.bkgImageNumber);

//    // Piece set
//    _piecesLabel->setPixmap(QPixmap(ImagesPaths::settingsPiecesSetsPath + _settingsData.piecesSetStr + PieceSets::Extencion));
//    _pieceSetsComboBox->setCurrentIndex(_settingsData.pieceSetNumber);

//    // Board
//    _boardLabel->setPixmap(QPixmap(ImagesPaths::settingsBoardsPath + _settingsData.boardStr + Boards::Extencion));
//    _boardComboBox->setCurrentIndex(_settingsData.boardNumber);

//    // Language
//    _languageComboBox->setCurrentIndex(_settingsData.languageNumber);

//    // Sound
//    _soundToggleSwitch->setChecked(_settingsData.isSoundAvailable);

//    // Theme
//    _themeToggleSwitch->setChecked(globalIsDarkTheme);
//    changeMenuTheme();

//    if (gLanguage == Languages::Armenian)
//    {
//        _bgImageTextLabel->setText("Ետնանկար");
//        _pieceSetsTextLabel->setText("Խաղաքարեր");
//        _boardTextLabel->setText("Խաղատախտակ");
//        _languageTextLabel->setText("Լեզու");
//        _soundTextLabel->setText("Ձայն");
//        _themeTextLabel->setText("Սև ֆոն");
//        _cancelPushButton->setText("Չեղարկել");
//        _savePushButton->setText("Պահպանել");
//        _hideAndShowButton->setText("Թաքցնել");
//        _hideAndShowButton->setGeometry((int)SettingsMenuProps::HideAndShowButtonX - 18, (int)SettingsMenuProps::HideAndShowButtonY, (int)SettingsMenuProps::HideAndShowButtonW + 18, (int)SettingsMenuProps::HideAndShowButtonH);
//    }
//    else if (gLanguage == Languages::Russian)
//    {
//        _bgImageTextLabel->setText("Фоновое изображение");
//        _pieceSetsTextLabel->setText("Фигуры");
//        _boardTextLabel->setText("Доска");
//        _languageTextLabel->setText("Язык");
//        _soundTextLabel->setText("Включить звук");
//        _themeTextLabel->setText("Чёрная тема");
//        _cancelPushButton->setText("Отмена");
//        _savePushButton->setText("Сохранить");
//        _hideAndShowButton->setText("Скрыть");
//        _hideAndShowButton->setGeometry((int)SettingsMenuProps::HideAndShowButtonX - 11, (int)SettingsMenuProps::HideAndShowButtonY, (int)SettingsMenuProps::HideAndShowButtonW + 11, (int)SettingsMenuProps::HideAndShowButtonH);
//    }
//    else // English US
//    {
//        _bgImageTextLabel->setText("Background Image");
//        _pieceSetsTextLabel->setText("Piece Set");
//        _boardTextLabel->setText("Board");
//        _languageTextLabel->setText("Language");
//        _soundTextLabel->setText("Play Sounds");
//        _themeTextLabel->setText("Dark Theme");
//        _cancelPushButton->setText("Cancel");
//        _savePushButton->setText("Save");
//        _hideAndShowButton->setText("Hide");
//        _hideAndShowButton->setGeometry((int)SettingsMenuProps::HideAndShowButtonX, (int)SettingsMenuProps::HideAndShowButtonY, (int)SettingsMenuProps::HideAndShowButtonW, (int)SettingsMenuProps::HideAndShowButtonH);
//    }
//}

// Private functions
void SettingsMenu::makeSettingsMenu(MainWindow* mainWindow)
{
    // Background label
    ::setStyleSheetByTheme(_bgLabel, StylesPaths::lightThemeBgLabelStyle, StylesPaths::darkThemeBgLabelStyle, _tempData.isDarkTheme);
    _bgLabel->setGeometry((int)SettingsMenuProps::BgLabelX, (int)SettingsMenuProps::BgLabelY, (int)SettingsMenuProps::BgLabelW, (int)SettingsMenuProps::BgLabelH);

    // Board label
    _boardLabel->setPixmap(QPixmap(ImagesPaths::SettingsBoardsPath + "board" + _tempData. + ".png"));
    _boardLabel->move((int)SettingsMenuProps::BoardLabelX, (int)SettingsMenuProps::BoardLabelY);

    // Pieces label
    _piecesLabel->setPixmap(QPixmap(ImagesPaths::settingsPiecesSetsPath + PieceSets::Cburnett + ".png"));
    _piecesLabel->move((int)SettingsMenuProps::BoardLabelX, (int)SettingsMenuProps::BoardLabelY);

    // Text for background image
    _bgImageTextLabel->setGeometry((int)SettingsMenuProps::BkgImageTextLabelX, (int)SettingsMenuProps::BkgImageTextLabelY, (int)SettingsMenuProps::BkgImageTextLabelW, (int)SettingsMenuProps::BkgImageTextLabelH);
    _bgImageTextLabel->setText("Background Image");
    ::setStyleSheetByTheme(StylesPaths::lightTextStyle, StylesPaths::darkBoldTextStyle, _bgImageTextLabel, _settingsData.isDarkTheme);

    // Background image combobox
    _bgImageComboBox->setGeometry((int)SettingsMenuProps::BkgImageComboBoxX, (int)SettingsMenuProps::BkgImageComboBoxY, (int)SettingsMenuProps::BkgImageComboBoxW, (int)SettingsMenuProps::BkgImageComboBoxH);
    ::setStyleSheetByTheme(StylesPaths::lightComboBoxStyle, StylesPaths::darkComboBoxStyle, _bgImageComboBox, _settingsData.isDarkTheme);
    _bgImageComboBox->addItem(removeUnderscoreInString(BackgroundImages::AngelView));
    _bgImageComboBox->addItem(removeUnderscoreInString(BackgroundImages::Blacked));
    _bgImageComboBox->addItem(removeUnderscoreInString(BackgroundImages::BravePawn));
    _bgImageComboBox->addItem(removeUnderscoreInString(BackgroundImages::Checkmate));
    _bgImageComboBox->addItem(removeUnderscoreInString(BackgroundImages::Dark_Chess));
    _bgImageComboBox->addItem(removeUnderscoreInString(BackgroundImages::Emperors));
    _bgImageComboBox->addItem(removeUnderscoreInString(BackgroundImages::FaceToFace));
    _bgImageComboBox->addItem(removeUnderscoreInString(BackgroundImages::IAmTheKing));
    _bgImageComboBox->addItem(removeUnderscoreInString(BackgroundImages::Landscape));
    _bgImageComboBox->addItem(removeUnderscoreInString(BackgroundImages::Legends));
    _bgImageComboBox->addItem(removeUnderscoreInString(BackgroundImages::Shadow));
    _bgImageComboBox->addItem(removeUnderscoreInString(BackgroundImages::StrongKnight));
    _bgImageComboBox->addItem(removeUnderscoreInString(BackgroundImages::TheBishop));
    _bgImageComboBox->addItem(removeUnderscoreInString(BackgroundImages::TheKing));
    _bgImageComboBox->addItem(removeUnderscoreInString(BackgroundImages::TheKnight));
    _bgImageComboBox->addItem(removeUnderscoreInString(BackgroundImages::TheQueen));
    _bgImageComboBox->addItem(removeUnderscoreInString(BackgroundImages::TheRook));
    _bgImageComboBox->addItem(removeUnderscoreInString(BackgroundImages::TopView));
    _bgImageComboBox->setCurrentIndex((int)BackgroundImagesNumbers::TheRook);
    connect(_bgImageComboBox, &QComboBox::currentIndexChanged, this, &SettingsMenu::bkgImageComboBoxIndexChanged);

    // Text for piece sets
    _pieceSetsTextLabel->setGeometry((int)SettingsMenuProps::PieceSetTextLabelX, (int)SettingsMenuProps::PieceSetTextLabelY, (int)SettingsMenuProps::PieceSetTextLabelW, (int)SettingsMenuProps::PieceSetTextLabelH);
    _pieceSetsTextLabel->setText("Piece Set");
    ::setStyleSheetByTheme(StylesPaths::lightTextStyle, StylesPaths::darkBoldTextStyle, _pieceSetsTextLabel, _settingsData.isDarkTheme);

    // Piece sets combobox
    _pieceSetsComboBox->setGeometry((int)SettingsMenuProps::PieceSetComboBoxX, (int)SettingsMenuProps::PieceSetComboBoxY, (int)SettingsMenuProps::PieceSetComboBoxW, (int)SettingsMenuProps::PieceSetComboBoxH);
    ::setStyleSheetByTheme(StylesPaths::lightComboBoxStyle, StylesPaths::darkComboBoxStyle, _pieceSetsComboBox, _settingsData.isDarkTheme);
    _pieceSetsComboBox->addItem(removeUnderscoreInString(PieceSets::Alpha));
    _pieceSetsComboBox->addItem(removeUnderscoreInString(PieceSets::California));
    _pieceSetsComboBox->addItem(removeUnderscoreInString(PieceSets::Cardinal));
    _pieceSetsComboBox->addItem(removeUnderscoreInString(PieceSets::Cases));
    _pieceSetsComboBox->addItem(removeUnderscoreInString(PieceSets::Cburnett));
    _pieceSetsComboBox->addItem(removeUnderscoreInString(PieceSets::Chess7));
    _pieceSetsComboBox->addItem(removeUnderscoreInString(PieceSets::Condal));
    _pieceSetsComboBox->addItem(removeUnderscoreInString(PieceSets::Fresca));
    _pieceSetsComboBox->addItem(removeUnderscoreInString(PieceSets::GameRoom));
    _pieceSetsComboBox->addItem(removeUnderscoreInString(PieceSets::Glass));
    _pieceSetsComboBox->addItem(removeUnderscoreInString(PieceSets::ICPieces));
    _pieceSetsComboBox->addItem(removeUnderscoreInString(PieceSets::Lolz));
    _pieceSetsComboBox->addItem(removeUnderscoreInString(PieceSets::Maestro));
    _pieceSetsComboBox->addItem(removeUnderscoreInString(PieceSets::Merida));
    _pieceSetsComboBox->addItem(removeUnderscoreInString(PieceSets::Neo));
    _pieceSetsComboBox->addItem(removeUnderscoreInString(PieceSets::Ocean));
    _pieceSetsComboBox->setCurrentIndex((int)PieceSetsNumber::Cburnett);
    connect(_pieceSetsComboBox, &QComboBox::currentIndexChanged, this, &SettingsMenu::pieceSetsComboBoxIndexChanged);

    // Text for board
    _boardTextLabel->setGeometry((int)SettingsMenuProps::BoardTextLabelX, (int)SettingsMenuProps::BoardTextLabelY, (int)SettingsMenuProps::BoardTextLabelW, (int)SettingsMenuProps::BoardTextLabelH);
    _boardTextLabel->setText("Board");
    ::setStyleSheetByTheme(StylesPaths::lightTextStyle, StylesPaths::darkBoldTextStyle, _boardTextLabel, _settingsData.isDarkTheme);

    // Board combobox
    _boardComboBox->setGeometry((int)SettingsMenuProps::BoardComboBoxX, (int)SettingsMenuProps::BoardComboBoxY, (int)SettingsMenuProps::BoardComboBoxW, (int)SettingsMenuProps::BoardComboBoxH);
    ::setStyleSheetByTheme(StylesPaths::lightComboBoxStyle, StylesPaths::darkComboBoxStyle, _boardComboBox, _settingsData.isDarkTheme);
    _boardComboBox->addItem(removeUnderscoreInString(Boards::Bit8));
    _boardComboBox->addItem(removeUnderscoreInString(Boards::Bases));
    _boardComboBox->addItem(removeUnderscoreInString(Boards::Blue));
    _boardComboBox->addItem(removeUnderscoreInString(Boards::Brown));
    _boardComboBox->addItem(removeUnderscoreInString(Boards::Bubblegum));
    _boardComboBox->addItem(removeUnderscoreInString(Boards::BurledWood));
    _boardComboBox->addItem(removeUnderscoreInString(Boards::DarkWood));
    _boardComboBox->addItem(removeUnderscoreInString(Boards::Dash));
    _boardComboBox->addItem(removeUnderscoreInString(Boards::Glass));
    _boardComboBox->addItem(removeUnderscoreInString(Boards::Graffiti));
    _boardComboBox->addItem(removeUnderscoreInString(Boards::Green));
    _boardComboBox->addItem(removeUnderscoreInString(Boards::IcySea));
    _boardComboBox->addItem(removeUnderscoreInString(Boards::Light));
    _boardComboBox->addItem(removeUnderscoreInString(Boards::Lolz));
    _boardComboBox->addItem(removeUnderscoreInString(Boards::Marble));
    _boardComboBox->addItem(removeUnderscoreInString(Boards::Metal));
    _boardComboBox->addItem(removeUnderscoreInString(Boards::Neon));
    _boardComboBox->addItem(removeUnderscoreInString(Boards::Newspaper));
    _boardComboBox->addItem(removeUnderscoreInString(Boards::Orange));
    _boardComboBox->addItem(removeUnderscoreInString(Boards::Parchment));
    _boardComboBox->addItem(removeUnderscoreInString(Boards::Purple));
    _boardComboBox->addItem(removeUnderscoreInString(Boards::Red));
    _boardComboBox->addItem(removeUnderscoreInString(Boards::Sand));
    _boardComboBox->addItem(removeUnderscoreInString(Boards::Sky));
    _boardComboBox->addItem(removeUnderscoreInString(Boards::Stone));
    _boardComboBox->addItem(removeUnderscoreInString(Boards::Tan));
    _boardComboBox->addItem(removeUnderscoreInString(Boards::Tournament));
    _boardComboBox->addItem(removeUnderscoreInString(Boards::Translucent));
    _boardComboBox->addItem(removeUnderscoreInString(Boards::Walnut));
    _boardComboBox->setCurrentIndex((int)BoardsNumber::Brown);
    connect(_boardComboBox, &QComboBox::currentIndexChanged, this, &SettingsMenu::boardComboBoxIndexChanged);

    // Text for language
    _languageTextLabel->setGeometry((int)SettingsMenuProps::LanguageTextLabelX, (int)SettingsMenuProps::LanguageTextLabelY, (int)SettingsMenuProps::LanguageTextLabelW, (int)SettingsMenuProps::LanguageTextLabelH);
    _languageTextLabel->setText("Language");
    ::setStyleSheetByTheme(StylesPaths::lightTextStyle, StylesPaths::darkBoldTextStyle, _languageTextLabel, _settingsData.isDarkTheme);

    // Language combobox
    _languageComboBox->setGeometry((int)SettingsMenuProps::LanguageComboBoxX, (int)SettingsMenuProps::LanguageComboBoxY, (int)SettingsMenuProps::LanguageComboBoxW, (int)SettingsMenuProps::LanguageComboBoxH);
    ::setStyleSheetByTheme(StylesPaths::lightComboBoxStyle, StylesPaths::darkComboBoxStyle, _languageComboBox, _settingsData.isDarkTheme);
    _languageComboBox->addItem(Languages::Armenian);
    _languageComboBox->addItem(Languages::Russian);
    _languageComboBox->addItem(Languages::English);
    _languageComboBox->setCurrentIndex(2);
    connect(_languageComboBox, &QComboBox::currentIndexChanged, this, &SettingsMenu::languageComboBoxIndexChanged);

    // Text for sound
    _soundTextLabel->setGeometry((int)SettingsMenuProps::SoundTextLabelX, (int)SettingsMenuProps::SoundTextLabelY, (int)SettingsMenuProps::SoundTextLabelW, (int)SettingsMenuProps::SoundTextLabelH);
    _soundTextLabel->setText("Play Sounds");
    ::setStyleSheetByTheme(StylesPaths::lightTextStyle, StylesPaths::darkBoldTextStyle, _soundTextLabel, _settingsData.isDarkTheme);

    // Sound toggle switch
    _soundToggleSwitch->move((int)SettingsMenuProps::SoundToggleSwitchX, (int)SettingsMenuProps::SoundToggleSwitchY);
    _soundToggleSwitch->setChecked(gSound);
    connect(_soundToggleSwitch, &QCheckBox::clicked, this, &SettingsMenu::swapSound);

    // Text for theme
    _themeTextLabel->setGeometry((int)SettingsMenuProps::ThemeTextLabelX, (int)SettingsMenuProps::ThemeTextLabelY, (int)SettingsMenuProps::ThemeTextLabelW, (int)SettingsMenuProps::ThemeTextLabelH);
    _themeTextLabel->setText("Dark theme");
    ::setStyleSheetByTheme(StylesPaths::lightTextStyle, StylesPaths::darkBoldTextStyle, _themeTextLabel, _settingsData.isDarkTheme);

    // Theme toggle switch
    _themeToggleSwitch->move((int)SettingsMenuProps::ThemeToggleSwitchX, (int)SettingsMenuProps::ThemeToggleSwitchY);
    _themeToggleSwitch->setChecked(_settingsData.isDarkTheme);
    connect(_themeToggleSwitch, &QCheckBox::clicked, this, &SettingsMenu::swapMenuTheme);

    // Buttons background label
    ::setStyleSheetByTheme(StylesPaths::lightThemeButtonsLabelStyle, StylesPaths::darkThemeButtonsLabelStyle, _buttonsBgLabel, _settingsData.isDarkTheme);
    _buttonsBgLabel->setGeometry((int)SettingsMenuProps::ButtonsBkgLabelX, (int)SettingsMenuProps::ButtonsBkgLabelY, (int)SettingsMenuProps::ButtonsBkgLabelW, (int)SettingsMenuProps::ButtonsBkgLabelH);

    // Cancel push button
    ::setStyleSheetByTheme(StylesPaths::settingsMenuLightCancelButtonStyle, StylesPaths::settingsMenuDarkCancelButtonStyle, _cancelPushButton, _settingsData.isDarkTheme);
    _cancelPushButton->setText("Cancel");
    _cancelPushButton->setGeometry((int)SettingsMenuProps::CancelButtonX, (int)SettingsMenuProps::CancelButtonY, (int)SettingsMenuProps::CancelButtonW, (int)SettingsMenuProps::CancelButtonH);

    // Save push button
    ::setStyleSheet(StylesPaths::settingsMenuSaveButtonStyle, _savePushButton);
    _savePushButton->setText("Save");
    _savePushButton->setGeometry((int)SettingsMenuProps::SaveButtonX, (int)SettingsMenuProps::SaveButtonY, (int)SettingsMenuProps::SaveButtonW, (int)SettingsMenuProps::SaveButtonH);

    // Menu hide and show button
    ::setStyleSheet(StylesPaths::hideAndShowButtonStyle, _hideAndShowButton);
    _hideAndShowButton->setText("Hide");
    _hideAndShowButton->setGeometry((int)SettingsMenuProps::HideAndShowButtonX, (int)SettingsMenuProps::HideAndShowButtonY, (int)SettingsMenuProps::HideAndShowButtonW, (int)SettingsMenuProps::HideAndShowButtonH);
    connect(_hideAndShowButton, &QPushButton::clicked, this, &SettingsMenu::hideAndShowMenu);
}

//void SettingsMenu::hideAndShowMenu()
//{
//    if (_isMenuVisible)
//    {
//        _bgLabel->hide();
//        _boardLabel->hide();
//        _piecesLabel->hide();

//        // Background image
//        _bgImageTextLabel->hide();
//        _bgImageComboBox->hide();

//        // Piece sets
//        _pieceSetsTextLabel->hide();
//        _pieceSetsComboBox->hide();

//        // Board
//        _boardTextLabel->hide();
//        _boardComboBox->hide();

//        // Language
//        _languageTextLabel->hide();
//        _languageComboBox->hide();

//        // Sound
//        _soundTextLabel->hide();
//        _soundToggleSwitch->hide();

//        // Theme
//        _themeTextLabel->hide();
//        _themeToggleSwitch->hide();

//        // Buttons background label
//        _buttonsBgLabel->hide();

//        // Confirm Buttons
//        _cancelPushButton->hide();
//        _savePushButton->hide();

//        // Menu hide and show button
//        if (gLanguage == Languages::Armenian)
//        {
//            _hideAndShowButton->setText("Ցուցադրել");
//            _hideAndShowButton->setGeometry((int)SettingsMenuProps::HideAndShowButtonX - 27, (int)SettingsMenuProps::HideAndShowButtonY, (int)SettingsMenuProps::HideAndShowButtonW + 27, (int)SettingsMenuProps::HideAndShowButtonH);
//        }
//        else if (gLanguage == Languages::Russian)
//        {
//            _hideAndShowButton->setText("Показать");
//            _hideAndShowButton->setGeometry((int)SettingsMenuProps::HideAndShowButtonX - 18, (int)SettingsMenuProps::HideAndShowButtonY, (int)SettingsMenuProps::HideAndShowButtonW + 18, (int)SettingsMenuProps::HideAndShowButtonH);
//        }
//        else // English US
//        {
//            _hideAndShowButton->setText("Show");
//            _hideAndShowButton->setGeometry((int)SettingsMenuProps::HideAndShowButtonX, (int)SettingsMenuProps::HideAndShowButtonY, (int)SettingsMenuProps::HideAndShowButtonW, (int)SettingsMenuProps::HideAndShowButtonH);
//        }
//        _isMenuVisible = false;
//    }
//    else
//    {
//        _bgLabel->show();
//        _boardLabel->show();
//        _piecesLabel->show();

//        // Background image
//        _bgImageTextLabel->show();
//        _bgImageComboBox->show();

//        // Piece sets
//        _pieceSetsTextLabel->show();
//        _pieceSetsComboBox->show();

//        // Board
//        _boardTextLabel->show();
//        _boardComboBox->show();

//        // Language
//        _languageTextLabel->show();
//        _languageComboBox->show();

//        // Sound
//        _soundTextLabel->show();
//        _soundToggleSwitch->show();

//        // Theme
//        _themeTextLabel->show();
//        _themeToggleSwitch->show();

//        // Buttons background label
//        _buttonsBgLabel->show();

//        // Confirm Buttons
//        _cancelPushButton->show();
//        _savePushButton->show();

//        // Menu hide and show button
//        if (gLanguage == Languages::Armenian)
//        {
//            _hideAndShowButton->setText("Թաքցնել");
//            _hideAndShowButton->setGeometry((int)SettingsMenuProps::HideAndShowButtonX - 18, (int)SettingsMenuProps::HideAndShowButtonY, (int)SettingsMenuProps::HideAndShowButtonW + 18, (int)SettingsMenuProps::HideAndShowButtonH);
//        }
//        else if (gLanguage == Languages::Russian)
//        {
//            _hideAndShowButton->setText("Скрыть");
//            _hideAndShowButton->setGeometry((int)SettingsMenuProps::HideAndShowButtonX - 11, (int)SettingsMenuProps::HideAndShowButtonY, (int)SettingsMenuProps::HideAndShowButtonW + 11, (int)SettingsMenuProps::HideAndShowButtonH);
//        }
//        else // English US
//        {
//            _hideAndShowButton->setText("Hide");
//            _hideAndShowButton->setGeometry((int)SettingsMenuProps::HideAndShowButtonX, (int)SettingsMenuProps::HideAndShowButtonY, (int)SettingsMenuProps::HideAndShowButtonW, (int)SettingsMenuProps::HideAndShowButtonH);
//        }
//        _isMenuVisible = true;
//    }
//}

//void SettingsMenu::changeMenuTheme()
//{
//    // Background label
//    ::setStyleSheetByTheme(StylesPaths::lightThemeBkgLabelStyle, StylesPaths::darkThemeBkgLabelStyle, _bgLabel, globalIsDarkTheme);

//    // Text for background image
//    ::setStyleSheetByTheme(StylesPaths::lightTextStyle, StylesPaths::darkBoldTextStyle, _bgImageTextLabel, globalIsDarkTheme);

//    // Background image combobox
//    ::setStyleSheetByTheme(StylesPaths::lightComboBoxStyle, StylesPaths::darkComboBoxStyle, _bgImageComboBox, globalIsDarkTheme);

//    // Text for piece sets
//    ::setStyleSheetByTheme(StylesPaths::lightTextStyle, StylesPaths::darkBoldTextStyle, _pieceSetsTextLabel, globalIsDarkTheme);

//    // Piece sets combobox
//    ::setStyleSheetByTheme(StylesPaths::lightComboBoxStyle, StylesPaths::darkComboBoxStyle, _pieceSetsComboBox, globalIsDarkTheme);

//    // Text for board
//    ::setStyleSheetByTheme(StylesPaths::lightTextStyle, StylesPaths::darkBoldTextStyle, _boardTextLabel, globalIsDarkTheme);

//    // Board combobox
//    ::setStyleSheetByTheme(StylesPaths::lightComboBoxStyle, StylesPaths::darkComboBoxStyle, _boardComboBox, globalIsDarkTheme);

//    // Text for language
//    ::setStyleSheetByTheme(StylesPaths::lightTextStyle, StylesPaths::darkBoldTextStyle, _languageTextLabel, globalIsDarkTheme);

//    // Language combobox
//    ::setStyleSheetByTheme(StylesPaths::lightComboBoxStyle, StylesPaths::darkComboBoxStyle, _languageComboBox, globalIsDarkTheme);

//    // Text for sound
//    ::setStyleSheetByTheme(StylesPaths::lightTextStyle, StylesPaths::darkBoldTextStyle, _soundTextLabel, globalIsDarkTheme);

//    // Text for theme
//    ::setStyleSheetByTheme(StylesPaths::lightTextStyle, StylesPaths::darkBoldTextStyle, _themeTextLabel, globalIsDarkTheme);

//    // Buttons background label
//    ::setStyleSheetByTheme(StylesPaths::lightThemeButtonsLabelStyle, StylesPaths::darkThemeButtonsLabelStyle, _buttonsBgLabel, globalIsDarkTheme);

//    // Cancel push button
//    ::setStyleSheetByTheme(StylesPaths::settingsMenuLightCancelButtonStyle, StylesPaths::settingsMenuDarkCancelButtonStyle, _cancelPushButton, globalIsDarkTheme);
//}

//// Private slots
//void SettingsMenu::bkgImageComboBoxIndexChanged(int index)
//{
//    _tempData.bkgImageNumber = index;
//    _tempData.bkgImageStr = getBkgStr(index);

//    MainWindow::GetInstance()->setBackgroundImage(_tempData.bkgImageStr);
//}

//void SettingsMenu::pieceSetsComboBoxIndexChanged(int index)
//{
//    QString pieceSet = getPieceSetStr(index);;

//    _tempData.pieceSetNumber = index;
//    _tempData.piecesSetStr = pieceSet;

//    _piecesLabel->setPixmap(QPixmap(ImagesPaths::settingsPiecesSetsPath + pieceSet + PieceSets::Extencion));
//}

//void SettingsMenu::boardComboBoxIndexChanged(int index)
//{
//    QString board = getBoardStr(index);;

//    _tempData.boardNumber = index;
//    _tempData.boardStr = board;

//    _boardLabel->setPixmap(QPixmap(ImagesPaths::settingsBoardsPath + board + PieceSets::Extencion));
//}

//void SettingsMenu::languageComboBoxIndexChanged(int index)
//{
//    _tempData.languageNumber = index;
//    _tempData.languageStr = getLanguageStr(index);
//    gLanguage = _tempData.languageStr;

//    if (gLanguage == Languages::Armenian)
//    {
//        _bgImageTextLabel->setText("Ետնանկար");
//        _pieceSetsTextLabel->setText("Խաղաքարեր");
//        _boardTextLabel->setText("Խաղատախտակ");
//        _languageTextLabel->setText("Լեզու");
//        _soundTextLabel->setText("Ձայն");
//        _themeTextLabel->setText("Սև ֆոն");
//        _cancelPushButton->setText("Չեղարկել");
//        _savePushButton->setText("Պահպանել");
//        _hideAndShowButton->setText("Թաքցնել");
//        _hideAndShowButton->setGeometry((int)SettingsMenuProps::HideAndShowButtonX - 18, (int)SettingsMenuProps::HideAndShowButtonY, (int)SettingsMenuProps::HideAndShowButtonW + 18, (int)SettingsMenuProps::HideAndShowButtonH);
//    }
//    else if (gLanguage == Languages::Russian)
//    {
//        _bgImageTextLabel->setText("Фоновое изображение");
//        _pieceSetsTextLabel->setText("Фигуры");
//        _boardTextLabel->setText("Доска");
//        _languageTextLabel->setText("Язык");
//        _soundTextLabel->setText("Включить звук");
//        _themeTextLabel->setText("Чёрная тема");
//        _cancelPushButton->setText("Отмена");
//        _savePushButton->setText("Сохранить");
//        _hideAndShowButton->setText("Скрыть");
//        _hideAndShowButton->setGeometry((int)SettingsMenuProps::HideAndShowButtonX - 11, (int)SettingsMenuProps::HideAndShowButtonY, (int)SettingsMenuProps::HideAndShowButtonW + 11, (int)SettingsMenuProps::HideAndShowButtonH);
//    }
//    else // English US
//    {
//        _bgImageTextLabel->setText("Background Image");
//        _pieceSetsTextLabel->setText("Piece Set");
//        _boardTextLabel->setText("Board");
//        _languageTextLabel->setText("Language");
//        _soundTextLabel->setText("Play Sounds");
//        _themeTextLabel->setText("Dark Theme");
//        _cancelPushButton->setText("Cancel");
//        _savePushButton->setText("Save");
//        _hideAndShowButton->setText("Hide");
//        _hideAndShowButton->setGeometry((int)SettingsMenuProps::HideAndShowButtonX, (int)SettingsMenuProps::HideAndShowButtonY, (int)SettingsMenuProps::HideAndShowButtonW, (int)SettingsMenuProps::HideAndShowButtonH);
//    }
//}

//void SettingsMenu::swapMenuTheme()
//{
//    if (_tempData.isDarkTheme)
//    {
//        _tempData.isDarkTheme = false;
//        globalIsDarkTheme = false;
//    }
//    else
//    {
//        _tempData.isDarkTheme = true;
//        globalIsDarkTheme = true;
//    }

//    changeMenuTheme();
//}

//void SettingsMenu::swapSound()
//{
//    if (_tempData.isSoundAvailable)
//        _tempData.isSoundAvailable = false;
//    else
//        _tempData.isSoundAvailable = true;
//}
