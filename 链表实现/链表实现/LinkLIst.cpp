#include "pch.h"
#include "LinkLIst.h"
#include <iostream>
#define NULL 0
using namespace std;
LinkLIst::LinkLIst()
{
	head = NULL;
	tail = NULL;
}

LinkLIst::~LinkLIst()
{
	NODE *p = NULL;
	int num_node = 0;
	while (head)
	{
		++num_node;
		p = head;
		head = head->next;
		delete(p);
	}
	head = NULL;
	tail = NULL;
	cout << num_node << " node(s) is deleted" << endl;
}
void LinkLIst::addNode(int a,bool head_add)
{
	if (head==NULL)
	{
		NODE* new_node = new NODE(a);
		head = new_node;
		tail = head;
		return;
	}
	if (head_add)
	{
		NODE* new_node = new NODE(a);
		new_node->next = head;
		head = new_node;
	}
	else
	{
		NODE* new_node = new NODE(a);
		tail->next = new_node;
		tail = new_node;
	}
}
bool LinkLIst::clearSqList()
{
	NODE *p = NULL;
	while (head)
	{
		p = head;
		head = head->next;
		delete(p);
	}
	head = NULL;
	tail = NULL;
	return true;
}
int LinkLIst::Length()
{
	NODE* p = head;
	int num_node = 0;
	while (p!=NULL)
	{
		++num_node;
		p = p->next;
	}
	return num_node;
}
void LinkLIst::print_linklist()
{
	NODE *p = head;
	while (p!=NULL)
	{
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}
void LinkLIst::Reverse()
{
	if (!(head && head->next))
	{
		return;
	}
	NODE* head_ls = NULL,*p=NULL,*next_n=NULL;
	head_ls = head;
	while (head_ls)
	{
		next_n = head_ls->next;
		head_ls->next = p;
		p = head_ls;
		head_ls = next_n;
	}
	head_ls = tail;
	tail = head;
	head = head_ls;
}