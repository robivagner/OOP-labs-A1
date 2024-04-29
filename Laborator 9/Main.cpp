#include <iostream>
template <typename K, typename V>
class Map {
	struct Element {
		K key;
		V value;
		int index;
	} *vector;
	int index;
	int size;
	void Resize()
	{
		if (size != 0)
		{
			Element* v = new Element[size * 2];
			memcpy(v, vector, sizeof(Element) * size);
			vector = v;
			size = size * 2;
			return;
		}
		vector = new Element[1];
		size = 1;
		index = 0;
	}
public:
	Map()
	{
		vector = new Element[1];
		size = 1;
		index = 0;
	}
	~Map() 
	{
		Clear();
	}
	Element* begin() const { return &vector[0]; }
	Element* end() const { return &vector[index]; }
	V& operator [] (K key)
	{
		for (int i = 0; i < index; i++)
		{
			if (key == vector[i].key)
				return vector[i].value;
		}
		vector[index].index = index;
		vector[index].key = key;
		index++;
		if (index == size)
			Resize();
		return vector[index - 1].value;
	}
	void Set(K k, V v)
	{
		for (int i = 0; i < index; i++)
		{
			if (vector[i].key == k)
			{
				vector[i].value = v;
				size++;
				return;
			}
		}
		return;
	}
	bool Get(const K& k, V& v)
	{
		for (int i = 0; i < index; i++)
		{
			if (vector[i].key == k)
			{
				v = vector[i].value;
				return true;
			}
		}
		return false;
	}
	int Index() const
	{
		return index;
	}
	void Clear()
	{
		size = 0;
		index = 0;
		delete[] vector;
		vector = nullptr;
	}
	bool Delete(const K& k)
	{
		for (int i = 0; i < index; i++)
		{
			if (vector[i].key == k)
			{
				for (int j = i; j < index - 1; j++)
					vector[j] = vector[j + 1];
				index--;
				for (int m = 0; m < index; m++)
					vector[m].index = m;
				return true;
			}
		}
		return false;
	}

	bool Includes(const Map<K, V>& map)
	{
		if (index < map.index) return false;
		bool exists;
		for (int i = 0; i < map.index; i++)
		{
			exists = false;
			for (int j = 0; j < index; j++)
				if (vector[j].key == map.vector[i].key)
				{
					exists = true;
					break;
				}
			if (exists == false)
				return false;
		}
		return true;
	}
};

int main()
{
	Map<int, const char*> m;
	m[10] = "C++";
	m[20] = "test";
	m[30] = "Poo";
	for (auto [key, value, index] : m)
	{
		printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
	}
	m[20] = "result";
	for (auto [key, value, index] : m)
	{
		printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
	}
	return 0;
}