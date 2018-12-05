#pragma once

#include "user_data.h"
#include "Matrix4x4.h"
#include "Vector4.h"
#include <vector>

/*
�ֲ�����ת�����������꣬��Ҫ֪���ֲ�������������������꣬������Ǿֲ��������
ƽ�Ʊ任�Ǿֲ����ĵ�λ�ƣ���ת��Χ�ƾֲ����ĵ���ת
*/
class Transformer
{
public:
	Transformer();
	~Transformer();
	// ƽ�Ʊ任�����ı�ԭ���ľֲ����ݣ������ƽ�Ʊ仯�������ֲ����ĵ�ƽ��
	void transformOffset(std::vector<Point>& pointsIn, std::vector<Point>& pointsOut, const Vector4& offset);
	// X����ת
	void transformRotationX(std::vector<Point>& points, double angle);
	// Y����ת
	void transformRotationY(std::vector<Point>& points, double angle);
	// Z����ת
	void transformRotationZ(std::vector<Point>& points, double angle);
	// ���þֲ���������
	void setLocalCenter(const Vector4& pos);
protected:
	// ת������
	Matrix4x4 m_transMat;
	// �ֲ��������ĵ�����
	Vector4 m_localCenter;
};

