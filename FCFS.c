#include<stdio.h>

struct process{
   int AT,WT,TT,BT;
};

struct process a[10];

int main(){
    int n; 
    int brust = 0, cmpl_T;
    float Avg_WT, Avg_TT,Total = 0;
    printf("ENter number of process\n");
    scanf("%d",&n);
    printf("Enter Arrival time and burst time of the process\n");
    printf("At BT\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d", &a[i].AT, &a[i].BT);
    }

   // Logic for calculating waiting  time
    for (int i = 0; i < n; i++)
    {
         if(i == 0)
            a[i].WT = a[i].AT;
            else 
               a[i].WT = brust - a[i].AT;
               brust += a[i].BT;
               Total += a[i].WT;
    }
     
     Avg_WT = Total / n;

     // Logical for calculating Turn around time
     cmpl_T = 0;
     Total = 0;
     for (int i = 0; i < n; i++)
     {
         cmpl_T += a[i].BT;
         a[i].TT = cmpl_T - a[i].AT;
         Total += a[i].TT;
     }
     
     Avg_TT = Total / n;

     // printing of output

     printf("Process , Waiting_time , Turn_time\n");
     for (int i = 0; i < n; i++)
     {
        printf("%d\t%d\t%d\t\t%d\n",i+1,a[i].WT,a[i].TT);
     }
     printf("Average waiting time is : %f\n",Avg_WT);
     printf("Average turn around time is: %f\n",Avg_TT);

   return 0;  

}