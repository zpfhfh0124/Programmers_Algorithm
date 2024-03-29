#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> cnts = vector<int>();
bool visited[50];

// 단어 철자 1개만 다를경우 true : 변환 가능
bool TransWordEnable(string word, string target)
{
	if (word.length() != target.length() || word.length() != 3) return false;

	int diff = 0;
	for (int i = 0; i < word.length(); i++)
	{
		if (word[i] != target[i]) diff++;
	}

	if (diff == 1) return true;
	else return false;
}

// 탐색 알고리즘 사용 - DFS
// 변환 가능한 단어를 찾아내는 재귀함수로 구현
void TransWord (string begin, string target, vector<string> words, int cnt = 0) 
{
	// target 있는지 검사
	//if (find(words.begin(), words.end(), target) == words.end()) cnts.push_back(0); return;

	// 탐색 시작
	for (int i = 0; i < words.size(); i++)
	{
		// 목표 단어 변환이 성립되면 return
		if (begin == target) {
			cnts.push_back(cnt);
			return;
		}

		// 변환이 가능한지 체크
		if (TransWordEnable(begin, words[i]) && !visited[i])
		{
			visited[i] = true;
			TransWord(words[i], target, words, cnt+1);
			visited[i] = false; // 백트래킹으로 인해 방문 체크 해제, 다음 분기점부터 탐색 재개
		}
	}

	return;
}

int main()
{
	vector<int> counts;
	vector<string> words = { "hot","dot", "dog", "lot", "log", "cog" };

	TransWord("hit", "cog", words);
	if (cnts.empty()) cnts.push_back(0);
	int min = *min_element(cnts.begin(), cnts.end());
	cout << "최소 : " << min << "회 변환" << endl;
}