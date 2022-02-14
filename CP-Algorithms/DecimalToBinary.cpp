#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

// function to convert decimal to binary
vector<int> decToBinary(int n)
{
    vector<int> ans;
    for (int i = 31; i >= 0; i--) {
        int k = n >> i;
        if (k & 1)
            ans.push_back(1);
        else
            ans.push_back(0);
    }
    // for(int i=0;i<ans.size();i++) cout<<ans[i]<<" ";
    // cout<<endl;
    return ans;
}



int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
