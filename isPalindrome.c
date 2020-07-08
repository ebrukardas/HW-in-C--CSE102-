/*-------------------------------------------------------------------------- */
/*                                                                           */
/*                    HW07_Part1_141044049_Ebru_Kardas                       */
/*                                                                           */
/*                                                                           */
/*                                                                           */
/* main.c                                                                    */
/* ------                                                            	     */
/* Created on 14/4/2016 by Ebru Kardas                                       */
/*                                                                           */
/*                                                                           */
/*                                                                           */
/* Description                                                               */
/* -----------                                                               */
/*                                                                           */
/* The main.c contains the implementation of function for the part of        */
/* the homework VII, which is used for finding polidrome in string.          */
/*		              		              		              		         */
/*                                                                           */
/* ------------------------------------------------------------------------  */
/*                                                                           */
/* Notes		                                                             */
/* -----	                              	                                 */
/*                                                                           */
/* Inputs: string															 */
/* Output: is string polidrome, 1 or not 0						             */
/*                                                                           */
/* ------------------------------------------------------------------------  */

/* ------------------------------------------------------------------------  */ 
/*                                                                           */ 
/*                              Includes                                     */
/*                              --------                                     */

#include <string.h>
#include <ctype.h>								  					// tolower

int isPalindrome(char* str);
char *cleaned(char* ptr);		// helper function that cleaned except letters

int isPalindrome(char* str){

	int size=0;

	cleaned(str);									// string has been cleaned
	size=strlen(str);

	if( str==NULL || str[0]=='\0'){
		return 1;
	}
	if(str[0]==str[size-1]){			// compare of first and last element
		str[size-1]='\0';							   // null to cut string
		return isPalindrome(&str[1]);	  				   // recursive call
	}
	return 0;
}

char* cleaned(char *ptr){
	// loop for delete characters except letters
	// if the letter is uppercase, convert lowercase in original string
	int i=0,j=0;
	for( ; ptr[j]!='\0'; j++){
		if( isalpha(ptr[j])!=0){
			ptr[i]=tolower(ptr[j]);
			i++;
		}
	}
	// end of the string
	ptr[i]='\0';

	return ptr;
}
