#ifndef PVPMENU_HPP
#define PVPMENU_HPP

#include <QWidget>
#include <QComboBox>
#include <QLabel>
#include <QSlider>

#include "predefined_classes.hpp"

// Command pattern used
class PVPMenu : public QWidget
{
    Q_OBJECT

public:
    explicit PVPMenu();
    virtual ~PVPMenu() override;

    void makeMenuBeforeSwitch();

private slots:
    void variantComboBoxIndexChanged(int index);
    void swapTimeControl();
    void minutesSliderValueChanged(int index);
    void incSecondsSliderValueChanged(int index);
    void returnToMainMenu();

private:
    void init();
    void makePVPMenu();

private:
    QLabel*       _bgLabel;
    QLabel*       _topTextLabel;

    /* Game Variant */
    QLabel*       _gameVariantTextLabel;
    QComboBox*    _gameVariantComboBox;

    /* Time Control */
    QLabel*       _timeControlBgLabel;
    QLabel*       _timeControlTextLabel;
    ToggleSwitch* _timeControlToggleSwitch;
    QLabel*       _minutesSliderTextLabel;
    QLabel*       _minutesSliderNumberLabel;
    QLabel*       _incSecondsTextLabel;
    QLabel*       _incSecondsNumberLabel;
    QSlider*      _minutesSlider;
    QSlider*      _incSecondsSlider;
    bool          _isTimeOn;

    /* Quick Games */
    QLabel*           _quickGamesTextLabel;
    StartGameButton*  _bullet1MButton;
    StartGameButton*  _blitz3MButton;
    StartGameButton*  _blitz3MInc2SecButton;
    StartGameButton*  _blitz5MButton;
    StartGameButton*  _blitz10MButton;
    StartGameButton*  _rapid15MButton;

    /* Color buttons */
    StartGameButton*  _whiteColorButton;
    StartGameButton*  _blackColorButton;
    StartGameButton*  _randomColorButton;

    /* Return button */
    ClickableLabel*   _returnButton;
};

#endif // PVPMENU_HPP
