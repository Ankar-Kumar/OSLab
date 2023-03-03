#include<bits/stdc++.h>
using namespace std;
int p,r,i,j;
vector<int>ans;

int allocation[100][100],available[100],request[100],need[100][100],mex[100][100],instance[100];
bool isSafety()
{
    ans.clear();
    vector<int>finish(p,0);
    vector<int>work(available,available+r);
//    for(i=0;i<r;i++) cout<<work[i]<<" ";
    int k=0;
    while(k<p)
    {

        bool flag=false;
        for(i=0; i<p; i++)
        {
            if(!finish[i])
            {
                for(j=0; j<r; j++)
                {
                    if(need[i][j]>work[j]) break;
                }
                if(j==r)
                {
                    for(j=0; j<r; j++)
                    {
                        work[j]+=allocation[i][j];
                    }
                    ans.push_back(i);
                    k++;
                    finish[i]=1;
                    flag=true;
                }
            }
        }
        if(flag==false) return false;

    }
    return true;
}


bool requestResource(int pid)
{
//    cout<<endl<<endl;
//    for(i=0;i<p;i++){
//        for(int j=0;j<r;j++){
//            cout<<allocation[i][j]<<" ";
//        }cout<<endl;
//    }
//    cout<<endl<<endl;
    for(i=0; i<r; i++)
    {
        //cout<<request[i]<<" ";
        available[i]-=request[i];
        allocation[pid][i]+=request[i];
        need[pid][i]-=request[i];
    }

    if(isSafety())
    {
        return true;
    }
    else
    {
        for(i=0; i<r; i++)
        {
            available[i]+=request[i];
            allocation[pid][i]-=request[i];
            need[pid][i]+=request[i];
        }
        return false;
    }
}

int main()
{
    freopen("request.txt","r",stdin);

    cin>>p>>r;
    for(i=0; i<r; i++) cin>>available[i];
    for(i=0; i<p; i++)
    {
        for(j=0; j<r; j++)
        {
            cin>>allocation[i][j];
        }
    }

    for(i=0; i<p; i++)
    {
        for(j=0; j<r; j++)
        {
            cin>>need[i][j];
        }
    }
    if(isSafety())
    {
        int t=1;
        while(t--)
        {

                int pid;//process id
                cin>>pid;
                for(i=0; i<r; i++) cin>>request[i];
                bool valid=true;
                for(i=0; i<r; i++)
                {
                    if(request[i]>need[pid][i])
                    {
                        valid=false;
                        break;
                    }
                }
                if(valid==false) continue;
                for(i=0; i<r; i++)
                {
                    if(request[i]>available[i])
                    {
                        valid=false;
                        break;
                    }
                }
                if(valid==false) continue;
                if(requestResource(pid))
                {
                    cout<<"The Resources has been allocated.\n";
                    for(i=0; i<p; i++) cout<<ans[i]<<" ";
                    cout<<endl;
                }
                else
                {
                    cout<<"request cannt be granted"<<endl;
                }
        }
    }
    else  cout<<"there is no safe sequence"<<endl;
}

