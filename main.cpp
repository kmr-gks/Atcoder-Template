// エディタでひな形部分を折りたたむため#ifブロックで囲む
#if 1
//手元でコンパイル:
// atcoder側のコンパイルコマンド
// https://atcoder.jp/contests/language-test-202001
// g++ -std=gnu++17 -Wall -Wextra -O2 -DONLINE_JUDGE main.cpp
//clang++ -std=c++17 -stdlib=libc++ -Wall -O2 -DNDEBUG -DONLINE_JUDGE -I /usr/include/c++/11 -I /usr/include/x86_64-linux-gnu/c++/11 main.cpp

#ifndef ONLINE_JUDGE	// VSでビルドするとき

// VSで発生するエラーの対策
// no_init_all 不明な属性
#ifndef no_init_all
#define no_init_all deprecated
#endif
#define _CRT_SECURE_NO_WARNINGS

#define NOMINMAX	 // std::maxとWindowsAPIが競合する
#include <windows.h>
#include <ShlObj.h>

#endif

// clangでは bits/stdc++.hはつかえない
#include <bits/stdc++.h>

//#include <atcoder/all>
// using namespace atcoder; //atcoder libraryを使うなら必要

//ループやイテレータの操作を簡単化
#define rep(i, a, b) for (int i = a; i < b; i++)
#define repll(i, a, b) for (ll i = a; i < b; i++)
#define repmodll(i, a, b) for (modll i = a; i < b; i++)
#define fore(youso, hairetsu) for (auto &youso : hairetsu)
#define all(x) (x).begin(), (x).end()

//変換関数の別名
#define toString to_string
#define toInt stoi
#define toLL stoll
#define toLl stoll

namespace myns
{
	//型の別名
	using ll = long long int;
	using ull = unsigned long long int;
	using ld = long double;

	//円周率
	constexpr long double pi = 3.141592653589793238462643383279;

	//long longの最大値:9e18
	constexpr ll infll = 922'3372'0368'5477'5807LL;

	//intの最大値:2e9
	constexpr int inf = 21'4748'3647;

#ifndef ONLINE_JUDGE//VS
	//ここからプロトタイプ宣言
	//規定引数を定義とプロトタイプ宣言両方で行うとエラー

	//コンソールのウィンドウハンドルを取得
	HWND GetConsoleHwnd(bool multiwindows);
	//ハンドルを取得して最前面に持ってくる
	void SetConsoleTopMost(bool enable, bool multiwindows);
	//デスクトップフォルダーのパスを取得(ASCII/Shift-JIS)
	std::string getDesktopPath();

	//標準入力のパス
	const std::string path = myns::getDesktopPath() + std::string("\\coding\\source\\atcoder-stdInput.txt");
#else
	//提出時
	void SetConsoleTopMost(bool = false, bool = false) {}
#endif

	//2つの値を比較 左に代入
	template <class T> constexpr bool chmax(T& a, const T& b);
	template <class T> constexpr bool chmin(T& a, const T& b);

	// std::vectorの中に要素が含まれているかを調べる
	template <class V, class T> constexpr bool contains(const V& v, const T& a)noexcept;

	//変数名だけでソート(std::vector)
	template <class T> constexpr void sort(std::vector<T>& v);
	template <class T> constexpr void gyakusort(std::vector<T>& v);//逆順

	//文字列の前方一致/後方一致
	bool startsWith(const std::string& a, const std::string& b)noexcept;
	bool endsWith(const std::string& a, const std::string& b)noexcept;

	//文字列分割
	std::vector<std::string> split(const std::string& str, const std::string& separator, bool deleteBlank)noexcept;
	std::vector<std::wstring> split(const std::wstring& str, const std::wstring& separator, bool deleteBlank)noexcept;
	template <typename T> constexpr bool next_combination(const T first, const T last, int k) noexcept;
	constexpr ll nCk_lowlevel(ll n, ll k) noexcept;
	template<typename T> constexpr T gcd(std::vector<T> const& a)noexcept;

