#include "game_data.hpp"
#include "data_collector.hpp"

GameData::GameData()
{
    init();
}

GameData::~GameData()
{}

/* Singlton pattern realization */
GameData *GameData::_gameData = nullptr;

GameData *GameData::GetInstance()
{
    if(_gameData == nullptr)
        _gameData = new GameData();

    return _gameData;
}

void GameData::init()
{
    syncDataWithDataCollector();
}

/* Public functions */
void GameData::syncDataWithDataCollector()
{
    auto dataCollector = DataCollector::GetInstance();

    /* Settings data */
    pieceSet = dataCollector->getPieceSet();
    pieceSetStr = dataCollector->getPieceSetStr();
    board = dataCollector->getBoard();
    boardStr = dataCollector->getBoardStr();
    isSoundOn = dataCollector->isSoundOn();
    isDarkTheme = dataCollector->isDarkTheme();

    /* Game data */
    gameVariant = dataCollector->getGameVariant();
    isTimeOn = dataCollector->isTimeOn();
    gameMinutes = dataCollector->getGameMinutes();
    gameIncSeconds = dataCollector->getGameIncSeconds();
    playerColor = dataCollector->getPlayerColor();
}
