#include "paths.hpp"

namespace ImagesPaths
{
    QString ImagesPath = ":/images/";

    // Logos images
    QString LogosPath = ImagesPath + "logos/";

    // Menus images
    QString MenusImagesPath = ImagesPath + "menus/";

    //
    // Settings menu paths
    //

    // Settings menu
    QString SettingsPath = MenusImagesPath + "settings/";
    QString SettingsBoardsPath = SettingsPath + "boards/";
    QString SettingsPiecesSetsPath = SettingsPath + "pieces_sets/";

    // Background images
    QString BackgroundsPath = ImagesPath + "backgrounds/";
    QString LightThemeGameBg = "light_theme_game_Bg";
    QString DarkThemeGameBg = "dark_theme_game_Bg";

    // Boards images
    QString BoardsPath = ImagesPath + "boards/";




















    // Steps images
    QString stepsPath = ImagesPath + "steps/";

    // Pieces images
    QString piecesPath = ImagesPath + "pieces/";

    QString AlphaPath = ImagesPath + "Alpha";
    QString CaliforniaPath = ImagesPath + "California";
    QString CardinalPath = ImagesPath + "Cardinal";
    QString CasesPath = ImagesPath + "Cases";
    QString CburnettPath = ImagesPath + "Cburnett";
    QString Chess7Path = ImagesPath + "Chess7";
    QString CondalPath = ImagesPath + "Condal";
    QString FrescaPath = ImagesPath + "Fresca";
    QString GameRoomPath = ImagesPath + "Game_Room";
    QString GlassPath = ImagesPath + "Glass";
    QString ICPiecesPath = ImagesPath + "IC_Pieces";
    QString LolzPath = ImagesPath + "Lolz";
    QString MaestroPath = ImagesPath + "Maestro";
    QString MeridaPath = ImagesPath + "Marida";
    QString NeoPath = ImagesPath + "Neo";
    QString OceanPath = ImagesPath + "Ocean";




    // PVP menu
    QString PVPMenuPath = MenusImagesPath + "pvp/";
    QString ReturnButtonPath = PVPMenuPath + "return_button/";

    QString LightStartButtonsPath = PVPMenuPath + "light_start_buttons/";
    QString LightBullet1MButton = LightStartButtonsPath + "bullet_1M.png";
    QString LightBlitz3MButton = LightStartButtonsPath + "blitz_3M.png";
    QString LightBlitz3MInc2SecButton = LightStartButtonsPath + "blitz_3M_inc2sec.png";
    QString LightBlitz5MButton = LightStartButtonsPath + "blitz_5M.png";
    QString LightBlitz10MButton = LightStartButtonsPath + "blitz_10M.png";
    QString LightRapid15MButton = LightStartButtonsPath + "rapid_15M.png";
    QString LightBlackColorButton = LightStartButtonsPath + "black_color.png";
    QString LightRandomColorButton = LightStartButtonsPath + "random_color.png";
    QString LightWhiteColorButton = LightStartButtonsPath + "white_color.png";
    QString LightReturnButton = ReturnButtonPath + "light_return_button.png";

    QString LightHoverStartButtonsPath = PVPMenuPath + "light_hover_start_buttons/";
    QString LightBullet1MHoverButton = LightHoverStartButtonsPath + "bullet_1M_hover.png";
    QString LightBlitz3MHoverButton = LightHoverStartButtonsPath + "blitz_3M_hover.png";
    QString LightBlitz3MInc2SecHoverButton = LightHoverStartButtonsPath + "blitz_3M_inc2sec_hover.png";
    QString LightBlitz5MHoverButton = LightHoverStartButtonsPath + "blitz_5M_hover.png";
    QString LightBlitz10MHoverButton = LightHoverStartButtonsPath + "blitz_10M_hover.png";
    QString LightRapid15MHoverButton = LightHoverStartButtonsPath + "rapid_15M_hover.png";
    QString LightBlackColorHoverButton = LightHoverStartButtonsPath + "black_color_hover.png";
    QString LightRandomColorHoverButton = LightHoverStartButtonsPath + "random_color_hover.png";
    QString LightWhiteColorHoverButton = LightHoverStartButtonsPath + "white_color_hover.png";

