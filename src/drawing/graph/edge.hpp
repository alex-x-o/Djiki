#ifndef EDGE_HPP
#define EDGE_HPP

#include "node.hpp"

#include <QLineF>

class Edge : public QObject, public QGraphicsItem {
    Q_OBJECT
    Q_INTERFACES(QGraphicsItem)

public:
    Edge(Node* s, Node* e, int w, bool curve, QWidget* p);

    QRectF boundingRect() const override;
    QPainterPath shape() const override;

    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget = nullptr) override;

    void mousePressEvent(QGraphicsSceneMouseEvent* event) override;
    void mouseDoubleClickEvent(QGraphicsSceneMouseEvent* event) override;

    Node* getStart() const;
    Node* getEnd() const;
    int getEdgeWeight() const;

    void animateEdge();
    void advance(int phase) override;

public Q_SLOTS:
    /* If user moves node edge needs to be redrawn, so this slot receives signal */
    void nodeMoved();

Q_SIGNALS:
    void edgeDeleted(Edge* e);

private:
    std::pair<QPointF, QPointF> getCurrentNodeCoords() const;
    void drawEdgeWeight(QPainter* painter) const;
    void drawArrow(QPainter* painter) const;

    Node* start;
    Node* end;

    int edgeWeight;
    QPointF getIntersecWithEndNode(QLineF line) const;
    bool curve;

    bool animate;
    double currentStep;

    QWidget* parent;
};

#endif // EDGE_HPP
