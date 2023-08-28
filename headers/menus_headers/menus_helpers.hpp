#ifndef MENUS_HELPERS_HPP
#define MENUS_HELPERS_HPP

#include <QString>

#include "helpers.hpp"

//
// MainMenu
//
enum class MainMenuProps
{
    // Layouts proporties
    verLayoutW = ((int)MainWindowProps::windowSizeW / 10) * 4,
    verLayoutH = (int)MainWindowProps::windowSizeH / 4 - 8,
    verLayoutX = ((int)MainWindowProps::windowSizeW - verLayoutW) / 2,
    horLayoutX = verLayoutX,
    horLayoutW = verLayoutW,
    horLayoutH = verLayoutH / 3,
    verLayoutY = ((int)MainWindowProps::windowSizeH - (verLayoutH + horLayoutH + 20)) / 2,
    horLayoutY = verLayoutY + verLayoutH - 5,

    // PushButtons proporties
    verLayoutButtonsW = 0,
    verLayoutButtonsH = 44,
    verLayoutButtonsFont = 18,
    horLayoutButtonsW = verLayoutButtonsW,
    horLayoutButtonsH = verLayoutButtonsH,
    horLayoutButtonsFont = verLayoutButtonsFont,

    // Version text proporties
    VersionTextLabelX = (int)MainWindowProps::windowSizeW - 120,
    VersionTextLabelY = (int)MainWindowProps::windowSizeH - 30,
    VersionTextLabelW = 140,
    VersionTextLabelH = 20,
};


//
// PVPMenu
//
enum class PVPMenuProps
{
    BgLabelW = 440,
    BgLabelH = 589,
    BgLabelX = ((int)MainWindowProps::windowSizeW - BgLabelW) / 2,
    BgLabelY = ((int)MainWindowProps::windowSizeH - BgLabelH) / 2,

    TopTextLabelX = BgLabelX,
    TopTextLabelY = BgLabelY + 22,
    TopTextLabelW = BgLabelW,
    TopTextLabelH = 40,

    GameVariantTextLabelX = BgLabelX + 112,
    GameVariantTextLabelY = TopTextLabelY + 72,
    GameVariantTextLabelW = 200,
    GameVariantTextLabelH = 20,

    GameVariantComboBoxX = GameVariantTextLabelX + 57,
    GameVariantComboBoxY = GameVariantTextLabelY - 8,
    GameVariantComboBoxW = 157,
    GameVariantComboBoxH = 35,

    TimeControlBgLabelX = BgLabelX,
    TimeControlBgLabelY = GameVariantTextLabelY + 49,
    TimeControlBgLabelW = BgLabelW,
    TimeControlBgLabelH = 323,

    TimeControlTextLabelX = TimeControlBgLabelX + 140,
    TimeControlTextLabelY = TimeControlBgLabelY + 16,
    TimeControlTextLabelW = 100,
    TimeControlTextLabelH = 20,

    TimeControlToggleSwitchX = TimeControlTextLabelX + 94,
    TimeControlToggleSwitchY = TimeControlTextLabelY - 10,

    MinutesTextLabelX = TimeControlTextLabelX + 5,
    MinutesTextLabelY = TimeControlTextLabelY + 41,
    MinutesTextLabelW = 400,
    MinutesTextLabelH = 20,

    MinutesNumberLabelX = MinutesTextLabelX + 117,
    MinutesNumberLabelY = MinutesTextLabelY + 3,
    MinutesNumberLabelW = 30,
    MinutesNumberLabelH = 15,

    MinutesSliderW = 360,
    MinutesSliderH = 25,
    MinutesSliderX = BgLabelX + (BgLabelW - MinutesSliderW) / 2,
    MinutesSliderY = MinutesTextLabelY + 30,

    IncSecondsTextLabelX = MinutesTextLabelX - 10,
    IncSecondsTextLabelY = MinutesSliderY + 44,
    IncSecondsTextLabelW = MinutesTextLabelW,
    IncSecondsTextLabelH = MinutesTextLabelH,

