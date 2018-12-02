// 二叉树.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//2018-11-29

#include "pch.h"
#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <algorithm>
using namespace std;
typedef int ElemType;
//typedef char ElemType;
//树节点声明
struct TreeNode 
{
	ElemType val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(ElemType x) : val(x), left(NULL), right(NULL) {}
};
//生成二叉树,构建一个完全二叉树,0为空节点
TreeNode* create_tree_ByVector(vector<ElemType> tree_vec)
{
	//构建一个完全二叉树,0为空节点
	if (tree_vec.empty()) return NULL;
	vector<TreeNode*> node_vec;
	//先创建节点，只有值，没有left和right
	for (auto it = tree_vec.begin(); it != tree_vec.end(); it++)
	{
		if (*it != 0)
		{
			TreeNode* new_node = new TreeNode(*it);
			node_vec.push_back(new_node);
		}
		else node_vec.push_back(NULL);
	}
	TreeNode* head = node_vec[0];
	int node_depth = 0;//节点深度
	for (int id_node = 0; id_node < node_vec.size(); id_node++)
	{
		if (!node_vec[id_node]) continue; //是空就跳过
		//先计算节点在第几层
		while ((id_node + 1) / pow(2, node_depth) >= 2) node_depth++;
		//完全二叉树中，当第一个节点ID为0时，第I个节点的左子节点是第2I+1个，右子节点是第2I+2个
		if (id_node * 2 + 1 < node_vec.size()) 
			node_vec[id_node]->left = node_vec[id_node * 2 + 1];
		else node_vec[id_node]->left = NULL;
		if (id_node * 2 + 2 < node_vec.size())
			node_vec[id_node]->right = node_vec[id_node * 2 + 2];
		else node_vec[id_node]->right = NULL;
	}
	return head;
}
//删除整个树 递归
int delete_tree(TreeNode* head)
{
	int del_num = 1;
	if (!head) return 0;
	del_num += delete_tree(head->left);
	del_num += delete_tree(head->right);
	delete head;
	return del_num;
}
//前序遍历 递归
vector<ElemType> traversal_preorder(TreeNode* head)
{
	vector<ElemType> res;
	if (!head) return res;
	res.push_back(head->val);
	cout << head->val << ' ';
	vector<ElemType> v1 = traversal_preorder(head->left);
	res.insert(res.end(), v1.begin(), v1.end());
	vector<ElemType> v2 = traversal_preorder(head->right);
	res.insert(res.end(), v2.begin(), v2.end());
	return res;
}
//中序遍历 递归
vector<ElemType> traversal_inorder(TreeNode* head)
{
	vector<ElemType> res;
	if (!head) return res;
	vector<ElemType> v1 = traversal_preorder(head->left);
	res.insert(res.end(), v1.begin(), v1.end());
	res.push_back(head->val);
	cout << head->val << ' ';
	vector<ElemType> v2 = traversal_preorder(head->right);
	res.insert(res.end(), v2.begin(), v2.end());
	return res;
}
//后序遍历 递归
vector<ElemType> traversal_postorder(TreeNode* head)
{
	vector<ElemType> res;
	if (!head) return res;
	vector<ElemType> v1 = traversal_preorder(head->left);
	res.insert(res.end(), v1.begin(), v1.end());
	vector<ElemType> v2 = traversal_preorder(head->right);
	res.insert(res.end(), v2.begin(), v2.end());
	res.push_back(head->val);
	cout << head->val << ' ';
	return res;
}
//层序遍历,输出节点
vector<TreeNode*> traversal_depth2node(TreeNode* head, bool isPrint = false)
{	
	//A为B、E的双亲结点，遍历顺序是 根->左->右 是不是。
	//而且每个结点都是这样的遍历顺序。那么我们完全可以采用队列的数据结构。
	//A入队->然后出队，出队时将其左右孩子入队，循环队列进行出队，每次出队将其左右孩子入队。
	//当队列为空时，整棵树层序遍历完毕。
	TreeNode* out;
	vector<TreeNode*> tree_queue1,tree_queue2,res;
	tree_queue1.push_back(head);
	while (true)
	{
		out = tree_queue1[tree_queue1.size() - 1];
		if (isPrint) cout << out->val << ' ';
		res.push_back(out);
		tree_queue1.pop_back();
		if (out->left) tree_queue1.insert(tree_queue1.begin(), out->left);
		if (out->right) tree_queue1.insert(tree_queue1.begin(), out->right);
		if (tree_queue1.empty()) break;
	}
	if (isPrint) cout << endl;
	return res;
}
//层序遍历，输出值
vector<ElemType> traversal_depth2val(TreeNode* head, bool isPrint = false)
{
	TreeNode* out;
	vector<TreeNode*> tree_queue1, tree_queue2;
	vector<ElemType> res;
	tree_queue1.push_back(head);
	while (true)
	{
		out = tree_queue1[tree_queue1.size() - 1];
		if (isPrint) cout << out->val << ' ';
		res.push_back(out->val);
		tree_queue1.pop_back();
		if (out->left) tree_queue1.insert(tree_queue1.begin(), out->left);
		if (out->right) tree_queue1.insert(tree_queue1.begin(), out->right);
		if (tree_queue1.empty()) break;
	}
	if (isPrint) cout << endl;
	return res;
}
//求二叉树最大深度
int maxDepth(TreeNode* root)
{
	if (!root) return 0;
	int res = 0;
	res = max(maxDepth(root->left), maxDepth(root->right));
}
//按照层打印二叉树
void print_tree(TreeNode* head)
{
	string need_print;

}
int main()
{
	vector<ElemType> tree_vec = { 5,8,9,0,0,7,6,0,0,0,0,0,0,88 };
	//vector<ElemType> tree_vec = { 'A','B','E','C','D',NULL,'G' };
	TreeNode* head = create_tree_ByVector(tree_vec);
	cout << "层序遍历为" << endl;
	traversal_depth2node(head, true);
	cout << "前序遍历为" << endl;
	vector<ElemType>res = traversal_preorder(head);
	cout << endl;
	cout << "中序遍历为" << endl;
	res = traversal_inorder(head);
	cout << endl;
	cout << "后序遍历为" << endl;
	res = traversal_postorder(head);
	cout << endl;
	cout << "已删除了" << delete_tree(head) << "个节点";
}
