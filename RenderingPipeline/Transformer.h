#pragma once

#include "user_data.h"
#include "Matrix4x4.h"
#include "Vector4.h"
#include <vector>

/*
�ֲ�����ת�����������꣬��Ҫ֪���ֲ�������������������꣬������Ǿֲ��������
ƽ�Ʊ任�Ǿֲ����ĵ�λ�ƣ���ת��Χ�ƾֲ����ĵ���ת

// X��Ӹ�������ȥ��˳ʱ��
*/

class Transformer
{
public:
	Transformer();
	~Transformer();

	// �°�Ľӿ�
	// �����ڿռ��е��ƶ�
	void transformOffset(Object& object, Vector4& offset);
	// X����ת
	void transformRotationX(Object& object, double angle);
	// Y����ת
	void transformRotationY(Object& object, double angle);
	// Z����ת
	void transformRotationZ(Object& object, double angle);

protected:
	// ת������
	Matrix4x4 m_transMatRotX;
	Matrix4x4 m_transMatRotY;
	Matrix4x4 m_transMatRotZ;
	Matrix4x4 m_transMatOffset;
};

