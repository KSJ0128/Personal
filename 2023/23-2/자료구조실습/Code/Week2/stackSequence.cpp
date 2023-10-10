#include <iostream>
#include <stack>
#include <queue>
using namespace std;
int main()
{
	stack<int> st;
	queue<char> que;
	bool status = true;
	int n, stack_num = 1, input_num;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> input_num;
		
		if (input_num >= stack_num)
		{
			while (input_num >= stack_num)
			{
				st.push(stack_num);
				que.push('+');
        stack_num += 1;
			}
			st.pop();
			que.push('-');
		}
		else
		{
			if (st.top() != input_num)
			{
				cout << "NO";
				status = false;
				break;
			}
			else
			{
				st.pop();
				que.push('-');
			}
		}
	}
	if (status == true)
	{
		while (!que.empty())
		{
			cout << que.front() << endl;
			que.pop();
		}
	}
}