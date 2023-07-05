#include<bits/stdc++.h>

using namespace std;
int main()
{
    int proc,i,j=1;
    cin>>proc;
    vector<int>first(proc),cmplt(proc,-1);
    for(i=0; i<proc; i++)
        cin>>first[i];   //frame size
    int siz,tmp=proc;
    while(tmp--)
    {
        cin>>siz;
        int ind=-1,k=siz;
       // sort(first.rbegin(),first.rend());
        for(i=0; i<proc; i++)
        {
            if(first[i]>=siz)  // sb theke maximum size e store krbo
            {
                siz=first[i];
                ind=i;
            }
        }
        if(ind==-1)
            cout<<"no allocation process size "<<siz<<endl;
        else{
            cout<<"allocated into "<<k<<endl;
                cmplt[ind]=j++;
                first[ind]=-1;
               // break;
        }
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

