#include<stdio.h>

struct Person {
	char *name;
	int age;
	int height;
	int weight;
};

void Person_print(struct Person who)
{
	printf("Name: %s\n", who.name);
	printf("\tAge: %d\n", who.age);
	printf("\tHeight: %d\n", who.height);
	printf("\tWeight: %d\n", who.weight);
}
int main(int argc, char *argv[]){
	
	struct Person joe; 
	joe.name="Joe Alex";
	joe.age=32;
	joe.height=64;
	joe.weight=140;

	struct Person frank ={.name="Frank Blank",.age=20,.height=72, .weight=180};

	printf("Joe is at memory location %p:\n", joe);
	Person_print(joe);
	printf("Frank is at memory location %p\n", frank);
	Person_print(frank);

	joe.age += 20;
	joe.height -= 2;
	joe.weight += 40;
	Person_print(joe);

	frank.age += 20;
	frank.weight += 20;
	Person_print(frank);

	return 0;
}


