// Volna.cpp: implementation of the CVolna class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "MDIVolna.h"
#include "Volna.h"
#include <math.h>

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif


//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CVolna::CVolna()
{
	Teta = 81.4605703079852*PI/180;
	v = 0;
	h = 1e-6;
	lambda = .6e-6;
	Nc = 1.;
	Nf = 1.62;
	Ns = 1.515;
	type_welle = 1;
	h_min = 1.83725214562442e-007;
	lambda_max = 3.26574662834904e-006;
	Amplitude = 1;
	mode = 0;
}

CVolna::~CVolna()
{

}

double CVolna::FindenTeta()
{
	double x, y, c, Fx, Fy, Fc;
	x = asin(Ns/Nf);
	y = PI/2;
	Fx = Urav(x);
	Fy = Urav(y);
	if(Fx*Fy > 0.0 || mode) return ERROR_INTERVAL;
	do{
		c = (y - x)/2  + x;
		Fc = Urav(c);
		if(Fx*Fc > 0.0) { x = c; Fy = Fc;}
		else { y = c; Fy = Fc; }
	}while(Fc != 0 && (y - x) > EPS);

	Teta = c;

	return c;
}

double CVolna::FindenFc(double ugol)
{
	double temp;

	if(type_welle)
	{
		temp = Nf*Nf*sin(ugol)*sin(ugol) - Nc*Nc;
		if (fabs(temp) < 1e-14) temp = 0;
		if ( temp < 0.)return OUR_ERROR;
		return atan(   sqrt(temp) / (Nf*cos(ugol))   );
	}
	else
	{
		temp = Nf*Nf*sin(ugol)*sin(ugol) - Nc*Nc;
		if (fabs(temp) < 1e-14) temp = 0;
		if ( temp < 0.)return OUR_ERROR;
		return atan(   (Nf*Nf/Nc/Nc)*sqrt(temp) / (Nf*cos(ugol))  );
	}
}

double CVolna::FindenFs(double ugol)
{
	double temp;

	//TE
	if(type_welle)
	{
		temp = Nf*Nf*sin(ugol)*sin(ugol) - Ns*Ns;
		if (fabs(temp) < 1e-14) temp = 0;
		if ( temp < 0.)return OUR_ERROR;
		return atan(   sqrt(temp) / (Nf*cos(ugol))   );
	}
	//TM
	else
	{
		temp = Nf*Nf*sin(ugol)*sin(ugol) - Ns*Ns;
		if (fabs(temp) < 1e-14) temp = 0;
		if ( temp < 0.)return OUR_ERROR;
		return atan(   (Nf*Nf/Ns/Ns)*sqrt(temp) / (Nf*cos(ugol))  );
	}
}

double CVolna::Urav(double ugol)
{
	return ( 2*PI/lambda*Nf*h*cos(ugol) - FindenFc(ugol) - FindenFs(ugol) - v*PI );
}

