#include "Group.h"



Group::Group(){

	setFlags(QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsSelectable);
}

void Group::paint( QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget )
{
	if( this->isSelected() ) {

		QPen pen( painter->pen() );
		pen.setColor( "gray" );
		pen.setStyle( Qt::DashLine );
		painter->setPen( pen );
		painter->drawRect( this->boundingRect() );
	}
}


