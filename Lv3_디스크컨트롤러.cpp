#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

struct compare
{
	bool operator()(vector<int> a, vector<int> b) {
		return a[1] > b[1];
	}
};

priority_queue<vector<int>, vector<vector<int>>, compare> pq;

int solution(vector<vector<int>> jobs) {
	int currTiem = 0;  // 현재 시간
	int totalTime = 0; // 전체 소요 시간
	int cnt = 0;

	sort(jobs.begin(), jobs.end());

	while (cnt < jobs.size() || !pq.empty())
	{
		if (cnt < jobs.size() && jobs[cnt][0] <= currTiem) {
			pq.push(jobs[cnt++]);
		}
		else
		{
			// 작업 수행
			if (!pq.empty()) {
				currTiem += pq.top()[1];
				totalTime += currTiem - pq.top()[0];
				pq.pop();
			}
			// 작업이 없는 경우, 다음 작업 시간으로 갱신
			else {
				currTiem = jobs[cnt][0];
			}
		}
	}
	return totalTime / jobs.size();
}

int main() {
	vector<vector<int>> jobs = { {0,3}, {1,9}, {2,6} };
	int result = solution(jobs);
	cout << " 결과 : " << result;
}