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
 
const int n=50;
const int m=71;

//A
// int main(){
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     vector<string> lines;
//     fstream ss("input.txt");
//     string line;
//     while(getline(ss,line)){
//         lines.push_back(line);
//     }
//     vector<string> grid;
//     for(int i=0;i<n;i++){
//         grid.push_back(lines[i]);
//     }

//     int x=-1;
//     int y=-1;

//     for(int i=0;i<n;i++){
//         for(int j=0;j<n;j++){
//             if(grid[i][j]=='@'){
//                 x=i;
//                 y=j;
//             }
//         }
//     }
//     for(int i=n+1;i<m;i++){
//         for(auto ch:lines[i]){
//             switch (ch)
//             {
//             case '>':
//                 if(grid[x][y+1]=='.'){
//                     grid[x][y]='.';
//                     y++;
//                 }
//                 else if(grid[x][y+1]=='O'){
//                     int tempy=y+1;
//                     while(grid[x][tempy]=='O'){
//                         tempy++;
//                     }
//                     if(grid[x][tempy]=='.'){
//                         grid[x][tempy]='O';
//                         grid[x][y]='.';
//                         y++;
//                         grid[x][y]='.';
//                     }
//                 }
//                 break;
//             case '^':
//                 if(grid[x-1][y]=='.'){
//                     grid[x][y]='.';
//                     x--;
//                 }
//                 else if(grid[x-1][y]=='O'){
//                     int tempx=x-1;
//                     while(grid[tempx][y]=='O'){
//                         tempx--;
//                     }
//                     if(grid[tempx][y]=='.'){
//                         grid[tempx][y]='O';
//                         grid[x][y]='.';
//                         x--;
//                         grid[x][y]='.';
//                     }
//                 }
//                 break;
//             case '<':
//                 if(grid[x][y-1]=='.'){
//                     grid[x][y]='.';
//                     y--;
//                 }
//                 else if(grid[x][y-1]=='O'){
//                     int tempy=y-1;
//                     while(grid[x][tempy]=='O'){
//                         tempy--;
//                     }
//                     if(grid[x][tempy]=='.'){
//                         grid[x][tempy]='O';
//                         grid[x][y]='.';
//                         y--;
//                         grid[x][y]='.';
//                     }
//                 }
//                 break;
//             case 'v':
//                 if(grid[x+1][y]=='.'){
//                     grid[x][y]='.';
//                     x++;
//                 }
//                 else if(grid[x+1][y]=='O'){
//                     int tempx=x+1;
//                     while(grid[tempx][y]=='O'){
//                         tempx++;
//                     }
//                     if(grid[tempx][y]=='.'){
//                         grid[tempx][y]='O';
//                         grid[x][y]='.';
//                         x++;
//                         grid[x][y]='.';
//                     }
//                 }
//                 break;
            
//             default:
//                 break;
//             }
//         }
//     }
//     ll res=0;
//     for(int i=0;i<n;i++){
//         for(int j=0;j<n;j++){
//             if(grid[i][j]=='O'){
//                 res+=(100*i)+j;
//             }
//         }
//     }
//     cout<<res<<endl;

//     return 0;
// }


bool canMoveBoxUp(vector<string> & grid,int i,int j){
    if(grid[i-1][j]=='#' || grid[i-1][j+1]=='#'){
        return false;
    }
    if(grid[i-1][j]=='['){
        return canMoveBoxUp(grid,i-1,j);
    }
    bool flag=true;
    if(grid[i-1][j+1]=='['){
        flag&=canMoveBoxUp(grid,i-1,j+1);
    }
    if(grid[i-1][j]==']'){
        flag&=canMoveBoxUp(grid,i-1,j-1);
    }
    return flag;
}

bool canMoveBoxDown(vector<string> & grid,int i,int j){
    if(grid[i+1][j]=='#' || grid[i+1][j+1]=='#'){
        return false;
    }
    if(grid[i+1][j]=='['){
        return canMoveBoxDown(grid,i+1,j);
    }
    bool flag=true;
    if(grid[i+1][j+1]=='['){
        flag&=canMoveBoxDown(grid,i+1,j+1);
    }
    if(grid[i+1][j]==']'){
        flag&=canMoveBoxDown(grid,i+1,j-1);
    }
    return flag;
}

void moveBoxUp(vector<string> & grid,int i,int j){
    if(grid[i-1][j]=='#' || grid[i-1][j+1]=='#'){
        return;
    }
    if(grid[i-1][j]=='['){
        moveBoxUp(grid,i-1,j);
        if(grid[i-1][j]=='.' && grid[i-1][j+1]=='.'){
            grid[i][j]='.';
            grid[i][j+1]='.';
            grid[i-1][j]='[';
            grid[i-1][j+1]=']';
        }
    }
    bool flag=true;
    if(grid[i-1][j+1]=='['){
        moveBoxUp(grid,i-1,j+1);
    }
    if(grid[i-1][j]==']'){
        moveBoxUp(grid,i-1,j-1);
    }
    if(grid[i-1][j]=='.' && grid[i-1][j+1]=='.'){
        grid[i][j]='.';
        grid[i][j+1]='.';
        grid[i-1][j]='[';
        grid[i-1][j+1]=']';
    }
}

