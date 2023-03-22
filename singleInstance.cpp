#include<bits/stdc++.h>
using namespace std;
int p,r;
vector<int>graph[20];
int dead=0,tmp;
bool cycle(int ind,vector<int>&vis,vector<int>&dfs)
{
    vis[ind]=1;
    dfs[ind]=1;
    for(auto x:graph[ind]){
        if(!vis[x]){
            if(cycle(x,vis,dfs)) return true;
        }else if(dfs[x]){ // and also vis[x]=1
            return true;
        }
    }
    dfs[ind]=0;
    return false;
}
int main()
{
    freopen("single.txt","r",stdin);
    cin>>p>>r;
    string a,b,c;
    int i,j;
    vector< pair<int, pair<int, int> > >tmp;
    while(cin>>a>>b>>c){

        int x=a[1]-48;
        int y=b[1]-48;
        int z=c[1]-48;
        tmp.push_back(make_pair(x,make_pair(y,z)));
    }
//    for(auto x:tmp){
//        cout<<x.first<<" "<<x.second.first<<" "<<x.second.second<<endl;
//    }


    for(auto x:tmp){
        graph[x.second.second].push_back(x.second.first);

    }
//    for(i=0;i<p;i++){
//        cout << i << " -> ";
//        for(j=0;j<graph[i].size();j++){
//            cout<<graph[i][j]<<" ";
//        }cout<<endl;
//    }
    vector<int>vis(p+1,0),dfs(p+1,0);
    for(i=0;i<p;i++){
            if(!vis[i]){
                if(cycle(i,vis,dfs)){
                    dead=1;
                }
            }
    }
    if(dead) cout<<"DEADLOCK DETECTED";
    else cout<<"NO DEADLOCK";



}
