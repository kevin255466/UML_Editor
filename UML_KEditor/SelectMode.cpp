#include "SelectMode.h"


SelectMode::SelectMode()
	: Mode()
	, mouseSelectStartPoint(QPointF())
	, mouseSelectRect(NULL){

}

SelectMode::~SelectMode(){

	if ( mouseSelectRect ) {
		delete mouseSelectRect;
	}
}


void SelectMode::onMousePress( QGraphicsSceneMouseEvent * event){

	releaseAllItem();

	QGraphicsItem * topItem = Scene::SceneGetInstance()->itemAt(event->scenePos());

	if(topItem){
		
		Scene::SceneGetInstance()->defaultMousePressEvent(event);
	}
	else{
		
		mouseSelectRect = new QGraphicsRectItem( QRectF( event->scenePos(), QSizeF() ) );
		mouseSelectStartPoint = event->scenePos();
		QPen pen( mouseSelectRect->pen() );
		pen.setColor( "gray" );
		pen.setStyle( Qt::DashLine );
		mouseSelectRect->setPen( pen );
		Scene::SceneGetInstance()->addItem( mouseSelectRect );	
	}
}

void SelectMode::onMouseMove(QGraphicsSceneMouseEvent *event){

	if ( mouseSelectRect ) {
		QRectF rect( mouseSelectStartPoint, event->scenePos() );
		mouseSelectRect->setRect( rect.normalized() );
	}
	Scene::SceneGetInstance()->defaultMouseMoveEvent(event);

}

void SelectMode::onMouseRelease(QGraphicsSceneMouseEvent *event){

	if ( mouseSelectRect ) {

		Scene::SceneGetInstance()->setSelectionArea( mouseSelectRect->mapToScene( 
											   mouseSelectRect->shape() ), 
											   Qt::ContainsItemBoundingRect, 
											   QTransform() );

		delete mouseSelectRect;
		mouseSelectRect = NULL;

	}
	Scene::SceneGetInstance()->defaultMouseReleaseEvent( event );
}

void SelectMode::releaseAllItem(){

	QList< Item * > selectItemList( Scene::SceneGetInstance()->itemList );
	QListIterator< Item * > itemIter( selectItemList );


	while(itemIter.hasNext()){
	
		itemIter.next()->setSelected(false);
	}
}
