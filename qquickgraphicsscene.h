#ifndef QQUICKGRAPHICSSCENE_H
#define QQUICKGRAPHICSSCENE_H

#include <QObject>
#include <QGraphicsScene>
#include <QGraphicsView>

#include <QGraphicsSceneMouseEvent>
#include <QGraphicsSceneMoveEvent>
#include <QGraphicsSceneResizeEvent>
#include <QGraphicsSceneWheelEvent>
#include <QGraphicsSceneHoverEvent>
#include <QGraphicsSceneHelpEvent>
#include <QGraphicsSceneContextMenuEvent>
#include <QGraphicsSceneDragDropEvent>

#include <QRect>
#include <QRectF>
#include <QPoint>
#include <QPointF>

#include <QDebug>
class QQuickGraphicsScene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit QQuickGraphicsScene(QObject *parent = nullptr);

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event){
        if(this->views().at(0)->dragMode() == QGraphicsView::ScrollHandDrag)return;
        QGraphicsScene::mousePressEvent(event);}
//    void mouseMoveEvent(QGraphicsSceneMouseEvent *event){

//        QGraphicsScene::mouseMoveEvent(event);}
//    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event){

//        QGraphicsScene::mouseReleaseEvent(event);}
//    void wheelEvent(QGraphicsSceneWheelEvent *event){

//        QGraphicsScene::wheelEvent(event);}
signals:

public slots:

private:

};

#endif // QQUICKGRAPHICSSCENE_H
