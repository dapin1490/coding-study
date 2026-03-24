#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

struct Song {
    int id;
    int play;
};

bool cmpPlays(pair<string, int> a, pair<string, int> b) {
    if (a.second > b.second)
        return true;
    return false;
}

bool cmpSongs(Song a, Song b) {
    if (a.play > b.play || (a.play == b.play && a.id < b.id))
        return true;
    return false;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    map<string, int> genrePlaySum;
    map<string, vector<Song>> genreSongs;
    vector<pair<string, int>> chartGenre;

    for (int i = 0; i < genres.size(); i++) {
        genrePlaySum[genres[i]] += plays[i];
        genreSongs[genres[i]].push_back(Song{i, plays[i]});
    }

    chartGenre = vector<pair<string, int>> (genrePlaySum.begin(), genrePlaySum.end());
    sort(chartGenre.begin(), chartGenre.end(), cmpPlays);

    for (auto i = chartGenre.begin(); i != chartGenre.end(); i++) {
        auto temp = genreSongs[i->first];
        int len = (temp.size() < 2 ? 1 : 2);
        sort(temp.begin(), temp.end(), cmpSongs);

        for (int j = 0; j < len; j++) {
            answer.push_back(temp[j].id);
        }
    }

    return answer;
}

#include <iostream>

int main() {
    vector<string> gen(5);
    vector<int> pl(5);

    for (int i = 0; i < 5; i++) {
        cin >> gen[i];
    }
    for (int i = 0; i < 5; i++) {
        cin >> pl[i];
    }

    auto ans = solution(gen, pl);

    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
}