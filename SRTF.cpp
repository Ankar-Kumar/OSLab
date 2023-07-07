#include<bits/stdc++.h>
using namespace std;
vector<int> ans;
struct process{
    int pid;
    int bt;
    int art;
};

void findWaitTime(process proc[],int n,int wt[])
{
    int rt[n];///remaining time
    for (int i = 0; i < n; i++)
        rt[i] = proc[i].bt;

    int complete = 0, t = 0, mn = INT_MAX;
    int ind = 0, f_time;
    bool check = false;

    while (complete < n)
    {
        for (int j = 0; j < n; j++)
        {

            if ((proc[j].art <= t) && rt[j] < mn && rt[j] > 0)
            {
                //ans.push_back(proc[ind].pid);
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
        ans.push_back(proc[ind].pid); //last added   // kun process access pabe seta push krbo
        rt[ind]--; /// remaining time 1 decrease krbo
        mn = rt[ind];

        if (mn == 0)
            mn = INT_MAX;

        if (rt[ind] == 0)
        {

            complete++;
            // check = false;
            f_time = t + 1;
            wt[ind] = f_time -(proc[ind].bt + proc[ind].art);
            if (wt[ind] < 0)
                wt[ind] = 0;
        }
        t++;
    }


}

void findTurnAroundTime(process proc[],int n,int wt[],int tat[])
{
    for(int i=0;i<n;i++)
    {
        tat[i]=proc[i].bt+wt[i];
    }
}
void gantt_chart()
{
    vector<int>id, time;
    int c = 1;
    id.push_back(ans[0]);
    time.push_back(0);
    // ind++;
    for (int i = 1; i < ans.size(); i++)
    {
        if (ans[i] == ans[i - 1])
        {
            c++;
            continue;
        }
        else
        {
            time.push_back(c);
            id.push_back(ans[i]);
            // ind++;
            c = 1;
        }
    }
    time.push_back(c);
    cout<<"  ";//2
    for (int i = 0; i < id.size(); i++)
    {
        cout << "p" << id[i] << "    ";//4
    }
    cout << endl;
    cout << 0 << "   ";
    for (int i = 1; i < time.size(); i++)
    {
        time[i] += time[i - 1];
        cout << time[i] << "     ";
    }

    cout << endl;

}
void findAvgTime(process proc[],int n){

    int wt[n],tat[n],total_wt=0,total_tat=0;
    findWaitTime(proc,n,wt);
    findTurnAroundTime(proc,n,wt,tat);
   // cout << "Processes "<< " Burst time "<< " Waiting time "<< " Turn around time\n";
    for (int i = 0; i < n; i++)
    {
        total_wt = total_wt + wt[i];
        total_tat = total_tat + tat[i];
        cout <<proc[i].pid<<" "<<wt[i]<< "\t\t " << tat[i] << endl;
    }
    cout <<"\nAverage waiting time = "<< total_wt/(float)n<<"\n";
    cout <<"\nAverage turn around time = "<< total_tat/(float)n<<"\n";
    cout<<"GANTT CHART   "<<endl;
   gantt_chart();

}
int main(){
    int n,i,j;
    freopen("srtf.txt","r",stdin);
   // cout<<"Enter total number of processor  ";
    cin>>n;
    process proc[n+1];
    for(i=0;i<n;i++){
        cin>>proc[i].pid>>proc[i].art>>proc[i].bt;
    }
    findAvgTime(proc,n);
}

