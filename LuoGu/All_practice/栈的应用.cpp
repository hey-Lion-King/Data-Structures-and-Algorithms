#include<iostream>
#include<vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(false); 
	cin.tie(0); cout.tie(0);
	string a;
	//vector<char> A;

	int l = 0, r = 0;
	cin >> a;

	for (int i = 0; i < a.size() - 1; i++)
	{
		if (a[i]=='(')	l++;
		if (a[i] == ')')
			if (l > 0) {
				l--; //r--;
			}
			else {
				cout << "NO" << endl;
				return 0;
			}
	}

	if (l != 0) cout << "NO" << endl;
	else cout << "YES" << endl;;

	return 0;
}