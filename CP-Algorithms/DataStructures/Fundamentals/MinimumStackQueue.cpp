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
#include<utility>
#include<valarray>
#include<stack>

using namespace std;

class modifiedStackDS {
    private:
        stack<pair<int,int>> modifiedStack;
    public:
        void push(int element) {
            int minimum=modifiedStack.empty()?element:min(element,modifiedStack.top().second);
            modifiedStack.push({element,minimum});
        }
        int pop(){
            int removedElement=modifiedStack.top().first;
            modifiedStack.pop();
            return removedElement;
        }
        int findMinimum(){
            return modifiedStack.top().second;
        }
        int getSize(){
            return modifiedStack.size();
        }
};

int main(int argc, char const *argv[])
{
    /*
        modifiedStackDS modifiedStack;
        modifiedStack.push(23);
        cout<<"Stack size after pushing 23: "<<modifiedStack.getSize()<<"\n";
        modifiedStack.push(34);
        cout<<"Stack size after pushing 34: "<<modifiedStack.getSize()<<"\n";
        cout<<"Minimum Element in stack: "<<modifiedStack.findMinimum()<<"\n";
        modifiedStack.push(78);
        cout<<"Stack size after pushing 78: "<<modifiedStack.getSize()<<"\n";
        modifiedStack.push(18);
        cout<<"Stack size after pushing 18: "<<modifiedStack.getSize()<<"\n";
        cout<<"Minimum Element in stack: "<<modifiedStack.findMinimum()<<"\n";
        int removedElement=modifiedStack.pop();
        cout<<"Stack size after popping: "<<modifiedStack.getSize()<<"\n";
        cout<<"Removed Element: "<<removedElement<<"\n";
        cout<<"Minimum Element in stack: "<<modifiedStack.findMinimum()<<"\n";
        modifiedStack.push(3);
        cout<<"Stack size after pushing 3: "<<modifiedStack.getSize()<<"\n";
        cout<<"Minimum Element in stack: "<<modifiedStack.findMinimum()<<"\n";
    */
    return 0;
}
