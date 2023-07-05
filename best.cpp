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
        int ind=-1,k=siz,prev=INT_MAX;
       // sort(first.rbegin(),first.rend());
        for(i=0; i<proc; i++)   //  minimum highest e store kora lagbe
        {
            if (first[i] >= siz and first[i] <= prev)  // minimum prev change
            {
                prev=first[i];
                ind=i;
            }
        }
        if(ind==-1)
            cout<<"no allocation process size "<<siz<<endl;
        else{
            cout<<"allocated into "<<prev<<endl;
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

