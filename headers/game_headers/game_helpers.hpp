#ifndef GAME_HELPERS_HPP
#define GAME_HELPERS_HPP

//#include "pieces_helpers.hpp"
//#include "menus_helpers.hpp"

#include "helpers.hpp"

//
// Game Menu
//
enum class GameMenuProps
{
    ReturnButtonW = 35,
    ReturnButtonH = 28,
    ReturnButtonX = (int)MainWindowProps::windowSizeW - ReturnButtonW - 13,
    ReturnButtonY =  (int)MainWindowProps::windowSizeH - ReturnButtonH - 12,

    BoardImageLabelX = 10,
    BoardImageLabelY = BoardImageLabelX,
    BoardImageLabelW = 680,
    BoardImageLabelH = BoardImageLabelW,
};

enum class BoardWidgetProps
{
//    BoardWidgetX = 1,
//    BoardWidgetY = BoardWidgetX,
//    BoardWidgetW = 698,
//    BoardWidgetH = BoardWidgetW,
//    PieceLabelW = BoardWidgetW / 8,
//    PieceLabelH = PieceLabelW,
};


// Moves Widget
//enum class MovesWidgetProps
//{
//    ScrollW = 332,
//    ScrollH = 300,
//    ScrollX = 690 + 14,
//    ScrollY = 200,
//    WidgetW = ScrollW - 20,
//    WidgetH = 0,
//    WidgetX = 0,
//    WidgetY = 0,
//    NumberLabelX = 0,
//    NumberLabelY = 0,
//    NumberLabelW = 60,
//    NumberLabelH = 30
//};

//namespace PieceSymbolsForMove
//{
//    extern QString WhitePawn;
//    extern QString WhiteKnight;
//    extern QString WhiteBishop;
//    extern QString WhiteRook;
//    extern QString WhiteQueen;
//    extern QString WhiteKing;
//    extern QString BlackPawn;
//    extern QString BlackKinght;
//    extern QString BlackBishop;
//    extern QString BlackRook;
//    extern QString BlackQueen;
//    extern QString BlackKing;
//}


//// PawnProm Dialog
//enum class PawnPromDialogProps
//{
//    windowSizeW = 415,
//    windowSizeH = 115,
//    QueenPosX = 12,
//    QueenPosY = 15,
//    RookPosX = QueenPosX + (int)BoardWidgetProps::PieceLabelW + 15,
//    RookPosY = QueenPosY,
//    BishopPosX = RookPosX + (int)BoardWidgetProps::PieceLabelW + 15,
//    BishopPosY = RookPosY,
//    KnightPosX = BishopPosX + (int)BoardWidgetProps::PieceLabelW + 15,
//    KnightPosY = BishopPosY
//};

#endif // GAME_HELPERS_HPP
