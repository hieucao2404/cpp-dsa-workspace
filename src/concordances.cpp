#include <bits/stdc++.h>
using namespace std;

struct ConcordanceEntry {
    int poemId;
    int lineId;
    vector<string> words;
    string starredWord;
};

ConcordanceEntry parseLine(const string& line) {
    ConcordanceEntry entry;
    stringstream ss(line);
    string idPart;
    ss >> idPart;

    //split into poemId:lineId
    size_t pos = idPart.find(':');
    entry.poemId = stoi(idPart.substr(0, pos));
    entry.lineId = stoi(idPart.substr(pos + 1));

    string word;
    while(ss >> word) {
        if(word[0] == '"'){
            entry.starredWord = word.substr(1);
            word = entry.starredWord;
        }
        entry.words.push_back(word);
    }
    return entry;
}


//Merge fragmennts by overlapping words
vector<string> mergeFragments(vector<ConcordanceEntry> &frags) {
    vector<string> result = frags[0].words;

    for(size_t i = 1; i < frags.size(); i++){
        vector<string> &frag = frags[i].words;
        bool merged = false;

        //try to overlap
        for(size_t overlap = frag.size(); overlap > 0; overlap--) {
            if(result.size() >= overlap) {
                bool match = true;
                for (size_t k = 0; k < overlap; k++){
                    if(result[result.size() - overlap + k] != frag[k]){
                        match = false;
                        break;
                    }
                }
                if(match) {
                    result.insert(result.end(), frag.begin() + overlap, frag.end());
                    merged = true;
                    break;
                }
            }
        }
        if(!merged) {
            //if no overlap, just append
            result.insert(result.end(), frag.begin(), frag.end());
        }
    }
    return result;
    
}

int main(){
    //example concordance lines
    vector<string> raw = {
       "1:2 was \"\"day to day!",
        "1:2 was day to *day!",
        "1:2 so very like, *was day"  
    };

    vector<ConcordanceEntry> entries;
    for(auto &line :raw) {
        entries.push_back(parseLine(line));
    }

    //group by poem and line
    map<pair<int,int>, vector<ConcordanceEntry>> groups;
    for(auto &e : entries){
        groups[{e.poemId, e.lineId}].push_back(e);
    } 

    //Reconstruct each line
    for(auto &g : groups) {
        auto poemId = g.first.first;
        auto lineId = g.first.second;
        auto &frags = g.second;

        //Merge fragmments
        vector<string> lineWords = mergeFragments(frags);

        //print result
        cout << "Poem " << poemId << " Line " << lineId  << ": ";
        for(size_t i = 0; i < lineWords.size(); i++){
            cout << lineWords[i];
            if(i + 1 < lineWords.size()) cout << " ";
        }
        cout << endl;
    }
}
