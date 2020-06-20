#include<stdio.h>

// declaring functions to be used
void write_data(FILE *ptr, int d[], int size);
void read_data(FILE *ptr, int d[], int *size);
double average(int d[], int size);
int get_maxNum(int d[], int size);
void print_data(int d[], int size);
int get_size(FILE *ptr);

// driver 
int main(int argc, char * argv[])
{
	int i;
	int size;

	FILE *ifp, *ofp;
//	ifp = fopen("text", "r");
	ifp = fopen(argv[1], "r");
	ofp = fopen("answer-hw3", "w+");


	size = get_size(ifp);

	int data[size];

	read_data(ifp, data, &size);

	print_data(data, size);

	write_data(ofp, data, size);

	fclose(ifp);
	fclose(ofp);
	return 0;
}

// defining the declared functions
int get_size(FILE *ptr) {
	int size;
	if(fscanf(ptr, "%d", &size) != 1)
		size = 0;
	return size;
}

void read_data(FILE *ptr, int d[], int *size) {
	for(int i =0; i < *size; i++)
		if(fscanf(ptr, "%d", &d[i]) != 1)
			d[i] = 0;
}

double average(int d[], int size) {
	int i;
	double avg = 0.0;
	for(i = 0; i < size; i++)
		avg += d[i];
	return (avg/size);
}

int get_maxNum(int d[], int size) {
	int max = d[0];
	for(int i = 1; i < size; i++) {
		if( d[i] > max)
			max = d[i];
	}
	return max;
}

void print_data(int d[], int size)
{
	int i;
	printf("Size of the array is %d\n", size);
	for (i = 0 ; i < size; i++)
                printf("%d\t", d[i]);
	printf("\nMaximum Number is %d\nThe average is %.2f", get_maxNum(d, size), average(d, size));
}

void write_data(FILE *ptr, int d[], int size) {
	fprintf(ptr, "size = %d\n", size);
	for (int i = 0 ; i < size; i++)
		fprintf(ptr, "%d\t", d[i]);
	fprintf(ptr, "\nMaximum Number is %d", get_maxNum(d, size));
	fprintf(ptr,"\nThe average is %.2f", average(d, size));
}

