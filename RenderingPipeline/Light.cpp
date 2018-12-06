#include "Light.h"
#include <cassert>
#include <QDebug>


Light::Light()
{
}


Light::~Light()
{
}

void Light::setCameraDir(const Vector4 & cameraDir)
{
	m_cameraDir = cameraDir;
}

void Light::setLightDir(const Vector4 & lightDir)
{
	m_lightDir = lightDir;
}

void Light::setPolygonLight(Plane& plane)
{
	// ����ÿ����Ĺ���
	if (plane.size() <= 2)   // һ��ƽ������3����
		return;
	// �ٶ����еĶ��㲻����
	const auto& p0 = plane[0];
	const auto& p1 = plane[1];
	const auto& p2 = plane[2];
	Vector4 vec1(p0.x - p1.x, p0.y - p1.y, p0.z - p1.z);
	Vector4 vec2(p2.x - p1.x, p2.y - p1.y, p2.z - p1.z);
	auto&& normalVec = vec1.cross(vec2);  // ƽ��ķ�����

	// �����������뷨�����н�С��90�ȣ����������������
	if (m_cameraDir.dot(normalVec) < 0) {
		normalVec.reverse();
	}

	if (normalVec.dot(m_lightDir) > 0) {   // ���߱��ڵ�
		return;
	}

	double k = -normalVec.dot(m_lightDir) / (normalVec.length()*m_lightDir.length());
	k = std::acos(k);  // ����0-90
	k /= (90 * PI / 180);
	k += 1;
	for (auto&p : plane) {
		p.r *= k;
		p.g *= k;
		p.b *= k;
		p.r = std::max(p.r, 255);
		p.g = std::max(p.g, 255);
		p.b = std::max(p.b, 255);
	}
}
