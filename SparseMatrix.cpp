#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, m;
    cout << "Enter number of students and subjects: ";
    cin >> n >> m;
    int g[n][m];
    cout << "Enter grades:\n";
    for (int i = 0; i < n; i++) {
        cout << "Student " << i << ": ";
        for (int j = 0; j < m; j++) {
            cin >> g[i][j];
        }
    }

    cout << "\nGrades:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << g[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\nAverage per subject:\n";
    int bestSubj = -1;
    double bestAvg = -1;

    for (int j = 0; j < m; j++) {
        int sum = 0, cnt = 0;
        for (int i = 0; i < n; i++) {
            if (g[i][j] != 0) {
                sum += g[i][j];
                cnt++;
            }
        }
        if (cnt > 0) {
            double avg = (double)sum / cnt;
            cout << "Subj " << j << ":" << avg << "\n";

            if (avg > bestAvg) {
                bestAvg = avg;
                bestSubj = j;
            }
        } else {
            cout << "Subj " << j << ":NA\n";
        }
    }
    int maxG = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (g[i][j] > maxG) maxG = g[i][j];

    cout << "\nTop grades:\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (g[i][j] == maxG)
                cout << "Student " << i << " got " << maxG << " in subj " << j << "\n";
    if (bestSubj != -1)
        cout << "\nBest avg: subj " << bestSubj << " with " << bestAvg << "\n";
    else
        cout << "\nNo grades to calculate average.\n";

    return 0;
}
