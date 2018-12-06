#include "Projector.h"



Projector::Projector()
{
}


Projector::~Projector()
{
}

void Projector::project(Object & object, int width, int height)
{
	for (auto& plane : object.planes) {
		for (auto& point : plane) {
			Vector4 vec(point);
			auto&& res = m_proMat * vec;
			// ��һ��
			point.x = res.X() / res.W();
			point.y = res.Y() / res.W();
			point.z = res.Z() / res.W();   // ��ȷ���
			// ӳ�䵽��Ļ
			point.x *= width;
			point.y *= height;
		}
	}
}