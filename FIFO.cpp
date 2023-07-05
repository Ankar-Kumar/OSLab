#include<bits/stdc++.h>
using namespace std;
int fault=0;

void FIFO(vector<int>&pages,int siz)
{
    set<int>tmp;
    queue<int>ind;
    for(auto val:pages)
    {
        if(tmp.size()<siz)
        {
            if(tmp.find(val)==tmp.end())  //not found
            {
                fault++;
                tmp.insert(val);
                ind.push(val);
            }
        }
        else
        {
            if(tmp.find(val)==tmp.end())   //not found
            {
                int prev=ind.front();
                ind.pop();
                tmp.erase(prev);

                ind.push(val);
                tmp.insert(val);
                fault++;
            }
        }
    }
    cout<<fault;
}
int main()
{
    vector<int>a= {7,0,0,1,2,0,3,0,4,2,3,0,3,0,3,2,1,2,0,1,7,0,1};//15
         //  {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2} 7
    while(1){
    int siz;
    cout<<"FRAME SIZE ";
    cin>>siz;
    FIFO(a,siz);
    }
}