void moveBoxDown(vector<string> & grid,int i,int j){
    if(grid[i+1][j]=='#' || grid[i+1][j+1]=='#'){
        return;
    }
    if(grid[i+1][j]=='['){
        moveBoxDown(grid,i+1,j);
        if(grid[i+1][j]=='.' && grid[i+1][j+1]=='.'){
            grid[i][j]='.';
            grid[i][j+1]='.';
            grid[i+1][j]='[';
            grid[i+1][j+1]=']';
        }
    }
    if(grid[i+1][j+1]=='['){
        moveBoxDown(grid,i+1,j+1);
    }
    if(grid[i+1][j]==']'){
        moveBoxDown(grid,i+1,j-1);
    }
    if(grid[i+1][j]=='.' && grid[i+1][j+1]=='.'){
        grid[i][j]='.';
        grid[i][j+1]='.';
        grid[i+1][j]='[';
        grid[i+1][j+1]=']';
    }
}

//B
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<string> lines;
    fstream ss("input.txt");
    string line;
    while(getline(ss,line)){
        lines.push_back(line);
    }
    vector<string> grid1;
    for(int i=0;i<n;i++){
        grid1.push_back(lines[i]);
    }

    vector<string> grid;

    for(int i=0;i<n;i++){
        string row;
        for(int j=0;j<n;j++){
            switch (grid1[i][j])
            {
            case '#':
                row+="##";
                break;
            case '.':
                row+="..";
                break;
            case 'O':
                row+="[]";
                break;
            case '@':
                row+="@.";
                break;
            
            default:
                break;
            }
        }
        grid.push_back(row);
    }



    int x=-1;
    int y=-1;

    for(int i=0;i<grid.size();i++){
        for(int j=0;j<grid[0].size();j++){
            if(grid[i][j]=='@'){
                x=i;
                y=j;
            }
        }
    }
    for(int i=n+1;i<m;i++){
        for(auto ch:lines[i]){
            switch (ch)
            {
            case '>':
                if(grid[x][y+1]=='.'){
                    grid[x][y]='.';
                    y++;
                }
                else if(grid[x][y+1]=='['){
                    int tempy=y+1;
                    while(grid[x][tempy]=='[' || grid[x][tempy]==']'){
                        tempy++;
                    }
                    if(grid[x][tempy]=='.'){
                        while(tempy!=y+1){
                            grid[x][tempy]=grid[x][tempy-1];
                            tempy--;
                        }
                        grid[x][y]='.';
                        y++;
                        grid[x][y]='.';
                    }
                }
                break;
            case '^':
                if(grid[x-1][y]=='.'){
                    grid[x][y]='.';
                    x--;
                }
                else if(grid[x-1][y]=='['){
                    if(canMoveBoxUp(grid,x-1,y)){
                        moveBoxUp(grid,x-1,y);
                        if(grid[x-1][y]=='.'){
                            grid[x][y]='.';
                            x--;
                        }
                    }
                }
                else if(grid[x-1][y]==']'){
                    if(canMoveBoxUp(grid,x-1,y-1)){
                        moveBoxUp(grid,x-1,y-1);
                        if(grid[x-1][y]=='.'){
                            grid[x][y]='.';
                            x--;
                        }
                    }
                }
                break;
            case '<':
                if(grid[x][y-1]=='.'){
                    grid[x][y]='.';
                    y--;
                }
                else if(grid[x][y-1]==']'){
                    int tempy=y-1;
                    while(grid[x][tempy]=='[' || grid[x][tempy]==']'){
                        tempy--;
                    }
                    if(grid[x][tempy]=='.'){
                        while(tempy!=y-1){
                            grid[x][tempy]=grid[x][tempy+1];
                            tempy++;
                        }
                        grid[x][y]='.';
                        y--;
                        grid[x][y]='.';
                    }
                }
                break;
            case 'v':
                if(grid[x+1][y]=='.'){
                    grid[x][y]='.';
                    x++;
                }
                else if(grid[x+1][y]=='['){
                    if(canMoveBoxDown(grid,x+1,y)){
                        moveBoxDown(grid,x+1,y);
                        if(grid[x+1][y]=='.'){
                            grid[x][y]='.';
                            x++;
                        }
                    }
                }
                else if(grid[x+1][y]==']'){
                    if(canMoveBoxDown(grid,x+1,y-1)){
                        moveBoxDown(grid,x+1,y-1);
                        if(grid[x+1][y]=='.'){
                            grid[x][y]='.';
                            x++;
                        }
                    }
                }
                break;
            
            default:
                break;
            }
        }
    }

    for(int i=0;i<grid.size();i++){
        for(int j=0;j<grid[0].size();j++){
            cout<<grid[i][j];
        }
        cout<<endl;
    }

    ll res=0;
    for(int i=0;i<grid.size();i++){
        for(int j=0;j<grid[0].size();j++){
            if(grid[i][j]=='['){
                res+=(100*i)+j;
            }
        }
    }
    cout<<res<<endl;

    return 0;
}