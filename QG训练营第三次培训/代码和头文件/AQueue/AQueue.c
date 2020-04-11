#include "AQueue.h"
#include <stdlib.h>
#include <stdio.h>
#include<string.h>

void InitAQueue(AQueue* Q) {

	for (int i = 0; i < MAXQUEUE; i++) {
		Q->data[i] = (void*)malloc(21);
	}
	Q->front = 0;
	Q->rear = 0;
	Q->length = 0;

}

void DestoryAQueue(AQueue* Q) {

	if (Q->data[0]) {
		for (int i = 0; i < MAXQUEUE; i++) {
			free(Q->data[i]);
		}
	}

}

Status IsFullAQueue(const AQueue* Q) {

	return ((Q->rear + 1) % MAXQUEUE == Q->front ? TRUE : FALSE);

}

Status IsEmptyAQueue(const AQueue* Q) {

	return (Q->rear == Q->front ? TRUE : FALSE);

}

Status GetHeadAQueue(AQueue* Q, void* e) {

	if (Q->data[Q->front]) {
		
		memcpy(e, Q->data[Q->front], (size_t)sizeof(Q->data[Q->front]));
		printf("--> %d", *(int*)e);
		return TRUE;
	}

	return FALSE;
}

int LengthAQueue(AQueue* Q) {

	return (Q->rear - Q->front + MAXQUEUE) % MAXQUEUE;

}

Status EnAQueue(AQueue* Q, void* data) {

	if (!(IsFullAQueue(Q))) {	
		memcpy(Q->data[Q->rear], data, (size_t)sizeof(data));		
		Q->rear = (Q->rear + 1) % MAXQUEUE;
		Q->length++;
		return TRUE;
	}

	return FALSE;

}

Status DeAQueue(AQueue* Q) {

	if (!(IsEmptyAQueue(Q))) {
		Q->front = (Q->front + 1) % MAXQUEUE;
		Q->length--;
		return TRUE;
	}

	return FALSE;
}

void ClearAQueue(AQueue* Q) {

	if (!IsEmptyAQueue(Q)) {
		Q->front = Q->rear = 0;
	}

}

Status TraverseAQueue(const AQueue* Q, void (*foo)(void* q)) {

	if (!IsEmptyAQueue(Q)) {

		int i = Q->front;		

		while (i <= (MAXQUEUE - Q->front + Q->rear) % MAXQUEUE) {

			type = datatype[i];
			foo(Q->data[i]);
			i = (i + 1) % MAXQUEUE;

		}

		return TRUE;
	}

	return FALSE;
}

void APrint(void* q) {

	if (type == 'd')
		printf("--> %.2f", *(float*)q);

	if (type == 'c')
		printf("--> %c", *(char*)q);

	if (type == 'i')
		printf("--> %d ", *(int*)q);

	if (type == 's')
		printf("--> %s ", (char*)q);

}

