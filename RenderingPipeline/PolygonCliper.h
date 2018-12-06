#pragma once

#include "user_data.h"
#include "Vector4.h"
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

	// �ü��㷨����ӳ�����Ļ�Ķ���θ��ݱ߽���вü�
	void clip(Object& object);

	// ���ñ߽磬�ϱ߽硢�±߽硢��߽硢�ұ߽�
	void setBoundary(double t, double b, double l, double r);

protected:
	// ��������
	double T, B, L, R;
};

