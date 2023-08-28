#include "start_game_button.hpp"
#include "data_collector.hpp"
#include "paths.hpp"
#include "utils.hpp"

StartGameButton::StartGameButton(QWidget* parent, const StartGameButtons& button)
    : ClickableLabel(parent), _button(button)
{
    setButtonStr();
}

StartGameButton::~StartGameButton()
{}

// Enter and leave events
void StartGameButton::enterEvent(QEnterEvent* event)
{
    bool isDarkTheme = DataCollector::GetInstance()->isDarkTheme();
    this->setCursor(Qt::PointingHandCursor);

    if (isDarkTheme)
    {
        switch (_button)
        {
        default: // Random color
            changeImg(ImagesPaths::DarkRandomColorHoverButton, StylesPaths::darkQuickGamesHoverButtonStyle);
            break;
        case StartGameButtons::Bullet1M:
            changeImg(ImagesPaths::DarkBullet1MHoverButton, StylesPaths::darkQuickGamesHoverButtonStyle);
            break;
        case StartGameButtons::Blitz3M:
            changeImg(ImagesPaths::DarkBlitz3MHoverButton, StylesPaths::darkQuickGamesHoverButtonStyle);
            break;
        case StartGameButtons::Blitz3MInc2Sec:
            changeImg(ImagesPaths::DarkBlitz3MInc2SecHoverButton, StylesPaths::darkQuickGamesHoverButtonStyle);
            break;
        case StartGameButtons::Blitz5M:
            changeImg(ImagesPaths::DarkBlitz5MHoverButton, StylesPaths::darkQuickGamesHoverButtonStyle);
            break;
        case StartGameButtons::Blitz10M:
            changeImg(ImagesPaths::DarkBlitz10MHoverButton, StylesPaths::darkQuickGamesHoverButtonStyle);
            break;
        case StartGameButtons::Rapid15M:
            changeImg(ImagesPaths::DarkRapid15MHoverButton, StylesPaths::darkQuickGamesHoverButtonStyle);
            break;
        case StartGameButtons::BlackColor:
            changeImg(ImagesPaths::DarkBlackColorHoverButton, StylesPaths::darkQuickGamesHoverButtonStyle);
            break;
        case StartGameButtons::WhiteColor:
            changeImg(ImagesPaths::DarkWhiteColorHoverButton, StylesPaths::darkQuickGamesHoverButtonStyle);
            break;
        }
    }
    else
    {
        switch (_button)
        {
        default: // Random color
            changeImg(ImagesPaths::LightRandomColorHoverButton, StylesPaths::lightQuickGamesHoverButtonStyle);
            break;
        case StartGameButtons::Bullet1M:
            changeImg(ImagesPaths::LightBullet1MHoverButton, StylesPaths::lightQuickGamesHoverButtonStyle);
            break;
        case StartGameButtons::Blitz3M:
            changeImg(ImagesPaths::LightBlitz3MHoverButton, StylesPaths::lightQuickGamesHoverButtonStyle);
            break;
        case StartGameButtons::Blitz3MInc2Sec:
            changeImg(ImagesPaths::LightBlitz3MInc2SecHoverButton, StylesPaths::lightQuickGamesHoverButtonStyle);
            break;
        case StartGameButtons::Blitz5M:
            changeImg(ImagesPaths::LightBlitz5MHoverButton, StylesPaths::lightQuickGamesHoverButtonStyle);
            break;
        case StartGameButtons::Blitz10M:
            changeImg(ImagesPaths::LightBlitz10MHoverButton, StylesPaths::lightQuickGamesHoverButtonStyle);
            break;
        case StartGameButtons::Rapid15M:
            changeImg(ImagesPaths::LightRapid15MHoverButton, StylesPaths::lightQuickGamesHoverButtonStyle);
            break;
        case StartGameButtons::BlackColor:
            changeImg(ImagesPaths::LightBlackColorHoverButton, StylesPaths::lightQuickGamesHoverButtonStyle);
            break;
        case StartGameButtons::WhiteColor:
            changeImg(ImagesPaths::LightWhiteColorHoverButton, StylesPaths::lightQuickGamesHoverButtonStyle);
            break;
        }
    }

    QLabel::enterEvent(event);
}

