/***

    Miscellaneous Routines
    Amalia Duch
    March 2018

***/


#ifndef util_hh
#define util_hh


/** Standard inclusions **/

#include <algorithm>
#include <vector>
#include <iostream>
#include <limits>
#include <cstdlib>
#include <cassert>
#include <cmath>
#include <sys/resource.h>

using namespace std;


// Function $n$-th power of base
long long pot(int base, int n) {
  long long p;
  p = 1;
  while (n-- > 0)
    p *= base;
  return p;
}

// Converting base 10 to base 2
void dec2bin(int n, string& w, int k) {
  int i;
  for (i = 0; i  < k; i++) w[i] = '0';
  i = 0;
  while (n > 0) {
    w[i++] = n % 2 + '0';
    n /= 2;
  }
}

// Converting base 2 to base 10
int bin2dec(string w, int k) {
  int res = 0;
  for (int i = k - 1; i >= 0; i--)
    res = res * 2 + (w[i] - '0');
  return res; 
}

// Random numbers generation

//Returns a random real in $[0,1)$
inline double uniform(){
    return rand()/double(RAND_MAX);
}

//Returns a random integer in $[a,b]$
inline int rand_int(int a, int b){
    return a + rand() % (b-a+1);
}

//Returns a random integer in $[0,n-1]$
inline int rand_int(int n){
    return rand() % n;
}

//Returns true with probability $p$
inline bool rand_bit(double p){
    return uniform() < p;
}

//Returns a vector of $n$ random reals
vector<double> vector_uniform (int n){
    vector<double> v(n);
    for(int i=0; i<n; ++i) v[i] = uniform();
    return v;
}

//Returns a vector of $n$ random integers between $a$ and $b$
vector<int> randvector_int (int n, int a, int b){
    vector<int> v(n);
    for(int i=0; i<n; ++i) v[i] = rand_int(a,b);
    return v;
}

// Prints a K-dimensional point (K-d point = vector<double>)
void print_Kd_point(const vector<double>& p){
    for (int jp = 0; jp < p.size()-1; ++jp)
        cout << p[jp] << ",";
    cout << p[p.size()-1] << endl;
}

#endif

