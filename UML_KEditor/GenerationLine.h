#ifndef GenerationLine_H
#define GenerationLine_H

#include <QtGui/QPen>
#include <QtGui/QPainter>
#include "Line.h"


class GenerationLine :public Line{

public:

	GenerationLine();
	GenerationLine(ItemPort * startPort, ItemPort * endPort);
	void paint( QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * parent = 0 );
	QRectF boundingRect() const;
};

#endif 