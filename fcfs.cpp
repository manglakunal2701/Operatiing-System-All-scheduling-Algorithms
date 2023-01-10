#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cout << "Enter the number of processess\n";
    cin >> n;
    vector<pair<int, int>> abTime;
    int aT;
    int bT;
    cout << "Enter the Burst time and arrival time \n";
    for (int i = 0; i < n; i++)
    {
        cin >> bT;
        cin >> aT;
        abTime.push_back({aT, bT});
    }
    sort(abTime.begin(), abTime.end());
    vector<pair<int, int>> startComp;
    int c = 0;
    for (int i = 0; i < n; i++)
    {
        if (abTime[i].first > c)
            c = abTime[i].first;
        startComp.push_back({c, abTime[i].second + c});
        c += abTime[i].second;
    }
    cout << endl;
    cout << "Start time and arrival time are:" << endl;
    for (auto it : startComp)
    {
        cout << it.first << " " << it.second << "\n";
    }
    float rt = 0, wt = 0;
    float tat[n];
    for (int i = 0; i < n; i++)
    {
        rt += startComp[i].first - abTime[i].first;
        cout<<rt<<" ";
        tat[i] = startComp[i].second - abTime[i].first;
        wt += tat[i] - abTime[i].second;
    }
    float tp = (float)n / startComp[n - 1].second;
    float avt = 0;
    for (int i = 0; i < n; i++)
    {
        avt += tat[i];
    }
    cout << "average rt is:" << rt / n << endl;
    cout << "average wt is:" << wt / n << endl;
    cout << "through put is:" << tp << endl;
    cout << " Average turn around time is " << (float)avt / n << endl;
    return 0;
}