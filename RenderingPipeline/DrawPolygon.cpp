#include "DrawPolygon.h"



DrawPolygon::DrawPolygon()
{
	m_PolygonCliper = new PolygonCliper;
}


DrawPolygon::~DrawPolygon()
{
	if (m_PolygonCliper != nullptr) {
		delete m_PolygonCliper;
	}
}

void DrawPolygon::drawPolygonTexture(QWidget * widget, QPainter * painter, std::vector<Point>& points)
{
	int w = widget->width();
	int h = widget->height();
	m_PolygonCliper->setBoundary(h / 2, -h / 2, -w / 2, w / 2);
	m_polygonPoints.clear();  // �����ǰ�Ļ���
	m_PolygonCliper->clip(points, m_polygonPoints);
	/*
	����д���������㷨
	*/
}

void DrawPolygon::drawFrame(QWidget * widget, QPainter * painter, std::vector<Point>& points)
{
	int w = widget->width();
	int h = widget->height();
	m_PolygonCliper->setBoundary(h / 2, -h / 2, -w / 2, w / 2);
	m_polygonPoints.clear();  // �����ǰ�Ļ���
	m_PolygonCliper->clip(points, m_polygonPoints);
	/*
	����д���Ʊ߿��㷨
	*/
}

void DrawPolygon::drawFill(QWidget * widget, QPainter * painter, std::vector<Point>& points)
{
	int w = widget->width();
	int h = widget->height();
	m_PolygonCliper->setBoundary(h / 2, -h / 2, -w / 2, w / 2);
	m_polygonPoints.clear();  // �����ǰ�Ļ���
	m_PolygonCliper->clip(points, m_polygonPoints);
	/*
	����д��������㷨
	*/
}

void DrawPolygon::setTexture(int** red, int** green, int** blue)
{
	m_textureRed = red;
	m_textureGreen = green;
	m_textureBlue = blue;
}
