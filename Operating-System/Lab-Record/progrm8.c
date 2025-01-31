#include <stdio.h> 
int findPage(int frames[], int frame_size, int page) { 
    for (int i = 0; i < frame_size; i++) { 
        if (frames[i] == page) 
            return 1; 
    } 
    return 0; 
} 
void printFrames(int frames[], int frame_size) { 
    for (int i = 0; i < frame_size; i++) { 
        if (frames[i] != -1) 
            printf("%d ", frames[i]); 
        else 
            printf("- "); 
    } 
    printf("\n"); 
} 
void FIFO(int pages[], int n, int frame_size) { 
    int frames[frame_size], page_faults = 0; 
    int front = 0;  // Pointer to track the first page in FIFO order 
    for (int i = 0; i < frame_size; i++) { 
        frames[i] = -1;  // Initialize frame to empty 
    } 
    for (int i = 0; i < n; i++) { 
        if (!findPage(frames, frame_size, pages[i])) {  // Page fault occurs 
            frames[front] = pages[i];  // Replace the oldest page 
            front = (front + 1) % frame_size;  // Move the pointer 
            page_faults++; 
        } 
        printFrames(frames, frame_size); 
    } 
    printf("Total Page Faults = %d\n", page_faults); 
} 
int main() { 
    int pages[] = {1, 3, 0, 3, 5, 6, 3}; 
    int n = sizeof(pages) / sizeof(pages[0]); 
    int frame_size = 3; 
 
    printf("FIFO Page Replacement\n"); 
    FIFO(pages, n, frame_size); 
 
    return 0; 
}