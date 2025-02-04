//降序数组使用lower_bound/upper_bound的正确示例
#include<bits/stdc++.h>
using namespace std;

int main()
{
  int a[] = {4, 4, 3, 3,  2, 2,  1, 1};
  cout<< lower_bound(a, a+8, 0,greater<int>())-a <<endl; // 输出 8
  cout<< lower_bound(a, a+8, 4,greater<int>())-a <<endl; // 输出 0
  cout<< lower_bound(a, a+8, 1,greater<int>())-a <<endl; // 输出 6
  cout<< lower_bound(a, a+8, 3,greater<int>())-a <<endl; // 输出 2
  cout<< lower_bound(a, a+8, 5,greater<int>())-a <<endl; // 输出 2

  cout<< upper_bound(a, a+8, 0,greater<int>())-a <<endl; // 输出 8
  cout<< upper_bound(a, a+8, 4,greater<int>())-a <<endl; // 输出 2
  cout<< upper_bound(a, a+8, 1,greater<int>())-a <<endl; // 输出 8
  cout<< upper_bound(a, a+8, 3,greater<int>())-a <<endl; // 输出 4
  cout<< upper_bound(a, a+8, 5,greater<int>())-a <<endl; // 输出 4
  cout<<binary_search(a,a+8,2,greater<int>())<<endl;
  return 0;
}

