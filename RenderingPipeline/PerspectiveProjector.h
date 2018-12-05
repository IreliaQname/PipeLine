#pragma once

#include "Projector.h"
#include <vector>

/*
͸��ͶӰ�ĺ���
*/

class PerspectiveProjector :
	public Projector
{
public:
	PerspectiveProjector();
	virtual ~PerspectiveProjector();
	// ��д���þ���ĺ���
	void setProjectMat(double n = 10, double f = 1000,
		double t = 20, double b = -20,
		double l = 20, double r = -20)override;
};

