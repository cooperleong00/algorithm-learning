#include <iostream>
#include <vector>
#include <string>
#define inf 0x3f3f3f3f
//v1 WA 3 5（大数据集） 
/*
6 5 
1 2 0 4 5
1 3 0 1 3
2 5 0 1 5 
3 4 0 1 3
4 5 0 1 4 
1 5 
*/ 
//v2 WA 5 
using namespace std;
int main() {
	int N, M;
	cin >> N >> M;
	vector<vector<int>> dis(N, vector<int>(N, inf));
	vector<vector<int>> time(N, vector<int>(N, inf));
	for (int i = 0; i < M; i++) {
		int v1, v2, oneway, len, t;
		cin >> v1 >> v2 >> oneway >> len >> t;
		if (oneway==1) {
			dis[v1][v2] = len;
			time[v1][v2] = t;
		}
		else {
			dis[v1][v2] = len;
			dis[v2][v1] = len;
			time[v1][v2] = t;
			time[v2][v1] = t;
		}
	}
	int s, des;//起点，终点
	cin >> s >> des;
	//到每个节点最短路长度，是否访问过，时间，路径 
	vector<int>	st(N, inf), visited(N, 0), ft(N, inf), p1(N);
	for(int i=0;i<N;i++)	p1[i]=i;
	st[s] = 0; //ft[s] = 0; 
	for (int i = 0; i < N; i++) {
		int minu=-1, mind = inf;
		for (int j = 0; j < N; j++) {
			if (!visited[j] && st[j] < mind) {
				minu = j;
				mind = st[j];
			}
		}
		if(minu==-1)	break; 
		visited[minu] = 1;
		for (int j = 0; j < N; j++) {
			if (!visited[j]&&dis[minu][j]!=inf) {
				if (st[minu] + dis[minu][j] < st[j]) {
					st[j] = st[minu] + dis[minu][j];
					ft[j] = ft[minu] + time[minu][j];
					p1[j] = minu;
				}
				else if (st[minu] + dis[minu][j] == st[j]
					&& ft[j] > ft[minu] + time[minu][j]) {
					st[j] = st[minu] + dis[minu][j];
					p1[j] = minu;
				}
			}
		}
	}
	//重置访问flag 
	fill(visited.begin(),visited.end(),0);
	//最短时间，访问过，经过节点数，路径 
	vector<int> tt(N, inf), nnum(N, 0), p2(N);
	for(int i=0;i<N;i++)	p2[i]=i;
	tt[s] = 0; 
	for (int i = 0; i < N; i++) {
		int minu=-1, mind = inf;
		for (int j = 0; j < N; j++) {
			if (!visited[j] && tt[j] < mind) {
				minu = j;
				mind = tt[j];
			}
		}
		if(minu==-1)	break; 
		visited[minu] = 1;
		for (int j = 0; j < N; j++) {
			if (!visited[j]&&time[minu][j]!=inf) {
				if (tt[minu] + time[minu][j] < tt[j]) {
					tt[j] = tt[minu] + time[minu][j];
					nnum[j] = nnum[minu] + 1;
					p2[j] = minu;
				}
				else if (st[minu] + dis[minu][j] == st[j]
					&& nnum[j] > nnum[minu] + 1) {
					tt[j] = tt[minu] + time[minu][j];
					p2[j] = minu;
				}
			}
		}
	}
	//路径处理
	//用vector也可以，也重载了判断运算 
	vector<int> pt1, pt2;
	for (int i = des; i != s; i = p1[i]) {
		pt1.push_back(i);
	}
	for (int i = des; i != s; i = p2[i]) {
		pt2.push_back(i);
	}
	if (pt1 == pt2) {
		printf("Distance = %d; Time = %d: %d", st[des], tt[des], s);
		for (int i=pt1.size()-1;i>=0; i--)	printf(" -> %d", pt1[i]);
	}
	else {
		printf("Distance = %d: %d", st[des], s);
		for (int i=pt1.size()-1;i>=0; i--)	printf(" -> %d", pt1[i]);
		printf("\n");
		printf("Time = %d: %d", tt[des], s);
		for (int i=pt2.size()-1;i>=0; i--)	printf(" -> %d", pt2[i]);
	}
	return 0;
}
