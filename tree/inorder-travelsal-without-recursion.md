# 不使用递归来对二叉树进行中序遍历
一般来说用于替代递归的迭代都要用到栈啦
## 过程描述
1. 创建一个栈
2. 如果root不为NULL，则将root推入栈中，并将root设为root的左子树，循环。
3. 如果root 为NULL 但栈不为空，弹出栈顶赋值给root，访问root并将root设为root的右子树
4. 如果root为NULL且栈为空，则遍历已完成，退出循环

```
#include <iostream>
#include <stack>
using namespace std;
//leetcode风格 
struct TreeNode{
	TreeNode *left,*right;
	int val;
	TreeNode(int v):val(v),left(NULL),right(NULL){};
};
void inorder(TreeNode *root){
	stack<TreeNode*> stk;
	while(!stk.empty()||root){
		while(root){
			stk.push(root);
			root = root->left;
		}
		root = stk.top();
		cout<<root->val<<" ";
		stk.pop();
		root = root->right;	
	}
}
int main(){
	TreeNode *n1=new TreeNode(1);
	TreeNode *n2=new TreeNode(2);
	TreeNode *n3=new TreeNode(3);
	TreeNode *n4=new TreeNode(4);
	TreeNode *n5=new TreeNode(5);
	TreeNode *n6=new TreeNode(6);
	/*
	      1
	    /  \
	   2   3
	    \ / \
            45  6
	*/
	n1->left = n2;n1->right=n3;
	n2->right = n4;
	n3->left = n5;n3->right = n6;
	// 2 4 1 5 3 6
	inorder(n1);
	return 0;
}
```
