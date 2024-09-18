#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
int ptr = 0;
struct fcfs {
    int pid;
    int at;
    int bt;
    int ct;
    int tat;
    int wt;
};
void sortat(struct fcfs arr[], int n) {
    // Sort based on arrival time
    for (int i=0;i<n;i++) {
        for (int j=0;j<n-i-1;j++) {
            if (arr[j].at>arr[j+1].at) {
                struct fcfs temp =arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}
void caltatwt(struct fcfs arr[],int n) {
    ptr=arr[0].at;// Set pointer to the arrival time of the first process

    for (int i=0;i<n;i++) {
        if (arr[i].at>ptr) {
            ptr=arr[i].at;// Move pointer to process's arrival time if it's after the current time
        }
        ptr+=arr[i].bt;
        arr[i].ct = ptr;
        arr[i].tat=arr[i].ct-arr[i].at;// TAT = CT - AT
        arr[i].wt=arr[i].tat-arr[i].bt;// WT = TAT - BT
    }
}
void print(struct fcfs arr[], int n) {
    printf("Process Id\tArrival Time\tBurst Time\tCompletion Time\tTAT\tWaiting Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t%d\n", arr[i].pid, arr[i].at, arr[i].bt, arr[i].ct, arr[i].tat, arr[i].wt);
    }
}
int main() {
    int n;
    printf("Enter the number of processes:\n");
    scanf("%d", &n);
    struct fcfs arr[n];
    printf("Enter the process details (PID, Arrival Time, Burst Time) for each process:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d",&arr[i].pid,&arr[i].at,&arr[i].bt);
    }
    sortat(arr,n);
    caltatwt(arr,n);
    print(arr,n);
    return 0;
}
