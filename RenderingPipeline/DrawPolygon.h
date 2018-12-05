#pragma once

#include <QWidget>
#include <QPainter>
#include <vector>
#include "user_data.h"
#include "PolygonCliper.h"

/*
���ƶ����
*/
class DrawPolygon
{
public:
	DrawPolygon();
	~DrawPolygon();
	// ���ƶ��������
	void drawPolygonTexture(QWidget* widget, QPainter* painter, std::vector<Point>& points);
	// ���Ʊ߿�
	void drawFrame(QWidget* widget, QPainter* painter, std::vector<Point>& points);
	// �������
	void drawFill(QWidget* widget, QPainter* painter, std::vector<Point>& points);
	// ��������
	void setTexture(int** red, int** green, int** blue);
	
	// ������Ȼ���
	inline void setDepth(double** depth) { m_depthBuffer = depth; }
protected:
	// ���Ĵ���
	QWidget* m_widget{ nullptr };
	// ���Ļ�ˢ
	QPainter* m_painter{ nullptr };
	// �ü���
	PolygonCliper* m_PolygonCliper{ nullptr };
	// �ü���Ķ���ζ���
	std::vector<Point> m_polygonPoints;
	// ����RGB
	int** m_textureRed{ nullptr };
	int** m_textureGreen{ nullptr };
	int** m_textureBlue{ nullptr };
	// ��Ȼ������
	double** m_depthBuffer{ nullptr };
};

