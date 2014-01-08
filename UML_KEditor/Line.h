#ifndef Line_H
#define Line_H

#include <QtGui/QPainter>
#include <QtGui/QGraphicsScene>
#include <QtGui/QGraphicsLineItem>
#include <QtGui/QPen>
#include <QtGui/QPainter>


class ItemPort;
class Item;

class Line : public QGraphicsLineItem {
public:
	enum Type {
		AssociationLine,
		CompositionLine,
		GenerationLine
	};

	Line();
	Line( ItemPort * startPort, ItemPort * endPort );

	virtual void drawLine();
	
protected:
	ItemPort * startPort;
	ItemPort * endPort;
};

#endif