void StartGameButton::leaveEvent(QEvent* event)
{
    bool isDarkTheme = DataCollector::GetInstance()->isDarkTheme();

    if (isDarkTheme)
    {
        switch (_button)
        {
        default: // Random color
            changeImg(ImagesPaths::DarkRandomColorButton, StylesPaths::darkQuickGamesButtonStyle);
            break;
        case StartGameButtons::Bullet1M:
            changeImg(ImagesPaths::DarkBullet1MButton, StylesPaths::darkQuickGamesButtonStyle);
            break;
        case StartGameButtons::Blitz3M:
            changeImg(ImagesPaths::DarkBlitz3MButton, StylesPaths::darkQuickGamesButtonStyle);
            break;
        case StartGameButtons::Blitz3MInc2Sec:
            changeImg(ImagesPaths::DarkBlitz3MInc2SecButton, StylesPaths::darkQuickGamesButtonStyle);
            break;
        case StartGameButtons::Blitz5M:
            changeImg(ImagesPaths::DarkBlitz5MButton, StylesPaths::darkQuickGamesButtonStyle);
            break;
        case StartGameButtons::Blitz10M:
            changeImg(ImagesPaths::DarkBlitz10MButton, StylesPaths::darkQuickGamesButtonStyle);
            break;
        case StartGameButtons::Rapid15M:
            changeImg(ImagesPaths::DarkRapid15MButton, StylesPaths::darkQuickGamesButtonStyle);
            break;
        case StartGameButtons::BlackColor:
            changeImg(ImagesPaths::DarkBlackColorButton, StylesPaths::darkQuickGamesButtonStyle);
            break;
        case StartGameButtons::WhiteColor:
            changeImg(ImagesPaths::DarkWhiteColorButton, StylesPaths::darkQuickGamesButtonStyle);
            break;
        }
    }
    else
    {
        switch (_button)
        {
        default: // Random color
            changeImg(ImagesPaths::LightRandomColorButton, StylesPaths::lightQuickGamesButtonStyle);
            break;
        case StartGameButtons::Bullet1M:
            changeImg(ImagesPaths::LightBullet1MButton, StylesPaths::lightQuickGamesButtonStyle);
            break;
        case StartGameButtons::Blitz3M:
            changeImg(ImagesPaths::LightBlitz3MButton, StylesPaths::lightQuickGamesButtonStyle);
            break;
        case StartGameButtons::Blitz3MInc2Sec:
            changeImg(ImagesPaths::LightBlitz3MInc2SecButton, StylesPaths::lightQuickGamesButtonStyle);
            break;
        case StartGameButtons::Blitz5M:
            changeImg(ImagesPaths::LightBlitz5MButton, StylesPaths::lightQuickGamesButtonStyle);
            break;
        case StartGameButtons::Blitz10M:
            changeImg(ImagesPaths::LightBlitz10MButton, StylesPaths::lightQuickGamesButtonStyle);
            break;
        case StartGameButtons::Rapid15M:
            changeImg(ImagesPaths::LightRapid15MButton, StylesPaths::lightQuickGamesButtonStyle);
            break;
        case StartGameButtons::BlackColor:
            changeImg(ImagesPaths::LightBlackColorButton, StylesPaths::lightQuickGamesButtonStyle);
            break;
        case StartGameButtons::WhiteColor:
            changeImg(ImagesPaths::LightWhiteColorButton, StylesPaths::lightQuickGamesButtonStyle);
            break;
        }
    }

    QLabel::leaveEvent(event);
}

// Private functions
void StartGameButton::changeImg(QString image, QString stylePath)
{
    this->setPixmap(QPixmap(image));
    ::setStyleSheet(this, stylePath);
}

void StartGameButton::setButtonStr()
{
    switch (_button)
    {
    default:
        _buttonStr = StartGameButtonsStr::RandomColor;
        break;
    case StartGameButtons::Bullet1M:
        _buttonStr = StartGameButtonsStr::Bullet1M;
        break;
    case StartGameButtons::Blitz3M:
        _buttonStr = StartGameButtonsStr::Blitz3M;
        break;
    case StartGameButtons::Blitz3MInc2Sec:
        _buttonStr = StartGameButtonsStr::Blitz3MInc2Sec;
        break;
    case StartGameButtons::Blitz5M:
        _buttonStr = StartGameButtonsStr::Blitz5M;
        break;
    case StartGameButtons::Blitz10M:
        _buttonStr = StartGameButtonsStr::Blitz10M;
        break;
    case StartGameButtons::Rapid15M:
        _buttonStr = StartGameButtonsStr::Rapid15M;
        break;
    case StartGameButtons::WhiteColor:
        _buttonStr = StartGameButtonsStr::WhiteColor;
        break;
    case StartGameButtons::BlackColor:
        _buttonStr = StartGameButtonsStr::BlackColor;
        break;
    }
}
