#include "nav_Widget.h"
#include "qgraphicsview.h"

//构造函数
nav_Widget::nav_Widget(QWidget *parent)
	: QWidget(parent),
	m_ui(new Ui::nav_Widget),
	m_nav(new qfi_NAV)
{
	m_ui->setupUi(this);
	m_nav = m_ui->graphicsNAV;
	m_nav->setWindowFlags(this->windowFlags() | Qt::WindowStaysOnTopHint);
}
//析构函数
nav_Widget::~nav_Widget()
{
	if (m_ui) 
		delete m_ui; 
	m_ui = 0;
}
//设置窗体为透明
void nav_Widget::setBGColor()
{
	this->setStyleSheet("background-color:rgba(250,250,250,2)"); //这是设置背景透明
}

