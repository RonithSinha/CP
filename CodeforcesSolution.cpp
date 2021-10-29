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
#include<valarray>
#include<numeric>
#include<queue>
#include<stack>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

typedef long long int ll;
typedef unsigned long long int ull;

using namespace __gnu_pbds;
using namespace std;

typedef 
    tree<int,
    null_type,
    less<int>,
    rb_tree_tag,
    tree_order_statistics_node_update>
orderedList;

bool isMatch(string s, string p) {
  queue<int> track;
  bool star=false;
  for(int i=0;i<p.size();i++) {
    if(p[i]=='*') star=true;
    else {
      if(star){
        for(int j=0;j<s.size();j++){
          if(s[j]==p[j]) track.push(j);
        }
      }
    }
  }
}

void solve() {
  
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    //cin>>t;
    while(t--){
        //cout<<solve();
        solve();
        cout<<"\n";
    }
	return 0;
}
/*
5
2 6 1 5 9
3
4 1 9
*/