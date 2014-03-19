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
		painter->setPen( dsfsdffffffffffff );
		painter->drawRect( this->boundingRect(dsfsdfsdf) );
sdfsdffffffffffffffffffffffffffffffff
		qweqweq
	}
}


