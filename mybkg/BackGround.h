#ifndef BACKGROUND_H
#define BACKGROUND_H

#include <string>
#include <fstream>
/*#include "Common.h"*/
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
using namespace std;
class BackGround
{
	//��Ϊ
public:
	BackGround();
	~BackGround();

	void GetBackground(string srcfilename,string outputdir,unsigned int width=20,unsigned int height=20,double scale=1.2,double scalefactor=1.2,double step=0.2);
	
	void InitOutputPerBackground(string srcfilename,string outputdir,unsigned int width=20,unsigned int height=20,double scale=1.2,double scalefactor=1.2,double step=0.2);
	void OutputPerBackground(cv::Mat &bg);

	//��Ϊ
private:
	//��ʼ������
	void Init(int width,int height);

	//����ͼƬ·���ļ�
	void LoadPictures(string srcfilename);

	//���ø��������·��
	void SetOutputDir(string outputdir);

	//���������
	void OutputBackground(double scale,double scalefactor,double step);

	//�������ǰ׺
	void SetPrefix(string prefix);

	//��ȡ�����ļ�·���ͺ�׺���ļ���
	string GetFileName(const char *fullname);

	//����
private:
	unsigned int m_total;
	double m_scale;
	double m_scalefactor;
	double m_step;

	cv::Mat m_input;
	cv::Mat m_output;
	cv::Size m_bgroi;

	string m_srcfilename;
	string m_outputdir;
	string m_prefix;

	ifstream m_fin;
	string m_filepath;
	cv::Rect m_currentroi;
};

#endif