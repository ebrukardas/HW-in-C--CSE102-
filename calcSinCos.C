/*-------------------------------------------------------------------------- */
/*                                                                           */
/*                    HW04_Part1_141044049_Ebru_Kardas                       */
/*                                                                           */
/* main.c                                                                    */
/* ------                                                            	     */
/* Created on 25/3/2016 by Ebru Kardas                                       */
/*                                                                           */
/* Description                                                               */
/* -----------                                                               */
/* The main.c contains the implementation of function for the part of        */
/* the homework 4, which is used for calculating sine and cosine via         */
/* Taylor's series. 										                 */
/* NOTE: No other libraries are allowed to use like math                     */
/* ------------------------------------------------------------------------  */
/*                                                                           */
/* Notes		                                                             */
/* ------------------------------------------------------------------------  */
/* Inputs: degree and n value is taken by getInputs function			     */
/* Outputs: the value which is calculated by Taylor'series (cosine and sine  */
/* functions)of sine and cosine. 											 */
/* 																			 */
/* ------------------------------------------------------------------------  */ 
/*                                                                           */ 
/*                                                                           */
#define PI 3.14										 /* for radian convertion*/
#include <stdlib.h>
/*                                                                           */
/*                                                                           */
/* ------------------------------------------------------------------------  */
/*                         Function Prototypes                               */
/* ------------------------------------------------------------------------  */ 
/*                                                                           */
/* Power function I wrote.			 										 */
double power(double deger, int n);				   
/*                                                                           */
/* Factorial function I wrote.												 */
int factorial(int deger);
/*                                                                           */
/* function which calculate cosine via Taylor's series						 */
double cosine(int degree, int n);
/*                                                                           */
/* function which calculate sine via Taylor's series						 */
/*                                                                           */
/*     degree  -	taken degree for calculate sine and cosine	             */
/*     n 	   - 	n value is for Taylor's series                           */
double sine(int degree, int n);
/*                                                                           */
/*                                                                           */
/* Function gets inputs (degree and n)	and exit as pointer to return		 */
/*                                                                           */
/* 		degree - to get input to "degree" to use in other functions		     */
/*      n 	   - for n value is for Taylor's series       				     */
/*      exit   - exit pointer to return	                                     */
/*                                                                           */
/*   Return	(pointer)                                                        */
/*   ------                                                                  */
/*   0 on success                                                            */
/*   1 on error	                                                             */
void getInputs(int* degree, int* n, int* exit);
/*                                                                           */
/* ------------------------------------------------------------------------  */
/*                                                                           */
/*                      Function Implementations                             */
/*                                                                           */
/* ------------------------------------------------------------------------  */
/*                                                                           */
void getInputs(int* degree, int* n, int* exit){
	char ch;										   /* To get a character */
	int status;						  /* To control e or E character to exit */

/*  All values should be 0, in first.                 		                 */

	status =0;
	*degree =0;
	*n = 0;
	*exit = 0;

	status = scanf("%d ", degree);
/* If status scaned equals to 0 which means character is taken, take character*/
    if(status == 0)
	    scanf(" %c",&ch);

/* If taken character is 'e' or 'E', return 1 via exit pointer				 */
	if( ch == 'e' || ch == 'E'){
		*exit=1;
		return;
	}

/* Get n value                                                        		 */
	scanf("%d",  n);
}


double cosine(int degree, int n){
/* 		powe	-	-1's power												 */
/*		facto	-	factorial												 */
/*		degreepow-	degree's power											 */
/*		i 		-	loop to	 calculate Taylor's series						 */
/*		result  -	basis formula											 */
/*		sum		-	total value of the series								 */
	double  powe, facto, degreepow, i;
	double result, sum;
	double derece;

/*  All values should be 0, in first.                 		                 */
	result = 0.00;
	sum = 0.00;

/* If degree is higher than 360 which is about trigonometry, get mode		 */
	if(degree>=360)
		degree = degree%360;

/* Cast to double to use other functions									 */
	derece=(double)degree;

/* Convert to radian */
	derece = derece * (PI / 180);

/*  Calculate Taylor's series	                                             */
	for (i = 0; i < n; i++){
		powe = power((-1), i);
		facto = factorial(2*i);
		facto = (double)facto;
		degreepow = power(derece, (2*i));

		result = (powe/facto)*degreepow;
		sum = sum + result;
	}
/* cosine is negative between PI/2 and 3*PI/2								 */
	if(derece>=(PI/2) && derece<=(3*PI/2))
		sum = 0 - sum;

	return sum;
}

double sine(int degree, int n){
/* 		powe	-	-1's power												 */
/*		facto	-	factorial												 */
/*		degreepow-	degree's power											 */
/*		result  -	basis formula											 */
/*		sum		-	total value of the series								 */
	double  powe, facto, degreepow, i;
	double result, sum;
	double derece;

/*  All values should be 0, in first.                 		                 */
	result = 0.00;
	sum = 0.00;

/* If degree is higher than 360 which is about trigonometry, get mode		 */
	if(degree>=360)
		degree = degree%360;

/* Cast to double to use other functions									 */
	derece=(double)degree;

/* Convert to radian */
	derece = derece * (PI / 180);

/*  Calculate Taylor's series	                                             */
	for (i = 0; i < n; i++){
		powe = power((-1), i);
		facto = factorial((2*i)+1);
		facto = (double)facto;
		degreepow = power(derece, ((2*i)+1) );

		result = (powe/facto)*degreepow;
		sum = sum + result;
	}
/* cosine is negative between PI and 2*PI									 */
	if(derece>=PI && derece<=(2*PI))
		sum = 0 - sum;
	return sum;
}

double power(double num, int n) {

	double pow=1.0, d=num;

	if(n == 0)
		return 1;
	for( ; n!=0; --n) /* n >= 1*/
		pow = pow * d;

	return pow;
}

int factorial(int num) {
	int i=1, fact=1;

	for( ;i <= num; ++i )
		fact = fact * i;

	return fact;
}
