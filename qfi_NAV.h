#pragma once
#include <QGraphicsSvgItem>
#include <QGraphicsView>

class qfi_NAV:public QGraphicsView
{
	Q_OBJECT
public:
	explicit qfi_NAV(QWidget *parent = 0);
	virtual ~qfi_NAV();
	
	//复位
	void reinit();
	//更新状态
	void update();
	//设置横滚角
	void setHengGun(float HengGun);
	//设置纵倾角
	void setZongQing(float ZongQingJiao);
	//设置偏转角
	void setPianZhuan(float PianZhuanJiao);
	//设置中心坐标
	inline void setCentral(float x, float y)
	{
		x_central = x;
		y_central = y;
	}
protected:
	//重新调整scene大小
	void resizeEvent(QResizeEvent *event);

private:
	//2017.12.15
	QGraphicsScene *m_scene;
	//scene中心
	float x_central, y_central;
	
	QGraphicsItem *m_background;  //svg背景
	QGraphicsItem *m_henggun;     //svg横滚     
	QGraphicsItem *m_pianzhuan;   //svg偏转
	QGraphicsItem *m_zongqing;    //svg纵倾

	QPointF m_originalNavCtr;     //初始scene中心坐标

	float m_pianzhuanJiao;        //偏转角大小              
	float m_henggunJiao;          //横滚角大小
	float m_zongqingJiao;         //纵倾角大小

	float move_zongqing_new;      //由纵倾角引发的位移，新值
	float move_zongqing_old;      //由纵倾角引发的位移，旧值
	float move_pianzhuan_new;     //由偏转角引发的位移，新值
	float move_pianzhuan_old;     //由偏转角引发的位移，旧值

	float m_scaleX;               //窗口大小比例系数              
	float m_scaleY;               //窗口大小比例系数            

	const int m_originalHeight;   //scene初始高度        
	const int m_originalWidth;    //scene初始宽度        

	//svg参数值
	const int m_backZ;            
	const int m_maskZ;            
	const int m_markZ;

	//初始化
	void init();

	//复位
	void reset();

	//更新视图
	void updateView();	
};