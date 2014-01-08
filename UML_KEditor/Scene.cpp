#include "Scene.h"
#include <QtGui/QGraphicsView>
#include <QtGui/QInputDialog>
#include <QtGui/QMessageBox>

Scene * Scene::uniqueInstanceScene = NULL;

Scene::Scene() 
	: mode( NULL )
	, mouseSelectRect(NULL)
	, startItem(NULL)
{
	
}

Scene::~Scene()
{
	QListIterator< Item * > itemIteraor( itemList );
	while( itemIteraor.hasNext() ) {
		delete itemIteraor.next();
	}
}


Scene* Scene::SceneGetInstance(){

	if(uniqueInstanceScene == NULL){
		
		uniqueInstanceScene = new Scene();
	}

	return uniqueInstanceScene;
}




void Scene::defaultMousePressEvent( QGraphicsSceneMouseEvent * event )
{
	this->QGraphicsScene::mousePressEvent( event );
}

void Scene::defaultMouseMoveEvent( QGraphicsSceneMouseEvent * event )
{
	this->QGraphicsScene::mouseMoveEvent( event );
}

void Scene::defaultMouseReleaseEvent( QGraphicsSceneMouseEvent * event )
{
	this->QGraphicsScene::mouseReleaseEvent( event );
}


void Scene::mousePressEvent( QGraphicsSceneMouseEvent * event )
{
	if( event->button() == Qt::LeftButton ) {
		mode->onMousePress( event );
	}
}

void Scene::mouseMoveEvent( QGraphicsSceneMouseEvent * event )
{
	mode->onMouseMove( event );
}

void Scene::mouseReleaseEvent( QGraphicsSceneMouseEvent * event )
{
	mode->onMouseRelease( event );
}

void Scene::changeItemName(){

	QList< QGraphicsItem * > selectItemList(this->selectedItems() );
	QListIterator< QGraphicsItem * > ItemIter( selectItemList );

	while( ItemIter.hasNext() ) {
		Item * item = dynamic_cast< Item * >(ItemIter.next() );

		bool ok;
		QString name = QInputDialog::getText( this->views().first(), 
											  QObject::tr( "" ), 
											  QObject::tr( "Enter a name" ), 
											  QLineEdit::Normal, 
											  item ->getName(), &ok );
	
		if(ok && !name.isEmpty()){
			item ->setName( name );
		}
	
	}
}


void Scene::groupItem(){

	
	QList<QGraphicsItem*> itemList(selectedItems());

	if(itemList.size() > 0){

		Group *group = new Group();
		for (int i = 0; i < itemList.size(); i++)

			group -> addToGroup(itemList[i]);
		    addItem(group);
            group -> setSelected(true);
     }
}

void Scene::unGroupItem(){

	QList<QGraphicsItem*> itemList(selectedItems());
	QList<QGraphicsItem*> selectedInGroup;

	if(itemList.size() > 0){

		for(int i=0; i<itemList.size(); i++){
			
			Group *group = dynamic_cast< Group * >( itemList.at(i) );

			if(group){

				group -> setSelected(false);
                selectedInGroup = group -> childItems();
                destroyItemGroup(group);

                for (int i = 0; i < selectedInGroup.size(); i++){

					selectedInGroup[i] -> setSelected(false);	
				}
			}	
		}
	}
}


