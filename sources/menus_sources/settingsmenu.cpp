#include <QDebug>

#include "settingsmenu.hpp"
#include "mainwindow.hpp"
#include "toggle_switch.hpp"
#include "data_collector.hpp"
#include "defaults.hpp"
#include "paths.hpp"
#include "utils.hpp"

SettingsMenu::SettingsMenu()
{
    /* Init class members */
    init();

    /* Make SettingsMenu */
    makeSettingsMenu();
}

SettingsMenu::~SettingsMenu()
{
    delete _tempData;

    delete _bgLabel;
    delete _boardLabel;
    delete _piecesLabel;

    /* Background image */
    delete _bgImageTextLabel;
    delete _bgImageComboBox;

    /* Piece sets */
    delete _pieceSetsTextLabel;
    delete _pieceSetsComboBox;

    /* Board */
    delete _boardTextLabel;
    delete _boardComboBox;

    /* Language */
    delete _languageTextLabel;
    delete _languageComboBox;

    /* Sound */
    delete _soundTextLabel;
    delete _soundToggleSwitch;

    /* Theme */
    delete _themeTextLabel;
    delete _themeToggleSwitch;

    /* Buttons background label */
    delete _buttonsBgLabel;

    /* Confirm Buttons */
    delete _savePushButton;
    delete _cancelPushButton;

    /* Menu hide and show button */
    delete _hideAndShowButton;
}

void SettingsMenu::init()
{
    initSettingsData();

    _bgLabel = new QLabel(this);
    _boardLabel = new QLabel(this);
    _piecesLabel = new QLabel(this);

    /* Background image */
    _bgImageTextLabel = new QLabel(this);
    _bgImageComboBox = new QComboBox(this);

    /* Piece sets */
    _pieceSetsTextLabel = new QLabel(this);
    _pieceSetsComboBox = new QComboBox(this);

    /* Board */
    _boardTextLabel = new QLabel(this);
    _boardComboBox = new QComboBox(this);

    /* Language */
    _languageTextLabel = new QLabel(this);
    _languageComboBox = new QComboBox(this);

    /* Sound */
    _soundTextLabel = new QLabel(this);
    _soundToggleSwitch = new ToggleSwitch(this);

    /* Theme */
    _themeTextLabel = new QLabel(this);
    _themeToggleSwitch = new ToggleSwitch(this);

    /* Buttons background label */
    _buttonsBgLabel = new QLabel(this);

    /* Confirm Buttons */
    _savePushButton = new QPushButton(this);
    _cancelPushButton = new QPushButton(this);

    /* Menu hide and show button */
    _isMenuVisible = true;
    _hideAndShowButton = new QPushButton(this);
}

void SettingsMenu::initSettingsData()
{
    _tempData = new SettingsData();
    _tempData->bgImage = DefaultData::BgImage;
    _tempData->board = DefaultData::Board;
    _tempData->pieceSet = DefaultData::PieceSet;
    _tempData->language = DefaultData::Language;
    _tempData->isSoundOn = DefaultData::isSoundOn;
    _tempData->isDarkTheme = DefaultData::isDarkTheme;
}

