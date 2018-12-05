#pragma once

#include "user_data.h"
#include "Matrix4x4.h"
#include "Vector4.h"
#include <vector>

class Camera
{
public:
	Camera();
	~Camera();
	// ����Ķ������ݴ�����ת����������������ת�������������ϵ������������
	void transform(std::vector<Point>& pointsIn, std::vector<Point>& pointsOut);
	// ������������λ�á����㡢����
	void setCamera(const Vector4& pos, const Vector4& target, const Vector4& up);
protected:
	// �任����
	Matrix4x4 m_transMat;  
	// ���λ��
	Vector4 m_cameraPos;
	// ����Ľ���
	Vector4 m_cameraTarget;
	// ���������
	Vector4 m_cameraRight;
	// ���������
	Vector4 m_cameraUp;
};

