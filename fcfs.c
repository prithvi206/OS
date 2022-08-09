#include<stdio.h>
#include<stdlib.h>

struct process
{
   int ID, AT,BT,TAT,CT,WT;
};

void main()
{
    struct process p[10],temp;
    int n,i,j,ct=0;
    float total_wt=0, total_tat=0;

    printf("Enter the number of process:\n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        p[i].ID= i+1;
        printf("Enter the arrival time for the process %d :",i+1);
        scanf("%d",&p[i].AT);
        printf("Enter the Burst time for the process %d :",i+1);
        scanf("%d",&p[i].BT);
    }
    printf("Gantt chart:\n");

    for ( i = 0; i <n; i++)
    {
       for (j = 0; j<n; j++)
       {
         if(p[j].AT>p[j+1].AT)
         {
            temp = p[j];
            p[j]= p[j+1];
            p[j+1]= temp;
         }
       }
       
    }
    p[0].CT = p[0].AT + p[0].BT;
    ct = p[0].CT;
    printf("|p%d(%d) %d" ,p[0].ID,p[0].BT,ct);
    for(i=1;i<n;i++)
    {
        if(p[i].AT>p[i-1].CT)
        {
            printf("|idle(%d) %d",p[i].AT-p[i-1].CT,p[i].AT);
            ct = p[i].AT+p[i].BT;
        }
        else
        {
            ct+=p[i].BT;
            p[i].CT=ct;
            printf("| P%d(%d) %d", p[i].ID, p[i].BT, ct);
        }
    }
    for (i = 0; i < n; i++)
    {
        p[i].TAT = p[i].CT - p[i].AT;
        p[i].WT = p[i].TAT - p[i].BT;
        total_tat += p[i].TAT;
        total_wt += p[i].WT;
    }
      printf("\n\nID\tAT\tBT\tCT\tWT\tTAT\n");
    for (i = 0; i < n; i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", p[i].ID, p[i].AT, p[i].BT, p[i].CT, p[i].WT, p[i].TAT);
    }
    printf("AVG TAT : %.3f\n", total_tat / n);
    printf("AVG WT : %.3f\n", total_wt / n);
    

}
