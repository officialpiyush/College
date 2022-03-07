#include <iostream>
using namespace std;

struct Process {
	int arrival_time;
	int burst_time;
	int run_time;
	int completion_time;
	int turnaround_time;
	int waiting_time;
};

int main() {
	int process_number=3, total_processes=3, time_quantum, i=0, cpu_run_time=0;
	int total_turnaround_time=0, total_waiting_time=0;

	cout << "Enter Time Quantumn: ";
	cin >> time_quantum;

	cout << "Enter number of processes: ";
	cin >> process_number;


	Process *process_store = new Process[process_number];

	for(i=0;i<process_number;i++){
		cout << "Enter Arrival Time of P" << i+1 << ": ";
		cin >> process_store[i].arrival_time;
		cout << "Enter Burst Time of P" << i+1 << ": ";
		cin >> process_store[i].burst_time;

		process_store[i].run_time = 0;
	}

	total_processes = process_number;

	while(total_processes > 0) {
		for(i=0; i<process_number; i++) {
			Process &process = process_store[i];

			if(process.burst_time == process.run_time) continue;

			int remaining_time = process.burst_time - process.run_time;
			if(remaining_time >= time_quantum) {
				process.run_time += time_quantum;
				cpu_run_time += time_quantum;			
			} else {
				int time_taken = time_quantum - remaining_time;
				process.run_time += time_taken;
				cpu_run_time += time_taken;
			}

			remaining_time = process.burst_time - process.run_time;

			if(remaining_time <= 0) {
				process.completion_time = cpu_run_time;
				total_processes--;
			}
		}
	}

	for(i=0; i<process_number; i++) {
		Process &process = process_store[i];

		int turnaround_time = process.completion_time - process.arrival_time;
		process.turnaround_time = turnaround_time;
		total_turnaround_time += turnaround_time;

		int waiting_time = turnaround_time - process.burst_time;
		process.waiting_time = waiting_time;
		total_waiting_time += waiting_time;
	}

	cout << "Process\tA.T.\tB.T.\tC.T.\tT.T.\tW.T" << endl;
	for(i=0; i<process_number; i++) {
		Process process = process_store[i];
		cout << "P" << i+1 << "\t" << process.arrival_time << "\t" << process.burst_time << "\t" << process.completion_time << "\t" << process.turnaround_time << "\t" << process.waiting_time << endl;
	}

	cout << "Average Turnaround Time: " << total_turnaround_time/3.0 << "\nAverage Waiting Time: " << total_waiting_time/3.0 << endl;
	return 0;
}
