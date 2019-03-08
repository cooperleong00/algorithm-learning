#include <iostream>
#include <vector>
#include <string>
#include <map>
#define inf 0x3f3f3f3f
using namespace std;
int main() {
	int n, k, cnt = 1;
	cin >> n >> k;
	// 
	map<string, int> hpns;
	//出发城市 
	string st;
	cin >> st;
	hpns[st] = 0;
	for (int i = 1; i < n; i++) {
		string ct;
		int hp;
		cin >> ct >> hp;
		hpns[ct] = hp;
	}
	map<string, map<string, int>> cost;
	for (int i = 0; i < k; i++) {
		string s, des;
		int cst;
		cin >> s >> des >> cst;
		cost[s][des] = cst;
		cost[des][s] = cst;
	}
	map<string, int> mincost, maxhp, ctnum, visited,num;
	map<string, string> pt;//path
	for (auto p : hpns) {
		mincost[p.first] = inf;
		maxhp[p.first] = 0;
		ctnum[p.first] = 0;
		visited[p.first] = 0;
		num[p.first] = 0;
		pt[p.first] = p.first;
	}
	for (auto p1 : hpns) {
		for (auto p2 : hpns) {
			if (cost[p1.first][p2.first] == 0) {
				cost[p1.first][p2.first] = inf;
			}
		}
	}
	mincost[st] = 0;
	num[st] = 1;
	for (auto p1 : mincost) {
		string mincity;
		int minc = inf;
		for (auto p2 : mincost) {
			if (!visited[p2.first] && p2.second < minc) {
				mincity = p2.first;
				minc = p2.second;
			}
		}
		if (minc == inf)	break;
		visited[mincity] = 1;
		for (auto p2 : mincost) {
			string citynow = p2.first;
			if (!visited[citynow] && cost[mincity][citynow] != inf) {
				if (mincost[citynow] > mincost[mincity] + cost[mincity][citynow]) {
					mincost[citynow] = mincost[mincity] + cost[mincity][citynow];
					ctnum[citynow] = ctnum[mincity] + 1;
					maxhp[citynow] = maxhp[mincity] + hpns[citynow];
					pt[citynow] = mincity;
					//注意最短路径条数的计算 
					num[citynow]=num[mincity];
				}
				else if (mincost[citynow] == mincost[mincity] + cost[mincity][citynow]) {
					//注意最短路径条数的计算 
					num[citynow]+=num[mincity];
					if (maxhp[citynow] < maxhp[mincity] + hpns[citynow]) {
						ctnum[citynow] = ctnum[mincity] + 1;
						maxhp[citynow] = maxhp[mincity] + hpns[citynow];
						pt[citynow] = mincity;
					}
					//注意平均数最好求小数进行比较 
					else if (maxhp[citynow] == maxhp[mincity] + hpns[citynow]
						&& (maxhp[citynow]*1.0 / ctnum[citynow]) < (maxhp[mincity] + hpns[citynow])*1.0 / (ctnum[mincity] + 1)) {
						ctnum[citynow] = ctnum[mincity] + 1;
						//条件无需重复赋值 
						//maxhp[citynow] = maxhp[mincity] + hpns[citynow];
						pt[citynow] = mincity;
					}
				}
			}
		}
	}
	//注意hpns和maxhp得区别
	//hpns是每个城市的值，相当于路径的权重
	//maxhp是到某个城市最短路径的权重和 
	printf("%d %d %d %d\n", num["ROM"], mincost["ROM"], maxhp["ROM"], maxhp["ROM"] / ctnum["ROM"] );
	vector<string> route;
	for (string i = "ROM"; i != st; i = pt[i]) {
		route.push_back(i);
	}
	cout << st;
	for (int i = route.size() - 1; i >= 0; i--) {
		cout << "->" << route[i];
	}
	return 0;
}
