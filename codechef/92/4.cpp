#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int w,l;
        cin>>w>>l;
        int flag=0;
        int tempw=w;
        int templ=l;
        while(tempw>0){
            if((tempw+templ)%2==1 && (w-tempw+templ)%2==1){
                flag=1;
                break;
            }
            else{
                tempw/=2;
            }
        }
        if(flag==1){
            cout<<"YES"<<endl;
            continue;
        }
        while(templ>0){
            if((tempw+templ)%2==1 && (l-templ+tempw)%2==1){
                flag=1;
                break;
            }
            else{
                templ/=2;
            }
        }
        if(flag==1){
            cout<<"YES"<<endl;
        }
        else cout<<"NO"<<endl;
    }
    return 0;
}