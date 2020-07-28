#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QtWidgets>
#include "colortank.h"
#include "colorcircle.h"


void test();


int main(int argc, char **argv)
{
    QApplication a(argc, argv);
    test();
    return a.exec();
}

void test()
{
    QGraphicsScene *scene = new QGraphicsScene(-200, -200, 400, 400);
    QGraphicsView *view = new QGraphicsView(scene);

    for (int i = 0; i < 10; ++i) {
        ColorCircle *colorItem = new ColorCircle(QRandomGenerator::global()->generate());
        colorItem->setPos(::sin((i * 6.28) / 10.0) * 150,
                          ::cos((i * 6.28) / 10.0) * 150);

        scene->addItem(colorItem);
    }

    ColorTank *tank = new ColorTank();
    tank->setPos(0, 0);
    scene->addItem(tank);

    view->setRenderHint(QPainter::Antialiasing);
    view->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
    view->setBackgroundBrush(QColor(230, 200, 167));
    view->setWindowTitle("Color Picker");
    view->show();
}
