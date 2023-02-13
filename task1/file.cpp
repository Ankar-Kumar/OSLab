#include<bits/stdc++.h>
#define ll long long
#define lpr pair<long long int,long long int>
#define S second
#define F first
#define pb push_back
#define n1 '\n'

using namespace std;

 typedef pair<int,int>P;


 void solve(){

     vector<pair<int,pair<string,int>>>pr;
     int n;
     cin>>n;
     int last_arrival=0;
     for(int i=0;i<n;i++){
        string s;
        int burst_t,arrival_t;

        cin>>s>>arrival_t>>burst_t;
        pr.pb(make_pair(burst_t,make_pair(s,arrival_t)));
        last_arrival=arrival_t;
     }

     //for(int i=0; i<pr.size(); i++) cout<<pr[i].F<<" "<<pr[i].S.F<<" "<<pr[i].S.S<<endl;

     priority_queue<P,vector<P>,greater<P> >pq;
     vector<int>ans;
     int index=0;

     for(int i=0;i<=last_arrival;i++){
        if(pr[index].S.S==i){
            pq.push(make_pair(pr[index].F,index));
            index++;
        }
        pair<int,int>top=pq.top();
        pq.pop();
        ans.pb(top.S);
        top.F--;
        if(top.F>0){
            pq.push(make_pair(top.F,top.S));
        }
     }

     while(pq.size()){
        pair<int,int>top=pq.top();
        pq.pop();
        ans.pb(top.S);
        top.F--;
        if(top.F>0){
            pq.push(make_pair(top.F,top.S));
        }
     }
     for(int i=0;i<ans.size();i++)
     {
       cout<<" -- ";
     }
     cout<<n1;

     for(int i=0;i<ans.size();i++){
       cout<<" "<<pr[ans[i]].S.F<<" ";

     }
     cout<<n1;
     for(int i=0;i<ans.size();i++)
     {
         cout<<" -- ";

     }
     cout<<n1;
     for(int i=0; i<ans.size();i++){
        if(i<9) cout<<i<<"   ";
        else cout<<i<<"  ";
     }
     cout<<ans.size()<<n1;
 }
 int main()
 {

     int t=1;
     while(t--){
        solve();
     }
 }
