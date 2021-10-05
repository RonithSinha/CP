#include<iostream>
#include<algorithm>
#include<vector>
#include<list>
#include<deque>
#include<map>
#include<set>
#include<iterator>
#include<climits>
#include<cmath>

typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;

void solve() {
    int n,x,y,a,b;
    cin>>n>>x>>y;
    vector<vector<int>> elements(n,vector<int> (2,0));
    for(int i=0;i<n;i++) {
        cin>>a>>b;
        elements[i][0]=a;
        elements[i][1]=b;
    }
    int countA=0,countB=0;
    sort(elements.begin(),elements.end(),[&](vector<int>& a,vector<int>& b){
        if(countA>=x){
            return a[1]>b[1];
        }
        countA+=a[0];
        if(a[0]!=b[0]) return a[0]>b[0];
        return a[1]>b[1];
    });
    for(int i=0;i<n;i++) {
        cout<<elements[i][0]<<" "<<elements[i][1]<<endl;
    }
    sort(elements.begin(),elements.end(),[](vector<int>& a,vector<int>& b){
        if(a[0]!=b[0]) return a[0]<b[0];
        return a[1]<b[1];
    });
    for(int i=0;i<n;i++) {
        cout<<elements[i][0]<<" "<<elements[i][1]<<endl;
    }
    
}

int main() {
    int t=1;
    //cin>>t;
    while(t--){
        solve();
        //cout<<"\n";
    }
	return 0;
}