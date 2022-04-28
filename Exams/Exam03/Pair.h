#ifndef PAIR_H
#define PAIR_H

#include <iostream>
#include <string>
#include <sstream>

namespace ds
{
	template <class K,class V>
	class Pair
	{
		private:
		K key;
		V value;

		public:
		Pair()
		{
			key = K();
			value = V();
		}
	
		Pair(const K& key,const V& value) : key(key), value(value) {}

		Pair(const Pair<K,V>& obj)
		{
			key = obj.key;
			value = obj.value;
		}

		Pair<K,V>& operator=(const Pair<K,V>& rhs)
		{
			if(this != &rhs)
			{
				key = rhs.key;
				value = rhs.value;
			}
			return *this;
		}	

		~Pair() {}

		K& Key() 
		{
			return key;
		}

		const K& Key() const 
		{
			return key;
		}

		V& Value() 
		{
			return value;
		}

		const V& Value() const 
		{
			return value;
		}

		std::string ToString() const
		{
			std::stringstream out;
			out << "(" << key << "," << value << ")";
			return out.str();
		}

		friend std::ostream& operator<<(std::ostream& out,const Pair<K,V>& obj)
		{
			out << obj.ToString();
			return out;
		}
	};
}

#endif
