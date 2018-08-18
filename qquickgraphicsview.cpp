#include "qquickgraphicsview.h"
//--------------------------------------------------------
QQuickGraphicsview::QQuickGraphicsview(QQuickItem * parent):
    QQuickPaintedItem(parent)
{
    this->setRenderTarget(QQuickPaintedItem::FramebufferObject);
    this->setAcceptHoverEvents(true);
    this->setAcceptedMouseButtons(Qt::AllButtons);
    this->setFlag(ItemAcceptsInputMethod, true);

     graphics = new Graphicsview_ne(this);
     timer = new QTimer(this);

    connect(this,SIGNAL(mousePressEvent_signals(QMouseEvent*)),graphics,SLOT(mousePressEvent_slot(QMouseEvent*)));
    connect(this,SIGNAL(mouseDoubleClickEvent_signals(QMouseEvent*)),graphics,SLOT(mouseDoubleClickEvent_slot(QMouseEvent*)));
    connect(this,SIGNAL(mouseMoveEvent_signals(QMouseEvent*)),graphics,SLOT(mouseMoveEvent_slot(QMouseEvent*)));
    connect(this,SIGNAL(mouseReleaseEvent_signals(QMouseEvent*)),graphics,SLOT(mouseReleaseEvent_slot(QMouseEvent*)));
    connect(this,SIGNAL(wheelEvent_signals(QWheelEvent*)),graphics,SLOT(wheelEvent_slot(QWheelEvent*)));
    connect(this,SIGNAL(keyPressEvent_signals(QKeyEvent*)),graphics,SLOT(keyPressEvent_slot(QKeyEvent*)));
    connect(this,SIGNAL(keyReleaseEvent_signals(QKeyEvent*)),graphics,SLOT(keyReleaseEvent_slot(QKeyEvent*)));
    connect(timer,SIGNAL(timeout()),this,SLOT(timer_slot()));

    timer->start(28);
    pixmap = graphics->grab(graphics->rect());
}
void QQuickGraphicsview::paint(QPainter *painter){
    painter->drawPixmap(0,0,pixmap);
}
void QQuickGraphicsview::timer_slot(){
    pixmap = graphics->grab(graphics->rect());
//    pixmap = QPixmap::fromImage(pixmap.toImage().mirrored(false,true));

    graphics->resize(this->size().width(),this->size().height());
    graphics->move(mapToGlobal(QPointF(0,0)).toPoint());

    this->update();
}
