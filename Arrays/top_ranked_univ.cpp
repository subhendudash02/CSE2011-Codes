#include <iostream>
#include <cstring>

using namespace std;

void print(char college[][6], int from, int to){
    for (int i = from; i < to; i++){
        cout << "Rank " << i + 1 << ": ";
        for (int j = 0; j < 5; j++){
            cout << college[i][j];
        }
        cout << endl;
    }
}

int main(){

    cout << "Name: Subhendu Dash" << endl;
    cout << "Reg-No: 20BEE1004" << endl;
    cout << " " << endl;

    char coll[50][6] = {"IITB", "IITK", "IITR", "IITRK", "IITZ", "IITP", "FHFO", "ERBS", "IITE", "BITP", "BITH", "BITG", "VITV", "VITC", "VITA", "VITB", "FJGE", "QBFF", "DLEN", "DRBE", "SRGG", "SSJR", "AFNG", "CNDJ", "DKFR", "FWWN", "WWNQ", "LAOF", "QNVB", "BNDA", "LDMS", "FNDAJ", "XERT", "XLRI", "FENW", "PFJFR", "IRBW", "DQWNE", "FRNEW", "ENWQK", "DEBWW", "WNEE", "DNWR", "DWNF", "FNWM", "KIT", "WNW", "DMGE", "KDBR", "WENG"};

    cout << "Top 10 Colleges in India: " << endl;
    print(coll, 0, 10);

    cout << "Remaining Universities: " << endl;
    print(coll, 10, 50);

    return 0;
}