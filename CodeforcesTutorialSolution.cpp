#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<int>a(n),b(n);
    map<int,int>mp;
    for(int i=0;i<n;i++) cin>>a[i],b[i]=a[i],mp[a[i]]=0;
    sort(b.rbegin(),b.rend());
    int j=0;
    vector<int>c;
    for(int i=n-1;i>=0;i--){
        if(a[i]!=b[j]) c.push_back(a[i]),mp[a[i]]=1;
        else{
            c.push_back(a[i]);
            mp[a[i]]=1;
            for(int j=(int)c.size()-1;j>=0;j--){
                cout<<c[j]<<" ";
            }
            while(mp[b[j]]==1) j++;
            c.clear();
        }
    }
    for(int j=(int)c.size()-1;j>=0;j--){
        cout<<c[j]<<" ";
    }
    cout<<"\n";
}
                
int main(){
    int t=1;
    cin>>t;
    for(int i=1;i<=t;i++){
        // cout<<"Case #"<<i<<": ";
        solve();
    }
    return 0;
}