#include <stdio.h>
int main()
{
    int pid[15];
    int bt[15];
    int n;
    printf("Enter the no.of Processes: ");
    scanf("%d",&n);
    printf("Enter Process ID of all the Processes: ");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&pid[i]);
    }
    printf("Enter Burst Time of all the Processes: ");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&bt[i]);
    }
    int i,wt[n];
    wt[0]=0;
    for(i=1;i<n;i++)
    {
        wt[i]= bt[i-1]+ wt[i-1];
    }
    printf("  Process ID \t Burst Time \t Waiting Time \t TurnAround Time\n");
    float twt=0.0;
    float tat= 0.0;
    for(i=0;i<n;i++)
    {
        printf("\t%d\t\t", pid[i]);
        printf("%d\t\t", bt[i]);
        printf("%d\t\t", wt[i]);
        printf("%d\t\t", bt[i]+wt[i]);
        printf("\n");
        twt+=wt[i];
        tat+=(wt[i]+bt[i]);
    }
    float att,awt;
    awt=twt/n;
    att=tat/n;
    printf("Total Waiting Time= %f\n",twt);
    printf("Total Turnaround Time= %f\n",tat);
    printf("Avg. Waiting Time= %f\n",awt);
    printf("Avg. Turnaround Time= %f",att);
}
