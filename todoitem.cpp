#include "todoitem.h"

ToDoItem::ToDoItem(QObject *parent) : QObject(parent)
{

}

bool ToDoItem::done() const
{
    return m_done;
}

void ToDoItem::setDone(bool done)
{
    m_done = done;
}

QString ToDoItem::description() const
{
    return m_description;
}

void ToDoItem::setDescription(const QString description)
{
    m_description = description;
}

