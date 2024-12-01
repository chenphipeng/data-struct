#include <stdio.h>
#include <stdlib.h>

#define MAXQSIZE	1024

enum status{
	False,
	True
};

struct Queue{
	int *parr;
	int front;
	int rear;
};

static void Queue_Init(struct Queue *Q)
{
	Q->parr = malloc(MAXQSIZE*sizeof(int));
	if(Q->parr)
	{
		perror("malloc()");
		exit(1);
	}
	Q->front = 0;
	Q->rear = Q->front;
}

static int Queue_Len(struct Queue *Q)
{
	return (Q->rear-Q->front+MAXQSIZE)%MAXQSIZE;
}

static int Queue_En(struct Queue *Q, int element)
{
	if((Q->rear+1)%MAXQSIZE == Q->front)
	{
		return False;
	}
	(Q->parr)[Q->rear] = element;
	Q->rear = (Q->rear+1)%MAXQSIZE;
	return True;
}

static int Queue_De(struct Queue *Q, int *temp)
{
	if(Q->front == Q->rear)
	{
		return False;
	}
	*temp = (Q->parr)[Q->front];
	Q->front = (Q->front+1)%MAXQSIZE;
	return True;
}

static int Queue_GH(struct Queue *Q)
{
	if(Q->front!=Q->rear)
	{
		return (Q->parr)[Q->front];
	}
	return False;
}

static void Queue_Destroy(struct Queue *Q)
{
	if(Q->parr)
	{
		free(Q->parr);
	}
	Q->rear = Q->front = 0;
}

int main()
{
	struct Queue Q;
	int element=45, temp;

	Queue_Init(&Q);	// 队列初始化
	Queue_Len(&Q);	// 队列长度
	Queue_En(&Q, element);	// 入队
	Queue_De(&Q, &temp);	// 出队
	Queue_GH(&Q);	// 取队头元素
	Queue_Destroy(&Q);	// 销毁队列

	exit(0);
}