#pragma once

#include <QtWidgets/QWidget>
#include "ui_RenderingPipeline.h"

#include "user_data.h"
#include "Transformer.h"
#include "Camera.h"
#include "DrawPolygon.h"
#include "Light.h"
#include "Vector4.h"

class RenderingPipeline : public QWidget
{
	Q_OBJECT

public:
	RenderingPipeline(QWidget *parent = Q_NULLPTR);
	virtual ~RenderingPipeline();

protected:

	void paintEvent(QPaintEvent *event)override;
	void keyPressEvent(QKeyEvent *event)override;

	// ������Ȼ�������
	void updateDepthBuffer();
	
	// �����ƾֲ�XYZ����ת��ľֲ�����
	void setRotationX(double angle);
	void setRotationY(double angle);
	void setRotationZ(double angle);

	// ������ƽ�ƺ������
	void setOffsetXYZ(const Vector4& offset);

	// ��һ���Ȼ���һ�������壬�ռ�ͼ�α�����ƽ��ģ������޷���ȷ���ơ�
	// ����ͼ����ƽ��ƴ��

	// ���Ǿֲ�������
	std::vector<Point> m_polygonLocal1;
	std::vector<Point> m_polygonLocal2;
	std::vector<Point> m_polygonLocal3;
	std::vector<Point> m_polygonLocal4;
	std::vector<Point> m_polygonLocal5;
	std::vector<Point> m_polygonLocal6;

	// �������������
	std::vector<Point> m_polygonWorld1;
	std::vector<Point> m_polygonWorld2;
	std::vector<Point> m_polygonWorld3;
	std::vector<Point> m_polygonWorld4;
	std::vector<Point> m_polygonWorld5;
	std::vector<Point> m_polygonWorld6;


	Transformer* m_tranformer{ nullptr };
	Camera* m_camera{ nullptr };
	DrawPolygon* m_drawPolygon{ nullptr };
	Light* m_light{ nullptr };

	// ����RGB
	int** m_textureRed{ nullptr };
	int** m_textureGreen{ nullptr };
	int** m_textureBlue{ nullptr };

	// ��Ȼ������
	double** m_depthBuffer{ nullptr };

	// �ֲ���������
	Vector4 m_localPos;
	// ���λ��
	Vector4 m_camPos;
	// �������
	Vector4 m_camTarget;
	// ����
	Vector4 m_UpVec;
	// ���ߵķ���
	Vector4 m_lightDir;

	bool m_showFrame{ true };
	bool m_showFill{ false };
	bool m_showTexture{ true };

private:
	Ui::RenderingPipelineClass ui;
};