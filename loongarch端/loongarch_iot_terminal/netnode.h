#ifndef NETNODE_H
#define NETNODE_H


#include <QObject>
#include <QGraphicsPixmapItem>
#include "netnodelink.h"

class SuspensionDialog;
class NetNode : public QGraphicsPixmapItem
{
public:
    explicit NetNode(bool ipKnown, QString ip, QGraphicsScene *scene);
    explicit NetNode(QGraphicsScene *scene);
    ~NetNode();

    void addLink(NodeLink *link);
    QList<NodeLink*> getLinks();

    void adjustLinks();

    void drawPixmap(int key, int hops, int items, int maxlevel, int nodePerLevel);

protected:
    QVariant itemChange(GraphicsItemChange change, const QVariant &value);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

private:
    QGraphicsScene *pScene;
    bool inNet;
    int level;

    QList<NodeLink*> m_linkList;
};

#endif // NETNODE_H
