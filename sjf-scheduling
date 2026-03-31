#include<stdio.h>
void main()
{
    int n, i, j;
    int p[20], b[20], a[20], g[20], w[20], t[20];
    float avgw=0, avgt=0;

    printf("Enter number of processes: ");
    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        printf("\nProcess ID: ");
        scanf("%d",&p[i]);
        printf("Burst Time: ");
        scanf("%d",&b[i]);
        printf("Arrival Time: ");
        scanf("%d",&a[i]);
    }

    // SJF Scheduling (non-preemptive)
    int completed[20] = {0}, time=0, count=0, min_index;
    while(count<n)
    {
        min_index = -1;
        for(i=0;i<n;i++)
        {
            if(!completed[i] && a[i]<=time)
            {
                if(min_index==-1 || b[i]<b[min_index])
                    min_index = i;
            }
        }
        if(min_index==-1)
        {
            time++; // CPU idle
            continue;
        }

        g[count] = time;
        time += b[min_index];
        w[min_index] = g[count] - a[min_index];
        t[min_index] = w[min_index] + b[min_index];
        completed[min_index] = 1;
        count++;
    }

    // Output
    printf("\nPID\tBurst\tArrival\tWaiting\tTurnaround\tGantt\n");
    for(i=0;i<n;i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\t\t%d-%d\n",p[i],b[i],a[i],w[i],t[i],g[i],g[i]+b[i]);
        avgw += w[i];
        avgt += t[i];
    }

    avgw /= n;
    avgt /= n;

    printf("\nAverage waiting time: %.2f", avgw);
    printf("\nAverage turnaround time: %.2f\n", avgt);
}
