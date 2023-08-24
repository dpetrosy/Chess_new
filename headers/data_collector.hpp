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
    BgImages getBgImage() const;
    const QString& getBgImageStr() const;
    Languages getLanguage() const;
    const QString& getLanguageStr() const;
    PieceSets getPieceSet() const;
    const QString& getPieceSetStr() const;
    Boards getBoard() const;
    const QString& getBoardStr() const;
    const bool& isSoundOn() const;
    const bool& isDarkTheme() const;

    //Setters
    void setBgImage(BgImages bgImage);
    void setLanguage(Languages language);
    void setPieceSet(PieceSets pieceSet);
    void setBoard(Boards board);
    void setSound(bool isSoundOn);
    void setTheme(bool isDarkTheme);

    QString getBgImageStrByNumber(const BgImages& bgImage) const;
    QString getLanguageStrByNumber(const Languages& language) const;
    QString getPieceSetStrByNumber(const PieceSets& pieceSet) const;
    QString getBoardStrByNumber(const Boards& board) const;

private:
    explicit DataCollector();

    void init();

private:
    // Singleton pattern realization
    static DataCollector* _DataCollector;

    // Settings data
    BgImages   _bgImage;
    QString    _bgImageStr;

    Languages  _language;
    QString    _languageStr;

    PieceSets  _pieceSet;
    QString    _pieceSetStr;

    Boards     _board;
    QString    _boardStr;

    bool       _isSoundOn;
    bool       _isDarkTheme;
};

#endif // DATACOLLECTOR_HPP




