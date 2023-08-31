#include <QDebug>

#include "gamemenu.hpp"
#include "mainwindow.hpp"
#include "game_helpers.hpp"
#include "clickable_label.hpp"
#include "game_data.hpp"
#include "paths.hpp"
#include "utils.hpp"



//#include "boardwidget.hpp"
//#include "moveswidget.hpp"
//#include "piece.hpp"



GameMenu::GameMenu()
{
    /* Init class members */
    init();

    /* Make GameMenu */
    makeGameMenu();
}

GameMenu::~GameMenu()
{
    delete _gameData;
    delete _boardImageLabel;
//    delete _boardWidget;
//    delete _movesWidget;
    delete _returnButton;
//    delete _movesScrollArea;
}

/* Singlton pattern realization */
GameMenu* GameMenu::_gameMenu = nullptr;

GameMenu* GameMenu::GetInstance()
{
    if(_gameMenu == nullptr)
        _gameMenu = new GameMenu();

    return _gameMenu;
}

void GameMenu::init()
{
    /* Game data*/
    _gameData = GameData::GetInstance();

    /* Game elements */
    _boardImageLabel = new QLabel(this);
//    _boardWidget = BoardWidget::GetInstance(this);
//    _movesWidget = MovesWidget::GetInstance(this);

    /* Return button */
    _returnButton = new ClickableLabel(this);

//    _movesScrollArea = new QScrollArea(this);
}

//// Public functions
void GameMenu::makeMenuBeforeSwitch()
{
    _gameData->syncDataWithDataCollector();

    /* Set background image depends on choosed theme */
    if (_gameData->isDarkTheme)
    {
        _boardImageLabel->setStyleSheet("QLabel { border-radius: 8px; }");
        MainWindow::GetInstance()->setBackgroundImage(BgImages::DarkThemeGameBg);
    }
    else
        MainWindow::GetInstance()->setBackgroundImage(BgImages::WhiteThemeGameBg);

    /* Set board depends on player color */
    if (_gameData->playerColor == PlayerColors::White)
        _boardImageLabel->setPixmap(QPixmap(ImagesPaths::WhitePlayerBoardsPath + _gameData->boardStr + BoardsStr::Extencion));
    else
        _boardImageLabel->setPixmap(QPixmap(ImagesPaths::BlackPlayerBoardsPath + _gameData->boardStr + BoardsStr::Extencion));

}







//void GameMenu::startGame()
//{




//    if (globalIsDarkTheme)
//        _movesScrollArea->setBackgroundRole(QPalette::Shadow);
//    else
//        _movesScrollArea->setBackgroundRole(QPalette::Midlight);

//    gIsTimeEnded = false;
//    MovesWidget::ResetInstance();
//    _movesWidget = MovesWidget::GetInstance(this);
//    _movesWidget->setGeometry((int)MovesWidgetProps::WidgetX, (int)MovesWidgetProps::WidgetY, (int)MovesWidgetProps::WidgetW, (int)MovesWidgetProps::WidgetH);

//    _movesScrollArea->setWidget(_movesWidget);
//    if (globalIsDarkTheme)
//        _movesScrollArea->setBackgroundRole(QPalette::Shadow);
//    else
//        _movesScrollArea->setBackgroundRole(QPalette::Midlight);

//    // Return button
//    setQLabelPictureByTheme(_returnButton, globalIsDarkTheme, ImagesPaths::GameWidgetLightReturnButton, ImagesPaths::GameWidgetDarkReturnButton);

//    gSelectedPiece = nullptr;
//    resetBoard();

//    if (gSound)
//    {
//        _boardWidget->getMediaPlayer()->setSource(QUrl::fromLocalFile(Sounds::StartGameSound));
//        _boardWidget->getMediaPlayer()->play();
//    }
//}

