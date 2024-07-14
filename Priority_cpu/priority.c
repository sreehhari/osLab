#include <stdio.h>
#include <stdbool.h>

// Struct to represent a process
struct Process {
    int processNo;
    int arrivalTime;
    int burstTime;
    int priority;
};

// Function to sort processes based on arrival time and priority
void sortProcesses(struct Process proc[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (proc[j].arrivalTime < proc[i].arrivalTime ||
                (proc[j].arrivalTime == proc[i].arrivalTime && proc[j].priority < proc[i].priority)) {
                // Swap processes
                struct Process temp = proc[i];
                proc[i] = proc[j];
                proc[j] = temp;
            }
        }
    }
}

// Function to calculate waiting time for each process
void calculateWaitingTime(struct Process proc[], int wt[], int n) {
    wt[0] = 0; // Waiting time for the first process is zero
    int pstart[n];
    pstart[0] = proc[0].arrivalTime;
    
    for (int i = 1; i < n; i++) {
        pstart[i] = pstart[i - 1] + proc[i - 1].burstTime;
        wt[i] = pstart[i] - proc[i].arrivalTime;
        
        // If waiting time is negative, it means the CPU was idle
        if (wt[i] < 0) {
            pstart[i] = proc[i].arrivalTime;
            wt[i] = 0;
        }
    }
}

// Function to calculate turnaround time for each process
void calculateTurnaroundTime(struct Process proc[], int wt[], int tat[], int n) {
    for (int i = 0; i < n; i++) {
        tat[i] = proc[i].burstTime + wt[i];
    }
}

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process proc[n];
    int wt[n], tat[n];

    printf("Enter process details (arrival time, burst time, priority):\n");
    for (int i = 0; i < n; i++) {
        proc[i].processNo = i + 1;
        printf("P%d: ", i + 1);
        scanf("%d %d %d", &proc[i].arrivalTime, &proc[i].burstTime, &proc[i].priority);
    }

    // Sort processes based on arrival time and priority
    sortProcesses(proc, n);

    // Calculate waiting time and turnaround time
    calculateWaitingTime(proc, wt, n);
    calculateTurnaroundTime(proc, wt, tat, n);

    // Display results
    float awt = 0, atat = 0;
    printf("\nProcess\tArrival Time\tBurst Time\tPriority\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", proc[i].processNo, proc[i].arrivalTime,
               proc[i].burstTime, proc[i].priority, wt[i], tat[i]);
        awt += wt[i];
        atat += tat[i];
    }
    printf("Average Waiting Time = %.2f\n", awt / n);
    printf("Average Turnaround Time = %.2f\n", atat / n);

    return 0;
}
