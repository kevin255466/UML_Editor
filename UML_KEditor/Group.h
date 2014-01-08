#ifndef Group_H
#define Group_H

#include <QGraphicsItemGroup>
#include <QPen>
#include <QPainter>

class Group : public QGraphicsItemGroup{

public:
	Group();
	virtual void paint( QPainter * painter,
						const QStyleOptionGraphicsItem * option, QWidget * widget = 0 );

};


#endif
