#pragma once

#include "user_data.h"
#include "Vector4.h"
#include "user_data.h"
#include <vector>

/*
��������Ĺ���ǿ�ȣ�����alpha����
*/
class Light
{
public:
	Light();
	~Light();
	// �����������
	void setCameraDir(const Vector4& cameraDir);
	// ���ù��߷���
	void setLightDir(const Vector4& lightDir);
	// �°�����ù��ߵĺ���������ͼ��ÿ����Ĺ���
	void setPolygonLight(Plane& plane);
protected:
	// ��������������������� camTarget-camPos
	Vector4 m_cameraDir;
	// ���߷���
	Vector4 m_lightDir;
	// ƽ�淨�߷���
	Vector4 m_normalDir;
};

