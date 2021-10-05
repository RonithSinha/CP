#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int main(int argc, char const *argv[])
{
    /* code */
    int n;
    cin>>n;
    vector<int> s;
    int num=0;
    for(int i=0;i<n;i++){
        cin>>num;
        s.push_back(num);
    }
    sort(s.begin(),s.end());
    int q;
    cin>>q;
    int cost;
    for (int i = 0; i < q; i++)
    {
        /* code */
        cin>>cost;
        auto upper=upper_bound(s.begin(),s.end(),cost);
        cout<<(upper-s.begin())<<"\n";
    }
    return 0;
}
