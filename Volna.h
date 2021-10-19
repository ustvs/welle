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
//	double Teta_min;				// Minimum angle of incidence
	int mode;//		Chosen mode: 
			 //		0 - Waveguide,
			 //		1 - radiative in both directions,
			 //		2 - radiating to substrate
	double lambda;					// The length of the wave
	double    Nf;					// Refractive index of the film
	double    Nc;					// Refractive index of the cover layer
	double    Ns;					// Refractive index of the substrate
	double	   h;					// Film thickness
	double  Teta;					// The angle of incidence
	int		   v;					// Mode number
	int type_welle;					// Wave type: true (1) -TE wave, false (0) -TM wave
	
//	int Zahle;						// Number of modes
	double h_min;					// Minimum film thickness
	double lambda_max;				// Maximum wavelength
	double	Amplitude;					// Intensity

	double FindenTeta();
	double Urav(double ugol);
	double FindenFc(double ugol);
	double FindenFs(double ugol);

	virtual ~CVolna();

private:
	bool kontrol();

};

#endif // !defined(AFX_VOLNA_H__B5DCDC41_5287_11D4_81AA_0000E8DAC825__INCLUDED_)
