#ifndef NETNODELINK_H
#define NETNODELINK_H

#include <QGraphicsItem>

class NetNode;
class NodeLink : public QGraphicsItem
{
public:
    explicit NodeLink(NetNode *fromNode, NetNode *toNode);
    ~NodeLink();

    NetNode *getFromNode() const;
    NetNode *getToNode() const;

    void adjust();

protected:
    QRectF boundingRect() const Q_DECL_OVERRIDE;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) Q_DECL_OVERRIDE;

private:
    NetNode *m_fromNode;
    NetNode *m_toNode;

    QPointF  m_beginPoint;
    QPointF  m_endPoint;

};

#endif // NETNODELINK_H
