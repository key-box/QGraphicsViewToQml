#include "mainwindow.h"
#include "mywidget.h"
#include "mycolor.h"
#include "qmlqgraphcisview.h"
#include "widgeteventd.h"
#include "qquickgraphicsview.h"
#include "qquickgraphicsscene.h"
#include <QApplication>

#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include <QQuickWidget>
#include <QQuickView>
#include <QQmlContext>

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsWidget>

#include <QVector>
#include <QObject>
#include <QMoveEvent>

#include <QGraphicsDropShadowEffect>

#include <QRect>

#include <QQmlEngine>
#include <QQmlComponent>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

//    MainWindow w;
//    w.show();

//    mywidget widget0;
//    widget0.show();
//    my1widget widget1;
//    widget1.show();
//    QObject::connect(&widget1,SIGNAL(mousePressEvent_signal(QMouseEvent*))
//                     ,&widget0,SLOT(mousepress_slots(QMouseEvent*)));
//    qmlRegisterType<QRect>("na.qt.QtdataClass",1.0,"Rect");

    qmlRegisterType<QQuickGraphicsScene>("na.qt.GraphicsScene",1,0,"GraphicsScene");
    qmlRegisterType<QQuickGraphicsview>("na.qt.GraphicsView",1,0,"GraphicsView");
//    qmlRegisterType<QQuickQWidgetToQml>("na.qt.QWidgetToQml",1,0,"QwidgetToQml");
//    QQuickView * qmlquikview = new QQuickView();
//    qmlquikview->setSource(QUrl("qrc:/qmlitem.qml"));
//    qmlquikview->show();

//    lab label;
//    label.show();
    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return a.exec();
}
