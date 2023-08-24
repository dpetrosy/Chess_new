#ifndef UTILS_HPP
#define UTILS_HPP

#include <QPushButton>
#include <QLabel>

//#include "pieces_helpers.hpp"

void     setPushButtonSize(QPushButton *button, int width, int height);
void     setPushButtonFont(QPushButton *button, int font);
void     setLabelTextFont(QLabel* label, int font);
void     setStyleSheet(QWidget* obj, QString path);
void     setStyleSheetByTheme(QWidget* obj, QString lightStylePath, QString darkStylePath, bool isDarkTheme);
QString  replaceSpaceInString(QString str);


//void     setQLabelPictureByTheme(QLabel* label, bool isDarkTheme, QString lightThemePicturePath, QString darkThemePicturePath);
//void     copyVector2D(CharVector2D& dest, CharVector2D& source, int size);
//void     resetCharVector2D(CharVector2D& vector2D, int size, char symbol);

#endif // UTILS_HPP
