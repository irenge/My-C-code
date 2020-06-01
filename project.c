/*
 * author : Jules Irenge 
 * program to calculate average from a list of numbers in a file
 *
 */
#include <stdio.h> /* library for printf, fscanf - display and read in */

int main(void)
{
        int size = 1000; /* declare and initialize size */
        FILE *point = fopen("elephant_seal_data.txt", "r"); /* declare and initialise file pointer */
	if (point==NULL) {
		// if the file is not downloaded , it will not run
		printf("\nPlease download the file and name it 'elephant_seal_data.txt'\nPlace it in the same diirectory as theis progrm\nthen run the program again"); 
        return 0;
    }
	unsigned long  a[size]; /* declare array to store the data on the file */
	       int i; /* declare index for array  a[] to allow looping through array a[] */
	long sum = 0;
        /*
	 * read in all the values from the file to the array
	 */
	for(i = 0; i < size; i++)
	{
		fscanf( point , "%lu," , &a[i]);
		sum +=  a[i]; /* calculate the sum */
	}
	//display the average
	printf("\nThe average weight of the northern elephant seal is %.3lf\n", sum/1000.0);
    return 0;
}
