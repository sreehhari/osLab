#include<stdio.h>

//structure to represent a process

struct process{
    int id;
    int burst_time;
};


//function to simulate Round Robin scheduling
void roundRobin(struct process processes[],int n,int time_quantum){
    int remaining_time[n];
    int wt[n];
    int tat[n];

    for(int i=0;i<n;i++){
        remaining_time[i]=processes[i].burst_time;//fills up the remaining time array with the burst times of the processes
        
    }

    int current_time=0;
    int completed=0;
    

    while(completed<n){
        int flag=0;
        for (int i = 0; i < n; i++)
        {
            if (remaining_time[i]>0)
            {
                flag=1;
                if (remaining_time[i]<=time_quantum)
                {
                    current_time+=remaining_time[i];
                    remaining_time[i]=0;
                    printf("Process P%d completed at time %d\n",processes[i].id,current_time);
                    tat[i]=current_time;
                    wt[i]=tat[i]-processes[i].burst_time;
                    printf("process P%d WT=%d TAT=%d\n",processes[i].id,wt[i],tat[i]);
                    completed++;
                }else{
                    current_time+=time_quantum;
                    remaining_time[i]-=time_quantum;
                }
                
            }
            
        }
        if(!flag){
            break;
        }
        

    }
    float awt=0;
    float atat=0;
    for (int i = 0; i < n; i++)
    {
        awt+=wt[i];
        atat+=tat[i];
    }
    printf("average waiting time =%.2f, Average turn around time =%.2f\n",awt / n,atat/n);
}


int main(){
    int n=3;
    struct process processes[]={{1,4},{2,3},{3,5}};
    int time_quantum =2;
    printf("Round Robin scheduling :\n");
    roundRobin(processes,n,time_quantum);
    return 0;
}