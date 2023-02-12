#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Birthday{
	char name[30];
	char DOB[10];
	char email[30];
}birthday, *BirthdayList;

void Accept(BirthdayList);
void Display(BirthdayList,int);
void Edit(BirthdayList,int);
void SearchByName(BirthdayList,int);

int main(){
	int no=0, i=0;
	BirthdayList b=NULL;
	printf("Enter number of persons you want to enter birthday information:\n");
	scanf("%d",&no);
	b=(BirthdayList)malloc(no*sizeof(birthday));
//	printf("size of b %d\n",sizeof(birthday));
	for(i=0;i<no;i++){
		Accept(&b[i]);
	}
	printf("\n1.Add more enteries in birthday list\n2.Edit birthday list\n3.Display birthday list\n4.Search Birthday by name\n5.Exit\n");
	int ch=0;
	while(ch!=4){
		printf("\nEnter choice number from above:\n");
		scanf("%d",&ch);
	switch(ch){
		case 1:
			Accept(&b[no]);
			no=no+1;
			printf("Added successfully!!");
			break;
		case 2:
			Edit(b,no);
			break;
		case 3:
			Display(b,no);
			break;
		case 4:
			SearchByName(b,no);
			break;
		case 5:
			printf("Exited successfully!!");
			break;	
		default:
			printf("Enter valid choice!!\n");
			break;	
	}
	}
	return 0;
}

void Accept(BirthdayList b){
	printf("Enter name:");
	scanf("%s", b->name);
	printf("Enter DOB:");
	scanf("%s", b->DOB);
	printf("Enter email:");
	scanf("%s", b->email);
	printf("\n");	
}

void Display(BirthdayList b, int no){
	int i=0;
	for(i=0;i<no;i++){
		printf("Information of Bithday: %d\n", i+1);
		printf("Name: %s\n", b[i].name);
		printf("DOB: %s\n", b[i].DOB);
		printf("email: %s\n", b[i].email);
		
	}
}

void Edit(BirthdayList b, int no){
	char Change[30];
	printf("Enter name of person you want to edit birthday information:\n");
	scanf("%s",Change);
	int i=0,j=0;
	for(i=0;i<no;i++){
		if(b[i].name!=Change){
			
			for(j=0;j<3;j++){
				char ChangeDOB[10];
				printf("Enter DOB to edit:\n");
				scanf("%s", ChangeDOB);
				char Changeemail[30];
				strcpy(b[1].DOB, ChangeDOB);
				printf("Edited!\n");
				break;
			}
		}
		else{
			printf("Enter the name of person among you saved birthday information already\n");
		}
		break;
}
}

void SearchByName(BirthdayList b, int no){
	char SearchName[30];
	printf("Enter name to be search:\n");
	scanf("%s",SearchName);
	int i=1;
	while(i<=no){
		if(b[i].name!=SearchName){
		printf("Information of Bithday: %d\n", i+1);
		printf("DOB: %s\t\t", b[i].DOB);
		//printf("email: %s\t\t", b[i].email);
		printf("\n");
		break;
		}
		else{
			i++;
			printf("Information not available!!\n");
		}
	
	}
}

