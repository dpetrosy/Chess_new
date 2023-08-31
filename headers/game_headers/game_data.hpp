#ifndef GAME_DATA_HPP
#define GAME_DATA_HPP

#include <QString>

#include "menus_helpers.hpp"

/* Singleton pattern used */
class GameData
{
public:
    /* Singleton pattern realization */
    GameData(GameData& other) = delete;
    GameData& operator=(const GameData&) = delete;
    static GameData* GetInstance();
    virtual ~GameData();

public:
    void syncDataWithDataCollector();

private:
    explicit GameData();

    void init();

private:
    /* Singleton pattern realization */
    static GameData* _gameData;

public:
    /* Settings data */
    PieceSets     pieceSet;
    QString       pieceSetStr;

    Boards        board;
    QString       boardStr;

    bool          isSoundOn;
    bool          isDarkTheme;

    /* Game data */
    GameVariants  gameVariant;
    bool          isTimeOn;
    int           gameMinutes;
    int           gameIncSeconds;
    PlayerColors  playerColor;
};

#endif // GAME_DATA_HPP
