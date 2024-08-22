#include<bits/stdc++.h>
using namespace std;
int main()
{
    cout<<"JAHANGIR HUSSSEN "<<endl<<"CSE2201025011"<<endl<<"25A1"<<endl<<endl;
    cout<<"This is First Come First Service (FCFS) "<<endl;
    cout<<"Enter how many process you want"<<endl;
    int n;
    cin>>n;
    vector<int> Brust_time(n),waiting_time(n);
    cout << "Enter " << n << " Burst times separated by spaces: " << endl;
    for(int i=0; i<n; i++)
    {
        cin>>Brust_time[i];
    }


    for(int i=1; i<n; i++)
    {
        waiting_time[i]=waiting_time[i-1] + Brust_time[i-1];
    }

    cout<<"| Process   |"<<" waiting_time |"<<endl;
    float avg_wt=0;

    for(int i=0; i<n; i++)
    {
        cout<<"   P"<<i+1<<"           "<<waiting_time[i]<<endl;
        avg_wt=avg_wt + waiting_time[i];


    }

    cout<<"Average waiting time is = "<<avg_wt /n<<endl;



    return 0;
}

