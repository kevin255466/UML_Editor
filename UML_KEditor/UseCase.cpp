#include "UseCase.h"

UseCase::UseCase()
	: name( "" )
	, rect( QRectF( -50, -30, 100, 60 ) )
{
	const QRectF rect( this->boundingRect() );
	const qreal heightOffset = rect.height() / 2;
	const qreal widthOffset = rect.width() / 2;

	topPort.setOffset( QPointF( 0, 0-heightOffset ) );
	bottomPort.setOffset( QPointF( 0, heightOffset ) );
	leftPort.setOffset( QPointF( 0-widthOffset, 0 ) );
	rightPort.setOffset( QPointF( widthOffset, 0 ) );
}

QString UseCase::getName()
{
	return name;
}

void UseCase::setName( QString name )
{
	this->name = name;
}

QRectF UseCase::boundingRect() const
{
    return rect;
}


void UseCase::paint( QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget )
{

	QPainterPath path;
	path.addEllipse( this->boundingRect() );
	painter->setRenderHint(QPainter::Antialiasing, true);
	painter->setPen( QPen(Qt::darkGreen, 3, Qt::SolidLine) );
	painter->setBrush( QColor( 202, 255, 112, 127 ) );
	painter->drawEllipse( this->boundingRect());
	QFont font( painter->font() );
	font.setPointSize( 10 );
	painter->setFont( font );
	painter->drawText( this->boundingRect(), Qt::AlignCenter, this->getName() );
	this->Item::paint( painter, option, widget );	
}
