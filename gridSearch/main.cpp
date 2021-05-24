#include<bits/stdc++.h>
using namespace std;


string gridSearch(vector<string> G, vector<string> P) {
        string val = P[0];
        int valSize = val.size();
        cout<<"ValSize= "<<valSize<<endl;
        for(int x =0;x<G.size();x++)
        {
            size_t found = G[x].find(val);
            if( found!= string::npos)
            {
                cout<<"Found: "<<found<<endl;
                int z = x ;
                cout<<"Z:"<<z<<endl;
                int ref = z;
                for(int q =1;q<P.size();q++)
                {
                    ref = ref + 1;
                    cout<<"ref:"<<ref<<endl;
                    string a = G[ref].substr(found,valSize);
                    cout<<"A:"<<a<<endl;
                    if(a !=P[q])
                    return "NO";
                }
                return "YES";
            }
           
        }
}
int main()
{
    int t;
    int i,j,k;
    cin>>t;
    for(i=0;i<t;i++)
    {
        int R,C,r,c;
        cin>>R;
        cin>>C;
        vector<string> values;
        for(j=0;j<R;j++)
        {
            string num;
            cin>>num;
            values.push_back(num);
        }
        cin>>r;
        cin>>c;
        vector<string> searchVal;
        for(k=0;k<r;k++)
        {
            string sv;
            cin>>sv;
            searchVal.push_back(sv);
        }
        string result = gridSearch(values,searchVal);
        cout<<result;
    }

    
}