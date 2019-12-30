#include<iostream>
#include<string.h>
#include<string>
using namespace std;
#define MAXN 100
typedef struct Node* Nodeptr;

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
	Nodeptr list;
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
	list = NULL;
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
	Nodeptr i;
	cout << "\n\n";
	for (i = list; i != NULL; i = i->next)
	{
		if (i->power != 0)
		{
			cout << i->coeff << "x^" << i->power << " + ";
		}
		else
		{
			cout << i->coeff << endl;;
		}

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


long binomialCoefficient(int n, int m)
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

void performMultiplication(Link L1, Link L2)
{
	
	Nodeptr  eq1 = L1.getHead(), eq2 = L2.getHead(), check1, check2;
	int number, power;
	Link L3;

	sort(eq1);
	sort(eq2);

	if (eq1 != NULL && eq2 != NULL)
	{
		while (eq1 != NULL)
		{
			eq2 = L2.getHead();
			while (eq2 != NULL)
			{
				number = eq1->coeff * eq2->coeff;
				power = eq1->power + eq2->power;
				L3.iAE(number, power);
				eq2 = eq2->next;
			}
			eq1 = eq1->next;
		}
	}
	cout << "\nResult of multiplication is:  ";
	L3.traverse();
	cout << "\n\n";
}

void performAddition(Link L1, Link L2)
{

	Nodeptr  eq1 = L1.getHead(), eq2 = L2.getHead(), sum;
	Link L3;


	while (eq1 != NULL && eq2 != NULL)
	{

		if (eq1->power == eq2->power)
		{
			int add = eq1->coeff + eq2->coeff;
			L3.iAE(add, eq1->power);
			eq1 = eq1->next;
			eq2 = eq2->next;
		}

		else if (eq1->power > eq2->power)
		{
			L3.iAE(eq1->coeff, eq1->power);
			eq1 = eq1->next;
		}
		else if (eq1->power < eq2->power)
		{
			L3.iAE(eq2->coeff, eq2->power);
			eq2 = eq2->next;
		}

	}

	if (eq1 != NULL)
	{
		while (eq1 != NULL)
		{
			L3.iAE(eq1->coeff, eq1->power);
			eq1 = eq1->next;
		}
	}

	if (eq2 != NULL)
	{
		while (eq2 != NULL)
		{
			L3.iAE(eq2->coeff, eq2->power);
			cout << eq2->coeff << eq2->power << endl;
			eq2 = eq2->next;
		}
	}

	sum = L3.getHead();

	cout << "\nResult of addition is:  ";

	for (sum; sum != NULL; sum = sum->next)
	{
		if (sum->power != 0)
		{
			cout << sum->coeff << "x^" << sum->power << "+";
		}
		else
		{
			cout << sum->coeff << endl;;
		}
	}
	cout << "\n\n";
}


void performSubtraction(Link L1, Link L2)
{

	Nodeptr  eq1 = L1.getHead(), eq2 = L2.getHead(), sum;
	Link L3;


	while (eq1 != NULL && eq2 != NULL)
	{

		if (eq1->power == eq2->power)
		{
			int add = eq1->coeff - eq2->coeff;
			L3.iAE(add, eq1->power);
			eq1 = eq1->next;
			eq2 = eq2->next;
		}

		else if (eq1->power > eq2->power)
		{
			L3.iAE(eq1->coeff, eq1->power);
			eq1 = eq1->next;
		}
		else if (eq1->power < eq2->power)
		{
			L3.iAE(eq2->coeff, eq2->power);
			eq2 = eq2->next;
		}

	}

	if (eq1 != NULL)
	{
		while (eq1 != NULL)
		{
			L3.iAE(eq1->coeff, eq1->power);
			eq1 = eq1->next;
		}
	}

	if (eq2 != NULL)
	{
		while (eq2 != NULL)
		{
			L3.iAE(eq2->coeff, eq2->power);
			cout << eq2->coeff << eq2->power << endl;
			eq2 = eq2->next;
		}
	}

	sum = L3.getHead();

	cout << "\nResult of subtraction is:  ";

	for (sum; sum != NULL; sum = sum->next)
	{
		if (sum->power != 0)
		{
			cout << sum->coeff << "x^" << sum->power << "+";
		}
		else
		{
			cout << sum->coeff << endl;;
		}
	}
	cout << "\n\n";
}

int main()
{
	Link objLink, objLink2;
	string str1;
	string str2;
	int coeff[3] = {}, power[3] = {};
	str1 = "1x^2+5x^1+2x^0";
	str2 = "8x^2+2x^1+4x^0";
	int k = 0, l = 0;
	int num1 = 0, num2 = 0;
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
				cout << "Error Line # 372: Expected digit after ^";
				cout << "\n\n****************************************\n\n";
			}
		}
	}

	for (int i = 0; i < 3; i++)
	{
		objLink.iAE(coeff[i], power[i]);
	}

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
				cout << "Error Line # 424: Expected digit after ^";
				cout << "\n\n****************************************\n\n";
			}
		}
	}

	for (int i = 0; i < 3; i++)
	{
		objLink2.iAE(coeff[i], power[i]);
	}

	head1 = objLink.getHead();
	head2 = objLink2.getHead();

	sort(head1);
	sort(head2);

	cout << "\nTraversing Sorted First Expression\n";
	for (Nodeptr i = head1; i != NULL; i = i->next)
	{
		if (i->power != 0)
		{
			cout << i->coeff << "x^" << i->power << " + ";
		}
		else
		{
			cout << i->coeff << endl;;
		}
	}

	cout << "\nTraversing Sorted Second Expression\n";
	for (Nodeptr i = head2; i != NULL; i = i->next)
	{
		if (i->power != 0)
		{
			cout << i->coeff << "x^" << i->power << " + ";
		}
		else
		{
			cout << i->coeff << endl;;
		}
	}
	cout << "\n\n";

	cout << "\nEnter Number 1: >> ";
	cin >> num1;
	cout << "\nEnter Number 2: >> ";
	cin >> num2;

	cout << "\nThe Binomial Coefficient of " << num1 << " & "<< num2 << " is " << binomialCoefficient(num1, num2) << endl;
	performAddition(objLink, objLink2);
	performSubtraction(objLink, objLink2);
	performMultiplication(objLink, objLink2);

}