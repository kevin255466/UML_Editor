#include "ItemPort.h"



ItemPort::ItemPort()
	: offset(QPointF())
	, parentItem(NULL)
	, lineList()
{

}

QPointF ItemPort::getOffset(){

	return offset;
}

void ItemPort::setOffset( QPointF offset ){

	this->offset = offset;
}

Item * ItemPort::getParentItem(){

	return parentItem;
}

void ItemPort::setParentItem( Item * parentItem ){

	this->parentItem = parentItem;
}

void ItemPort::addLine(Line * line){

	lineList.append(line);

}

void ItemPort::updateLine(){

	QListIterator< Line * > iterator( lineList );
	while( iterator.hasNext() ) {
		iterator.next()->drawLine();
	}
}

