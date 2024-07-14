#include<stdio.h>
#include<stdlib.h>

//struct to represent a process

typedef struct 
{
    int name;
    int arrival;
    int burst;
    int completion;
    int waiting;
    int tat;


} Process;

int main(){
    //define the processes
    int n=0;
    printf("enter the number of processes\n");
    scanf("%d",&n);

    Process *processes =(Process *)malloc(n*sizeof(Process));// we make n number of such Process
    if(processes==NULL){
        printf("memory allocation failed\n");
        return 1;
    }

    //initialize the processes using a loop

    for(int i=0;i<n;i++){
       processes[i].name=i+1;//assigning a unique var name to the processes
       printf("enter the arrival time of the process %d\n",processes[i].name);
       scanf("%d",&processes[i].arrival);
       printf("enter the burst time for the process %d\n",processes[i].name);
       scanf("%d",&processes[i].burst);
       processes[i].completion=0;
       processes[i].waiting=0;
       processes[i].tat=0;
    }
    int currentTime=0;

    printf("time | process\n");
    printf("------+-------------------\n");

    //iterate through each process
    for (int i = 0; i < n; i++)
    {
        if(currentTime<processes[i].arrival){
            currentTime=processes[i].arrival;
        }//moves the current time to the arrival time of the first process
        //check if the process has arrived
        int exec_time =processes[i].burst;//adds the burst time of the current process to the execution time 
        currentTime+=exec_time;//mpves the current time forward

        //print the execution
        printf("%-5d | P%d\n",currentTime,processes[i].name);
        processes[i].completion=currentTime;
        processes[i].tat=processes[i].completion-processes[i].arrival;
        processes[i].waiting=processes[i].tat-processes[i].burst;
    }

    float avgwt=0.0;
    float avgtat=0.0;
    printf("process arrivalTime BurstTime Tat WaitingTime\n");
    for (int i = 0; i < n; i++)
    {
        printf("P%d%10d%10d%15d%20d\n",processes[i].name, processes[i].arrival,processes[i].burst,processes[i].tat,processes[i].waiting);
        avgwt=avgwt+processes[i].waiting;
        avgtat=avgtat+processes[i].tat;
    }
    printf("Average waiting time =%f\n",avgwt/n);
    printf("Average tat =%f\n",avgtat/n);
    free(processes);
    return 0;
    

}
