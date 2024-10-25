#include<bits/stdc++.h>
using namespace std;

class Compare {
public:
    bool operator()(pair<string,pair<int,string>> below, pair<string,pair<int,string>> above)
    {
        if (below.second.first < above.second.first) {
            return true;
        }
        else if (below.second.first == above.second.first
                 && below.second.second > above.second.second) {
            return true;
        }
 
        return false;
    }
};

vector<string> tokenize(string s, string del = " ")
{
    int start, end = -1*del.size();
    vector<string> final;
    do {
        start = end + del.size();
        end = s.find(del, start);
        final.push_back(s.substr(start, end - start));
    } while (end != -1);
    return final;
}

string maxFollow(vector<string> streams){
    map<string,pair<int,string>> mp;
    for(int i=0;i<streams.size();i++){
        vector<string> splits = tokenize(streams[i],"||");
        if(splits[3]!=""){
            mp[splits[0]].first++;
            mp[splits[0]].second=splits[2];
        }
        if(splits[4]!=""){
            mp[splits[4]].first++;
            mp[splits[4]].second=splits[2];
        }
    }
    priority_queue<pair<string,pair<int,string>>,vector<pair<string,pair<int,string>>>,Compare> pq;
    for(auto x:mp){
        pq.push({x.first,{x.second.first,x.second.second}});
    }
    if(pq.top().second.first==0) return "None";
    return pq.top().first;
}

int main(){
    int n;
    cin>>n;
    fflush(stdin);
    vector<string> streams;
    while(n--){
        string s;
        getline(cin,s);
        streams.push_back(s);
    }
    cout<<maxFollow(streams)<<endl;
    return 0;
}