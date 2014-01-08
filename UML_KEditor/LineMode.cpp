#include "LineMode.h"


LineMode::LineMode()
	:Mode()
{
	lineType = Line::AssociationLine;
}

LineMode::LineMode(Line::Type lineType )
	: Mode() , mouseMoveLine(nullptr)

{
	this->lineType = lineType;
}

LineMode::~LineMode(){

	delete mouseMoveLine;
}

void LineMode::onMousePress(QGraphicsSceneMouseEvent * event){

	QGraphicsItem * topItem = Scene::SceneGetInstance()->itemAt(event->scenePos());

	startItem = dynamic_cast<Item* > (topItem);

	if( startItem){
	
		startPort = startItem->decideWhichPort(event->scenePos());
		mouseMoveLine = new QGraphicsLineItem(QLineF(event->scenePos(), event->scenePos()));
		QPen pen( mouseMoveLine->pen());
		pen.setColor(QColor( 47, 79, 79 ));
		pen.setStyle(Qt::SolidLine);
		mouseMoveLine->setPen(pen);
		Scene::SceneGetInstance()->addItem(mouseMoveLine);
	}	
}

void LineMode::onMouseMove(QGraphicsSceneMouseEvent * event){

	if(mouseMoveLine){
	
		mouseMoveLine->setLine( QLineF(mouseMoveLine->line().p1(), event->scenePos()));
	
	}
}

void LineMode::onMouseRelease(QGraphicsSceneMouseEvent * event){

	if(mouseMoveLine != nullptr){
		
		mouseMoveLine->setLine( QLineF(mouseMoveLine->line().p1(), event->scenePos()));

		delete mouseMoveLine;
		mouseMoveLine = nullptr;

		QGraphicsItem * topItem = Scene::SceneGetInstance()->itemAt(event->scenePos());
		Item * endItem = dynamic_cast <Item * >(topItem);

		if(endItem){
		
			ItemPort *endPort = endItem->decideWhichPort(event->scenePos());

			Line * line;

			switch(lineType){
			
				case Line::AssociationLine:

					line = new AssociationLine(startPort , endPort);
					break;
			
				case Line::GenerationLine:

					line = new GenerationLine(startPort, endPort);
					break;

				case Line::CompositionLine:

					line = new CompositionLine(startPort, endPort);
					break;
			}
			
			if( startPort->getParentItem() != endPort->getParentItem()){

				startPort->addLine(line);
				endPort->addLine(line);
				Scene::SceneGetInstance()->addItem(line);
				line->drawLine();	
			}
		}
	}
}