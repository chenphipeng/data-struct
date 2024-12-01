#include <stdio.h>
#include <stdlib.h>

#define MAX	1024

enum status{
	False,
	True
};

// 顺序栈类型定义
struct Stack{
	int *top;
	int *base;
	int stacksize;
};

static void Init(struct Stack *S)
{
	S->stacksize = MAX;
	S->base = malloc(S->stacksize*sizeof(int));
	if(S->base == NULL)
	{
		perror("malloc()");
		exit(1);
	}
	S->top = S->base;
}

static int Stack_Empty(struct Stack *S)
{
	if (S->top == S->base)
	{
		return True;
	}
	return False;

}

static int Stack_Len(struct Stack *S)
{
	return S->top-S->base;
}

static int Stack_Clear(struct Stack *S)
{
	if(S->base)
	{
		S->top = S->base;
		return True;
	}
	return False;
}

static int Stack_Destroy(struct Stack *S)
{
	if(S->base)
	{
		free(S->base);
		S->stacksize = 0;
		S->base = NULL;
		S->top = S->base;
	}
	return True;
}

static int Stack_Push(struct Stack *S, int element)
{
	if(S->top-S->base == S->stacksize)
	{
		return False;
	}
	*(S->top) = element;
	S->top++;
	return True;
}

static int Stack_Pop(struct Stack *S, int *temp)
{
	if(S->top==S->base)
	{
		return False;
	}
	S->top--;
	*temp = *(S->top);
	return True;
}

int main()
{
	struct Stack S;
	int element=45, temp;

	Init(&S);	// 初始化栈
	Stack_Empty(&S);	// 判断栈是否为空
	Stack_Len(&S);	// 求栈的长度
	Stack_Clear(&S);	// 栈置空
	Stack_Destroy(&S);	// 销毁栈
	Stack_Push(&S, element);	// 入栈
	Stack_Pop(&S, &temp);	// 出栈

	exit(0);
}