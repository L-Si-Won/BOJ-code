#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct cnf
{
	int start;
	int end;
};

bool cmp(cnf t1, cnf t2)
{
	if(t1.end == t2.end)
		return t1.start < t2.start;
	else
		return t1.end < t2.end;
}

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n=0;
	cin >> n;

	vector<cnf> v(n);
	for(int i=0; i<n; i++)
		cin >> v[i].start >> v[i].end;

	sort(v.begin(), v.end(), cmp);
	
	int cnt=0;
	int a=0;
	for(int i=0; i<v.size(); i++)
	{
		if(a <= v[i].start)
		{
			a = v[i].end;
			cnt++;
		}
	}

	cout << cnt;
}
