#include <QFont>
#include <QFile>

#include "utils.hpp"

void setPushButtonSize(QPushButton *button, int width, int height)
{
    button->setSizeIncrement(width, height);
    button->setMinimumSize(width, height);
}

void setPushButtonFont(QPushButton *button, int font)
{
    QFont buttonFont = button->font();
    buttonFont.setPointSize(font);
    button->setFont(buttonFont);
}

void setQLabelTextFont(QLabel* label, int font)
{
    QFont buttonFont = label->font();
    buttonFont.setPointSize(font);
    label->setFont(buttonFont);
}

void setStyleSheet(QWidget* obj, const QString& path)
{
    QFile file;
    file.setFileName(path);
    file.open(QFile::ReadOnly);
    QString styleSheet = QLatin1String(file.readAll());
    obj->setStyleSheet(styleSheet);
    file.close();
}

void setStyleSheetByTheme(QWidget* obj, const QString& lightStylePath, const QString& darkStylePath, bool isDarkTheme)
{
    QString path;

    if (isDarkTheme)
        path = darkStylePath;
    else
        path = lightStylePath;

    setStyleSheet(obj, path);
}

QString replaceSpaceInString(const QString& str)
{
    QString temp;

    for (auto it = str.begin(); it != str.end(); ++it)
    {
        if (*it == ' ')
            temp += '_';
        else
            temp += *it;
    }

    return temp;
}

QString getBgImageStrByNumber(const BgImages& bgImage)
{
    switch (bgImage)
    {
    default: /* BgImages::TheRook */
        return BgImagesStr::TheRook;
    case BgImages::AngelView:
        return BgImagesStr::AngelView;
    case BgImages::Blacked:
        return BgImagesStr::Blacked;
    case BgImages::BravePawn:
        return BgImagesStr::BravePawn;
    case BgImages::Checkmate:
        return BgImagesStr::Checkmate;
    case BgImages::Dark_Chess:
        return BgImagesStr::Dark_Chess;
    case BgImages::Emperors:
        return BgImagesStr::Emperors;
    case BgImages::FaceToFace:
        return BgImagesStr::FaceToFace;
    case BgImages::IAmTheKing:
        return BgImagesStr::IAmTheKing;
    case BgImages::Landscape:
        return BgImagesStr::Landscape;
    case BgImages::Legends:
        return BgImagesStr::Legends;
    case BgImages::Shadow:
        return BgImagesStr::Shadow;
    case BgImages::StrongKnight:
        return BgImagesStr::StrongKnight;
    case BgImages::TheBishop:
        return BgImagesStr::TheBishop;
    case BgImages::TheKing:
        return BgImagesStr::TheKing;
    case BgImages::TheKnight:
        return BgImagesStr::TheKnight;
    case BgImages::TheQueen:
        return BgImagesStr::TheQueen;
    case BgImages::TopView:
        return BgImagesStr::TopView;
    case BgImages::WhiteThemeGameBg:
        return BgImagesStr::WhiteThemeGameBg;
    case BgImages::DarkThemeGameBg:
        return BgImagesStr::DarkThemeGameBg;
    }
}

QString getLanguageStrByNumber(const Languages& language)
{
    switch (language)
    {
    case Languages::Armenian:
        return LanguagesStr::Armenian;
    case Languages::Russian:
        return LanguagesStr::Russian;
    default:
        return LanguagesStr::English;
    }
}

QString getPieceSetStrByNumber(const PieceSets& pieceSet)
{
    switch (pieceSet)
    {
    case PieceSets::Alpha:
        return PieceSetsStr::Alpha;
    case PieceSets::California:
        return PieceSetsStr::California;
    case PieceSets::Cardinal:
        return PieceSetsStr::Cardinal;
    case PieceSets::Cases:
        return PieceSetsStr::Cases;
    case PieceSets::Chess7:
        return PieceSetsStr::Chess7;
    case PieceSets::Condal:
        return PieceSetsStr::Condal;
    case PieceSets::Fresca:
        return PieceSetsStr::Fresca;
    case PieceSets::GameRoom:
        return PieceSetsStr::GameRoom;
    case PieceSets::Glass:
        return PieceSetsStr::Glass;
    case PieceSets::ICPieces:
        return PieceSetsStr::ICPieces;
    case PieceSets::Lolz:
        return PieceSetsStr::Lolz;
    case PieceSets::Maestro:
        return PieceSetsStr::Maestro;
    case PieceSets::Merida:
        return PieceSetsStr::Merida;
    case PieceSets::Neo:
        return PieceSetsStr::Neo;
    case PieceSets::Ocean:
        return PieceSetsStr::Ocean;
    default:
        return PieceSetsStr::Cburnett;
    }
}

QString getBoardStrByNumber(const Boards& board)
{
    switch (board)
    {
    case Boards::Bit8:
        return BoardsStr::Bit8;
    case Boards::Bases:
        return BoardsStr::Bases;
    case Boards::Blue:
        return BoardsStr::Blue;
    case Boards::Brown:
        return BoardsStr::Brown;
    case Boards::Bubblegum:
        return BoardsStr::Bubblegum;
    case Boards::BurledWood:
        return BoardsStr::BurledWood;
    case Boards::DarkWood:
        return BoardsStr::DarkWood;
    case Boards::Dash:
        return BoardsStr::Dash;
    case Boards::Glass:
        return BoardsStr::Glass;
    case Boards::Graffiti:
        return BoardsStr::Graffiti;
    case Boards::Green:
        return BoardsStr::Green;
    case Boards::IcySea:
        return BoardsStr::IcySea;
    case Boards::Light:
        return BoardsStr::Light;
    case Boards::Lolz:
        return BoardsStr::Lolz;
    case Boards::Marble:
        return BoardsStr::Marble;
    case Boards::Metal:
        return BoardsStr::Metal;
    case Boards::Neon:
        return BoardsStr::Neon;
    case Boards::Newspaper:
        return BoardsStr::Newspaper;
    case Boards::Orange:
        return BoardsStr::Orange;
    case Boards::Parchment:
        return BoardsStr::Parchment;
    case Boards::Purple:
        return BoardsStr::Purple;
    case Boards::Red:
        return BoardsStr::Red;
    case Boards::Sand:
        return BoardsStr::Sand;
    case Boards::Sky:
        return BoardsStr::Sky;
    case Boards::Stone:
        return BoardsStr::Stone;
    case Boards::Tan:
        return BoardsStr::Tan;
    case Boards::Tournament:
        return BoardsStr::Tournament;
    case Boards::Translucent:
        return BoardsStr::Translucent;
    case Boards::Walnut:
        return BoardsStr::Walnut;
    default:
        return BoardsStr::Brown;
    }
}

void setQLabelImageByTheme(QLabel* label, QString lightThemePicturePath, QString darkThemePicturePath, bool isDarkTheme)
{
    if (isDarkTheme)
        label->setPixmap(QPixmap(darkThemePicturePath));
    else
        label->setPixmap(QPixmap(lightThemePicturePath));
}




//void copyVector2D(CharVector2D& dest, CharVector2D& source, int size)
//{
//    for (int i = 0; i < size; ++i)
//        for (int j = 0; j < size; ++j)
//            dest[i][j] = source[i][j];
//}

//void resetCharVector2D(CharVector2D& vector2D, int size, char symbol)
//{
//    for (int i = 0; i < size; ++i)
//        for (int j = 0; j < size; ++j)
//            vector2D[i][j] = symbol;
//}
