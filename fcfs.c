#include<stdio.h>
#include<stdlib.h>

#define MAX_REQUESTS 100

//fucn to calc the total seek time in fcfs

int calculateTotalSeekTime(int *requests,int numRequests){
    int totalSeekTime=0;
    int currentTrack=0;//we start at track 0

    //iterate through each request

    for (int i = 0; i < numRequests; i++)
    {
        //calc the seek time for the current req
        int seekTime=abs(currentTrack-requests[i]);

            //update the current req
    currentTrack=requests[i];

    //add the seek time to the total seek time
    totalSeekTime+=seekTime;
    }

    return totalSeekTime;


    

}

int main(){
    int requests[MAX_REQUESTS];
    int numRequests;


    printf("enter the number of requests\n");
    scanf("%d",&numRequests);

    if(numRequests<=0 || numRequests>MAX_REQUESTS){
        printf("invalid req\n");
        return 1;
    }

    //input disk requsts

    printf("enter the disk requests(track number):\n");

    for (int i = 0; i < numRequests; i++)
    {
        scanf("%d",&requests[i]);
    }

    //calculate and print total seek time 
    int totalSeekTime=calculateTotalSeekTime(requests,numRequests);
    printf("the total seek time using FCFS is :%d\n",totalSeekTime);

    return 0;
    

}