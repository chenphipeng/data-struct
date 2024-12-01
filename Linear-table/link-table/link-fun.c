#include "link-table.h"

int Init_L(struct Lnode **L)
{
	*L = malloc(sizeof(struct Lnode));
	if(*L == NULL)
	{
		return FAIL;
	}
	(*L)->next = NULL;
	return SUCCESS;
}

int Empty_L(struct Lnode **L)
{
	if((*L)->next == NULL)
	{
		return IS_EMPTY;
	}
	return NO_EMPTY;
}

void Destory_L(struct Lnode **L)
{
	struct Lnode *p;
	while(*L!=NULL)
	{
		p = *L;
		*L = (*L)->next;
		free(p);
	}
	return;
}

void Clear_L(struct Lnode **L)
{
	struct Lnode *p, *q;
	p = (*L)->next;
	while(p!=NULL)
	{
		q = p->next;
		free(p);
		p = q;
	}
	(*L)->next = NULL;
	return;
}

int Len_L(struct Lnode **L)
{
	struct Lnode *p;
	int i = 0;
	p = (*L)->next;
	while(p)
	{
		i++;
		p = p->next;
	}
	return i;
}

int Getelem_L(struct Lnode **L, int pos, struct data elem)
{
	struct Lnode *p = (*L)->next;
	int count = 1;
	while(count<pos && p!=NULL)
	{
		p = p->next;
		count++;
	}
	if(!p || count>pos)
	{
		return POS_ERR;
	}
	elem = p->elem;
	return SUCCESS;
}

/* 	结构体比较 
	memcpy()有缺陷，理由：当结构体存在内存对齐时会填充字节，填充的字节中的值未知
	因此采用结构体逐个成员比较的方法
*/
int cmp_struct(struct data *ps1, struct data *ps2)
{
	if(strcmp(ps1->name, ps2->name) || strcmp(ps1->id, ps2->id) || ps1->score!=ps2->score)
	{
		return NO_EQUAL;
	}
	return EQUAL;
}

int Locateelem_L(struct Lnode **L, struct data elem)
{
	struct Lnode *p = (*L)->next;
	int count = 1;
	while(p!=NULL && cmp_struct(&(p->elem), &elem)==NO_EQUAL)
	{
		p = p->next;
		count++;
	}
	if(!p)
	{
		return NO_VALUE;
	}
	return count;
}

int Listinsert_L(struct Lnode **L, int pos, struct data elem)
{
	struct Lnode *p, *e;
	p = (*L);
	e = malloc(sizeof(struct Lnode));
	e->elem = elem;
	int site = 0;
	while(p!=NULL && site<pos-1)
	{
		p = p->next;
		site++;
	}
	if(!p || site>=pos)
	{
		return POS_ERR;
	}
	e->next = p->next;
	p->next = e;
	return SUCCESS;
}

int Listdel_L(struct Lnode **L, int pos)
{
	struct Lnode *p, *sd;
	p = (*L);
	int site = 0;
	while(p->next!=NULL && site<pos-1)
	{
		p = p->next;
		site++;
	}
	if(!(p->next) || site>=pos)
	{
		return POS_ERR;
	}
	sd = p->next;
	p->next = sd->next;
	free(sd);
	return SUCCESS;
}

void Create_L(struct Lnode **L, int elem_n)
{
	struct Lnode *p;
	for(; elem_n>0; elem_n--)
	{
		p = malloc(sizeof(struct Lnode));
		printf("please enter name: ");
		scanf("%s", (p->elem).name);
		printf("please enter id: ");
		scanf("%s", (p->elem).id);
		printf("please enter score: ");
		scanf("%d", &(p->elem).score);
		p->next = (*L)->next;
		(*L)->next = p;
	}
	return;
}

void TCreate_L(struct Lnode **L, int elem_n)
{
	struct Lnode *t, *p;
	t = (*L);
	for(int i=0; i<elem_n; i++)
	{
		p = malloc(sizeof(struct Lnode));
		printf("please enter name: ");
		scanf("%s", (p->elem).name);
		printf("please enter id: ");
		scanf("%s", (p->elem).id);
		printf("please enter score: ");
		scanf("%d", &(p->elem).score);
		p->next = NULL;
		t->next = p;
		t = p;
	}
}