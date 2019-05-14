#include<stdio.h>
main()
{
	int c,nt;
	nt = 0;
	//printf("%d",EOF);
	while((c = getchar()) != EOF){
		if (c == ' '){
		while((c = getchar()) == ' ');
		putchar(' ');
		}
		putchar(c);
	}
	//printf("Blank %d\n", nt);
}

