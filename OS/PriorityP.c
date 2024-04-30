#include<stdio.h>
#define PROCESSES 4

struct Process {
	int id;
	int priority;
	int arrival_time;
	int burst_time;
	int waiting_time;
	int turnaround_time;
	int completed;
	int remaining_time;
} process[PROCESSES];

void sort() {
	for (int i = 0; i < PROCESSES; i++) {
		for (int j = i + 1; j < PROCESSES; j++) {
			if (process[i].arrival_time > process[j].arrival_time) {
				struct Process temp = process[i];
				process[i] = process[j];
				process[j] = temp;
			}
		}
	}
}

void priorityP() {
	double awt = 0, atat = 0;
	int time = 0, n = PROCESSES;
	printf("\n0 | ");
	for (time = 0; n > 0; time++) {
		int min = 9999, index = -1;
		for (int i = 0; i < PROCESSES; i++) {
			if (process[i].arrival_time <= time && process[i].completed != 1 && process[i].priority < min) {
				min = process[i].priority;
				index = i;
			}
		}
		if (index != -1) {
			process[index].remaining_time--;
			printf("P%d | %d | ", process[index].id, time + 1);
			if (process[index].remaining_time == 0) {
				process[index].waiting_time = time - process[index].arrival_time - process[index].burst_time + 1;
				process[index].turnaround_time = time - process[index].arrival_time + 1;
				awt += process[index].waiting_time;
				atat += process[index].turnaround_time;
				process[index].completed = 1;
				n--;
			}
		}
	}
	awt = awt / (double) PROCESSES;
	atat = atat / (double) PROCESSES;
	printf("\nAverage Waiting Time: %lf\n", awt);
	printf("Average Turnaround Time: %lf\n", atat);
}

void display() {
	printf("ID\tPriority\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n");
	for (int i = 0; i < PROCESSES; i++) {
		printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", process[i].id, process[i].priority, process[i].arrival_time, process[i].burst_time, process[i].waiting_time, process[i].turnaround_time);
	}
}

void input() {
	for (int i = 0; i < PROCESSES; i++) {
		process[i].id = i + 1;
		// printf("Enter the arrival time of process %d: ", i + 1);
		scanf("%d", &process[i].arrival_time);
		// printf("Enter the burst time of process %d: ", i + 1);
		scanf("%d", &process[i].burst_time);
		// printf("Enter the priority of process %d: ", i + 1);
		scanf("%d", &process[i].priority);
		process[i].completed = 0;
		process[i].remaining_time = process[i].burst_time;
	}
}

int main() {
	printf("Priority Scheduling (Preemptive)\n");
	input();
	sort();
	priorityP();
	display();
	return 0;
}

/*
1 8 1
0 9 2
3 4 3
2 5 4
*/