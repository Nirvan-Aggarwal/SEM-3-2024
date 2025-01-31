#include<stdio.h> 
 
void findWaitingTime(int processes[], int n, int burst_time[], int waiting_time[]) { 
    waiting_time[0] = 0;  // First process has 0 waiting time 
    for (int i = 1; i < n; i++) { 
        waiting_time[i] = burst_time[i-1] + waiting_time[i-1]; 
    } 
} 
 
void findTurnAroundTime(int processes[], int n, int burst_time[], int waiting_time[], int tat[]) { 
    for (int i = 0; i < n; i++) { 
        tat[i] = burst_time[i] + waiting_time[i]; 
    } 
} 
 
void findAvgTime(int processes[], int n, int burst_time[]) { 
    int waiting_time[n], tat[n]; 
    int total_wt = 0, total_tat = 0; 
 
    findWaitingTime(processes, n, burst_time, waiting_time); 
    findTurnAroundTime(processes, n, burst_time, waiting_time, tat); 
 
    printf("Processes   Burst time   Waiting time   Turn around time\n"); 
    for (int i = 0; i < n; i++) { 
        total_wt += waiting_time[i]; 
        total_tat += tat[i]; 
        printf(" %d\t\t%d\t\t%d\t\t%d\n", (i+1), burst_time[i], waiting_time[i], tat[i]); 
    } 
 
    printf("Average waiting time = %.2f\n", (float)total_wt / n); 
    printf("Average turn around time = %.2f\n", (float)total_tat / n); 
} 
 
int main() { 
    int processes[] = {1, 2, 3, 4}; 
    int n = sizeof processes / sizeof processes[0]; 
    int burst_time[] = {6, 2, 8, 3}; 
 
    findAvgTime(processes, n, burst_time); 
    return 0; 
}