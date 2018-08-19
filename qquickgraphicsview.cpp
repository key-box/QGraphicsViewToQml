#include "qquickgraphicsview.h"
Graphicsview_ne::Graphicsview_ne(QObject *parent){
    this->setRenderHints(QPainter::Antialiasing|QPainter::TextAntialiasing|QPainter::SmoothPixmapTransform);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    fitInView(this->sceneRect(),Qt::IgnoreAspectRatio);

    connect(time,SIGNAL(timeout()),this,SLOT(time_slot()));
}
void Graphicsview_ne::wheelscaleview(int p){
    if(p>0)timescala = 1.09; else timescala =0.9;
    time->start();
    time->setInterval(20);
}
void Graphicsview_ne::time_slot(){
    timer_interval += 1;
    if(timer_interval >= 10){
        timer_interval = 1;
        time->stop();
        return;
    }
    this->scale(timescala,timescala);
}
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
