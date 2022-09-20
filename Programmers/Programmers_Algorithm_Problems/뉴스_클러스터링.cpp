#include "뉴스_클러스터링.h"
#include <iostream>
#include <map>

using namespace std;

뉴스_클러스터링_BEGIN

#define DIV_NUM 65536

bool isAlpha(char ch) { return 'a' <= ch && ch <= 'z'; }

void findElements(string& str, map<string, int>& elementsInStr) {
    
    for (int i = 0; i < str.length(); i++) {

        if (isAlpha(str[i + 1]) == false) {
            i++;
            continue;
        }

        if (isAlpha(str[i]) == false)
            continue;

        elementsInStr[str.substr(i, 2)]++;
    }
}

int findIntersectionCount(map<string, int>& elements1, map<string, int>& elements2) {

    int count = 0;

    for (auto elementData : elements1) {

        string element = elementData.first;
        int elementCount = elementData.second;
    
        if (elements2.count(element) == 0)
            continue;

        count += min(elementCount, elements2[element]);
    }

    return count;
}

int findUnionCount(map<string, int>& elements1, map<string, int> elements2) {

    int count = 0;

    for (auto elementData : elements1) {

        string element = elementData.first;
        int elementCount = elementData.second;

        if (elements2.count(element) == 0) {
            count += elementCount;
            continue;
        }

        count += max(elementCount, elements2[element]);
        elements2.erase(element);
    }

    for (auto elementData : elements2) {
        int elementCount = elementData.second;
        count += elementCount;
    }

    return count;
}

int solution(string str1, string str2) {
    
    int answer = 0;
    
    for (int i = 0; i < str1.length(); i++)
        str1[i] = tolower(str1[i]);
    for (int i = 0; i < str2.length(); i++)
        str2[i] = tolower(str2[i]);

    map<string, int> elementsInStr1, elementsInStr2;

    findElements(str1, elementsInStr1);
    findElements(str2, elementsInStr2);

    int intersectionCount = findIntersectionCount(elementsInStr1, elementsInStr2);
    int unionCount = findUnionCount(elementsInStr1, elementsInStr2);

    if (intersectionCount == 0 && unionCount == 0)
        answer = 1 * DIV_NUM;
    else
        answer = (double)intersectionCount / unionCount * DIV_NUM;

    return answer;
}

void service() {

    string str1 = "FRANCE";
    string str2 = "french";

    cout << solution(str1, str2) << endl;
}

뉴스_클러스터링_END