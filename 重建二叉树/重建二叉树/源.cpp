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

	if (pre.empty() == true && vin.empty() == true) //�����ݹ�����������������
	{
		return NULL;
	}

	//�������ڵ�
	TreeNode *root = new TreeNode(pre[0]);

	//ǰ�������ֻ��һ��ֵ
	if (pre.size() == 1 && vin.size() == 1) //�����ݹ��������ֻ��һ��ֵ�����
	{
		if (pre == vin)  //vector ��ֱ������Ƚ�Ԫ�ش�Сô��
		{
			return root;
		}
		else
		{
			throw std::exception("�Ƿ����룡");
		}
	}

	//���������������������
	int In_root_index = 0;
	vector<int> In_left, In_right;
	while (In_root_index < vin.size() && vin[In_root_index] != root->val)
	{
		++In_root_index;
	}
	if (vin[In_root_index] == root->val) //���������ҵ����ڵ㣬��ֳ���������
	{
		for (int l = 0; l < In_root_index; l++) //��������ֱ����������ִ�У��޸�ֵ����Ϊ��
		{
			In_left.push_back(vin[l]);
		}
		int r = In_root_index + 1;
		if (r < vin.size())  //��������ֱ������
		{
			for (r; r < vin.size(); r++)
			{
				In_right.push_back(vin[r]);
			}
		}
	
	}

	//��ǰ�����������������,��������������ҵ������������ĳ���

	vector<int> Pre_left, Pre_right;
	if (In_left.empty() == false) //��Ϊ��
	{
		for (int l = 1; l <= In_left.size(); l++)
		{
			Pre_left.push_back(pre[l]);
		}
	}

	int r = In_left.size() + 1;
	if (r < pre.size())  //��������
	{
		while (r < pre.size())
		{
			Pre_right.push_back(pre[r]);
			r++;
		}
	}

	//ǰ��������������
	root->left = reConstructBinaryTree(Pre_left, In_left); //����������
	root->right = reConstructBinaryTree(Pre_right, In_right); //����������
	
	return root;
}

void pre_print(TreeNode* tree) //�ݹ�ǰ��
{
	if (tree != NULL)
	{
		cout << tree->val;
		pre_print(tree->left);
		pre_print(tree->right);
	}
}
void vin_print(TreeNode* tree) //�ݹ�����
{
	if (tree != NULL)
	{
		vin_print(tree->left);
		cout << tree->val;
		vin_print(tree->right);
	}
}
void beh_print(TreeNode* tree) //�ݹ����
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
	//�ݹ飨ǰ�����򣬺��򣩱���������
	cout << "ǰ��";
	pre_print(result);
	cout << endl << "����";
	vin_print(result);
	cout << endl << "����";
	beh_print(result);
	cout << endl;
	//�ǵݹ飨ǰ�����򣬺��򣩱���������

}

