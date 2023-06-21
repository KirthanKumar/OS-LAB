#include<stdio.h>

void waitingTime(int processors[], int n, int wt[], int bt[]){
                 wt[0] = 0;
                 int i;
                 for(i=1; i<n; i++){
                    wt[i] =bt[i-1] + wt[i-1];
                 }
}

void turnAroundTime(int processors[], int n, int tat[], int bt[], int wt[]){
                 int i;
                 for(i=0; i<n; i++){
                    tat[i] =bt[i] + wt[i];
                 }
}

void avgTime(int processors[], int n, int bt[] ){
    int waitTime[n], tatTime[n], totalWT = 0, totalTAT = 0;
    waitingTime(processors, n, waitTime, bt);
    turnAroundTime(processors, n, tatTime, bt, waitTime);
    int i;
    for(i=0; i<n; i++){
        totalWT += waitTime[i];
        totalTAT += tatTime[i];
        printf("\nProcessor\tburstTime\twaitTime\t turnAtime");
        printf("\n%d\t%d\t%d\t%d", processors[i], bt[i], waitTime[i], tatTime[i]);
    }
    float s1 = (float)totalWT/(float)n;
    float s2 = (float)totalTAT/(float)n;
    printf("\nAverage waiting time = %f",s1 );
    printf("\nAverage turn around time = %f", s2);
}

int main(){
    int n;
    printf("\nEnter number of processors: ");
    scanf("%d", &n);
    int processors[n];
    int burstTime[n];
    int i;
    for(i=0; i<n; i++){
        processors[i] = i+1;
        printf("Enter burst time for processor %d: ", i+1);
        scanf("%d", &burstTime[i]);
    }
    avgTime(processors, n, burstTime);
    return 0;
}
