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
	// ���ù��߷���
	void setLightDir(const Vector4& lightDir);
	// ������ģ��
	void setPolygonLight(Object& object);
protected:
	// ��������������������� camTarget-camPos
	Vector4 m_cameraDir;
	// ���߷���
	Vector4 m_lightDir;
	// ƽ�淨�߷���
	Vector4 m_normalDir;
	// ������ǿ��
};

