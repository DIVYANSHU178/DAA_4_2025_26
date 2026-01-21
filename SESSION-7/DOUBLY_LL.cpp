#include <iostream>
using namespace std;

class LL
{
public:
	int data;
	LL *next;
	LL *prev;
	LL *head;
	LL *tail;

	LL()
	{
		next = prev = tail = head = NULL;
	}

	void PUSH_FRONT(int n)
	{
		LL *newnode = new LL();
		newnode->data = n;
		if (head == NULL)
		{
			newnode->next = NULL;
			newnode->prev = NULL;
			head = newnode;
			tail = newnode;
		}
		else
		{
			head->prev = newnode;
			newnode->next = head;
			newnode->prev = NULL;
			head = newnode;
			LL *temp = head;
			while (temp->next != NULL)
			{
				temp = temp->next;
			}
			tail = temp;
		}
		cout << "\nSUCCESSFULLY INSERTED A NEW NODE AT FIRST POSITION FROM FRONT............\nDISPLAYING THE LIST FROM FRONT.......\n\n";
		print();
	}

	void PUSH_BACK(int n)
	{
		LL *newnode = new LL();
		newnode->data = n;
		if (head == NULL)
		{
			newnode->next = NULL;
			head = newnode;
		}
		else
		{
			LL *temp = head;
			while (temp->next != NULL)
			{
				temp = temp->next;
			}
			temp->next = newnode;
			newnode->prev = temp;
			newnode->next = NULL;
			tail = newnode;
		}
		cout << "\nSUCCESSFULLY INSERTED A NEW NODE AT LAST POSITION FROM FRONT............\nDISPLAYING THE LIST FROM FRONT.......\n\n";
		print();
	}
	void PUSH_MIDDLE(int pos, int val)
	{
		LL *newnode = new LL();
		newnode->data = val;
		if (pos <= 1 || head == NULL)
		{
			PUSH_FRONT(val);
			return;
		}
		LL *temp = head;
		int count = 1;
		while (temp != NULL && count < pos - 1)
		{
			temp = temp->next;
			count++;
		}
		if (temp == NULL || temp->next == NULL)
		{
			PUSH_BACK(val);
			return;
		}
		newnode->next = temp->next;
		newnode->prev = temp;
		temp->next->prev = newnode;
		temp->next = newnode;
		cout << "\nSUCCESSFULLY INSERTED A NEW NODE AT YOUR GIVEN POSITION FROM FRONT............\nDISPLAYING THE LIST FROM FRONT.......\n\n";
		print();
	}

	void DELETE_FRONT()
	{
		if (head == NULL)
			return;
		LL *temp = head;
		head = head->next;
		if (head != NULL)
			head->prev = NULL;
		else
			tail = NULL;
		delete temp;
		cout << "\nSUCCESSFULLY DELETED FIRST NODE FROM FRONT ............\nDISPLAYING THE LIST FROM FRONT.......\n\n";
		print();
	}

	void DELETE_BACK()
	{
		if (tail == NULL)
			return;
		LL *temp = tail;
		tail = tail->prev;
		if (tail != NULL)
			tail->next = NULL;
		else
			head = NULL;
		delete temp;
		cout << "\nSUCCESSFULLY DELETED LAST NODE FROM FRONT ............\nDISPLAYING THE LIST FROM FRONT.......\n\n";
		print();
	}

	void DELETE_MIDDLE(int pos)
	{
		if (pos <= 1)
		{
			DELETE_FRONT();
			return;
		}
		LL *temp = head;
		int count = 1;
		while (temp != NULL && count < pos)
		{
			temp = temp->next;
			count++;
		}
		if (temp == NULL || temp == tail)
		{
			DELETE_BACK();
			return;
		}
		temp->prev->next = temp->next;
		temp->next->prev = temp->prev;
		delete temp;
		cout << "\nSUCCESSFULLY DELETED SPECIFIC NODE FROM FRONT ............\nDISPLAYING THE LIST FROM FRONT.......\n\n";
		print();
	}

