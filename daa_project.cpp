#include<bits/stdc++.h>
#include <fstream>
using namespace std;
unordered_map<string,int> movie,actor;


int main()
{

    //we get values in movie and actor through some file reading
    movie["2"]=0;
    movie["simmba"]=1;
    movie["zero"]=2;
    actor["Rajinikanth"]=1;
    actor["Akshay Kumar"]=2;
    actor["Amy Jackson"]=5;
    actor["Shah Rukh Khan"]=4;
    actor["Katrina Kaif"]=0;
    actor["Anushka Sharma"]=6;
    actor["Tigmanshu Dhulia"]=3;

    vector<vector<int> > gph(7,vector<int> (7,-1));
    string line;
  ifstream myfile ("try.txt");
  if (myfile.is_open())
  {
    while ( getline (myfile,line) )
    {
        int st=0,en=0,mov=-1;vector<int> q;
        for(int i=0;line[i]!='\0';i++)
        {
            if(mov==-1&&line[i]=='|')
            {
                mov=movie[line.substr(st,i)];
                st=i+1;
            }
            else if(mov!=-1&&line[i]=='|')
            {
                q.push_back(actor[line.substr(st,i-st)]);
                st=i+1;
            }
        }
        for(int i=0;i<q.size();i++)
        {
            for(int j=i+1;j<q.size();j++)
            {
                gph[q[i]][q[j]]=mov;
                gph[q[j]][q[i]]=mov;
            }
        }
        q.clear();
    }
    myfile.close();
  }

  else cout << "Unable to open file";


}
