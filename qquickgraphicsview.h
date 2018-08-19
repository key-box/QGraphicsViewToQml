#ifndef QQUICKGRAPHICSVIEW_H
#define QQUICKGRAPHICSVIEW_H
#include <QObject>
#include <QQuickPaintedItem>
#include <QGraphicsView>

#include <QPaintEvent>
#include <QMouseEvent>
#include <QMoveEvent>
#include <QHoverEvent>
#include <QKeyEvent>

#include <QPainter>
#include <QSizeF>
#include <QtCore/qmap.h>
#include <QTimer>

#include <QDebug>
class ViewTool : public QObject
{
    Q_OBJECT
public:
    ViewTool() {}
    void Begin(){beginmousepoint = true;}
    void End(bool endDate){beginmousepoint = false;if(endDate)mousepoint.clear();}
    void addpoint(QPoint point){mousepoint.append(point);}
    QList<QPoint>*constpointf(){return &mousepoint;}
    QPoint  currentpointf(){return mousepoint.at(mousepoint.count()-1);}
    QPoint movepoint(){return mousemovepoint;}
    void setmovepoint(QPoint p){mousemovepoint = p;}
private:
    QList<QPoint> mousepoint;
    QPoint mousemovepoint;
    bool beginmousepoint;
};

class Graphicsview_ne : public QGraphicsView
{
    Q_OBJECT
public:
    Graphicsview_ne(QObject * parent = 0);
    void mousePressEvent_propert(QMouseEvent *event){this->mousePressEvent(event);}
    void mouseDoubleClickEvent_propert(QMouseEvent *event){this->mouseDoubleClickEvent(event);}
    void mouseMoveEvent_propert(QMouseEvent *event){this->mouseMoveEvent(event);}
    void mouseReleaseEvent_propert(QMouseEvent *event){this->mouseReleaseEvent(event);}
    void wheelEvent_propert(QWheelEvent *event){this->wheelEvent(event);}
    void keyPressEvent_propert(QKeyEvent *event){this->keyPressEvent(event);}
    void keyReleaseEvent_propert(QKeyEvent *event){this->keyReleaseEvent(event);}
    void wheelscaleview(int p);
    bool view_scale = false;
    bool view_rotate = false;
protected:
    void mousePressEvent(QMouseEvent *event){

//        viewtool.Begin();
//        viewtool.addpoint(event->pos());
       QGraphicsView::mousePressEvent(event);
    }
    void mouseMoveEvent(QMouseEvent *event){

        QGraphicsView::mouseMoveEvent(event);
    }
    void wheelEvent(QWheelEvent *event){
        if(view_scale == true){
            this->centerOn(mapToScene(event->pos()));
            wheelscaleview(event->delta());
        }
        QGraphicsView::wheelEvent(event);
    }
//    void keyPressEvent(QKeyEvent *event){qDebug("keypress");}
//    void keyReleaseEvent(QKeyEvent *event){qDebug("key");}
signals:
    void mousePressEvent_signals(QMouseEvent *event);
    void mouseDoubleClickEvent_signals(QMouseEvent *event);
    void mouseMoveEvent_signals(QMouseEvent *event);
    void mouseReleaseEvent_signals(QMouseEvent *event);
    void wheelEvent_signals(QWheelEvent *event);
    void keyPressEvent_signals(QKeyEvent *event);
    void keyReleaseEvent_signals(QKeyEvent *event);
public slots:
    void time_slot();
private:
    ViewTool viewtool;
    QTimer * time = new QTimer(this);
    int timer_interval = 0;
    float timescala = 1;
};
//-------------------------------------------------------------
class QQuickGraphicsview : public QQuickPaintedItem
{
    Q_OBJECT
    Q_PROPERTY(QGraphicsScene* scene READ scene WRITE setscene NOTIFY SceneChanged SCRIPTABLE true)
public:
    QQuickGraphicsview(QQuickItem * parent = 0);
    QGraphicsScene * scene(){return graphics->scene();emit SceneChanged(graphics->scene());}
    void setscene(QGraphicsScene *Scene){graphics->setScene(Scene);emit SceneChanged(graphics->scene());}
    Q_INVOKABLE void wheelviewscale(bool b){graphics->view_scale = b;}
    Q_INVOKABLE void mousedragmode(int m){
        switch (m) {
        case 0:
            graphics->setDragMode(QGraphicsView::NoDrag);
            return;
        case 1:
            graphics->setDragMode(QGraphicsView::ScrollHandDrag);
            return;
        case 2:
            graphics->setDragMode(QGraphicsView::RubberBandDrag);
            graphics->setRubberBandSelectionMode(Qt::ContainsItemBoundingRect);
            return;
        default:
            return;
        }}
    Q_INVOKABLE void rightrotate(bool b){graphics->view_rotate = b;}
protected:
    void paint(QPainter *painter);
    void mousePressEvent(QMouseEvent *event){graphics->mousePressEvent_propert(event);this->setFocus(true);emit mousePressEvent_signals(event);}
    void mouseDoubleClickEvent(QMouseEvent *event){graphics->mouseDoubleClickEvent_propert(event);emit mouseDoubleClickEvent_signals(event);}
    void mouseMoveEvent(QMouseEvent *event){graphics->mouseMoveEvent_propert(event);emit mouseMoveEvent_signals(event);}
    void mouseReleaseEvent(QMouseEvent *event){graphics->mouseReleaseEvent_propert(event);emit mouseReleaseEvent_signals(event);}
    void wheelEvent(QWheelEvent *event){graphics->wheelEvent_propert(event);emit wheelEvent_signals(event);}
    void keyPressEvent(QKeyEvent *event){graphics->keyPressEvent_propert(event);emit keyPressEvent_signals(event);}
    void keyReleaseEvent(QKeyEvent *event){graphics->keyReleaseEvent_propert(event);emit keyReleaseEvent_signals(event);}
signals:
    void mousePressEvent_signals(QMouseEvent *event);
    void mouseDoubleClickEvent_signals(QMouseEvent *event);
    void mouseMoveEvent_signals(QMouseEvent *event);
    void mouseReleaseEvent_signals(QMouseEvent *event);
    void wheelEvent_signals(QWheelEvent *event);
    void keyPressEvent_signals(QKeyEvent *event);
    void keyReleaseEvent_signals(QKeyEvent *event);

    void SceneChanged(QGraphicsScene * scene);
private slots:
    void timer_slot();
private:
    Graphicsview_ne * graphics;
    QTimer * timer;
    QPixmap  pixmap;
};
#endif // QQUICKGRAPHICSVIEW_H
