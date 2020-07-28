#include "colortank.h"
#include <QtWidgets>


ColorTank::ColorTank()
{
    init();
}

void ColorTank::setColor(const QColor &color)
{
    _color = color;
    update();
}

QRectF ColorTank::boundingRect() const
{
    return QRectF(-40, -40, 80, 80);
}

void ColorTank::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option)
    Q_UNUSED(widget)

    painter->setRenderHint(QPainter::Antialiasing);
    painter->setBrush(_dragOver ? _color.light(130) : _color);
    painter->drawEllipse(boundingRect());
}

void ColorTank::dragEnterEvent(QGraphicsSceneDragDropEvent *event)
{
    if (event->mimeData()->hasColor())
    {
        event->setAccepted(true);
        _dragOver = true;
        update();
    }
    else event->setAccepted(false);
}

void ColorTank::dragLeaveEvent(QGraphicsSceneDragDropEvent *event)
{
    Q_UNUSED(event)

    _dragOver = false;
    update();
}

void ColorTank::dropEvent(QGraphicsSceneDragDropEvent *event)
{
    if (event->mimeData()->hasColor())
    {
        setColor(qvariant_cast<QColor>(event->mimeData()->colorData()));
    }
    _dragOver = false;
}

void ColorTank::init()
{
    _dragOver = false;
    _color = QRandomGenerator::global()->generate();

    setColor(_color);
    setAcceptDrops(true);
}



