/*
 * Author : Jules Octave
 *
 * exercise 
 * ========
 * Write enumerated types that supports dates—such as december 12.
 * Then add a function that produces a next day.
 * So nextday(date) of december 12 is december 13.
 * Also write a function printdate(date) that prints a date legibly.
 * The function can assume that February has 28 days and it most know how many days are in each month.
 * Use a struct with two members;
 * one is the month and the second  is the day of the month—an int (or short).
 *
 */

#include <stdio.h>

// enumerator for months of the year
typedef enum month{ jan, feb, mar, apr, may, jun, jul, aug, sept, oct, nov, dec}  month;

// Struct with two members m and d
typedef struct date{ month m; int d;} date;

// function to print the next day
void nextday( date *s) {
	if( s->m == dec && s->d==31) {
		s->d = 1;
		s->m = jan;
	} else if( (s->m == feb && s->d == 28) || ((s->m == apr || s->m == jun || s->m==sept || s->m == nov) && s->d==30) || ( s->d == 31)) {
		s->d = 1;
		++(s->m);
	} else {
		s->d += 1;

	}
}
// convert enumerator object into readable months name
const char * const months[] = {
	[jan] = "January",
	[feb] = "February",
	[mar] = "March",
	[apr] = "April",
	[jun] = "June",
	[jul] = "July",
	[aug] = "August",
	[sept] = "September",
	[oct] = "October",
	[nov] = "November",
	[dec] = "December"
};

// print the day and month 
void printdate (date *s, const char * const str) {
	printf("\n%s %d", str, s->d);
}

int main() {
	date d;
// February 28
	d.d = 28;
	d.m = feb ;
	printdate(&d, months[d.m]);
	nextday(&d);
	printdate(&d, months[d.m]);
	printf("\n========================\n");
// March 14
        d.d = 14;
	d.m = mar;
	printdate(&d, months[d.m]);
	nextday(&d);
        printdate(&d, months[d.m]);
	printf("\n========================\n");

// October 31
	d.d = 31;
	d.m = oct;
	printdate(&d, months[d.m]);
	nextday(&d);
        printdate(&d, months[d.m]);
	printf("\n========================\n");

// December 31
	d.d = 31;
	d.m = dec;
	printdate(&d, months[d.m]);
	nextday(&d);
        printdate(&d, months[d.m]);
	printf("\n========================\n");


	return 0;
}
