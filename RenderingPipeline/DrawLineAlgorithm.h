#pragma once

#include "user_data.h"
#include <vector>

/*
�����㷨�Ļ��࣬����������Ƕ�ά�ռ�ĵ㣬���ڶ�ά�ռ��л���
*/

class DrawLineAlgorithm
{
public:
	DrawLineAlgorithm();
	virtual ~DrawLineAlgorithm();
	// ��㡢�յ㡢������Ҫ���Ƶĵ�
	virtual void drawLine(const Point& start,
		const Point& stop,
		std::vector<Point>& pointsOut) = 0;

	inline void setBuffer(double** buf) { m_buffer = buf; }
protected:
	double** m_buffer;  // ��Ȼ��壬�������Ƿ����ĳ����
};

