#include "CreateMode.h"

CreateMode::CreateMode()
	: itemType( Item::Class )
{

}

CreateMode::CreateMode( Item::Type itemType )
	: Mode( )
	, itemType( itemType )
{

}

CreateMode::~CreateMode(){

}

void CreateMode::onMousePress( QGraphicsSceneMouseEvent * event ){

	Item * item;
	switch (itemType )
	{
		case Item::UseCase:
			item = new UseCase();
			break;
		case Item::Class:
			item = new Class();
			break;

	}
	
	item->setPos( event->scenePos() );
	Scene::SceneGetInstance()->addItem( item );
	Scene::SceneGetInstance()->itemList.push_back( item );
}
