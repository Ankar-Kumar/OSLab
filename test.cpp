#include<bits/stdc++.h>

using namespace std;
int main()
{
    vector<int>freq(9,0);
    for(int i=0;i<6;i++){
        int k;
        cin>>k;
        freq[k]++;
    }
    for(auto x:freq){
        cout<<x<<" ";
    }
}