	void PUSH_MIDDLE_END(int pos, int val)
	{
		LL *newnode = new LL();
		newnode->data = val;

		if (tail == NULL || pos <= 1)
		{
			PUSH_BACK(val);
			return;
		}

		LL *temp = tail;
		int count = 1;
		while (temp != NULL && count < pos - 1)
		{
			temp = temp->prev;
			count++;
		}

		if (temp == NULL || temp->prev == NULL)
		{
			PUSH_FRONT(val);
			return;
		}

		newnode->next = temp;
		newnode->prev = temp->prev;
		temp->prev->next = newnode;
		temp->prev = newnode;

		cout << "\nSUCCESSFULLY INSERTED NODE AT POSITION " << pos << " FROM BACK\n";
		print();
	}
	void DELETE_MIDDLE_END(int pos)
	{
		if (tail == NULL || pos <= 1)
		{
			DELETE_BACK();
			return;
		}

		LL *temp = tail;
		int count = 1;
		while (temp != NULL && count < pos)
		{
			temp = temp->prev;
			count++;
		}

		if (temp == NULL || temp == head)
		{
			DELETE_FRONT();
			return;
		}

		temp->prev->next = temp->next;
		temp->next->prev = temp->prev;
		delete temp;

		cout << "\nSUCCESSFULLY DELETED NODE AT POSITION " << pos << " FROM BACK\n";
		print();
	}
	void PUSH_BACK_END(int val)
	{
		LL *newnode = new LL();
		newnode->data = val;
		newnode->next = NULL;

		if (tail == NULL)
		{
			head = tail = newnode;
			newnode->prev = NULL;
		}
		else
		{
			tail->next = newnode;
			newnode->prev = tail;
			tail = newnode;
		}

		cout << "\nINSERTED AT BACK USING TAIL\n";
		print();
	}
	void DELETE_BACK_END()
	{
		if (tail == NULL)
			return;

		LL *temp = tail;
		tail = tail->prev;

		if (tail != NULL)
			tail->next = NULL;
		else
			head = NULL;

		delete temp;
		cout << "\nDELETED LAST NODE USING TAIL\n";
		print();
	}
	void DELETE_FRONT_END()
	{
		if (tail == NULL)
			return;

		LL *temp = tail;
		while (temp->prev != NULL)
		{
			temp = temp->prev;
		}

		// temp is now head
		if (temp->next != NULL)
		{
			head = temp->next;
			head->prev = NULL;
		}
		else
		{
			head = tail = NULL;
		}

		delete temp;
		cout << "\nDELETED FIRST NODE BY TRAVERSING FROM TAIL\n";
		print();
	}
	void PUSH_FRONT_END(int val)
	{
		LL *newnode = new LL();
		newnode->data = val;

		if (tail == NULL)
		{
			head = tail = newnode;
			newnode->next = newnode->prev = NULL;
		}
		else
		{
			LL *temp = tail;
			while (temp->prev != NULL)
			{
				temp = temp->prev;
			}

			temp->prev = newnode;
			newnode->next = temp;
			newnode->prev = NULL;
			head = newnode;
		}

		cout << "\nINSERTED AT FRONT BY TRAVERSING FROM TAIL\n";
		print();
	}

