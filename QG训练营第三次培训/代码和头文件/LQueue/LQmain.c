#include "LQueue.h"
#include <stdio.h>

int main() {
	int choice, i;
	LQueue Q;
	int t;
	void* e = NULL;
	char c;

	printf("\n\t********************MENU********************\n");
	printf("\t\t1--Initialize LQueue\n");
	printf("\t\t2--Destroy\n");
	printf("\t\t3--Clear\n");
	printf("\t\t4--EnLQueue\n");
	printf("\t\t5--DeLQueue\n");
	printf("\t\t6--IsEmptyLQueue\n");
	printf("\t\t7--GetLQueueLength\n");
	printf("\t\t8--TravelLQueue\n");
	printf("\t\t9--GetHead\n");
	printf("\t\t10--Edit\n");
	printf("\t********************************************\n");

loop:

	printf("\nYour choice:");
	scanf("%d", &choice);

	switch (choice) {
	case 1:

		InitLQueue(&Q);
		printf("success\n");
		break;

	case 2:

		DestoryLQueue(&Q);
		printf("success\n");
		break;


	case 3:

		ClearLQueue(&Q);
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
			datatype = 'i';
			if (EnLQueue(&Q, &a)) {
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
			datatype = 'c';
			if (EnLQueue(&Q, &c)) {
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
			datatype = 'd';
			if (EnLQueue(&Q, &d)) {

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

		if (DeLQueue(&Q)) {
			printf("success\n");
		}
		else {
			printf("failed\n");
		}
		break;

	case 6:

		if (IsEmptyLQueue(&Q)) {
			printf("It's empty\n");
		}

		break;

	case 7:

		printf("Now the AQueue's length is -> %d", LengthLQueue(&Q));
		break;
		
	case 8:

		TraverseLQueue(&Q, LPrint);
		break;

	case 9:		
		
		datatype = Q.front->next->type;
		LPrint(Q.front->next->data);

		break;


	case 10:

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