	//集合vの要素に対して関数fを呼び出す。最後に関数flastを呼び出す。
	//デフォルトの引数は f = [](const auto& n) {std::cout << n << ' '; },flast = [](const T& v) {}
	template<class T, class U, class V = std::function<void(const T&)>> constexpr void print(const T& v, const U& f = [](const auto& n) {std::cout << n << ' '; }, const V& flast = [](const T&) {}) noexcept;

	//std::vectorを要素ごとに自動でstd::cin/std::cout
	//その時のマニピュレータのように使う

	//縦表示にする 例:std::cout<<TateHyoji
	struct tagTatehyoji {}TateHyoji;

	//横表示にする 例:std::cout<<YokoHyoji
	struct tagYokohyoji {}YokoHyoji;

	//これは内部的に使用する
	bool cout_vector_tatehyoji = false;

	//手元でのみ表示する

	struct tagMyCout {} dout;//debug std::cout
	struct tagMyCerr {} derr;//debug std::cerr

	//文字色
	//gccではenum text_color;のように前方宣言ができない？
	//enum text_color;
	enum text_color { white, black, red, blue, green, reset, normal };

	//演算子のオーバーロードのプロトタイプ宣言

	//できれば統一したい
	//配列要素を表示
	template<class T> constexpr std::ostream& operator<<(std::ostream& os, const std::vector<T>& v) noexcept;
	//配列要素を入力
	template<class T> constexpr std::istream& operator>>(std::istream& is, std::vector<T>& v) noexcept;
	//初期化子リストを表示
	template<class T> constexpr std::ostream& operator<<(std::ostream& os, const std::initializer_list<T>& v) noexcept;
	//両端キューを表示
	template<class T> constexpr std::ostream& operator<<(std::ostream& os, const std::deque<T>& v) noexcept;
	//連想配列を表示
	template<class T, class U> constexpr std::ostream& operator<<(std::ostream& os, const std::map<T, U>& v) noexcept;

	//std::pairを表示
	template<class T, class U> constexpr std::ostream& operator<<(std::ostream& os, const std::pair<T, U>& p) noexcept;
	//std::pairを入力
	template<class T, class U> constexpr std::istream& operator>>(std::istream& is, std::pair<T, U>& p) noexcept;

	//色表示マニピュレーター
	std::ostream& operator<<(std::ostream& os, text_color color)noexcept;
	//縦表示マニピュレーター
	constexpr std::ostream& operator<<(std::ostream& os, const tagTatehyoji&)noexcept;
	//横表示マニピュレーター
	constexpr std::ostream& operator<<(std::ostream& os, const tagYokohyoji&)noexcept;

	//endl用(第2引数は関数ポインタ)
	tagMyCout& operator<<(tagMyCout& myOs, std::ostream& (*)(std::ostream&)) noexcept;
	tagMyCerr& operator<<(tagMyCerr& myOs, std::ostream& (*)(std::ostream&)) noexcept;

	//std::coutのコピー
	template<class T> constexpr tagMyCout& operator<<(tagMyCout& myOs, const T& thing) noexcept;
	template<class T> constexpr tagMyCerr& operator<<(tagMyCerr& myOs, const T& thing) noexcept;

	//標準入力リダイレクト
	std::string GetClipboardText();
	bool SetStandardInput();
	bool SetStandardInput(std::string strPath);
	//標準出力リダイレクト
	bool SetStandardOutput();
	bool SetStandardOutput(std::string strPath);

}

