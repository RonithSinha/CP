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
#include<unistd.h>

typedef long long int ll;
typedef unsigned long long int ull;
using namespace std;

deque<int> trace;
int startRow=0,destRow=0,startCol=0,destCol=0,count=0;
map<int,bool> visited;
map<int,vector<int>> ans;

bool checkIfElementPresent(int element) { //check if element is already present in the stack
    if(!ans[element].empty()&&::count<10) {
        //cout<<element<<endl;
        //cout<<"reached -->>>>>";
        for(int i=trace.size()-1;i>=0;i--) cout<<trace[i]<<" ";
        for(int i=0;i<ans[element].size();i++) cout<<ans[element][i]<<" ";
        cout<<"\n";
        (::count)++;
        return true;
    }
    return visited[element];
}

bool checkIfMoveValid(int currRow,int currCol, int parentRow, int parentCol,int nextRowMove,int nextColMove){
    //for(int i=1;i<trace.size();i++) if(trace[i]==(currRow-1)*8+currCol) {return false;}
    if(currRow+nextRowMove<=8&&currRow+nextRowMove>=1&&currCol+nextColMove<=8&&currCol+nextColMove>=1&&!(currRow+nextRowMove==parentRow&&currCol+nextColMove==parentCol)&&!checkIfElementPresent((currRow+nextRowMove-1)*8+currCol+nextColMove)) return true;
    //cout<<(currRow-1)*8+currCol<<endl;
    return false;
}

void printPath(int currRow,int currCol, int parentRow, int parentCol){
    //  printf("%d %d %d %d %d %d\n", currRow,currCol,::count,count1,parentRow,parentCol);
    //  for(int i=trace.size()-1;i>=0;i--) cout<<trace[i]<<" ";
    // cout<<"\n";
    // if((currRow-1)*8+currCol==62) count1++;
    // if(count1>1) {
    //     cout<<"62 spotted again\n";
    //     printf("%d %d %d %d %d %d\n", currRow,currCol,::count,count1,parentRow,parentCol);
    //     for(int i=trace.size()-1;i>=0;i--) cout<<trace[i]<<" ";
    //     cout<<"\n";
    //     cout<<checkIfElementPresent(62)<<endl;
    //     sleep(10);
    //     return;
    // }
    //sleep(5);
    //if(count1>100) return;
    //count1++;
    if(::count>=10) return;
    if(currRow==destRow&&currCol==destCol) {
        //cout<<"reached destination->>>>>>>";
        trace.push_front((currRow-1)*8+currCol); //pushing the current element at the top of the stack.
        for(int i=trace.size()-1;i>=0;i--) cout<<trace[i]<<" ";
        cout<<"\n";
        for(auto it=trace.rbegin();it!=trace.rend();it++){
            if(ans[*it].empty()) ans[*it].assign(it,trace.rend());
        }
        // for(int i=0;i<=64;i++) {cout<<i<<"----->"; for(auto it=ans[i].begin();it!=ans[i].end();it++) cout<<*it<<" "; cout<<endl;}
        trace.pop_front(); //removing the current element from the top of the stack.
        (::count)++;
        //cout<<::count<<endl;
        //sleep(10);
        return;
    }
    trace.push_front((currRow-1)*8+currCol);
    visited[(currRow-1)*8+currCol]=true;
    //cout<<"pushed\n";
    //cout<<trace.front()<<endl;
    //cout<<trace.size()<<endl;

    // checkIfMoveValid(currRow,currCol,parentRow,parentCol,2,1);
    // checkIfMoveValid(currRow,currCol,parentRow,parentCol,1,2);
    // checkIfMoveValid(currRow,currCol,parentRow,parentCol,2,-1);
    // checkIfMoveValid(currRow,currCol,parentRow,parentCol,1,-2);
    // checkIfMoveValid(currRow,currCol,parentRow,parentCol,-1,2);
    // checkIfMoveValid(currRow,currCol,parentRow,parentCol,-1,-2);
    // checkIfMoveValid(currRow,currCol,parentRow,parentCol,-2,1);
    // checkIfMoveValid(currRow,currCol,parentRow,parentCol,-2,-1);
    
    if(checkIfMoveValid(currRow,currCol,parentRow,parentCol,2,1)) printPath(currRow+2,currCol+1,currRow,currCol);
    if(checkIfMoveValid(currRow,currCol,parentRow,parentCol,1,2)) printPath(currRow+1,currCol+2,currRow,currCol);
    if(checkIfMoveValid(currRow,currCol,parentRow,parentCol,2,-1)) printPath(currRow+2,currCol-1,currRow,currCol);
    if(checkIfMoveValid(currRow,currCol,parentRow,parentCol,1,-2)) printPath(currRow+1,currCol-2,currRow,currCol);
    if(checkIfMoveValid(currRow,currCol,parentRow,parentCol,-1,2)) printPath(currRow-1,currCol+2,currRow,currCol);
    if(checkIfMoveValid(currRow,currCol,parentRow,parentCol,-1,-2)) printPath(currRow-1,currCol-2,currRow,currCol);
    if(checkIfMoveValid(currRow,currCol,parentRow,parentCol,-2,1)) printPath(currRow-2,currCol+1,currRow,currCol);
    if(checkIfMoveValid(currRow,currCol,parentRow,parentCol,-2,-1)) printPath(currRow-2,currCol-1,currRow,currCol);
    visited[trace.front()]=false;
    trace.pop_front();

}

void solve() {
    int start,destination;
    cin>>start>>destination;
    if(start>64||start<1||destination>64||destination<1||start==destination) {
        cout<<"No paths possible\n";
        return;
    }
    startRow=(start-1)/8+1,startCol=(start-1)%8+1,destRow=(destination-1)/8+1,destCol=(destination-1)%8+1;
    printPath(startRow,startCol,-1,-1);
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

*/