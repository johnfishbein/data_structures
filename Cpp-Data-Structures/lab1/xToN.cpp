//jhf5my -- John Fishbein -- Thursday January 17, 2019
#include <iostream>
using namespace std;

int xton(int x, int n){
  if (n <= 0){
    return 1;
  }else{
    return x * xton(x, n - 1);
  }
  return 0;
}


int main(){
  int x, n, ans;
  cin >> x;
  cin >> n;
  ans = xton (x, n);
  cout << x << "^" << n << " = " << ans << endl;

  return 0;
}
