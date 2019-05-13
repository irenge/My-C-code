#include<stdio.h>

struct student
{
int id;
char name[30];
float percentage;
};

int main(){

int num,i;

printf("\nEnter how many students? ");
scanf("%d",&num);

struct student record[num];

for(i=1;i<=num;i++){

printf("\nEnter Id number :");
scanf("%d",&record[i].id);

printf("\nEnter Name of the student %d : ",i);
scanf("%s",&record[i].name);

printf("\nEnter percentage :");
scanf("%f",&record[i].percentage);
}

printf("\n");

for(i=1;i<=num;i++)
{
printf("Id %d : %d\n",i,record[i].id);
printf("Name %d : %s \n",i,record[i].name);
printf("Percentage of student %d : %.1f\n",i,record[i].percentage);
}
return 0;
}

