#ifndef TODOITEM_H
#define TODOITEM_H

#include <QObject>
#include <QDebug>

class ToDoItem : public QObject
{
    Q_OBJECT
    Q_PROPERTY(bool done READ done WRITE setDone NOTIFY doneChanged)
    Q_PROPERTY(QString description READ description WRITE setDescription NOTIFY descriptionChanged)

public:
    explicit ToDoItem(QObject *parent = nullptr);

    bool done() const;
    void setDone(bool done);

    QString description() const;
    void setDescription(const QString description);

signals:
    void doneChanged(bool done);
    void descriptionChanged(QString description);

public slots:
    void notifyDoneChanged(bool done);

private:
    bool m_done;
    QString m_description;
};


#endif // TODOITEM_H

