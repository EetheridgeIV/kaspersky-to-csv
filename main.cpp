#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "entry.h"

using namespace std;

void PrintUsage() {
    cout << "Usage: ./ConvertToCSV <input.txt>\n";
}

void KpmPrint(vector<KpmEntry*> entries) {
    ofstream outfile;
    outfile.open("1pass.csv");

    for(int i = 0; i < entries.size(); i++) {
        outfile << entries[i]->websiteName.substr(0, entries[i]->websiteName.length() - 1)
            << ","
            << entries[i]->websiteUrl.substr(0, entries[i]->websiteUrl.length() - 1)
            << ","
            << entries[i]->login.substr(0, entries[i]->login.length() - 1)
            << ","
            << entries[i]->password
            << endl;
    }

    outfile.close();
}

int main(int argc, char* argv[]) {
    if(argc != 2) {
        PrintUsage();
    }

    ifstream infile(argv[1]);
    string line;
    string webName, webUrl, login, pass;

    vector<KpmEntry*> entries;

    while(getline(infile, line)) {

        if(line.substr(0,12) == "Applications") {
            break;
        }

        if(line.substr(0,14) == "Website name: ") {
            webName = line.substr(14, line.length() - 14);
        }
        else if(line.substr(0,13) == "Website URL: ") {
            webUrl = line.substr(13, line.length() - 13);
        }
        else if(line.substr(0,7) == "Login: ") {
            login = line.substr(7, line.length() - 7);
        }
        else if(line.substr(0,10) == "Password: ") {
            pass = line.substr(10, line.length() - 10);
        }
        else if(line.substr(0,3) == "---") {
            KpmEntry* k = new KpmEntry(webName, webUrl, login, pass);
            entries.push_back(k);
        }
    }
    KpmPrint(entries);

    return 0;
}
