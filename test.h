#ifndef TEST_H
#define TEST_H

#include <QObject>
#include <QDebug>
#include <QQmlListProperty>
#include "todoitem.h"

class Test : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QQmlListProperty<ToDoItem> items READ itemsList NOTIFY itemsChanged)

public:
    explicit Test(QList<ToDoItem*> nomes, QObject *parent = nullptr);

    QQmlListProperty<ToDoItem> itemsList();
    QList<ToDoItem*> items();
    void setItems(const QList<ToDoItem*> items);

signals:
    void itemsChanged(QList<ToDoItem*> m_items);

public slots:
    void setItem(QString name);
    void removeFirst();
    void removeLast();
    void removeAll();

private slots:
    void alert(QList<ToDoItem*> items);

private:
    QList<ToDoItem*> m_items;
};

#endif // TEST_H
