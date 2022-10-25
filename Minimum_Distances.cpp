#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    unordered_map<int, int> m;
    int minD = INT_MAX;
    int x;
    for(int i=0;i<n;i++){
        cin>>x;
        if(m.find(x)!=m.end()){
            minD = min(minD,i - m[x]);
        }

        m[x] = i;
    }
    if(minD == INT_MAX)
        minD = -1;
    cout<<minD;
}
