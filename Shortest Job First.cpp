#include <bits/stdc++.h>
using namespace std;

int main()
{
    cout << "JAHANGIR HUSSEN " << endl << "CSE2201025011" << endl << "25A1" << endl << endl;
        cout<<"1 This is Shortest Job First (SJF) "<<endl;

    cout << "Enter how many processes you want: ";
    int n;
    cin >> n;

    vector<pair<int, int>> p(n);

    cout << "Enter " << n << " Burst times separated by spaces:  " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> p[i].first;
        p[i].second = i + 1;
    }

    sort(p.begin(), p.end());

    vector<int> waiting_time(n);
    waiting_time[0] = 0;
    for (int i = 1; i < n; i++)
    {
        waiting_time[i] = waiting_time[i - 1] + p[i - 1].first;
    }

    cout << "| Process | Waiting Time |" << endl;
    float avg_wt = 0;
    for (int i = 0; i < n; i++)
    {
        cout << "   P" << p[i].second << "         " << waiting_time[i] << endl;
        avg_wt =avg_wt + waiting_time[i];
    }

    cout << "Average waiting time is = " << avg_wt / n << endl;

    return 0;
}