#ifndef ONLINE_JUDGE
//コンソールのウィンドウハンドルを取得
HWND myns::GetConsoleHwnd(bool multiwindows)
{
	constexpr int MY_BUFSIZE = 1024;
	HWND hwndFound;
	TCHAR pszNewWindowTitle[MY_BUFSIZE];
	TCHAR pszOldWindowTitle[MY_BUFSIZE];
	ULARGE_INTEGER nt = { 0,0 };
	nt.QuadPart = GetTickCount64();
	GetConsoleTitle(pszOldWindowTitle, MY_BUFSIZE);
	if (multiwindows) {
		wsprintf(pszNewWindowTitle, TEXT("%d%d/%d"), nt.HighPart, nt.LowPart, GetCurrentProcessId());
		SetConsoleTitle(pszNewWindowTitle);
		Sleep(40);
		hwndFound = FindWindow(NULL, pszNewWindowTitle);
		SetConsoleTitle(pszOldWindowTitle);
	}
	else {
		hwndFound = FindWindow(NULL, pszOldWindowTitle);
	}
	return (hwndFound);
}
//ハンドルを取得して最前面に持ってくる
void myns::SetConsoleTopMost(bool enable = true, bool multiwindows = false)
{
	if (enable) {
		HWND hwndConsole = GetConsoleHwnd(multiwindows);
		MoveWindow(hwndConsole, 1000, 550, 800, 500, TRUE);
		SetWindowPos(hwndConsole, HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);
		SetActiveWindow(hwndConsole);
	}
	SetConsoleTitle(TEXT("Ready"));
}

std::string myns::getDesktopPath() {
	char desktopPath[1000];
	SHGetSpecialFolderPathA(nullptr, desktopPath, CSIDL_DESKTOP, FALSE);
	return desktopPath;
}

std::ostream& myns::operator<<(std::ostream& os, myns::text_color color) noexcept {
	WORD wTextColor = FOREGROUND_INTENSITY;
	switch (color) {
	case white: {
		wTextColor = FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED;
		break;
	}
	case black: {
		wTextColor = 0;
		break;
	}
	case blue: {
		wTextColor = FOREGROUND_BLUE;
		break;
	}
	case green: {
		wTextColor = FOREGROUND_GREEN;
		break;
	}
	case red: {
		wTextColor = FOREGROUND_RED;
		break;
	}
	case reset:
	case normal: {
		wTextColor = FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED;
		break;
	}
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), wTextColor);
	return os;
}
std::string myns::GetClipboardText() {
	if (!OpenClipboard(nullptr)) {
		return "";
	}
	HANDLE hData = GetClipboardData(CF_TEXT);
	if (hData == nullptr) {
		CloseClipboard();
		return "";
	}
	char* pszText = static_cast<char*>(GlobalLock(hData));
	if (pszText == nullptr) {
		return "";
	}
	GlobalUnlock(hData);
	CloseClipboard();
	return std::string(pszText);
}
bool myns::SetStandardInput() {
	std::string clipText = myns::GetClipboardText();
	if (clipText.size() > 0) {
		static std::istringstream iss(clipText);
		std::cin.rdbuf(iss.rdbuf());
	}else myns::SetStandardInput(myns::path);
	return true;
}
bool myns::SetStandardInput(std::string strPath) {
	//おそらくリダイレクト先のifstreamオブジェクトはずっと保持する必要がある
	static std::ifstream ifs(strPath);
	if (!ifs) {
		//""内に日本語を使うとclangが警告を出す
		std::cerr << "Can't open file:" << strPath << std::endl;
		return false;
	}
	std::cin.rdbuf(ifs.rdbuf());
	return true;
}
bool myns::SetStandardOutput() {
	return myns::SetStandardOutput(myns::path);
}
bool myns::SetStandardOutput(std::string strPath) {
	static std::ofstream ofs(strPath);
	if (!ofs) {
		std::cerr << "Can't open file:" << strPath << std::endl;
		return false;
	}
	std::cout.rdbuf(ofs.rdbuf());
	return true;
}
//std::cout<<endlのendlは関数と考え、プロトタイプは
//std::ostream& _cdecl endl(std::ostream&);
//とし、このポインタを引数に取るオーバーロードを実装して、endlを使用可能にする。
myns::tagMyCout& myns::operator<<(myns::tagMyCout& myOs, std::ostream& (*)(std::ostream&)) noexcept {
	std::cout << std::endl;
	return myOs;
}
myns::tagMyCerr& myns::operator<<(myns::tagMyCerr& myOs, std::ostream& (*)(std::ostream&)) noexcept {
	std::cerr << std::endl;
	return myOs;
}
template<class T> constexpr myns::tagMyCout& myns::operator<<(myns::tagMyCout& myOs, const T& thing) noexcept {
	std::cout << thing;
	return myOs;
}
template<class T> constexpr myns::tagMyCerr& myns::operator<<(myns::tagMyCerr& myOs, const T& thing) noexcept {
	std::cerr << thing;
	return myOs;
}

