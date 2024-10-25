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
 

vector<string> canDeleteSubstring(vector<string> given_strings){
    vector<string> result;
    string target = "programming";
    for(auto &str : given_strings){
        int i = 0, j = 0;
        // Find the first matching character in the given string
        while(i < str.size() && str[i] != target[j]) i++;
        // If no matching character found, print "No"
        if(i == str.size()){
            result.push_back("No");
            continue;
        }
        // Find the last matching character in the given string
        int k = str.size() - 1;
        while(k > i && str[k] != target.back()) k--;
        // Check if the substring between the first and last matching characters contains all characters of "programming"
        string sub = str.substr(i, k - i + 1);
        int m = 0, n = 0;
        int flag=0;
        while(m < sub.size() && n < target.size()){
            if(sub[m] == target[n]) n++;
            else flag=1;
            m++;
        }
        // If all characters of "programming" are found in order, print "Yes", else print "No"
        if((flag==1 && i!=0) || (flag==1 && k!=str.size()-1) || (i!=0 && k!=str.size()-1)){
            result.push_back("No");
            continue;
        }
        if(n == target.size()) result.push_back("Yes");
        else result.push_back("No");
    }
    return result;
}

int main(){
    int t;
    cin>>t;
    vector<string> arr;
    for(int i=0;i<t;i++){
        string s;
        cin>>s;
        arr.push_back(s);
    }
    vector<string> res=canDeleteSubstring(arr);
    for(int i=0;i<res.size();i++){
        cout<<res[i]<<endl;
    }
    return 0;
}