#include <iostream>
using namespace std;

int main()
{
  int frame_size, pages_size, page_fault=0;
  int i = 0, j = 0, k = 0;
  bool exists;

  cout << "Enter the size of the frame: ";
  cin >> frame_size;

  cout << "Enter the size of the pages: ";
  cin >> pages_size;

  int *input_stream = new int[pages_size];
  int *output = new int[frame_size];

  for(i=0; i<pages_size; i++) {
    cout << "Enter " << i+1 << "th input: ";
    cin >> input_stream[i];
  }

  cout << "Incoming";
  for(i=0;i<frame_size;i++) {
    cout << "\t Frame " << i+1;
    output[i] = -1;
  }

  for(i=0; i<pages_size; i++) {
    exists = false;
    for(j=0; j<=frame_size; j++) {
      if(input_stream[i] == output[j]) {
        exists = true;
        page_fault--;
      }
    }
    page_fault++;

    if(!exists) {
      if(page_fault <= frame_size) {
        output[i] = input_stream[i];
      } else {
        output[((page_fault - 1) % frame_size)] = input_stream[i];
      }
    }
    cout << endl;
    cout << input_stream[i] << "\t\t\t";
    for(k=0; k<frame_size;k++) {
      if(output[i] != -1) {
        cout << output[k] << "\t\t";
      } else {
        cout << "- \t\t";
      }
    }
  }

  cout << endl;
  cout << "Page Fault: " << page_fault << endl;
  cout << "Page Hit: " << pages_size - page_fault << endl;
}
