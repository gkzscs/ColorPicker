#include "colorcircle.h"
#include <QPainter>
#include <QtWidgets>


ColorCircle::ColorCircle(const QColor &color)
    : _color(color)
{
    init();
}

QRectF ColorCircle::boundingRect() const
{
    return QRectF(-15, -15, 30, 30);
}

void ColorCircle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option)
    Q_UNUSED(widget)

    painter->setRenderHint(QPainter::Antialiasing);
    painter->setPen(Qt::NoPen);
    painter->setBrush(Qt::darkGray);
    painter->drawEllipse(boundingRect().translated(3, 3));
    painter->setPen(Qt::black);
    painter->setBrush(_color);
    painter->drawEllipse(boundingRect());
}

void ColorCircle::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    Q_UNUSED(event)

    setCursor(Qt::ClosedHandCursor);
}

void ColorCircle::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    QDrag *drag = new QDrag(event->widget());
    QMimeData *mimeData = new QMimeData();
    drag->setMimeData(mimeData);

    mimeData->setText(toolTip());
    mimeData->setColorData(_color);

    // Add pixmap
    QPixmap pixmap(34, 34);
    QPainter painter(&pixmap);
    painter.translate(15, 15);
    painter.setRenderHint(QPainter::Antialiasing);
    paint(&painter, nullptr, nullptr);
    painter.end();

    pixmap.setMask(pixmap.createHeuristicMask());

    drag->setPixmap(pixmap);
    drag->setHotSpot(QPoint(15, 20));

    drag->exec();
}

void ColorCircle::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    Q_UNUSED(event)

    setCursor(Qt::OpenHandCursor);
}

void ColorCircle::init()
{
    QString tip = "QColor: rgba(%1, %2, %3, %4)";
    setToolTip(tip);
    setCursor(Qt::OpenHandCursor);
    setAcceptedMouseButtons(Qt::LeftButton);
}


