#include <bits/stdc++.h>
using namespace std;
int n,m;
queue <int> q;
int main()
{
	scanf("%d%d",&n,&m);
	vector <queue<int> > a(m);
	vector <vector<int> > mem(n);
	for(int i=0;i<m;i++){
		int k;
		scanf("%d",&k);
		for(int j=0;j<k;j++){
			int ar;
			scanf("%d",&ar);
			a[i].push(ar-1);
		}
		mem[a[i].front()].push_back(i);
	}
	/*
		cout<<"\n----------\n";
		for(int i=0;i<a.size();i++) {
			cout<<"i-> " <<i<<",";
			cout<<"a[i] front-> " <<a[i].front()<<",";
			cout<<"a[i] back-> " <<a[i].back();
			cout<<endl;
		}
		for(int i=0;i<mem.size();i++){
			cout<<"i-> " <<i<<": ";
			for(int j=0;j<mem[i].size();j++) cout<<mem[i][j]<<" ";
			cout<<endl;
		}
	*/
    for(int i=0;i<n;i++){
		if(mem[i].size()==2){
			q.push(i);
		}
	}
	/*
		if(!q.empty()){
			cout<<"q front-> " <<q.front()<<",";
			cout<<"q back-> " <<q.back()<<" ";
		}
		cout<<"\n----------\n";
    */
	while(!q.empty()){
		int pos=q.front();
		q.pop();
		for(auto p:mem[pos]){
			a[p].pop();
			if(!a[p].empty()){
				mem[a[p].front()].push_back(p);
				if(mem[a[p].front()].size()==2){
					q.push(a[p].front());
				}
			}
		}
	}
	for(auto p:a){
		if(!p.empty()){
			printf("No");
			return 0;
		}
	}
	printf("Yes");
	return 0;
}