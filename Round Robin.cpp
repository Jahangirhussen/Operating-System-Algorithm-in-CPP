#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cout<<"JAHANGIR HUSSSEN "<<endl<<"CSE2201025011"<<endl<<"25A1"<<endl<<endl;
    cout << "Enter how many song you want: ";
    cin >> n;
    vector<tuple<int, int, int>> p(n);

    cout << "Enter "<<n<<" burst time for each Song :\n";
    for (int i = 0; i < n; i++)
    {
        cin >> get<1>(p[i]);
        get<0>(p[i]) = i + 1;
        get<2>(p[i]) = get<1>(p[i]);
    }

    int q;
    cout << "Enter time quantum: ";
    cin >> q;

    vector<int> waiting_time(n);
    int total_time_need  = 0, need_process = 0;

    while (need_process < n)
    {
        for (int i = 0; i < n; i++)
        {
            if (  get<2>(p[i])   > 0)
            {
                int finish_time = min(  get<2>(p[i])  , q);
                total_time_need  += finish_time;
                get<2>(p[i])      -= finish_time;

                if ( get<2>(p[i])  == 0)
                {
                    need_process++;
                    waiting_time[i] = total_time_need  - get<1>(p[i]);
                }
            }
        }
    }

    float avg_wt = 0;
    cout << "| Process | Waiting Time |\n";
    for (int i = 0; i < n; i++)
    {
        cout << "   P" <<   get<0>(p[i])    << "          " << waiting_time[i] << endl;
        avg_wt += waiting_time[i];
    }
    cout << "Average waiting total_time_need : " << avg_wt / n << endl;

    return 0;
}
