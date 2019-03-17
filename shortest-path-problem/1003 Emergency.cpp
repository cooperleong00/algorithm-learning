#include <iostream>
#include <vector>
#include <string>
#define inf 0x3f3f3f3f
using namespace std;
/* // !!最短路径条数和与 最大队伍数（点权和） 无关 
5 6 0 3
1 2 3 4 2 
0 1 1
0 2 1
1 3 1
2 3 1
0 4 1
4 2 1 
*/ 
int main(){
	int n,m,c1,c2;
	cin>>n>>m>>c1>>c2;
	vector<vector<int>> len(n,vector<int>(n,inf));
	vector<int> teamnum(n);
	for(int i=0;i<n;i++)	cin>>teamnum[i];
	for(int i=0;i<m;i++){
		int s,d,l;
		cin>>s>>d>>l;
		len[s][d] = l;
		len[d][s] = l;
	}
	vector<int> st(n,inf),maxteam(n,0),ptnum(n,0),visited(n,0),vis2(n,0);
	st[c1]=0;
	maxteam[c1]=teamnum[c1];
	while(1){
		int ct,minl=inf;
		for(int i=0;i<n;i++){
			if(!visited[i]&&st[i]<minl){
				minl=st[i];
				ct=i;
			}
		}
		if(minl==inf)	break;
		visited[ct]=1;
		//考虑了孤立节点的可能，但是测试点中没有 
		ptnum[ct]= ptnum[ct]==0?1:ptnum[ct];
		for(int i=0;i<n;i++){
			if(!visited[i]&&len[ct][i]!=inf){
				if(st[i]>len[ct][i]+st[ct]){
					st[i]=len[ct][i]+st[ct];
					maxteam[i] = maxteam[ct]+teamnum[i];
					ptnum[i]=ptnum[ct];
				}
				// !!最短路径条数和与 最大队伍数（点权和） 无关 
				else if(st[i]==len[ct][i]+st[ct]){
					if(maxteam[i] < maxteam[ct]+teamnum[i]){
						maxteam[i] = maxteam[ct]+teamnum[i];
					}
					ptnum[i]+=ptnum[ct];
				}
				
			}
		}
	} 
	cout<<ptnum[c2]<<" "<<maxteam[c2];
	return 0;
} 
