#ifndef CREATEMODE_H
#define CREATEMODE_H

#include "Mode.h"
#include "Item.h"
#include "Usecase.h"
#include "Class.h"
#include "Scene.h"
#include <QtGui/QGraphicsSceneMouseEvent>

class CreateMode : public Mode {

public:

	CreateMode();
	~CreateMode();
	CreateMode(Item::Type itemType );
	virtual void onMousePress( QGraphicsSceneMouseEvent * event );

private:

	Item::Type itemType;

};

#endif