#include <bits/stdc++.h>
using namespace std;
int main()
{
    int NoP=0, NoR=0, i=0, j=0, F=0, T=0;
    cout<<"Enter the number of processes :   ";
    cin>>NoP;
    cout<<"Enter the number of Resources :   ";
    cin>>NoR;
    int C[NoP][NoR], All[NoP][NoR], Av[NoR], N[NoP][NoR], Rv[NoR];
    bool PF[NoP];
    for (i=0; i<NoP ; i++)      //entering the claim matrix
        for (j=0; j<NoR ; j++)
        {
            cout<< "Enter P"<<i+1<<" and R"<<j+1<<" Claim :     ";
            cin>>C[i][j];
        }
    for (i=0; i<NoP ; i++)      //entering the Allocation matrix
        for (j=0; j<NoR ; j++)
        {
            cout<< "Enter P"<<i+1<<" and R"<<j+1<<" Allocation :    ";
            cin>>All[i][j];
        }
    for (j=0; j<NoR ; j++)     //entering the Available Resource matrix
    {
        cout<<"R"<<j+1<<" Available Resources :   ";
        cin>>Av[j];
    }
    for (j=0; j<NoR ; j++)
        Rv[j]=Av[j];
    for (i=0; i<NoP ; i++)      //Calculating the Needs matrix
        for (j=0; j<NoR ; j++)
        {
            N[i][j]=C[i][j]-All[i][j];
            if (N[i][j]<0)
                N[i][j]=0;
        }
    cout<<"--------Needs Matrix------------------------------------------------------------"<<endl;
    for (i=0; i<NoP ; i++)       //Printing the Needs matrix
    {
        for (j=0; j<NoR ; j++)
            cout<<"         "<<N[i][j];
        cout<<endl;
    }
    cout<<"--------------------------------------------------------------------------------\n\n";
    for (i=0; i<NoP ; i++)      //Calculating the Resource Vector matrix
    {
        for (j=0; j<NoR ; j++)
        {
            Rv[j]+=All[i][j];
        }
        cout<<endl;
    }
    cout<<endl<<"--------Resource Vector Matrix--------------------------------------------------"<<endl;
    for (j=0; j<NoR ; j++)     //Printing the Resource Vector matrix
        cout<<"         "<<Rv[j];
    cout<<"\n--------------------------------------------------------------------------------\n\n";
    while (true)              //checking whether the system is safe or not
    {
        for (i=0; i<NoP ; i++)
        {
            if (PF[i]==false)
            {
                for (j=0; j<NoR ; j++)
                {
                    if ((N[i][j])<=Av[j])
                    {
                        PF[i]=true;
                        continue;
                    }
                    else
                    {
                        PF[i]=false;
                        break;
                    }
                }
                if (PF[i]==true)
                {
                    for (j=0; j<NoR; j++)
                        Av[j]+=All[i][j];
                    cout<<"P"<<i+1<<" will run\n";
                    F++;
                }
                else
                    cout<<"P"<<i+1<<" won't run\n";
                if(((i+1) == NoP && F == T))
                {
                    cout<<"\n--------------------------------------------------------------------------------\n\n";
                    cout << "The system is unsafe" << endl;
                    exit(1);
                }
                else if(F == NoP)
                {
                    cout<<"\n--------------------------------------------------------------------------------\n\n";
                    cout << "The system is safe" << endl;
                    goto E;
                }
                else if((i+1) == NoP)
                {
                    T = F;
                    cout<<"--------------------------------------------------------------------------------\n\n";
                }
            }
        }
    }
E:
    cout<<"\n\n";
    cout<<"--------Available Resource Matrix-----------------------------------------------\n";
    for (j=0; j<NoR ; j++)
        cout<<"         "<<Av[j];
    cout<<"\n--------------------------------------------------------------------------------\n\n";
    return 0;
}