	void print()
	{
		LL *temp = head;
		while (temp != NULL)
		{
			cout << temp->data << "->";
			temp = temp->next;
		}
		cout << "NULL\n\n";

		cout << "\nDISPLAYING THE LIST FROM BACK..........\n";

		LL *temp2 = tail;
		cout << "\nNULL->";
		while (temp2 != NULL)
		{
			if (temp2->prev == NULL)
			{
				cout << temp2->data;
				temp2 = temp2->prev;
			}
			else
			{
				cout << temp2->data << "->";
				temp2 = temp2->prev;
			}
		}
		cout << endl;
	}
};
int main()
{
	LL obj;
	bool check = true;
	int p, z;
	while (check == true)
	{
		cout << "FROM WHICH END YOU WANT TO DO OPERATIONS?\n1-HEAD\n2-TAIL\nYOUR CHOICE : ";
		cin >> z;
		if (z == 1)
		{
			cout << "\n\nCHOOSE A OPTION\n1. PUSH_FRONT\n2. PUSH_BACK\n3. PUSH_MIDDLE\n4. DELETE_FRONT\n5. DELETE_BACK\n6. DELETE_MIDDLE\n\nYOUR CHOICE : ";
			cin >> p;
			if (p == 1)
			{
				cout << "\nYOU OPTED FOR PUSH_FRONT......\nA NEW NODE IS CREATED.......\nENTER A VALUE TO INSERT IN IT.......\nYOUR ENTERED VALUE : ";
				int x;
				cin >> x;

				obj.PUSH_FRONT(x);
			}
			if (p == 2)
			{
				cout << "\nYOU OPTED FOR PUSH_BACK.........\nA NEW NODE IS CREATED.......\nENTER A VALUE TO INSERT IN IT.......\n";
				int x;
				cin >> x;
				obj.PUSH_BACK(x);
			}
			if (p == 3)
			{
				cout << "\nYOU OPTED FOR PUSH_MIDDLE.........\nA NEW NODE IS CREATED.......\nENTER A VALUE TO INSERT IN IT.......\n";
				int x;
				cin >> x;
				cout << "\nNOW ENTER THE POSITION FROM FRONT TO INSERT AT\nPOSITION : ";
				int y;
				cin >> y;
				obj.PUSH_MIDDLE(y, x);
			}
			if (p == 4)
			{
				cout << "\nYOU OPTED FOR DELETE_FRONT......\nFRONT NODE IS DELETED.......\n";

				obj.DELETE_FRONT();
			}
			if (p == 5)
			{
				cout << "\nYOU OPTED FOR DELETE_BACK......\nLAST NODE IS DELETED.......\n";

				obj.DELETE_FRONT();
			}
			if (p == 6)
			{
				int x;
				cout << "\nYOU OPTED FOR DELETE_MIDDLE......\nENTER NUMBER OF NODE TO BE DELETED.......\n";
				cin >> x;
				obj.DELETE_MIDDLE(x);
			}
		}
		if (z == 2)
		{
			cout << "\n\nCHOOSE A OPTION\n1. PUSH_BACK_END\n2. PUSH_FRONT_END\n3. PUSH_MIDDLE_BACK\n4. DELETE_BACK_END\n5. DELETE_FRONT_END\n6. DELETE_MIDDLE_BACK\n\nYOUR CHOICE : ";
			cin >> p;
			if (p == 1)
			{
				cout << "\nYOU OPTED FOR PUSH_BACK_END......\nENTER VALUE : ";
				int x;
				cin >> x;
				obj.PUSH_BACK_END(x);
			}
			if (p == 2)
			{
				cout << "\nYOU OPTED FOR PUSH_FRONT_END......\nENTER VALUE : ";
				int x;
				cin >> x;
				obj.PUSH_FRONT_END(x);
			}
			if (p == 3)
			{
				cout << "\nYOU OPTED FOR PUSH_MIDDLE_BACK......\nENTER VALUE : ";
				int x;
				cin >> x;
				cout << "ENTER POSITION FROM BACK : ";
				int y;
				cin >> y;
				obj.PUSH_MIDDLE_END(y, x);
			}
			if (p == 4)
			{
				cout << "\nYOU OPTED FOR DELETE_BACK_END......\n";
				obj.DELETE_BACK_END();
			}
			if (p == 5)
			{
				cout << "\nYOU OPTED FOR DELETE_FRONT_END......\n";
				obj.DELETE_FRONT_END();
			}
			if (p == 6)
			{
				cout << "\nYOU OPTED FOR DELETE_MIDDLE_BACK......\nENTER POSITION FROM BACK : ";
				int x;
				cin >> x;
				obj.DELETE_MIDDLE_END(x);
			}
		}

		cout << "\nWANT TO OPERATE MORE?\nENTER 1(TRUE) TO OPERATE MORE OR 0(FALSE) TO EXIT :  ";
		cin >> check;
	}
	cout << "THANKS FOR USING\nEXITING THE RUN.........";
}