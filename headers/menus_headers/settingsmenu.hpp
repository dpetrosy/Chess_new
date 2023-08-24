#ifndef SETTINGS_MENU_HPP
#define SETTINGS_MENU_HPP

#include <QWidget>
#include <QLabel>
#include <QComboBox>
#include <QPushButton>

#include "menus_helpers.hpp"
#include "predefined_classes.hpp"

class SettingsMenu : public QWidget
{
    Q_OBJECT

public:
    explicit SettingsMenu(MainWindow* mainWindow);
    virtual ~SettingsMenu();

    //bool            getTheme();
    //SettingsData&   getData();
    void            makeMenuBeforeSwitch();

public slots:
    void saveButtonClicked();
    void cancelButtonClicked();


private slots:
    void bkgImageComboBoxIndexChanged(int index);
    void pieceSetsComboBoxIndexChanged(int index);
    void boardComboBoxIndexChanged(int index);
    void languageComboBoxIndexChanged(int index);
    void swapMenuTheme();
    void swapSound();

private:
    void init();
    void initSettingsData();

    void    makeSettingsMenu(MainWindow* mainWindow);
    void    hideAndShowMenu();
    void    changeMenuTheme();

private:
    SettingsData  _tempData;
    QLabel*       _bgLabel;
    QLabel*       _boardLabel;
    QLabel*       _piecesLabel;

    // Background image
    QLabel*       _bgImageTextLabel;
    QComboBox*    _bgImageComboBox;

    // Piece sets
    QLabel*       _pieceSetsTextLabel;
    QComboBox*    _pieceSetsComboBox;

    // Board
    QLabel*       _boardTextLabel;
    QComboBox*    _boardComboBox;

    // Language
    QLabel*       _languageTextLabel;
    QComboBox*    _languageComboBox;

    // Sound
    QLabel*       _soundTextLabel;
    ToggleSwitch* _soundToggleSwitch;

    // Theme
    QLabel*       _themeTextLabel;
    ToggleSwitch* _themeToggleSwitch;

    // Buttons background label
    QLabel*       _buttonsBgLabel;

    // Confirm Buttons
    QPushButton*  _savePushButton;
    QPushButton*  _cancelPushButton;

    // Menu hide and show button
    bool          _isMenuVisible;
    QPushButton*  _hideAndShowButton;
};

#endif // SETTINGS_MENU_HPP
