// 二叉树.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <string>
#include <math.h>
using namespace std;
//树节点声明
struct TreeNode 
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
//生成二叉树
TreeNode* create_tree(vector<int> tree_vec)
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
//删除整个树
void delete_tree(TreeNode* head)
{

}
//前序遍历 递归
void traversal_preorder(TreeNode* head)
{
	if (!head) return;
	cout << head->val << ' ';
	traversal_preorder(head->left);
	traversal_preorder(head->right);
}
//中序遍历 递归
void traversal_inorder(TreeNode* head)
{
	if (!head) return;
	traversal_preorder(head->left);
	cout << head->val << ' ';
	traversal_preorder(head->right);
}
//后序遍历 递归
void traversal_postorder(TreeNode* head)
{
	if (!head) return;
	traversal_preorder(head->left);
	traversal_preorder(head->right);
	cout << head->val << ' ';
}
int main()
{
	vector<int> tree_vec = { 5,8,9,0,0,7,6,0,0,0,0,0,0,88 };
	TreeNode* head = create_tree(tree_vec);
	traversal_preorder(head);
	cout << endl;
	traversal_inorder(head);
	cout << endl;
	traversal_postorder(head);
	cout << endl;
}
