#ifndef GAME_WIDGET_HPP
#define GAME_WIDGET_HPP

#include <QWidget>

#include "predefined_classes.hpp"

/* Singlton pattern used */
class GameWidget : public QWidget
{
    Q_OBJECT

public:
    /* Singleton pattern realization */
    GameWidget(GameWidget& other) = delete;
    GameWidget& operator=(const GameWidget&) = delete;
    static GameWidget* GetInstance();
    virtual ~GameWidget() override;

private:
    explicit GameWidget();

    void init();
    void makeGameWidget();

private:
    /* Singlton pattern realization */
    static GameWidget*  _gameWidget;

    /* Game data */
    GameData* _gameData;
};

#endif // GAME_WIDGET_HPP
