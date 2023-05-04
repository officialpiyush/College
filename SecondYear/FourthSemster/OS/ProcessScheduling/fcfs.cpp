#include <iostream>
using namespace std;

int main() {
  int total_processes;

  cout << "Enter total number of processes: ";
  cin >> total_processes;
    
  int *arrival_time = new int[total_processes], *burst_time = new int[total_processes], *time_comp = new int[total_processes], *t_t = new int[total_processes], *waiting_time = new int[total_processes], i=0, sum=0, t_sum=0,w_sum=0;

  for(i=0;i<total_processes;i++) {
    cout << "Enter arrival time of P" << i+1 << ": ";
    cin >> arrival_time[i];
    cout << "Enter burst time of P" << i+1 << ": ";
    cin >> burst_time[i];
  }

  for(i=0;i<total_processes;i++) {
    sum  += burst_time[i];
    time_comp[i] = sum;
  }

  for(i=0;i<total_processes;i++) {
    t_t[i] = time_comp[i] - arrival_time[i];
    t_sum += t_t[i];
  }

  for(i=0;i<total_processes;i++) {
    waiting_time[i] = t_t[i] - burst_time[i];
    w_sum += waiting_time[i];
  }

  cout << "Process\tA.T.\tB.T\tC.T\tT.T\tW.T" << endl;
  for(i=0;i<3;i++) {
    cout << "P" << i+1 << "\t" << arrival_time[i] << "\t" << burst_time[i] << "\t" << time_comp[i] << "\t" << t_t[i] <<"\t" << waiting_time[i] << endl;
  }

  cout << "Average Waiting Time: " << w_sum/float(total_processes) << endl;
  cout << "Average Turnaround Time: " <<  t_sum/float(total_processes) << endl;
  return 0;
}
