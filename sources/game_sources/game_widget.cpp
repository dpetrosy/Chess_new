#include <QDebug>

#include "game_widget.hpp"
#include "game_data.hpp"

GameWidget::GameWidget()
{
    /* Init class members */
    init();

    /* Make GameWidget */
    makeGameWidget();
}

GameWidget::~GameWidget()
{
}

/* Singlton pattern realization */
GameWidget* GameWidget::_gameWidget = nullptr;

GameWidget* GameWidget::GetInstance()
{
    if(_gameWidget == nullptr)
        _gameWidget = new GameWidget();

    return _gameWidget;
}

void GameWidget::init()
{
    /* Game data*/
    _gameData = GameData::GetInstance();
}

/* Private functions */
void GameWidget::makeGameWidget()
{

}
