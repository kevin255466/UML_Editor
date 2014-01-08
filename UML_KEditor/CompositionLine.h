#ifndef CompositionLine_H
#define CompositionLine_H

#include <QtGui/QPen>
#include <QtGui/QPainter>
#include "Line.h"


class CompositionLine : public Line{

public:

	CompositionLine();
	CompositionLine(ItemPort * startPort, ItemPort * endPort);
	void paint( QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * parent = 0 );
	QRectF boundingRect() const;


};

#endif