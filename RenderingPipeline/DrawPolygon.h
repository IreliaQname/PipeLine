#pragma once

#include <QWidget>
#include <QPainter>
#include <vector>
#include "user_data.h"
#include "PolygonCliper.h"
#include "DrawLineAlgorithm.h"

/*
���ƶ����
*/
class DrawPolygon
{
public:
	DrawPolygon();
	~DrawPolygon();

	///////////////////////////�°�Ľӿ�////////////////////////////////////
	// �����Object��ÿ���㶼��ͶӰ��һ�����
	// ���ƺ���
	void drawPolygonTexture(QWidget* widget, QPainter* painter, Object& object);
	// ���Ʊ߿�
	void drawFrame(QWidget* widget, QPainter* painter, Object& points);
	// �������
	void drawFill(QWidget* widget, QPainter* painter, Object& points);

	// ��������
	void setTexture(int** red, int** green, int** blue);
	// ������Ȼ���
	void setDepth(double** depth);

	inline void setMode(int mode) { m_mode = mode; }
protected:
	// ���Ĵ���
	QWidget* m_widget{ nullptr };
	// ���Ļ�ˢ
	QPainter* m_painter{ nullptr };
	// �ü���
	PolygonCliper* m_PolygonCliper{ nullptr };
	// �����㷨
	DrawLineAlgorithm* m_drawLine;

	// �ü���Ķ���ζ���
	std::vector<Point> m_polygonPoints;
	// ����RGB
	int** m_textureRed{ nullptr };
	int** m_textureGreen{ nullptr };
	int** m_textureBlue{ nullptr };
	// ��Ȼ������
	double** m_depthBuffer{ nullptr };

	// ����ģʽ��0����䣬��������ͼ
	int m_mode{ 0 };
};

