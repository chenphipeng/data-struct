#ifndef __LINK_TABLE_H__
#define __LINK_TABLE_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAMESIZE	1024
#define IDSIZE		15

struct data{
	char name[NAMESIZE];
	char id[IDSIZE];
	int score;
};

struct Lnode{
	struct data elem;
	struct Lnode *next;
};

enum erron_num{
	SUCCESS,   // 0
	FAIL,
	IS_EMPTY,
	NO_EMPTY,
	POS_ERR,
	NO_VALUE,
	EQUAL,
	NO_EQUAL
};

int Init_L(struct Lnode **L);	// 初始化单链表
int Empty_L(struct Lnode **L);	// 判断单链表是否为空
void Destory_L(struct Lnode **L);	// 销毁单链表
void Clear_L(struct Lnode **L);	// 清空单链表（链表仍存在，但链表中无元素，成为空表）
int Len_L(struct Lnode **L);	// 求单链表的长度 
int Getelem_L(struct Lnode **L, int pos, struct data elem);	// 获取单链表中某一个位置的元素
int Locateelem_L(struct Lnode **L, struct data elem);	// 按值查找单链表中的元素，并返回元素所在位置
int Listinsert_L(struct Lnode **L, int pos, struct data elem);	// 往单链表中插入元素
int Listdel_L(struct Lnode **L, int pos);	// 删除单链表上的结点
void HCreate_L(struct Lnode **L, int elem_n);	// 建立单链表(头插法)
void TCreate_L(struct Lnode **L, int elem_n);	// 建立单链表(尾插法)
#endif