void SettingsMenu::makeSettingsMenu()
{
    /* Background label */
    setStyleSheetByTheme(_bgLabel, StylesPaths::lightThemeBgLabelStyle, StylesPaths::darkThemeBgLabelStyle, _tempData->isDarkTheme);
    _bgLabel->setGeometry((int)SettingsMenuProps::BgLabelX, (int)SettingsMenuProps::BgLabelY,
                         (int)SettingsMenuProps::BgLabelW, (int)SettingsMenuProps::BgLabelH);

    /* Board label */
    _boardLabel->setPixmap(QPixmap(ImagesPaths::SettingsBoardsPath + DefaultData::BoardStr + BoardsStr::Extencion));
    _boardLabel->move((int)SettingsMenuProps::BoardLabelX, (int)SettingsMenuProps::BoardLabelY);

    /* Pieces label */
    _piecesLabel->setPixmap(QPixmap(ImagesPaths::SettingsPiecesSetsPath + DefaultData::PieceSetStr + PieceSetsStr::Extencion));
    _piecesLabel->move((int)SettingsMenuProps::BoardLabelX, (int)SettingsMenuProps::BoardLabelY);

    /* Text for background image */
    _bgImageTextLabel->setGeometry((int)SettingsMenuProps::BgImageTextLabelX, (int)SettingsMenuProps::BgImageTextLabelY,
                                  (int)SettingsMenuProps::BgImageTextLabelW, (int)SettingsMenuProps::BgImageTextLabelH);
    setStyleSheetByTheme(_bgImageTextLabel, StylesPaths::lightTextStyle, StylesPaths::darkBoldTextStyle, _tempData->isDarkTheme);
    _bgImageTextLabel->setText("Background Image");

    /* Background image combobox */
    _bgImageComboBox->setGeometry((int)SettingsMenuProps::BgImageComboBoxX, (int)SettingsMenuProps::BgImageComboBoxY,
                                 (int)SettingsMenuProps::BgImageComboBoxW, (int)SettingsMenuProps::BgImageComboBoxH);
    setStyleSheetByTheme(_bgImageComboBox, StylesPaths::lightComboBoxStyle, StylesPaths::darkComboBoxStyle, _tempData->isDarkTheme);
    _bgImageComboBox->addItem(BgImagesStr::AngelView);
    _bgImageComboBox->addItem(BgImagesStr::Blacked);
    _bgImageComboBox->addItem(BgImagesStr::BravePawn);
    _bgImageComboBox->addItem(BgImagesStr::Checkmate);
    _bgImageComboBox->addItem(BgImagesStr::Dark_Chess);
    _bgImageComboBox->addItem(BgImagesStr::Emperors);
    _bgImageComboBox->addItem(BgImagesStr::FaceToFace);
    _bgImageComboBox->addItem(BgImagesStr::IAmTheKing);
    _bgImageComboBox->addItem(BgImagesStr::Landscape);
    _bgImageComboBox->addItem(BgImagesStr::Legends);
    _bgImageComboBox->addItem(BgImagesStr::Shadow);
    _bgImageComboBox->addItem(BgImagesStr::StrongKnight);
    _bgImageComboBox->addItem(BgImagesStr::TheBishop);
    _bgImageComboBox->addItem(BgImagesStr::TheKing);
    _bgImageComboBox->addItem(BgImagesStr::TheKnight);
    _bgImageComboBox->addItem(BgImagesStr::TheQueen);
    _bgImageComboBox->addItem(BgImagesStr::TheRook);
    _bgImageComboBox->addItem(BgImagesStr::TopView);
    _bgImageComboBox->setCurrentIndex((int)_tempData->bgImage);
    connect(_bgImageComboBox, &QComboBox::currentIndexChanged, this, &SettingsMenu::bgImageComboBoxIndexChanged);

    /* Text for piece sets */
    _pieceSetsTextLabel->setGeometry((int)SettingsMenuProps::PieceSetTextLabelX, (int)SettingsMenuProps::PieceSetTextLabelY,
                                    (int)SettingsMenuProps::PieceSetTextLabelW, (int)SettingsMenuProps::PieceSetTextLabelH);
    setStyleSheetByTheme(_pieceSetsTextLabel, StylesPaths::lightTextStyle, StylesPaths::darkBoldTextStyle, _tempData->isDarkTheme);
    _pieceSetsTextLabel->setText("Piece Set");

    /* Piece sets combobox */
    _pieceSetsComboBox->setGeometry((int)SettingsMenuProps::PieceSetComboBoxX, (int)SettingsMenuProps::PieceSetComboBoxY,
                                   (int)SettingsMenuProps::PieceSetComboBoxW, (int)SettingsMenuProps::PieceSetComboBoxH);
    setStyleSheetByTheme(_pieceSetsComboBox, StylesPaths::lightComboBoxStyle, StylesPaths::darkComboBoxStyle, _tempData->isDarkTheme);
    _pieceSetsComboBox->addItem(PieceSetsStr::Alpha);
    _pieceSetsComboBox->addItem(PieceSetsStr::California);
    _pieceSetsComboBox->addItem(PieceSetsStr::Cardinal);
    _pieceSetsComboBox->addItem(PieceSetsStr::Cases);
    _pieceSetsComboBox->addItem(PieceSetsStr::Cburnett);
    _pieceSetsComboBox->addItem(PieceSetsStr::Chess7);
    _pieceSetsComboBox->addItem(PieceSetsStr::Condal);
    _pieceSetsComboBox->addItem(PieceSetsStr::Fresca);
    _pieceSetsComboBox->addItem(PieceSetsStr::GameRoom);
    _pieceSetsComboBox->addItem(PieceSetsStr::Glass);
    _pieceSetsComboBox->addItem(PieceSetsStr::ICPieces);
    _pieceSetsComboBox->addItem(PieceSetsStr::Lolz);
    _pieceSetsComboBox->addItem(PieceSetsStr::Maestro);
    _pieceSetsComboBox->addItem(PieceSetsStr::Merida);
    _pieceSetsComboBox->addItem(PieceSetsStr::Neo);
    _pieceSetsComboBox->addItem(PieceSetsStr::Ocean);
    _pieceSetsComboBox->setCurrentIndex((int)_tempData->pieceSet);
    connect(_pieceSetsComboBox, &QComboBox::currentIndexChanged, this, &SettingsMenu::pieceSetsComboBoxIndexChanged);

    /* Text for board */
    _boardTextLabel->setGeometry((int)SettingsMenuProps::BoardTextLabelX, (int)SettingsMenuProps::BoardTextLabelY,
                                (int)SettingsMenuProps::BoardTextLabelW, (int)SettingsMenuProps::BoardTextLabelH);
    setStyleSheetByTheme(_boardTextLabel, StylesPaths::lightTextStyle, StylesPaths::darkBoldTextStyle, _tempData->isDarkTheme);
    _boardTextLabel->setText("Board");

    /* Board combobox */
    _boardComboBox->setGeometry((int)SettingsMenuProps::BoardComboBoxX, (int)SettingsMenuProps::BoardComboBoxY,
                               (int)SettingsMenuProps::BoardComboBoxW, (int)SettingsMenuProps::BoardComboBoxH);
    setStyleSheetByTheme(_boardComboBox, StylesPaths::lightComboBoxStyle, StylesPaths::darkComboBoxStyle, _tempData->isDarkTheme);
    _boardComboBox->addItem(BoardsStr::Bit8);
    _boardComboBox->addItem(BoardsStr::Bases);
    _boardComboBox->addItem(BoardsStr::Blue);
    _boardComboBox->addItem(BoardsStr::Brown);
    _boardComboBox->addItem(BoardsStr::Bubblegum);
    _boardComboBox->addItem(BoardsStr::BurledWood);
    _boardComboBox->addItem(BoardsStr::DarkWood);
    _boardComboBox->addItem(BoardsStr::Dash);
    _boardComboBox->addItem(BoardsStr::Glass);
    _boardComboBox->addItem(BoardsStr::Graffiti);
    _boardComboBox->addItem(BoardsStr::Green);
    _boardComboBox->addItem(BoardsStr::IcySea);
    _boardComboBox->addItem(BoardsStr::Light);
    _boardComboBox->addItem(BoardsStr::Lolz);
    _boardComboBox->addItem(BoardsStr::Marble);
    _boardComboBox->addItem(BoardsStr::Metal);
    _boardComboBox->addItem(BoardsStr::Neon);
    _boardComboBox->addItem(BoardsStr::Newspaper);
    _boardComboBox->addItem(BoardsStr::Orange);
    _boardComboBox->addItem(BoardsStr::Parchment);
    _boardComboBox->addItem(BoardsStr::Purple);
    _boardComboBox->addItem(BoardsStr::Red);
    _boardComboBox->addItem(BoardsStr::Sand);
    _boardComboBox->addItem(BoardsStr::Sky);
    _boardComboBox->addItem(BoardsStr::Stone);
    _boardComboBox->addItem(BoardsStr::Tan);
    _boardComboBox->addItem(BoardsStr::Tournament);
    _boardComboBox->addItem(BoardsStr::Translucent);
    _boardComboBox->addItem(BoardsStr::Walnut);
    _boardComboBox->setCurrentIndex((int)_tempData->board);
    connect(_boardComboBox, &QComboBox::currentIndexChanged, this, &SettingsMenu::boardComboBoxIndexChanged);

    /* Text for language */
    _languageTextLabel->setGeometry((int)SettingsMenuProps::LanguageTextLabelX, (int)SettingsMenuProps::LanguageTextLabelY,
                                   (int)SettingsMenuProps::LanguageTextLabelW, (int)SettingsMenuProps::LanguageTextLabelH);
    setStyleSheetByTheme(_languageTextLabel, StylesPaths::lightTextStyle, StylesPaths::darkBoldTextStyle, _tempData->isDarkTheme);
    _languageTextLabel->setText("Language");

    /* Language combobox */
    _languageComboBox->setGeometry((int)SettingsMenuProps::LanguageComboBoxX, (int)SettingsMenuProps::LanguageComboBoxY,
                                  (int)SettingsMenuProps::LanguageComboBoxW, (int)SettingsMenuProps::LanguageComboBoxH);
    setStyleSheetByTheme(_languageComboBox, StylesPaths::lightComboBoxStyle, StylesPaths::darkComboBoxStyle, _tempData->isDarkTheme);
    _languageComboBox->addItem(LanguagesStr::Armenian);
    _languageComboBox->addItem(LanguagesStr::Russian);
    _languageComboBox->addItem(LanguagesStr::English);
    _languageComboBox->setCurrentIndex((int)_tempData->language);
    connect(_languageComboBox, &QComboBox::currentIndexChanged, this, &SettingsMenu::languageComboBoxIndexChanged);

    /* Text for sound */
    _soundTextLabel->setGeometry((int)SettingsMenuProps::SoundTextLabelX, (int)SettingsMenuProps::SoundTextLabelY,
                                (int)SettingsMenuProps::SoundTextLabelW, (int)SettingsMenuProps::SoundTextLabelH);
    setStyleSheetByTheme(_soundTextLabel, StylesPaths::lightTextStyle, StylesPaths::darkBoldTextStyle, _tempData->isDarkTheme);
    _soundTextLabel->setText("Play Sounds");

    /* Sound toggle switch */
    _soundToggleSwitch->move((int)SettingsMenuProps::SoundToggleSwitchX, (int)SettingsMenuProps::SoundToggleSwitchY);
    connect(_soundToggleSwitch, &QCheckBox::clicked, this, &SettingsMenu::swapSound);
    _soundToggleSwitch->setChecked(_tempData->isSoundOn);

    /* Text for theme */
    _themeTextLabel->setGeometry((int)SettingsMenuProps::ThemeTextLabelX, (int)SettingsMenuProps::ThemeTextLabelY,
                                (int)SettingsMenuProps::ThemeTextLabelW, (int)SettingsMenuProps::ThemeTextLabelH);
    setStyleSheetByTheme(_themeTextLabel, StylesPaths::lightTextStyle, StylesPaths::darkBoldTextStyle, _tempData->isDarkTheme);
    _themeTextLabel->setText("Dark theme");

    /* Theme toggle switch */
    _themeToggleSwitch->move((int)SettingsMenuProps::ThemeToggleSwitchX, (int)SettingsMenuProps::ThemeToggleSwitchY);
    _themeToggleSwitch->setChecked(_tempData->isDarkTheme);
    connect(_themeToggleSwitch, &QCheckBox::clicked, this, &SettingsMenu::swapMenuTheme);

    /* Buttons background label */
    _buttonsBgLabel->setGeometry((int)SettingsMenuProps::ButtonsBgLabelX, (int)SettingsMenuProps::ButtonsBgLabelY,
                                (int)SettingsMenuProps::ButtonsBgLabelW, (int)SettingsMenuProps::ButtonsBgLabelH);
    setStyleSheetByTheme(_buttonsBgLabel, StylesPaths::lightThemeButtonsLabelStyle,
                  StylesPaths::darkThemeButtonsLabelStyle, _tempData->isDarkTheme);

    /* Save push button */
    _savePushButton->setGeometry((int)SettingsMenuProps::SaveButtonX, (int)SettingsMenuProps::SaveButtonY,
                                (int)SettingsMenuProps::SaveButtonW, (int)SettingsMenuProps::SaveButtonH);
    ::setStyleSheet(_savePushButton, StylesPaths::settingsMenuSaveButtonStyle);
    _savePushButton->setText("Save");
    connect(_savePushButton, &QPushButton::clicked, this, &SettingsMenu::saveButtonClicked);

    /* Cancel push button */
    _cancelPushButton->setGeometry((int)SettingsMenuProps::CancelButtonX, (int)SettingsMenuProps::CancelButtonY,
                                  (int)SettingsMenuProps::CancelButtonW, (int)SettingsMenuProps::CancelButtonH);
    setStyleSheetByTheme(_cancelPushButton, StylesPaths::settingsMenuLightCancelButtonStyle,
                    StylesPaths::settingsMenuDarkCancelButtonStyle, _tempData->isDarkTheme);
    _cancelPushButton->setText("Cancel");
    connect(_cancelPushButton, &QPushButton::clicked, this, &SettingsMenu::cancelButtonClicked);

    /* Menu hide and show button */
    _hideAndShowButton->setGeometry((int)SettingsMenuProps::HideAndShowButtonX, (int)SettingsMenuProps::HideAndShowButtonY,
                                   (int)SettingsMenuProps::HideAndShowButtonW, (int)SettingsMenuProps::HideAndShowButtonH);
    connect(_hideAndShowButton, &QPushButton::clicked, this, &SettingsMenu::hideAndShowMenu);
    ::setStyleSheet(_hideAndShowButton, StylesPaths::hideAndShowButtonStyle);
    _hideAndShowButton->setText("Hide");
}

