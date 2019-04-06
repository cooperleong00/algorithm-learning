#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int n;
vector<int> in, post;
//二叉树 
struct node {
	node *left, *right;
	int val;
	node(int v) :val(v), left(NULL), right(NULL) {
	};
};
//常规建树 
node* makeTree(int postl, int postr, int inl, int inr) {
	if (inl > inr)	return NULL;
	int i = 0;
	while (post[postr] != in[i])	i++;
	node *tn = new node(in[i]);
	//cout<<tn->val<<" ";
	tn->left = makeTree(postl, postl + (i - inl) - 1, inl, i - 1);
	tn->right = makeTree(postl + (i - inl), postr - 1, i + 1, inr);
	return tn;
}
// 改装层序遍历 
void levelorder(node* root, vector<int> &lvl) {
	vector<node*> q;
	q.push_back(root);
	//一个用于改变每层遍历顺序的flag 
	int flag = 1;
	while (q.size()) {
		int t = q.size();
		while (t-- > 0) {
			node* cur = q[0];
			lvl.push_back(cur->val);
			q.erase(q.begin());
			if (!flag) {
				if (cur->left)	q.push_back(cur->left);
				if (cur->right)	q.push_back(cur->right);
			}
			else {
				if (cur->right)	q.push_back(cur->right);
				if (cur->left)	q.push_back(cur->left);
			}
		}
		flag = !flag;
		//把queue里的顺序调转 
		reverse(q.begin(), q.end());
	}
}
int main() {
	cin >> n;
	in.resize(n); post.resize(n);
	vector<int> level;
	for (int i = 0; i < n; i++)	cin >> in[i];
	for (int i = 0; i < n; i++)	cin >> post[i];
	node *root = makeTree(0, n - 1, 0, n - 1);
	levelorder(root, level);
	for (int i = 0; i < n; i++) {
		cout << level[i];
		if (i != n - 1)	cout << " ";
	}
	return 0;
}
