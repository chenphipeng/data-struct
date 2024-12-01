#include "order-table.h"

int Init_L(struct Sqlit *pL)
{
	pL->pstu = malloc(STUTAB);
	if(pL->pstu == NULL)
	{
		return 1;
	}
	pL->length = 0;
	return 0;
}

void Destroy_L(struct Sqlit *pL)
{
	if(pL->pstu)
	{
		free(pL->pstu);
	}
}

void Clear_L(struct Sqlit *pL)
{
	pL->length = 0;
}

int Getlength(struct Sqlit *pL)
{
	return pL->length;
}

int Isempty(struct Sqlit *pL)
{
	if(pL->length == 0)
	{
		return 1;
	}
	return 0;
}

int Getelem(struct Sqlit *pL, const char *te_name, struct score *te_gra)
{
	for(int i=0; i<pL->length; i++)
	{
		if(strcmp((pL->pstu)[i].name, te_name) == 0)
		{
			*te_gra = *((pL->pstu)+i);
			return SUCCESS;
		}
	}
	return NO_FIND;
}

int Insert_L(struct Sqlit *pl, int pos, struct score *ps)
{
	if(pos<0 || pos>pl->length+1)
	{
		return POS_FAIL;
	}
	if(pl->length == STUTAB)
	{
		return MEM_OVER;
	}
	for(int j=pl->length-1; j>=pos-1; j--)
	{
		(pl->pstu)[j+1] = (pl->pstu)[j];
	}
	(pl->pstu)[pos-1] = *ps;
	pl->length++;
	return SUCCESS;
}

int Delete_L(struct Sqlit *pl, char *p_id)
{
	for(int i=0; i<pl->length; i++)
	{
		if(strcmp((pl->pstu)[i].id, p_id) == 0)
		{
			for(; i<pl->length-1; i++)
			{
				(pl->pstu)[i] = (pl->pstu)[i+1];
			}
			pl->length--;
			return SUCCESS;
		}
	}
	return NO_FIND;
}

int Modify_L(struct Sqlit *pl, char *p_id, struct score *pstu)
{
	for(int i=0; i<pl->length; i++)
	{
		if(strcmp((pl->pstu)[i].id, p_id) == 0)
		{
			(pl->pstu)[i] = *pstu;
			return SUCCESS;
		}
	}
	return NO_FIND;
}

void meau()
{
	printf("********1.查询		2.插入********\n");
	printf("********3.删除		4.修改********\n");
	printf("********5.退出		     ********\n");
}