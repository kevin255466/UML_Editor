#include "GenerationLine.h"
#include "Item.h"

const double PI = acos( -1.0 );
const qreal ARROW_HEAD_SIZE = 20;

GenerationLine::GenerationLine(){

}

GenerationLine::GenerationLine(ItemPort * startPort, ItemPort * endPort)
	: Line( startPort, endPort )
{


}

QRectF GenerationLine::boundingRect() const{

	qreal extra = ( this->pen().widthF() + ARROW_HEAD_SIZE ) / 2.0;
	return this->Line::boundingRect().adjusted( -extra, -extra, extra, extra );
}

void GenerationLine::paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * parent  ){
	
	QPolygonF head;
	head.append( QPointF( 0.0, 0.0 ) );
	head.append( QPointF( cos( PI / 6 ), -sin( PI / 6 ) ) );
	head.append( QPointF( cos( -PI / 6 ), -sin( -PI / 6 ) ) );

	QPainterPath path;
	path.addPolygon( head );

	QTransform transform;
	transform.translate( this->line().p2().x(), this->line().p2().y() );
	transform.scale( ARROW_HEAD_SIZE, ARROW_HEAD_SIZE );
	transform.rotate( 180.0 - this->line().angle() );

	QTransform copy( painter->transform() );
	painter->setTransform( transform, true );
	painter->fillPath( path, QColor( "yellow" ) );
	painter->setPen( this->pen() );
	painter->drawPolygon( head );
	painter->setTransform( copy );

	qreal triangleHeight = ::sqrt( 3.0 ) / 2.0;
	QPointF realP2( transform.map( QLineF( QPointF( 0.0, 0.0 ), QPointF( triangleHeight, 0.0 ) ) ).p2() );
	painter->drawLine( this->line().p1(), realP2 );
}
