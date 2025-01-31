#include <stdio.h>

struct Process {
    int id, bt, priority, wt, tat;
};

// Function to sort processes based on priority (higher priority first)
void sortByPriority(struct Process p[], int n) {
    struct Process temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (p[i].priority < p[j].priority) {  // Higher priority first
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }
}

void calculateTimes(struct Process p[], int n) {
    p[0].wt = 0; // First process has zero waiting time
    for (int i = 1; i < n; i++) {
        p[i].wt = p[i - 1].wt + p[i - 1].bt;
    }
    for (int i = 0; i < n; i++) {
        p[i].tat = p[i].wt + p[i].bt;
    }
}

void printProcesses(struct Process p[], int n) {
    printf("\nProcess\tBT\tPriority\tWT\tTAT\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t\t%d\t%d\n", p[i].id, p[i].bt, p[i].priority, p[i].wt, p[i].tat);
    }
}

int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    struct Process p[n];

    // Input process details
    for (int i = 0; i < n; i++) {
        p[i].id = i + 1;
        printf("Enter burst time and priority for process P%d: ", i + 1);
        scanf("%d %d", &p[i].bt, &p[i].priority);
    }

    // Sort by priority
    sortByPriority(p, n);

    // Calculate waiting time & turnaround time
    calculateTimes(p, n);

    // Print the table
    printProcesses(p, n);

    return 0;
}