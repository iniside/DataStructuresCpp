#pragma once
/*
	Implementation of templated single linked list.
*/

/*
	Node class used in list.
*/
template<class ItemType>
class ListNode
{
public:
	ItemType Value;

	ListNode* NextNode;
public:
	ListNode()
	{}
	ListNode(ItemType ValueIn)
		: Value(ValueIn),
		NextNode(nullptr)
	{}
	ListNode(ItemType ValueIn, ListNode* NextNodeIn)
		: Value(ValueIn),
		NextNode(NextNodeIn)
	{}
	~ListNode()
	{}
};
/*
	Container implementation.
*/
template<class ItemType>
class SingleLinkedList
{
protected:
	/*
		First element in list.
	*/
	ListNode<ItemType>* ListBegin;
	/*
		Last element in list.
	*/
	ListNode<ItemType>* ListEnd;
public:

	bool IsEmpty()
	{
		return ListBegin == nullptr;
	}

	/*
		If list is empty add new element to begining.
		If there is something in list, it will add new item sequentially.
	*/
	void AddNewItemToStart(ItemType ItemIn)
	{
		if (IsEmpty())
		{
			ListNode<ItemType>* newNode = new ListNode<ItemType>(ItemIn);
			ListBegin = newNode;
			
			if (ListEnd == nullptr)
			{
				ListEnd = ListBegin;
			}
		}
		else
		{
			ListNode<ItemType>* temp = ListBegin;// ListBegin->NextNode;
			ListNode<ItemType>* newNode = new ListNode<ItemType>(ItemIn);
			
			//this looks bad
			//but! It's simplest way to do it
			while (true)
			{
				if (temp->NextNode == nullptr)
				{
					temp->NextNode = newNode;
					ListEnd = newNode;
					return;
				}
				temp = temp->NextNode;
			}
		}
	}

	void AddNewItemToEnd(ItemType ItemIn)
	{
		if (ListEnd != nullptr)
		{
			ListNode<ItemType>* newNode = new ListNode<ItemType>(ItemIn);
			ListNode<ItemType>* temp = ListEnd;
			//add new element as Next item fot current last node.
			//ListEnd->NextNode = newNode;
			temp->NextNode = newNode;
			//then copy NextItem to end of the list, so it will new Last.
			ListEnd = newNode;
		}
		else
		{
			ListBegin = ListEnd = new ListNode<ItemType>(ItemIn);
		}
	}

	ItemType DeleteFromBegin()
	{
		ItemType Value = ListBegin->Value;
		ListNode<ItemType>* temp = ListBegin;

		if (ListBegin == ListEnd)
		{
			ListBegin = ListEnd = nullptr;
		}
		else
		{
			ListBegin = ListBegin->NextNode;
		}
		delete = temp;
		return Value;
	}

	ItemType DeleteFromEnd()
	{
		ItemType Value = ListEnd->Value;

		if (ListBegin == ListEnd)
		{
			delete ListBegin;
			ListBegin = ListEnd = nullptr;
		}
		else
		{
			ListNode<ItemType>* temp;
			/*
				1. Assign value of begining of the list.
				2. Compare NextNode with end
				3. If false, assign next node from temp.
			*/
			for (temp = ListBegin; temp->NextNode != ListEnd; temp = temp->NextNode);

			/*
				Find predecesor of ListEnd.
				If the NextNode is different than ListEnd
				It means it is not predecesor.
			*/
			temp = ListBegin;
			while (temp->NextNode != ListEnd)
			{
				temp = temp->NextNode;
			}

			delete ListEnd;
			ListEnd = temp;
			temp->NextNode = nullptr;
		}
		return Value;
	}

	ItemType DeleteNode(ItemType ItemIn)
	{
		if (ListBegin != nullptr)
		{
			if (ListBegin == ListEnd && ItemIn == ListBegin->Value)
			{
				ItemType value = ListBegin->Value;
				delete ListBegin;
				ListBegin = ListEnd == nullptr;
				return value;
			}
			else if (ItemIn == ListBegin->Value)
			{
				ListNode<ItemType>* temp = ListBegin->NextNode;
				ItemType value = ListBegin->Value;
				ListBegin = ListBegin->NextNode;
				delete temp;
				return value;
			}
			else
			{
				ListNode<ItemType>* temp = ListBegin->NextNode;
				ListNode<ItemType>* pred = ListBegin;

				while (temp != nullptr &&
					!(temp->Value == ItemIn))
				{
					temp = temp->NextNode;
					pre = pred->NextNode;
					if (temp != nullptr)
					{
						pred->NextNode = temp->NextNode;
						if (temp == ListEnd)
						{
							ListEnd = pred;
						}
						delete temp;
					}
				}

				/*for (pred = ListBegin, temp = ListBegin->NextNode;
					temp != nullptr && !(temp->Value == ItemIn);
					pred = pred->NextNode, temp = temp->NextNode);
				{
					if (temp != nullptr)
					{
						pred->NextNode = temp->NextNode;
						if (temp == ListEnd)
						{
							ListEnd = pred;
						}
						delete temp;
					}
				}*/
			}
		}
	}

	SingleLinkedList()
		: ListBegin(nullptr),
		ListEnd(nullptr)
	{}
	~SingleLinkedList()
	{	
		//as long as there is Item
		for (ListNode<ItemType>* Item; !IsEmpty();)
		{
			//get next Node from begin of the list
			Item = ListBegin->NextNode;

			delete ListBegin;
			//and assign it to Begin
			ListBegin = Item;
		}//now if Item is != nullptr, we will repeate this.
	}
};

