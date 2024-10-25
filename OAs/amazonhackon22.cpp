#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,k;
    cin>>n>>k;
    vector<int> p(n);
    for(int i=0;i<n;i++){
        cin>>p[i];
        if(p[i]%2==0) p[i]--;
    }
    int sum=0;
    int maxsum=0;
    int dist=0;
    unordered_map<int,int> m;
    for(int i=0;i<k;i++){
        sum+=p[i];
        if(m[p[i]]==0) dist++;
        m[p[i]]++;
    }
    if(dist == k) maxsum=sum;

    for(int i=k;i<n;i++){
        m[p[i-k]]--;
        if(m[p[i-k]] == 0) dist--;
        sum+=p[i];
        sum-=p[i-k];
        if(m[p[i]]==0) dist++;
        m[p[i]]++;
        if(dist == k)
        maxsum=max(maxsum, sum);
    }
    cout<<maxsum<<endl;
    return 0;
}