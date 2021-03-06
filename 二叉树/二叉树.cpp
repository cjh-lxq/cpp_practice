// 二叉树.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//2018-11-29

#include "pch.h"
#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <algorithm>
#include <queue>
using namespace std;
typedef int Element_type;
//typedef char Element_type;
//树节点声明
struct TreeNode 
{
	Element_type val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(Element_type x) : val(x), left(NULL), right(NULL) {}
};
//生成二叉树,构建一个完全二叉树,0为空节点
TreeNode* create_tree_ByVector(vector<Element_type> tree_vec)
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
vector<Element_type> traversal_preorder(TreeNode* head)
{
	vector<Element_type> res;
	if (!head) return res;
	res.push_back(head->val);
	cout << head->val << ' ';
	vector<Element_type> v1 = traversal_preorder(head->left);
	res.insert(res.end(), v1.begin(), v1.end());
	vector<Element_type> v2 = traversal_preorder(head->right);
	res.insert(res.end(), v2.begin(), v2.end());
	return res;
}
//中序遍历 递归
vector<Element_type> traversal_inorder(TreeNode* head)
{
	vector<Element_type> res;
	if (!head) return res;
	vector<Element_type> v1 = traversal_preorder(head->left);
	res.insert(res.end(), v1.begin(), v1.end());
	res.push_back(head->val);
	cout << head->val << ' ';
	vector<Element_type> v2 = traversal_preorder(head->right);
	res.insert(res.end(), v2.begin(), v2.end());
	return res;
}
//后序遍历 递归
vector<Element_type> traversal_postorder(TreeNode* head)
{
	vector<Element_type> res;
	if (!head) return res;
	vector<Element_type> v1 = traversal_preorder(head->left);
	res.insert(res.end(), v1.begin(), v1.end());
	vector<Element_type> v2 = traversal_preorder(head->right);
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
vector<Element_type> traversal_depth2val(TreeNode* head, bool isPrint = false)
{
	TreeNode* out;
	vector<TreeNode*> tree_queue1, tree_queue2;
	vector<Element_type> res;
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
	int res = 1;
	res = 1+max(maxDepth(root->left), maxDepth(root->right));
	return res;
}
//二叉树的层序遍历，返回二维数组(值)
vector<vector<Element_type>> levelOrderBottom_val(TreeNode* root, bool add_zero=false)
{
	//先将根节点加入第一层列表，然后将其左右节点分别加入第二层列表，再迭代上述过程。
	vector<Element_type> col_val_vec0, col_val_vec1;
	vector<TreeNode*> col_node_vec0, col_node_vec1;
	vector<vector<Element_type>> res_val;
	vector<vector<TreeNode*>> res_node;
	if (!root) return res_val;
	bool col_empty = false; //判断这层是不是为空
	col_val_vec0.push_back(root->val);
	col_node_vec0.push_back(root);
	res_node.push_back(col_node_vec0);
	res_val.push_back(col_val_vec0);
	while (!col_node_vec0.empty())
	{
		for (int i = 0; i < col_node_vec0.size(); i++)
		{
			if (col_node_vec0[i]->left)
			{
				col_node_vec1.push_back(col_node_vec0[i]->left);
				col_val_vec1.push_back(col_node_vec0[i]->left->val);
			}
			else if (add_zero) col_val_vec1.push_back(0);
			if (col_node_vec0[i]->right)
			{
				col_node_vec1.push_back(col_node_vec0[i]->right);
				col_val_vec1.push_back(col_node_vec0[i]->right->val);
			}
			else if (add_zero) col_val_vec1.push_back(0);
		}
		col_node_vec0.clear();
		col_val_vec0.clear();
		col_node_vec0 = col_node_vec1;
		col_val_vec0 = col_val_vec1;
		col_node_vec1.clear();
		col_val_vec1.clear();
		if (!col_node_vec0.empty())
		{
			res_node.push_back(col_node_vec0);
			res_val.push_back(col_val_vec0);
		}
	}
	return res_val;
}
//二叉树的层序遍历，返回二维数组(节点)
vector<vector<TreeNode*>> levelOrderBottom_node(TreeNode* root, bool add_zero=false)
{
	vector<vector<TreeNode*>> res_node;
	if (!root) return res_node;
	if (add_zero)
	{
		int tree_max_depth = maxDepth(root);
		vector<vector<TreeNode*>>& element_node_vec = res_node;
		element_node_vec.resize(tree_max_depth);
		element_node_vec[0].push_back(root);
		//将值填入element_val_vec中, 将地址填入element_node_vec中
		for (int num_depth = 1; num_depth < tree_max_depth; num_depth++)
			//从第1层开始循环，跳过了第二层int i = 0; i < element_node_vec[num_depth - 1].size(); i++
		{
			for (int i = 0; i < element_node_vec[num_depth - 1].size(); i++)
			{
				if (element_node_vec[num_depth - 1][i] != NULL)
				{
					if (element_node_vec[num_depth - 1][i]->left)
						element_node_vec[num_depth].push_back(element_node_vec[num_depth - 1][i]->left);
					else
						element_node_vec[num_depth].push_back(NULL);
					if (element_node_vec[num_depth - 1][i]->right)
						element_node_vec[num_depth].push_back(element_node_vec[num_depth - 1][i]->right);
					else
						element_node_vec[num_depth].push_back(NULL);
				}
				else
				{
					element_node_vec[num_depth].push_back(NULL);
					element_node_vec[num_depth].push_back(NULL);
				}
			}
		}
	}
	else
	{
		//先将根节点加入第一层列表，然后将其左右节点分别加入第二层列表，再迭代上述过程。
		vector<Element_type> col_val_vec0, col_val_vec1;
		vector<TreeNode*> col_node_vec0, col_node_vec1;
		vector<vector<Element_type>> res_val;
		if (!root) return res_node;
		col_val_vec0.push_back(root->val);
		col_node_vec0.push_back(root);
		res_node.push_back(col_node_vec0);
		res_val.push_back(col_val_vec0);
		while (!col_node_vec0.empty())
		{
			for (int i = 0; i < col_node_vec0.size(); i++)
			{
				if (col_node_vec0[i]->left)
				{
					col_node_vec1.push_back(col_node_vec0[i]->left);
					col_val_vec1.push_back(col_node_vec0[i]->left->val);
				}
				if (col_node_vec0[i]->right)
				{
					col_node_vec1.push_back(col_node_vec0[i]->right);
					col_val_vec1.push_back(col_node_vec0[i]->right->val);
				}
			}
			col_node_vec0.clear();
			col_val_vec0.clear();
			col_node_vec0 = col_node_vec1;
			col_val_vec0 = col_val_vec1;
			col_node_vec1.clear();
			col_val_vec1.clear();
			if (!col_node_vec0.empty())
			{
				res_node.push_back(col_node_vec0);
				res_val.push_back(col_val_vec0);
			}
		}
	}
	return res_node;
}
//按照层打印二叉树(还是不会写)
void print_tree(TreeNode* head, bool print_cols=true)
{
	//2018-12-5进展：补零的层序遍历完成了，现在生成字符串打印的部分还没有完成
	if (!head) return;
	vector<vector<TreeNode*>> element_node_vec = levelOrderBottom_node(head, true);//此时，element_node_vec就是层序遍历的结果(所有的空除补上NULL)
	vector<string> need_print_vec;//接下来要从层序遍历（已补零）的二维数组返回要打印的字符串数组
	int tree_depth = maxDepth(head);
	need_print_vec.resize(tree_depth);
	int num_space = 0;
	int num_depth = 0;
	for (int i = 1; i <= tree_depth; i++)
	{
		num_space = pow(2, i) - 1;
		num_depth = tree_depth - i;//行数从0开始计算
	}
	cout << '123' << endl;
}
void print_tree_structure(TreeNode *bt, int spaces)
{
	if (bt != NULL)
	{
		print_tree_structure(bt->right, spaces + 5);
		for (int i = 0; i < spaces; i++)
			cout << ' ';
		cout << "   " << bt->val << endl;
		print_tree_structure(bt->left, spaces + 5);
	}
}
int main()
{
	vector<Element_type> tree_vec = { 8,5,10,2,0,9,11,14,0,0,0,15,4,8,0 };
	//vector<Element_type> tree_vec = { 'A','B','E','C','D',NULL,'G' };
	TreeNode* head = create_tree_ByVector(tree_vec);
	cout << "层序遍历为" << endl;
	traversal_depth2node(head, true);
	cout << "前序遍历为" << endl;
	vector<Element_type>res = traversal_preorder(head);
	cout << endl;
	cout << "中序遍历为" << endl;
	res = traversal_inorder(head);
	cout << endl;
	cout << "后序遍历为" << endl;
	res = traversal_postorder(head);
	cout << endl;
	cout << "按层打印为" << endl;
	print_tree(head);
	//print_tree_structure(head);
	cout << "已删除了" << delete_tree(head) << "个节点";
}