double CVolna::get_mode_amplitude(double x)
{

	if(!mode) FindenTeta();
	double temp_kc, temp_ks, kf, kc, ks, Fc, Fs, k, Es, Ec, F;
	k = 2*PI/lambda;
//	N = Nf*sin(Teta);
	kf  = sqrt(fabs(Nf*k*Nf*k - Nf*k*sin(Teta)*Nf*k*sin(Teta)));
	
	//эти значени€ вычислены дл€ 1 случа€, в остальных случа€х другие знаки
	temp_ks = -(Ns*Ns*k*k - (k*Nf*sin(Teta))*(k*Nf*sin(Teta)));
	double t1 = -Nc*Nc;
	double t2 = Nf*sin(Teta)*Nf*sin(Teta);
	temp_kc = k*k*(t1 +t2);
	//temp_kc = -k*k*( Nc*Nc - (Nf*sin(Teta))*(Nf*sin(Teta)));
	
	
	//≈сли мода волноводна€, считаем угол и возвращаем амплитуду
	if(!mode)
	{
		
		/*Fc = FindenFc(Teta);
		Fs = FindenFs(Teta);*/

		if(fabs(temp_kc)<1e-14) temp_kc = 0.0;
		kc = sqrt(temp_kc);
		
		if(fabs(temp_ks)<1e-14) temp_ks = 0.0;
		ks = sqrt(temp_ks);
		
		// TE - волна
		if(type_welle) 
		{
			Es = Amplitude*sqrt((Nf*Nf - N*N)/(Nf*Nf - Ns*Ns));
			Ec = Amplitude*sqrt((Nf*Nf - N*N)/(Nf*Nf - Nc*Nc));
		}
		
		// TM - волна
		else
		{
			double q = (N/Nf)*(N/Nf) + (N/Ns)*(N/Ns) - 1;
			Es = Amplitude*Ns/Nf*sqrt((Nf*Nf - N*N)/(Nf*Nf - Ns*Ns) )/sqrt(q);
			
			q = (N/Nf)*(N/Nf) + (N/Nc)*(N/Nc) - 1;
			Ec = Amplitude*Nc/Nf*sqrt((Nf*Nf - N*N)/(Nf*Nf - Nc*Nc) )/sqrt(q);
		}

		if( x < 0.0) return Es*exp(ks*x);
		if( x >= 0.0 && x <= h ) return Amplitude*cos(kf*x - FindenFs(Teta) );
		if(v%2)	return - Ec*exp(-kc*(x - h));//если мода четна€
		else return Ec*exp(-kc*(x - h));//если мода нечетна€
	}
	

	// ¬ случае излучательных мод в покровный слой и подложку
	if(mode == 1)
	{
		temp_kc = -temp_kc;
		if( fabs(temp_kc) < 1e-14 ) temp_kc = 0.0;
		double kc = sqrt(temp_kc);
		
		temp_ks = -temp_ks;
		if( fabs(temp_ks) < 1e-14 ) temp_ks = 0.0;
		double ks = sqrt(temp_ks);
		
		// TE - волна
		if(type_welle)
		{
			F = .5*atan(  sin( 2*kf*h )/( cos(2*kf*h) + ks/kc*(1 - kf*kf/ks/ks)/
				(1 - kf*kf/kc/kc) )  );
			Fs = atan(ks/kf*tan(F));	//ks tan(F) = kf tan(Fc)
			
			Fc = atan(kc/kf*tan(kf*h - F));
			Es = Amplitude*sqrt( ( sin(F)*sin(F) + (kf*kf)/(ks*ks)*cos(F)*cos(F) ) );
			Ec = Amplitude*sqrt( ( sin(kf*h - F)*sin(kf*h - F)
				+ (kf*kf)/(kc*kc)*cos(kf*h - F)*cos(kf*h - F) ) );
		}

		// TM - волна
		else
		{
			F = .5*atan
			(
				sin( 2*(kf/Nf/Nf)*h )/
				(
					cos(2*(kf/Nf/Nf)*h) + 
					(ks/Ns/Ns)/(kc/Nc/Nc)*( 1 - (kf/Nf/Nf)*(kf/Nf/Nf)/(ks/Ns/Ns)/(ks/Ns/Ns) )/
					( 1 - (kf/Nf/Nf)*(kf/Nf/Nf)/(kc/Nc/Nc)/(kc/Nc/Nc) )
				)
			);
			
			Fs = atan( ks*(Nf*Nf)*tan(F)/(Ns*Ns)/kf );	//ks/ns*ns tan(F) = kf/nf*nf tan(Fc)
			Fc = atan( kc*Nf*Nf/(kf*Nc*Nc)*tan(kf*h - F) );
			Es = Amplitude*sqrt( ( sin(F)*sin(F) + (Ns*Ns*kf)/(Nf*Nf*ks)*(Ns*Ns*kf)/
				(Nf*Nf*ks)*cos(F)*cos(F) ) );
			Ec = Amplitude*sqrt( ( sin(kf*h - F)*sin(kf*h - F) + 
				(Nc*Nc*kf)/(Nf*Nf*ks)*(Nc*Nc*kf)/
				(Nf*Nf*ks)*cos(kf*h - F)*cos(kf*h - F) ) );
		}
		
		if(Es*sin( - Fs) * Amplitude*sin(- F) < 0.) Es = -Es;
		if( x <= 0.0) return Es*sin(ks*x - Fs);
		if( x > 0.0 && x <= h )	return Amplitude*sin(kf*x - F);
		if(( (Ec*sin( Fc ))*Amplitude*sin(kf*h - F) ) < 0.0) Ec = -Ec;
		return (Ec*sin(kc*(x - h) + Fc )) ;
	}

	// ¬ случае излучательных мод в подложку
	else
	{
		if( fabs(temp_kc) < 1e-14 ) temp_kc = 0.0;
		kc = sqrt(temp_kc);
	
		temp_ks = -temp_ks;
		if( fabs(temp_ks) < 1e-14 ) temp_ks = 0.0;
		ks = sqrt(temp_ks);

		// TE - волна
		if(type_welle)
		{			
			Fc = atan(kc/kf);
			F = atan(kf/ks*tan(Fc - kf*h));
			Ec = Amplitude*sqrt( (Nf*Nf - N*N)/(Nf*Nf - Nc*Nc) );
			Es = Amplitude*sqrt( (1 + (Nf*Nf - Ns*Ns)/(Ns*Ns - N*N)*sin(Fc - kf*h)*sin(Fc - kf*h)) );
		}
		
		// TM - волна
		else
		{
			Fc = atan( (Nf*Nf)/(Nc*Nc)*(kc/kf) );
			F = atan( (kf/(Nf*Nf))*tan(Fc - kf*h)*((Ns*Ns)/ks) );
			
			double q = (N/Nf)*(N/Nf) + (N/Nc)*(N/Nc) - 1;
			Ec = Amplitude*	sqrt( (Nf*Nf - N*N)/(Nf*Nf)/((Nf*Nf - Nc*Nc)*q/(Nc*Nc)) );

			//Fs = atan( (Nf/Ns)*(Nf/Ns)*ks/kf );
			q = (N/Nf)*(N/Nf) + (N/Ns)*(N/Ns) - 1;
			Es = Amplitude*sqrt( ( 1 + (Ns*Ns)/(Nf*Nf)*q*((Nf*Nf - Ns*Ns)/
				(Ns*Ns - N*N))*sin(F - kf*h)*sin(F - kf*h) ) );
		}

		if(Es*cos(F) * Amplitude*cos(kf*( -h) + Fc ) < 0.)Es = - Es; 
		if( x <= 0.0) return Es*cos(ks*x + F);
		if( x > 0.0 && x <= h )	return Amplitude*cos(kf*(x - h) + Fc );
		if(Ec* Amplitude*cos( Fc ) < 0. )Ec = -Ec;
		return Ec*exp(- kc*(x - h));
	}
	return 0.0;
}

bool CVolna::kontrol()
{
	if( (Nf < Ns) || (Ns < Nc)) return FALSE;
	else return TRUE;		
}


void CVolna::calculate_Xi()
{
	double k = 2*PI/lambda;
	double temp_ks = -(Ns*Ns*k*k - (k*Nf*sin(Teta))*(k*Nf*sin(Teta)));
	double t1 = -Nc*Nc;
	double t2 = Nf*sin(Teta)*Nf*sin(Teta);
	double temp_kc = k*k*(t1 +t2);
	if(!mode)
	{
		if(fabs(temp_kc)<1e-14) Xc = 99.0;// very big
		else Xc = 1/sqrt(temp_kc);
		
		if(fabs(temp_ks)<1e-14) Xs = 99.0;
		Xs = 1/sqrt(temp_ks);
	}
}
