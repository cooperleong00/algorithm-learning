#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

void bfs(map<string,vector<string> > &t){
	string root = "01";
	int layer = 1;
	queue<string> q;
	q.push_back(root);
	while(q.size()){
		string r = q.front();
		if(t[r].size()>0){
		}
		else{
			cout<<
		}
	}
}

int main(){
	int n,m;
	while(cin>>n>>m){
		if(n==0)	break;
		map<string,vector<string> > tree;
		for(int i=0;i<m;i++){
			string id;
			int k;
			cin>>id>>k;
			vector<string> v(k);
			for(int j=0;j<k;j++){
				cin>>v[j];
				if(tree.find(v[j])==tree.end()){
					vector<string> temp;
					map[v[j]]=temp;
				}
			}
			map[id]=v;
		}
	}
	return 0;
} 
