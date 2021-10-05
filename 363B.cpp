#include<iostream>
#include<climits>
using namespace std;

int main(int argc, char const *argv[])
{
    /* code */
    int n,k;
    cin>>n>>k;
    int a[n+1];
    a[0]=0;
    for(int i=1;i<=n;i++) cin>>a[i];
    int ans=INT_MAX,index=0;
    for(int i=1;i<=n;i++){
        a[i]+=a[i-1];
        if(i>=k&&a[i]-a[i-k]<ans){
            index=i-k+1;
            ans=a[i]-a[i-k];
        }
        //printf("%d %d\n",a[i],ans);
    }
    cout<<index<<"\n";
    return 0;
}