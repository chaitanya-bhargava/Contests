#include <bits/stdc++.h>
using namespace std;

int main() {
    int a,b;
    cin>>a>>b;
    vector<vector<int>> C(b,vector<int> (3));
    for(int i=0;i<b;i++){
        int x,y,w;
        cin>>x>>y>>w;
        C[i]={x,y,w};
    }
    solve()
    return 0;
}
