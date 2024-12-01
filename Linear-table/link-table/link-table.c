#include "link-table.h"

int main()
{
	struct Lnode *L;

	if(Init_L(&L))
	{
		printf("malloc faild!\n");
		exit(1);
	}

	exit(0);
}