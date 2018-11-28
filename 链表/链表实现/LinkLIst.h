#pragma once
#define NULL 0
typedef struct node {
	int data;
	struct node *next;
	node(int x) :data(x), next(NULL) {}
}NODE;
class LinkLIst
{
private:
	NODE * head;
	NODE * tail;
public:
	LinkLIst();
	~LinkLIst();
	bool clearSqList();
	void addNode(int a,bool head_add);
	bool isEmpty() { return head == NULL; }
	int Length();
	void GetElem(int i, int *e);
	void print_linklist();
	//int LocateElem(int e);
	//bool PriorElem(int cur_e, int *pre_e);
	//bool NextElem(int cur_e, int *next_e);
	//bool Insert(int i, int e);
	//bool Delete(int i, int *e);
	void Reverse();
};

