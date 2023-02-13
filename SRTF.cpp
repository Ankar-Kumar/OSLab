#include<bits/stdc++.h>
using namespace std;

struct process{
    int pid;
    int bt;
    int art;
};

void findWaitTime(process proc[],int n,int wt[])
{
    int rt[n];
    for (int i = 0; i < n; i++)
        rt[i] = proc[i].bt;

    int complete = 0, t = 0, mn = INT_MAX;
    int ind = 0, f_time;
    bool check = false;
    vector<int>ans;
    while (complete < n)
    {
        for (int j = 0; j < n; j++)
        {
            if ((proc[j].art <= t) && (rt[j] < mn) && rt[j] > 0)
            {
                //ans.push_back(j+1);
                mn = rt[j];
                ind = j;
                check = true;
            }
        }

        if (check == false)
        {
            t++;
            continue;
        }

        rt[ind]--;
        mn = rt[ind];

        if (mn == 0)
            mn = INT_MAX;

        if (rt[ind] == 0)
        {
            //ans.push_back(ind+1);
            complete++;
            check = false;
            f_time = t++;
            wt[ind] = f_time -(proc[ind].bt + proc[ind].art);
            if (wt[ind] < 0)
                wt[ind] = 0;
        }
        t++;
    }
    // for(auto x:ans){
    //     cout<<x<<" ";
    // }
    // cout<<endl;
    // cout<<endl;
}

void findTurnAroundTime(process proc[],int n,int wt[],int tat[])
{
    for(int i=0;i<n;i++)
    {
        tat[i]=proc[i].bt+wt[i];
    }
}
void gantt_chart(process proc[],int n,int bt[],int art[])
{


}
void findAvgTime(process proc[],int n){

    int wt[n],tat[n],total_wt=0,total_tat=0;
    findWaitTime(proc,n,wt);
    findTurnAroundTime(proc,n,wt,tat);
   // cout << " Waiting time "<< " Turn around time\n";
    for (int i = 0; i < n; i++)
    {
        total_wt = total_wt + wt[i];
        total_tat = total_tat + tat[i];
        cout <<wt[i]<< "\t\t " << tat[i] << endl;
    }
    cout <<"\nAverage waiting time = "<< total_wt/(float)n<<"\n";
    cout <<"\nAverage turn around time = "<< total_tat/(float)n<<"\n";

//    gantt_chart(proc,n,bt,art);

}
int main(){
    int n,i,j;
    freopen("srtf.txt","r",stdin);
    cout<<"Enter total number of processor  ";
    cin>>n;
    process proc[n+1];
    for(i=0;i<n;i++){
        cin>>proc[i].pid>>proc[i].art>>proc[i].bt;
    }
    findAvgTime(proc,n);
}

