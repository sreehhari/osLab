#include<stdio.h>
#include<stdlib.h>

#define MAX_FRAMES 3
#define MAX_PAGES 20


int frames[MAX_FRAMES];//array to store those frames
int rear=-1;//pointer to the rear of the frame queue


//func to initialize the frames array
void initialize(){
    for (int i = 0; i < MAX_FRAMES; i++)
    {
        frames[i]=-1;//initialize with -1 empty
    }
    
}

//fucntion to display the frames

void displayFrames(){
    for (int i = 0; i < MAX_FRAMES; i++)
    {
        if (frames[i]!=-1)
        {
            printf("%d\n",frames[i]);
        }else{
            printf("-");
        }
        printf("\n");
        
    }
    
}

//function to implement the fifo page reaplcement algorithm

void FIFO(int pages[],int n){
    int page_faults=0;
    int front =0;//pointer to the front of the frame queue

    for (int i = 0; i < n; i++)
    {
        int page =pages[i];
        int found =0;

        //check if the page already exists in the frame
        for (int j = 0; j < MAX_FRAMES; j++)
        {
            if (frames[j]==page)
            {
                found =1;
                printf("the page %d already exists \n",page);
                break;
            }
            
        }
        if(!found){
            page_faults++;

            if (rear<MAX_FRAMES-1)
            {
                rear++;
            }else{
                rear=0;
            }
            frames[rear]=page;
            printf("page %d loaded in frame %d\n",page,rear);

        }
        displayFrames();
        
    }
    printf("total page faults : %d\n",page_faults);
    
}

int main(){
    int pages[MAX_PAGES];
    int n;
    printf("enter the number of pages:");
    scanf("%d", &n);
    printf("Enter the page reference sequence: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &pages[i]);
    }

    initialize();
    FIFO(pages,n);
    return 0;
}