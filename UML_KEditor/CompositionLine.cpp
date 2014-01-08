#include "CompositionLine.h"
#include "Item.h"

const qreal DIAMOND_SIZE = 15;


CompositionLine::CompositionLine(){


}

CompositionLine::CompositionLine(ItemPort * startPort, ItemPort * endPort)
	: Line(startPort, endPort)
{


}

QRectF CompositionLine::boundingRect()const{

	qreal extra = this->pen().width() + DIAMOND_SIZE/2.0;
	return this->Line::boundingRect().adjusted( -extra, -extra, extra, extra);
}

void CompositionLine::paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * parent){

	QPolygonF head;
	head.append(QPointF( 0.0, 0.0));
	head.append(QPointF( 1.0, -1.0));
	head.append(QPointF( 2.0, 0.0));
	head.append(QPointF( 1.0, 1.0));

	QPainterPath path;
	path.addPolygon(head);

	QTransform transform;
	transform.translate( this->line().p2().x(), this->line().p2().y());
	transform.scale(DIAMOND_SIZE, DIAMOND_SIZE );
	transform.rotate( 180.0 - this->line().angle());

	QTransform copy( painter->transform());
	painter->setTransform( transform, true);
	painter->fillPath( path, QColor("yellow"));
	painter->setPen(this->pen());
	painter->drawPolygon(head);
	painter->setTransform(copy);

	qreal triangleHeight = ::sqrt( 3.0 ) / 2.0;
	QPointF realP2( transform.map( QLineF( QPointF( 0.0, 0.0 ), QPointF( triangleHeight, 0.0 ) ) ).p2() );
	painter->drawLine( this->line().p1(), realP2);

}