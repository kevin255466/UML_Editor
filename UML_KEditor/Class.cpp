#include "Class.h"

Class::Class()
	: name( "" )
	, rect( QRectF( -50, -50, 100, 100 ) )
{

	const QRectF rect( this->boundingRect() );

	const qreal heightOffset = rect.height() / 2;
	const qreal widthOffset = rect.width() / 2;

	topPort.setOffset( QPointF( 0, 0-heightOffset ) );
	bottomPort.setOffset( QPointF( 0, heightOffset ) );
	leftPort.setOffset( QPointF( 0-widthOffset, 0 ) );
	rightPort.setOffset( QPointF( widthOffset, 0 ) );
}

QString Class::getName(){

	return name;
}

void Class::setName( QString name ){

	this->name = name;
}

QRectF Class::boundingRect() const{

    return rect;
}

void Class::paint( QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget ){

	const QRectF rect( this->boundingRect() );

	painter->setBrush( QColor( 202, 255, 112, 127 ) );
	painter->setPen( this->pen() );
	painter->setPen( QPen(Qt::darkGreen, 3, Qt::SolidLine) );
	painter->drawRect( this->boundingRect() );
	painter->drawLine( QPointF( rect.left(), rect.top() + rect.height() / 3 ), QPointF( rect.right(), rect.top() + rect.height() / 3 ) );
	painter->drawLine( QPointF( rect.left(), rect.top() + rect.height() / 3 * 2 ), QPointF( rect.right(), rect.top() + rect.height() / 3 * 2 ) );
	QFont font( painter->font() );
	font.setPointSize( 10 );
	painter->setFont( font );

	const QRectF fontRect( rect.left(), rect.top(), rect.width(), rect.height() / 3 );
	painter->drawText( fontRect, Qt::AlignCenter, this->getName() );
	this->Item::paint( painter, option, widget );
}
