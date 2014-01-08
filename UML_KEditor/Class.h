#ifndef CLASS_H
#define CLASS_H

#include <QtGui/QMenu>
#include <QtGui/QGraphicsScene>
#include <QtGui/QPainter>
#include "Item.h"

class Class : public Item {
public:
	Class();
	virtual QString getName();
	virtual void setName( QString name );
    virtual QRectF boundingRect() const;
    virtual void paint( QPainter * painter, 
						const QStyleOptionGraphicsItem * option, QWidget * widget = 0 );
private:
	QString name;
	const  QRectF rect;
};

#endif