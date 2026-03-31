#include <stdio.h>

int main() {
    int i, n, time_quantum, total = 0, counter = 0;
    int arrival_time[20], burst_time[20], temp[20];
    int wait_time = 0, turnaround_time = 0;
    float average_wait_time, average_turnaround_time;

    printf("Enter total number of processes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        printf("\nEnter details of Process[%d]\n", i + 1);
        printf("Arrival Time: ");
        scanf("%d", &arrival_time[i]);
        printf("Burst Time: ");
        scanf("%d", &burst_time[i]);
        temp[i] = burst_time[i]; // Store original burst time
    }

    printf("\nEnter Time Quantum: ");
    scanf("%d", &time_quantum);

    int remaining = n;  // Remaining processes
    int current_time = 0;

    printf("\nProcess ID\tBurst Time\tTurnaround Time\tWaiting Time\n");

    while(remaining != 0) {
        counter = 0;
        for(i = 0; i < n; i++) {
            if(temp[i] > 0 && arrival_time[i] <= current_time) {
                if(temp[i] <= time_quantum) {
                    current_time += temp[i];
                    temp[i] = 0;
                    counter = 1;

                    int tat = current_time - arrival_time[i];
                    int wt = tat - burst_time[i];

                    turnaround_time += tat;
                    wait_time += wt;

                    printf("Process[%d]\t%d\t\t%d\t\t%d\n", i + 1, burst_time[i], tat, wt);
                    remaining--;
                } else {
                    temp[i] -= time_quantum;
                    current_time += time_quantum;
                }
            }
        }
        // If no process has arrived yet, advance time
        int any_arrived = 0;
        for(i = 0; i < n; i++) {
            if(temp[i] > 0 && arrival_time[i] <= current_time) {
                any_arrived = 1;
                break;
            }
        }
        if(!any_arrived) current_time++;
    }

    average_wait_time = (float)wait_time / n;
    average_turnaround_time = (float)turnaround_time / n;

    printf("\nAverage Waiting Time: %f", average_wait_time);
    printf("\nAverage Turnaround Time: %f\n", average_turnaround_time);

    return 0;
}
