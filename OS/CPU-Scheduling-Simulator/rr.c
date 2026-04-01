#include <stdio.h>

int main() {
    int n, i, time = 0, remain;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int bt[n], rt[n], wt[n], tat[n];
    int tq;

    printf("Enter burst times:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &bt[i]);
        rt[i] = bt[i];
    }

    printf("Enter time quantum: ");
    scanf("%d", &tq);

    remain = n;

    while(remain != 0) {
        for(i = 0; i < n; i++) {
            if(rt[i] > 0) {
                if(rt[i] <= tq) {
                    time += rt[i];
                    rt[i] = 0;
                    remain--;
                    tat[i] = time;
                } else {
                    time += tq;
                    rt[i] -= tq;
                }
            }
        }
    }

    for(i = 0; i < n; i++) {
        wt[i] = tat[i] - bt[i];
    }

    printf("\nProcess\tBT\tWT\tTAT\n");
    for(i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\n", i+1, bt[i], wt[i], tat[i]);
    }

    return 0;
}
