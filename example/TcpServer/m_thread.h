#ifndef M_THREAD_H
#define M_THREAD_H

#include <QMainWindow>
#include <QObject>
#include <QThread>


class M_Thread : public QObject,public QThread
{
    Q_OBJECT
public:
    explicit M_Thread(QObject *parent = nullptr);

signals:

public slots:
};

#endif // M_THREAD_H
