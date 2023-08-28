#include "data_collector.hpp"
#include "defaults.hpp"
#include "utils.hpp"

DataCollector::DataCollector()
{
    init();
}

DataCollector::~DataCollector()
{}

// Singlton pattern realization
DataCollector *DataCollector::_DataCollector = nullptr;

DataCollector *DataCollector::GetInstance()
{
    if(_DataCollector == nullptr)
        _DataCollector = new DataCollector();

    return _DataCollector;
}

void DataCollector::init()
{
    // Settings data
    _bgImage = DefaultData::BgImage;
    _bgImageStr = DefaultData::BgImageStr;
    _language = DefaultData::Language;
    _languageStr = DefaultData::LanguageStr;
    _pieceSet = DefaultData::PieceSet;
    _pieceSetStr = DefaultData::PieceSetStr;
    _board = DefaultData::Board;
    _boardStr = DefaultData::BoardStr;
    _isSoundOn = DefaultData::isSoundOn;
    _isDarkTheme = DefaultData::isDarkTheme;

    // Game data
    _gameVariant = DefaultData::GameVariant;
    _isTimeOn = DefaultData::isTimeOn;
    _GameMinutes = DefaultData::GameMinutes;
    _GameIncSeconds = DefaultData::GameIncSeconds;
}

// Getters
const BgImages& DataCollector::getBgImage() const
{
    return _bgImage;
}

const QString& DataCollector::getBgImageStr() const
{
    return _bgImageStr;
}

const Languages& DataCollector::getLanguage() const
{
    return _language;
}

const QString& DataCollector::getLanguageStr() const
{
    return _languageStr;
}

const PieceSets& DataCollector::getPieceSet() const
{
    return _pieceSet;
}

const QString& DataCollector::getPieceSetStr() const
{
    return _pieceSetStr;
}

const Boards& DataCollector::getBoard() const
{
    return _board;
}

const QString& DataCollector::getBoardStr() const
{
    return _boardStr;
}

const bool& DataCollector::isSoundOn() const
{
    return _isSoundOn;
}

const bool& DataCollector::isDarkTheme() const
{
    return _isDarkTheme;
}

const GameVariants& DataCollector::getGameVariant() const
{
    return _gameVariant;
}

const bool& DataCollector::isTimeOn() const
{
    return _isTimeOn;
}

const int& DataCollector::getGameMinutes() const
{
    return _GameMinutes;
}

const int& DataCollector::getGameIncSeconds() const
{
    return _GameIncSeconds;
}

//Setters
void DataCollector::setBgImage(BgImages bgImage)
{
    _bgImage = bgImage;
    _bgImageStr = getBgImageStrByNumber(_bgImage);
}

void DataCollector::setLanguage(Languages language)
{
    _language = language;
    _languageStr = getLanguageStrByNumber(_language);
}

void DataCollector::setPieceSet(PieceSets pieceSet)
{
    _pieceSet = pieceSet;
    _pieceSetStr = getPieceSetStrByNumber(_pieceSet);
}

void DataCollector::setBoard(Boards board)
{
    _board = board;
    _boardStr = getBoardStrByNumber(_board);
}

void DataCollector::setSound(bool isSoundOn)
{
    _isSoundOn = isSoundOn;
}

void DataCollector::setTheme(bool isDarkTheme)
{
    _isDarkTheme = isDarkTheme;
}

void DataCollector::setGameVariant(GameVariants gameVariant)
{
    _gameVariant = gameVariant;
}

void DataCollector::setTime(bool isTimeOn)
{
    _isTimeOn = isTimeOn;
}

void DataCollector::setGameMinutes(int gameMinutes)
{
    _GameMinutes = gameMinutes;
}

void DataCollector::setGameIncSeconds(int gameIncSeconds)
{
    _GameIncSeconds = gameIncSeconds;
}

// Public functions
void DataCollector::resetTempData(SettingsData* tempData) const
{
    tempData->bgImage = _bgImage;
    tempData->board = _board;
    tempData->pieceSet = _pieceSet;
    tempData->language = _language;
    tempData->isSoundOn = _isSoundOn;
    tempData->isDarkTheme = _isDarkTheme;
}

void DataCollector::saveTempData(const SettingsData* const tempData)
{
    _bgImage = tempData->bgImage;
    _board = tempData->board;
    _pieceSet = tempData->pieceSet;
    _language = tempData->language;
    _isSoundOn = tempData->isSoundOn;
    _isDarkTheme = tempData->isDarkTheme;
}
