/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;

vector<int> nge(int arr[],int n)
{
  vector<int>v;
  stack<pair<int,int>>s;
  int pseudoindex=n;
  for(int i=n-1;i>=0;i--)
  {if(s.size()==0)
     v.push_back(pseudoindex);
  else if(s.size()>0 && s.top().first<arr[i])
     v.push_back(s.top().second);
   else if(s.size()>0 && s.top().first>=arr[i])
     {
         while(s.size()>0 && s.top().first>=arr[i])
         {
             s.pop();
         }
         if(s.size()==0)
           v.push_back(pseudoindex);
         else 
           v.push_back(s.top().second);
     }
     s.push({arr[i],i});
  }
  reverse(v.begin(),v.end());
  return v;
}
int main()
{
int arr[]={1,4,0,2,6};
int n=sizeof(arr)/sizeof(arr[0]);
vector<int> out=nge(arr,n);
for(auto i:out)
 cout<<i<<" ";
    return 0;
}
