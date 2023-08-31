#include "defaults.hpp"

namespace DefaultData
{
    // Settings menu data
    BgImages  BgImage = BgImages::StrongKnight;
    QString BgImageStr = BgImagesStr::StrongKnight;

    Languages Language = Languages::English;
    QString LanguageStr = LanguagesStr::English;

    PieceSets PieceSet = PieceSets::Cburnett;
    QString PieceSetStr = PieceSetsStr::Cburnett;

    Boards Board = Boards::Brown;
    QString BoardStr = BoardsStr::Brown;

    bool isSoundOn = true;
    bool isDarkTheme = false;

    // PVP menu data
    bool isTimeOn = false;
    PlayerColors playerColor = PlayerColors::White;
    GameVariants GameVariant = GameVariants::Standard;
    QString GameVariantsStr = GameVariantsStr::Standard;

    int GameMinutes = 10;
    int MinutesSliderIndex = 13;
    QString MinutesSliderNumberStr = "10";

    int GameIncSeconds = 0;
    int IncSecondsIndex = 0;
    QString IncSecondsNumberStr = "0";
}
