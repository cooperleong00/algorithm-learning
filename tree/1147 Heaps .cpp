#include <iostream>
#include <vector>
using namespace std;

struct node{
	int data,lc,rc;
};

void post(vector<int> &out,vector<node> &in,int c){
	if(c==-1||c>=in.size())	return;
	post(out,in,in[c].lc);
	post(out,in,in[c].rc);
	out.push_back(in[c].data);
}
int main(){
	int m,n,flag;//flag=0 for max,1 for min,2 for not
	cin>>m>>n;
	for(int i=0;i<m;i++){
		vector<int> r;//layer travalsal input
		vector<node> tree(n);
		for(int j=0;j<n;j++){
			cin>>tree[j].data;
			tree[j].lc=2*j+1<=n?2*j+1:-1;
			tree[j].rc=2*j+2<=n?2*j+2:-1;
		}
		flag=tree[0].data>tree[1].data?0:1;
		//完全二叉树中有子树的最后一个节点下标
		for(int j=0;j<=(n-1)/2;j++){
			if(flag==0&&(tree[j].data<tree[tree[j].lc].data||(tree[j].rc<n&&tree[j].data<tree[tree[j].rc].data)))
				flag=2;
			if(flag==1&&(tree[j].data>tree[tree[j].lc].data||(tree[j].rc<n&&tree[j].data>tree[tree[j].rc].data)))
				flag=2;
		}
		if(flag==0)	cout<<"Max Heap\n";
		else if(flag==1)	cout<<"Min Heap\n";
		else if(flag==2)	cout<<"Not Heap\n";
		post(r,tree,0);
		for(int j=0;j<n;j++){
			cout<<r[j];
			if(j<n-1)	cout<<" ";
			else cout<<"\n";
		}
	}
	return 0;
} 
