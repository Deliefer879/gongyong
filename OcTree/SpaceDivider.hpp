#pragma once

#include "Node.hpp"
#include "CollisionManager.hpp"
#include <set>
#include <queue>

enum class DivideDimension
{
	DIMENSION2 = 4,
	DIMENSION3 = 8
};

template <typename T = Collider>
class SpaceDivider
{
private:
	Node<T>* root;
	std::set<Node<T>*> dynamicObjectNodeList;
	std::queue<Node<T>*> queue;
	int splitNum;

private:
	void ClearDynamicObject()
	{
		for (auto& dNode : dynamicObjectNodeList)
			dNode.ClearDynamicObject();
	};

	void BuildTree(Node<T>* parent)
	{
		if (parent->GetDepth() > 1)
			return;

		// set child min pos
		Vector3 childSize = parent->GetNodeArea().Size() / 2;
		std::vector<Vector3> splitPos; splitPos.resize(8);

		splitPos[0] = parent->GetNodeArea().Min();
		splitPos[1] = parent->GetNodeArea().Min() + Vector3(childSize.X(), 0, 0);
		splitPos[2] = parent->GetNodeArea().Center() - Vector3(0,0,childSize.Z());
		splitPos[3] = parent->GetNodeArea().Min() + Vector3(0, childSize.Y(), 0);
		splitPos[4] = splitPos[0] + Vector3(0, 0, childSize.Z());
		splitPos[5] = splitPos[1] + Vector3(0, 0, childSize.Z());
		splitPos[6] = splitPos[2] + Vector3(0, 0, childSize.Z());
		splitPos[7] = splitPos[3] + Vector3(0, 0, childSize.Z());

		for (int i = 0; i < splitNum; i++)
			parent->GetChildren().push_back(new Node<T>( {splitPos[i],  childSize}, parent));

		for (auto& child : parent->GetChildren())
			BuildTree(child);
	};

	void LevelOrder(Node<T>* node)
	{
		if (node == nullptr)
			return;

		// print
		std::cout << "[" << node->GetDepth() << "] ";
		node->GetNodeArea().PrintInfo();
		for (auto& object : node->GetDynamicObjects())
		{	
			std::cout << "    ";
			object->PrintInfo();
		}
		// print

		for (auto& child : node->GetChildren())
		{
			if (child != nullptr)
				queue.push(child);
		}

		if (!queue.empty())
		{
			Node<T>* nextNode = queue.front();
			queue.pop();
			LevelOrder(nextNode);
		}
	};	

	Node<T>* FindNode(Object<T>* object)
	{
		Node<T>* target = root;

		while (target != nullptr)
		{
			for (auto& child : target->GetChildren())
			{
				if (child != nullptr &&  CollisionManager::CubeInCube(child->GetNodeArea(), object->GetArea()))
				{
					object->GetArea().Collision(&(child->GetNodeArea()));

					queue.push(child);
					break;
				}
			}

			if (queue.empty())
				break;

			target = queue.front();
			queue.pop();
		}

		return target;
	};
public:
	Node<T>* GetRoot() const { return root; }

	void Init(DivideDimension dimension, const T& rootArea)
	{
		splitNum = (int)dimension;
		root = new Node<T>(rootArea, nullptr); 
		BuildTree(root);
	};

	virtual void Frame()
	{
		for (auto& node : dynamicObjectNodeList)
			node->ClearDynamicObject();

		dynamicObjectNodeList.clear();
	};

	virtual void Render()
	{
		LevelOrder(root);
	};

	virtual void Release()
	{
		delete root;
	};

	void AddStaticObject(Object<T>* object)
	{
		Node<T>* target = FindNode(object);

		if(target != nullptr)
			target->AddStaticObject(object);
	};

	void AddDynamicObject(Object<T>* object)
	{
		Node<T>* target = FindNode(object);

		if (target != nullptr)
		{
			target->AddDynamicObject(object);
			dynamicObjectNodeList.insert(target);
		};
	};
};
