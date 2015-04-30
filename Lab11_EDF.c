#include<stdio.h>

int main()
{
	int n,i,j,time_total=0,time,temp,flag=0,min;
	
	printf("\nEnter the number of process: ");
	scanf("%d",&n);
	
	int process[n][3];
	for(i=0;i<n;i++)
	{
		printf("\nEnter release time for process %d: ",i+1);
		scanf("%d",&process[0][i]);
		printf("\nEnter deadline for process %d: ",i+1);
		scanf("%d",&process[1][i]);
		printf("\nEnter execution time for process %d: ",i+1);
		scanf("%d",&process[2][i]);
		time_total=time_total+process[2][i];
	}
		
	int gantt[n][time_total];
	for(i=0;i<n;i++)
	{
		for(j=0;j<time_total;j++)
		{
			gantt[i][j]=0;
		}	
	}
	
	min = process[1][0];
	j=0;
	for(time=0;time<time_total;time++)
	{
		
		for(i=0;i<n;i++)
		{
			if(process[0][i]<=time && process[2][i]!=0)
			{
				if(flag==1)
				{
					min = process[1][i];
					flag = 0;
					j=i;
				}
				if(process[1][i]<min)
				{
					min = process[1][i];
					j=i;
				}				
			}
			else if(process[0][i]>time)
			break;
		}
		
		process[2][j] = process[2][j] - 1;
		gantt[j][time]=1;
		if(process[2][j]==0)
		{
			flag=1;
		}			
	}
	
for(i=0;i<n;i++)
	{
		for(j=0;j<time_total;j++)
		{
			printf("%d",gantt[i][j]);
		}
		printf("\n");	
	}
	return 0;			
}
