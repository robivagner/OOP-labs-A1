#include <queue>
template <class T>
class Node
{
	T key;
	Node<T>** children;
	Node<T>* parent;
	int childcount, capacity;
public:
	Node(T value, Node<T>* parent = nullptr) : key(value), parent(parent), children(nullptr), childcount(0), capacity(1) {}
	Node<T>** getChildren()
	{
		return this->children;
	}
	Node<T>* getParent()
	{
		return this->parent;
	}
	int getChildcount()
	{
		return this->childcount;
	}
	T getKey()
	{
		return this->key;
	}
	void add_node(T value)
	{
		Node<T>* newNode = new Node<T>(value, this->parent);
		newNode->parent = this;
		if (this->childcount == this->capacity)
		{
			this->capacity = this->capacity * 2;
			Node<T>** newChildren = new Node<T>*[this->capacity];

			for (int i = 0; i < this->childcount; i++)
				newChildren[i] = this->children[i];

			newChildren[childcount] = newNode;
			newChildren[childcount]->parent = this;
			delete[] this->children;
			this->children = newChildren;
		}
		else if (this->capacity == 1)
		{
			this->capacity = this->capacity * 2;
			this->children = new Node<T>*[this->capacity];
			this->children[this->childcount] = newNode;
		}
		else if(this->childcount < this->capacity)
		{
			this->children[this->childcount] = newNode;
		}
		this->childcount++;
	}
	Node<T>* get_node(Node<T>* parent, int index)
	{
		if (index < parent->childcount)
			return parent->children[index];
		else return nullptr;
	}
	void delete_node(Node<T>* node)
	{
		int i = 0;
		if (node->parent != nullptr)
		{
			for (i = 0; i < node->parent->childcount; i++)
				if (node->parent->children[i] == node)
					break;
			for (int j = i; j < node->parent->childcount - 1; j++)
				node->parent->children[j] = node->parent->children[j + 1];
			node->parent->childcount--;
		}
		for (int i = 0; i < node->childcount; i++)
		{
			node->delete_node(children[i]);
			delete node->children[i];
		}
		delete[] node->children;
		node->children = nullptr;
		node->childcount = 0;
	}
	Node<T>* find(T value)
	{
		if (this->key == value)
			return this;
		for (int i = 0; i < this->childcount; i++)
		{
			Node<T>* found = this->children[i]->find(value);
			if (found != nullptr)
				return found;
		}
		return nullptr;
	}
	void insert(int index, T value)
	{
		if (index < 0 || index > this->childcount)
			return;

		Node<T>* newNode = new Node<T>(value, this->parent);
		newNode->parent = this;
		if (this->childcount == this->capacity)
		{
			Node<T>** newchildren = new Node<T>*[this->capacity * 2];
			this->capacity = this->capacity * 2;
			this->childcount++;

			for (int i = 0; i < index; i++)
				newchildren[i] = this->children[i];
			newchildren[index] = newNode;
			newchildren[index]->parent = this;

			for (int i = index + 1; i < this->childcount; i++)
				newchildren[i] = this->children[i - 1];
			delete[] this->children;
			this->children = newchildren;
		}
		else if (this->capacity == 1)
		{
			this->capacity = this->capacity * 2;
			this->children = new Node<T>*[this->capacity];
			this->children[this->childcount] = newNode;
			this->childcount++;
		}
		else if (this->childcount < this->capacity)
		{
			this->children[this->childcount] = newNode;
			this->childcount++;
		}
	}
	void sort(bool (*compare)(T, T) = nullptr)
	{
		for (int i = 0; i < this->childcount - 1; i++)
			for (int j = i + 1; j < this->childcount; j++)
				if ((compare && compare(this->children[i]->key, this->children[j]->key)) || (!compare && this->children[i]->key > this->children[j]->key))
					std::swap(this->children[i], this->children[j]);
	}
	int count()
	{
		int count = this->childcount;
		if (this->parent == nullptr)
			count++;
		for (int i = 0; i < this->childcount; i++)
			count += this->children[i]->count();
		return count;
	}
	void print()
	{
		for (int i = 0; i < this->childcount; i++)
			std::cout << this->children[i]->key << ' ';
	}
	void BFS()
	{
		if (this == nullptr)
			return;

		std::queue<Node<T>*> q;
		q.push(this);
		q.push(nullptr); // null pointer indicates the end of a level

		while (!q.empty())
		{
			Node<T>* current = q.front();
			q.pop();

			if (current == nullptr)
			{
				std::cout << '\n';
				if (!q.empty())
					q.push(nullptr); // add marker for next level
			}
			else
			{
				std::cout << current->getKey() << ' ';
				for (int i = 0; i < current->getChildcount(); i++)
					q.push(current->getChildren()[i]);
			}
		}
	}
};