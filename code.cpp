#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int N;
int arr[100][100];
int cash[100];

void reset()
{
    N=0;
    return;
}

void input()
{
    if(N==0)
    {
        cout<<"Enter the number of people : ";
        cin>>N;
        cout<<endl;
    }
    while(1)
    {
        int c,d,a;
        cout<<"Enter the index of creditor : ";
        cin>>c;
        cout<<endl;
        cout<<"Enter the index of debitor : ";
        cin>>d;
        cout<<endl;
        cout<<"Enter amout to be paid : ";
        cin>>a;
        cout<<endl;
        if(c>=N || d>=N)
            cout<<"Invalid Input"<<endl<<endl;
        else
        {
            arr[d][c]=a;
            arr[c][d]=-a;
        }
        cout<<"Do you want to add more enteries? "<<endl<<endl<<"Press x for NO and any other key for YES : ";
        char cr;
        cin>>cr;
        cout<<endl;
        if(cr=='x' || cr=='X')
            break;
    }
    return;
}

void print()
{
    if(N==0)
    {
        cout<<"No existing enteries"<<endl;
        return;
    }
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
            cout<<arr[i][j]<<"  ";
        cout<<endl<<endl;
    }
    return;
}

pair<int,int> xtreme()
{
    pair<int,int>ans=make_pair(0,0);
    for(int i=0; i<N; i++)
    {
        if(cash[i]>cash[ans.first])
            ans.first=i;
        if(cash[i]<cash[ans.second])
            ans.second=i;
    }
    return ans;
}

void helper()
{
    pair<int,int> p = xtreme();
    int maximum = p.first, minimum = p.second;
    if(cash[maximum]==0 && cash[minimum]==0)
        return;
    int curr = min(-cash[minimum], cash[maximum]);
    cash[maximum]-=curr;
    cash[minimum]+=curr;
    cout<<minimum<<" needs to pay "<<curr<<" amount to "<<maximum<<endl<<endl;
    arr[minimum][maximum]-=curr;
    arr[maximum][minimum]+=curr;
    return helper();
}

void simplify()
{
    if(N==0)
        return;
    for(int i=0; i<N; i++)
        cash[i]=0;
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            cash[i]+=arr[i][j];
    return helper();
}

int main()
{
    cout<<endl<<"WELCOME"<<endl<<endl;
    reset();
    int choice=-1;
    while(1)
    {
        cout<<"Select from the following options"<<endl<<endl;
        cout<<"1. Create or edit a cash-flow database"<<endl<<endl;
        cout<<"2. View the cash-flow graph"<<endl<<endl;
        cout<<"3. Simplify the cash-flow and display amount to be debted and credited for each user"<<endl<<endl;
        cout<<"4. Reset"<<endl<<endl;
        cout<<"5. Quit"<<endl<<endl;
        cout<<"Enter your desired choice : ";
        cin>>choice;
        cout<<endl;
        if(choice==1)
            input();
        else if(choice==2)
            print();
        else if(choice==3)
            simplify();
        else if(choice==4)
            reset();
        else if(choice==5)
            break;
        else
            cout<<"Invalid input"<<endl;
    }
    return 0;
}