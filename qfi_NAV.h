#pragma once
#include <QGraphicsSvgItem>
#include <QGraphicsView>

class qfi_NAV:public QGraphicsView
{
	Q_OBJECT
public:
	explicit qfi_NAV(QWidget *parent = 0);
	virtual ~qfi_NAV();
	
	//��λ
	void reinit();
	//����״̬
	void update();
	//���ú����
	void setHengGun(float HengGun);
	//���������
	void setZongQing(float ZongQingJiao);
	//����ƫת��
	void setPianZhuan(float PianZhuanJiao);
	//������������
	inline void setCentral(float x, float y)
	{
		x_central = x;
		y_central = y;
	}
protected:
	//���µ���scene��С
	void resizeEvent(QResizeEvent *event);

private:
	//2017.12.15
	QGraphicsScene *m_scene;
	//scene����
	float x_central, y_central;
	
	QGraphicsItem *m_background;  //svg����
	QGraphicsItem *m_henggun;     //svg���     
	QGraphicsItem *m_pianzhuan;   //svgƫת
	QGraphicsItem *m_zongqing;    //svg����

	QPointF m_originalNavCtr;     //��ʼscene��������

	float m_pianzhuanJiao;        //ƫת�Ǵ�С              
	float m_henggunJiao;          //����Ǵ�С
	float m_zongqingJiao;         //����Ǵ�С

	float move_zongqing_new;      //�������������λ�ƣ���ֵ
	float move_zongqing_old;      //�������������λ�ƣ���ֵ
	float move_pianzhuan_new;     //��ƫת��������λ�ƣ���ֵ
	float move_pianzhuan_old;     //��ƫת��������λ�ƣ���ֵ

	float m_scaleX;               //���ڴ�С����ϵ��              
	float m_scaleY;               //���ڴ�С����ϵ��            

	const int m_originalHeight;   //scene��ʼ�߶�        
	const int m_originalWidth;    //scene��ʼ���        

	//svg����ֵ
	const int m_backZ;            
	const int m_maskZ;            
	const int m_markZ;

	//��ʼ��
	void init();

	//��λ
	void reset();

	//������ͼ
	void updateView();	
};