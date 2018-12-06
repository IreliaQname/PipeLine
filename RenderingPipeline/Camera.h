#pragma once

#include "user_data.h"
#include "Matrix4x4.h"
#include "Vector4.h"
#include <vector>
#include "Light.h"

class Camera
{
public:
	Camera();
	~Camera();

	// ������������λ�á����㡢���ᡢ���շ���
	void setCamera(const Vector4& pos, const Vector4& target, const Vector4& up);

	// �°��ת���ӿڣ��������������е������壬������������е�������
	void transform(Object& objectIn, Object& objectOut);

	// ���ù��߷���
	void setLightDir(const Vector4& lightDir);

	inline void setLightMode(int mode) { m_mode = mode; }

protected:
	// �任����
	Matrix4x4 m_lookAt;  
	// ���λ��
	Vector4 m_cameraPos;
	// ����Ľ���
	Vector4 m_cameraTarget;
	// ���������
	Vector4 m_cameraRight;
	// ���������
	Vector4 m_cameraUp;
	// �����������
	Vector4 m_Up;
	// ��ķ���
	Vector4 m_lightDir;
	// ���ù���
	Light* m_light{ nullptr };
	// ���ù���ģʽ�����߿��ʱ����������
	int m_mode{ 0 };
};

