#include <stdio.h>
typedef struct Student
{

	int sid;
	char name[100];
	char sex;
}St,*STU;

 int main()
 {
 	St student1;
 	student1.sid = 99;
 	STU parr = &student1;
 	//parr->name = {'d','d'};
 	printf("%s\n",parr->name);
 	printf("%d\n",parr->sid);
 	return 0;
 }
