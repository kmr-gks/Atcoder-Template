// constexpr ll mod = 1e9 + 7;
constexpr ll mod = 9'9824'4353;

class modll
{
private:
	ll value;
	static constexpr int KAIJO_MAX = 100'0000;
	static inline ll kaijo[KAIJO_MAX] = {1, 1};

public:
	// C++17
	constexpr modll(ll value = 0) noexcept : value(value < 0 ? value % mod + mod : value % mod) {}
	/*
	//C++20
	constexpr modll(ll value = 0) {
		value %= mod;
		if (value < 0) value += mod;
		this->value = value;
	}
	*/

	constexpr ll toll() const noexcept { return this->value; }
	friend constexpr modll modpow(const modll &a, const modll &b) noexcept;

#ifdef ONLINE_JUDGE
#define MYLIB_CONSTEXPR
#else
#define MYLIB_CONSTEXPR constexpr
#endif
	MYLIB_CONSTEXPR friend modll kaijo(const modll &n) noexcept;
	MYLIB_CONSTEXPR friend modll nCk(const modll &a, const modll &b) noexcept;
	MYLIB_CONSTEXPR friend modll nPk(const modll &a, const modll &b) noexcept;
	MYLIB_CONSTEXPR friend modll nck(const modll &a, const modll &b) noexcept;
	MYLIB_CONSTEXPR friend modll npk(const modll &a, const modll &b) noexcept;
	MYLIB_CONSTEXPR friend modll gyakugen(const modll &n) noexcept;

	constexpr modll modpow(ll t) const noexcept
	{
		if (!t)
			return 1;
		modll a = modpow(t >> 1);
		a *= a;
		if (t & 1)
			a *= *this;
		return a;
	}
	constexpr modll inverse() const noexcept
	{
		return modpow(mod - 2);
	}
	constexpr modll operator-() const noexcept
	{
		return mod - value;
	}

	friend constexpr modll &operator+=(modll &a, const modll &b) noexcept
	{
		a.value += b.value;
		a.value %= mod;
		if (a.value < 0)
			a.value += mod;
		return a;
	}
	friend constexpr modll &operator-=(modll &a, const modll &b) noexcept
	{
		a.value -= b.value;
		a.value %= mod;
		if (a.value < 0)
			a.value += mod;
		return a;
	}
	friend constexpr modll &operator*=(modll &a, const modll &b) noexcept
	{
		a.value *= b.value;
		a.value %= mod;
		if (a.value < 0)
			a.value += mod;
		return a;
	}
	friend constexpr modll &operator/=(modll &a, const modll &b) noexcept
	{
		a.value *= b.inverse().value;
		if (a.value < 0)
			a.value += mod;
		return a;
	}
	friend constexpr modll &operator%=(modll &a, const modll &b) noexcept
	{
		a.value %= b.value;
		return a;
	}

	friend constexpr ll &operator+=(ll &a, const modll &b) noexcept
	{
		a += b.value;
		a %= mod;
		if (a < 0)
			a += mod;
		return a;
	}
	friend constexpr ll &operator-=(ll &a, const modll &b) noexcept
	{
		a -= b.value;
		a %= mod;
		if (a < 0)
			a += mod;
		return a;
	}
	friend constexpr ll &operator*=(ll &a, const modll &b) noexcept
	{
		a *= b.value;
		a %= mod;
		if (a < 0)
			a += mod;
		return a;
	}
	friend constexpr ll &operator/=(ll &a, const modll &b) noexcept
	{
		a *= b.inverse().value;
		a %= mod;
		if (a < 0)
			a += mod;
		return a;
	}
	friend constexpr ll &operator%=(ll &a, const modll &b) noexcept
	{
		a %= b.value;
		return a;
	}

	friend constexpr modll operator+(const modll &a, const modll &b) noexcept
	{
		return modll(a.value + b.value);
	}
	friend constexpr modll operator-(const modll &a, const modll &b) noexcept
	{
		return modll(a.value - b.value);
	}
	friend constexpr modll operator*(const modll &a, const modll &b) noexcept
	{
		return modll(a.value * b.value);
	}
	friend constexpr modll operator/(const modll &a, const modll &b) noexcept
	{
		return modll(a.value * b.inverse());
	}
	friend constexpr modll operator%(const modll &a, const modll &b) noexcept
	{
		return modll(a.value % b.value);
	}

	constexpr modll &operator++() noexcept
	{
		value++;
		if (value == mod)
			value = 0;
		return *this;
	}
	constexpr modll &operator--() noexcept
	{
		if (value == 0)
			value = mod - 1;
		if (value == 1)
			value = 0;
		else
			value--;
		return *this;
	}
	constexpr modll &operator++(int) noexcept
	{
		modll result = *this;
		value++;
		if (value == mod)
			value = 0;
		return result;
	}
	constexpr modll &operator--(int) noexcept
	{
		modll result = *this;
		if (value == 0)
			value += mod;
		value--;
		return result;
	}

	friend constexpr bool operator==(const modll &a, const modll &b) noexcept
	{
		return a.value == b.value;
	}
	friend constexpr bool operator!=(const modll &a, const modll &b) noexcept
	{
		return a.value != b.value;
	}
	friend constexpr bool operator<(const modll &a, const modll &b)
	{
		return a.value < b.value;
	}
	friend constexpr bool operator<=(const modll &a, const modll &b) noexcept
	{
		return a.value <= b.value;
	}
	friend constexpr bool operator>(const modll &a, const modll &b)
	{
		return a.value > b.value;
	}
	friend constexpr bool operator>=(const modll &a, const modll &b) noexcept
	{
		return a.value >= b.value;
	}

	friend ostream &operator<<(ostream &os, const modll &n) noexcept
	{
		os << n.value;
		return os;
	}
	friend istream &operator>>(istream &is, modll &n) noexcept
	{
		is >> n.value;
		return is;
	}
};

constexpr modll modpow(const modll &a, const modll &b) noexcept
{
	ll res = 1, k = b.value, y = a.value;
	while (k)
	{
		//繰り返し二乗法とフェルマーの小定理
		if (k & 1)
			res = (res * y) % mod;
		y = (y * y) % mod;
		k /= 2;
	}
	return res;
}

MYLIB_CONSTEXPR modll kaijo(const modll &n) noexcept
{
	if (modll::kaijo[2] == 0)
	{
		//初めて2以上の階乗を計算するとき
		for (ll i = 2; i < modll::KAIJO_MAX; ++i)
		{
			modll::kaijo[i] = (modll::kaijo[i - 1] * i) % mod;
		}
	}
	if (n.value < modll::KAIJO_MAX)
		return modll::kaijo[n.value];
	else
	{
		modll ans(modll::kaijo[modll::KAIJO_MAX - 1]);
		for (ll i = modll::KAIJO_MAX; i <= n.value; i++)
		{
			ans = (ans * i) % mod;
		}
		return ans;
	}
}
MYLIB_CONSTEXPR modll gyakugen(const modll &n) noexcept { return modpow(n, mod - 2); }
MYLIB_CONSTEXPR modll nCk(const modll &n, const modll &k) noexcept { return kaijo(n) * gyakugen(kaijo(n - k)) * gyakugen(kaijo(k)); }
MYLIB_CONSTEXPR modll nPk(const modll &n, const modll &k) noexcept { return kaijo(n) * gyakugen(kaijo(n - k)); }
MYLIB_CONSTEXPR modll nck(const modll &n, const modll &k) noexcept { return nCk(n, k); }
MYLIB_CONSTEXPR modll npk(const modll &n, const modll &k) noexcept { return nPk(n, k); }