#ifndef CLICKABLELABEL_HPP
#define CLICKABLELABEL_HPP

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

#endif // CLICKABLELABEL_HPP
