#include<bits/stdc++.h>
using namespace std;
unordered_map<string,int> movie,actor;
void getm(int a)
{
    string line;
  ifstream myfile ("movie.txt");
  if (myfile.is_open())
  {
    while ( getline (myfile,line) )
    {
      movie[line]=a;a++;
    }
    myfile.close();
  }

  else cout << "Unable to open file";
}

void geta(int a)
{
    string line;
  ifstream myfile ("actor.txt");
  if (myfile.is_open())
  {
    while ( getline (myfile,line) )
    {
        int n=line.size(),st=0;
        for(int i=0;i<n;i++)
        {
            if(line[i]=='|')
            {
                if(actor.find(line.substr(st,i-st))==actor.end())
                {
                    actor[line.substr(st,i-st)]=a;a++;

                }
                st=i+1;
            }
        }
        if(actor.find(line.substr(st))==actor.end())
                {
                    actor[line.substr(st)]=a;a++;
                }
    }
    myfile.close();
  }

  else cout << "Unable to open file";
}
getdata(vector<vector<int> > &gph)
{
    string line;
  ifstream myfile ("try.txt");
  if (myfile.is_open())
  {
    while ( getline (myfile,line) )
    {
        int mov=-2,st=0,n=0;vector<int> q;
        for(int i=0;i<line.size();i++)
        {
            if(line[i]==9)
                continue;
            else if(mov==-2&&line[i]=='|')
            {
                st=i+2;
                mov=movie[line.substr(0,i-1)];
            }
            else if(line[i]=='|')
            {
                q.push_back(actor[line.substr(st,i-st)]);

                st=i+1;
            }
        }
        q.push_back(actor[line.substr(st)]);

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

string getnameactor(int a)
{
    for(auto it=actor.begin();it!=actor.end();it++)
    {
        if(it->second==a)
        {
            return it->first;
        }
    }
}

string getnamemovie(int a)
{
    for(auto it=movie.begin();it!=movie.end();it++)
    {
        if(it->second==a)
        {
            return it->first;
        }
    }
    return "error";
}

void bfs( vector<vector<int> > adj,int src,int dest)
{
    queue<int> q;int v=adj.size();
    bool visited[v];
    int pred[v],dist[v];
    for (int i = 0; i < v; i++) {
        visited[i] = false;
        dist[i] = INT_MAX;
        pred[i] = -1;
    }
    visited[src] = true;
    dist[src] = 0;
    q.push(src);
  bool ans=false;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int i = 0; i < v; i++) {

            if (adj[u][i]!=-1 && visited[i] == false) {

                visited[i] = true;
                dist[i] = dist[u] + 1;
                pred[i] = u;
                q.push(i);
                if (i == dest)
                    {

                        ans=true;break;
                    }
            }

        }
        if(ans)
                break;
    }
    if(!ans)
    {
        cout<<"They are not connected";
    }
    else
    {
        vector<int> path;
        int crawl = dest;
        path.push_back(crawl);
        while (pred[crawl] != -1) {
            path.push_back(pred[crawl]);
            crawl = pred[crawl];
        }

    cout << "Shortest path length is : "
         << path.size()-1<<endl;

    for (int i = path.size() - 1; i > 0; i--)
        {
            cout<<getnameactor(path[i])<<" is in the movie "<<getnamemovie(adj[path[i]][path[i-1]]);
            cout<<" with actor "<<getnameactor(path[i-1])<<endl;;

        }
    }

}

print(vector<vector<int> > &gph)

{
    int n=gph.size();
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<gph[i][j]<<"  ";
        }
        cout<<endl;
    }
}

int main()
{
    getm(0);
    geta(0);int n=actor.size();
    vector<vector<int> > gph(n,vector<int>(n,-1));
    getdata(gph);
    string ac1,ac2;
    getline(cin,ac1);
    getline(cin,ac2);

    bfs(gph,actor[ac1],actor[ac2]);

}
