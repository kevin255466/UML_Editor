#ifndef AssociationLine_H
#define AssociationLine_H

#include <QtGui/QPen>
#include <QtGui/QPainter>
#include "Line.h"


class AssociationLine :public Line{

public:

	AssociationLine();
	AssociationLine(ItemPort * startPort, ItemPort * endPort);

};

#endif 