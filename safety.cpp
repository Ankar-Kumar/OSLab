#include<bits/stdc++.h>
using namespace std;
int p,r,i,j;
vector<int>ans;

int allocation[100][100],available[100],request[100],need[100][100],mex[100][100],instance[100];
void findavail()
{
    for(i=0; i<r; i++)
    {
        int sum=0;
        for(j=0; j<p; j++)
        {
            sum+=allocation[j][i];
        }
        available[i]=instance[i]-sum;
    }
//    for(i=0;i<r;i++) cout<<available[i]<<" ";
//    cout<<endl<<endl;
}
void findNeed()
{
    for(i=0; i<p; i++)
    {
        for(j=0; j<r; j++)
        {
            need[i][j]=mex[i][j]-allocation[i][j];
        }
    }

//    for(i=0;i<p;i++){
//        for(j=0;j<r;j++){
//            cout<<need[i][j]<<" ";
//        }cout<<endl;
//    }
//    cout<<endl<<endl;
}

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
int main()
{
    freopen("safety.txt","r",stdin);
    cin>>p>>r;
    int i,j,k,c=0;
    for(i=0; i<r; i++) cin>>instance[i];
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
            cin>>mex[i][j];
        }
    }

    findavail();
    findNeed();
    if(isSafety())
    {
        cout<<"there is  safe sequence"<<endl;
        for(i=0; i<p; i++) cout<<ans[i]<<" ";
        cout<<endl<<endl;
    }
    else
    {
        cout<<"there is no safe sequence"<<endl;
    }




}
