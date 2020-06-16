#include <stdio.h>
#include<stdlib.h>
#include <time.h>
#include <ctype.h>

/* declaration */
typedef struct list { int data; struct list* next; } list;
/* declare functions to be used */
int is_empty(const list *l);
list * create_list(int d);
list * add_to_front(int d, list* h);
list* array_to_list(int d[], int size);
void print_list( list *h , char *title);
void swap(list *a, list *b);
void sort_list(list *h);

int main() {

list* head = NULL;

int i;
int arr_r[100];

srand(time(NULL));
for(i = 0; i < 100; i++)
	arr_r[i] = rand()%200;

head = array_to_list(arr_r, 100);

print_list(head, "arr_r[100] made into 100 element list");
printf("\n\n");
sort_list(head);
print_list(head, "Sorted listof 100 elements");

return EXIT_SUCCESS;
}
/* define the declared  functions */
int is_empty(const list *l) { return (l==NULL); }

list * create_list(int d)
{	// allocate memory for list
	list* head  = malloc(sizeof(list));
	head->data = d; // add data element to list
	head->next = NULL; // next linked list not yet created
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
	int count = 0;
	printf("%s\n", title);
	while(h != NULL) {
		// ensure list display in 5 rows
		if(!(count%21))
			printf("\n");
		printf("%4d", h->data);
                if(h->next) {
			printf(":\t");
		} else { printf("\n");}
		h= h->next;
		count++;
	}
}

void swap(list *a, list *b)
{
	int temp = a->data;
	a->data = b->data;
	b->data = temp;
}

void sort_list(list *h){
	int s;
	list *begin;
	list *another = NULL;
	if(is_empty(h))
		return;
	do
	{
		s = 0;
		begin = h;
		while(begin->next != another)
		{
			if( begin->data > begin->next->data)
			{
				swap(begin, begin->next);
					s = 1;
			}
			begin = begin->next;
		}
			another = begin;
		}while(s);
	}
