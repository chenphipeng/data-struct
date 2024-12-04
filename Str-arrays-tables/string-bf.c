#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSIZE	1024

struct Sstring{
	char ch[MAXSIZE+1];
	int len;
};

static int index_BF(const struct Sstring *main_str, const struct Sstring *sub_str)
{
	int i=1, j=1;
	while(i<=(main_str->len)&&j<=(sub_str->len))
	{
		if((main_str->ch)[i]==(sub_str->ch)[j])
		{
			++i;
			++j;
		}
		else
		{
			j = 1;
			i = i-j+2; // j-1表示移动了多少次，(i-(j-1))表示回退到初始位置，(i-(j-1))+1表示回退到初始位置的下一个位置
		}
	}
	if(j>sub_str->len)
	{
		return i-sub_str->len;
	}
	return 0;
}

int main()
{
	struct Sstring main_str, sub_str;
	
	printf("please enter arbitrary main-string: ");
	scanf("%s", main_str.ch+1);
	main_str.len = strlen(main_str.ch)-1;

	printf("please enter arbitrary sub-string: ");
	scanf("%s", sub_str.ch+1);
	sub_str.len = strlen(sub_str.ch)-1;

	int index = index_BF(&main_str, &sub_str);
	if(index)
	{
		printf("The %d position of the substring in the main string\n", index);
	}
	else
	{
		printf("There are no substrings in the main string\n");
	}
	

	exit(0);
}