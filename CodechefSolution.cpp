// video https://youtu.be/0jWeUdxrGm4
// problem https://www.spoj.com/problems/RMQSQ/
#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 100'005;
const int LOG = 17;
int a[MAX_N];
int maxArray[MAX_N][LOG]; // maxArray[i][j] is maximum among a[i..i+2^j-1]
int minArray[MAX_N][LOG]; // minArray[i][j] is minimum among a[i..i+2^j-1]
int bin_log[MAX_N];

int maxQuery(int L, int R) { // O(1)
	int length = R - L + 1;
	int k = bin_log[length];
    return max(maxArray[L][k], maxArray[R-(1<<k)+1][k]);
}

int minQuery(int L, int R) { // O(1)
	int length = R - L + 1;
	int k = bin_log[length];
	return min(minArray[L][k], minArray[R-(1<<k)+1][k]);
}

int main() {
	// 1) read input
	int n,q;
	cin >> n;
	bin_log[1] = 0;
	for(int i = 2; i <= n; i++) {
		bin_log[i] = bin_log[i/2]+1;
	}
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		minArray[i][0] = a[i];
        maxArray[i][0] = a[i];
	}
	// 2) preprocessing, O(N*log(N))
	for(int k = 1; k < LOG; k++) {
		for(int i = 0; i + (1 << k) - 1 < n; i++) {
			minArray[i][k] = min(minArray[i][k-1], minArray[i+(1<<(k-1))][k-1]);
            maxArray[i][k] = max(maxArray[i][k-1], maxArray[i+(1<<(k-1))][k-1]);
		}
	}
    // for(int i=0;i<n;i++) cout<<i+1<<":"<<a[i]<<", ";
    // cout<<endl;
	// 3) answer queries
    cin>>q;
	for(int i = 0; i < q; i++) {
		int L, R;
		cin >> L >> R;
        // cout << maxQuery(L, R) << " ";
        // cout << minQuery(L, R) << "\n";
        int m=0,M=0,M2=-1;
        m=minQuery(L,R);
        M=maxQuery(L,R);
        if(L>0) M2=maxQuery(0,L-1);
        if(R<n-1) M2=max(M2,maxQuery(R+1,n-1));
        float ans=(float)(m)+max((float)((float)(M-m)/2),(float)(M2));
        cout<<fixed<<setprecision(1)<<ans<<"\n";
	}   
}
/*
36
3 4 2 1 5 7 9 7 10 5 12 3 1 1 2 1 3 2 7 14 2 11 5 7 9 4 1 5 12 3 11 11 23 12 3 1
52
4 10
14 17
1 16
1 2
1 8
5 8
9 14
9 9
1 1
6 7
8 8
4 7
5 13
1 12
1 4
5 9
9 10
9 9
1 5
6 17
8 15
4 10
4 17
12 16
11 12
1 17
5 17
9 17
9 11
1 10
6 8
8 10
4 9
15 15
1 14
3 4
15 16
9 16
9 17
1 15
1 11
8 17
24 29
25 35
1 34
3 14
15 36
9 36
2 7
1 25
1 21
8 13
O/P:
9.0
13.0
6.5
14.0
13.0
19.0
11.0
17.0
16.0
19.0
22.0
17.0
6.5
6.5
13.0
17.0
15.0
17.0
13.0
8.0
10.0

*/