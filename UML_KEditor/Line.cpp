#include "Line.h"
#include "ItemPort.h"
#include "Item.h"


const double PI = acos( -1.0 );
const qreal ARROW_HEAD_SIZE = 20;

Line::Line(){

	this->setFlags( QGraphicsItem::ItemIsSelectable | 
					QGraphicsItem::ItemIsMovable | 
					QGraphicsItem::ItemSendsGeometryChanges );
}

Line::Line(ItemPort * startPort, ItemPort * endPort)
	: startPort(startPort)
	, endPort(endPort)
{

	QPen pen( this->pen() );
	pen.setColor( QColor( 139, 34, 82 )  );
	this->setPen( pen );
	this->setZValue( -1 );
}

void Line::drawLine(){

	QPointF startPoint = startPort->getParentItem()->scenePos() + startPort->getOffset();
	QPointF endPoint = endPort->getParentItem()->scenePos() + endPort->getOffset();

	QLineF line( startPoint, endPoint );
	this->setLine( line );
}

