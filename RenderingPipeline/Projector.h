#pragma once

#include "user_data.h"
#include <vector>
#include "Matrix4x4.h"

/*
ͶӰ�������
*/

class Projector
{
public:
	Projector();
	virtual ~Projector();
	// �������ͶӰ
	virtual void project(std::vector<Point>& points) final;

	// ����ͶӰ����
	virtual void setProjectMat(double n = 10, double f = 1000,
		double t = 20, double b = -20,
		double l = 20, double r = -20) = 0;

protected:
	// ��ƽ�棬Զƽ�棬�������ײ�����࣬�Ҳ�
	double N, F, T, B, L, R;
	// ͶӰ�任����
	Matrix4x4 m_proMat;
};

