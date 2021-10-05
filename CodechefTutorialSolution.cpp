#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<iomanip>
#include<math.h>
#include<limits.h>

using namespace std;


struct tree{
	vector<int> ans_min;
	vector<int> ans_max;
	tree(int n, vector<int> &length){
		ans_min.resize(1000000);
		ans_max.resize(1000000);
		for(int i = 0; i < n; i++){
			update(0, i, length[i], 0, n - 1);
		}
	}
	void update(int index, int change_index, int change, int curr_l, int curr_r){
		if(change_index < curr_l) return ;
		if(change_index > curr_r) return ;
		if(curr_l == curr_r){
			ans_min[index] = change;
			ans_max[index] = change;
			return;
		}
		int mid = (curr_l + curr_r) / 2;
		update(2 * index + 1, change_index, change, curr_l, mid);
		update(2 * index + 2, change_index, change, mid + 1, curr_r);
		ans_min[index] = min(ans_min[2 * index + 1], ans_min[2 * index + 2]);
		ans_max[index] = max(ans_max[2 * index + 1], ans_max[2 * index + 2]);
	}

	pair<int, int> get(int index, int curr_l, int curr_r, int l, int r){
		if(curr_r < l){
			return {INT_MAX, INT_MIN};
		}
		if(r < curr_l){
			return {INT_MAX, INT_MIN};
		}
		if(curr_l >= l && curr_r <= r){
			return {ans_min[index], ans_max[index]};
		}
		int mid = (curr_l + curr_r) / 2;
		pair<int, int> first = get(2 * index + 1, curr_l, mid, l, r);
		pair<int, int> second = get(2 * index + 2, mid + 1, curr_r, l, r);
		return {min(first.first, second.first), max(first.second, second.second)};
	}
};

int main(){
	int n;
	cin>>n;
	vector<int> arr(n);
	for(int i = 0; i < n; i++){
		cin>>arr[i];
	}
	tree t1(n, arr);
	int q;
	cin>>q;
	for(int i = 0; i < q; i++){
		int l, r;
		cin>>l>>r;
		pair<int, int> a = t1.get(0, 0, n - 1, l, r);
		double another_max = double(a.second - a.first) / 2;
		int temp_max = -1;
		if(l > 0){
			pair<int, int> b = t1.get(0, 0, n - 1, 0, l - 1);
			temp_max = max(temp_max, b.second);
		}
		if( r < n - 1){
			pair<int, int> b = t1.get(0, 0, n - 1, r + 1, n - 1);
			temp_max = max(temp_max, b.second);
		}
		double answer = a.first + another_max;
		if(a.first + temp_max > answer){
			answer = a.first + temp_max;
		}
		cout<<fixed<<setprecision(1)<<answer<<endl;
	}
	return 0;
}


/*
	*/