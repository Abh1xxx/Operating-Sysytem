#include<stdio.h>
#include<stdlib.h>

struct process                                 //Structure 
{           
    int pid,bt,wt,trt,pr;                      // Priority=pr
} ;                                      

int n,i,j,sum_wt,sum_trt,choice,y,sum,qt;          //global variables
float avgwt,avgtrt;

void read(struct process p1[])
{
    printf("\nEnter the number of process  N=");
    scanf("%d",&n);
    printf("\nProcess Number \t\tBurst Time\n");
    printf("____________________________________\n");
    for(i=0;i<n;i++)
    {
        printf("       %d      \t\t     ",i+1);
        scanf("%d",&p1[i].bt);
        p1[i].pid=i+1;   
    }
}
       
void waiting_time(struct process p2[])
{
    if(choice ==4)                         // for ROUND ROBIN
    {
       for (i = 0,sum_wt=0; i < n ; i++ ) 
            sum_wt=sum_wt+p2[i].wt; 
    } 
    else
    {
         p2[0].wt=0;                             // waiting time for first process is 0 
        for (i = 1,sum_wt=0; i < n ; i++ )      // calculating waiting time  for 
        {
            p2[i].wt =  p2[i-1].bt + p2[i-1].wt ;  //   fcfs
            sum_wt=sum_wt+p2[i].wt;              //   sjfw
                                                //   Priority 
        }
    }                                                   
    avgwt=(float)sum_wt / (float)n;
}

void trunaround_time(struct process p3[])
{
    for(i=0,sum_trt=0;i < n;i++)
    { 
        if (choice != 4) 
            p3[i].trt=p3[i].bt+p3[i].wt;
        sum_trt=sum_trt+p3[i].trt;
    }  
    avgtrt=(float)sum_trt / (float)n; 
}

void print(struct process p4[])
{
    printf("__________________________________________________________________\n");
    printf("Process \t Burst time\t Waiting time\tTrun around time \n");
    printf("__________________________________________________________________\n");
    for(i=0;i<n;i++)
    {
        printf("    %d   \t     %d    \t       %d    \t        %d       \n",p4[i].pid,p4[i].bt,p4[i].wt,p4[i].trt);
    }
        printf("__________________________________________________________________\n");
    printf("\n\tn=%d\tsum wt=%d\tsum of trt=%d\n",n,sum_wt,sum_trt);
    printf("\nAverage Waiting time     =\t%f \nAverage Turn Around time=\t%f\n",avgwt,avgtrt);
}

void main()                                    //  Main  function
{  
    struct process p[10],p12[10],p13[10];                                       //Structure variable pS
    int flag=0,pos,temp1,temp[10],sum;
    char x;
    read(p);
    do{  
        printf("\n\t\tSelect your Scheduling algorithm\n");
        printf("__________________________________________________________________\n");
        printf("\t1.FCFS\n\t2.SJFS\n\t3.Priority\n\t4.RR\n\t5.Enter a  new Scheduling\n\t6.EXIT\n");
        printf("Enter your choice\t:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:                      //   FCFS
                    printf("\n\tGran Chart\n________________________\n\n");
                    printf("0");
                    sum=0;
                    for(i=0;i<n;i++)
                    {
                        sum+=p[i].bt;
                        printf(" | P%d | %d",p[i].pid,sum);
                    }
                    printf("\n");
                    waiting_time(p);
                    trunaround_time(p);  
                    print(p);          
            break;
            case 2:                    //SJFS
                    for(i=0;i<n;i++)
                    {                    //Copying p->p12
                        p12[i].pid=p[i].pid;
                        p12[i].bt=p[i].bt;
                    }
                    printf("\n\tGran Chart\n________________________\n\n");
                    printf("0");
                    sum=0; 
                    for(i=0;i<n;i++)            // Sorting
                    {                           // Burst time and process id
                        pos=i;
                        for(j=i+1;j<n;j++)
                        {
                            if(p12[j].bt<p12[pos].bt)
                            pos=j;
                        }
                        temp1=p12[i].bt;         //  sorting burst time
                        p12[i].bt=p12[pos].bt;
                        p12[pos].bt=temp1;
 
                        temp1=p12[i].pid;
                        p12[i].pid=p12[pos].pid;    // sorting process
                        p12[pos].pid=temp1;
                        sum+=p12[i].bt;
                        printf(" | P%d | %d",p12[i].pid,sum);
                    }
                    printf("\n");
                    waiting_time(p12);
                    trunaround_time(p12);  
                    print(p12); 
            break;  
            case 3: 
                    printf("\nProcess no.\t\tPriority\n");
                    for(i=0;i<n;i++)                       // Reading priority
                    {
                        printf("     %d   \t\t      ",i+1);
                        scanf("%d",&p[i].pr);
                    }
                    for(i=0;i<n;i++)        //Copying p->p13
                    {
                        p13[i].pid=p[i].pid;
                        p13[i].bt=p[i].bt;
                        p13[i].pr=p[i].pr;
                    } 
                    printf("\n\tGran Chart\n________________________\n\n");
                    printf("0");
                    sum=0;
                    for(i=0;i<n;i++)
                    {
                        pos=i;
                        for(j=i+1;j<n;j++)
                        {
                            if(p13[j].pr<p13[pos].pr)
                            pos=j;
                        }
 
                        temp1=p13[i].pr;          //sorting Priority number
                        p13[i].pr=p13[pos].pr;
                        p13[pos].pr=temp1;
 
                        temp1=p13[i].bt;         //sorting burst time
                        p13[i].bt=p13[pos].bt;
                        p13[pos].bt=temp1;
  
                        temp1=p13[i].pid;        //sorting process time
                        p13[i].pid=p13[pos].pid;
                        p13[pos].pid=temp1;
                        sum+=p13[i].bt;
                        printf(" | P%d | %d",p13[i].pid,sum);
                    }
                    printf("\n");
                    waiting_time(p13);
                    trunaround_time(p13);  
                    print(p13);      
            break;
            case 4: 
                    printf("\nEnter Quantum time = ");             // Quantum Time
                    scanf("%d",&qt);
                    for(i=0;i<n;i++)                    //Copying bt -> temp 
                        temp[i]=p[i].bt;
                    y=n;                           //initializing y -> no. of process (n)
                    printf("\n\tGran Chart\n________________________\n\n");
                    printf("0");
                    for(sum=0,i=0;y!=0;)
                    {
                        if(temp[i]<=qt && temp[i]>0)
                        {
                            sum=sum+temp[i];
                            temp[i]=0;
                            flag=1;
                            printf(" | P%d | %d",i+1,sum);

                        }
                        else if (temp[i]>qt)
                        {
                            temp[i]=temp[i]-qt;
                            sum=sum+qt;
                            printf(" | P%d | %d",i+1,sum);
                        }
                        if(temp[i]==0 && flag==1)
                        {
                            y--;
                            p[i].trt=sum;
                            p[i].wt=sum-p[i].bt;
                            flag=0;
                            // g[ind++]=i;    
                        }
                        
                        // if(temp[i]!=0)
                        // {
                        //     g=0;
                        // }
                        if(i==n-1)
                            i=0;
                        else
                            i++;
                    }
                    printf("\n\n");
                    waiting_time(p);
                    trunaround_time(p);
                    print(p);
            break; 
            case 5: read(p);
            break;;
            case 6: exit(0);
            break;
            default: printf("\nEnter a valid Number please")  ;                             
        }
        printf("\nDo you want to continue(y/n)\t:");
        scanf(" %c",&x);
    }while(x== 'Y'||x=='y');
}