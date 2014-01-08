#include "Item.h"

Item::Item()
	:PORTSIZE(6)
{

	this->setFlags( QGraphicsItem::ItemIsSelectable | 
					QGraphicsItem::ItemIsMovable | 
					QGraphicsItem::ItemSendsGeometryChanges );
					
	topPort.setParentItem(this);
	bottomPort.setParentItem(this);
	leftPort.setParentItem(this);
	rightPort.setParentItem(this);
}

void Item::paint( QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget ){

	if(this->isSelected()){
	
		const QRectF rect( this->boundingRect() );
		const QPointF center( rect.center() );

		QPainterPath path;
		path.addEllipse( center.x() - PORTSIZE / 2, rect.top(), PORTSIZE, PORTSIZE);
		path.addEllipse( center.x() - PORTSIZE / 2, rect.bottom() - PORTSIZE, PORTSIZE, PORTSIZE);
		path.addEllipse( rect.left(), center.y() - PORTSIZE/2, PORTSIZE, PORTSIZE);
		path.addEllipse( rect.right()  - PORTSIZE, center.y() - PORTSIZE/2, PORTSIZE, PORTSIZE);

		painter->fillPath( path, QColor( 47, 79, 79 ) );

	}

	topPort.updateLine();
	bottomPort.updateLine();
	leftPort.updateLine();
	rightPort.updateLine();
}


ItemPort * Item::decideWhichPort( const QPointF & scenePosition){

	QPointF center( this->boundingRect().center() );
	QPointF diff( this->mapFromScene( scenePosition ) - center );
	
	bool compareXY = fabs(diff.x()) > fabs(diff.y());

	if(compareXY){
	
		if(diff.x()>0){

			return &rightPort;
		
		}else{
			
			return &leftPort;
		}
	}
	else{
		
		if(diff.y() >0){
			
			return &topPort;
		}else{
			
			return &bottomPort;
		}
	}
}




