#include <stdio.h>

#define N 3

// structure to store process details
struct Process {
	int pid;
	int burst_time;
	int arrival_time;
	int waiting_time;
	int turnaround_time;
	int completion_time;
} p[N], temp;

int main() {
	int awt = 0, atat = 0, time = 0, count = 0, min = 0, min_burst = 0;
	for (int i = 0; i < N; i++) {
		printf("Enter the arrival time and burst time for process %d: ", i + 1);
		scanf("%d %d", &p[i].arrival_time, &p[i].burst_time);
		p[i].pid = i + 1;
	}

	// sort the processes based on arrival time
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			if (p[i].arrival_time > p[j].arrival_time) {
				temp = p[i];
				p[i] = p[j];
				p[j] = temp;
			}
		}
	}
	// display the Gantt chart
	printf("\nGantt chart\n");
	printf("0");
	for (int i = 0; i < N; i++) {
		printf(" P%d %d\t", p[i].pid, p[i].completion_time);
	}
	// display the process details
	printf("\nPID\tAT\tBT\tWT\tTAT\tCT\n");
	for (int i = 0; i < N; i++) {
		printf("%d\t%d\t%d\t%d\t%d\t%d\n", p[i].pid, p[i].arrival_time, p[i].burst_time, p[i].waiting_time, p[i].turnaround_time, p[i].completion_time);
	}
	// calculate the average waiting time and average turnaround time
	printf("Average waiting time: %f\n", (float)awt / N);
	printf("Average turnaround time: %f\n", (float)atat / N);

	return 0;
}
