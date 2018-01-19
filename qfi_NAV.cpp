#include "qfi_NAV.h"
#include <stdio.h>
#include <iostream>
using namespace std;

qfi_NAV::qfi_NAV(QWidget *parent):
	QGraphicsView(parent),
	m_scene(0),
	m_background(0),
	m_henggun(0),
	m_zongqing(0),
	m_pianzhuan(0),

	m_originalNavCtr(x_central,y_central),

	move_zongqing_new(0.0f),
	move_zongqing_old(0.0f),
	move_pianzhuan_new(0.0f),
	move_pianzhuan_old(0.0f),

	m_scaleX(1.0f),
	m_scaleY(1.0f),

	m_backZ(100),
	m_maskZ(100),
	m_markZ(200),

	m_originalHeight(280),
	m_originalWidth(350)
{
	reset();

	m_scene = new QGraphicsScene(this);
	setScene(m_scene);

	m_scene->clear();

	init();
}
qfi_NAV::~qfi_NAV()
{
	if (m_scene)
	{
		m_scene->clear();
		delete m_scene;
		m_scene = 0;
	}
	reset();
}
//��λ������2017.12.26
void qfi_NAV::reinit()
{
	if (m_scene)
	{
		m_scene->clear();
		init();
	}
}
//����״̬��2017.12.26
void qfi_NAV::update()
{
	updateView();

	move_zongqing_old = move_zongqing_new;
	move_pianzhuan_old = move_pianzhuan_new;
}
//����AUV�ĺ���ǣ�2017.12.26
void qfi_NAV::setHengGun(float HengGun)
{
	m_henggunJiao = HengGun;

	while (m_henggunJiao <   0.0f) m_henggunJiao += 360.0f;
	while (m_henggunJiao > 360.0f) m_henggunJiao -= 360.0f;
}
//����AUV�����
void qfi_NAV::setZongQing(float ZongQing)
{
	m_zongqingJiao = ZongQing;

	while (m_zongqingJiao <   0.0f) m_zongqingJiao += 360.0f;
	while (m_zongqingJiao > 360.0f) m_zongqingJiao -= 360.0f;
}
//����AUVƫת��
void qfi_NAV::setPianZhuan(float PianZhuan)
{
	m_pianzhuanJiao = PianZhuan;

	while (m_pianzhuanJiao <   0.0f) m_pianzhuanJiao += 360.0f;
	while (m_pianzhuanJiao > 360.0f) m_pianzhuanJiao -= 360.0f;
}
//�������ڴ�С��2017.12.26
void qfi_NAV::resizeEvent(QResizeEvent *event)
{
	QGraphicsView::resizeEvent(event);

	reinit();
}

void qfi_NAV::init()
{	
	//���ű���ϵ��
	m_scaleX = (float)width() / (float)m_originalWidth;
	m_scaleY = (float)height() / (float)m_originalHeight;

	//����---2017.12.26
	m_background = new QGraphicsSvgItem(":/svg/image/nav_background.svg");
	m_background->setCacheMode(QGraphicsItem::NoCache);
	m_background->setZValue(m_backZ);
	m_background->setTransform(QTransform::fromScale(m_scaleX, m_scaleY), true);
	m_scene->addItem(m_background);
	m_originalNavCtr = m_background->boundingRect().center();
	//���---2017.12.26
	m_henggun = new QGraphicsSvgItem(":/svg/image/nav_henggun.svg");
	m_henggun->setCacheMode(QGraphicsItem::NoCache);
	m_henggun->setZValue(m_maskZ);
	m_henggun->setTransform(QTransform::fromScale(m_scaleX, m_scaleY), true);
	m_henggun->setTransformOriginPoint(m_originalNavCtr.x(), m_originalNavCtr.y());
	m_scene->addItem(m_henggun);
	//����---2107.12.26
	m_zongqing = new QGraphicsSvgItem(":/svg/image/nav_zongqing.svg");
	m_zongqing->setCacheMode(QGraphicsItem::NoCache);
	m_zongqing->setZValue(m_maskZ);
	m_zongqing->setTransform(QTransform::fromScale(m_scaleX, m_scaleY), true);
	m_zongqing->setTransformOriginPoint(m_originalNavCtr.x(), m_originalNavCtr.y());
	m_scene->addItem(m_zongqing);
	//ƫת
	m_pianzhuan = new QGraphicsSvgItem(":/svg/image/nav_pianzhuan.svg");
	m_pianzhuan->setCacheMode(QGraphicsItem::NoCache);
	m_pianzhuan->setZValue(m_maskZ);
	m_pianzhuan->setTransform(QTransform::fromScale(m_scaleX, m_scaleY), true);
	m_pianzhuan->setTransformOriginPoint(m_originalNavCtr.x(), m_originalNavCtr.y());
	m_scene->addItem(m_pianzhuan);

	updateView();
}

void qfi_NAV::reset()
{
	m_henggunJiao = 0.0f;
	m_pianzhuanJiao = 0.0f;
	m_zongqingJiao = 0.0f;
}

void qfi_NAV::updateView()
{
	//���±���ϵ��
	m_scaleX = (float)width() / (float)m_originalWidth;
	m_scaleY = (float)height() / (float)m_originalHeight;
	//����ǣ�ֱ��ƫת
	m_henggun->setRotation(m_henggunJiao);
	//����ǣ���Ҫת��
	move_zongqing_new = 40 * sin(m_zongqingJiao);
	m_zongqing->moveBy(0, move_zongqing_new - move_zongqing_old);
	//ƫת�ǣ���Ҫת��
	move_pianzhuan_new = 40 * sin(m_pianzhuanJiao);
	m_pianzhuan->moveBy(move_pianzhuan_new - move_pianzhuan_old, 0);
	//����
	m_scene->update();
	//�Ƶ����Ĵ�
	centerOn(width()/2.0, height()/2.0);
}
