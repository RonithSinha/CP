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
#define NIL -1

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

ll solve() {
    ll n, l = 0;
    cin >> n;
    ll p[n + 5], d[n + 5];
    for (ll i = 0; i < n; i++) {
        cin >> p[i];
        d[i] = p[i];
    }
    if (n == 3){
        if (p[1] % 2 == 1) return -1;
        return p[1] / 2;
    }
    bool ans = true;
    for (ll i = 1; i < n - 1; i++) if (p[i] > 1) ans = 0;
    if (ans) return -1;
    for (ll i = 1; i < n - 1; i++) l += (p[i] + 1) / 2;
    return l;
}

int main() {
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    int t=1;
    cin>>t;
    while(t--){
        //solve();
        cout<<solve();
        cout<<"\n";
    }
	return 0;
}
/*

*/