    QString DarkStartButtonsPath = PVPMenuPath + "dark_start_buttons/";
    QString DarkBullet1MButton = DarkStartButtonsPath + "bullet_1M.png";
    QString DarkBlitz3MButton = DarkStartButtonsPath + "blitz_3M.png";
    QString DarkBlitz3MInc2SecButton = DarkStartButtonsPath + "blitz_3M_inc2sec.png";
    QString DarkBlitz5MButton = DarkStartButtonsPath + "blitz_5M.png";
    QString DarkBlitz10MButton = DarkStartButtonsPath + "blitz_10M.png";
    QString DarkRapid15MButton = DarkStartButtonsPath + "rapid_15M.png";
    QString DarkBlackColorButton = DarkStartButtonsPath + "black_color.png";
    QString DarkRandomColorButton = DarkStartButtonsPath + "random_color.png";
    QString DarkWhiteColorButton = DarkStartButtonsPath + "white_color.png";
    QString DarkReturnButton = ReturnButtonPath + "dark_return_button.png";

    QString DarkHoverStartButtonsPath = PVPMenuPath + "dark_hover_start_buttons/";
    QString DarkBullet1MHoverButton = DarkHoverStartButtonsPath + "bullet_1M_hover.png";
    QString DarkBlitz3MHoverButton = DarkHoverStartButtonsPath + "blitz_3M_hover.png";
    QString DarkBlitz3MInc2SecHoverButton = DarkHoverStartButtonsPath + "blitz_3M_inc2sec_hover.png";
    QString DarkBlitz5MHoverButton = DarkHoverStartButtonsPath + "blitz_5M_hover.png";
    QString DarkBlitz10MHoverButton = DarkHoverStartButtonsPath + "blitz_10M_hover.png";
    QString DarkRapid15MHoverButton = DarkHoverStartButtonsPath + "rapid_15M_hover.png";
    QString DarkBlackColorHoverButton = DarkHoverStartButtonsPath + "black_color_hover.png";
    QString DarkRandomColorHoverButton = DarkHoverStartButtonsPath + "random_color_hover.png";
    QString DarkWhiteColorHoverButton = DarkHoverStartButtonsPath + "white_color_hover.png";

    // GameWidget images
    QString GameWidgetPath = ImagesPath + "game_widget/";
    QString GameWidgetReturnButtonPath = GameWidgetPath + "return_button/";

    QString GameWidgetLightReturnButton = GameWidgetReturnButtonPath + "light_return_button.png";
    QString GameWidgetDarkReturnButton = GameWidgetReturnButtonPath + "dark_return_button.png";
}

namespace StepsImages
{
    QString CanGo = ImagesPaths::stepsPath + "can_go.png";
    QString CanBeat = ImagesPaths::stepsPath + "can_beat.png";
    QString CurrentPiece = ImagesPaths::stepsPath + "current_piece.png";
    QString LastStepFrom = ImagesPaths::stepsPath + "last_step_from.png";
    QString LastStepTo = ImagesPaths::stepsPath + "last_step_to.png";
    QString LastStepFromAndCanGo = ImagesPaths::stepsPath + "last_step_from_can_go.png";
    QString Check = ImagesPaths::stepsPath + "check.png";
    QString CurrentPieceAndChecked = ImagesPaths::stepsPath + "current_piece_and_checked.png";
}

namespace StylesPaths
{
    QString StylesPath = ":/styles/";

