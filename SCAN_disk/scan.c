#include<stdio.h>
#include<stdlib.h>

#define MAX_REQUESTS 100

//function to calculate the total seek time using SCAN algorithm

int calculateTotalSeekTime(int *requests,int numRequests){
    int totalSeekTime=0;
    int currentTrack=0;
    int direction =1;//inital direction towards higher tracks


    //iterate through each req

    for (int i = 0; i < numRequests; i++)
    {
        while (currentTrack>=0 && currentTrack<=199)//this while loop takes the arm forward and checks if each track is the requested one and iterates the arm by one (+direction)
        {
            //check if the current req lie on the current track
            if(requests[i]==currentTrack){
                totalSeekTime+=abs(currentTrack-requests[i]);
                requests[i]=-1;//mark that request as serviced
                break;
            }
            //move the disk arm in the current direction
            currentTrack+=direction;//this makes the arm move the current track in the direction (forward)
            totalSeekTime++;
        }

        //change the direction after the arm reaches the last track
        if(currentTrack==200){
            direction=-1;//changes direction towards the lower tracks

            currentTrack=199;//reverse aay aka move to the highest track

        }else if (currentTrack==-1)
        {
            direction=1;//changes direction towards the higher tracks
            currentTrack=0;//move to the lowest track
        }
        
        
    }
    return totalSeekTime;
}


int main(){
    int requests[MAX_REQUESTS];
    int numRequests;


    //input the number of requests

    printf("Enter the number of disk requests\n");
    scanf("%d",&numRequests);


    if(numRequests<=0 || numRequests>MAX_REQUESTS){
        printf("invalid request\n");
        return 1;
    }

    //input the requests
    for (int i = 0; i < numRequests; i++)
    {
        printf("enter the disk request\n");

        scanf("%d",&requests[i]);

    }

    //calc the seek time

    int totalSeekTime=calculateTotalSeekTime(requests,numRequests);
    printf(" the total seek time is :%d",totalSeekTime);
    
}