#include <stdio.h>
#include <stdlib.h>

struct data{
	int score;
	int data[1];
};

int main()
{
	int temp, test;
	temp = test = 46;
	printf("temp=%d, test=%d\n", temp, test);
	struct data *p = malloc(sizeof(struct data));
	printf("%d\n", sizeof((p->data)));
	printf("%d\n", sizeof(struct data));
	exit(0);
}