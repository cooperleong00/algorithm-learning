#include <iostream>
#include <vector>
#include <string.h>
using namespace std;
//��¼ÿ��Ԫ�ظ��������߶� 
//���1000��Ԫ�أ�Ҳ�����1000�� 
int lvl[1024],maxdp=0;
struct node{
	node *left,*right;
	//��¼���ڲ� 
	int val,level;
	node(int v,int l):val(v),level(l),left(NULL),right(NULL){
	};
};
 
void is(node *rt,int va){
	if(rt==NULL)	return ;
	//BST�ܱ�֤Ԫ��һ����ѡ��ĳ���ڵ������Ҳ���
	//����ѭ�����׼��� 
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
			//ע����ĳ�ʼ��Ҫ�������ļ�¼����Ҳ��ʼ���� 
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
