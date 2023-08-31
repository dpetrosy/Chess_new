#ifndef DATACOLLECTOR_HPP
#define DATACOLLECTOR_HPP

#include <QString>

#include "menus_helpers.hpp"

// Singleton pattern used
class DataCollector
{
public:
    // Singleton pattern realization
    DataCollector(DataCollector &other) = delete;
    DataCollector& operator=(const DataCollector&) = delete;
    static DataCollector *GetInstance();
    virtual ~DataCollector();

public:
    // Getters
    const BgImages& getBgImage() const;
    const QString& getBgImageStr() const;
    const Languages& getLanguage() const;
    const QString& getLanguageStr() const;
    const PieceSets& getPieceSet() const;
    const QString& getPieceSetStr() const;
    const Boards& getBoard() const;
    const QString& getBoardStr() const;
    const bool& isSoundOn() const;
    const bool& isDarkTheme() const;

    const GameVariants& getGameVariant() const;
    const bool& isTimeOn() const;
    const int& getGameMinutes() const;
    const int& getGameIncSeconds() const;
    const PlayerColors& getPlayerColor() const;

    //Setters
    void setBgImage(BgImages bgImage);
    void setLanguage(Languages language);
    void setPieceSet(PieceSets pieceSet);
    void setBoard(Boards board);
    void setSound(bool isSoundOn);
    void setTheme(bool isDarkTheme);

    void setGameVariant(GameVariants gameVariant);
    void setTime(bool isTimeOn);
    void setGameMinutes(int gameMinutes);
    void setGameIncSeconds(int gameIncSeconds);
    void setPlayerColor(PlayerColors playerColor);

    // Public functions
    void resetTempData(SettingsData* tempData) const;
    void saveTempData(const SettingsData* const tempData);

private:
    explicit DataCollector();

    void init();

private:
    // Singleton pattern realization
    static DataCollector* _DataCollector;

    // Settings data
    BgImages      _bgImage;
    QString       _bgImageStr;

    Languages     _language;
    QString       _languageStr;

    PieceSets     _pieceSet;
    QString       _pieceSetStr;

    Boards        _board;
    QString       _boardStr;

    bool          _isSoundOn;
    bool          _isDarkTheme;

    // Game data
    GameVariants  _gameVariant;
    bool          _isTimeOn;
    int           _GameMinutes;
    int           _GameIncSeconds;
    PlayerColors  _PlayerColor;
};

#endif // DATACOLLECTOR_HPP
