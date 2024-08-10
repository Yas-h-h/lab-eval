#include <iostream>
#include <vector>
using namespace std;

vector <int> prime(int x,vector <int>&ans)
{
    //vector <int> ans;
    for(int i=2 ; i<x; i++)
    {
        
            int fac=0;
            for(int j=2;j<i;j++)
            {
                if(i%j==0)
                fac++;
            }
            if(fac==0)
            ans.push_back(i);
            
        
    }
    return ans;
}

int main()
{
    
    cout<<"enter the integer upto which you want all prime numbers"<< endl;
    int x;
    cin>>x;
    vector <int>ans; prime(x,ans);
    
    for(int i=0; i<ans.size();i++)
    {
        cout<<ans[i]<<"\t";
    }    
    
}