    IncSecondsNumberLabelX = IncSecondsTextLabelX + 147,
    IncSecondsNumberLabelY = IncSecondsTextLabelY + 3,
    IncSecondsNumberLabelW = MinutesNumberLabelW,
    IncSecondsNumberLabelH = MinutesNumberLabelH,

    IncSecondsSliderX = MinutesSliderX,
    IncSecondsSliderY = IncSecondsTextLabelY + 31,
    IncSecondsSliderW = MinutesSliderW,
    IncSecondsSliderH = MinutesSliderH,

    QuickGamesTextLabelX = IncSecondsTextLabelX + 36,
    QuickGamesTextLabelY = IncSecondsSliderY + 38,
    QuickGamesTextLabelW = 200,
    QuickGamesTextLabelH = 30,

    // Quick game buttons sizes
    StartGameButtonW = 58,
    StartGameButtonH = 74,

    Bullet1MButtonX = BgLabelX + 15,
    Bullet1MButtonY = QuickGamesTextLabelY + 37,

    Blitz3MButtonX = Bullet1MButtonX + StartGameButtonW + 12,
    Blitz3MButtonY = Bullet1MButtonY,

    Blitz3MInc2SecButtonX = Blitz3MButtonX + StartGameButtonW + 13,
    Blitz3MInc2SecButtonY = Bullet1MButtonY,

    Blitz5MButtonX = Blitz3MInc2SecButtonX + StartGameButtonW + 13,
    Blitz5MButtonY = Bullet1MButtonY,

    Blitz10MButtonX = Blitz5MButtonX + StartGameButtonW + 12,
    Blitz10MButtonY = Bullet1MButtonY,

    Rapid15MButtonX = Blitz10MButtonX + StartGameButtonW + 12,
    Rapid15MButtonY = Bullet1MButtonY,

    RandomColorButtonW = 90,
    RandomColorButtonH = RandomColorButtonW,
    RandomColorButtonX = BgLabelX + ((BgLabelW - RandomColorButtonW) / 2),
    RandomColorButtonY = Bullet1MButtonY + StartGameButtonH + 29,

    BlackColorButtonW = 70,
    BlackColorButtonH = BlackColorButtonW,
    BlackColorButtonX = RandomColorButtonX - BlackColorButtonW - 15,
    BlackColorButtonY = RandomColorButtonY + (RandomColorButtonH - BlackColorButtonH),

    WhiteColorButtonX = RandomColorButtonX + RandomColorButtonW + 15,
    WhiteColorButtonY = BlackColorButtonY,

    ReturnButtonW = 25,
    ReturnButtonH = 20,
    ReturnButtonX = BgLabelX + BgLabelW - ReturnButtonW - 8,
    ReturnButtonY = BgLabelY + BgLabelH - ReturnButtonH - 7,
};

enum class GameVariants
{
    Standard,
    Chess960,
    KingOfTheHill,
    ThreeCheck,
    Horde,
    FromPosition,
};

namespace GameVariantsStr
{
    extern QString Standard;
    extern QString Chess960;
    extern QString KingOfTheHill;
    extern QString ThreeCheck;
    extern QString Horde;
    extern QString FromPosition;
    extern QString HordeSymbolsVector2D;
    extern QString StandardSymbolsVector2D;
}

enum class StartGameButtons
{
    NoSelected,
    Bullet1M,
    Blitz3M,
    Blitz3MInc2Sec,
    Blitz5M,
    Blitz10M,
    Rapid15M,
    WhiteColor,
    BlackColor,
    RandomColor,
};

namespace StartGameButtonsStr
{
    extern QString NoSelected;
    extern QString Bullet1M;
    extern QString Blitz3M;
    extern QString Blitz3MInc2Sec;
    extern QString Blitz5M;
    extern QString Blitz10M;
    extern QString Rapid15M;
    extern QString WhiteColor;
    extern QString BlackColor;
    extern QString RandomColor;
}


