#ifndef ITEMPORT_H
#define ITEMPORT_H

#include <QtGui/QGraphicsItem>
#include <QtGui/QPainter>
#include <QList>

#include "Line.h"

class Item;

class ItemPort {
public:
	ItemPort();

	QPointF getOffset();
	void setOffset( QPointF offset );
	Item * getParentItem();
	void setParentItem( Item * parentItem );
	void addLine( Line * line );
	void updateLine();

private:
	QList< Line * > lineList;
	QPointF offset;
	Item * parentItem;

};

#endif
