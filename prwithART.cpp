#include<bits/stdc++.h>
using namespace std;
struct process{
    int pid;
    int art;
    int bt;
    int pr;
};

int wt[5],tat[5],total_wt=0,total_tat=0;
void findGantt(vector<int>ans)
{
    vector<int>id,time;
    id.push_back(ans[0]);
    time.push_back(0);
    int c=1;
    for(int i=1;i<ans.size();i++){
        if(ans[i]==ans[i-1]) c++;
        else{
            time.push_back(c);
            c=1;
            id.push_back(ans[i]);
        }
    }
    time.push_back(c);
    cout<<"  " ; //2
    for(auto x:id){
        cout<<"p"<<x<<"    "; //4
    }
    cout<<endl;
    cout<<0<<"   ";//3
    for(int i=1;i<time.size();i++){
        time[i]+=time[i-1];
        cout<<time[i]<<"     ";  //5
    }
    cout<<endl;
}
void findWaitTime(process proc[],int n)
{
//    cout<<1;
    int rt[n];
    for(int i=0;i<n;i++){
        rt[i]=proc[i].bt;
    }
    int complete=0,fullTime=0,check=0;
    int time=0,priority=INT_MAX;
    int index=0;
    vector<int>ans;
    while(complete<n){
        for(int j=0;j<n;j++){
            if(proc[j].art<=time and rt[j]>0 and  proc[j].pr<priority){
                check=1;
                priority=proc[j].pr;
                index=j;
            }
        }
        if(!check){
            time++;
            continue;
        }
        time++;
     
        ans.push_back(proc[index].pid);
        rt[index]--;

        if(rt[index]==0){
            complete++;
            priority=INT_MAX;
            wt[index]=time-proc[index].bt-proc[index].art;

        }
    }
    findGantt(ans);



}

int main()
{
    freopen("with.txt","r",stdin);
//    cout<<"no of processor ";
    int n;
    cin>>n;
    process proc[n];
    for(int i=0;i<n;i++){
        cin>>proc[i].pid>>proc[i].bt>>proc[i].pr>>proc[i].art;
    }
    findWaitTime(proc,n);
}
