/*
ǰ������ԭ���ú��� 
*/

#include <iostream>
#include <vector>
using namespace std;
int flag=0;//��� 
vector<int> pre,in;
void solve(int prel,int prer,int inl,int inr){
	//ע��ݹ����ǰ�ж��˳�������ʱ 
	if(inr<inl||flag)	return;
	int i=inl;
	while(in[i]!=pre[prel])	i++;
	solve(prel+1,prel+i-inl,inl,i-1);
	solve(prel+i-inl+1,prer,i+1,inr);
	if(flag==0){
		cout<<in[inl];
		flag=1;
	}
}
int main(){
	int n;
	cin>>n;
	pre.resize(n);in.resize(n);
	for(int i=0;i<n;i++)	scanf("%d",&pre[i]);
	for(int i=0;i<n;i++)	scanf("%d",&in[i]);
	solve(0,n-1,0,n-1);
	return 0;
} 
