#include <iostream>
using namespace std;
int main()
{
  int size=0;
  cout<<"enter number of operations: "<<endl;
  cin>>size;
  int input_seq[size];
  cout<<"Enter seq of arrival:"<<endl;
  int sum=0;
  for(int i=0;i<size;i++)
  {
    cin>>input_seq[i];
  }
  for(int i=0;i<size;i++)
  {	if(i<size-1)
    {
      sum += abs(input_seq[i+1]-input_seq[i]);
    }
  }
  cout<<"the number of seek operations: "<<sum<<endl;
  cout<<"seek sequence is:"<<endl;
  for(int i=0;i<size;i++)
  {
    cout<<input_seq[i]<<endl;
  }
}
