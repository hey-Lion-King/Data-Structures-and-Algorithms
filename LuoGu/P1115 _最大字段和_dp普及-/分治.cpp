#include<iostream>
#include<limits>

using namespace std;

const int N = 2 * 1e5 + 10;
int n, a[N], T_max = INT_MIN;
int dp[N];

//该递归函数是自下而上
int maxSum(int* a, int l, int r)
{
	if (l == r) return a[l] > 0 ? a[l] : 0;

	int A_sum = 0;
	//int q = (r - l >> 1) + l;
	int q = r + l >> 1;
	int l_sum = maxSum(a, l, q), r_sum = maxSum(a, q + 1, r);

	int T_left_sum = INT_MIN, T_right_sum = INT_MIN;
	//左<-中
	for (int i = q, T_sum = 0; i >= l; i--) {
		T_sum += a[i];
		T_left_sum = max(T_sum, T_left_sum);
	}
	//中->右
	for (int i = q + 1, T_sum = 0; i <= r; i++) {
		T_sum += a[i];
		T_right_sum = max(T_sum, T_right_sum);
	}

	A_sum = T_left_sum + T_right_sum;
	if (A_sum < l_sum) A_sum = l_sum;
	if (A_sum < r_sum) A_sum = r_sum;

	return A_sum;
}

int main()
{
	cin >> n;

	for (int i = 0; i < n; i++) cin >> a[i];

	auto res = maxSum(a, 0, n - 1);
	cout << res;

	return 0;
}