/* Public functions */
void SettingsMenu::makeMenuBeforeSwitch()
{
    QString image;

    /* Background image */
    _bgImageComboBox->setCurrentIndex((int)_tempData->bgImage);

    /* Piece set */
    image = replaceSpaceInString(getPieceSetStrByNumber(_tempData->pieceSet));
    _piecesLabel->setPixmap(QPixmap(ImagesPaths::SettingsPiecesSetsPath + image + PieceSetsStr::Extencion));
    _pieceSetsComboBox->setCurrentIndex((int)_tempData->pieceSet);

    /* Board */
    image = replaceSpaceInString(getBoardStrByNumber(_tempData->board));
    _boardLabel->setPixmap(QPixmap(ImagesPaths::SettingsBoardsPath + image + BoardsStr::Extencion));
    _boardComboBox->setCurrentIndex((int)_tempData->board);

    /* Language */
    _languageComboBox->setCurrentIndex((int)_tempData->language);

    /* Sound */
    _soundToggleSwitch->setChecked(_tempData->isSoundOn);

    /* Theme */
    _themeToggleSwitch->setChecked(_tempData->isDarkTheme);
    changeMenuTheme();

    if (_tempData->language == Languages::Armenian)
    {
        _bgImageTextLabel->setText("Ետնանկար");
        _pieceSetsTextLabel->setText("Խաղաքարեր");
        _boardTextLabel->setText("Խաղատախտակ");
        _languageTextLabel->setText("Լեզու");
        _soundTextLabel->setText("Ձայն");
        _themeTextLabel->setText("Սև ֆոն");
        _cancelPushButton->setText("Չեղարկել");
        _savePushButton->setText("Պահպանել");
        _hideAndShowButton->setText("Թաքցնել");
        _hideAndShowButton->setGeometry((int)SettingsMenuProps::HideAndShowButtonX - 18, (int)SettingsMenuProps::HideAndShowButtonY,
                                       (int)SettingsMenuProps::HideAndShowButtonW + 18, (int)SettingsMenuProps::HideAndShowButtonH);
    }
    else if (_tempData->language == Languages::Russian)
    {
        _bgImageTextLabel->setText("Фоновое изображение");
        _pieceSetsTextLabel->setText("Фигуры");
        _boardTextLabel->setText("Доска");
        _languageTextLabel->setText("Язык");
        _soundTextLabel->setText("Включить звук");
        _themeTextLabel->setText("Чёрная тема");
        _cancelPushButton->setText("Отмена");
        _savePushButton->setText("Сохранить");
        _hideAndShowButton->setText("Скрыть");
        _hideAndShowButton->setGeometry((int)SettingsMenuProps::HideAndShowButtonX - 11, (int)SettingsMenuProps::HideAndShowButtonY,
                                       (int)SettingsMenuProps::HideAndShowButtonW + 11, (int)SettingsMenuProps::HideAndShowButtonH);
    }
    else /* English */
    {
        _bgImageTextLabel->setText("Background Image");
        _pieceSetsTextLabel->setText("Piece Set");
        _boardTextLabel->setText("Board");
        _languageTextLabel->setText("Language");
        _soundTextLabel->setText("Play Sounds");
        _themeTextLabel->setText("Dark Theme");
        _cancelPushButton->setText("Cancel");
        _savePushButton->setText("Save");
        _hideAndShowButton->setText("Hide");
        _hideAndShowButton->setGeometry((int)SettingsMenuProps::HideAndShowButtonX, (int)SettingsMenuProps::HideAndShowButtonY,
                                       (int)SettingsMenuProps::HideAndShowButtonW, (int)SettingsMenuProps::HideAndShowButtonH);
    }
}

