#include<stdio.h>
#include<stdlib.h>

#define MAX_REQUESTS 100

//function to calculat the total seek time using the CSCAN algotithm
int calculateTotalSeekTime(int *requests, int numRequests){
    int totalSeekTime=0;
    int currentTrack=0;
    int direction =1;

    //sort the requests in ascending order 
    for (int i = 0; i < numRequests-1; i++)
    {
        for (int j = 0; j < numRequests-i-1; j++)
        {
            if (requests[j]>requests[j+1])
            {
                int temp =requests[j];
                requests[j]=requests[j+1];
                requests[j+1]=temp;
            }
            
        }
        
    }
    //now we iterate through each request
    for (int i = 0; i < numRequests; i++)
    {
        //scan the current direction until the end of the disk
        while (currentTrack>=0 && currentTrack<=199)
        {
            //check if the current request lies on the current track
            if(requests[i]==currentTrack){
                totalSeekTime+=abs(currentTrack-requests[i]);//add seek time
                requests[i]=-1;//mark it as serviced
                break;//move to the next request


            }

            //move the arm in the current direction
            currentTrack+=direction;
            totalSeekTime++;
        }

        //if we reach the end of the disk, wrap around to the beginnign
        if(currentTrack==200){
            currentTrack=0;
            direction=1;
        }
        
    }
    return totalSeekTime;
    
    
}

int main(){
    int requests[MAX_REQUESTS];
    int numRequests;

    //input the total number of requests
    printf("enter the numebr of disk requests\n");
    scanf("%d",&numRequests);

    //now we take the input of the requests

    for (int i = 0; i < numRequests; i++)
    {
        printf("enter the disk request(track numeber)\n");
        scanf("%d",&requests[i]);
    }

    //now calculat the total seek time usinf the function we defined

    int totalSeekTime=calculateTotalSeekTime(requests,numRequests);
    printf("the total seek time is :%d\n",totalSeekTime);
    return 0;
    
}