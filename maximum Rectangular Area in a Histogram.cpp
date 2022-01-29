  vector<int> nsefromright(long long arr[],int n)
{
  vector<int>v;
  stack<pair<long long,int>>s;
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
vector<int> nsefromleft(long long arr[],int n)
{
  vector<int>v;
  stack<pair<long long,int>>s;
  int pseudoindex=-1;
  for(int i=0;i<n;i++)
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
  return v;
}
    long long getMaxArea(long long arr[], int n)
    {
vector<int>right=nsefromright(arr,n);
vector<int>left=nsefromleft(arr,n);
long long m=INT_MIN;
for(long long i=0;i<n;i++)
{
 m=max(m,(right[i]-left[i]-1)*arr[i]);
}
return m;
    }
