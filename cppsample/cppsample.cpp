#include <bits/stdc++.h>
using namespace std;

int main() {
#ifdef _MSC_VER
	//標準入力をファイルに設定
	ifstream in("../include/atcoder-stdinput.txt");
	cin.rdbuf(in.rdbuf());
#endif
	string line;
	while (!cin.eof()) {
		getline(cin, line);
		cout << line << endl;
	}
}