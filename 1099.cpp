#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <queue>


using namespace std;

struct Word
{
    string str;
    int c;
    Word(string s, int cc) {
        str=s;
        c=cc;
    }
};


int main()
{
    string a, b;
    cin >> a >> b;
    queue<Word> q;
    q.push(Word(a, 0));

    map<string, string> dict;
    string aa, bb;
    while(cin >> aa >> bb) {
        dict.insert(make_pair(aa, bb));
    }

    while(!q.empty()) {
        Word cur = q.front();
        q.pop();
        if(cur.c>9) {
            cout << "NO ANSWER!" << endl;
            return 0;
        }

        for(map<string, string>::iterator i=dict.begin(); i!=dict.end(); i++) {
            string pp = i->first;
            string qq = i->second;
            size_t found = 0;
            while(found!=string::npos) {
                if(found == 0) {
                    found = cur.str.find(pp);
                    if(found!=string::npos)
                        found++;
                } else {
                    found = cur.str.find(pp, found);
                }

                if(found!=string::npos) {
                    string word = cur.str.substr(0, found-1) + qq + cur.str.substr(found-1+pp.size());
                    //cout << word << endl;
                    if(word.compare(b)==0) {
                        cout << cur.c+1;
                        return 0;
                    }
                    q.push(Word(word, cur.c+1));
                }

            }

        }
    }


    return 0;
}

