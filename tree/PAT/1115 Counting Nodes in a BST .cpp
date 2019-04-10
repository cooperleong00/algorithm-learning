#include <iostream>
#include <vector>
#include <string.h>
using namespace std;
//记录每层元素个数，最大高度 
//最多1000个元素，也就最多1000层 
int lvl[1024],maxdp=0;
struct node{
	node *left,*right;
	//记录所在层 
	int val,level;
	node(int v,int l):val(v),level(l),left(NULL),right(NULL){
	};
};
 
void is(node *rt,int va){
	if(rt==NULL)	return ;
	//BST能保证元素一定能选择某个节点的左或右插入
	//所以循环到底即可 
	while(1){
		if(va<=rt->val){
			if(rt->left==NULL){
				int newlvl = rt->level+1;
				rt->left = new node(va,newlvl);
				lvl[newlvl]++;
				if(maxdp<newlvl)	maxdp=newlvl;
				break;
			}
			else rt = rt->left;
		}
		else{
			if(rt->right==NULL){
				int newlvl = rt->level+1;
				rt->right = new node(va,newlvl);
				lvl[newlvl]++;
				if(maxdp<newlvl)	maxdp=newlvl;
				break;
			}
			else{
				rt=rt->right;
			}
		}
	}
}

int main(){
	int n;
	cin>>n;
	memset(lvl,0,1024*sizeof(int));
	node *root = new node(0,0);
	for(int i=0;i<n;i++){
		int in;
		cin>>in;
		if(i==0){
			//注意根的初始化要把其他的记录变量也初始化了 
			root->val = in;
			lvl[0]++;
		}	
		else{
			is(root,in);
		}
	}
	printf("%d + %d = %d",lvl[maxdp],lvl[maxdp-1],lvl[maxdp]+lvl[maxdp-1]);
	return 0;
} 
