#include <iostream>
#include <set>
#include<map>
#include <fstream>

using namespace std;

string removePunct(string word);
string toLower(const string &s);

int main() {

    string keyword,fileName, text = "", word;
    map <string, int> table;
    int keywordCounter=0, wordCounter=0, fail=1;

    loop:
    cout<<"Enter the name of the file that you want to copy text from: ";
    cin>>fileName; //name of the file is: test.txt

    ifstream ifs(fileName);
    while(fail==1) {
        if (ifs.fail()) {
            cout << "Could not load the file, try again" << endl;
            goto loop;
        }
        else{
            cout<<"File loaded successfully"<<endl;
            fail=0;
        }
    }
    cout << "Enter keyword you want to find: " << endl;
    cin >> keyword;
    while(!ifs.eof()){
        //getline(ifs, text);
        ifs >> word;
        text.append(word);
        word = removePunct(word);
        word = toLower(word);
        if (word == keyword) keywordCounter++;
        text.append(" ");
        if (word[0] != '$')wordCounter++;
    }
    ifs.close();

    //cout<<text<<endl;

    cout<<"amount of words: "<<wordCounter<<endl;
    cout<<"amount of keyword found: "<<keywordCounter<<endl;
    return 0;
}

//remove punctuation from string

string removePunct(string word){
    for (int i=0; i<word.size();i++){
        if(ispunct(word[i])){
            word.erase(i);
        }
    }
    return word;
}



string toLower(const string &s) {
    int i = 0;
    string lower=s;
    while (s[i] != '\0') {
        if (s[i] >= 'A' && s[i] <= 'Z') {
            lower[i] = s[i] + 32;
        }
        i++;
    }
    return lower;
}
