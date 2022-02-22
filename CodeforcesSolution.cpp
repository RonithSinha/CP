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

void solve() {
    
}


int main() {
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    int t=1;
    //cin>>t;
    while(t--){
        solve();
        //cout<<solve();
        //cout<<"\n";
    }
	return 0;
}
/*
4 4
5 5 3 3
1 1 5 3
2 2 5 4
2 2 4 4
*/