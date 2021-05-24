#include<bits/stdc++.h>
using namespace std; 

void organizingContainers(vector<vector<int>> container) {
  int x,y,z;
  int sizeOfContainers1[container.size()];
  vector<int> numberOfBalls;
  int totalContainers = container.size();
  int totalBalls;
  for(y=0;y<totalContainers;y++)
  {
    int sum =0;
    for(z=0;z<totalContainers;z++)
    {
     totalBalls = container[z][y];
    if(y==0)
      sizeOfContainers1[z] = totalBalls;
    else
      sizeOfContainers1[z] =sizeOfContainers1[z] + totalBalls;
     sum = sum + totalBalls;
    }
    numberOfBalls.push_back(sum);
  }
  int po = 0;
  int sumBalls = 0;
  int sumContainer = 0;
  for(int u:numberOfBalls)
  {
    bool flag = false;
    int key = u;
    for(int tr1=0;tr1<container.size();tr1++)
    {
      if(!flag && key == sizeOfContainers1[tr1] )
      {
        sizeOfContainers1[tr1] = 0;
        flag = true;
      }

    }
    cout<<u<<",";
     po = po + u;
     sumBalls = sumBalls + u;
  }
  cout<<endl;
  cout<<"PO : "<<po<<endl;
  cout<<"Size of the containers"<<endl;
  int t =0;
  for(int tr=0;tr<container.size();tr++)
  {
    cout<<sizeOfContainers1[tr]<<",";
    t = t + sizeOfContainers1[tr]; 
    sumContainer = sumContainer + sizeOfContainers1[tr];
  }
  cout<<"T:"<<t;
  if(t == 0)
  cout<<"Possible";
  else
  cout<<"Impossible";
}
int main() 
{ 
	int q;
  cin>>q;
  int i,j,k;
  for(i=0;i<q;i++)
  {
     int n;
     cin>>n;
     vector<vector<int>> v;
     for(int j=0;j<n;j++)
     {
       vector<int> temp;
       for(k=0;k<n;k++)
       {
         int x;
         cin>>x;
         temp.push_back(x); 
       }
       v.push_back(temp);
     } 
     organizingContainers(v);
  }

} 
