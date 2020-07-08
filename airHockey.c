/*-------------------------------------------------------------------------- */
/*                                                                           */
/*                    HW07_Part2_141044049_Ebru_Kardas                       */
/*                                                                           */
/* main.c                                                                    */
/* ------                                                            	     */
/* Created on 14/4/2016 by Ebru Kardas                                       */
/*                                                                           */
/* Description                                                               */
/* -----------                                                               */
/* The main.c contains finding the ball is in the goal width or not.
/*                                                                           */
/* ------------------------------------------------------------------------  */
/*                                                                           */
/* Notes		                                                             */
/* -----	                              	                                 */
/* Inputs: wallWidth, wallHeight, ballCenterX, kickAngle, ballRadius,		 */
/* goalWidth															     */
/* Output: is in goal width return 1 or not 0					             */
/*                                                                           */
/* ------------------------------------------------------------------------  */


#include <math.h>
#include <stdlib.h>

#define PI 3.1415926535

int kickDisc(double wallWidth, double wallHeight, double ballCenterX, 
			 double kickAngle, double ballRadius, double goalWidth);
int reflection(int angle);
int randNumber(int angle);


int main (){
	kickDisc(10, 26, 2, 45, 1, 2); /* 0 */
	return 0;
}

/* ------------------------------------------------------------------------  */

int kickDisc(double wallWidth, double wallHeight, double ballCenterX, 
			 double kickAngle, double ballRadius, double goalWidth){

	double degree, y, x;
	if( wallWidth<=0 && ballCenterX-ballRadius<0 && ballRadius<0 &&
		goalWidth<0 && goalWidth>wallWidth) {
		return 0;
	}
/* take its tangent and multiply with value which is direction's projection  */
/* and the result is height according to angle for the first crash. If it is */
/* heigher than height of table, don't take the height of first crash, take  */
/* projection according the rest of height. And compare if it is in the goal */
/* or not */
	else{
		degree = kickAngle * PI/180;				  // transform to radian 
		y = (wallWidth-ballCenterX) * tan(degree);
		if(y<wallHeight){
			kickDisc(wallWidth, wallHeight-y, wallWidth - ballRadius, 
						reflection(kickAngle), ballRadius, goalWidth);
		}
		else if(y>=wallHeight){
			x= wallHeight * tan(degree);
			if( x+ballCenterX<= (wallWidth+goalWidth)/2 && 
				x+ballCenterX>= (wallWidth-goalWidth)/2){
				return 1;
			}
		}
	}
}

int reflection(int angle){
	angle = angle + ( randNumber(angle)%6 );			
/* random number function's result has to be between 5 - -5 include 5 and *5 */
/* so taken mode according to 6 											 */
	if(angle > 175){				 // if it is higher than 175, be set 175 
		return (angle=175);
	}
	else if(angle < 5){					  // if it is lower than 5, be set 5 
		return (angle=5);
	}
	return angle;
}

int randNumber(int angle){						// the given rannum function 
	srand(angle);
	return rand();
}
