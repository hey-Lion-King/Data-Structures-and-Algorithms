#include<iostream>
#include<limits.h>

using namespace std;
const int N = 2 * 1e5 + 10;
int n, a[N], T_max = INT_MIN, T_sum = 0;
int dp[N];

//ÓÅ»¯dp
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];

	for (int i = 0; i < n; i++)
	{
		if (T_sum < 0) T_sum = 0;
		T_sum += a[i];
		T_max = max(T_max, T_sum);
	}

	cout << T_max;

	return 0;
}