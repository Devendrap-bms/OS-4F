#include <stdio.h>

struct process{
    int pid,at,bt,pr,ct,wt,tat;
};
int main(){
    printf("Devendra.P\n");
    printf("1BM25CS439\n");
    int n;

    printf("Enter The Number of processes :");
    scanf("%d",&n);
    int completed[n];
    struct process p[n];
    for (int i=0;i<n;i++){
        p[i].pid=i+1;

        printf("Arrival Time of P%d:",p[i].pid);
        scanf("%d",&p[i].at);

        printf("Burst Time of P%d:",p[i].pid);
        scanf("%d",&p[i].bt);

        printf("Priority of P%d:",p[i].pid);
        scanf("%d",&p[i].pr);
        completed[i]=0;

    }
    int Current_Time=0;
    int Completed_Count=0;
    int SumTAT=0;
    int SumWT=0;

    while(Completed_Count<n){
        int Highest_Priority=9999;
        int Selected_process=-1;

        for (int i=0;i<n;i++){
            if(p[i].at<=Current_Time&&completed[i]==0){
               if(p[i].pr<Highest_Priority){
                  Highest_Priority=p[i].pr;
                  Selected_process=i;
                  }

               }
        }
        if(Selected_process==-1){
            Current_Time=Current_Time+1;
        }
        else{
            int Start_Time=Current_Time;
            p[Selected_process].ct=Start_Time+p[Selected_process].bt;
            p[Selected_process].tat=p[Selected_process].ct-p[Selected_process].at;
            p[Selected_process].wt=p[Selected_process].tat-p[Selected_process].bt;
            Current_Time=p[Selected_process].ct;
            completed[Selected_process]=1;
            Completed_Count=Completed_Count+1;
            SumTAT+=p[Selected_process].tat;
            SumWT+=p[Selected_process].wt;

        }

    }
    printf("\nProcess\tArrival Time\tBurst Time\tPriority\tCompletion Time\tTurnaround Time\tWaiting Time\n");

    for(int i = 0; i < n; i++) {
        printf("P%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",
               p[i].pid,
               p[i].at,
               p[i].bt,
               p[i].pr,
               p[i].ct,
               p[i].tat,
               p[i].wt);
    }
    printf("\nAverage TAT: %.2f\n", (float)SumTAT/n);
    printf("Average WT: %.2f\n", (float)SumWT/n);
    return 0;

}
