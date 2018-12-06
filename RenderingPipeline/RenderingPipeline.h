#pragma once

#include <QtWidgets/QWidget>
#include "ui_RenderingPipeline.h"

#include <QPaintEvent>
#include <QKeyEvent>
#include "user_data.h"
#include "Transformer.h"
#include "Camera.h"
#include "DrawPolygon.h"
#include "Light.h"
#include "Vector4.h"
#include "PerspectiveProjector.h"

/*
��Ⱦ���ߵ����࣬���Ǵ���һ������ϵ�ȱ�ݣ�
���ߵ���Ⱦ��ʾ����Camera���ڲ��ģ����������̫�ߡ�
*/

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

	Object m_initCube;  // ��ʼ��������
	Object m_finalCube; // ���ڻ��Ƶ�������

	// ����
	Transformer* m_tranformer{ nullptr };
	Camera* m_camera{ nullptr };
	DrawPolygon* m_drawPolygon{ nullptr };
	//Light* m_light{ nullptr }; 
	PerspectiveProjector* m_perspectiveProjector;

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

	// ��ʾ���
	bool m_showFrame{ true };
	bool m_showFill{ false };
	bool m_showTexture{ false };

private:
	Ui::RenderingPipelineClass ui;
};