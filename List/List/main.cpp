// ContainerList v0.3
#include <iostream>
#include <vector>

using namespace std;

struct List
{
	List* Front;
	int Value;
	List* Back;
};

void push_back(List* _Current, const int& _Value);
void pop_back(List* _Current);
void insert(List* _Current, int _Where, const int& _Value);
void erase(List* _Current, const int _Where);
//void Insert(List* head, int idx, const int& _Value);
void OutputA(const List* _Current);
void OutputB(const List* _Current);

List* End = nullptr;

int main(void)
{
	List* NumberList = new List;

	NumberList->Front = nullptr;
	NumberList->Value = 0;
	NumberList->Back = nullptr;

	for (int i = 0; i < 10; ++i)
		push_back(NumberList, i * 10 + 10);

	insert(NumberList, 2, 15);
	OutputA(NumberList);

	erase(NumberList, 2);
	//Insert(NumberList, 3, 15);
	OutputA(NumberList);

	OutputB(End);
	pop_back(NumberList);
	OutputA(NumberList);

	return 0;
}

void push_back(List* _Current, const int& _Value)
{
	if (_Current->Back == nullptr)
	{
		List* Temp = new List;

		Temp->Front = nullptr;
		Temp->Value = _Value;
		Temp->Back = nullptr;

		_Current->Back = Temp;
	}
	else
		push_back(_Current->Back, _Value);
}

void pop_back(List* _Current)
{
	if (_Current->Back == nullptr)
	{
		End = _Current->Front;
		_Current->Front->Back = nullptr;
		delete _Current;
		_Current->Back = nullptr;
	}
	else
		pop_back(_Current->Back);
}

void insert(List* _Current, int _Where, const int& _Value)
{
	if (_Where == 1)
	{
		List* Temp = new List;

		Temp->Front = _Current;
		Temp->Value = _Value;
		Temp->Back = _Current->Back;
	}
	else
		insert(_Current->Back, _Where - 1, _Value);
}

void erase(List* _Current, const int _Where)
{
	if (_Where == 0)
	{
		_Current->Back->Front = _Current->Front;
		_Current->Front->Back = _Current->Back;

		delete _Current;
		_Current = nullptr;
	}
	else
		erase(_Current->Back, _Where - 1);
}

//void Insert(List* head, int idx, const int& _Value)
//{
//	List* ptr = head;
//	List* temp = ptr;
//
//	List* node = new List;
//	node->Value = _Value;
//	node->Back = nullptr;
//
//	for (int i = 0; i < idx; i++)
//	{
//		temp = ptr;
//		ptr = ptr->Back;
//	}
//	temp->Back = node;
//	node->Back = ptr;
//}

void OutputA(const List* _Current)
{
	cout << _Current->Value << endl;
	//cout << &_Current << endl << endl;

	if (_Current->Back != nullptr)
		Output(_Current->Back);
}

void OutputB(const List* _Current)
{
	cout << _Current->Value << endl;
	//cout << &_Current << endl << endl;

	if (_Current->Front != nullptr)
		Output(_Current->Front);
}