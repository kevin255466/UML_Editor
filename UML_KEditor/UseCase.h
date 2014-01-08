#ifndef USECASE_H
#define USECASE_H

#include <QtGui/QMenu>
#include <QtGui/QGraphicsScene>
#include <QtGui/QPainter>
#include "Item.h"

class UseCase : public Item {
public:
	UseCase();
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