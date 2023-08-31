#ifndef CLICKABLE_LABEL_HPP
#define CLICKABLE_LABEL_HPP

#include <QLabel>

class ClickableLabel : public QLabel
{
    Q_OBJECT

public:
    explicit ClickableLabel(QWidget* parent = nullptr);
    ~ClickableLabel();

signals:
    void clickedLeftButton();

private:
    virtual void mousePressEvent(QMouseEvent* event);
};

#endif // CLICKABLE_LABEL_HPP
