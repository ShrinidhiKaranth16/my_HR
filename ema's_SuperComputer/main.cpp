#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,m,i,j,minimum=0,low =0,k,ab,cd;
    int up=0,down=0,left=0,right =0;
    bool ischanged = false;
    vector<string> arr;
    vector<int> lessNums;
    vector<int> finalNums;
    vector<pair<int,int>> xyz; 
    vector<pair<int,int>> pairs;
    vector<pair<int,int>> bad;
    vector<pair<int,int>> mostcount;
    vector<vector<pair<int,int>>> overlap;
    cin>>n>>m;
    for(i=0;i<n;i++)
    {
        string dem;
        cin>>dem;
        arr.push_back(dem);
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
             pair<int,int> temp;
            string ch;
            ch = arr[i].at(j);
            if(ch=="B")
            {
                temp.first = j;
                temp.second = i;
                bad.push_back(temp);
            }
        }
    }
    //display 
    for(i=0;i<n;i++)
    {
        for(j =0 ;j<m;j++)
        cout<<arr[i].at(j)<<" ";
        cout<<endl;
    }
    for(i=1;i<n-1;i++)
    {
        for(j=1;j<m-1;j++)
        {
            int count=0;
            if(arr[i].at(j) =='G')
            {
                if((arr[i-1].at(j)=='B')||(arr[i+1].at(j)=='B')||(arr[i].at(j+1)=='B')||(arr[i].at(j-1)=='B'))
                {}
                else
                {
                    pair <int,int> p;
                    vector<pair<int,int>> asdf;
                    p.first = j;
                    p.second = i;
                    pair<int,int> ov;
                    ov.first = j;
                    ov.second = i-1;
                    asdf.push_back(ov);
                    ov.first = j;
                    ov.second = i+1;
                    asdf.push_back(ov);
                    ov.first = j-1;
                    ov.second = i;
                    asdf.push_back(ov);
                    ov.first = j+1;
                    ov.second = i;
                    asdf.push_back(ov);
                    overlap.push_back(asdf);
                    pairs.push_back(p);
                }
            }
        }
    }
    cout<<"Adjacent"<<endl;
    for(i=0;i<overlap.size();i++)
    {
        for(j=0;j<overlap[i].size();j++)
        {
         cout<<i<<": ";
         cout<<"  "<<overlap[i][j].second <<","<<overlap[i][j].first<<endl;
        }
        cout<<endl;
    }
    cout<<endl;
for(i=0;i<pairs.size();i++)
{
    cout<<"Y: "<<pairs[i].second<<","<<" X:"<<pairs[i].first<<endl;
}

cout<<"Bad are present in"<<endl;
for(i=0;i<bad.size();i++)
{
    cout<<bad[i].second<<","<<bad[i].first<<endl;
}

cout<<endl;
vector<int> total;
vector<vector<pair<int,int>>> v;
if(pairs.size()<1)
{
    cout<<"1";
    return 1;
}
for(i=0;i<pairs.size();i++)
{
    int x = pairs[i].first;
    int y = pairs[i].second;
    int count;
    int Rr,Rl,Cu,Cd;
    Rr = m-x-1;
     Rl = x;
    Cu = y;
    Cd = n-y-1;
    cout<<"first"<<endl;
    for(j=0;j<bad.size();j++)
    { 
        if(bad[j].first==x  && bad[j].second<y ) Cu = Cu - bad[j].second + 1;
        if(bad[j].first==x  && bad[j].second>y ) Cd = Cd - (bad[j].second -y);
        if(bad[j].second==y && bad[j].first<x  ) Rl = Rl - bad[j].first + 1;
        if(bad[j].second==y && bad[j].first>x  ) Rr = Rr - (bad[j].first -x);
    }
        int least =min(Rr,min(Rl,min(Cu, Cd)));
            vector<pair<int,int>> d;
            minimum = least;
            lessNums.push_back(least);
            for(k=0;k<4;k++)
            {
                pair<int,int>pp;
                pp.first = overlap[i][k].first;
                pp.second = overlap[i][k].second;
                d.push_back(pp);
            }
            v.push_back(d);
        int vsize = v.size()-1;
        cout<<"Pushed down adjacent sides are"<<endl;
            for(cd=0;cd<4;cd++)
            {
                cout<<v[vsize][cd].second<<","<<v[vsize][cd].first<<endl;
            }
            cout<<"total vector v"<<endl;
        for(ab=0;ab<vsize+1;ab++)
        {
             for(cd=0;cd<4;cd++)
             {
                  cout<<v[ab][cd].second<<","<<v[ab][cd].first<<endl;
             }
        }
            Rr = minimum;
            Rl = minimum;
            Cu = minimum;
            Cd = minimum;
          int sum = Rr +Rl + Cu + Cd+1;
            total.push_back(sum);
        }
int ty;
 for(ab=0;ab<overlap.size();ab++)
{
    for(cd =0;cd<4;cd++)
             {
               for( ty = ab+1;ty<overlap.size();ty++)
                {
                    for(int yu = 0;yu<4;yu++)
                    {
                         if(overlap[ab][cd].first==overlap[ty][yu].first && overlap[ab][cd].second==overlap[ty][yu].second)
                       {
                           pair<int,int> po;
                           po.first = ab;
                           po.second = ty;
                           xyz.push_back(po);
                       }
                    }
                }
          }
}

cout<<"XYZ"<<endl;
for(i=0;i<xyz.size();i++)
{
    cout<<xyz[i].first<<","<<xyz[i].second<<endl;
}
cout<<"LessNUms"<<endl;
for(i=0;i<lessNums.size();i++)
{
cout<<lessNums[i]<<","<<endl;
}
cout<<endl;
for(i=0;i<xyz.size();i++)
{  
  if(lessNums[xyz[i].first]>lessNums[xyz[i].second])
  finalNums.push_back(lessNums[xyz[i].first]);
  else if(lessNums[xyz[i].first]<lessNums[xyz[i].second])
  finalNums.push_back(lessNums[xyz[i].second]);
  else
  finalNums.push_back(lessNums[xyz[i].second]);  
}
cout<<"LessNums"<<endl;
for(int q:finalNums)
cout<<q<<",";
cout<<endl;

cout<<"total is: ";
for(int r:total)
cout<<r<<","<<endl;

sort(total.begin(),total.end());
int c =total.size();
if(c==1)
cout<<total[c-1];
else
cout<<total[c-1]*total[c-2];

    return 0;
}