#include <stdio.h>
void main()
{
    int i, NOP, sum = 0, count = 0, y, quant, wt = 0, tat = 0, at[10], bt[10], temp[10];
    float avg_wt, avg_tat;
    printf(" Total number of process in the system: ");
    scanf("%d", &NOP);
    y = NOP; 
    for (i = 0; i < NOP; i++)
    {
        printf("\n Enter the Burst time of the Process[%d]\n", i + 1);
        at[i]=0;
        printf(" \nBurst time is: \t");
        scanf("%d", &bt[i]);
        temp[i] = bt[i];
    }
    printf("Enter the Time Quantum for the process: \t");
    scanf("%d", &quant);
    printf("\n Process No \t\t Burst Time \t\t TAT \t\t Waiting Time ");
    for (sum = 0, i = 0; y != 0;)
    {
        if (temp[i] <= quant && temp[i] > 0) 
        {
            sum = sum + temp[i];
            temp[i] = 0;
            count = 1;
        }
        else if (temp[i] > 0)
        {
            temp[i] = temp[i] - quant;
            sum = sum + quant;
        }
        if (temp[i] == 0 && count == 1)
        {
            y--; 
            printf("\nProcess No[%d] \t\t %d\t\t\t\t %d\t\t\t %d", i + 1, bt[i], sum - at[i], sum - at[i] - bt[i]);
            wt = wt + sum - at[i] - bt[i];
            tat = tat + sum - at[i];
            count = 0;
        }
        if (i == NOP - 1)
        {
            i = 0;
        }
        else if (at[i + 1] <= sum)
        {
            i++;
        }
        else
        {
            i = 0;
        }
    }
    avg_wt = wt * 1.0 / NOP;
    avg_tat = tat * 1.0 / NOP;
    printf("\n Average Turn Around Time: \t%f", avg_wt);
    printf("\n Average Waiting Time: \t%f", avg_tat);
}

#include <stdio.h>

void waitingtime(int proc[], int n, int burst_time[], int wait_time[])
{
    wait_time[0] = 0;
    for (int i = 1; i < n; i++)
    {
        wait_time[i] = burst_time[i - 1] + wait_time[i - 1];
    }
}
void turnaroundtime(int proc[], int n, int burst_time[], int wait_time[], int tat[])
{
    for (int i = 0; i < n; i++)
    {
        tat[i] = burst_time[i] + wait_time[i];
    }
}
int avgtime(int proc[], int n, int burst_time[],int prior[])
{
    int wait_time[n], tat[n], total_wt = 0, total_tat = 0;

    waitingtime(proc, n, burst_time, wait_time);
    turnaroundtime(proc, n, burst_time, wait_time, tat);

    printf("Process\tBurst Time\tpriority\tWaiting Time\tTurnaround Time\n");

    for (int i = 0; i < n; i++)
    {
        total_wt = total_wt + wait_time[i];
        total_tat = total_tat + tat[i];
        printf("%d\t\t%d\t%d\t\t%d\t\t%d\n", proc[i], burst_time[i],prior[i], wait_time[i], tat[i]);
    }

    printf("Average waiting time = %f\n", (float)total_wt / (float)n);
    printf("Average turn around time = %f\n", (float)total_tat / (float)n);
}
int main()
{
    int j, temp2, temp, i, n, burst[10], proc[10],prior[10];
    printf("Enter no of processes:");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("Enter burst time of process %d:", i + 1);
        scanf("%d", &burst[i]);
        proc[i] = i + 1;
    }
    for (i = 0; i < n; i++)
    {
        printf("Enter priority time of process %d:", i + 1);
        scanf("%d", &prior[i]);
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n-i-1; j++)
        {
            if (prior[j] > prior[j+1])
            {
                temp=prior[j];
                prior[j]=prior[j+1];
                prior[j+1]=temp;
                temp = burst[j];
                burst[j] = burst[j+1];
                burst[j+1] = temp;
                temp2 = proc[j];
                proc[j] = proc[j+1];
                proc[j+1] = temp2;
            }
        }
    }

    avgtime(proc, n, burst,prior);

    return 0;
}
