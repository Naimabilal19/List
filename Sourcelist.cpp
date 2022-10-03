#include <iostream>
using namespace std;

struct Element
{
	char data;
	Element* next;
};

class list
{
private:
	Element* Head;
	Element* Tail;
	int count;
public:
	list();
	~list(); 
	void Add(char data);
	void Del();
	void DellAll();
	void AddIndex(short index, char x);
	void DelIndex(short x);
	int Search(char x);
	void Print();
	int Get_count();
};

list::list()
{
	Head = Tail = NULL;
	count = NULL;
}
list::~list()
{
	if (Head != NULL)
	{
		Del();
	}
}
void list::Add(char data)
{
	Element* temp = new Element;
	temp->data = data;
	temp->next = NULL;
	if (Head != NULL)
	{
		Tail->next = temp;
		Tail = temp;
	}
	else
	{
		Head = Tail = temp;
	}
}
void list::Del()
{
	Element* temp = Head;
	Head = Head->next;
	delete temp;
}
void list::DellAll()
{
	while (Head != 0)
		Del();
}


//-------------------------------------------------------------
void list::AddIndex(short index, char x)
{
	if (index == 1)
	{
		Element* temp = new Element;
		Element* Temp1 = Head;
		temp->data = x;
		temp->next = Temp1;
		Head = temp;
	}
	else
	{
		Element* temp = new Element;
		temp->data = x;
		Element* Temp1 = Head;
		for (short i = 1; i < index - 1; i++)
		{
			Temp1 = Temp1->next;
			temp->next = Temp1->next;
			Temp1->next = temp;
		}
		cout << " " << endl;
	}
}
void list::DelIndex(short x)
{
	Element* temp = Head;
	for (short i = 1; i < x - 1; i++)
	{
		temp = temp->next;
	}
	Element* Temp1 = Head;
	for (int i = 1; i < x; i++)
	{
		Temp1 = Temp1->next;
	}
	temp->next = Temp1->next;
	delete Temp1;
}
int list::Search(char x)
{
	Element* temp = Head;
	int pos = 1;
	while (temp->data != x)
	{
		if (temp->data == x)
		{
			return pos;
		}
		temp = temp->next;
		pos++;
	}
	return 0;
}


void list::Print()
{
	Element* temp = Head;
	while (temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
}
int list::Get_count()
{
	return count;
}

int main()
{
	list obj;
	char s[] = "Naima Bilal";
	cout << s << endl;
	int size = strlen(s);
	for (int i = NULL; i < size; i++)
	{
		obj.Add(s[i]);
	}
	cout << "\n";

}