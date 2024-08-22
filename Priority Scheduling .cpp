#include <bits/stdc++.h>
using namespace std;
int main()
{
    cout<<"JAHANGIR HUSSSEN "<<endl<<"CSE2201025011"<<endl<<"25A1"<<endl<<endl;
    cout<<"This is Priority Scheduling "<<endl;
    cout << "Enter how many processes you want: ";
    int n;
    cin >> n;
    vector<tuple<int, int, int>> p(n);

    cout << "Enter priority and burst time for each process:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> get<0>(p[i]) >> get<1>(p[i]);
        get<2>(p[i]) = i + 1;
    }

    sort(p.begin(), p.end());

    vector<int> waiting_time(n, 0);
    for (int i = 1; i < n; i++)
    {
        waiting_time[i] = waiting_time[i - 1] + get<1>(p[i - 1]);
    }

    float avg = 0;
    cout << "| Process | Waiting Time |\n";
    for (int i = 0; i < n; i++)
    {
        cout << "   P" << get<2>(p[i]) << "          " << waiting_time[i] << endl;
        avg =avg  +  waiting_time[i];
    }
    cout << "Average waiting time: " << avg / n << endl;

    return 0;
}
