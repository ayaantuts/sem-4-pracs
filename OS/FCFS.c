#include <stdio.h>
#include <conio.h>
// Control the number of processes
#define MAX 3

// Structure to store process details
struct Process {
	int id;
	int AT;
	int BT;
	int waiting;
} p[MAX], temp;

int main() {
	int i, j, clock = 0, AWT = 0, ATAT = 0;
	// Array to store Gantt chart
	int chart[MAX + 1];
	printf("FCFS Process Scheduling Technique");
	for (i = 0; i < MAX; i++) {
		printf("\nEnter the arrival time (in ms) of process %d: ", i + 1);
		scanf("%d", &p[i].AT);
		printf("\nEnter the burst time (in ms) of process %d: ", i + 1);
		scanf("%d", &p[i].BT);
		p[i].id = i + 1;
	}
	// Display the process details
	printf("\nProcess\t| AT\t|BT");
	for (i = 0; i < MAX; i++)
		printf("\n%d\t| %d\t| %d ", p[i].id, p[i].AT, p[i].BT);
	
	// Sort the processes based on arrival time
	for (i = 0; i < MAX; i++) {
		for (j = i; j < MAX; j++)
			if (p[i].AT > p[j].AT) {
				temp = p[i];
				p[i] = p[j];
				p[j] = temp;
			}
	}
	chart[0] = 0;
	printf("\nGantt chart");
	printf("\nPID\t| Enter\t| Exit");
	for (i = 0; i < MAX; i++) {
		p[i].waiting = clock;
		clock += p[i].BT;
		chart[i + 1] = clock;
		printf("\nP%d\t| %d\t| %d", p[i].id, p[i].waiting, clock);
	}
	// Calculate the average waiting time and average turnaround time
	for (i = 0; i < MAX; i++)
		AWT += p[i].waiting;
	printf("\nAverage waiting time: %fms", (float) AWT / MAX);
	for (i = 0; i < MAX; i++)
		ATAT += chart[i] - p[i].AT;
	ATAT += chart[MAX];
	printf("\nAverage turnaround time: %fms", (float) ATAT / MAX);
}