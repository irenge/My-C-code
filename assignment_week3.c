#include <stdio.h>
#include<stdlib.h>
#include <time.h>
#include <ctype.h>

typedef struct list { int data; struct list* next; } list;

int is_empty(const list *l) { return (l==NULL); }

list * create_list(int d)
{
	list* head  = malloc(sizeof(list));
	head->data = d;
	head->next = NULL;
	return head;
}

list * add_to_front(int d, list* h)
{
	list * head = create_list(d);
	head->next = h;
	return head;
}

list* array_to_list(int d[], int size)
{
	list* head =  create_list(d[0]);
	int i;
	for (i = 1; i < size; i++)
	{
		head = add_to_front(d[i], head);
	}
	return head;
}

void print_list( list *h , char *title)
{
	int count =0;
	printf("%s\n", title);
	while(h != NULL) {
		++count;
		if(!(count%21)) 
			printf("\n");
		printf("%d: ", h->data);
		h= h->next;
	}
}


void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
/*
void print_array(int how_many, int data[], char *str)
{
	int i;
	printf("%s", str);

	for (i = 0; i < how_many; i++)
		printf("%d\t", data[i]);
}
*/
void bubble (int data[], int how_many)
{
	int i, j;

	for( i = 0; i < how_many; i++) {
		//print_array(how_many, data, "\ninside bubble\n");
		for(j = how_many - 1; j > i; j--)
			if(data[j-1] > data[j])
				swap(&data[j-1], &data[j]);
	}
}



int main() {

list* head = NULL;

int i;
int arr_r[100];

srand(time(NULL));
for(i = 0; i < 100; i++)
	arr_r[i] = rand()%200;
bubble(arr_r, 100);

head = array_to_list(arr_r, 100);

print_list(head, "arr_r[100] made into 100 element list");
printf("\n\n");
/*
for(i = 0; i < 100; i++) {
	if(!(i%11))
		printf("\n");
	printf("%d\t", arr_r[i]);
}
*/





return EXIT_SUCCESS;
}