/* Private functions */
void GameMenu::makeGameMenu()
{
//    // Set BoardWidget geometry
//    _boardWidget->setGeometry((int)BoardWidgetProps::BoardWidgetX, (int)BoardWidgetProps::BoardWidgetY, (int)BoardWidgetProps::BoardWidgetW, (int)BoardWidgetProps::BoardWidgetH);

    /* Board image */
    _boardImageLabel->setGeometry((int)GameMenuProps::BoardImageLabelX, (int)GameMenuProps::BoardImageLabelY,
                                 (int)GameMenuProps::BoardImageLabelW, (int)GameMenuProps::BoardImageLabelH);
    if (_gameData->playerColor == PlayerColors::White)
        _boardImageLabel->setPixmap(QPixmap(ImagesPaths::WhitePlayerBoardsPath + _gameData->boardStr + BoardsStr::Extencion));
    else
        _boardImageLabel->setPixmap(QPixmap(ImagesPaths::BlackPlayerBoardsPath + _gameData->boardStr + BoardsStr::Extencion));

    /* Return button */
    _returnButton->move((int)GameMenuProps::ReturnButtonX, (int)GameMenuProps::ReturnButtonY);
    setQLabelImageByTheme(_returnButton, ImagesPaths::GameMenuLightReturnButton, ImagesPaths::GameMenuDarkReturnButton, _gameData->isDarkTheme);
    _returnButton->setCursor(Qt::PointingHandCursor);
    connect(_returnButton, &ClickableLabel::clickedLeftButton, this, std::bind(&GameMenu::switchToMenu, this, Menus::MainMenu));

//    // MovesWidget
//    _movesWidget->setGeometry((int)MovesWidgetProps::WidgetX, (int)MovesWidgetProps::WidgetY, (int)MovesWidgetProps::WidgetW, (int)MovesWidgetProps::WidgetH);

//    // Scroll area
//    _movesScrollArea->setGeometry((int)MovesWidgetProps::ScrollX, (int)MovesWidgetProps::ScrollY, (int)MovesWidgetProps::ScrollW, (int)MovesWidgetProps::ScrollH);
//    if (globalIsDarkTheme)
//        _movesScrollArea->setBackgroundRole(QPalette::Shadow);
//    else
//        _movesScrollArea->setBackgroundRole(QPalette::Midlight);
//    _movesScrollArea->setWidget(_movesWidget);
}

void switchToMenu(Menus toMenu)
{
    switchMenu(MainWindow::GetInstance(), toMenu);
}

//void GameMenu::resetBoard()
//{
//    if (_gameData.belowPlayerColor == PiecesColors::Black)
//        _boardLabel->setPixmap(QPixmap(ImagesPaths::BlackBoardsPath + _gameData.board + "_ln" + Boards::Extencion));
//    else
//        _boardLabel->setPixmap(QPixmap(ImagesPaths::WhiteBoardsPath + _gameData.board + "_ln" + Boards::Extencion));

//    auto& symbolsVector2D = _boardWidget->getPiecesSymbolsVector2D();
//    auto& stepsVector2D = _boardWidget->getPossibleStepsVector2D();

//    _boardWidget->clearBoardLayout();
//    _boardWidget->clearUnderLayout();

//    resetCharVector2D(symbolsVector2D, 8, (char)PiecesSymbols::Empty);
//    resetCharVector2D(stepsVector2D, 8, (char)PiecesSymbols::Empty);

//    resetSymbolsVector2D();

//    resetPiecesVector2D();

//    _boardWidget->drawUnderLayer();
//    _boardWidget->resetBoardLayout();


//    _boardWidget->setTurn(PiecesColors::White);
//    _boardWidget->setIsChecked(false);
//    _boardWidget->setIsCheckedKingSelected(false);
//    _boardWidget->setCheckPosition(0, 0);
//    _boardWidget->setIsPawnPromoted(false);
//    _boardWidget->setPromotedPawnPosition(0, 0);
//    _boardWidget->setHordPiecesCount(36);
//    _boardWidget->setWhiteKingCheckCount(0);
//    _boardWidget->setBlackKingCheckCount(0);
//}

//void GameMenu::resetSymbolsVector2D()
//{
//    auto variant = _gameData.gameVariant;
//    auto playerColor = _gameData.belowPlayerColor;

//    if (variant == GameVariants::Horde)
//        makeSymbolsVector2DForHorde();
//    else if (variant == GameVariants::Chess960)
//        makeSymbolsVector2DForChess960();
//    else
//        makeSymbolsVector2DStandard();

//    if (playerColor == PiecesColors::Black)
//        reverseSymbolsVector2D();
//}

//void GameMenu::reverseSymbolsVector2D()
//{
//    int i1 = 0;
//    int j1 = 0;
//    char temp;
//    auto& vector2D = _boardWidget->getPiecesSymbolsVector2D();

//    for (int i = 7; i >= 4; --i, ++i1)
//    {
//        j1 = 0;
//        for (int j = 7; j >= 0; --j, ++j1)
//        {
//            temp = vector2D[i][j];
//            vector2D[i][j] = vector2D[i1][j1];
//            vector2D[i1][j1] = temp;
//        }
//    }
//}

//void GameMenu::makeSymbolsVector2DForHorde()
//{
//    QString hordeMatrix = GameVariants::HordeSymbolsVector2D;
//    auto& vector2D = _boardWidget->getPiecesSymbolsVector2D();

