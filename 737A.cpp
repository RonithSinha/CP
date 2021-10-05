#include<iostream>
#include<iomanip>
#include<numeric>
#include<algorithm>


using namespace std;
int main(int argc, char const *argv[])
{
    /* code */
    int t;
    cin>>t;
    while(t--){
        long long int  n;
        cin>>n;
        long long int  a[n];
        for(long long int  i=0;i<n;i++) cin>>a[i];
        sort(a,a+n);
        long long int sum=0;
        sum=accumulate(a,a+n,sum);
        sum=sum-a[n-1];
        long double ans=(long double)(sum)/(long double)(n-1)+(long double)(a[n-1]);
        cout<<fixed<<setprecision(9)<<ans<<"\n";
    }
    return 0;
}
