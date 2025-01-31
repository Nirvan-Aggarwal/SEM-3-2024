#include <stdio.h>

// Structure to store process details
typedef struct {
    int pid;       // Process ID
    int burst;     // Burst time
    int wait;      // Waiting time
    int turnaround;// Turnaround time
} Process;

// Function to sort processes by burst time (Shortest Job First)
void sortByBurstTime(Process p[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (p[i].burst > p[j].burst) {
                Process temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }
}

// Function to calculate waiting and turnaround times
void calculateTimes(Process p[], int n) {
    p[0].wait = 0;
    p[0].turnaround = p[0].burst;
    
    for (int i = 1; i < n; i++) {
        p[i].wait = p[i - 1].wait + p[i - 1].burst;
        p[i].turnaround = p[i].wait + p[i].burst;
    }
}

// Function to display process details
void displayProcesses(Process p[], int n) {
    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t\t%d\t\t%d\t\t%d\n", p[i].pid, p[i].burst, p[i].wait, p[i].turnaround);
    }
}

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    Process p[n];
    
    // Input process details
    for (int i = 0; i < n; i++) {
        p[i].pid = i + 1;
        printf("Enter burst time for Process P%d: ", p[i].pid);
        scanf("%d", &p[i].burst);
    }
    
    // Sort processes based on burst time (SJF Scheduling)
    sortByBurstTime(p, n);
    
    // Calculate waiting time and turnaround time
    calculateTimes(p, n);
    
    // Display the process execution details
    displayProcesses(p, n);
    
    // Calculate and display average waiting and turnaround time
    float avgWait = 0, avgTurnaround = 0;
    for (int i = 0; i < n; i++) {
        avgWait += p[i].wait;
        avgTurnaround += p[i].turnaround;
    }
    avgWait /= n;
    avgTurnaround /= n;
    
    printf("\nAverage Waiting Time: %.2f", avgWait);
    printf("\nAverage Turnaround Time: %.2f\n", avgTurnaround);
    
    return 0;
}
