#pragma once

#include <iostream>
#include <vector>
#include <map>
#include <set>

namespace lab7
{
	template <typename K, class V>
	std::map<K, V> ConvertVectorsToMap(const std::vector<K>& keys, const std::vector<V>& values)
	{
		std::map<K, V> m;

		const unsigned int MAP_SIZE = keys.size() <= values.size() ? keys.size() : values.size();
		
		for (size_t i = 0; i < MAP_SIZE; ++i)
		{
			m.insert(std::pair<K, V>(keys[i], values[i]));
		}

		return m;
	}

	template <typename K, class V>
	std::vector<K> GetKeys(const std::map<K, V>& m)
	{
		std::vector<K> v;
		v.reserve(m.size());
		typename std::map<K, V>::const_iterator it;
		
		for (it = m.begin(); it != m.end(); ++it)
		{
			v.push_back(it->first);
		}

		return v;
	}

	template <typename K, class V>
	std::vector<V> GetValues(const std::map<K, V>& m)
	{
		std::vector<V> v;
		v.reserve(m.size());
		typename std::map<K, V>::const_iterator it;

		for (it = m.begin(); it != m.end(); ++it)
		{
			v.push_back(it->second);
		}

		return v;
	}

	template <typename T>
	std::vector<T> Reverse(const std::vector<T>& v)
	{
		std::vector<T> rv;
		rv.reserve(v.size());
		typename std::vector<T>::const_reverse_iterator it;
		
		for (it = v.rbegin(); it != v.rend(); ++it)
		{
			rv.push_back(*it);
		}

		return rv;
	}

	template <typename T>
	std::vector<T> operator+(const std::vector<T>& v1, const std::vector<T>& v2)
	{
		std::vector<T> combined;
		combined.reserve(v1.size() + v2.size());

		std::set<T> tmp;

		for (size_t i = 0; i < v1.size(); ++i)
		{
			tmp.insert(v1[i]);
		}

		for (size_t i = 0; i < v2.size(); ++i)
		{
			tmp.insert(v2[i]);
		}

		typename std::set<T>::const_iterator it;

		for (it = tmp.begin(); it != tmp.end(); ++it)
		{
			combined.push_back(*it);
		}

		return combined;
	}

	template <typename K, class V>
	std::map<K, V> operator+(const std::map<K, V>& m1, const std::map<K, V>& m2)
	{
		std::map<K, V> combined;
		
		typename std::map<K, V>::const_iterator it;

		for (it = m1.begin(); it != m1.end(); ++it)
		{
			combined.insert(*it);
		}


		for (it = m2.begin(); it != m2.end(); ++it)
		{
			combined.insert(*it);
		}

		return combined;
	}

	template<typename T>
	std::ostream& operator<<(std::ostream& os, const std::vector<T>& v)
	{
		for (size_t i = 0; i < v.size(); ++i)
		{
			os << v[i];

			if (i < v.size() - 1)
			{
				os << ", ";
			}
		}

		return os;
	}

	template <typename K, class V>
	std::ostream& operator<<(std::ostream& os, const std::map<K, V>& m)
	{
		typename std::map<K, V>::const_iterator it;

		for (it = m.begin(); it != m.end(); ++it)
		{
			os << "{ " << it->first << ", " << it->second << " }" << std::endl;
		}

		return os;
	}
}