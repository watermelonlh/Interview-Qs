#include <iostream>
using namespace std;

struct linklist
{
	linklist *next, *random;
	int value;
};

linklist *insert(linklist *now, int value)
{
	linklist *p = new linklist;
	p->value = value;
	if (now != NULL)
	{
		p->next = now->next;
		now->next = p;
	}
	return p;
}

linklist *dupLinkList(linklist *head)
{
	linklist *now = head;
	while (now != NULL)
	{
		insert(now, now->value);
		cout << now->value << endl;
		now = now->next->next;
	}
	now = head;
	linklist *res = head->next;
	while (now != NULL)
	{
		linklist *dup = now->next;
		dup->random = now->random->next;
		now->next = dup->next;
		dup->next = now->next;
		now = now->next;
	}
	return res;
}

int main()
{
	int N;
	cin >> N;
	linklist *head = NULL, *tail = NULL;
	for (int i = 0; i < N; i++)
	{
		int a;
		cin >> a;
		tail = insert(tail, a);
		if (head == NULL) head = tail;
	}


	for (linklist *p = head; p != NULL; p = p->next)
	{
		int a;
		cin >> a;
		linklist *now = head;
		for (int k = 1; k < a; k++)
			now = now->next;
		p->random = now;
	}

	linklist *head2 = dupLinkList(head);


	for (linklist *p = head2; p != NULL; p = p->next)
		cout << p->value << ' ' << p->random->value << endl;
	for (linklist *p = head; p != NULL; p = p->next)
		cout << p->value << ' ' << p->random->value << endl;
	
}
