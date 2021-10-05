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
#include <experimental/random>
#include <fstream>

typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;

void GenerateTestCases(){
    ofstream newFile;
    newFile.open("AtCoderABC216-TestCases-D.txt",ios_base::app);
    newFile<<"------------\n";
    
    int n=100000;
    int m=experimental::randint(30000,n-1);
    vector<deque<int>> cylinders(m);
    newFile<<n<<" ";
    for(int i=0;i<n;i++){
        vector<int> randomIntegerChoices;
        int selectedIndex=experimental::randint(2,m-1);
        for (int i = 0; i < m; i++) if(i!=selectedIndex) randomIntegerChoices.push_back(i);
        int secondIntegerIndex= rand()%randomIntegerChoices.size();
        int selectedIndex2=randomIntegerChoices[secondIntegerIndex];
        cylinders[selectedIndex].push_front(i+1);
        cylinders[selectedIndex2].push_front(i+1);
    }
    int cylinderSize=0;
    for(int i=0;i<cylinders.size();i++) if(cylinders[i].size()>0) cylinderSize++;
    newFile<<cylinderSize<<endl;
    for(int i=0;i<cylinders.size();i++){
        if(cylinders[i].size()>0) {
            newFile<<cylinders[i].size()<<endl;
            for(int j=0;j<cylinders[i].size();j++) newFile<<cylinders[i][j]<<" ";
            newFile<<endl;
        }
    }
    newFile.close();
}
int main() {
    GenerateTestCases();
	return 0;
}