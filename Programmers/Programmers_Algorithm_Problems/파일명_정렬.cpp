#include "���ϸ�_����.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

���ϸ�_����_BEGIN

bool cmp(pair<int, pair<string, int>> lhs, pair<int, pair<string, int>> rhs) {
    if (lhs.second.first < rhs.second.first)
        return true;
    else if (lhs.second.first == rhs.second.first)
        if (lhs.second.second < rhs.second.second)
            return true;
    return false;
}

vector<string> solution(vector<string> files) {
    
    // head�� number ������ �̿��ؼ� ����.
    // �� ��, �����ؾ� �� ����
    // �����Ҷ� ��� ������ ���ٸ� ������ ������ �����ؾ� �Ѵٴ� ���̴�.
    // �̰��� ���������� �ǹ��Ѵ�.
    // c++���� �����ϴ� sort() �Լ��� quick sort ����̱� ������ �Ҿ��� �����̴�.
    // ���� ���� �����ͳ����� ������ ���� �� ������ �ٸ� �� �ֱ� ������ stable_sort()�� ����ؾ� �Ѵ�.

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

���ϸ�_����_END