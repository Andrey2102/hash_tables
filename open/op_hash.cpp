#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace  std;

struct Node
{
	Node* next;
	int data;
};

typedef Node* PNode;

class Hash{
	PNode *Hash_Table;
	int size;
	public:
		Hash() : Hash_Table(nullptr), size(0) {}
		void generate_data(int);
		void SIZE_inp();
		int Hash_func(int);
		void insert_elem(int);
		void create_Hash_Table();
		void output_HT();
		PNode find(int);
};

int Hash::Hash_func(int key){
	return (key % size);
}

void Hash::insert_elem(int num)
{
	PNode p, p0;
	int h = Hash_func(num);
	p = new Node;
	p0 = Hash_Table[h];
	Hash_Table[h] = p;
	p->next = p0;
	p->data = num;
}

void Hash::generate_data(int count){
	srand(time(NULL));
	int n;
	cout << endl << endl << "Generated numbers: " << endl;
	for (int i = 0; i < count; ++i)
	{
		n = rand() % 100;
		if (i % 10 == 0 && i > 0)
		{
			cout << endl;
		}
		cout << setw(4) << n;
		insert_elem(n);
	}
}

void Hash::SIZE_inp(){
	cout << endl << endl << "Hash table size: ";
	cin >> size;	
}

void Hash::output_HT(){
	cout << endl << endl << "Hash table: " << endl;
	for (int i = 0; i < size; ++i)
	{
		cout << i << " ";
		Node *temp = Hash_Table[i];
		while(temp){
			cout << "-> " << temp->data;
			temp = temp->next;		
		}
		cout << endl;
	}
}

void Hash::create_Hash_Table()
{
	SIZE_inp();
	Hash_Table = new Node*[size];
	for (int i = 0; i < size; i++)
	{
		Hash_Table[i] = nullptr;
	}
	cout << endl << "Enter count of elements to insert in hash table: ";
	int count_of_el;
	cin >> count_of_el;
	generate_data(count_of_el);
	output_HT();
}

PNode Hash::find(int key)
{
	Node* p;
	p = Hash_Table[Hash_func(key)];
	while (p && !(p->data == key))
	{
		p = p->next;
	}
	return p;
}

int main(){
	Hash hash_t;
	hash_t.create_Hash_Table();
	cout << endl << endl << "Enter the number to search in the hash table: ";
	int search;
	cin >> search;
	return 0;
}