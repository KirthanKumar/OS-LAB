#include<stdio.h>

void waitingtime(int proc[],int n,int burst_time[],int wait_time[]){
    wait_time[0]=0;
    for(int i=1;i<n;i++){
        wait_time[i] = burst_time[i-1] + wait_time[i-1];
    }
}
void turnaroundtime(int proc[],int n,int burst_time[],int wait_time[],int tat[]){
    for(int i=0;i<n;i++){
        tat[i] = burst_time[i] + wait_time[i];
    }
 }
 int avgtime(int proc[], int n, int burst_time[]) {
  int wait_time[n], tat[n], total_wt = 0, total_tat = 0;

  waitingtime(proc, n, burst_time, wait_time);
  turnaroundtime(proc, n, burst_time, wait_time, tat);

  printf("Process\tBurst Time\tWaiting Time\tTurnaround Time\n");

  for (int i = 0; i < n; i++) {
    total_wt = total_wt + wait_time[i];
    total_tat = total_tat + tat[i];
    printf("%d\t\t%d\t\t%d\t\t%d\n", i+1, burst_time[i], wait_time[i], tat[i]);
  }

  printf("Average waiting time = %f\n", (float)total_wt / (float)n);
  printf("Average turn around time = %f\n", (float)total_tat / (float)n);
}
int main() {
  int j,temp2,temp,i,n,burst[10],proc[10];
  printf("Enter no of processes:");
  scanf("%d",&n);
  for(i=0;i<n;i++){
    printf("Enter burst time of process %d:",i+1);
    scanf("%d",&burst[i]);
    proc[i]=i+1;
  }
  for(i=0;i<n;i++){
    for(j=i+1;j<n;j++){
        if(burst[i]>burst[j]){
            temp=burst[i];
            burst[i]=burst[j];
            burst[j]=temp;
            temp2=proc[i];
            proc[i]=proc[j];
            proc[j]=temp2;
        }
    }
  }

  avgtime(proc, n, burst);

  return 0;
}
