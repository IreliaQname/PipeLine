#pragma once

#include "user_data.h"
#include "Vector4.h"
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
	// ���ù���
	void setPolygonLight(std::vector<Point>& polygon);
protected:
	// �������
	Vector4 m_cameraDir;
	// ���߷���
	Vector4 m_lightDir;
	// ƽ�淨�߷���
	Vector4 m_normalDir;
};

