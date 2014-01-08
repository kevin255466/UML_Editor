#ifndef MODE_H
#define MODE_H

class Scene;
class QGraphicsSceneMouseEvent;

class Mode {

public:
	Mode();
	virtual void onMousePress( QGraphicsSceneMouseEvent * event );
	virtual void onMouseMove( QGraphicsSceneMouseEvent * event );
	virtual void onMouseRelease( QGraphicsSceneMouseEvent * event );

};

#endif