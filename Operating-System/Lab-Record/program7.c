#include <stdio.h>

struct Process {
    int id, bt, wt, tat, remaining_bt;
};

void roundRobinScheduling(struct Process p[], int n, int quantum) {
    int time = 0, done;
    
    do {
        done = 1;
        for (int i = 0; i < n; i++) {
            if (p[i].remaining_bt > 0) {
                done = 0; // There is at least one process left
                
                if (p[i].remaining_bt > quantum) {
                    time += quantum;
                    p[i].remaining_bt -= quantum;
                } else {
                    time += p[i].remaining_bt;
                    p[i].tat = time;  // Completion time - Arrival time (0)
                    p[i].remaining_bt = 0;
                }
            }
        }
    } while (!done);

    // Calculate waiting time
    for (int i = 0; i < n; i++) {
        p[i].wt = p[i].tat - p[i].bt;
    }
}

void printProcesses(struct Process p[], int n) {
    printf("\nProcess\tBT\tWT\tTAT\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\n", p[i].id, p[i].bt, p[i].wt, p[i].tat);
    }
}

int main() {
    int n, quantum;
    
    printf("Enter number of processes: ");
    scanf("%d", &n);
    
    struct Process p[n];

    // Input process details
    for (int i = 0; i < n; i++) {
        p[i].id = i + 1;
        printf("Enter burst time for process P%d: ", i + 1);
        scanf("%d", &p[i].bt);
        p[i].remaining_bt = p[i].bt; // Initial remaining burst time
    }

    printf("Enter time quantum: ");
    scanf("%d", &quantum);

    // Perform Round Robin Scheduling
    roundRobinScheduling(p, n, quantum);

    // Print result
    printProcesses(p, n);

    return 0;
}
