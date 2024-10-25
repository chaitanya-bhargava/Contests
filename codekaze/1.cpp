#include<bits/stdc++.h>
using namespace std;

long long contributions(int n, vector<int> &a) {
    vector<vector<int>> rem(3);
    for(int i=0;i<n;i++){
        rem[a[i]%3].push_back(a[i]);
    }
    long long ans=0;
    for(int i=0;i<3;i++){
        for (int j = 0; j < 32; j++)
    {
        int zc = 0, oc = 0;
        long long idsum = 0;
        for (int k = 0; k < rem[i].size(); k++)
        {
            if (rem[i][k] % 2 == 0)
                zc++;
            else
                oc++;
            rem[i][k] /= 2;
        }
        idsum = oc * zc * (1 << j);   
        ans += idsum;
    }
    }
    return ans;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        cout<<contributions(n,a)<<endl;
    }
    return 0;
}