#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,siz,f;
    cin>>n>>siz>>f;
    vector<int>page(n,-1);
    for(int i=0;i<n;i++){
        cin>>page[i];
    }
    while(1){
        int t;
        cin>>t;
        if(t==0) break;
        cout<<"find physical address  ";
        int pno,offset;
        cin>>pno>>offset;
        if(page[pno]==-1){
            cout<<"page is not available"<<endl;
        }
        else{
            cout<<"physical adderess of "<<pno<<" "<<offset<<" is  :"<<page[pno]<<"    "<<offset<<endl;
        }
    }
}
