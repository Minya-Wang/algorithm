#include<iostream>
#include<vector>
#include<stack>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin){

	if (pre.empty() == true && vin.empty() == true) //结束递归的条件：无树的情况
	{
		return NULL;
	}

	//创建根节点
	TreeNode *root = new TreeNode(pre[0]);

	//前序和中序只有一个值
	if (pre.size() == 1 && vin.size() == 1) //结束递归的条件：只有一个值的情况
	{
		if (pre == vin)  //vector 可直接整体比较元素大小么？
		{
			return root;
		}
		else
		{
			throw std::exception("非法输入！");
		}
	}

	//在中序遍历中找左右子树
	int In_root_index = 0;
	vector<int> In_left, In_right;
	while (In_root_index < vin.size() && vin[In_root_index] != root->val)
	{
		++In_root_index;
	}
	if (vin[In_root_index] == root->val) //在中序中找到根节点，拆分出左右子树
	{
		for (int l = 0; l < In_root_index; l++) //无左子树直接跳过本行执行，无赋值，即为空
		{
			In_left.push_back(vin[l]);
		}
		int r = In_root_index + 1;
		if (r < vin.size())  //无右子树直接跳过
		{
			for (r; r < vin.size(); r++)
			{
				In_right.push_back(vin[r]);
			}
		}
	
	}

	//在前序遍历中找左右子树,根据中序遍历中找到的左右子树的长度

	vector<int> Pre_left, Pre_right;
	if (In_left.empty() == false) //不为空
	{
		for (int l = 1; l <= In_left.size(); l++)
		{
			Pre_left.push_back(pre[l]);
		}
	}

	int r = In_left.size() + 1;
	if (r < pre.size())  //无右子树
	{
		while (r < pre.size())
		{
			Pre_right.push_back(pre[r]);
			r++;
		}
	}

	//前序中序左右子树
	root->left = reConstructBinaryTree(Pre_left, In_left); //构建左子树
	root->right = reConstructBinaryTree(Pre_right, In_right); //构建右子树
	
	return root;
}

void pre_print(TreeNode* tree) //递归前序
{
	if (tree != NULL)
	{
		cout << tree->val;
		pre_print(tree->left);
		pre_print(tree->right);
	}
}
void vin_print(TreeNode* tree) //递归中序
{
	if (tree != NULL)
	{
		vin_print(tree->left);
		cout << tree->val;
		vin_print(tree->right);
	}
}
void beh_print(TreeNode* tree) //递归后序
{
	if (tree != NULL)
	{
		beh_print(tree->left);
		beh_print(tree->right);
		cout << tree->val;
	}
}
//void pre_print(TreeNode* tree)
//{
//	stack<TreeNode* > nodes;
//	while (tree != NULL)
//	{
//		cout << tree->val;
//		nodes.push(tree);
//		tree = tree->left;
//	}
//	tree = nodes.top();
//	nodes.pop();
//	tree = tree->right;
//
//}
int main(){
	vector<int> pre = {1, 2, 4, 7, 3, 5, 6, 8 };
	vector<int> vin = {4, 7, 2, 1, 5, 3, 8, 6 };
	TreeNode *result = reConstructBinaryTree(pre, vin);
	//递归（前序，中序，后序）遍历二叉树
	cout << "前序：";
	pre_print(result);
	cout << endl << "中序：";
	vin_print(result);
	cout << endl << "后序：";
	beh_print(result);
	cout << endl;
	//非递归（前序，中序，后序）遍历二叉树

}

