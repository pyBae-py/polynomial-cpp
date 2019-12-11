#include<iostream>
using namespace std;

typedef struct Node* Nodeptr;

Nodeptr concatenate(Nodeptr, Nodeptr);
void printConcat(Nodeptr);
void sort(Nodeptr);

struct Node
{
	int info;
	int coeff;
	int power;
	Nodeptr next;
	Nodeptr prev;
};


class Link
{
private:
	Nodeptr list = NULL;
	int count;
public:
	Link();
	Nodeptr makeNode();
	void iAS(int, int);
	void iAE(int , int);
	Nodeptr getHead();
	Nodeptr getTail();
	void traverse();
	void sort();
};

Link::Link()
{
	count = 0;
}

Nodeptr Link::makeNode()
{
	Nodeptr p = new Node();
	p->info = 0;
	p->power = 0;
	p->coeff = 0;
	p->next = NULL;
	p->prev = NULL;
	return p;
}

void Link::iAS(int coeff,int pow)
{
	Nodeptr q = makeNode();
	q->coeff = coeff;
	q->power = pow;
	q->next = list;
	list = q;
	q->prev = NULL;
	count++;
}



void Link::iAE(int coeff,int pow)
{
	if (list == NULL)
	{
		iAS(coeff,pow);
	}
	else
	{
		count++;
		Nodeptr q = NULL;
		Nodeptr p;
		for (p = list; p->next != NULL; p = p->next);
		q = makeNode();
		q->coeff = coeff;
		q->power = pow;
		
		q->next = NULL;
		q->prev = p;
		p->next = q;
	}
}


Nodeptr Link::getHead()
{
	return list;
}

Nodeptr Link::getTail()
{
	Nodeptr p;
	for (p = list; p != NULL; p = p->next);
	return p;
}

void Link::traverse()
{
	Nodeptr p;
	cout << "\n\n";
	for (p = list; p!= NULL; p = p->next)
	{
		cout << p->coeff << "x" << "^" << p->power << " + ";
	
	}
	cout << "\n\n";
}


void Link::sort()
{
	int temp,temp1,temp2;
	Nodeptr p;
	int i, j;
	for (i = 0; i < count - 1; i++)
	{
		for (j = 0; j < count - 1 - i; j++)
		{
			for (p = list; p != NULL; p = p->next)
			{
				if (p->next == NULL)
				{
					break;
				}
				if (p->power < p->next->power)
				{
					temp = p->next->power;
					temp1 = p->next->coeff;
					
					p->next->power = p->power;
					p->next->coeff = p->coeff;
					
					p->power = temp;
					p->coeff = temp1;
					
				}
			}
		}
	}
}



Nodeptr concatenate(Nodeptr head1, Nodeptr head2)
{
	if (head1 != NULL && head2 != NULL)
	{
		if (head1->next == NULL)
		{
			head1->next = head2;
		}
		else
		{
			concatenate(head1->next, head2);
		}
	}
	else
	{
		cout << "\nEither a or b is NULL\n";
	}

	return head1;
}


void printConcat(Nodeptr head)
{
	cout << "\nPrinting Unsorted Concatenated List\n";
	Nodeptr p;
	cout << "\n\n";
	for (p = head; p != NULL; p = p->next)
	{
		cout << p->coeff << "x" << "^" << p->power << " + ";

	}
	cout << "\n\n";

	sort(head);
	cout << "\nPrinting Sorted Concatenated List\n";
	cout << "\n\n";
	for (p = head; p != NULL; p = p->next)
	{
		cout << p->coeff << "x" << "^" << p->power << " + ";

	}
	cout << "\n\n";
}


void sort(Nodeptr head)
{
	int temp, temp1;
	Nodeptr a, b;
	Nodeptr p;
	int i, j;
	int c = 0;
	for (Nodeptr k = head; k != NULL; k = k->next)
	{
		c++;
	}
	for (i = 0; i < c - 1; i++)
	{
		for (j = 0; j < c - 1 - i; j++)
		{
			for (p = head; p != NULL; p = p->next)
			{
				if (p->next == NULL)
				{
					break;
				}
				if (p->power < p->next->power)
				{
					temp = p->next->power;
					temp1 = p->next->coeff;
					
					p->next->power = p->power;
					p->next->coeff = p->coeff;
					
					p->power = temp;
					p->coeff = temp1;
					
				}
			}
		}
	}
}

int main()
{
	Link objLink,objLink2;
	string str1;
	int coeff=0, power=0,con=4;
	str1 = "1x^2+5x^1+2x^0";
	
	int k=0, l=0;

	
	
	for (int i = 0; i < str1.length(); i++)
	{
		
		if (isdigit(str1[i]))
		{
			if (str1[i + 1] == 'x')
			{
				coeff = str1[i] - '0';
				k++;
			}
			
		}
		else if (str1[i] == '^')
		{
			if (isdigit(str1[i + 1]))
			{
				power = str1[i + 1] - '0';
				l++;
			}
			else
			{
				cout << "\n\n****************************************\n\n";
				cout << "Error Line # 258: Expected digit after ^";
				cout << "\n\n****************************************\n\n";
			}
		}
	}
	
		objLink.iAE(coeff, power);
	
	

	cout << "\nTraversing Unsorted First Expression\n";
	objLink.traverse();

	
	/*objLink.iAE(1, 2);
	objLink.iAE(3, 4);
	objLink.iAE(5, 6);
	objLink.iAE(7, 8);

	
	objLink2.iAE(4, 9);
	objLink2.iAE(84, 4);
	objLink2.iAE(45, 6);
	objLink2.iAE(417, 8);

	cout << "\nTraversing Unsorted Second Expression\n";
	objLink2.traverse();

	Nodeptr head1, head2;
	Nodeptr temp;
	head1 = objLink.getHead();
	head2 = objLink2.getHead();
	temp = concatenate(head1, head2);
	printConcat(temp);*/

	/*objLink2.traverse();
	objLink2.sort();
	Nodeptr head1, head2;
	Nodeptr temp;
	head1 = objLink.getHead();
	head2 = objLink2.getHead();
	temp = Link<double>::concatenate(head1, head2);
	cout << "\n\n";
	objLink2.traverse();*/

}