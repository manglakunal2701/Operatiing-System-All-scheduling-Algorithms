#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cout << "Enter the number of processess\n";
    cin >> n;
    vector<pair<int, int>> abTime;
    vector<int>remTime;
    int aT;
    int bT;
    cout << "Enter the Burst time and arrival time \n";
    for (int i = 0; i < n; i++)
    {

        cin >> bT;
        cin >> aT;
        abTime.push_back({aT, bT});
        remTime.push_back(bT);
    }
    sort(abTime.begin(), abTime.end());
    vector<pair<int, int>> startComp;
    int c = 0;
  
        if (abTime[0].first > c)
            c = abTime[0].first;
   
    priority_queue<pair<int,int>,vector<pair<int,int>>>pq;
    
    pq.push({abTime[0].second,-1});
    int i=1;
    while( !pq.empty()){
        
        if(pq.top().first > 0){
           
            int bt= pq.top().first;
           
            int aT = pq.top().second;
            pq.pop();
            pq.push({bt-1,aT});
        }
        if(pq.top().second==-1){
           int t= pq.top().first;
           pq.pop();
           pq.push({t,c});
        }
        cout<<c<<pq.top().second<<" ";
        c=c+1;
        if(pq.top().first==0){
            
            startComp.push_back({pq.top().second, c});
            pq.pop();
        }
        while(1){
            if(i<n && abTime[i].first<= c){
            pq.push({abTime[i].second,-1});
            i++;
            }
            else{
                break;
            }
        }
    }
    
    cout << endl;
    cout << "Start time and completion time are:" << endl;
    for (auto it : startComp)
    {
        cout << it.first << " " << it.second << "\n";
    }
    float rt = 0, wt = 0;
    float tat[n];
    for (int i = 0; i < n; i++)
    {
        rt += startComp[i].first - abTime[i].first;
       // cout<<rt<<" ";
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