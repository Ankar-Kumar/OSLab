#include<bits/stdc++.h>

using namespace std;
int main()
{
    int proc,i,j=1;
    cin>>proc;
    vector<int>first(proc),cmplt(proc,-1);
    for(i=0; i<proc; i++)
        cin>>first[i];
    int siz,tmp=proc;
    while(tmp--)
    {
        cin>>siz;
        int c=0;
        for(i=0; i<proc; i++)
        {
            if(first[i]>=siz)
            {
                cout<<"allocated into "<<first[i]<<endl;
                c=1;
                first[i]=-1;
                cmplt[i]=j++;
                break;
            }
        }
        if(!c)
            cout<<"no allocation process size "<<siz<<endl;
    }
    for(auto x:cmplt)
    {
        cout<<x<<" ";
    }
    cout<<endl;
}

/*

5
15 25 10 13 17

*/
