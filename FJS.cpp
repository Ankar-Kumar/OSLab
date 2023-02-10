#include <bits/stdc++.h>

#define MAX_PROCESS 100
using namespace std;
struct process {
    int pid;
    int burst_time;
    int waiting_time;
};

typedef struct process Process;
double average_waiting_time;
int total_waiting_time;
int ind[100],tat[100];

int compare(Process a, Process b)
{
    return a.burst_time < b.burst_time;
}
void WaitingTime(Process p[], int n)
{
    int i;
    total_waiting_time = 0;
    p[0].waiting_time = 0;
    cout<<p[0].pid<<" "<<p[0].waiting_time<<endl;
    tat[0] = p[0].waiting_time + p[0].burst_time;
    for(i=1; i<n; i++) {
        p[i].waiting_time = p[i-1].waiting_time + p[i-1].burst_time;
        tat[i]= p[i].waiting_time+p[i].burst_time;
        cout<<p[i].pid<<" "<<p[i].waiting_time<<endl;
        total_waiting_time += p[i].waiting_time;
    }
}

void gantt(Process proc[], int n)
{
    int i, j;
    cout << " ";
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < proc[i].burst_time; j++)
        {
          cout << "--";
        }
        cout << " ";
    }
    printf("\n|");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < proc[i].burst_time - 1; j++)
        {
          cout << " ";
        }
        cout << "p" << proc[i].pid;
        for (j = 0; j < proc[i].burst_time - 1; j++)
        {
          cout << " ";
        }
        cout << "|";
    }
    printf("\n ");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < proc[i].burst_time; j++)
        {
          cout << "--";
        }
        cout << " ";
    }
    cout << endl;

    cout << 0;
    for(i=0;i<n;i++){
        for(int j=0;j<proc[i].burst_time;j++) cout<<"  ";
        if(tat[i]>9) cout<<"\b";
        cout<<tat[i];
    }
    
}
int main()
{
    freopen("fjs.txt","r",stdin);
    Process p[MAX_PROCESS];
    int n, i, j;
    puts("SHORTEST JOB FIRST SCHEDULING ALGORITHM");
    puts("=======================================");

    printf("Enter total process: ");
    scanf("%d", &n);
    printf("Enter burst time for each process:\n");
    for(i=0; i<n; i++) {
        printf("P[%d]: ", i+1);
        scanf("%d", &p[i].burst_time);
        p[i].pid = i+1;
    }

    sort(p,p+n,compare);
    WaitingTime(p, n);

    average_waiting_time = (double) ( (double)total_waiting_time / (double) n );

    puts("");
    printf("Average Waiting Time: %.2lf\n",average_waiting_time);

    printf("Gantt Chart:\n");
    gantt(p,n);

    return 0;
}

