// Question: Construct a C program to implement non-preemptive SJF algorithm.
// Code:
#include<stdio.h>
int
main()
{
    int at[10],bt[10],pr[10];
    int n,i,j,temp,time=0,count,over=0,sum_wait=0,sum_turnaround=0,start;
    float avgwait,avgturn;

    printf("Enter the number of processes\n");
    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        printf("Enter the arrival time and execution time for process %d\n",i+1);
        scanf("%d%d",&at[i],&bt[i]);
        pr[i]=i+1;
    }

    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(at[i]>at[j])
            {
                temp=at[i];
                at[i]=at[j];
                at[j]=temp;

                temp=bt[i];
                bt[i]=bt[j];
                bt[j]=temp;

                temp=pr[i];
                pr[i]=pr[j];
                pr[j]=temp;
            }
        }
    }

    printf("\n\nProcess\t|Arrival time\t|Execution time\t|Start time\t|End time\t|waiting time\t|Turnaround time\n\n");

    while(over<n)
    {
        count=0;

        for(i=over;i<n;i++)
        {
            if(at[i]<=time)
                count++;
            else
                break;
        }

        if(count>1)
        {
            for(i=over;i<over+count-1;i++)
            {
                for(j=i+1;j<over+count;j++)
                {
                    if(bt[i]>bt[j])
                    {
                        temp=at[i];
                        at[i]=at[j];
                        at[j]=temp;

                        temp=bt[i];
                        bt[i]=bt[j];
                        bt[j]=temp;

                        temp=pr[i];
                        pr[i]=pr[j];
                        pr[j]=temp;
                    }
                }
            }
        }

        start=time;
        time+=bt[over];

        printf("p[%d]\t|\t%d\t|\t%d\t|\t%d\t|\t%d\t|\t%d\t|\t%d\n",
               pr[over], at[over], bt[over], start, time,
               time-at[over]-bt[over], time-at[over]);

        sum_wait+=time-at[over]-bt[over];
        sum_turnaround+=time-at[over];

        over++;
    }

    avgwait=(float)sum_wait/(float)n;
    avgturn=(float)sum_turnaround/(float)n;

    printf("Average waiting time is %f\n",avgwait);
    printf("Average turnaround time is %f\n",avgturn);

    return 0;
}

// Output:
// Enter the number of processes
// 3
// Enter the arrival time and execution time for process 1
// 1 3
// Enter the arrival time and execution time for process 2
// 2 6
// Enter the arrival time and execution time for process 3
// 3 8


// Process |Arrival time   |Execution time |Start time     |End time       |waiting time   |Turnaround time

// p[1]    |       1       |       3       |       0       |       3       |       -1      |       2
// p[2]    |       2       |       6       |       3       |       9       |       1       |       7
// p[3]    |       3       |       8       |       9       |       17      |       6       |       14
// Average waiting time is 2.000000
// Average turnaround time is 7.666667
