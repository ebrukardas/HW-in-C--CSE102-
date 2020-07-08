/*-------------------------------------------------------------------------- */
/*                                                                           */
/*                   	 HW10_141044049_Ebru_Kardas      	                 */
/*                                                                           */
/* main.c                                                                    */
/* ------                                                            	     */
/* Created on 6/5/2016 by Ebru Kardas                                        */
/*                                                                           */
/* Description                                                               */
/* -----------                                                               */
/* The main.c contains  reading information from binary file and 
	write to a file.				     		              		         */
/* Inputs: a binary file												     */
/* Output: a .txt file                                                       */
/*                                                                           */
/* ------------------------------------------------------------------------  */
/* If any error occurs, return -1.											 */
/* ------------------------------------------------------------------------  */ 
/*                                                                           */ 
#include <stdio.h>
#include <string.h>
#define SIZE 25									  /* Wanted lenght of strings*/
#define SIZE_SYS 20								  /* Wanted lenght of system */

struct student_s{					         /* structure for student's info */
	int id;					       							/*  student's id */
	char name[SIZE];					    			  /*  student's name */
	char surname[SIZE];					       		   /*  student's surname */
};

struct lecturer_s{					        /* structure for lecturer's info */
	char degree[SIZE];				  			 	   /*  lecturer's degree */
	int id;			  								       /*  lecturer's id */
	char name[SIZE];			  						 /*  lecturer's name */
	char surname[SIZE];			  					  /*  lecturer's surname */
};

struct lecture_s{				    	    /* structure for lectures's info */
	int code;				  							  /*  lecture's code */
	char name[SIZE];				  			 		  /*  lecture's name */
	int id;				  								    /*  lecture's id */
};

struct schedule_s{					        /* structure for schedule's info */
	char className[SIZE];		   /* classroom name which the lecture is in */
	char day[SIZE];							  /* day which the lecture is on */
	int startTime;					  		 /* time which the lecture is at */
	int durTime;					  		/* how long is the lecture takes */
	int code;					  			  			  /*  lecture's code */
};

struct courseTaken_s{        /* structure for courses taken by students info */
	int id;
	int code;	
};


int main(){

	FILE *binp, *ptr;  /* pointer to open input(binary) and output(txt) files */

	/* SYSTEM ARRAYS (MADE OF STRUCTS) */
	struct student_s student[SIZE_SYS];
	struct lecturer_s lecturer[SIZE_SYS];
	struct lecture_s lecture[SIZE_SYS];
	struct schedule_s schedule[SIZE_SYS];
	struct courseTaken_s courseTaken[SIZE_SYS];

	int i;

	binp = fopen("input.dat","rb");				 /* open binary file to read */
	ptr = fopen("output.txt", "w+");		/* open/create .txt file to write*/

	if(!binp){							   /* if input file cannot be opened */
		printf("Input file cannot be opened!\n");
		return -1;
	}
	if(!ptr){						 	   /* if input file cannot be opened */
		printf("Output file cannot be opened!\n");
		return -1;
	}
	
	for(i=0; i<SIZE_SYS; i++){
		fread( &student[i], sizeof(student), 1, binp );

		fread( &lecturer[i], sizeof(lecturer), 1, binp );

		fread( &lecture[i], sizeof(lecture), 1, binp );

		fread( &schedule[i], sizeof(schedule), 1, binp ) ;

		fread( &courseTaken[i], sizeof(courseTaken), 1, binp );
	}

	for(i=0; i<SIZE_SYS; i++){
		fprintf( ptr, "%d %s %s", student[i].id, 
								  student[i].name, 
								  student[i].surname );

		fprintf( ptr, "%s %d %s %s", lecturer[i].degree, 
									 lecturer[i].id, 
									 lecturer[i].name, 
									 lecturer[i].surname );

		fprintf( ptr, "%s %s %d %d %d", schedule[i].className, 
										schedule[i].day, 
										schedule[i].startTime,
										schedule[i].durTime, 
										schedule[i].code );

		fprintf( ptr, "%d %d", courseTaken[i].id, 
							   courseTaken[i].code );


	}

	fclose(binp);
	fclose(ptr);

	return 0;

}