#include "qquickgraphicsscene.h"

#include <QGraphicsItem>
#include <QGraphicsProxyWidget>
#include <QTextEdit>
QQuickGraphicsScene::QQuickGraphicsScene(QObject *parent)
{
    setItemIndexMethod(QGraphicsScene::NoIndex);
    addWidget(new QTextEdit("kkkkkk"));
    QGraphicsProxyWidget *k = addWidget(new QTextEdit("kkkkeeeee"));
    k->moveBy(100,100);

//    for(int i=0;i<=1000;i++){
//        QGraphicsItem * e = this->addEllipse(i*10,0,100,100);
//        e->setFlags(QGraphicsItem::ItemIsSelectable|QGraphicsItem::ItemIsMovable);
//        e->setAcceptDrops(true);
//    }

}
