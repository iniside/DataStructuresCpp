// DataStructures.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include "SingleLinkedList.h"

int _tmain(int argc, _TCHAR* argv[])
{
	SingleLinkedList<int> IntList;
	IntList.AddNewItemToStart(1);
	IntList.AddNewItemToStart(3);
	IntList.AddNewItemToEnd(4);
	IntList.AddNewItemToEnd(7);


	return 0;
}

