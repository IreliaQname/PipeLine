#pragma once

#include "user_data.h"
#include <vector>

/*
����βü���������Ķ���βü������ʵ�ƽ����
*/

class PolygonCliper
{
public:
	PolygonCliper();
	~PolygonCliper();
	// �ü��㷨������ĵ㡢����ĵ�
	void clip(std::vector<Point>& pointsIn, std::vector<Point>& pointsOut);
	// ���ñ߽磬�ϱ߽硢�±߽硢��߽硢�ұ߽�
	void setBoundary(double t, double b, double l, double r);
protected:
	// ��������
	double T, D, L, R;
};

