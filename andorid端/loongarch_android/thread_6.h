#ifndef THREAD_6_H
#define THREAD_6_H

#include <QThread>

class thread_6 : public QThread
{
    Q_OBJECT
public:
    thread_6(QObject* par);
    ~thread_6();

    void run();

signals:

};

#endif // THREAD_6_H
