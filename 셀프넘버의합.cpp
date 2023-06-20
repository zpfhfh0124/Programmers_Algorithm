#include <iostream>
#include <set>
#include <string>
#include <algorithm>

using namespace std;

// �ڿ��� n | d(n) : n�� �� �ڸ����� n�� �� -> n�� d(n)�� ���׷�����(generator)
// ���׷����Ͱ� �������� �ʴ� �� : ���� �ѹ� (self - number) -> d(n)���� ������ �ʴ� ��
// 1 �̻� 5000 �̸��� ��� �ڿ��� �� ���� �ѹ����� �� ���ϱ�

// �˰��� ���� ���� : 
// 1. ���׷����� ���ϴ� �Լ� ����
// 2. 1 ~ 5000�� ��� �ִ� ���� �ѹ����� �ƴ��� �Ǻ��� �� �ִ� �ڷᱸ���� ���� <int, bool>
// 3. �ݺ������� d�Լ��� �̿��Ͽ� 1 ~ 5000�� ���׷����ͷ� �ϴ� ���� ���Ѵ�.
// 4. 1 ~ 5000 �� 3�� �������� ���� ���� �� �� ���� ���� ������ ������ ���� �ѹ�

// Tip 
// Set �ڷᱸ���� Ȱ������... 

set<int> set_numbers;

int d(int n) {
	int sum = 0;
	int len = to_string(n).length();
	int digit = 0;
	sum += n;

	for (int i = 0; i < len; i++) {
		
		digit = n % 10;
		sum += digit;
		n /= 10;
	}

	return sum;
}

int main()
{
	for (int i = 1; i <= 5000; i++) {
		set_numbers.insert(d(i));
	}

	//sort(set_numbers.begin(), set_numbers.end());

	int sum = 0;
	for (int i = 1; i <= 5000; i++) {
		auto find = set_numbers.find(i);
		if (find == set_numbers.end()) sum += i;
	}

	cout << "��� : " << sum;

	return sum;
}