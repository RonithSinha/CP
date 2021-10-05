#include<iostream>
#include<algorithm>

using namespace std;
int main(int argc, char const *argv[])
{
    /* code */
    int ans=0;
    int n;
    cin>>n;
    int a[n];
    int buffer[]={0,0,0,0,0};
    for(int i=0;i<n;i++) cin>>a[i];
    sort(a,a+n);
    for(int i=0;i<n;i++) buffer[a[i]]++;
    for(int i=0;i<n;i++) printf("%d ",a[i]);
    printf("\n");
    int current=4;
    for(int i=0;i<n;i++){
        if(buffer[a[i]]>0){
            buffer[a[i]]--;
            if(current+a[i]<=4){
                current+=a[i];
            }
            else{
                bool found=false;
                for(int j=4-a[i];j>0;j--){
                    if(buffer[j]>0){
                        found=true;
                        printf("found %d for %d\n",j,a[i]);
                        buffer[j]--;
                        current=a[i]+j;
                        ans++;
                        break;
                    }
                }
                if(!found){
                    current=a[i];
                    ans++;
                }
            }
            printf("%d %d %d\n",a[i],ans,current);
        }
        
    }
    //for(int i=0;i<=4;i++) printf("%d ",buffer[i]);
    cout<<ans<<"\n";
    return 0;
}