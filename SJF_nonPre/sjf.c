#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>


//struct to represent a process

typedef struct {
    int pid;
    int arrival_time;
    int burst_time;
}Process;


//function to sort the processes based on burst time

void sort(Process processes[],int n){
    for (int i = 0; i < n-1; i++)
    {
        for (int j = 0; j < n-i-1; j++)
        {
            if(processes[j].burst_time>processes[j+1].burst_time){
                Process temp = processes[j];
                processes[j]=processes[j+1];
                processes[j+1]=temp;
            }
        }
        
    }
    
}

//function to calculate the waiting time and turnaround time

void calcTime(Process processes[],int n,int wt[],int tat[]){
    wt[0]=0;
    tat[0]=wt[0]+processes[0].burst_time;
    for (int i = 1; i < n; i++)
    {
        wt[i]=wt[i-1]+processes[i-1].burst_time;
        tat[i]=wt[i]+processes[i].burst_time;
    }
    
}

//function to calculate the average waiting time and turnaround time 

void calculateAvgTimes(Process processes[],int n){
    int wt[n];
    int tat[n];
    calcTime(processes,n,wt,tat);

    float avg_wt=0,avg_tat=0;
    printf("PID\t WT\t TAT\n");
    for (int i = 0; i < n; i++)
    {
        avg_wt+=wt[i];
        avg_tat+=tat[i];
        printf("%d\t %d\t %d\n",processes[i].pid,wt[i],tat[i]);
    }

    printf("average waiting time=%.2f\n",avg_wt/n);
    printf("average turnaround time =%.2f\n",avg_tat/n);
    
}


int main(){
    int n=0;
    printf("enter the number of processes\n");
    scanf("%d",&n);

    Process *processes =(Process *)malloc(n*sizeof(Process));

    for (int i = 0; i < n; i++)
    {
        processes[i].pid=i+1;
        printf("enter the arrival time of process %d\n",processes[i].pid);
        scanf("%d",&processes[i].arrival_time);
        printf("enter the burst time of process %d\n",processes[i].pid);
        scanf("%d",&processes[i].burst_time);
    }

    sort(processes,n);

    calculateAvgTimes(processes,n);
    return 0;

    
}
