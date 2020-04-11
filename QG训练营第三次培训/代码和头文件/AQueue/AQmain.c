#include "AQueue.h"
#include <stdio.h>

int main() {
	int choice, i;
	AQueue Q;
	int t;
	void* e=NULL;
	char c;

	printf("\n\t********************MENU********************\n");
	printf("\t\t1--Initialize AQueue\n");
	printf("\t\t2--Destroy\n");
	printf("\t\t3--Clear\n");
	printf("\t\t4--EnAQueue\n");
	printf("\t\t5--DeAQueue\n");
	printf("\t\t6--IsEmptyAQueue\n");
	printf("\t\t7--IsFullAQueue\n");
	printf("\t\t8--TravelAQueue\n");
	printf("\t\t9--GetHead\n");
	printf("\t\t10--GetAQueueLength\n");
	printf("\t\t11--Edit\n");
	printf("\t********************************************\n");

loop:

	printf("\nYour choice:");
	scanf("%d", &choice);

	switch (choice) {
	case 1:

		InitAQueue(&Q);
		printf("success\n");
		break;

	case 2:

		DestoryAQueue(&Q);
		printf("success\n");
		break;


	case 3:

		ClearAQueue(&Q);
		printf("success\n");
		break;


	case 4:

		printf("which type do you want to enter?\n");
		printf("1. int 2. char 3. double(Two decimal places)\n");
		printf("your choice:");
		scanf("%d", &t);
		while (t < 1 || t>3)
		{
			printf("data error\n");
			printf("your choice:");
			scanf("%d", &t);
		}
		printf("enter data:");

		switch (t)
		{
		case 1: {

			int a;
			scanf("%d", &a);	
			datatype[Q.rear] = 'i';
			if (EnAQueue(&Q, &a)) {				
				printf("success\n");
			}
			else {
				printf("failed\n");
			}
			break;

		}

		case 2: {
		
			getchar();			
			c = getchar();
			datatype[Q.rear] = 'c';
			if (EnAQueue(&Q, &c) ){			
				printf("success\n");
			}
			else {
				printf("failed\n");
			}
			break;

		}

		case 3: {

			double d;
			printf("enter (eg:3.89):");
			scanf("%f", &d);			
			datatype[Q.rear] = 'd';
			if (EnAQueue(&Q, &d)) {
			
				printf("success\n");
			}
			else {
				printf("failed\n");
			}
			break;

		}

		default:printf("data error!\n");
		
		}
	
		break;


	case 5:

		if (DeAQueue(&Q)) {
			printf("success\n");
		}
		else {
			printf("failed\n");
		}
		break;

	case 6:
		
		if (IsEmptyAQueue(&Q)) {
			printf("It's empty\n");
		}
		
		break;

	case 7:

		if (IsEmptyAQueue(&Q)) {
			printf("It's full\n");
		}	
		break;

	case 8:

		TraverseAQueue(&Q, APrint);
		break;

	case 9:
		
		type = datatype[Q.front];
		APrint(Q.data[Q.front]);
				
		break;


	case 10:
		
		printf("Now the AQueue's length is -> %d", LengthAQueue(&Q));		
		break;

	case 11:

		return 0;

	default:printf("data error!\n");
	}

	do {
		printf("\ncontinue to use the menu or stop(enter 1 or 0):");
		scanf("%d", &i);
		if (i == 1) goto loop;
		if (i != 1 && i != 0) printf("data error!");
	} while (i != 1 && i != 0);
	
	return 0;
}


