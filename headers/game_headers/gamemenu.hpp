#ifndef GAMEMENU_HPP
#define GAMEMENU_HPP

#include <QWidget>
#include <QLabel>

#include "helpers.hpp"
#include "predefined_classes.hpp"



//#include <QChar>
//#include <QRandomGenerator>
//#include <QScrollArea>
//#include <QTimer>

//#include "game_helpers.hpp"
//#include "menus_helpers.hpp"




/* Singlton pattern used */
class GameMenu : public QWidget
{
    Q_OBJECT

public:
    // Singleton pattern realization
    GameMenu(GameMenu& other) = delete;
    GameMenu& operator=(const GameMenu&) = delete;
    static GameMenu* GetInstance();
    virtual ~GameMenu() override;

public:
    void makeMenuBeforeSwitch();

//    void startGame();

private:
    explicit GameMenu();

    void init();
    void makeGameMenu();

    void switchToMenu(Menus toMenu);

//    void resetBoard();
//    void resetSymbolsVector2D();
//    void makeSymbolsVector2DStandard();
//    void makeSymbolsVector2DForHorde();
//    void makeSymbolsVector2DForChess960();
//    void reverseSymbolsVector2D();
//    void resetPiecesVector2D();

private:
    /* Singlton pattern realization */
    static GameMenu*  _gameMenu;

    /* Game data */
    GameData* _gameData;

    /* Game elements */
    QLabel*           _boardImageLabel;
//    BoardWidget* _boardWidget;
//    MovesWidget* _movesWidget;
//    QScrollArea* _movesScrollArea;

    /* Return button */
    ClickableLabel*   _returnButton;
};

#endif // GAMEMENU_HPP
