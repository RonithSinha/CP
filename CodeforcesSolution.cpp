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

string solve() {
  ll n,x;
  cin>>n>>x;
  ll a[n],b[n];
  for(ll i=0;i<n;i++){
    cin>>a[i];
    b[i]=a[i];
  }
  sort(a,a+n);
  for(ll i=0;i<n;i++){
    //printf("%lld %lld %lld %lld\n",abs(a[i]-a[0]),abs(a[i]-a[n-1]),b[i],a[i]);
    if(abs(a[i]-a[0])<x&&abs(a[i]-a[n-1])<x&&a[i]!=b[i]) return "NO";
  }
  return "YES";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    cin>>t;
    while(t--){
        cout<<solve();
        cout<<"\n";
    }
	return 0;
}
/*
3
2 4
3 7
2 6
4 2
3 11
2 1 7

1
6 4
8 2 2 7 4 5

1
5 4
5 8 7 8 4

4
3 3
3 2 1
4 3
1 2 3 4
5 2
5 1 2 3 4
5 4
1 2 3 4 4

1
5 3
4 5 8 7 8

*/