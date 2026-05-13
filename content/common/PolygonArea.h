/**
 * Author: Brandon Han
 * Date: 2025-11-22
 * License: ???
 * Source: ???
 * Description: Takes a list of PointT. Assumes the list of
 * points are the vertices of a polygon in counterclockwise
 * order. Returns twice the area of the polygon
 */
#pragma once

#include "PointT.h"

template<class T>
T twicePolygonArea(vector<PointT<T>> &v) {
	T a = v.back().cross(v.front());
	rep(i, 0, sz(v)-1) a += v[i].cross(v[i+1]);
	return a;
}