/* Private slots */
void SettingsMenu::bgImageComboBoxIndexChanged(int index)
{
    _tempData->bgImage = static_cast<BgImages>(index);
    MainWindow::GetInstance()->setBackgroundImage(_tempData->bgImage);
}

void SettingsMenu::pieceSetsComboBoxIndexChanged(int index)
{
    _tempData->pieceSet = static_cast<PieceSets>(index);

    QString image = getPieceSetStrByNumber(_tempData->pieceSet);
    image = replaceSpaceInString(image);
    _piecesLabel->setPixmap(QPixmap(ImagesPaths::SettingsPiecesSetsPath + image + PieceSetsStr::Extencion));
}

void SettingsMenu::boardComboBoxIndexChanged(int index)
{
    _tempData->board = static_cast<Boards>(index);

    QString image = getBoardStrByNumber(_tempData->board);
    image = replaceSpaceInString(image);
    _boardLabel->setPixmap(QPixmap(ImagesPaths::SettingsBoardsPath + image + BoardsStr::Extencion));
}

void SettingsMenu::languageComboBoxIndexChanged(int index)
{
    _tempData->language = static_cast<Languages>(index);

    if (_tempData->language == Languages::Armenian)
    {
        _bgImageTextLabel->setText("Ետնանկար");
        _pieceSetsTextLabel->setText("Խաղաքարեր");
        _boardTextLabel->setText("Խաղատախտակ");
        _languageTextLabel->setText("Լեզու");
        _soundTextLabel->setText("Ձայն");
        _themeTextLabel->setText("Սև ֆոն");
        _cancelPushButton->setText("Չեղարկել");
        _savePushButton->setText("Պահպանել");
        _hideAndShowButton->setText("Թաքցնել");
        _hideAndShowButton->setGeometry((int)SettingsMenuProps::HideAndShowButtonX - 18, (int)SettingsMenuProps::HideAndShowButtonY,
                                        (int)SettingsMenuProps::HideAndShowButtonW + 18, (int)SettingsMenuProps::HideAndShowButtonH);
    }
    else if (_tempData->language == Languages::Russian)
    {
        _bgImageTextLabel->setText("Фоновое изображение");
        _pieceSetsTextLabel->setText("Фигуры");
        _boardTextLabel->setText("Доска");
        _languageTextLabel->setText("Язык");
        _soundTextLabel->setText("Включить звук");
        _themeTextLabel->setText("Чёрная тема");
        _cancelPushButton->setText("Отмена");
        _savePushButton->setText("Сохранить");
        _hideAndShowButton->setText("Скрыть");
        _hideAndShowButton->setGeometry((int)SettingsMenuProps::HideAndShowButtonX - 11, (int)SettingsMenuProps::HideAndShowButtonY,
                                        (int)SettingsMenuProps::HideAndShowButtonW + 11, (int)SettingsMenuProps::HideAndShowButtonH);
    }
    else /* English US */
    {
        _bgImageTextLabel->setText("Background Image");
        _pieceSetsTextLabel->setText("Piece Set");
        _boardTextLabel->setText("Board");
        _languageTextLabel->setText("Language");
        _soundTextLabel->setText("Play Sounds");
        _themeTextLabel->setText("Dark Theme");
        _cancelPushButton->setText("Cancel");
        _savePushButton->setText("Save");
        _hideAndShowButton->setText("Hide");
        _hideAndShowButton->setGeometry((int)SettingsMenuProps::HideAndShowButtonX, (int)SettingsMenuProps::HideAndShowButtonY,
                                        (int)SettingsMenuProps::HideAndShowButtonW, (int)SettingsMenuProps::HideAndShowButtonH);
    }
}

