/**
 * Author: ???
 * Date: ???
 * License: ???
 * Source: ???
 * Description: Template to easily create multi-dimensional vectors
 * Usage: Vec<NUM_DIMENSIONS, TYPE> VARIABLE_NAME(DIM_1, DIM_2, ...., DEFAULT_VALUE)
 */
#pragma once

template<int D, typename T>
struct Vec : public vector<Vec<D - 1, T>> {
	static_assert(D >= 1, "Vector dimension must be greater than zero!");
	template<typename... Args>
		Vec(int n = 0, Args... args) : vector<Vec<D - 1, T>>(n, Vec<D - 1, T>(args...)) {
		}
};
template<typename T>
struct Vec<1, T> : public vector<T> {
	Vec(int n = 0, const T& val = T()) : vector<T>(n, val) {
	}
};
