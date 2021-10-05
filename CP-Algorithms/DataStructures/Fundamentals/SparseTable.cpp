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
	cin >> n >> q;
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
    for(int i=0;i<n;i++) cout<<i+1<<":"<<a[i]<<", ";
    cout<<endl;
	// 3) answer queries
	for(int i = 0; i < q; i++) {
		int L, R;
		cin >> L >> R;
        L--;
        R--;
		cout << maxQuery(L, R) << " ";
        cout << minQuery(L, R) << "\n";
	}
}
/*
17 8
2 3 5 4 2 1 6 8 1 8 4 6 9 6 12 15 1
3 9
12 15
4 16
3 15
1 5
14 16
3 5
2 2
*/