void SettingsMenu::swapSound()
{
    _tempData->isSoundOn = !_tempData->isSoundOn;
}

void SettingsMenu::swapMenuTheme()
{
    _tempData->isDarkTheme = !_tempData->isDarkTheme;
    changeMenuTheme();
}

void SettingsMenu::saveButtonClicked()
{
    auto dataCollector = DataCollector::GetInstance();
    dataCollector->saveTempData(_tempData);

    auto mainWindow = MainWindow::GetInstance();
    mainWindow->setBackgroundImage(_tempData->bgImage);
    switchMenu(mainWindow, Menus::MainMenu);
}

void SettingsMenu::cancelButtonClicked()
{
    auto dataCollector = DataCollector::GetInstance();
    dataCollector->resetTempData(_tempData);

    auto mainWindow = MainWindow::GetInstance();
    mainWindow->setBackgroundImage(_tempData->bgImage);
    switchMenu(mainWindow, Menus::MainMenu);
}

void SettingsMenu::hideAndShowMenu()
{
    if (_isMenuVisible)
    {
        _isMenuVisible = false;

        _bgLabel->hide();
        _boardLabel->hide();
        _piecesLabel->hide();

        /* Background image */
        _bgImageTextLabel->hide();
        _bgImageComboBox->hide();

        /* Piece sets */
        _pieceSetsTextLabel->hide();
        _pieceSetsComboBox->hide();

        /* Board */
        _boardTextLabel->hide();
        _boardComboBox->hide();

        /* Language */
        _languageTextLabel->hide();
        _languageComboBox->hide();

        /* Sound */
        _soundTextLabel->hide();
        _soundToggleSwitch->hide();

        /* Theme */
        _themeTextLabel->hide();
        _themeToggleSwitch->hide();

        /* Buttons background label */
        _buttonsBgLabel->hide();

        /* Confirm Buttons */
        _cancelPushButton->hide();
        _savePushButton->hide();

        /* Menu hide and show button */
        if (_tempData->language == Languages::Armenian)
        {
            _hideAndShowButton->setText("Ցուցադրել");
            _hideAndShowButton->setGeometry((int)SettingsMenuProps::HideAndShowButtonX - 27, (int)SettingsMenuProps::HideAndShowButtonY,
                                           (int)SettingsMenuProps::HideAndShowButtonW + 27, (int)SettingsMenuProps::HideAndShowButtonH);
        }
        else if (_tempData->language == Languages::Russian)
        {
            _hideAndShowButton->setText("Показать");
            _hideAndShowButton->setGeometry((int)SettingsMenuProps::HideAndShowButtonX - 18, (int)SettingsMenuProps::HideAndShowButtonY,
                                           (int)SettingsMenuProps::HideAndShowButtonW + 18, (int)SettingsMenuProps::HideAndShowButtonH);
        }
        else /* English */
        {
            _hideAndShowButton->setText("Show");
            _hideAndShowButton->setGeometry((int)SettingsMenuProps::HideAndShowButtonX, (int)SettingsMenuProps::HideAndShowButtonY,
                                           (int)SettingsMenuProps::HideAndShowButtonW, (int)SettingsMenuProps::HideAndShowButtonH);
        }
    }
    else
    {
        _isMenuVisible = true;

        _bgLabel->show();
        _boardLabel->show();
        _piecesLabel->show();

        /* Background image */
        _bgImageTextLabel->show();
        _bgImageComboBox->show();

        /* Piece sets */
        _pieceSetsTextLabel->show();
        _pieceSetsComboBox->show();

        /* Board */
        _boardTextLabel->show();
        _boardComboBox->show();

        /* Language */
        _languageTextLabel->show();
        _languageComboBox->show();

        /* Sound */
        _soundTextLabel->show();
        _soundToggleSwitch->show();

        /* Theme */
        _themeTextLabel->show();
        _themeToggleSwitch->show();

        /* Buttons background label */
        _buttonsBgLabel->show();

        /* Confirm Buttons */
        _cancelPushButton->show();
        _savePushButton->show();

        /* Menu hide and show button */
        if (_tempData->language == Languages::Armenian)
        {
            _hideAndShowButton->setText("Թաքցնել");
            _hideAndShowButton->setGeometry((int)SettingsMenuProps::HideAndShowButtonX - 18, (int)SettingsMenuProps::HideAndShowButtonY,
                                           (int)SettingsMenuProps::HideAndShowButtonW + 18, (int)SettingsMenuProps::HideAndShowButtonH);
        }
        else if (_tempData->language == Languages::Russian)
        {
            _hideAndShowButton->setText("Скрыть");
            _hideAndShowButton->setGeometry((int)SettingsMenuProps::HideAndShowButtonX - 11, (int)SettingsMenuProps::HideAndShowButtonY,
                                           (int)SettingsMenuProps::HideAndShowButtonW + 11, (int)SettingsMenuProps::HideAndShowButtonH);
        }
        else /* English */
        {
            _hideAndShowButton->setText("Hide");
            _hideAndShowButton->setGeometry((int)SettingsMenuProps::HideAndShowButtonX, (int)SettingsMenuProps::HideAndShowButtonY,
                                           (int)SettingsMenuProps::HideAndShowButtonW, (int)SettingsMenuProps::HideAndShowButtonH);
        }
    }
}