//
// SettingsMenu
//
enum class SettingsMenuProps
{
    BgLabelW = 460,
    BgLabelH = 507,
    BgLabelX = ((int)MainWindowProps::windowSizeW - BgLabelW) / 2,
    BgLabelY = ((int)MainWindowProps::windowSizeH - BgLabelH) / 2,

    BoardLabelX = BgLabelX + 10,
    BoardLabelY = BgLabelY + 10,
    BoardLabelW = BgLabelW - 20,
    BoardLabelH = 137,

    BgImageTextLabelX = BoardLabelX,
    BgImageTextLabelY = BoardLabelY + BoardLabelH + 13,
    BgImageTextLabelW = BoardLabelW / 2,
    BgImageTextLabelH = 30,

    BgImageComboBoxX = BoardLabelX + (BoardLabelW / 2),
    BgImageComboBoxY = BgImageTextLabelY,
    BgImageComboBoxW = BgImageTextLabelW,
    BgImageComboBoxH = BgImageTextLabelH,

    PieceSetTextLabelX = BgImageTextLabelX,
    PieceSetTextLabelY = BgImageTextLabelY + BgImageTextLabelH + 15,
    PieceSetTextLabelW = BgImageTextLabelW,
    PieceSetTextLabelH = BgImageTextLabelH,

    PieceSetComboBoxX = BgImageComboBoxX,
    PieceSetComboBoxY = PieceSetTextLabelY,
    PieceSetComboBoxW = BgImageComboBoxW,
    PieceSetComboBoxH = BgImageComboBoxH,

    BoardTextLabelX = BgImageTextLabelX,
    BoardTextLabelY = PieceSetTextLabelY + PieceSetTextLabelH + 15,
    BoardTextLabelW = BgImageTextLabelW,
    BoardTextLabelH = BgImageTextLabelH,

    BoardComboBoxX = BgImageComboBoxX,
    BoardComboBoxY = BoardTextLabelY,
    BoardComboBoxW = BgImageComboBoxW,
    BoardComboBoxH = BgImageComboBoxH,

    LanguageTextLabelX = BgImageTextLabelX,
    LanguageTextLabelY = BoardTextLabelY + BoardTextLabelH + 15,
    LanguageTextLabelW = BgImageTextLabelW,
    LanguageTextLabelH = BgImageTextLabelH,

    LanguageComboBoxX = BgImageComboBoxX,
    LanguageComboBoxY = LanguageTextLabelY,
    LanguageComboBoxW = BgImageComboBoxW,
    LanguageComboBoxH = BgImageComboBoxH,

    SoundTextLabelX = BgImageTextLabelX,
    SoundTextLabelY = LanguageTextLabelY + LanguageTextLabelH + 15,
    SoundTextLabelW = BgImageTextLabelW,
    SoundTextLabelH = BgImageTextLabelH,

    SoundToggleSwitchX = BgImageComboBoxX + 162,
    SoundToggleSwitchY = SoundTextLabelY - 4,

    ThemeTextLabelX = BgImageTextLabelX,
    ThemeTextLabelY = SoundTextLabelY + SoundTextLabelH + 15,
    ThemeTextLabelW = BgImageTextLabelW,
    ThemeTextLabelH = BgImageTextLabelH,
    ThemeToggleSwitchX = SoundToggleSwitchX,
    ThemeToggleSwitchY = ThemeTextLabelY - 4,

    ButtonsBgLabelX = BgLabelX,
    ButtonsBgLabelY = ThemeTextLabelY + ThemeTextLabelH + 15,
    ButtonsBgLabelW = BgLabelW,
    ButtonsBgLabelH = 80,

    CancelButtonX = ButtonsBgLabelX + 16,
    CancelButtonY = ButtonsBgLabelY + 15,
    CancelButtonW = (BgLabelW - 50) / 2,
    CancelButtonH = ButtonsBgLabelH - 30,