    // General for menus
    QString MenusStylesPath = StylesPath + "menus_styles/";
    QString lightThemeBgLabelStyle = MenusStylesPath + "light_theme_bg_label.txt";
    QString darkThemeBgLabelStyle = MenusStylesPath + "dark_theme_bg_label.txt";
    QString lightTextStyle = MenusStylesPath + "light_text.txt";
    QString darkTextStyle = MenusStylesPath + "dark_text.txt";
    QString lightBoldTextStyle = MenusStylesPath + "light_bold_text.txt";
    QString darkBoldTextStyle = MenusStylesPath + "dark_bold_text.txt";
    QString lightComboBoxStyle = MenusStylesPath + "light_combobox.txt";
    QString darkComboBoxStyle = MenusStylesPath + "dark_combobox.txt";
    QString lightSliderStyle = MenusStylesPath + "light_slider.txt";
    QString darkSliderStyle = MenusStylesPath + "dark_slider.txt";
    QString lightDimTextStyle = MenusStylesPath + "light_dim_text.txt";
    QString darkDimTextStyle = MenusStylesPath + "dark_dim_text.txt";
    QString lightBoldDimTextStyle = MenusStylesPath + "light_bold_dim_text.txt";
    QString darkBoldDimTextStyle = MenusStylesPath + "dark_bold_dim_text.txt";

    // Main menu
    QString MainMenuStylesPath = MenusStylesPath + "main_menu_styles/";
    QString VersionTextStyle = MainMenuStylesPath + "version_text.txt";
    QString MainMenuButtonStyle = MainMenuStylesPath + "main_menu_button.txt";

    // Settings menu
    QString SettingsMenuStylesPath = MenusStylesPath + "settings_menu_styles/";
    QString hideAndShowButtonStyle = SettingsMenuStylesPath + "hide_and_show_button.txt";
    QString lightThemeButtonsLabelStyle = SettingsMenuStylesPath + "light_theme_buttons_label.txt";
    QString darkThemeButtonsLabelStyle = SettingsMenuStylesPath + "dark_theme_buttons_label.txt";
    QString settingsMenuLightCancelButtonStyle = SettingsMenuStylesPath + "settings_menu_light_cancel_button.txt";
    QString settingsMenuDarkCancelButtonStyle = SettingsMenuStylesPath + "settings_menu_dark_cancel_button.txt";
    QString settingsMenuSaveButtonStyle = SettingsMenuStylesPath + "settings_menu_save_button.txt";

    // PVP menu
    QString PVPMenuStylesPath = MenusStylesPath + "pvp_menu_styles/";
    QString lightTopTextStyle = PVPMenuStylesPath + "light_top_text.txt";
    QString darkTopTextStyle = PVPMenuStylesPath + "dark_top_text.txt";
    QString lightTimeControlBgLabelStyle = PVPMenuStylesPath + "light_time_control_bg_label.txt";
    QString darkTimeControlBgLabelStyle = PVPMenuStylesPath + "dark_time_control_bg_label.txt";
    QString lightQuickGamesTextStyle = PVPMenuStylesPath + "light_quick_games_text.txt";
    QString darkQuickGamesTextStyle = PVPMenuStylesPath + "dark_quick_games_text.txt";
    QString lightQuickGamesButtonStyle = PVPMenuStylesPath + "light_quickgames_button.txt";
    QString darkQuickGamesButtonStyle = PVPMenuStylesPath + "dark_quickgames_button.txt";
    QString lightQuickGamesHoverButtonStyle = PVPMenuStylesPath + "light_quickgames_hover_button.txt";
    QString darkQuickGamesHoverButtonStyle = PVPMenuStylesPath + "dark_quickgames_hover_button.txt";
    QString darkColorButtonStyle = PVPMenuStylesPath + "dark_color_button.txt";
    QString lightVariantComboboxStyle = PVPMenuStylesPath + "light_variant_combobox.txt";
    QString darkVariantComboboxStyle = PVPMenuStylesPath + "dark_variant_combobox.txt";

    // Pieces styles
    QString PiecesStylesPath = StylesPath + "pieces_styles/";
    QString PawnPromButtonsStyle = PiecesStylesPath + "pawn_prom_buttons_style.txt";
}

namespace Sounds
{
    QString SoundsPath = "qrc:/sound/";
    QString StartGameSound = SoundsPath + "startGame.mp3";
    QString Go = SoundsPath + "go.mp3";
    QString Beat = SoundsPath + "beat.mp3";
}