#else//提出

bool myns::SetStandardInput() { return true; }
//提出するときは関数呼び出し規約(_cdecl)を指定するとエラー(手元のgccではコンパイルできる)
myns::tagMyCout& myns::operator<<(myns::tagMyCout& myOs, std::ostream& (*)(std::ostream&)) noexcept { return myOs; }
myns::tagMyCerr& myns::operator<<(myns::tagMyCerr& myOs, std::ostream& (*)(std::ostream&)) noexcept { return myOs; }
template<class T> constexpr myns::tagMyCout& myns::operator<<(myns::tagMyCout& myOs, const T&) noexcept { return myOs; }
template<class T> constexpr myns::tagMyCerr& myns::operator<<(myns::tagMyCerr& myOs, const T&) noexcept { return myOs; }

std::ostream& myns::operator<<(std::ostream& os, myns::text_color) noexcept {
	return os;
}


#endif

//左に代入
template <class T>constexpr bool myns::chmax(T& a, const T& b)
{
	if (a < b)
	{
		a = b;
		return true;
	}
	return false;
}
template <class T>constexpr bool myns::chmin(T& a, const T& b)
{
	if (b < a)
	{
		a = b;
		return true;
	}
	return false;
}

// std::vectorの中に要素が含まれているかを調べる
template <class V, class T> constexpr bool myns::contains(const V& v, const T& a)noexcept
{
	for (const auto& youso : v)
	{
		if (youso == a)
			return true;
	}
	return false;
}

//変数名だけでソート(std::vector)
template <class T>constexpr void myns::sort(std::vector<T>& v)
{
	sort(v.begin(), v.end());
}
template <class T>constexpr void myns::gyakusort(std::vector<T>& v)
{
	sort(v.begin(), v.end(), std::greater<>());
}

//string::starts_withは使えない。(AtCoder)
//https://marycore.jp/prog/cpp/starts-with-prefix-search/
//https://marycore.jp/prog/cpp/ends-with-has-suffix-search/
bool myns::startsWith(const std::string& a, const std::string& b)noexcept {
	return a.size() >= b.size() && equal(b.begin(), b.end(), a.begin());
}
bool myns::endsWith(const std::string& a, const std::string& b)noexcept {
	return a.size() >= b.size() && a.find(b, a.size() - b.size());
}
std::vector<std::string> myns::split(const std::string& str, const std::string& separator, bool deleteBlank = true)noexcept {
	std::vector<std::string> ans;
	std::string tstr = str + separator;
	auto l = tstr.length(), sl = separator.length();
	size_t pos = 0, prev = 0;
	for (; pos < l && (pos = tstr.find(separator, pos)) != std::string::npos; prev = (pos += sl)) {
		ans.push_back(tstr.substr(prev, pos - prev));
		//空文字列は削除(分割する文字列が連続するとき)
		if (deleteBlank && (*(ans.end() - 1)).length() == 0) ans.pop_back();
	}
	return ans;
}
std::vector<std::wstring> myns::split(const std::wstring& str, const std::wstring& separator, bool deleteBlank = true)noexcept {
	std::vector<std::wstring> ans;
	std::wstring tstr = str + separator;
	auto l = tstr.length(), sl = separator.length();
	size_t pos = 0, prev = 0;
	for (; pos < l && (pos = tstr.find(separator, pos)) != std::string::npos; prev = (pos += sl)) {
		ans.push_back(tstr.substr(prev, pos - prev));
		//空文字列は削除(分割する文字列が連続するとき)
		if (deleteBlank && (*(ans.end() - 1)).length() == 0) ans.pop_back();
	}
	return ans;
}

