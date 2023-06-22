#include <iostream>
#include <string>

using namespace std;

// 제곱해서 나온 수의 끝에 원래 수가 포함되어 있는지 확인
int F(int x) 
{
	int isRight = 1;
	int sqrt = x * x;
	int len = to_string(x).length();

	for (int i = 0; i < len; i++)
	{
		int sqrt_mod = sqrt % 10;
		sqrt /= 10;
		int x_mod = x % 10;
		x /= 10;

		if (sqrt_mod != x_mod) 
		{
			isRight = 0;
			break;
		}
	}

	return isRight;
}

int main() 
{
	int x;
	cout << "임의의 정수를 입력 : " << endl;
	cin >> x;

	cout << F(x);
}