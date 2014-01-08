#ifndef Item_H
#define Item_H

#include <QtGui/QAbstractGraphicsShapeItem>
#include <QtGui/QPainter>
#include <QtGui/QGraphicsScene>

#include "ItemPort.h"

class Item : public QAbstractGraphicsShapeItem {

public:
	
	enum Type {

		Class,
		UseCase
	};
	
	Item();
	virtual QString getName() = 0;
	virtual void setName( QString name ) = 0;
	virtual QRectF boundingRect() const = 0;
	virtual void paint( QPainter * painter, 
						const QStyleOptionGraphicsItem * option, QWidget * widget = 0 ) = 0;

	ItemPort * decideWhichPort( const QPointF & scenePosition);
	const qreal PORTSIZE;

protected:
	ItemPort topPort;
	ItemPort bottomPort;
	ItemPort leftPort;
	ItemPort rightPort;
};

#endif
