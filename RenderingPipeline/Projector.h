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

	// ����ͶӰ����
	virtual void setProjectMat(double n = 10, double f = 1000,
		double t = 20, double b = -20,
		double l = 20, double r = -20) = 0;

	// ͶӰ������������ӳ��ΪNDC����ת�����û�����Ļ����
	virtual void project(Object& object, int width = WINDOW_WIDTH, int hegiht = WINDOW_HEIGHT) final;

protected:
	// ��ƽ�棬Զƽ�棬�������ײ�����࣬�Ҳ�
	double N, F, T, B, L, R;
	// ͶӰ�任����
	Matrix4x4 m_proMat;
};

