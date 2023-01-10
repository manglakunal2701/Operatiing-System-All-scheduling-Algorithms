// #include<iostream>
// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//     int n;
//     cout<<"Enter the number of processes"<<endl;
//     cin>>n;
//     int tq;
//     cout<<"Enter Time quonta"<<endl;
//     cin>>tq;
//     vector<pair<int,int>>abTime;
//     vector<int>remainingBt;
//     cout<<"Enter the burst time and arrival time"<<endl;
//     int bt,at;
//     for(int i=0;i<n;i++){
//         cin>>bt;
//         cin>>at;
//         abTime.push_back({at,bt});
//         remainingBt.push_back(bt);
//     }
//     sort(abTime.begin(),abTime.end());
//     vector<pair<int,int>>startComp;
//     int c=0;
//     if (abTime[0].first > c)
//             c = abTime[0].first;
//     queue<pair<int,int>>q;
//     q.push({abTime[0].second,c});
//     while(!q.empty()){
//         int bT= q.front().first;
//         q.pop();
//         if(remainingBt[i]>tq){

//         }

//     }

    

    
//     return 0;
// }
#include<stdio.h>

void calcTime(int p[], int n, int bt[], int tq) {
    int total_wt = 0, total_tat = 0, num = n, i = 0, sum = 0, count = 0;
    int temp[n];
    for (int i = 0; i < n; ++i)
        temp[i] = bt[i];
    
    printf("\nProcesses | Burst time | Waiting time | Turn around time\n");
    while (num != 0) {
        if (temp[i] <= tq && temp[i] > 0) {
            sum += temp[i];






            temp[i] = 0;
            count = 1;
        }
        else if (temp[i] > 0) {
            temp[i] -= tq;
            sum += tq;
        }

        if (temp[i] == 0 && count == 1) {
            --num;
            printf("   %d ",p[i]);
            printf("       %d ", bt[i]);
            printf("              %d",sum-bt[i]);
            printf("                  %d\n",sum);
            total_wt += (sum - bt[i]);
            total_tat += sum;
            count = 0;
        }

        if (i == n - 1)
            i = 0;
        else
            ++i;
    }
    float avgw = (float)total_wt / (float)n;
    float avgt = (float)total_tat / (float)n;

    printf("\nAverage waiting time = %.2f \n", avgw);
    printf("Average turn around time = %.2f \n", avgt);
}

int main() {
    int n, tq;
    printf("Enter no. of processes: ");
    scanf("%d",&n);
    int burst_time[n],processes[n];
  
    for (int i = 0; i < n; ++i) {
        printf("\nEnter process ID: ");
        scanf("%d", &processes[i]);
        printf("Enter burst time: ");
        scanf("%d", &burst_time[i]);   
    }

    printf("\nEnter Time Quanta: ");
    scanf("%d", &tq);

    calcTime(processes, n,  burst_time, tq);
    return 0;		}