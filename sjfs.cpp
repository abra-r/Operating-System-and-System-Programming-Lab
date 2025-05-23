#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Process {
    int pid, bt;
};

int main() {
    int n;
    cout << "Enter number of processes: ";
    cin >> n;
    vector<Process> p(n);

    for(int i = 0; i < n; ++i) {
        p[i].pid = i + 1;
        cout << "P[" << i + 1 << "] Burst Time: ";
        cin >> p[i].bt;
    }

    sort(p.begin(), p.end(), [](Process a, Process b) {
        return a.bt < b.bt;
    });

    vector<int> wt(n), tat(n);
    wt[0] = 0;
    for(int i = 1; i < n; ++i)
        wt[i] = wt[i - 1] + p[i - 1].bt;

    cout << "\nProcess\tBT\tWT\tTAT\n";
    for(int i = 0; i < n; ++i) {
        tat[i] = wt[i] + p[i].bt;
        cout << "P[" << p[i].pid << "]\t" << p[i].bt << "\t" << wt[i] << "\t" << tat[i] << "\n";
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
