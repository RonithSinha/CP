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
#include<utility>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

typedef long long int ll;
typedef unsigned long long int ull;

using namespace __gnu_pbds;
using namespace std;

typedef 
    tree<ll,
    null_type,
    less<ll>,
    rb_tree_tag,
    tree_order_statistics_node_update>
orderedList;

ll solveIndividual(vector<ll>elements,map<ll,deque<ll>> integerIndicesMapping){
  deque<ll> elementPosition;
  vector<ll> track;
  ll ans=0;
  for(ll i=elements.size()-1;i>=0;i--){
    elementPosition.push_front(integerIndicesMapping[elements[i]].front());
    integerIndicesMapping[elements[i]].pop_front();
  }
  for(ll i=0;i<elementPosition.size();i++){
    for(ll j=0;i<track.size();j++) if(track[j]<elementPosition[i]) ans++;
  }
  return ans;
}

void solve() {
  ll n,m,num;
  cin>>n>>m;
  vector<vector<ll>> indexValueVector;
  for(ll i=0;i<n*m;i++) {
    cin>>num;
    indexValueVector.push_back({num,i});
  }
  // for(int i=0;i<n*m;i++) {
  //   for(int j=0;j<indexValueVector[i].size();j++) cout<<indexValueVector[i][j]<<" ";
  //   cout<<endl;
  // }
  sort(indexValueVector.begin(),indexValueVector.end(),[](vector<ll>& v1, vector<ll>& v2){
    if(v1[0]!=v2[0]) return v1[0]<v2[0];
    return v1[1]>v2[1];
  });
  for(int i=0;i<n*m;i++) {
    for(int j=0;j<indexValueVector[i].size();j++) cout<<indexValueVector[i][j]<<" ";
    cout<<endl;
  }
  orderedList track;
  ll ans=0,count=0;
  map<ll,ll> countMapping;
  for(ll i=0;i<n;i++) {
    
  }
  cout<<ans;  
}

int main() {
    int t=1;
    cin>>t;
    
    while(t--){
        cout<<"yes";
        cout<<"\n";
    }
	return 0;
}
/*

*/