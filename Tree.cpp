#include "Tree.h"
#include <stack>
#include <queue>

TreeNode * Tree::create(int * a,int len)
{
	TreeNode *node = NULL;
	//node = NULL;
	if (num ==len)
	{
		return NULL;
	}


	int val = a[num];
	num++;

	if (val != 0)
	{
		node = new TreeNode();
		if (head == NULL)
		{
			head = node;
		}
		node->val = val;
		node->left = create(a,len);
		node->right = create(a,len);


	}

	return node;



}


void Tree::preOrderTravel(TreeNode * node)
{
	if (node == NULL)
	{
		return;
	}

	cout << node->val << " ";
	preOrderTravel(node->left);
	preOrderTravel(node->right);
}

void Tree::midOrderTravel(TreeNode *node)
{
	if (node == NULL)
		return;


	midOrderTravel(node->left);
	cout << node->val << " ";
	midOrderTravel(node->right);
}


void Tree::postOrderTravel(TreeNode *node)
{
	if (node == NULL)
		return;

	postOrderTravel(node->left);
	postOrderTravel(node->right);
	cout << node->val << " ";
}


void Tree::preOrder(TreeNode *node)
{
	stack<TreeNode *> st;

	TreeNode * p = node;


	while (p!= NULL ||st.size() !=0)
	{
		while (p != NULL)
		{
			cout << p->val << " ";
			st.push(p);
			p = p->left;
		}


		if (st.size() != 0)
		{
			p = st.top();
			st.pop();
			p = p->right;
		}

	}



}


void Tree::midOrder(TreeNode * node)
{
	TreeNode * p = node;

	
	stack<TreeNode *> st;

	while (p != NULL || st.size() != 0)
	{
		while (p != NULL)
		{
			st.push(p);
			p = p->left; 
		}


		if (st.size() != 0)
		{
			p = st.top();
			st.pop();
			cout << p->val << " ";
			p = p->right;
		}
		

	}


}


void Tree::postOrder(TreeNode* node)
{
	TreeNode* p = node;
	TreeNode* pre =NULL;
	stack<TreeNode *> st;


	st.push(p);
	while (st.size() != 0)
	{
		
		p = st.top();
		if ((p->left == NULL && p->right == NULL) ||((pre!=NULL) && (pre==p->left || pre==p->right) ) )
		{
			cout << p->val << " ";
			st.pop();
			pre = p;
		}
		else
		{
			if (p->right != NULL)
				st.push(p->right);

			if (p->left != NULL)
				st.push(p->left);
		}

	}


}


void Tree::floorOrder(TreeNode* node)
{
	TreeNode *p = node;

	queue<TreeNode* > qu;

	qu.push(p);

	while (qu.size()!=0)
	{
		p = qu.front();
		qu.pop();

		cout << p->val << " ";

		if (p->left != NULL)
		{
			qu.push(p->left);
		}

		if (p->right != NULL)
		{
			qu.push(p->right);
		}
		
	}
}