    SaveButtonX = CancelButtonX + CancelButtonW + 18,
    SaveButtonY = CancelButtonY,
    SaveButtonW = CancelButtonW,
    SaveButtonH = CancelButtonH,

    HideAndShowButtonW = 40,
    HideAndShowButtonH = 40,
    HideAndShowButtonX = (int)MainWindowProps::windowSizeW - HideAndShowButtonW - 15,
    HideAndShowButtonY = (int)MainWindowProps::windowSizeH - HideAndShowButtonH - 15
};

enum class BgImages
{
    AngelView,
    Blacked,
    BravePawn,
    Checkmate,
    Dark_Chess,
    Emperors,
    FaceToFace,
    IAmTheKing,
    Landscape,
    Legends,
    Shadow,
    StrongKnight,
    TheBishop,
    TheKing,
    TheKnight,
    TheQueen,
    TheRook,
    TopView,
};

namespace BgImagesStr
{
    extern QString Extencion;
    extern QString AngelView;
    extern QString Blacked;
    extern QString BravePawn;
    extern QString Checkmate;
    extern QString Dark_Chess;
    extern QString Emperors;
    extern QString FaceToFace;
    extern QString IAmTheKing;
    extern QString Landscape;
    extern QString Legends;
    extern QString Shadow;
    extern QString StrongKnight;
    extern QString TheBishop;
    extern QString TheKing;
    extern QString TheKnight;
    extern QString TheQueen;
    extern QString TheRook;
    extern QString TopView;
}

enum class Boards
{
    Bit8,
    Bases,
    Blue,
    Brown,
    Bubblegum,
    BurledWood,
    DarkWood,
    Dash,
    Glass,
    Graffiti,
    Green,
    IcySea,
    Light,
    Lolz,
    Marble,
    Metal,
    Neon,
    Newspaper,
    Orange,
    Parchment,
    Purple,
    Red,
    Sand,
    Sky,
    Stone,
    Tan,
    Tournament,
    Translucent,
    Walnut,
};

namespace BoardsStr
{
    extern QString Extencion;
    extern QString Bit8;
    extern QString Bases;
    extern QString Blue;
    extern QString Brown;
    extern QString Bubblegum;
    extern QString BurledWood;
    extern QString DarkWood;
    extern QString Dash;
    extern QString Glass;
    extern QString Graffiti;
    extern QString Green;
    extern QString IcySea;
    extern QString Light;
    extern QString Lolz;
    extern QString Marble;
    extern QString Metal;
    extern QString Neon;
    extern QString Newspaper;
    extern QString Orange;
    extern QString Parchment;
    extern QString Purple;
    extern QString Red;
    extern QString Sand;
    extern QString Sky;
    extern QString Stone;
    extern QString Tan;
    extern QString Tournament;
    extern QString Translucent;
    extern QString Walnut;
}

enum class PieceSets
{
    Alpha,
    California,
    Cardinal,
    Cases,
    Cburnett,
    Chess7,
    Condal,
    Fresca,
    GameRoom,
    Glass,
    ICPieces,
    Lolz,
    Maestro,
    Merida,
    Neo,
    Ocean,
};

namespace PieceSetsStr
{
    extern QString Extencion;
    extern QString Alpha;
    extern QString California;
    extern QString Cardinal;
    extern QString Cases;
    extern QString Cburnett;
    extern QString Chess7;
    extern QString Condal;
    extern QString Fresca;
    extern QString GameRoom;
    extern QString Glass;
    extern QString ICPieces;
    extern QString Lolz;
    extern QString Maestro;
    extern QString Merida;
    extern QString Neo;
    extern QString Ocean;
}

enum class Languages
{
    Armenian,
    Russian,
    English,
};

namespace LanguagesStr
{
    extern QString Armenian;
    extern QString Russian;
    extern QString English;
}

struct SettingsData
{
    BgImages   bgImage;
    PieceSets  pieceSet;
    Boards     board;
    Languages  language;
    bool       isSoundOn;
    bool       isDarkTheme;
};

#endif // MENUS_HELPERS_HPP
