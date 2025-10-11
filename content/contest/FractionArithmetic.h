/**
 * Author: Brandon Han
 * Date: 2025-10-05
 * License: ???
 * Source: ???
 * Description: Operators for fraction arithmetic. Will likely
 * break down after a few operations due to overflow. 
 */
#pragma once

struct Frac {
	ll p, q;
	Frac(ll numer=0, ll denom=1) : p(numer), q(denom) {
		assert(q != 0);
		if(q < 0) { p = -p; q = -q; }
		ll fac = gcd(abs(p), q);
		p /= fac; q /= fac;
	}
	Frac operator+(Frac b) {
		ll denom = lcm(q, b.q);
		return Frac(
			p * (denom / q) + b.p * (denom / b.q), 
			denom
		);
	}
	Frac operator-(Frac b) { return *this + b.negate(); }
	Frac operator*(Frac b) {
		ll fac_pq = gcd(p, b.q);
		ll fac_qp = gcd(q, b.p);
		return Frac(
			(p / fac_pq) * (b.p / fac_qp), 
			(q / fac_qp) * (b.q / fac_pq)
		);
	}
	Frac operator/(Frac b) { return *this * b.invert(); }
	Frac negate() { return Frac(-p, q); }
	Frac invert() { return Frac(q, p); }
	friend ostream &operator<<(ostream &st, Mod a) { st << a.p << '/' << a.q; }
};
