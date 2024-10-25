#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;
    if(n%2==1){
        cout<<-1<<endl;
        return 0;
    }
    string ans="";
    int i=0;
    int j=0;
    vector<vector<int>> grid(n,vector<int> (n));
    int count=0;
    for(int i=0;i<n-1;i++){
        grid[0][i]=count;
        count=(count+1)%n;
        ans.push_back('R');
    }
    grid[0][n-1]=count;
    count=(count+1)%n;
    ans.push_back('D');
    for(int j=n-1;j>=0;j-=2){
        for(int i=1;i<n;i++){
            grid[i][j]=count;
            count=(count+1)%n;
            if(i!=n-1) ans.push_back('D');
        }
        ans.push_back('L');
        for(int i=n-1;i>=1;i--){
            grid[i][j-1]=count;
            count=(count+1)%n;
            if(i!=1) ans.push_back('U');
        }
        if(j!=1) ans.push_back('L');
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<grid[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    ans.push_back('U');
    cout<<ans<<endl;
    return 0;
}