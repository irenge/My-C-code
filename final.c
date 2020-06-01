/*
 * author : Jules Irenge 
 * program to calculate average from a list of numbers in a file
 *
 */
#include <stdio.h> /* library for printf, fscanf - display and read in */

int main(void)
{
  unsigned long  a[1200];
        int i; /* declare index for array  a[] to allow looping through array a[] */
        long sum = 0; /* declare and initialise the sum 
        /*
         * read in all the values from the file to the array
         */

        i = 0;

	FILE *fptr = fopen("elephant_seal_data.txt", "r"); /* declare and initialise file pointer */
	if (fptr==NULL) {
		// if the file is not downloaded , it will not run
		printf("\nPlease download the file and name it 'elephant_seal_data.txt'\nPlace it in the same diirectory as theis progrm\nthen run the program again"); 
        return 0;
    }
	while(fscanf(fptr, "%lu", &a[i])==1)
	{
		sum +=  a[i]; /* calculate the sum */
		++i;
	}
	//display the average
	printf("\nThe average weight of the northern elephant seal is %.3lf\n", sum/(double) i);
        fclose(fptr);
    return 0;
}
