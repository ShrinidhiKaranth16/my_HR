 istringstream iss(time);
    string t[2];
    string demo,P ;
    string  result[3];
    int i=0;
    while(getline(iss, demo, ' '))
    {
        t[i] = demo;
        i++;
    }
    int j=0;
     istringstream iss2(t[0]);
         while (getline(iss2,P,':'))
         {
             result[j]= P;
             j++;
         }
         string a =" ";
         string b =" ";
         for(int l=2;l<4;l++)
          b = b + result[2].at(l);
           b.erase(remove(b.begin(), b.end(), ' '), b.end());
         for(int j=0;j<2;j++)
         a = a + result[2].at(j);
         result[2] = a;
    result[2].erase(remove(result[2].begin(), result[2].end(), ' '), result[2].end()); 
   if((b == "AM") && (result[0] == "12"))
     result[0] = "00";
    
   if(b == "PM")
   {
        int x = atoi(result[0].c_str()); 
        int y = x+12;
      result[0] = to_string(y);
  
  }
  string output;
   for(int i=0;i<3;i++)
   {
    output = output.append(result[i]);  
    if(i!=2)
    output = output +":";
   }