/**
 * Author: Brandon Han
 * Date: 2025-11-22
 * License: ???
 * Source: ???
 * Description: Operators for a point in 2D space
 */
#pragma once

template<class T>
struct PointT {
	typedef PointT<T> P;
	T x, y;
	PointT(T xx=0, T yy=0) : x(xx), y(yy) {}
	P rotate(double rad) {
		return P(x * cos(rad) - y * sin(rad), x * sin(rad) + y * cos(rad));
	}
	T cross(P b) { return x * b.y - y * b.x; }
};
typedef PointT<double> Point;