//https://kamino.hatenablog.com/entry/cpp-permutation-combination
//https://qiita.com/mdstoy/items/39104b686540c5f1dc6c
template <typename T> constexpr bool myns::next_combination(const T first, const T last, int k) noexcept {
	const T subset = first + k;
	// empty container | k = 0 | k == n 
	if (first == last || first == subset || last == subset) {
		return false;
	}
	T src = subset;
	while (first != src) {
		src--;
		if (*src < *(last - 1)) {
			T dest = subset;
			while (*src >= *dest) {
				dest++;
			}
			iter_swap(src, dest);
			rotate(src + 1, dest + 1, last);
			rotate(subset, subset + (last - dest) - 1, last);
			return true;
		}
	}
	// restore
	rotate(first, subset, last);
	return false;
}

constexpr myns::ll myns::nCk_lowlevel(myns::ll n, myns::ll k) noexcept {
	myns::ll x = 1; // n!の初期値
	myns::ll y = 1; // (n-k)!の初期値
	myns::ll z = 1; // k!の初期値

	rep(i, 0, n) x *= n - i; // n!を計算
	rep(i, 0, n - k) y *= n - k - i; // (n-k)!を計算
	rep(i, 0, k) z *= k - i; // k!を計算

	return (x / (y * z)); // 定義通りに計算
}
// N個の要素に対する最大公約数
template<typename T> constexpr T myns::gcd(std::vector<T> const& a)noexcept {
	T ans = a[0];
	rep(i, 1, a.size()) {
		ans = std::gcd(ans, a[i]);
	}
	return ans;
}

template<class T, class U, class V> constexpr void myns::print(const T& v, const U& f, const V& flast) noexcept {
	for (const auto& a : v) f(a);
	flast(v);
}

template<class T> constexpr std::ostream& myns::operator<<(std::ostream& os, const std::vector<T>& v) noexcept {
	if (myns::cout_vector_tatehyoji) {
		for (auto& i : v) {
			os << i << '\n';
		}
	}
	else {
		for (auto& i : v) {
			os << i << ' ';
		}
	}
	return os;
}
template<class T> constexpr std::ostream& myns::operator<<(std::ostream& os, const std::initializer_list<T>& v) noexcept {
	if (myns::cout_vector_tatehyoji) {
		for (auto& i : v) {
			os << i << '\n';
		}
	}
	else {
		for (auto& i : v) {
			os << i << ' ';
		}
	}
	return os;
}
template<class T> constexpr std::ostream& myns::operator<<(std::ostream& os, const std::deque<T>& v) noexcept {
	if (myns::cout_vector_tatehyoji) {
		for (auto& i : v) {
			os << i << '\n';
		}
	}
	else {
		for (auto& i : v) {
			os << i << ' ';
		}
	}
	return os;
}
template<class T, class U> constexpr std::ostream& myns::operator<<(std::ostream& os, const std::map<T, U>& v) noexcept {
	if (myns::cout_vector_tatehyoji) {
		for (auto& i : v) {
			os << i << '\n';
		}
	}
	else {
		for (auto& i : v) {
			os << i << ' ';
		}
	}
	return os;
}

//ベクトル要素の縦表示、横表示の変更
constexpr std::ostream& myns::operator<<(std::ostream& os, const tagTatehyoji&)noexcept {
	cout_vector_tatehyoji = true;
	return os;
}
constexpr std::ostream& myns::operator<<(std::ostream& os, const tagYokohyoji&)noexcept {
	cout_vector_tatehyoji = false;
	return os;
}
template<class T, class U> constexpr std::ostream& myns::operator<<(std::ostream& os, const std::pair<T, U>& p) noexcept {
	os << p.first << ' ' << p.second;
	return os;
}
template<class T, class U> constexpr std::istream& myns::operator>>(std::istream& is, std::pair<T, U>& p) noexcept {
	is >> p.first >> p.second;
	return is;
}
template<class T> constexpr std::istream& myns::operator>>(std::istream& is, std::vector<T>& v) noexcept {
	for (auto& i : v) {
		is >> i;
	}
	return is;
}

//引数のvoidを省略するとプロトタイプ宣言にならない(C)
void solving(void);

using namespace std;
using namespace myns;

int main() {
	solving();
}

#endif

void solving() {
	SetStandardInput();
	//SetConsoleTopMost();
}
