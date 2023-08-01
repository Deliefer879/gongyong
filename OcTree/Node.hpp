#pragma once

#include "Object.hpp"
#include <vector>

template <typename T = Collider>
class Node
{
private:
	int depth;
	T area;
	Node<T>* parent;
	std::vector<Node<T>*> children;
	std::vector<Object<T>*> staticObjects;
	std::vector<Object<T>*> dynamicObjects;
public:
	// constructor
	Node(const T& area, Node<T>* parent)
	{
		static_assert(std::is_base_of_v<Collider, T>, "T must be derived from Collider");
		SetParent(parent);
		this->area = area;
	}
	virtual ~Node() 
	{
		for (auto& child : children)
			delete child;
	};

	// get, set
	int GetDepth() const { return depth; }
	Node<T>* GetParent() const { return parent; }
	T& GetNodeArea() { return area; }
	std::vector<Node<T>*>& GetChildren() { return children; }
	std::vector<Object<T>*>& GetDynamicObjects() { return dynamicObjects; }

	void SetParent(Node<T>* parent)
	{
		if (parent != nullptr)
		{
			this->parent = parent;
			depth = parent->depth + 1;
		}
	};

	void AddStaticObject(Object<T>* object)
	{
		staticObjects.push_back(object);
	}

	void AddDynamicObject(Object<T>* object)
	{
		dynamicObjects.push_back(object);
	}

	void ClearDynamicObject()
	{
		dynamicObjects.clear();
	}
};

