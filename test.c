#include "types.h"
#include "user.h"
#include "stat.h"
#define ARRAY_MAX_SIZE 800

int size = ARRAY_MAX_SIZE;
int arr[ARRAY_MAX_SIZE];
int num = ARRAY_MAX_SIZE;

void swap(int *xp, int *yp) {
  int temp = *xp;
  *xp = *yp;
  *yp = temp;
}



void bubble_sort(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                swap(arr+j, arr+j+1);
            }
        }
    }
}
void wasteTime(){
    for(int i=0; i<30;i++){

    for (int j = 0; j < size; j++) {
        arr[j] = num;
        num--;
    }
    bubble_sort(arr, size);

}
    //sleep(300);

}

int main() {
    int pid;
    int ticket = 100;
    int tickets[10] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512};
    //int tickets[2] = {1000, 2000};
    //ordenado: 2000 - 800 - 500 - 400  200 -- 150 - 120 - - 80 - 50 -10
    for (int i = 0; i < sizeof(tickets)/sizeof(int); i++) {
        pid = fork(tickets[i]);
        if (pid < 0) {
            printf(1,"Failed to fork process.\n");
            exit();
        } else if (pid == 0) { 
            wasteTime();
            if (tickets[i]) ticket = tickets[i];       
            printf(1,"Process with %d tickets executed.\n", ticket); sleep(100);
            exit();
        }
    }
    
    // Wait for all child processes to finish
     while (wait() != -1);
   
    exit();
    return 0;
}