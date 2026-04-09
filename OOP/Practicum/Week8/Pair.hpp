#pragma once
#include <utility>
#include <fstream>

template <typename K, typename V>
class Pair
{
private:
	K key;
	V value;
public:
	K getKey() const;
	V getValue() const;

	void setKey(K key);
	void setValue(V value);

	Pair() = default;

	Pair(const K& key, const V& value);
	Pair(K&& key, const V& value);
	Pair(const K& key, V&& value);
	Pair(K&& key, V&& value);

	friend std::ostream& operator<< <K,V>(std::ostream& os, const Pair<K,V>& pair);

	friend std::istream& operator>> <K,V>(std::istream& is, Pair<K,V>& pair);
};

template<typename K, typename V>
inline K Pair<K, V>::getKey() const
{
	return key;
}

template<typename K, typename V>
inline V Pair<K, V>::getValue() const
{
	return value;
}

template<typename K, typename V>
inline void Pair<K, V>::setKey(K key)
{
	this->key = key;
}

template<typename K, typename V>
inline void Pair<K, V>::setValue(V value)
{
	this->value = value;
}

template<typename K, typename V>
inline Pair<K, V>::Pair(const K& key, const V& value) : key(key), value(value)
{
	
}

template<typename K, typename V>
inline Pair<K, V>::Pair(K&& key, const V& value) : key(std::move(key)), value(value)
{
}

template<typename K, typename V>
inline Pair<K, V>::Pair(const K& key, V&& value) : key(key), value(std::move(value))
{
}

template<typename K, typename V>
inline Pair<K, V>::Pair(K&& key, V&& value) : key(std::move(key)), value(std::move(value))
{
}

template<typename K, typename V>
std::ostream& operator<<(std::ostream& os, const Pair<K, V>& pair)
{
	os << pair.key << " " << pair.value;

	return os;
}

template<typename K, typename V>
std::istream& operator>>(std::istream& is, Pair<K, V>& pair)
{
	is >> pair.key >> pair.value;

	return is;
}