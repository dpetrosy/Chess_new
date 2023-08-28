#include <QMouseEvent>
#include <QDebug>
#include <Qt>

#include "clickablelabel.hpp"

ClickableLabel::ClickableLabel(QWidget* parent) : QLabel(parent)
{}

ClickableLabel::~ClickableLabel()
{}

// Mouse press events
void ClickableLabel::mousePressEvent(QMouseEvent* event)
{
    if(event->buttons() & Qt::LeftButton)
        emit clickedLeftButton();
}