/* Private functions */
void SettingsMenu::changeMenuTheme()
{
    /* Background label */
    setStyleSheetByTheme(_bgLabel, StylesPaths::lightThemeBgLabelStyle, StylesPaths::darkThemeBgLabelStyle, _tempData->isDarkTheme);

    /* Text for background image */
    setStyleSheetByTheme(_bgImageTextLabel, StylesPaths::lightTextStyle, StylesPaths::darkBoldTextStyle, _tempData->isDarkTheme);

    /* Background image combobox */
    setStyleSheetByTheme(_bgImageComboBox, StylesPaths::lightComboBoxStyle, StylesPaths::darkComboBoxStyle, _tempData->isDarkTheme);

    /* Text for piece sets */
    setStyleSheetByTheme(_pieceSetsTextLabel, StylesPaths::lightTextStyle, StylesPaths::darkBoldTextStyle, _tempData->isDarkTheme);

    /* Piece sets combobox */
    setStyleSheetByTheme(_pieceSetsComboBox, StylesPaths::lightComboBoxStyle, StylesPaths::darkComboBoxStyle, _tempData->isDarkTheme);

    /* Text for board */
    setStyleSheetByTheme(_boardTextLabel, StylesPaths::lightTextStyle, StylesPaths::darkBoldTextStyle, _tempData->isDarkTheme);

    /* Board combobox */
    setStyleSheetByTheme(_boardComboBox, StylesPaths::lightComboBoxStyle, StylesPaths::darkComboBoxStyle, _tempData->isDarkTheme);

    /* Text for language */
    setStyleSheetByTheme(_languageTextLabel, StylesPaths::lightTextStyle, StylesPaths::darkBoldTextStyle, _tempData->isDarkTheme);

    /* Language combobox */
    setStyleSheetByTheme(_languageComboBox, StylesPaths::lightComboBoxStyle, StylesPaths::darkComboBoxStyle, _tempData->isDarkTheme);

    /* Text for sound */
    setStyleSheetByTheme(_soundTextLabel, StylesPaths::lightTextStyle, StylesPaths::darkBoldTextStyle, _tempData->isDarkTheme);

    /* Text for theme */
    setStyleSheetByTheme(_themeTextLabel, StylesPaths::lightTextStyle, StylesPaths::darkBoldTextStyle, _tempData->isDarkTheme);

    /* Buttons background label */
    setStyleSheetByTheme(_buttonsBgLabel, StylesPaths::lightThemeButtonsLabelStyle, StylesPaths::darkThemeButtonsLabelStyle, _tempData->isDarkTheme);

    /* Cancel push button */
    setStyleSheetByTheme(_cancelPushButton, StylesPaths::settingsMenuLightCancelButtonStyle, StylesPaths::settingsMenuDarkCancelButtonStyle, _tempData->isDarkTheme);
}
