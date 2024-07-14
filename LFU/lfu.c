#include<stdio.h>
#include<stdlib.h>

#define MAX_FRAMES 3
#define MAX_PAGES 20

int frames[MAX_FRAMES];
int count[MAX_FRAMES];


void initialize(){
    for (int i = 0; i < MAX_FRAMES; i++)
    {
        frames[i]=-1;
        count[i]=0;
    }
    
}

void display(){
    for (int i = 0; i < MAX_FRAMES; i++)
    {
        if(frames[i]!=-1){
            printf("%d\n",frames[i]);
        }else{
            printf("-");
        }
    printf("\n");
    }
    
}

//function to find the lfu frame

int findLFU(){
    int min=count[0];
    int lfu_frame=0;

    for (int i = 1; i < MAX_FRAMES; i++)
    {
        if (count[i]<min)
        {
            min=count[i];
            lfu_frame=i;
        }
        
    }
    return lfu_frame;
    
}

//implement the lfu

void LFU(int pages[],int n){
    int page_faults=0;
    for (int i = 0; i < n; i++)
    {
        int page =pages[i];
        int found =0;

        for (int j = 0; j < MAX_FRAMES; j++)
        {
            if (frames[j]==page)
            {
                found =1;
                count[j]++;
                printf("the %d frame is already in memory\n",page);
                break;

            }
            
        }

        if(!found){
            int lfu_frame = findLFU();
            frames[lfu_frame]=page;
            count[lfu_frame]=1;
            page_faults++;
            printf("the %d is loaded into the frame %d",page,lfu_frame);

        }
        display();
    }
    printf("total page faults : %d\n",page_faults);
    
}


int main(){
    int pages[MAX_PAGES];
    int n;
    printf("Enter number of pages: ");
    scanf("%d", &n);
    printf("Enter the page reference sequence: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &pages[i]);
    }

    initialize(); // Initialize frames and counts arrays
    LFU(pages, n); // Apply LFU algorithm

    return 0;
}
