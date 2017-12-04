#include "test.h"
#include "todoitem.h"

Test::Test(QList<ToDoItem*> items, QObject *parent) : QObject(parent)
  , m_items(items)
{
    connect(this, SIGNAL(itemsChanged(QList<ToDoItem*>)), this, SLOT(alert(QList<ToDoItem*>)));
}

QList<ToDoItem *> Test::items()
{
    return m_items;
}

QQmlListProperty<ToDoItem> Test::itemsList()
{
    return QQmlListProperty<ToDoItem>(this, m_items);
}

void Test::setItem(QString description)
{
//    ToDoItem* item = new ToDoItem();

//    item->done = false;
//    item->description = description;
//    m_items.append(&item);

    emit itemsChanged(m_items);
}

void Test::removeFirst()
{
    m_items.removeFirst();
    emit itemsChanged(m_items);
}

void Test::removeLast()
{
    m_items.removeLast();
    emit itemsChanged(m_items);
}

void Test::removeAll()
{
    m_items.clear();
    emit itemsChanged(m_items);
}

void Test::alert(QList<ToDoItem *> items)
{
    qDebug() << " #########";
//    qDebug() << " #########" << items;
//    QString  * conas = new QString();
//    QString coninhas;

//    if(m_pilinhas != nullptr)
//        delete m_pilinhas;
//    if(m_pilinhas == nullptr)
//        m_pilinhas = new QString("Minha Pilinha");
//    else {
//        m_pilinhas = new QString("Minha Pilinha");
//    }
//    conas->append("tetinhas");
//    coninhas.append("sdfsdf");

//    delete conas;

}

void Test::setItems(const QList<ToDoItem*> items)
{
    m_items = items;
    emit itemsChanged(m_items);
}

