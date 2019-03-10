#include <iostream>
#include <string>
#include <vector>
#define inf 0x3f3f3f3f
using namespace std;
struct e{
	int ds,ct;
};
int main(){
	int n,m,s,d;
	cin>>n>>m>>s>>d;
	vector<vector<e>> road(n,vector<e>(n,e{inf,inf}));
	for(int i=0;i<m;i++){
		int v1,v2,dis,c;
		cin>>v1>>v2>>dis>>c;
		road[v1][v2].ds = dis;
		road[v1][v2].ct = c;
		road[v2][v1].ds = dis;
		road[v2][v1].ct = c;
	}
	vector<int> stpt(n,inf),cppt(n,inf),visited(n,0),pt(n);
	stpt[s] = 0;
	cppt[s] = 0;
	pt[s] = -1;
	while(1){
		int minct,mind=inf;
		for(int i=0;i<n;i++){
			if(!visited[i]&&stpt[i]<mind){
				minct = i;
				mind = stpt[i];
			}
		}
		if(mind==inf)	break;
		visited[minct]=1;
		for(int i=0;i<n;i++){
			if(!visited[i]&&road[minct][i].ds!=inf){
				if(stpt[i] > stpt[minct] + road[minct][i].ds){
					stpt[i] = stpt[minct] + road[minct][i].ds;
					cppt[i] = cppt[minct] + road[minct][i].ct;
					pt[i] = minct;
				}
				else if(stpt[i] == stpt[minct] + road[minct][i].ds 
					&& cppt[i] > cppt[minct] + road[minct][i].ct){
					cppt[i] = cppt[minct] + road[minct][i].ct;
					pt[i] = minct;
				}
			}
		}
	}
	vector<int> r;
	for(int i=d;i!=-1;i=pt[i])	r.push_back(i);
	for(int i=r.size()-1;i>=0;i--)	cout<<r[i]<<" ";
	cout<<stpt[d]<<" "<<cppt[d];
	return 0;
} 
