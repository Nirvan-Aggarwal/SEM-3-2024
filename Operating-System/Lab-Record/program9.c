#include <stdio.h>

#define MAX_FRAMES 10
#define MAX_PAGES 100

// Function to check if a page is in the frame
int isPageInFrame(int frames[], int n, int page) {
    for (int i = 0; i < n; i++) {
        if (frames[i] == page) return i;
    }
    return -1;
}

// Function to find the Least Recently Used (LRU) page
int findLRU(int pages[], int n, int frames[], int frameCount, int currentIndex) {
    int lruIndex = -1, minIndex = currentIndex;
    for (int i = 0; i < frameCount; i++) {
        for (int j = currentIndex - 1; j >= 0; j--) {
            if (pages[j] == frames[i]) {
                if (j < minIndex) {
                    minIndex = j;
                    lruIndex = i;
                }
                break;
            }
        }
    }
    return lruIndex;
}

// Function to implement LRU Page Replacement
void LRU(int pages[], int n, int frameCount) {
    int frames[MAX_FRAMES], pageFaults = 0, index = 0;

    for (int i = 0; i < frameCount; i++) frames[i] = -1; // Initialize frames as empty

    for (int i = 0; i < n; i++) {
        int page = pages[i];

        int pos = isPageInFrame(frames, frameCount, page);
        
        if (pos == -1) {  // Page fault occurs
            pageFaults++;

            if (index < frameCount) { // If there's space, insert directly
                frames[index++] = page;
            } else { // Replace the LRU page
                int lruIndex = findLRU(pages, n, frames, frameCount, i);
                frames[lruIndex] = page;
            }
        }

        // Display the current frame status
        printf("\nStep %d: ", i + 1);
        for (int j = 0; j < frameCount; j++) {
            if (frames[j] == -1)
                printf(" - ");
            else
                printf(" %d ", frames[j]);
        }
    }

    printf("\n\nTotal Page Faults: %d\n", pageFaults);
}

int main() {
    int n, frameCount, pages[MAX_PAGES];

    printf("Enter number of pages: ");
    scanf("%d", &n);
    
    printf("Enter page reference string: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &pages[i]);
    }

    printf("Enter number of frames: ");
    scanf("%d", &frameCount);

    LRU(pages, n, frameCount);

    return 0;
}
