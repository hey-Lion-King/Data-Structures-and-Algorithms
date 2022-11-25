#include<iostream>
#include<limits.h>

using namespace std;

const int N = 2 * 1e5 + 10;
long n, a[N],T_max=INT_MIN;
long dp[N];

//ÆÓËØdp
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];

	for (int i = 1; i <= n; i++)
	{
		dp[i] = max(dp[i - 1] + a[i], a[i]);
		T_max = max(T_max, dp[i]);
	}

	cout << T_max;

	return 0;
}