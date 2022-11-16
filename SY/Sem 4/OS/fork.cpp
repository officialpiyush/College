#include <iostream>
#include <unistd.h>
#include <sys/types.h>
using namespace std;

int main() {
  pid_t p;
  p = fork();

  if(p<0) { // smaller than 0 for errors
    cout << "Errorr while creating a fork";
  } else if(p == 0) { // equal to 0 for child fork
    cout << "CHILD | PID: " << getpid() << endl;
    cout << "CHILD | Parent PID: " << getppid();
  } else { // greater than 0, contains process ID of created fork process
    cout << "PARENT | PID: " << getpid() << endl;
    cout << "PARENT | Child PID: " << p;
  }

  cout << endl << "Common to both processes" << endl;
  return 0;
}
