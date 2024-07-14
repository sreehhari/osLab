#include <stdio.h>
#include <stdlib.h>

#define MAX_FRAMES 3
#define MAX_PAGES 20

int frames[MAX_FRAMES];
int counter[MAX_FRAMES];

// Function to initialize the frames and counters
void initialize() {
    for (int i = 0; i < MAX_FRAMES; i++) {
        frames[i] = -1;
        counter[i] = 0;
    }
}

// Function to display the current state of frames
void displayFrames() {
    for (int i = 0; i < MAX_FRAMES; i++) {
        if (frames[i] != -1) {
            printf("%d ", frames[i]);
        } else {
            printf("- ");
        }
    }
    printf("\n");
}

// Function to find the least recently used frame
int findLRU() {
    int max = counter[0];
    int lru_frame = 0;
    for (int i = 1; i < MAX_FRAMES; i++) {
        if (counter[i] > max) {
            max = counter[i];
            lru_frame = i;
        }
    }
    return lru_frame;
}

// Function to implement the LRU page replacement algorithm
void LRU(int pages[], int n) {
    int page_faults = 0;

    for (int i = 0; i < n; i++) {
        int page = pages[i];
        int found = 0;

        // Check if the page is already in any frame
        for (int j = 0; j < MAX_FRAMES; j++) {
            if (frames[j] == page) {
                found = 1;
                printf("The page %d is already there\n", page);
                // Reset the counter for the found frame
                counter[j] = 0;
                break;
            }
        }

        if (!found) {
            int lru_frame = findLRU();
            printf("Page %d is loaded into frame %d\n", page, lru_frame);
            frames[lru_frame] = page;
            counter[lru_frame] = 0;
            page_faults++;
        }

        // Increment the counter for all frames except the one that was just used
        for (int j = 0; j < MAX_FRAMES; j++) {
            if (frames[j] != page) {
                counter[j]++;
            }
        }

        displayFrames();
    }

    printf("Total page faults: %d\n", page_faults);
}

int main() {
    int pages[MAX_PAGES];
    int n;
    printf("Enter the number of pages: ");
    scanf("%d", &n);
    printf("Enter the page reference sequence: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &pages[i]);
    }

    initialize();
    LRU(pages, n);
    return 0;
}
