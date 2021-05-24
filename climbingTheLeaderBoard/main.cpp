#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int> arr;
    int i,x;
    for( i=0;i<n;i++)
    {
      cin>>x;
      arr.push_back(x);  
    }
    int count=0;
    for(i=0;i<n-1;i++)
    {
        if(arr[i]==arr[i+1])
        count++;
    }
    int t = n-count;
  vector<int> rank;
        int j = 1;
    for(i=0;i<n;i++)
    {
        if(i==0)
        {
            x = arr[i];
            rank.push_back(x);
        }
        if(rank[j-1]>arr[i])
        {
             x = arr[i];
             rank.push_back(x);
                j++;
        }
    }
    sort(rank.begin(),rank.end());
   int numberOfGames;
   cin>>numberOfGames;
   vector<int> alice;
   for(i=0;i<numberOfGames;i++)
   {
     cin>>x;
    alice.push_back(x);
   }
 
 vector<int> result;
  int k;
  for(k=0;k<numberOfGames;k++)
  {
      int val = alice[k];
  vector<int>::iterator lower,upper; 
    lower = lower_bound (rank.begin(), rank.end(), val);  
    upper = upper_bound (rank.begin(), rank.end(), val); 
    int l =  lower- rank.begin();
    int u =  upper - rank.begin();
    if(l!=u)
    result.push_back((t-u)+1);
    else
     result.push_back(t-l+1);
  }
  for(int x:result)
  cout<<x<<endl;
  return 0;
}