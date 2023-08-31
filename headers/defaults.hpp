#ifndef DEFAULTS_HPP
#define DEFAULTS_HPP

#include <QString>

#include "menus_helpers.hpp"

namespace DefaultData
{
    // Settings menu data
    extern BgImages   BgImage;
    extern QString    BgImageStr;

    extern Languages  Language;
    extern QString    LanguageStr;

    extern PieceSets  PieceSet;
    extern QString    PieceSetStr;

    extern Boards     Board;
    extern QString    BoardStr;

    extern bool       isSoundOn;
    extern bool       isDarkTheme;

    // PVP menu data
    extern bool          isTimeOn;
    extern PlayerColors  PlayerColor;
    extern GameVariants  GameVariant;
    extern QString       GameVariantsStr;

    extern int           GameMinutes;
    extern int           MinutesSliderIndex;
    extern QString       MinutesSliderNumberStr;

    extern int           GameIncSeconds;
    extern int           IncSecondsIndex;
    extern QString       IncSecondsNumberStr;

}

#endif // DEFAULTS_HPP
