#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;
// 题目明确给出数字限制时尽量使用线性表 
vector<vector<int> > tree(100);
vector<int> noden(100);
int maxd=0;
//d为当前深度 
void dfs(int root,int d){
	//到叶子 
	if(tree[root].size()==0){
		noden[d]++;
		maxd=max(maxd,d);
		return; 
	}
	for(int i=0;i<tree[root].size();i++)
		dfs(tree[root][i],d+1);
}

int main(){
	int n,m,id,k,child;
	cin>>n>>m;
	for(int i=0;i<m;i++){
		cin>>id>>k;
		//cout<<id<<" "<<k;
		//看清循环变量！ 
		for(int j=0;j<k;j++){
			cin>>child;
			tree[id].push_back(child);
		}
	}
	dfs(1,0);
	cout<<noden[0];
	for(int i=1;i<=maxd;i++){
		cout<<" "<<noden[i];
	}
	return 0;
} 
