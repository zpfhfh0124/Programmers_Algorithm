#include <iostream>
#include <set>
#include <string>
#include <algorithm>

using namespace std;

// 자연수 n | d(n) : n의 각 자리수와 n의 합 -> n은 d(n)의 제네레이터(generator)
// 제네레이터가 존재하지 않는 수 : 셀프 넘버 (self - number) -> d(n)값을 가지지 않는 것
// 1 이상 5000 미만의 모든 자연수 중 셀프 넘버들의 합 구하기

// 알고리즘 설계 과정 : 
// 1. 제네레이터 구하는 함수 구현
// 2. 1 ~ 5000가 들어 있는 셀프 넘버인지 아닌지 판별할 수 있는 자료구조를 생성 <int, bool>
// 3. 반복문으로 d함수를 이용하여 1 ~ 5000을 제네레이터로 하는 수를 구한다.
// 4. 1 ~ 5000 중 3번 과정에서 구한 값들 중 한 번도 값이 나오지 않은건 셀프 넘버

// Tip 
// Set 자료구조를 활용하자... 

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

	cout << "결과 : " << sum;

	return sum;
}