#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    LRUCache c1(n); //LRUCache is class
    int c;
    cin>>c;
    for(int i=0;i<c;i++){
        string op;
        cin>>op;
        if(op=="PUT"){
            string delim;
            int key,value;
            cin>>key>>delim>>value;
            c1.put(key,value); 
        }
        else if(op=="GET"){
            int key;
            cin>>key;
            c1.get(key);
        }
    }
    return 0;
}