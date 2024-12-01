// 学生成绩管理系统
#include "order-table.h"

int main()
{
	struct Sqlit L;
	int choice;

	// 初始化线性表L（学生成绩表），成功返回0，失败返回1
	if(Init_L(&L))
	{
		perror("malloc()");
		exit(0);
	}

	while(1)
	{
		meau();
		printf("please enter your choice: ");
		scanf("%d", &choice);
		switch(choice)
		{
			// 查询学生的成绩
			case 1:
				printf("please enter your name: ");
				char te_name[NAMESIZE];
				struct score te_gra;
				scanf("%s", te_name);
				if(Getelem(&L, te_name, &te_gra) == NO_FIND)
				{
					printf("sorry, no find\n");
					break;
				}
				printf("name is %s, id is %s, score is %d\n", te_gra.name, te_gra.id, te_gra.score);
				break;
			// 插入学生的成绩
			case 2:
				printf("please enter insert position: ");
				int i, ret;
				struct score stu;
				scanf("%d", &i);
				printf("please enter student's name, id and score: ");
				scanf("%s %s %d", &stu.name, &stu.id, &stu.score);
				ret = Insert_L(&L, i, &stu);
				if(ret == POS_FAIL)
				{
					printf("you insert position is fail\n");
				}
				else if(ret == MEM_OVER)
				{
					printf("table is overflow\n");
				}
				else
				{
					printf("insert success\n");
				}
				break;
			// 删除学生的成绩
			case 3:
				printf("please enter student's id: ");
				char id[IDSIZE];
				scanf("%s", id);
				if(Delete_L(&L, id) == NO_FIND)
				{
					printf("sorry, no find!\n");
					break;
				}
				printf("delete success\n");
				break;
			// 修改学生的成绩
			case 4:
				printf("please enter student's id: ");
				scanf("%s", id);
				printf("please enter modify name id and score: ");
				scanf("%s %s %d", &stu.name, &stu.id, &stu.score);
				if(Modify_L(&L, id, &stu) == NO_FIND)
				{
					printf("sorry, no find!\n");
					break;
				}
				printf("modify success\n");
				break;
			// 退出系统
			case 5:
				Clear_L(&L);
				Destroy_L(&L);
				printf("bye bye!\n");
				goto label1;
				break;
			default:
				printf("choice is fail!\n");
				break;
		}
	}
	label1:
	exit(0);
}