#ifndef XYZXYZ_KPMENTRY
#define XYZXYZ_KPMENTRY

#include <string.h>

using namespace std;

class KpmEntry {
    public:
        string websiteName;
        string websiteUrl;
        string login;
        string password;

        KpmEntry();
        KpmEntry(string s1, string s2, string s3, string s4);
        void KpmPrint(ofstream o1);
};

KpmEntry::KpmEntry() {
    this->websiteName = "";
    this->websiteUrl = "";
    this->login = "";
    this->password = "";
}

KpmEntry::KpmEntry(string s1, string s2, string s3, string s4) {
    this->websiteName = s1; 
    this->websiteUrl = s2;
    this->login = s3;
    this->password = s4;
}



#endif
