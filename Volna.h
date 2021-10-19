// Volna.h: interface for the CVolna class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_VOLNA_H__B5DCDC41_5287_11D4_81AA_0000E8DAC825__INCLUDED_)
#define AFX_VOLNA_H__B5DCDC41_5287_11D4_81AA_0000E8DAC825__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

//////////////////////////////////////////////////////////////////////
#define		OUR_ERROR			-1
#define		PI					3.1415926535897932
#define		ERROR_INTERVAL		-2
#define		EPS					1e-6
#define		K					2*PI/lambda
#define		N					Nf*sin(Teta)
//////////////////////////////////////////////////////////////////////

class CVolna  
{ 
public:
	void calculate_Xi();
	double Xs;
	double Xc;
	double get_mode_amplitude(double);
	CVolna();
//	double Teta_min;				// ����������� ���� �������
	int mode;//		����� ���� �������: 
			 //		0 - �����������,
			 //		1 - ������������� � ��� �������,
			 //		2 - ������������� � ��������
	double lambda;					// ����� �����
	double    Nf;					// ���������� ����������� ������
	double    Nc;					// ���������� ����������� ���������� ����
	double    Ns;					// ���������� ����������� ��������
	double	   h;					// ������� ������
	double  Teta;					// ���� �������
	int		   v;					// ����� ����
	int type_welle;					// ��� �����: true(1)-TE �����, false(0)-TM �����
	
//	int Zahle;						// ����� ���
	double h_min;					// ����������� ������� ������ 
	double lambda_max;				// ������������ ����� �����
	double	Amplitude;					// �������������

	double FindenTeta();
	double Urav(double ugol);
	double FindenFc(double ugol);
	double FindenFs(double ugol);

	virtual ~CVolna();

private:
	bool kontrol();

};

#endif // !defined(AFX_VOLNA_H__B5DCDC41_5287_11D4_81AA_0000E8DAC825__INCLUDED_)
