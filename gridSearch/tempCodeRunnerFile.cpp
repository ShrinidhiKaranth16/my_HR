int gSize = G.size();
    int pSize = P.size();
    int valSize = P[0].size();
    for(int x=0;x<gSize;x++)
    {
        int h;
        int found = G[x].find(P[0]);
        string s = G[x];
        if(found != string::npos)
        {
            int ref = x;
            int u = 1;
            for(int q =1; q<pSize;q++)
            {
                ref =  ref + 1;
                string a = G[ref].substr(found,valSize);
               // cout<<"X :"<<x<<" A : "<<a<<" P[q] "<< P[q]<<endl;
                if(a ==P[q])
                {
                    u++;
                
                }else
                {
                    break;
                }
                
            }
            //cout<<"U: "<<u <<endl;
            if(u==pSize){
            return "YES";
            }
            else{
                vector<int> occurs;
                occurs.push_back(found);
                for( h=found+1;h<G[x].size();h++)
                {
                        if(G[x].size() - h >= pSize)
                    {
                    string r = s.substr(h,pSize);
                   // cout<<"X :"<< x <<" h: "<<h<<" Psize: "<<pSize<<endl;
                   // cout<<"SubString is "<< r<<endl;
                     int ref2 = x;
                     int v = 1;
                     for(int q1 =1; q1<pSize;q1++)
                     {
                         ref2 = ref2 + 1;
                         string b = G[ref2].substr(h,valSize);
                        // cout<<"X :"<<x<<" B : "<<b<<" P[q1] "<< P[q1]<<endl;
                         if(b ==P[q1])
                        {
                            v++;
                        }
                     }
                    // cout<<"V: "<<v <<endl;
                     if(v == pSize)
                     return "YES";
                    }
                }
            }
            
        }
    }
    return "NO";