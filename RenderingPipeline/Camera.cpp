#include "Camera.h"



Camera::Camera()
{
	m_light = new Light;
}


Camera::~Camera()
{
	if (m_light != nullptr) {
		delete m_light;
	}
}

void Camera::setCamera(const Vector4 & pos, const Vector4 & target, const Vector4 & up)
{
	m_cameraPos = pos;
	m_cameraTarget = target;
	m_Up = up;
	auto&& cameraDir = m_cameraPos - m_cameraTarget;
	cameraDir.normalize();
	m_cameraRight = m_Up.cross(cameraDir);
	m_cameraRight.normalize();
	m_cameraUp = cameraDir.cross(m_cameraRight);
	m_cameraUp.normalize();

	m_light->setCameraDir(cameraDir);

	Matrix4x4 left, right;

	left.setIdentity();
	left.setVal(0, 0, m_cameraRight.X());
	left.setVal(0, 1, m_cameraRight.Y());
	left.setVal(0, 2, m_cameraRight.Z());
	left.setVal(1, 0, m_cameraUp.X());
	left.setVal(1, 1, m_cameraUp.Y());
	left.setVal(1, 2, m_cameraUp.Z());
	left.setVal(2, 0, cameraDir.X());
	left.setVal(2, 1, cameraDir.Y());
	left.setVal(2, 2, cameraDir.Z());

	right.setIdentity();
	right.setVal(0, 3, -m_cameraPos.X());
	right.setVal(1, 3, -m_cameraPos.Y());
	right.setVal(2, 3, -m_cameraPos.Z());

	m_lookAt = left * right;
}

void Camera::transform(Object & objectIn, Object & objectOut)
{
	if (objectIn.planes.empty())
		return;
	double x = objectIn.centerPos.X();
	double y = objectIn.centerPos.Y();
	double z = objectIn.centerPos.Z();
	objectOut.planes.clear();
	for (auto& plane : objectIn.planes) {
		Plane planeOut;
		for (auto& point : plane) {
			Vector4 vec(point.x + x, point.y + y, point.z + z);  // �ֲ�������Ҫ�ۼ���ȫ�ֵģ����ɵ�ǰ��ȫ������
		//	Vector4 vec(point.x, point.y, point.z);
			auto&& resVec = m_lookAt * vec;
			planeOut.emplace_back(Point(resVec.X(), resVec.Y(), resVec.Z(),
				point.r, point.g, point.b,
				point.u, point.v));
		}
		if (m_mode != 0)
			m_light->setPolygonLight(planeOut);    // ���������ù���
		objectOut.planes.push_back(planeOut);  // �����Ժ�Ҫ���Ǹĳ��ƶ�����
	}
}

void Camera::setLightDir(const Vector4 & lightDir)
{
	m_lightDir = lightDir; 
	m_light->setLightDir(m_lightDir);
}
