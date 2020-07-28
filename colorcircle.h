#ifndef COLORCIRCLE_H
#define COLORCIRCLE_H

#include <QGraphicsItem>


class ColorCircle : public QGraphicsItem
{
public:
    ColorCircle(const QColor &color);

protected:
    virtual QRectF boundingRect() const override;
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;

    virtual void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    virtual void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;

private:
    void init();

private:
    QColor _color;

};

#endif // COLORCIRCLE_H
