#include<stdio.h>
#include<graphics.h>
#include<conio.h>
#include<stdlib.h>
#include "DDA.C"
void gantt_chart(int smallest[100],int timing[100],int time)
{              int i=0,j=0,count=0;
    int s[100],t[100];
    char a[20],b[20];
    printf("\n*****GANTT CHART*****\n\n");

    for(i=0;i<time;i++)
    {
	if(smallest[i]!=smallest[i+1])
	{
	    count++;
	    s[j]=smallest[i];
	    t[j]=timing[i]+1;
	    j++;
	}

    }
    line(100,95,100,115);
    outtextxy(100,120,"0");
    for(i=0;i<count;i++)
    {
    line(100+25*i,95,100+25*(i+1),95);
    line(100+25*i,115,100+25*(i+1),115);
    line(100+25*(i+1),95,100+25*(i+1),115);
    itoa(s[i],a,10);
    itoa(t[i],b,10);
    outtextxy(105+25*i,100,"P");
    outtextxy(115+25*i,100,a);
    outtextxy(100+25*(i+1),120,b);
    }
}
void main()
{    int gd=DETECT,gm;
    int arrival_time[10], burst_time[10],temp[10],proce[10],proc_temp[100],wait[10],turn[10],burst[10],smallest[100],timing[100];
    int j=0, i, small=0, count=0, time, no;
    int wait_time=0, turnaround_time=0, end;
    float average_waiting_time, average_turnaround_time;
    printf("Enter the total number of processes: \n");
    scanf("%d",&no);
    printf("Enter the detail of process: \n");
    for(i=0;i<no;i++)
    {
	proce[i]=i+1;
	printf("Enter Arrival time: \n");
	scanf("%d",&arrival_time[i]);
	printf("Enter Burst time: \n");
	scanf("%d",&burst_time[i]);
	temp[i]=burst_time[i];
	burst[i]=burst_time[i];
    }
    burst_time[9]=9999;
    for(time=0;count!=no;time++)
    {
	small=9;
	for(i=0;i<no;i++)
	{
	    if((arrival_time[i]<=time)&&(burst_time[i]<burst_time[small])&&(burst_time[i]>0))
	    {
		small=i;
	    }
	}
	smallest[j]=small+1;
	timing[j]=time;
	proc_temp[j]=proce[small];
	j++;
	burst_time[small]--;
	if(burst_time[small]==0)
	{
	    count++;
	    end=time+1;
	    wait[small]=end-arrival_time[small]-temp[small];
	    turn[small]=end-arrival_time[small];
	    wait_time=wait_time+end-arrival_time[small]-temp[small];
	    turnaround_time=turnaround_time+end-arrival_time[small];
	}

	proc_temp[i]=proce[small];
    }
    smallest[j]=0;
   printf("\nDATA IS AS FOLLOWS: \n\n");
    printf("+-----+------------+--------------+-----------------+--------------+\n");
    printf("| PID | Burst Time | Waiting Time | Turnaround Time | Arrival time |\n");
    printf("+-----+------------+--------------+-----------------+--------------+\n");
    for(i=0;i<no;i++)
    {
    printf("| %2d  |     %2d     |      %2d      |        %2d       |       %2d     |\n"
	       , proce[i],burst[i],wait[i],turn[i],arrival_time[i] );
	printf("+-----+------------+--------------+-----------------+--------------+\n");
    }
       average_waiting_time=wait_time/no;
    average_turnaround_time=turnaround_time/no;
    printf("Average Waiting Time:%.2f\n",average_waiting_time);
    printf("Average Turnaround Time:%.2f\n",average_turnaround_time);
    getch();
    initgraph(&gd,&gm,"c:\\turboc3\\bgi");
    gantt_chart(smallest,timing,time);

    getch();
   closegraph();
}






