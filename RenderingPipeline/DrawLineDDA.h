#pragma once
#include "DrawLineAlgorithm.h"

/*
DDA�����㷨
*/

class DrawLineDDA :
	public DrawLineAlgorithm
{
public:
	DrawLineDDA();
	virtual ~DrawLineDDA();
	virtual void drawLine(const Point& start,
		const Point& stop,
		std::vector<Point>& pointsOut)override;
};

