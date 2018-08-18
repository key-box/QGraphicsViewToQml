#ifndef QQUICKGRAPHICSVIEW_H
#define QQUICKGRAPHICSVIEW_H

#include <QObject>
#include <QQuickItem>
#include <QQuickPaintedItem>
#include <QGraphicsView>

#include <QPaintEvent>
#include <QMouseEvent>
#include <QMoveEvent>
#include <QHoverEvent>
#include <QKeyEvent>

#include <QPainter>
#include <QSizeF>
#include <QDebug>
#include <QtCore/qmap.h>
#include <QTimer>
class Graphicsview_ne : public QGraphicsView
{
    Q_OBJECT
public:
    Graphicsview_ne(QObject * parent = 0){
        this->setRenderHints(QPainter::Antialiasing|QPainter::TextAntialiasing|QPainter::SmoothPixmapTransform);
        setHorizontalScrollBarPolicy(	Qt::ScrollBarAlwaysOff);
        setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
         //   setDragMode(QGraphicsView::RubberBandDrag);
         //   setRubberBandSelectionMode(Qt::ContainsItemBoundingRect);
    }
protected:
signals:
public slots:
    void mousePressEvent_slot(QMouseEvent *event){this->mousePressEvent(event);}
    void mouseDoubleClickEvent_slot(QMouseEvent *event){this->mouseDoubleClickEvent(event);}
    void mouseMoveEvent_slot(QMouseEvent *event){this->mouseMoveEvent(event);}
    void mouseReleaseEvent_slot(QMouseEvent *event){this->mouseReleaseEvent(event);}
    void wheelEvent_slot(QWheelEvent *event){this->wheelEvent(event);}
    void keyPressEvent_slot(QKeyEvent *event){this->keyPressEvent(event);}
    void keyReleaseEvent_slot(QKeyEvent *event){this->keyReleaseEvent(event);}
private:
};

class QQuickGraphicsview : public QQuickPaintedItem
{
    Q_OBJECT
    Q_PROPERTY(QGraphicsScene* Scene READ Scene WRITE setScene NOTIFY SceneChanged SCRIPTABLE true)
public:
    QQuickGraphicsview(QQuickItem * parent = 0);
    QGraphicsScene * Scene(){return graphics->scene();emit SceneChanged(graphics->scene());}
    void setScene(QGraphicsScene *Scene){graphics->setScene(Scene);emit SceneChanged(graphics->scene());}
protected:
    void paint(QPainter *painter);
    void mousePressEvent(QMouseEvent *event){emit mousePressEvent_signals(event);}
    void mouseDoubleClickEvent(QMouseEvent *event){emit mouseDoubleClickEvent_signals(event);}
    void mouseMoveEvent(QMouseEvent *event){emit mouseMoveEvent_signals(event);}
    void mouseReleaseEvent(QMouseEvent *event){emit mouseReleaseEvent_signals(event);}
    void wheelEvent(QWheelEvent *event){emit wheelEvent_signals(event);}
    void keyPressEvent(QKeyEvent *event){emit keyPressEvent_signals(event);}
    void keyReleaseEvent(QKeyEvent *event){emit keyReleaseEvent_signals(event);}
signals:
    void mousePressEvent_signals(QMouseEvent *event);
    void mouseDoubleClickEvent_signals(QMouseEvent *event);
    void mouseMoveEvent_signals(QMouseEvent *event);
    void mouseReleaseEvent_signals(QMouseEvent *event);
    void wheelEvent_signals(QWheelEvent *event);
    void keyPressEvent_signals(QKeyEvent *event);
    void keyReleaseEvent_signals(QKeyEvent *event);

    void SceneChanged(QGraphicsScene * scene);
public slots:
    void timer_slot();
private:
    Graphicsview_ne * graphics;
    QTimer * timer;
    QPixmap  pixmap;
};
#endif // QQUICKGRAPHICSVIEW_H
