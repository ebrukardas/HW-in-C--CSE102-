/*-------------------------------------------------------------------------- */ 

/*                    HW01_Part2_141044049_Ebru_Kardas                       */ 

/*                                                                           */ 

/*                                main.c                                     */

/* ------------------------------------------------------------------------  */ 

/*                                                                           */ 

/*                   Created on 18/2/2016 by Ebru Kardas                     */

/*                                                                           */ 

/*                             Description                                   */

/* ------------------------------------------------------------------------  */ 

/* I have defined days in a year on Earth (365) as DAYS_YEAR_EARTH and 		 */
/* days in a month on Earth (30) as DAYS_MONTH_EARTH to use in "livedDays" 	 */
/* formule which calculates days a person lived.							 */

/* Inputs: current date and birthdate, time information about another planet */
/* Outputs: lived days and would be lived on the other planet 				 */

/*                               Notes                                       */

/* ------------------------------------------------------------------------  */ 

/* 								Includes 									 */


#include <stdio.h>					/* printf, scanf definitions */

/* */

/*								 Defines 								   	 */

#define DAYS_YEAR_EARTH 365			/* days in a year on Earth (365) */
#define DAYS_MONTH_EARTH 30			/* days in a month on Earth (30) */
#define HOURS_DAY_EARTH 24			/* hours in a day on Earth (24) */


/*                             Description                                   */

/* ------------------------------------------------------------------------- */	

int main(void)			/* main function takes integer output, no argumans	 */
{
	int curYear, curMonth, curDay;		
	/*Current year, month day definition*/
	int birthYear, birthMonth, birthDay;	
	/*Birth year, month day definition*/
	int livedDays;
	/*Days a person lived formule*/

	int hoursInDay, daysInMonth, monthsInYear;
	/* Respectively, hours in a day, days in a month and months in a year */
	/* for another planet. */

	int totalHours;				/* total hours the person lived. */

	int hoursInYearPlt, hoursInMonthPlt, 
		/*
		lived hours in a year for other planet, 
		hours in a month for other planet
		*/

		yearOnPlt, monthOnPlt, dayOnPlt,
		/*  
		years would be lived on other planet, 
		months would be lived on other planet
		days would be lived on other planet 
		*/
	
		toFindMonth, toFindDay, remainHoursPlt;
		/*
		a variable to calculate months would be lived on other planet, 
		a variable to calculate days would be lived on other planet,
		remaining hours from years and months for other planet.
		*/
	




	printf("Please enter the current date.\n");

	printf("Year:");			/* print "Year: " for current year */
	scanf("%d", &curYear);		/* takes current year as double from user */

	printf("Month:");			/* print "Month: " for current month */
	scanf("%d", &curMonth);		/* takes current month as double from user */

	printf("Day:");			/* print "Day: " for current day */
	scanf("%d", &curDay);		/* takes current day as double from user */

	printf("Please enter your birthday.\n");

	printf("Year:");			/* print "Year: " for birth year */
	scanf("%d", &birthYear);	/* takes birth year as double from user */

	printf("Month:");			/* print "Month: " for birth month */
	scanf("%d", &birthMonth);	/* takes birth month as double from user */

	printf("Day:");			/* print "Day: " for birth day */
	scanf("%d", &birthDay);		/* takes birth day as double from user */

	livedDays = (curYear-birthYear) * DAYS_YEAR_EARTH + 
				(curMonth-birthMonth) * DAYS_MONTH_EARTH  + 
				curDay - birthDay ;
	/* Calculate a person lived how many days. */

	printf("You have lived %d days. \n", livedDays);




	printf("Please enter about the time of another planet\n");

	printf("How many hours is a day?");
	scanf("%d", &hoursInDay);		
	/* takes hours in a day on other planet as double from user */

	printf("How many days is a month?");
	scanf("%d", &daysInMonth);
	/* takes days in a month on other planet as double from user */

	printf("How many months is a year?");
	scanf("%d", &monthsInYear);
	/* takes months in a year on other planet as double from user */


	totalHours = livedDays * HOURS_DAY_EARTH;
	/* To find total hours, multiply livedDays and HOURS_DAY_EARTH */

	hoursInYearPlt = hoursInDay * daysInMonth * monthsInYear;
	/* The variable is 'how many hours in a year on the other planet' */

	yearOnPlt = totalHours / hoursInYearPlt;
	/* The variable is 'how many years would be lived on the other planet' */
	
	toFindMonth = totalHours % hoursInYearPlt;
	/* To find would be lived months on the other planet */

	hoursInMonthPlt = daysInMonth * hoursInDay;
	/* The variable is 'how many hours in a month on the other planet' */

	monthOnPlt = toFindMonth / hoursInMonthPlt;
	/* The variable is 'how many months would be lived on the other planet' */

	remainHoursPlt = yearOnPlt * hoursInYearPlt + monthOnPlt * hoursInMonthPlt;
	/* Remaining hours from years and months, to find days */

	toFindDay = totalHours % remainHoursPlt;
	/* To find would be lived days on the other planet */

	dayOnPlt = toFindDay / hoursInDay;
	/* The variable is 'how many days would be lived on the other planet' */

	printf("If you lived in a planet where a day is %d hours, ", hoursInDay);
	printf("a month is %d days and a year is %d ", daysInMonth, monthsInYear);
	printf("months: you were %d years, %d months", yearOnPlt,monthOnPlt);
	printf(" and %d days old", dayOnPlt);

	return (0);
}
