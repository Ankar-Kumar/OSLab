#include<bits/stdc++.h>
using namespace std;
void gantt_chart(int n,int bt[100],int tat[100]){
    int i,j;
     cout<<" ";
        for(i=0;i<n;i++){
            for(j=0;j<bt[i];j++){
                cout<<"--";
            }
            cout<<" ";
        }
        printf("\n|");
        for(i=0;i<n;i++){
           for(j=0;j<bt[i]-1;j++){
                cout<<" ";
            }
            cout<<"p"<<i+1;
            for(j=0;j<bt[i]-1;j++){
                cout<<" ";
            }
            cout<<"|";
        }
        printf("\n ");
        for(i=0;i<n;i++){
            for(j=0;j<bt[i];j++){
                cout<<"--";
            }
            cout<<" ";
        }
    cout<<endl;
     printf("0");
    for(i=0; i<n; i++) {
        for(j=0; j<bt[i]; j++) cout<<"  ";
        if(tat[i] > 9) printf("\b"); // backspace : remove 1 space
        cout<<tat[i];
    }

}
int main() {
    freopen("fcfs.txt", "r", stdin);
    int n,bt[20],wt[20],tat[20],avwt=0,avtat=0,i,j;
    cout<<"Enter total number of processes(maximum 20):";
    cin>>n;
    for (i=0;i<n;i++) {
        cout<<"P["<<i+1<<"]:";
        cin>>bt[i];
    }
    wt[0]=0;
    for (i=1;i<n;i++) {
        wt[i]=0;
        for (j=0;j<i;j++)
                    wt[i]+=bt[j];
    }
    for (i=0;i<n;i++) {
        tat[i]=bt[i]+wt[i];
        avwt+=wt[i];
        avtat+=tat[i];
        cout<<"nP["<<i+1<<"] "<<bt[i]<<"  "<<wt[i]<<"   "<<tat[i]<<endl;
    }
    avwt/=i;
    avtat/=i;
    cout<<"nnAverage Waiting Time:"<<avwt;
    cout<<"nAverage Turnaround Time:"<<avtat;
    cout<<endl<<endl<<endl;
   gantt_chart(n,bt,tat);
    return 0;
}
