#pragma once
#include <QWidget>
#include "ui_nav_Widget.h"
#include <qfi_NAV.h>
#include <iostream>
using namespace std;

namespace Ui
{
	class nav_Widget;
}
//�ӿ���+������
class nav_Widget : public QWidget
{
	Q_OBJECT

public:
	explicit nav_Widget(QWidget *parent = 0);
	virtual ~nav_Widget();

	//���ô���Ϊ͸��,2017.12.21
	void setBGColor();
	//���ý�������
	inline void setCentral(float x, float y)
	{
		m_nav->setCentral(x, y);
	}
	//����
	inline void update()
	{
		m_nav->update();
	}
	//����AUV�ĺ���ǣ�������С������Ϊ�������������нϿ�������ٶ�
	inline void setHengGun(float HengGun)
	{
		m_nav->setHengGun(HengGun);
	}
	//����AUV�������
	inline void setZongQing(float ZongQing)
	{
		m_nav->setZongQing(ZongQing);
	}
	//����AUV��ƫת��
	inline void setPianZhuan(float PianZhuan)
	{
		m_nav->setPianZhuan(PianZhuan);
	}
	//�������ڴ�С
	inline void ChangeSize(int x, int y)
	{
		this->resize(x, y);
	}
	//�ƶ�����λ��
	inline void MoveWidget(int x, int y)
	{
		this->move(x, y);
	}

private:
	Ui::nav_Widget *m_ui;
	qfi_NAV *m_nav;
};
