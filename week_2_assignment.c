/*
 * Write enumerated types that supports dates—such as december 12.
 * Then add a function that produces a next day.
 * So nextday(date) of december 12 is december 13.
 * Also write a function printdate(date) that prints a date legibly.
 * The function can assume that February has 28 days and it most know how many days are in each month.
 * Use a struct with two members;
 * one is the month and the second  is the day of the month—an int (or short).
 */

#include <stdio.h>

typedef enum month{ jan, feb, mar, apr, may, jun, jul, aug, sept, oct, nov, dec}  month;
typedef struct date{ month m; int d;} date;

void nextday( date *s) {
	if( s->m == feb && s->d == 28) {
		s->d = 1;
		//s->m += 1;
	} else if ( (s->m == apr || s->m == jun || s->m==sept || s->m == nov) && s->d==30) {
		s->d = 1;
		//s->m += 1;
	} else if ( s->d == 31) {
		s->d = 1;
	}
	s->m += 1;

}

//typedef const char (*int_function_t) (int);


const char * get_month_name(date *s) {
	switch(s->m) {
	case jan:
		return "January";
		break;
	case feb:
		return "February";
		break;
	case mar:
		return "March";
		break;
	case apr:
		return "April";
		break;
	case may:
		return "May";
		break;
	case jun:
		return "June";
		break;
	case jul:
		return "July";
		break;
	case aug:
		return "August";
		break;
	case sept:
		return "September";
		break;
	case oct:
		return "October";
		break;
	case nov:
		return "November";
		break;
	case dec:
		return "December";
		break;
	}
}
/*void printdate (date *s) {
	printf("\n%s %d", get_month_name(s), s->d);
}
*/
int main() {
	date d;
	d.d = 28;
	d.m = feb ;
//	printdate(&d);
	printf( "\nDate is %s %d", get_month_name(&d), d.d);
	nextday(&d);
	printf("\nNext date is %s %d \n", get_month_name(&d), d.d);
	return 0;
}
