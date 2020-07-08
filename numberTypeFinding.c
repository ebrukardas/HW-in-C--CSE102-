/*-------------------------------------------------------------------------- */
/*                                                                           */
/*                    HW03_141044049_Ebru_Kardas      		                 */
/*                                                                           */
/*                                                                           */
/*                                                                           */
/* 								main.c                                       */
/* 								------                                	     */
/* 					Created on 18/2/2016 by Ebru Kardas                      */
/*                                                            	             */
/*                                                                           */
/*                                                                           */
/* Description                                                               */
/* -----------                                                               */
/*                                                                           */
/* The main.c contains the implementation of function for the part of        */
/* the homework III, which is used for checking entered number if an odd	 */
/* number, a factorial number or a narcissistic number. 					 */
/*                                                                           */
/* ------------------------------------------------------------------------  */
/*                                                                           */
/* Notes		                                                             */
/* -----	                              	                                 */
/*                                                                           */
/* İf character input is 'y', loop continues; if it is 'n', the loop is over.*/
/* Until the 'n' input is entered, entered number is asked for checking.     */
/*                                                                           */
/* Inputs: number for checking and option for exit or continue			     */
/* Output: type of the entered number 							             */
/* ------------------------------------------------------------------------  */ 
/*                                                                           */ 
/*                              Includes                                     */
/*                              --------                                     */
#include <stdio.h>								/* printf, scanf definitions */

void oddNum(int num);
					  /* function to find if entered number is an odd number */
void factNum(int num);
				 /* function to find if entered number is a factorial number */
void narcNum(int num);
			  /* function to find if entered number is a narcissistic number */

int main()
{
	int option;					  /* to use for selecting property of number */
	int number;						/* variable entered number for checking  */
	char continuity;					 /* character for continuity of loop */

															/* entry of loop */
	printf("***************************************************** \n");
	printf("*                     WELCOME!                      * \n");
	printf("*   This program checks whether the given number    * \n");
	printf("*  is an odd, a factorial or a narcissistic number  * \n");
	printf("*                                                   * \n");
	printf("***************************************************** \n");

	continuity = 'y';	   	   /* to start loop, continuity variable's value */

	while( (continuity == 'y') && (continuity != 'Y') ){
				  /* as long as character value's is 'y', loop will continue */

			printf("\nPlease enter a positive integer : "); /* taking number */
			scanf("%d", &number);

			if(number > 0) {			 /* To take positive number, control */

				printf("Which property would you like to check? \n");
				printf("1) Odd number \n");
				printf("2) Factorial number \n");
				printf("3) Narcissistic number \n");

				printf("Please enter(1/2/3): "); /* taking option for switch */
				scanf("%d", &option);

				if( (option >= 1) && (option <= 3) ){ /* option(between 1-3) */
					switch(option) {			 /* taking option for switch */
						case 1:					 /* 1 to check if odd number */
							oddNum(number);
							break;
						case 2:			    /* 2 to check if fctorial number */
							factNum(number);
							break;
						case 3:			/* 3 to check if narcissistic number */
							narcNum(number);
							break;
						}
					}
				}
			else if(number <= 0)	 /* if taken number is negative, warning */
				printf("The number you entered is not positive.\n");

				printf("Do you want to continue (y/n)? ");	/*continue control*/
				scanf(" %c", &continuity);
		}

							  /* if character value's is 'n', loop will over */
	if( (continuity == 'n') && (continuity != 'N') )
		printf("Good bye !\n");

	return 0;
}

/* ------------------------------------------------------------------------  */ 

void oddNum(int num){
	/* if entered num divides 2 and remainder is 1, the number is odd number */
	if( (num % 2) == 1)					  /* control if odd number and print */
		printf("%d is an odd number ! \n", num);
	else								    /* else not odd number and print */
		printf("%d is not an odd number ! \n", num);

}

/* ------------------------------------------------------------------------  */ 

void factNum(int num){
	int  upsizing, numReceiver;
				  /* define growing number for factorial and factorial value */

	numReceiver = 1;				  /* Factorial number rule: begin with 1 */
	upsizing = 1;			 /* growing number for factorial (begins with 1) */

	while(num > numReceiver){
/* Until factorial number is equal to entered number, upsizing value and	 */
/* receiver multiplies and upsizing is increased.							 */
			numReceiver = upsizing * numReceiver;
			upsizing = upsizing + 1;
		}

	if(num == numReceiver)
				  /* control if entered number is factorial number and print */
			printf("%d is a factorial number ! \n", num);
	else							  /* else not factorial number and print */
			printf("%d is not a factorial number ! \n", num);
}

/* ------------------------------------------------------------------------  */ 

void narcNum(int num){
/* Narcissistic fonksiyonu 9 basamaklıdan sonrasını bulabiliyor */
	int decDigit, decimalDigit, digit, total, basDegeri, 
counter, kuvvet, sayici;
/* definition of  */

/*							FINDING DIGIT NUMBER							 */


	digit = 1;										   /* units digit number */
	decDigit = 10;					  /* variable (*10) to find digit number */

	while((num % decDigit) != num){
/* as long as remainder from decimal system is not equal number, digit number is counted */
			decDigit = decDigit * 10;
			digit = digit + 1;
		}

/*	FINDING DIGIT VALUES & CALCULATE POWER DUE TO DIGIT NUMBER AND MULTIPLY	 */

	counter = 0;									 /* counter to calculate */
	decimalDigit = 10;							/* digit to calculate values */
	total = 0;							   /* to compare, total digit values */

	while( counter < digit ){
				  /* loop will continue until counter is out of digit number */

			basDegeri = num % decimalDigit;					  /* digit value */

/* If values of digit is over 10 (for digit value), mathematical operation	 */
/* will  occur. 															 */

			if(basDegeri > 10)
				basDegeri = basDegeri / (decimalDigit/10) ;
			else if( (counter >= 1) && (basDegeri < 10 ))
/* over ten digits, if value is 0, mathematical operation will occur. */
				basDegeri = 0;

			/*		POWER THE DIGIT VALUE DUE TO DIGIT NUMBER 				 */
				kuvvet = 1;									  /* power value */
				sayici= 0;											/* power */

				while(sayici != digit){
					kuvvet *= basDegeri;
					sayici = ++sayici;
					}

					total += kuvvet;	  /* finding (multiply) digit values */

					decDigit *=  10;
					sayici = ++sayici;

			counter = ++counter;			/* to calculate all digit values */
			decimalDigit *= 10 ;			 /* enchanging the decimal digit */
		}

	if (total == num)
			   /* control if entered number is narcissistic number and print */
		printf("%d is a narcissistic number !\n", total);
	else						   /* else not narcissistic number and print */
		printf("%d is not a narcissistic number !\n", total);
}
