#include<stdio.h>
int main(){
int n, i , bt[20],tat[20],wt[20],p[20]; //assuming the arrival time to be zero for all
printf("enter the number of processes: ");
scanf("%d",&n);
for(i=0;i<n;i++){
    p[i]=i+1;
    printf("please enter the burst time fro process %d : ",i+1);
    scanf("%d",&bt[i]);
}
for(i=0;i<n-1;i++){
    for(int j=i+1;j<n;j     ++){
        if(bt[i]>bt[j]){
            int temp=bt[i];
            bt[i]=bt[j];
            bt[j]=temp;

            temp=p[i];
            p[i]=p[j];
            p[j]=temp;
        }
    }
}
wt[0]=0;
for(i=1;i<n;i++){
    wt[i] = wt[i-1]+ bt[i-1];  // tat=ct-at
}                              // wt=ct-at-bt ---> tat=wt+bt by ignoring the ct and at
for(i=0;i<n;i++){
    tat[i]=wt[i]+bt[i];
}
for(i=0;i<n;i++){
    printf("the time for process %d are %d , %d , %d \n",p[i],bt[i],wt[i],tat[i]);
}
}
