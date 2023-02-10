#include<bits/stdc++.h>
using namespace std;
int wt[100], tat[100], total_wt = 0, total_tat = 0;
struct Process
{
    int pid; // Process ID
    int bt; // Burst Time
    int pr; // Priority
};

bool cmp(Process a, Process b)
{
    return a.pr < b.pr;
}

void findAverageTime(Process proc[], int n)
{
    
    wt[0] = 0;
    tat[0] = proc[0].bt;
    for(int i=1; i<n; i++)
    {
        wt[i] = proc[i-1].bt + wt[i-1];
        tat[i] = proc[i].bt + wt[i];
    }

    cout << "\nProcesses  "<< " Burst time  "<< " Waiting time  " << " Turn around time\n";
    for (int i = 0; i < n; i++)
    {
        total_wt = total_wt + wt[i];
        total_tat = total_tat + tat[i];
        cout << "   " << proc[i].pid << "\t\t" << proc[i].bt <<"\t    "<< wt[i] <<"\t\t  " << tat[i] << "\n";
    }

    cout << "\nAverage waiting time = "<< total_wt/(double)n<<"\n";
    cout << "\nAverage turn around time = "<< total_tat/(double)n<<"\n";
}

void gantt(Process proc[], int n){
    int i, j;
    cout << " ";
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < proc[i].bt; j++)
        {
            cout << "--";
        }
        cout << " ";
    }
    printf("\n|");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < proc[i].bt - 1; j++)
        {
            cout << " ";
        }
        cout << "p" << proc[i].pid;
        for (j = 0; j < proc[i].bt - 1; j++)
        {
            cout << " ";
        }
        cout << "|";
    }
    printf("\n ");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < proc[i].bt; j++)
        {
            cout << "--";
        }
        cout << " ";
    }
    cout << endl;

    cout<<0;
    for(int i=0;i<n;i++){
        for(int j=0;j<proc[i].bt;j++) cout<<"  ";
        if(tat[i]>9) cout<<"\b";
        cout<<tat[i];
    }
    
}
int main()
{
    freopen("priority.txt","r",stdin);
    int n;
    cout<<"Enter Total Processes: ";
    cin>>n;

    Process proc[n];
    cout<<"\nEnter burst time and Priority:\n";
    for(int i=0; i<n; i++)
    {
        cin>>proc[i].bt>>proc[i].pr;
        proc[i].pid = i+1;
    }

    sort(proc, proc+n, cmp);
    findAverageTime(proc, n);
    gantt(proc,n);
    return 0;
}
