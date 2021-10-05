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

ll calcMinCount(ll m,ll x){
    ll k=1;
    while(m/x&&m%x==0) {
        k++;
        m/=x;
    }
    return k;
}

void solve() {
    ull l,r;
    cin>>l>>r;
    if(r-l<2) cout<<-1;
    else if(r-l>2||l%2==0) cout<<l+l%2<<" "<<l+1+l%2<<" "<<l+2+l%2;
    else cout<<-1;
}

int main() {
    int t=1;
    //cin>>t;
    
    while(t--){
        solve();
        cout<<"\n";
    }
	return 0;
}
/*
900000000000000009 900000000000000029
9000000000000000010 900000000000000029

*/