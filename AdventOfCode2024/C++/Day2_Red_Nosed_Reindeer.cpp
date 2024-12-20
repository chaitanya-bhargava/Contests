#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define V vector
#define pb push_back
#define pf push_front
#define qb pop_back
#define qf pop_front
#define eb emplace_back
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
#define fi first
#define se second
#define _F(i, a, b) for (int i = a; i <= b; i++)
#define _FR(i, a, b) for (int i = a; i >= b; i--)
#define IF(a,b,c) ((a)?(b):(c));
#define _sort(x) sort((x).begin(),(x).end());
const int inf = 0x3f3f3f3f, mod = 1e9 + 7;
const ll infl = 0x3f3f3f3f3f3f3f3fll;
 
const int n=1000;

//A
// int main(){
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     vector<string> reports(n);
//     vector<vector<int>> arr(n);
//     for(int i=0;i<n;i++){
//         getline(cin,reports[i]);
//         stringstream ss(reports[i]); 
//         string word; 
//         while(ss>>word){
//             arr[i].push_back(stoi(word));
//         }
//     }
//     long long res=0;
//     for(int i=0;i<n;i++){
//         bool inc=true;
//         bool dec=true;
//         bool gap=true;
//         for(int j=1;j<arr[i].size();j++){
//             if(arr[i][j]<arr[i][j-1]) inc=false; 
//             if(arr[i][j]>arr[i][j-1]) dec=false; 
//             if(abs(arr[i][j]-arr[i][j-1])<1 || abs(arr[i][j]-arr[i][j-1])>3){
//                 gap=false;
//                 break;
//             } 
//         }
//         if(gap && (inc || dec)) res++;
//     }
//     cout<<res<<endl;
//     return 0;
// }

//B
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<string> reports(n);
    vector<vector<int>> arr(n);
    for(int i=0;i<n;i++){
        getline(cin,reports[i]);
        stringstream ss(reports[i]); 
        string word; 
        while(ss>>word){
            arr[i].push_back(stoi(word));
        }
    }
    long long res=0;
    for(int i=0;i<n;i++){
        for(int skip=0;skip<arr[i].size();skip++){
            int left=0;
            int right=1;
            if(skip==0){
                bool inc=true;
                bool dec=true;
                bool gap=true;
                for(int j=2;j<arr[i].size();j++){
                    if(arr[i][j]<arr[i][j-1]) inc=false; 
                    if(arr[i][j]>arr[i][j-1]) dec=false; 
                    if(abs(arr[i][j]-arr[i][j-1])<1 || abs(arr[i][j]-arr[i][j-1])>3){
                        gap=false;
                        break;
                    } 
                }
                if(gap && (inc || dec)){
                    res++;
                    break;
                }
            }
            else if(skip==arr[i].size()-1){
                bool inc=true;
                bool dec=true;
                bool gap=true;
                for(int j=1;j<arr[i].size()-1;j++){
                    if(arr[i][j]<arr[i][j-1]) inc=false; 
                    if(arr[i][j]>arr[i][j-1]) dec=false; 
                    if(abs(arr[i][j]-arr[i][j-1])<1 || abs(arr[i][j]-arr[i][j-1])>3){
                        gap=false;
                        break;
                    } 
                }
                if(gap && (inc || dec)){
                    res++;
                    break;
                }
            }
            else{
                bool inc=true;
                bool dec=true;
                bool gap=true;
                while(right<arr[i].size()){
                    if(right==skip) right++;
                    if(left==skip) left++;
                    if(arr[i][left]<arr[i][right]) dec=false;
                    if(arr[i][left]>arr[i][right]) inc=false;
                    if(abs(arr[i][left]-arr[i][right])<1 || abs(arr[i][left]-arr[i][right])>3){
                        gap=false;
                        break;
                    }
                    left++;
                    right++;
                }
                if(gap && (inc || dec)){
                    res++;
                    break;
                }
            }
        }
    }
    cout<<res<<endl;
    return 0;
}