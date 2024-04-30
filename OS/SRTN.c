#include <stdio.h>
#include <limits.h>

#define N 3

struct Process {
  int pid;
  int burst_time;
  int arrival_time;
  int remaining_time;
  int waiting_time;
  int turnaround_time;
  int completion_time;
} p[N];

int main() {
  int awt = 0, atat = 0, time = 0, count = 0, min = 0, min_index = 0;
  for (int i = 0; i < N; i++) {
    printf("Enter the arrival time and burst time for process %d: ", i + 1);
    scanf("%d %d", &p[i].arrival_time, &p[i].burst_time);
    p[i].pid = i + 1;
    p[i].remaining_time = p[i].burst_time;
  }

  for (int i = 0; i < N - 1; i++) {
    for (int j = i + 1; j < N; j++) {
      if (p[i].arrival_time > p[j].arrival_time) {
        struct Process temp = p[i];
        p[i] = p[j];
        p[j] = temp;
      }
    }
  }

  while (count < N) {
    min = INT_MAX;
    for (int i = 0; i < N; i++) {
      if (p[i].arrival_time <= time && p[i].remaining_time < min && p[i].remaining_time > 0) {
        min = p[i].remaining_time;
        min_index = i;
      }
    }

    p[min_index].remaining_time--;
    time++;

    if (p[min_index].remaining_time == 0) {
      count++;
      p[min_index].completion_time = time;
      p[min_index].turnaround_time = p[min_index].completion_time - p[min_index].arrival_time;
      p[min_index].waiting_time = p[min_index].turnaround_time - p[min_index].burst_time;
      awt += p[min_index].waiting_time;
      atat += p[min_index].turnaround_time;
    }
  }

  printf("\nGantt chart\n");
  printf("0");
  for (int i = 0; i < N; i++) {
    printf(" P%d %d\t", p[i].pid, p[i].completion_time);
  }

  printf("\nPID\tAT\tBT\tWT\tTAT\tCT\n");
  for (int i = 0; i < N; i++) {
    printf("%d\t%d\t%d\t%d\t%d\t%d\n", p[i].pid, p[i].arrival_time, p[i].burst_time, p[i].waiting_time, p[i].turnaround_time, p[i].completion_time);
  }

  printf("Average waiting time: %f\n", (float)awt / N);
  printf("Average turnaround time: %f\n", (float)atat / N);

  return 0;
}