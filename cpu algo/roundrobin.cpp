#include <iostream>
#include <queue>
using namespace std;

int main() {
    queue<int> q;
    int n, tq;
    cout << "Enter n: ";
    cin >> n;
    cout << "Enter time quantum: ";
    cin >> tq;
    int p[n], at[n], bt[n];
    for (int i = 0; i < n; i++) {
        cin >> p[i] >> at[i] >> bt[i];
    }
    int rt[n];
    int st[n];
    for (int i = 0; i < n; i++) {
        rt[i] = bt[i];
        st[i] = 1;
    }
    int ct[n], tat[n], wt[n];
    int count = 0;
    int time = 0;
    int sm = -1;
    while (count < n) {
        for (int i = 0; i < n; i++) {
            if (at[i] <= time) {
                if (rt[i] > 0 && st[i] == 1) {
                    q.push(i);
                    st[i] = 0;
                }
            }
        }
        if (!q.empty()) {
			if(sm >= 0){
				if(rt[sm]!=0){
					q.push(sm);
				}
			}
            int tem = q.front();
			sm = tem;
            q.pop();
            if (rt[tem] <= tq) {
                time = time + rt[tem];
                rt[tem] = 0;
            } else {
                rt[tem] = rt[tem] - tq;
                time = time + tq;
            }
            if (rt[tem] == 0) {
                count++;
                ct[tem] = time;
                tat[tem] = ct[tem] - at[tem];
                wt[tem] = tat[tem] - bt[tem];
            }
        } else {
            time = time + 1;
        }
    }
    float avg = 0, tt = 0;
    cout << "Process" << "\t" << "arrival-time" << "\t" << "burst-time" << "\t" 
	<< "completion-time" << "\t" << "turnaround-time" << "\t" << "waiting-time" << endl;
    for (int i = 0; i < n; i++) {
        cout << "p" << p[i] << "\t" << at[i] << "\t\t" << bt[i] << "\t\t"
             << ct[i] << "\t\t" << tat[i] << "\t\t" << wt[i] << endl;
        avg = avg + wt[i];
        tt = tt + tat[i];
    }
    cout << "\n\nAverage waiting time = " << avg / n;
    cout << " Average Turnaround time = " << tt / n << endl;
    cout << endl;
    return 0;
}
