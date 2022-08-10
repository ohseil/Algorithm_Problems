#include "ÃÖ´ñ°ª°ú_ÃÖ¼Ú°ª.h"
#include <iostream>
#include <string>
#include <limits.h>

using namespace std;

ÃÖ´ñ°ª°ú_ÃÖ¼Ú°ª_BEGIN

string solution(string s) {

    string answer = "";

    int maxNum = INT_MIN;
    int minNum = INT_MAX;

    while (s.length() > 0) {

        int num = stoi(s.substr(0, s.find(" ")));

        if (num > maxNum)
            maxNum = num;
        if (num < minNum)
            minNum = num;

        if (0 > s.find(" ") || s.find(" ") >= s.length())
            break;

        s = s.substr(s.find(" ") + 1);
    }

    answer = to_string(minNum) + " " + to_string(maxNum);

    return answer;
}

void service() {

    string str = "1 2 3 4";
    cout << solution(str) << endl;
}

ÃÖ´ñ°ª°ú_ÃÖ¼Ú°ª_END