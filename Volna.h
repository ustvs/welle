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
//	double Teta_min;				// Минимальный угол падения
	int mode;//		какая мода выбрана: 
			 //		0 - волноводная,
			 //		1 - излучательная в обе стороны,
			 //		2 - излучательная в подложку
	double lambda;					// Длина волны
	double    Nf;					// Показатель преломления пленки
	double    Nc;					// Показатель преломления покровного слоя
	double    Ns;					// Показатель преломления подложки
	double	   h;					// Толщина пленки
	double  Teta;					// Угол падения
	int		   v;					// Номер моды
	int type_welle;					// Тип волны: true(1)-TE волна, false(0)-TM волна
	
//	int Zahle;						// Число мод
	double h_min;					// Минимальная толщина пленки 
	double lambda_max;				// Максимальная длина волны
	double	Amplitude;					// Интенсивность

	double FindenTeta();
	double Urav(double ugol);
	double FindenFc(double ugol);
	double FindenFs(double ugol);

	virtual ~CVolna();

private:
	bool kontrol();

};

#endif // !defined(AFX_VOLNA_H__B5DCDC41_5287_11D4_81AA_0000E8DAC825__INCLUDED_)
