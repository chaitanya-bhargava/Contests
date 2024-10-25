#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define _sort(x) sort(x.begin(), x.end())
const int mod= 1e9+7;

void helper(int & c,int & b,int & a, string & s, int & n)
{
    if(s.size() ==n)
    {
        cout<<s<<endl;
        return;
    }
    if(b>0){
        s.push_back('B');
        b--;
        helper(c,b,a,s,n);
        b++;
        s.pop_back();
    }
    if(c>0){
        s.push_back('C');
        c--;
        helper(c,b,a,s,n);
        c++;
        s.pop_back();
    }
    if(a>0){
        s.push_back('A');
        a--;
        helper(c,b,a,s,n);
        a++;
        s.pop_back();
    }
}
int main()
{
    int n;
    cin>> n;
    int b,c,a;
    cin>>b>>c>>a;
    if(n>(a+b+c)) return 0;
    string s;
    helper(c,b,a,s,n);
    return 0;
}