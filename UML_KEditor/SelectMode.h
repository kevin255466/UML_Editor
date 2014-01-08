#ifndef SELECTMODE_H
#define SELECTMODE_H

#include "Mode.h"
#include "Item.h"
#include "UseCase.h"
#include "Class.h"
#include "Scene.h"

#include <QtGui/QGraphicsSceneMouseEvent>

class SelectMode: public Mode{

public:
	SelectMode();
	~SelectMode();
	virtual void onMousePress( QGraphicsSceneMouseEvent * event);
	virtual void onMouseMove( QGraphicsSceneMouseEvent * event);
	virtual void onMouseRelease( QGraphicsSceneMouseEvent * event);
	void releaseAllItem();

private:
	QPointF mouseSelectStartPoint;
	QGraphicsRectItem *mouseSelectRect;

};

#endif