#include <stdio.h>

struct task {
    int pid;
    int arrival;
    int burst;
    int remaining;
    int completion;
    int turnaround;
    int waiting;
};

int main()
{
    printf("Devendra.P\n");
    printf("1BM25CS439\n");
    int total;
    printf("Enter number of processes: ");
    scanf("%d", &total);

    struct task t[20];

    for(int i=0;i<total;i++)
    {
        t[i].pid = i+1;

        printf("Arrival time of P%d: ",t[i].pid);
        scanf("%d",&t[i].arrival);

        printf("Burst time of P%d: ",t[i].pid);
        scanf("%d",&t[i].burst);

        t[i].remaining = t[i].burst;
    }

    int finished = 0;
    int currentTime = 0;
    int shortest;
    int minRemain;
    int sumTAT = 0, sumWT = 0;

    while(finished != total)
    {
        minRemain = 9999;
        shortest = -1;

        for(int i=0;i<total;i++)
        {
            if(t[i].arrival <= currentTime && t[i].remaining > 0 && t[i].remaining < minRemain)
            {
                minRemain = t[i].remaining;
                shortest = i;
            }
        }

        if(shortest == -1)
        {
            currentTime++;
            continue;
        }

        t[shortest].remaining--;
        currentTime++;

        if(t[shortest].remaining == 0)
        {
            finished++;

            t[shortest].completion = currentTime;
            t[shortest].turnaround = t[shortest].completion - t[shortest].arrival;
            t[shortest].waiting = t[shortest].turnaround - t[shortest].burst;

            sumTAT += t[shortest].turnaround;
            sumWT += t[shortest].waiting;
        }
    }

    printf("\nProcess\tAT\tBT\tCT\tTAT\tWT\n");

    for(int i=0;i<total;i++)
    {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
        t[i].pid,
        t[i].arrival,
        t[i].burst,
        t[i].completion,
        t[i].turnaround,
        t[i].waiting);
    }

    printf("\nAverage Turnaround Time: %.2f",(float)sumTAT/total);
    printf("\nAverage Waiting Time: %.2f",(float)sumWT/total);

    return 0;
}
