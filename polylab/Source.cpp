#include<iostream>
using namespace std;
#define MAXN 100
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
	void iAE(int, int);
	Nodeptr getHead();
	Nodeptr getTail();
	void traverse();
	void sort();
	int getCount();
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

void Link::iAS(int coeff, int pow)
{
	Nodeptr q = makeNode();
	q->coeff = coeff;
	q->power = pow;
	q->next = list;
	list = q;
	q->prev = NULL;
	count++;
}



void Link::iAE(int coeff, int pow)
{
	if (list == NULL)
	{
		iAS(coeff, pow);
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
int Link::getCount()
{
	return count;
}

void Link::traverse()
{
	Nodeptr p;
	cout << "\n\n";
	for (p = list; p != NULL; p = p->next)
	{
		cout << p->coeff << "x" << "^" << p->power << " + ";

	}
	cout << "\n\n";
}


void Link::sort()
{
	int temp, temp1, temp2;
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

Nodeptr makeNode()
{
	Nodeptr p = new Node();
	p->info = 0;
	p->power = 0;
	p->coeff = 0;
	p->next = NULL;
	p->prev = NULL;
	return p;
}

void addPoly(Nodeptr q)
{
	for (Nodeptr p = q; p != NULL; p = p->next)
	{
		cout << p->coeff << "x" << "^" << p->power << " + ";
	}
	Nodeptr temp = makeNode();
	Nodeptr p;
	int co;
	int intTemp;
	for (Nodeptr i = q; i->next != NULL; i = i->next)
	{
		intTemp = i->power;

		for (p = i; p != NULL && p->power == intTemp; p = p->next)
		{



			co = p->coeff + i->coeff;
			//temp->power = intTemp;
			//temp = temp->next;
			cout << co << " x ";

		}
	}


	for (Nodeptr p = temp; p != NULL; p = p->next)
	{
		cout << p->coeff << "x" << "^" << p->power << " + ";
	}

}


long binomial_coefficient(int n, int m)
{
	int i, j;
	long bc[MAXN][MAXN];
	for (i = 0; i <= n; i++)
	{
		bc[i][0] = 1;
	}
	for (j = 0; j <= n; j++)
	{
		bc[j][j] = 1;
	}

	for (i = 1; i <= n; i++)
	{
		for (j = 1; j < i; j++)
		{
			bc[i][j] = bc[i - 1][j - 1] + bc[i - 1][j];
		}
	}
	return bc[n][m];
}



int main()
{
	Link objLink, objLink2;
	string str1;
	int coeff[3] = {}, power[3] = {};
	str1 = "1x^2+5x^1+2x^0";
	int k = 0, l = 0;

	Nodeptr head1, head2, concat;
	int count1, count2;

	for (int i = 0; i < str1.length(); i++)
	{

		if (isdigit(str1[i]))
		{
			if (str1[i + 1] == 'x')
			{
				if (k > 2)
				{
					break;
				}
				coeff[k] = str1[i] - '0';
				k++;
			}

		}
		else if (str1[i] == '^')
		{
			if (isdigit(str1[i + 1]))
			{
				if (l > 2)
				{
					break;
				}
				power[l] = str1[i + 1] - '0';
				l++;
			}
			else
			{
				cout << "\n\n****************************************\n\n";
				cout << "Error Line # 340: Expected digit after ^";
				cout << "\n\n****************************************\n\n";
			}
		}
	}

	for (int i = 0; i < 3; i++)
	{
		objLink.iAE(coeff[i], power[i]);
	}



	cout << "\nTraversing Unsorted First Expression\n";
	objLink.traverse();

	string str2;
	str2 = "8x^2+2x^1+4x^0";

	k = 0;
	l = 0;
	for (int i = 0; i < str2.length(); i++)
	{

		if (isdigit(str2[i]))
		{
			if (str2[i + 1] == 'x')
			{
				if (k > 2)
				{
					break;
				}
				coeff[k] = str2[i] - '0';
				k++;
			}

		}
		else if (str2[i] == '^')
		{
			if (isdigit(str2[i + 1]))
			{
				if (l > 2)
				{
					break;
				}
				power[l] = str2[i + 1] - '0';
				l++;
			}
			else
			{
				cout << "\n\n****************************************\n\n";
				cout << "Error Line # 391: Expected digit after ^";
				cout << "\n\n****************************************\n\n";
			}
		}
	}

	for (int i = 0; i < 3; i++)
	{
		objLink2.iAE(coeff[i], power[i]);
	}

	cout << "\nTraversing Unsorted Second Expression\n";
	objLink2.traverse();

	count1 = objLink.getCount();
	count2 = objLink2.getCount();
	head1 = objLink.getHead();
	head2 = objLink2.getHead();

	concat = concatenate(head1, head2);
	printConcat(concat);

	addPoly(concat);
}