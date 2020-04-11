#include "LQueue.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define NULL 0
/**
  *  @name        : void InitLQueue(LQueue *Q)
  *    @description : 初始化队列
  *    @param         Q 队列指针Q
  *  @notice      : None
  */
void InitLQueue(LQueue* Q) {

	Node* p = (Node*)malloc(sizeof(Node));
	p->next = NULL;
	Q->front = p;
	Q->rear = p;
	Q->length = 0;

}

/**
 *  @name        : void DestoryLQueue(LQueue *Q)
 *    @description : 销毁队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void DestoryLQueue(LQueue* Q) {

	while (Q->front) {		
		Q->rear= Q->front;
		Q->front = Q->front->next;
		free(Q->rear);
	}
	Q->length = 0;

}

/**
 *  @name        : Status IsEmptyLQueue(const LQueue *Q)
 *    @description : 检查队列是否为空
 *    @param         Q 队列指针Q
 *    @return         : 空-TRUE; 未空-FALSE
 *  @notice      : None
 */
Status IsEmptyLQueue(const LQueue* Q) {

	return (Q->rear == Q->front ? TRUE : FALSE);

}

/**
 *  @name        : Status GetHeadLQueue(LQueue *Q, void *e)
 *    @description : 查看队头元素
 *    @param         Q e 队列指针Q,返回数据指针e
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否空
 */
Status GetHeadLQueue(LQueue* Q, void* e) {

	if (!IsEmptyLQueue(Q)) {
		memcpy(e, Q->front->next->data, (size_t)sizeof(Q->front->next->data));
		return TRUE;
	}
	return FALSE;

}

/**
 *  @name        : int LengthLQueue(LQueue *Q)
 *    @description : 确定队列长度
 *    @param         Q 队列指针Q
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : None
 */
int LengthLQueue(LQueue* Q) {

	return Q->length;

}

/**
 *  @name        : Status EnLQueue(LQueue *Q, void *data)
 *    @description : 入队操作
 *    @param         Q 队列指针Q,入队数据指针data
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否为空
 */
Status EnLQueue(LQueue* Q, void* data) {

	Node* p = (Node*)malloc(sizeof(Node));	
	if (!p)		return FALSE;	

	p->data = (void*)malloc(sizeof(data));	
	p->type = datatype;
	memcpy(p->data, data, (size_t)sizeof(data));	

	p->next = NULL;	
	Q->rear->next = p;	
	Q->rear = p;
	Q->length++;
	return TRUE;
	
}

/**
 *  @name        : Status DeLQueue(LQueue *Q)
 *    @description : 出队操作
 *    @param         Q 队列指针Q
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : None
 */
Status DeLQueue(LQueue* Q) {

	if (IsEmptyLQueue(Q))	return FALSE;

	Node* p = (Node*)malloc(sizeof(Node));	
	p = Q->front->next;	
	Q->front->next = p->next;	

	if (!Q->front->next) {
		Q->rear = Q->front;
	}
		
	free(p);
	Q->length--;
	return TRUE;
	
}

/**
 *  @name        : void ClearLQueue(AQueue *Q)
 *    @description : 清空队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void ClearLQueue(LQueue* Q) {

	if (!IsEmptyLQueue(Q)) {
		Node* p, * q;
		Q->rear = Q->front;
		p = Q->front->next;
		while (p) {
			q = p;
			p = p->next;
			free(q);
		}
		free(p);
	}
	
}

/**
 *  @name        : Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q))
 *    @description : 遍历函数操作
 *    @param         Q 队列指针Q，操作函数指针foo
 *    @return         : None
 *  @notice      : None
 */
Status TraverseLQueue(const LQueue* Q, void (*foo)(void* q)) {

	if (!IsEmptyLQueue(Q)) {

		Node* n = Q->front->next;
		while (n) {
			datatype = n->type;
			foo(n->data);
			n = n->next;
		}

		return TRUE;
	}

	return FALSE;
}

/**
 *  @name        : void LPrint(void *q)
 *    @description : 操作函数
 *    @param         q 指针q

 *  @notice      : None
 */
void LPrint(void* q) {

	if (datatype == 'd')
		printf("--> %.2f", *(float*)q);

	if (datatype == 'c')
		printf("--> %c", *(char*)q);

	if (datatype == 'i')
		printf("--> %d ", *(int*)q);

	if (datatype == 's')
		printf("--> %s ", (char*)q);
}

