#ifndef SAD_H
#define SAD_H

namespace sda {
    using namespace std;

    void sacados(int n,int g)
{
    int i,v;
    int c[10],w[10],x[10],Z[100][100];
    for (i=1;i<=n;i++)
    {
    cout<<"   c["<<i<<"]  = ";
    sac>>c[i];
    cout<<c[i]<<endl;
    }
    cout<<endl;
    for (i=1;i<=n;i++)
    {
    cout<<"   w["<<i<<"]  = ";
    sac>>w[i];
    cout<<w[i]<<endl;
    }
    cout<<endl;
    for (v=1;v<=g;v++)
    {
        Z[v][0]=0;
    }
    for (i=1;i<=n;i++)
        {
          for (v=0;v<=g;v++)
          {
              if(v<w[i])
              {
                  Z[v][i]=Z[v][i-1];
              }
              else
              {
                  Z[v][i]=max(Z[v][i-1],Z[v-w[i]][i-1]+c[i]);
              }
          }
        }
        for (i=0;i<=n;i++)
    {
        for (v=0;v<=g;v++)
        {
            cout<<"    "<<Z[v][i];
            if(v==g)
            {
                cout<<endl;
            }
        }
    }
    cout<<endl;
    cout<<"   le cout maximum qu'on peut obtenir est : "<<Z[g][n]<<endl;
    cout<<endl;
    for (i=0;i<=n;i++)
    {
        x[i]=0;
    }
    int k=n;
    while((g>0)||(k>0))
    {
        if (Z[g][k]!=Z[g][k-1])
        {
            x[k]=x[k]+1;
            g=g-w[k];
        }
        k--;
    }

    cout<<""<<endl;
    cout<<"   On va prendre le(s) objet(s) : ";

    for (int j=1;j<=n;j++)
    {
        if (x[j]==1)
        {
            cout<<"   "<<j<<" , ";
        }
    }
}
}


#endif