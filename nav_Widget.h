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
//接口类+界面类
class nav_Widget : public QWidget
{
	Q_OBJECT

public:
	explicit nav_Widget(QWidget *parent = 0);
	virtual ~nav_Widget();

	//设置窗体为透明,2017.12.21
	void setBGColor();
	//设置界面中心
	inline void setCentral(float x, float y)
	{
		m_nav->setCentral(x, y);
	}
	//更新
	inline void update()
	{
		m_nav->update();
	}
	//设置AUV的横滚角，函数较小，设置为内联函数，具有较快的运行速度
	inline void setHengGun(float HengGun)
	{
		m_nav->setHengGun(HengGun);
	}
	//设置AUV的纵倾角
	inline void setZongQing(float ZongQing)
	{
		m_nav->setZongQing(ZongQing);
	}
	//设置AUV的偏转角
	inline void setPianZhuan(float PianZhuan)
	{
		m_nav->setPianZhuan(PianZhuan);
	}
	//调整窗口大小
	inline void ChangeSize(int x, int y)
	{
		this->resize(x, y);
	}
	//移动窗口位置
	inline void MoveWidget(int x, int y)
	{
		this->move(x, y);
	}

private:
	Ui::nav_Widget *m_ui;
	qfi_NAV *m_nav;
};
