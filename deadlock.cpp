
#include<bits/stdc++.h>
using namespace std;
int p,r,i,j;
vector<int>ans;

int allocation[100][100],available[100],request[100][100],need[100][100],mex[100][100],instance[100];

bool isSafety()
{
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
                    if(request[i][j]>work[j]) break;
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
int main()
{
    freopen("deadlock.txt","r",stdin);
    cin>>p>>r;
    int i,j,k,c=0;
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
            cin>>request[i][j];
        }
    }

    if(isSafety())
    {
        cout<<"there is  no deadlock"<<endl;

    }
    else
    {
        cout<<"deadlock detected"<<endl;
    }




}
