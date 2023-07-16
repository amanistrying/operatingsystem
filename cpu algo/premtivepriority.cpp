#include <iostream>
using namespace std;
int main(){
	int n;
	cout << "Enter n: ";
	cin >> n;
	int p[n], at[n], bt[n], pr[n];
	for (int i = 0; i<n; i++){
		cin >> p[i] >> at[i] >> bt[i] >> pr[i];
 	}
 	int b[n+1];
 	int rt[n+1];
 	for(int i = 0; i<n; i++){
 		b[i] = pr[i];
 		rt[i] = bt[i];
 	}
 b[n] = 2147483647;
 rt[n] = 2147483647; 
 int ct[n], tat[n], wt[n];
 int count = 0;
 int time = 0;
 while(count < n){
 	int sm = n;
 	for(int i=0; i<n; i++){
 		if (at[i] <= time){
 			if(b[i] < b[sm] && rt[i]>0){
 				sm = i;
 			}
 			else if(b[i] == b[sm] && at[i] < at[sm] && rt[i]>0){
 				sm = i;
 			}
 		}
 	}
 	rt[sm] = rt[sm] - 1;
 	time = time + 1;
 	if(rt[sm] == 0){
 		count++;
 		ct[sm] = time;
 		tat[sm] = ct[sm] - at[sm];
 		wt[sm] = tat[sm] - bt[sm];
 	}
 }
 float avg = 0, tt = 0;
 cout<<"Process"<<"\t"<< "arrival-time"<<"\t"<<"burst-time" <<"\t" << "priority"
 <<"\t"<<"completion-time" <<"\t"<<"turnaround-time"<< "\t"<<"waiting-time"<<endl;
 for(int i=0; i<n; i++){
 	cout<<"p"<<p[i]<<"\t"<<at[i]<<"\t\t"<<bt[i]<<"\t\t"<<pr[i]<<"\t\t"
 	<<ct[i]<<"\t\t"<<tat[i]<<"\t\t"<<wt[i]<<endl;
 	avg = avg + wt[i];
 	tt = tt + tat[i];
 }
 cout<<"\n\nAverage waiting time ="<<avg/n;
 cout<<" Average Turnaround time ="<<tt/n<<endl;
 cout<< endl;
 return 0;
} 