//    hordeMatrix.remove(' ');

//    int k = 0;
//    for (int i = 0; i < 8; ++i)
//        for (int j = 0; j < 8; ++j, ++k)
//            vector2D[i][j] = static_cast<char>(hordeMatrix.at(k).toLatin1());
//}

//void GameMenu::makeSymbolsVector2DForChess960()
//{
//    auto& vector2D = _boardWidget->getPiecesSymbolsVector2D();
//    char shuffeledLine[8] = {'0', '0', '0', '0', '0', '0', '0', '0'};
//    int min = 0;
//    int max = 7;

//    // King
//    int kingPos = QRandomGenerator::global()->bounded(min + 1, max);
//    shuffeledLine[kingPos] = (char)PiecesSymbols::BlackKing;

//    // Rooks
//    int rookPos = QRandomGenerator::global()->bounded(min, kingPos);
//    shuffeledLine[rookPos] = (char)PiecesSymbols::BlackRook;
//    rookPos = QRandomGenerator::global()->bounded(kingPos + 1, max + 1);
//    shuffeledLine[rookPos] = (char)PiecesSymbols::BlackRook;

//    // Bishops
//    bool blackSquareBishop = false;
//    bool whiteSquareBishop = false;
//    int pos;
//    while (true)
//    {
//        pos = QRandomGenerator::global()->bounded(min, max + 1);

//        if ((pos % 2 != 0) && shuffeledLine[pos] == '0' && !blackSquareBishop)
//        {
//            shuffeledLine[pos] = (char)PiecesSymbols::BlackBishop;
//            blackSquareBishop = true;
//        }
//        else if ((pos % 2 == 0) && shuffeledLine[pos] == '0' && !whiteSquareBishop)
//        {
//            shuffeledLine[pos] = (char)PiecesSymbols::BlackBishop;
//            whiteSquareBishop = true;
//        }

//        if (blackSquareBishop && whiteSquareBishop)
//            break;
//    }

//    // Queen
//    while (true)
//    {
//        pos = QRandomGenerator::global()->bounded(min, max + 1);
//        if (shuffeledLine[pos] == '0')
//        {
//            shuffeledLine[pos] = (char)PiecesSymbols::BlackQueen;
//            break;
//        }
//    }

//    // Knights
//    for (int i = 0; i < 8; ++i)
//        if (shuffeledLine[i] == '0')
//            shuffeledLine[i] = (char)PiecesSymbols::BlackKnight;

//    for (int i = 0; i < 8; ++i)
//    {
//        vector2D[0][i] = shuffeledLine[i];
//        vector2D[7][i] = toupper(shuffeledLine[i]);
//        vector2D[1][i] = (char)PiecesSymbols::BlackPawn;
//        vector2D[6][i] = (char)PiecesSymbols::WhitePawn;
//    }
//}

//void GameMenu::makeSymbolsVector2DStandard()
//{
//    QString standartMatrix = GameVariants::StandardSymbolsVector2D;
//    auto& vector2D = _boardWidget->getPiecesSymbolsVector2D();

//    standartMatrix.remove(' ');

//    int k = 0;
//    for (int i = 0; i < 8; ++i)
//        for (int j = 0; j < 8; ++j, ++k)
//            vector2D[i][j] = static_cast<char>(standartMatrix.at(k).toLatin1());
//}

//void GameMenu::resetPiecesVector2D()
//{
//    auto& piecesVector2D = _boardWidget->getPiecesVector2D();
//    auto& piecesSymbolsVector2D = _boardWidget->getPiecesSymbolsVector2D() ;

//    //_boardWidget->clearBoardLayout();

//    for (int i = 0; i < (int)BoardWidgetProps::BoardSquaresCount; ++i)
//    {
//        for (int j = 0; j < (int)BoardWidgetProps::BoardSquaresCount; ++j)
//        {
//            //delete piecesVector2D[i][j];
//            //piecesVector2D[i][j]->getPieceLabel()->disconnect();

//            if (piecesVector2D[i][j]->getPieceSymbol() != piecesSymbolsVector2D[i][j])
//            {
//                delete piecesVector2D[i][j];
//                _boardWidget->makeNewPieceBySymbol(piecesSymbolsVector2D[i][j], i, j);
//                //connect(piecesVector2D[i][j]->getPieceLabel(), &ClickableLabel::clickedLeftButton, _boardWidget,
//                  //      std::bind(&BoardWidget::processLeftButtonClick, _boardWidget, piecesVector2D[i][j]));
//             }

//            piecesVector2D[i][j]->changePixmap();
//        }
//    }
//}
