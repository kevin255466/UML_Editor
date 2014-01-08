#ifndef SCENE_H
#define SCENE_H

#include <QtGui/QGraphicsSceneMouseEvent>
#include <QtGui/QGraphicsScene>
#include <QtCore/QList>

#include "Mode.h"
#include "CreateMode.h"
#include "SelectMode.h"
#include "LineMode.h"
#include "Item.h"
#include "UseCase.h"
#include "Class.h"
#include "Line.h"
#include "AssociationLine.h"
#include "ItemPort.h"
#include "Group.h"


class Scene : public QGraphicsScene {

public:
	static Scene* SceneGetInstance();
	~Scene();
	void defaultMousePressEvent( QGraphicsSceneMouseEvent * event );
	void defaultMouseMoveEvent( QGraphicsSceneMouseEvent * event );
	void defaultMouseReleaseEvent( QGraphicsSceneMouseEvent * event );
	void changeItemName();
	void groupItem();
	void unGroupItem();

	QList< Item * > itemList;
	Mode * mode;

protected:
	virtual void mousePressEvent( QGraphicsSceneMouseEvent * event );
	virtual void mouseMoveEvent( QGraphicsSceneMouseEvent * event );
	virtual void mouseReleaseEvent( QGraphicsSceneMouseEvent * event );


private:
	Scene();
	QPointF mouseSelectStartPoint;
	QGraphicsRectItem *mouseSelectRect;
	Item * startItem;
	static Scene * uniqueInstanceScene;

	
};

#endif