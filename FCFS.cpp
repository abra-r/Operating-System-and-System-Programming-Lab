#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cout << "Enter number of processes: ";
    cin >> n;

    vector<int> bt(n), wt(n), tat(n);
    cout << "Enter burst times:\n";
    for(int i = 0; i < n; ++i) {
        cout << "P[" << i + 1 << "]: ";
        cin >> bt[i];
    }

    wt[0] = 0;
    for(int i = 1; i < n; ++i)
        wt[i] = wt[i - 1] + bt[i - 1];

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
