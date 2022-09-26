#include "파일명_정렬.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

파일명_정렬_BEGIN

bool cmp(pair<int, pair<string, int>> lhs, pair<int, pair<string, int>> rhs) {
    if (lhs.second.first < rhs.second.first)
        return true;
    else if (lhs.second.first == rhs.second.first)
        if (lhs.second.second < rhs.second.second)
            return true;
    return false;
}

vector<string> solution(vector<string> files) {
    
    // head와 number 정보를 이용해서 정렬.
    // 이 때, 주의해야 할 점은
    // 정렬할때 모든 조건이 같다면 기존의 순서를 유지해야 한다는 것이다.
    // 이것은 안정정렬을 의미한다.
    // c++에서 제공하는 sort() 함수는 quick sort 기반이기 때문에 불안정 정렬이다.
    // 따라서 같은 데이터끼리의 순서가 정렬 전 순서와 다를 수 있기 때문에 stable_sort()를 사용해야 한다.

    vector<string> answer;
    
    vector<pair<int, pair<string, int>>> sortingFileInfos;

    for (int i = 0; i < files.size(); i++) {

        string file = files[i];

        int idx;
        string head;
        int number;

        for (int j = 0; j < file.length(); j++) {
            if ('0' <= file[j] && file[j] <= '9') 
                break;
            idx = j;
        }

        head = file.substr(0, idx + 1);
        file = file.substr(idx + 1);

        for (int j = 0; j < file.length(); j++) {
            if (('0' <= file[j] && file[j] <= '9') == false)
                break;
            idx = j;
        }

        number = stoi(file.substr(0, idx + 1));

        for (int j = 0; j < head.length(); j++)
            head[j] = tolower(head[j]);

        sortingFileInfos.push_back({ i, { head, number } });
    }

    stable_sort(sortingFileInfos.begin(), sortingFileInfos.end(), cmp);

    for (auto fileInfo : sortingFileInfos)
        answer.push_back(files[fileInfo.first]);

    return answer;
}

void service() {

    vector<string> files = { "img12.png", "img10.png", "img02.png", "img1.png", "IMG01.GIF", "img2.JPG" };

    vector<string> ans = solution(files);
    for (auto a : ans)
        cout << a << " ";
    cout << endl;
}

파일명_정렬_END