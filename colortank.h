#ifndef COLORTANK_H
#define COLORTANK_H

#include <QGraphicsItem>


class ColorTank : public QGraphicsItem
{
public:
    ColorTank();

    void setColor(const QColor &color);

protected:
    virtual QRectF boundingRect() const override;
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;
    virtual void dragEnterEvent(QGraphicsSceneDragDropEvent *event) override;
    virtual void dragLeaveEvent(QGraphicsSceneDragDropEvent *event) override;
    virtual void dropEvent(QGraphicsSceneDragDropEvent *event) override;

private:
    void init();

private:
    QColor _color;
    bool _dragOver;

};

#endif // COLORTANK_H
