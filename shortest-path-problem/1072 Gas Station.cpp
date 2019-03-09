#include <iostream>
#include <string>
#include <vector>
#define inf 0x3f3f3f3f
using namespace std;
int n, m, k, ds;

int g2node(string t) {
	if (t[0]=='G') {
		//一定要考虑边界情况
		//有可能输入G10 不能只处理t[1] 
		return stoi(t.substr(1))+n-1;
	}
	else {
		return stoi(t)-1;
	}
}

int main() {
	cin >> n >> m >> k >> ds;
	//节点下标输入从1开始 
	vector<vector<int>> dis(n + m, vector<int>(n + m, inf));
	for (int i = 0; i < k; i++) {
		string p1, p2;
		int d;
		cin >> p1 >> p2 >> d;
		int n1=g2node(p1),n2=g2node(p2);
		if(p1==p2){
			dis[n1][n2] = 0;
		}
		else{
			dis[n1][n2] = d<dis[n1][n2]?d:dis[n1][n2];
			dis[n2][n1] = d<dis[n2][n1]?d:dis[n2][n1];
		}

	}
	vector<int> dissum(m, inf), min(m, inf);
	for (int i = n; i < n + m; i++) {
		vector<int> mindis(n + m, inf), visited(n + m, 0);
		mindis[i] = 0;
		int sum = 0;
		while (1) {
			int mind = inf, minu=n+m;
			for (int j = 0; j < n + m; j++) {
				if (!visited[j] && mindis[j] < mind) {
					mind = mindis[j];
					minu = j;
				}
			}
			if (mind == inf)	break;
			visited[minu] = 1;
			if (minu < n) {
				if (mindis[minu] > ds) {
					sum = inf;
					////
					min[i - n] = 0;
					break;
				}
				else {
					sum += mindis[minu];
					min[i - n] = mindis[minu] < min[i - n] ? mindis[minu] : min[i - n];
				}
			}
			
			for (int j = 0; j < n + m; j++) {
				if (!visited[j] && dis[minu][j] != inf) {
					if (mindis[j] > mindis[minu] + dis[minu][j]) {
						mindis[j] = mindis[minu] + dis[minu][j];
					}
				}
			}
		}
		dissum[i - n] = sum;
	}
	//与房屋的最小距离越大越好，与所有房屋平均距离最小
	int maxdd = 0, mings;
	for (int i = 0; i < m; i++) {
		if (maxdd < min[i]) {
			maxdd = min[i];
			mings = i;
		}
		else if (maxdd == min[i]&&maxdd!=inf) {
			if (dissum[i] < dissum[mings]) {
				maxdd = min[i];
				mings = i;
			}
		}
	}
	if(dissum[mings]!=inf)
		printf("G%d\n%.1f %.1f", mings + 1, min[mings]*1.0, dissum[mings] * 1.0  / n);
	else    printf("No Solution");
	return 0;
}
