#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext> // expose object to qml
#include "test.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);

//    qmlRegisterType<ToDoModel>("ToDo", 1, 0, "ToDoModel");
//    qmlRegisterUncreatableType<ToDoList>("ToDo", 1, 0, "ToDoList",QStringLiteral("ToDoList should not be created in QML"));


    QQmlApplicationEngine engine;

    qmlRegisterType<ToDoItem>("ToDo", 1, 0, "ToDoItem");
    qmlRegisterUncreatableType<Test>("ToDo", 1, 0, "Test", "d ");

    ToDoItem * item = new ToDoItem();
    item->setDone(true);
    item->setDescription(QStringLiteral("temporário"));
    QList<ToDoItem *> items;

    items.append(item);
    items.append(item);

    Test* test = new Test(items);

 //   qDebug() << test->items().at(0).description;

    engine.rootContext()->setContextProperty(QStringLiteral("test"), test);

    engine.load(QUrl(QLatin1String("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
