#include <iostream>
#include <cstdio>
#include <ctime>
using namespace std;

int mainyboi() {
  clock_t start, end;
  double duration;

  start = clock();

  end = clock();
  duration = ( end - start ) / (double) CLOCKS_PER_SEC;

  cout<<"elapsed time: "<< duration <<'\n';
}
