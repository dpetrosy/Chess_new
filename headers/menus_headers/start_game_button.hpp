#ifndef START_GAME_BUTTON_HPP
#define START_GAME_BUTTON_HPP

#include "menus_helpers.hpp"
#include "clickable_label.hpp"

class StartGameButton : public ClickableLabel
{
    Q_OBJECT

public:
    explicit StartGameButton(QWidget* parent, const StartGameButtons& button);
    virtual ~StartGameButton() override;

private:
    // Enter and leave events
    using QLabel::enterEvent;
    void enterEvent(QEnterEvent* event) override;
    void leaveEvent(QEvent* event) override;

    void changeImg(QString image, QString stylePath);
    void setButtonStr();

private:
    StartGameButtons _button;
    QString          _buttonStr;
};

#endif // START_GAME_BUTTON_HPP
