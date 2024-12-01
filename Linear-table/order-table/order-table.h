#ifndef __ORDER_TABLE_H__
#define __ORDER_TABLE_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAMESIZE	20
#define IDSIZE		15
#define STUTAB		800

enum erron_num{
	SUCCESS,
	POS_FAIL,
	MEM_OVER,
	NO_FIND
};

// 学生成绩
struct score{
	char name[NAMESIZE];
	char id[IDSIZE];
	int score;
};

// 线性表类型定义
struct Sqlit{
	int length;
	struct score *pstu;
};

int Init_L(struct Sqlit *pL);		// 初始化线性表
void Destroy_L(struct Sqlit *pL);	// 销毁线性表
void Clear_L(struct Sqlit *pL);		// 清空线性表
int Getlength(struct Sqlit *pL);	// 获取线性表的长度
int Isempty(struct Sqlit *pL);		// 判断线性表是否为空
int Getelem(struct Sqlit *pL, const char *te_name, struct score *te_gra);	// 查询线性表
int Insert_L(struct Sqlit *pl, int pos, struct score *ps);	// 线性表中插入
int Delete_L(struct Sqlit *pl, char *p_id);	// 线性表中删除
int Modify_L(struct Sqlit *pl, char *p_id, struct score *pstu);	// 线性表中修改
void meau();	// 打印菜单

#endif