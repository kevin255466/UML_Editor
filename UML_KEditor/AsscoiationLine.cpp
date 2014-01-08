#include "AssociationLine.h"
#include "Item.h"


AssociationLine::AssociationLine(){

}

AssociationLine::AssociationLine(ItemPort * startPort, ItemPort * endPort)
	: Line( startPort, endPort )
{


}