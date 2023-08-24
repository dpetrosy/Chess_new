#include "data_collector.hpp"
#include "defaults.hpp"

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
}

// Getters
BgImages DataCollector::getBgImage() const
{
    return _bgImage;
}

const QString& DataCollector::getBgImageStr() const
{
    return _bgImageStr;
}

Languages DataCollector::getLanguage() const
{
    return _language;
}

const QString& DataCollector::getLanguageStr() const
{
    return _languageStr;
}

PieceSets DataCollector::getPieceSet() const
{
    return _pieceSet;
}

const QString& DataCollector::getPieceSetStr() const
{
    return _pieceSetStr;
}

Boards DataCollector::getBoard() const
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

// Public functions
QString DataCollector::getBgImageStrByNumber(const BgImages& bgImage) const
{
    switch (bgImage)
    {
    case BgImages::AngelView:
        return BgImagesStr::AngelView;
    case BgImages::Blacked:
        return BgImagesStr::Blacked;
    case BgImages::BravePawn:
        return BgImagesStr::BravePawn;
    case BgImages::Checkmate:
        return BgImagesStr::Checkmate;
    case BgImages::Dark_Chess:
        return BgImagesStr::Dark_Chess;
    case BgImages::Emperors:
        return BgImagesStr::Emperors;
    case BgImages::FaceToFace:
        return BgImagesStr::FaceToFace;
    case BgImages::IAmTheKing:
        return BgImagesStr::IAmTheKing;
    case BgImages::Landscape:
        return BgImagesStr::Landscape;
    case BgImages::Legends:
        return BgImagesStr::Legends;
    case BgImages::Shadow:
        return BgImagesStr::Shadow;
    case BgImages::StrongKnight:
        return BgImagesStr::StrongKnight;
    case BgImages::TheBishop:
        return BgImagesStr::TheBishop;
    case BgImages::TheKing:
        return BgImagesStr::TheKing;
    case BgImages::TheKnight:
        return BgImagesStr::TheKnight;
    case BgImages::TheQueen:
        return BgImagesStr::TheQueen;
    case BgImages::TopView:
        return BgImagesStr::TopView;
    default:
        return BgImagesStr::TheRook;
    }
}

QString DataCollector::getLanguageStrByNumber(const Languages& language) const
{
    switch (language)
    {
    case Languages::Armenian:
        return LanguagesStr::Armenian;
    case Languages::Russian:
        return LanguagesStr::Russian;
    default:
        return LanguagesStr::English;
    }
}

QString DataCollector::getPieceSetStrByNumber(const PieceSets& pieceSet) const
{
    switch (pieceSet)
    {
    case PieceSets::Alpha:
        return PieceSetsStr::Alpha;
    case PieceSets::California:
        return PieceSetsStr::California;
    case PieceSets::Cardinal:
        return PieceSetsStr::Cardinal;
    case PieceSets::Cases:
        return PieceSetsStr::Cases;
    case PieceSets::Chess7:
        return PieceSetsStr::Chess7;
    case PieceSets::Condal:
        return PieceSetsStr::Condal;
    case PieceSets::Fresca:
        return PieceSetsStr::Fresca;
    case PieceSets::GameRoom:
        return PieceSetsStr::GameRoom;
    case PieceSets::Glass:
        return PieceSetsStr::Glass;
    case PieceSets::ICPieces:
        return PieceSetsStr::ICPieces;
    case PieceSets::Lolz:
        return PieceSetsStr::Lolz;
    case PieceSets::Maestro:
        return PieceSetsStr::Maestro;
    case PieceSets::Merida:
        return PieceSetsStr::Merida;
    case PieceSets::Neo:
        return PieceSetsStr::Neo;
    case PieceSets::Ocean:
        return PieceSetsStr::Ocean;
    default:
        return PieceSetsStr::Cburnett;
    }
}

QString DataCollector::getBoardStrByNumber(const Boards& board) const
{
    switch (board)
    {
    case Boards::Bit8:
        return BoardsStr::Bit8;
    case Boards::Bases:
        return BoardsStr::Bases;
    case Boards::Blue:
        return BoardsStr::Blue;
    case Boards::Brown:
        return BoardsStr::Brown;
    case Boards::Bubblegum:
        return BoardsStr::Bubblegum;
    case Boards::BurledWood:
        return BoardsStr::BurledWood;
    case Boards::DarkWood:
        return BoardsStr::DarkWood;
    case Boards::Dash:
        return BoardsStr::Dash;
    case Boards::Glass:
        return BoardsStr::Glass;
    case Boards::Graffiti:
        return BoardsStr::Graffiti;
    case Boards::Green:
        return BoardsStr::Green;
    case Boards::IcySea:
        return BoardsStr::IcySea;
    case Boards::Light:
        return BoardsStr::Light;
    case Boards::Lolz:
        return BoardsStr::Lolz;
    case Boards::Marble:
        return BoardsStr::Marble;
    case Boards::Metal:
        return BoardsStr::Metal;
    case Boards::Neon:
        return BoardsStr::Neon;
    case Boards::Newspaper:
        return BoardsStr::Newspaper;
    case Boards::Orange:
        return BoardsStr::Orange;
    case Boards::Parchment:
        return BoardsStr::Parchment;
    case Boards::Purple:
        return BoardsStr::Purple;
    case Boards::Red:
        return BoardsStr::Red;
    case Boards::Sand:
        return BoardsStr::Sand;
    case Boards::Sky:
        return BoardsStr::Sky;
    case Boards::Stone:
        return BoardsStr::Stone;
    case Boards::Tan:
        return BoardsStr::Tan;
    case Boards::Tournament:
        return BoardsStr::Tournament;
    case Boards::Translucent:
        return BoardsStr::Translucent;
    case Boards::Walnut:
        return BoardsStr::Walnut;
    default:
        return BoardsStr::Brown;
    }
}
