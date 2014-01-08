#ifndef LINEMODE_H
#define LINEMODE_H

#include "Mode.h"
#include "Line.h"
#include "Scene.h"
#include "Item.h"
#include "Line.h"
#include "AssociationLine.h"
#include "GenerationLine.h"
#include "CompositionLine.h"

#include <QtGui/QGraphicsLineItem>
#include <QtGui/QGraphicsSceneMouseEvent>

class LineMode : public Mode{

public:

	LineMode();
	LineMode(Line::Type lineType);
	~LineMode();

	virtual void onMousePress( QGraphicsSceneMouseEvent * event );
	virtual void onMouseMove( QGraphicsSceneMouseEvent * event );
	virtual void onMouseRelease( QGraphicsSceneMouseEvent * event );

private:
	 Line::Type lineType; 
	 QGraphicsLineItem * mouseMoveLine;
	 ItemPort * startPort;
	 Item * startItem;
};


#endif