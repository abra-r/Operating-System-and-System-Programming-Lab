#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, tq;
    cout << "Enter number of processes: ";
    cin >> n;

    vector<int> bt(n), rt(n), wt(n, 0), tat(n);
    cout << "Enter burst times:\n";
    for(int i = 0; i < n; ++i) {
        cout << "P[" << i + 1 << "]: ";
        cin >> bt[i];
        rt[i] = bt[i];
    }

    cout << "Enter time quantum: ";
    cin >> tq;

    int time = 0;
    while(true) {
        bool done = true;
        for(int i = 0; i < n; ++i) {
            if(rt[i] > 0) {
                done = false;
                if(rt[i] > tq) {
                    time += tq;
                    rt[i] -= tq;
                } else {
                    time += rt[i];
                    wt[i] = time - bt[i];
                    rt[i] = 0;
                }
            }
        }
        if(done) break;
    }

    cout << "\nProcess\tBT\tWT\tTAT\n";
    for(int i = 0; i < n; ++i) {
        tat[i] = bt[i] + wt[i];
        cout << "P[" << i + 1 << "]\t" << bt[i] << "\t" << wt[i] << "\t" << tat[i] << "\n";
    }
    int totalwt=0;
    for(int i=0;i<n;i++)
    {
        totalwt+=wt[i];
    }
    double avarageWt=(double)(totalwt)/(double)n;

    cout<<"Avarage Waiting time: "<<avarageWt<<endl;


    return 0;
}
