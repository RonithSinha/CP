#include<iostream>
#include<array>
#include<algorithm>
#include<map>

using namespace std;

int main(int argc, char const *argv[])
{
    /* code */
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        int a[n];
        for(int i=0;i<n;i++) cin>>a[i];
        int sortedArray[n] = {};
        copy(a,a+n,sortedArray);
        sort(sortedArray,sortedArray+n);
        map<int,int> elementLocationMapping;
        for (int i = 0; i < n; i++) elementLocationMapping[sortedArray[i]]=i;
        int count=0;
        for (int i = 0; i < n; i++) {
            if(elementLocationMapping[a[i]]>0&&i>0&&sortedArray[elementLocationMapping[a[i]]-1]==a[i-1]) continue;
            else count++;
        }
        if(count>k) cout<<"NO\n";
        else cout<<"YES\n";
    }
    return 0;
}
