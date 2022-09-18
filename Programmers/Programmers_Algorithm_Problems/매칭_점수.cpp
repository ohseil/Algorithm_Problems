#include "매칭_점수.h"
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

매칭_점수_BEGIN

string findURLInPage(string page) {
    string urlMetaString = "<meta property=\"og:url\" content=\"";
    page = page.substr(page.find(urlMetaString) + urlMetaString.length());
    return page.substr(0, page.find("\""));
}

bool isAlpha(char ch) {
    return 'a' <= ch && ch <= 'z';
}

double searchWordCount(string& word, string page) {

    int count = 0;

    int idx = page.find(word);
    char lastCharacter = '?';

    while (0 <= idx && idx < page.length()) {

        if (((idx - 1 < 0 && isAlpha(lastCharacter) == false) || (idx - 1 >= 0 && isAlpha(page[idx - 1]) == false)) &&
            isAlpha(page[idx + word.length()]) == false) {
            count++;
        }
        
        lastCharacter = page[idx + word.length() - 1];
        page = page.substr(idx + word.length());
        idx = page.find(word);
    }

    return count;
}

void countLinks(string page, string& url, map<string, vector<string>>& outerLinks, map<string, vector<string>>& innerLinks) {

    string linkMetaString = "<a href=\"";

    int idx = page.find(linkMetaString);

    while (0 <= idx && idx < page.length()) {

        page = page.substr(idx + linkMetaString.length());

        string linkURL = page.substr(0, page.find("\""));

        outerLinks[url].push_back(linkURL);
        innerLinks[linkURL].push_back(url);

        page = page.substr(linkURL.length());
        idx = page.find(linkMetaString);
    }
}

bool cmp(pair<double, int> lhs, pair<double, int> rhs) {
    if (lhs.first > rhs.first)
        return true;
    else if (lhs.first == rhs.first)
        if (lhs.second < rhs.second)
            return true;
    return false;
}

int solution(string word, vector<string> pages) {
    
    // 각 페이지마다
    // 기본 점수, 외부로 나가는 링크의 url, 외부로부터 들어오는 링크의 url
    // 데이터들을 각 map으로 저장한다.

    // 저장해 놓은 데이터로 각 페이지의 매칭점수를 계산하고,
    // 조건에 맞게 정렬하여 첫 번째 index의 데이터를 선택한다.

    int answer = 0;
    
    vector<string> pageOrders;
    map<string, double> normalScores;
    map<string, vector<string>> outerLinks, innerLinks;

    for (int i = 0; i < word.length(); i++)
        word[i] = tolower(word[i]);

    for (int i = 0; i < pages.size(); i++)
        for (int j = 0; j < pages[i].length(); j++)
            pages[i][j] = tolower(pages[i][j]);

    for (string page : pages) {

        string url = findURLInPage(page);

        normalScores[url] = searchWordCount(word, page);
        countLinks(page, url, outerLinks, innerLinks);
    
        pageOrders.push_back(url);
    }

    vector<pair<double, int>> orderV;

    for (int i = 0; i < pageOrders.size(); i++) {

        string pageURL = pageOrders[i];
        double matchScore = normalScores[pageURL];

        for (string linkingPageURL : innerLinks[pageURL]) {
            matchScore += (normalScores[linkingPageURL] / outerLinks[linkingPageURL].size());
        }

        orderV.emplace_back(matchScore, i);
    }

    sort(orderV.begin(), orderV.end(), cmp);

    answer = orderV[0].second;

    return answer;
}

void service() {

    string word = "blind";
    vector<string> pages = { "<html lang=\"ko\" xml:lang=\"ko\" xmlns=\"http://www.w3.org/1999/xhtml\">\n<head>\n  <meta charset=\"utf-8\">\n  <meta property=\"og:url\" content=\"https://a.com\"/>\n</head>  \n<body>\nBlind Lorem Blind ipsum dolor Blind test sit amet, consectetur adipiscing elit. \n<a href=\"https://b.com\"> Link to b </a>\n</body>\n</html>", 
        "<html lang=\"ko\" xml:lang=\"ko\" xmlns=\"http://www.w3.org/1999/xhtml\">\n<head>\n  <meta charset=\"utf-8\">\n  <meta property=\"og:url\" content=\"https://b.com\"/>\n</head>  \n<body>\nSuspendisse potenti. Vivamus venenatis tellus non turpis bibendum, \n<a href=\"https://a.com\"> Link to a </a>\nblind sed congue urna varius. Suspendisse feugiat nisl ligula, quis malesuada felis hendrerit ut.\n<a href=\"https://c.com\"> Link to c </a>\n</body>\n</html>", 
        "<html lang=\"ko\" xml:lang=\"ko\" xmlns=\"http://www.w3.org/1999/xhtml\">\n<head>\n  <meta charset=\"utf-8\">\n  <meta property=\"og:url\" content=\"https://c.com\"/>\n</head>  \n<body>\nUt condimentum urna at felis sodales rutrum. Sed dapibus cursus diam, non interdum nulla tempor nec. Phasellus rutrum enim at orci consectetu blind\n<a href=\"https://a.com\"> Link to a </a>\n</body>\n</html>" };

    cout << solution(word, pages) << endl;
}

매칭_점수_END