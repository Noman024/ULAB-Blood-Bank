/*
Group No      : 01
Project Name  : ULAB BLOOD BANK

Submitted by  :
---------------
Student Name  : Md. Mutasim Billah Abu Noman Akanda
Student ID    : 192 014 038

Submitted to  :
---------------
Faculty Name  : Bijan Paul

Submission    :
---------------
12 January, 2021

Features used :
---------------
1. Singly Linked List
2. Stack
3. Bubble Sort
4. File
*/

#include <iostream>
#include <cstring>
#include <fstream>
#include <conio.h>

using namespace std;

//blood bank program
struct ListNode{
	int id,mobile;
	string name,email,blood;
	ListNode *next;
};

ListNode *Head = NULL;
ListNode *previous = 0;
int counter = 0;
fstream user_file;

ListNode *GetNewNode(void)
{
	ListNode *Node = new ListNode;
	Node->next = NULL;
	return Node;
}

bool isempty()
{
    if(Head == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int Getid(void)
{
	int id;
	cout << "Enter Donor's ULAB ID : ";
	cin >> id;
	user_file.open("Donor_lists.txt",ios::out|ios::app);
	user_file << id << "\t";
	user_file.close();
	return id;
}

void Addid(ListNode *p,int id)
{
	p->id = id;
}

int Getmobile(void)
{
	int mobile;
	cout << "Enter Donor's Phone Number : ";
	cin >> mobile;
	user_file.open("Donor_lists.txt",ios::out|ios::app);
	user_file << mobile << endl;
	user_file.close();
	return mobile;
}

void Addmobile(ListNode *p,int mobile)
{
	p->mobile = mobile;
}

string Getname(void)
{
	string name;
	cout << "Enter Donor's Name : ";
	fflush(stdin);
	getline(cin,name);
	user_file.open("Donor_lists.txt",ios::out|ios::app);
	user_file << name << "\t";
	user_file.close();
	return name;
}

void Addname(ListNode *p,string name)
{
	p->name = name;
}

string Getemail(void)
{
	string email;
	cout << "Donor's Email : ";
	fflush(stdin);
	getline(cin,email);
	user_file.open("Donor_lists.txt",ios::out|ios::app);
	user_file << email << "\t";
	user_file.close();
	return email;
}

void Addemail(ListNode *p,string email)
{
	p->email = email;
}

string Getblood(void)
{
	string blood;
	cout << "Enter Donor's Blood Group : ";
	fflush(stdin);
	getline(cin,blood);
	user_file.open("Donor_lists.txt",ios::out|ios::app);
	user_file << blood << "\t";
	user_file.close();
	return blood;
}

void Addblood(ListNode *p,string blood)
{
	p->blood = blood;
}

ListNode *CreateNewNode(void)
{
	ListNode *CurNode = GetNewNode();
	Addname(CurNode,Getname());
	Addid(CurNode,Getid());
	Addemail(CurNode,Getemail());
	Addblood(CurNode,Getblood());
	Addmobile(CurNode,Getmobile());
    cout << endl;
	return CurNode;
}

void CreateList(int TotalElement)
{
    ListNode *CurNode = Head = GetNewNode();
    counter++;
    Addname(CurNode,Getname());
    Addid(CurNode, Getid());
	Addemail(CurNode,Getemail());
	Addblood(CurNode,Getblood());
	Addmobile(CurNode,Getmobile());
    cout << endl;
    for(int i=1; i<TotalElement; i++)
    {
        counter++;
	    CurNode->next = CreateNewNode();
	    CurNode = CurNode->next;
    }
}

void showlist()
{
    ListNode *CurNode = Head;
    cout << "Donor Number : " << counter << endl;
    cout << "Donor Details : " << endl << endl;
    while(CurNode!=NULL)
    {
        cout << CurNode->name << "\t";
        cout << CurNode->id << "\t";
        cout << CurNode->email << "\t";
        cout << CurNode->mobile << "\t";
        cout << CurNode->blood << endl;
        CurNode = CurNode->next;
    }
}

void insertFirst()
{
    counter++;
    ListNode *link = CreateNewNode();
    link->next = Head;
    Head = link;
}

void insertGivenPosition()
{
    int pos,i = 1;
    ListNode *temp;
    ListNode *link = CreateNewNode();
    cout << "enter new donor position : ";
    cin >> pos;
    while(pos>counter)
    {
        cout << "Invalid!!! Enter new donor position : ";
        cin >> pos;
    }
    temp = Head;
    while(i<pos-1)
    {
        temp = temp->next;
        i++;
    }
    link->next = temp->next;
    temp->next = link;
    counter++;
}

void insertEnd()
{
    ListNode *temp;
    ListNode *newnodeC = CreateNewNode();
    temp = Head;
    while(temp->next!=0)
    {
        temp = temp->next;
    }
    temp->next = newnodeC;
    counter++;
}

void deleteFirst()
{
    if(Head==0)
        cout << "List is empty!!!" << endl;
    else
    {
    	ListNode *temp;
    	temp = Head;
    	Head = Head->next;
    	user_file.open("Removed_Donor_lists.txt",ios::out|ios::app);
        user_file << temp->name << "\t";
        user_file << temp->id << "\t";
        user_file << temp->email << "\t";
        user_file << temp->mobile << "\t";
        user_file << temp->blood << endl;
        user_file.close();
    	free(temp);
    	counter--;
    }
}

int deleteGivenPosition()
{
    if(isempty()==true)
        cout << "List is empty!!!" << endl;
    else
    {
        ListNode *temp,*nextnode;
        int pos,i=1;
        temp = Head;
        cout << "Enter deletion position : ";
        cin >> pos;
        while(pos>counter || pos==0 || pos==1)
        {
            if(pos==1)
            {
                deleteFirst();
                return 0;
            }
            cout << "Invalid!!! Enter correct position : ";
            cin >> pos;
        }
        while(i<pos-1)
        {
            temp = temp->next;
            i++;
        }
        nextnode = temp->next;
        temp->next = nextnode->next;
        user_file.open("Removed_Donor_lists.txt",ios::out|ios::app);
        user_file << nextnode->name << "\t";
        user_file << nextnode->id << "\t";
        user_file << nextnode->email << "\t";
        user_file << nextnode->mobile << "\t";
        user_file << nextnode->blood << endl;
        user_file.close();
        free(nextnode);
        counter--;
    }
    return 0;
}

void deleteEnd()
{
    if(isempty()==true)
    {
        cout << "List is empty" << endl;
    }
    else
    {
        ListNode *temp, *previousnode;
        temp = Head;
        while(temp->next!=0)
        {
            previousnode = temp;
            temp = temp->next;
        }

        if(temp == Head)
        {
            Head = 0;
            user_file.open("Removed_Donor_lists.txt",ios::out|ios::app);
            user_file << temp->name << "\t";
            user_file << temp->id << "\t";
            user_file << temp->email << "\t";
            user_file << temp->mobile << "\t";
            user_file << temp->blood << endl;
            user_file.close();
            free(temp);
            counter--;
        }
        else
        {
            previousnode->next = 0;
            user_file.open("Removed_Donor_lists.txt",ios::out|ios::app);
            user_file << temp->name << "\t";
            user_file << temp->id << "\t";
            user_file << temp->email << "\t";
            user_file << temp->mobile << "\t";
            user_file << temp->blood << endl;
            user_file.close();
            free(temp);
            counter--;
        }
    }
}

void deleteBasedonStudentID(ListNode *ptr)
{
    if(ptr == Head)
    {
       Head = Head->next;
    }
    else
    {
       previous->next = ptr->next;
    }
    user_file.open("Removed_Donor_lists.txt",ios::out|ios::app);
    user_file << ptr->name << "\t";
    user_file << ptr->id << "\t";
    user_file << ptr->email << "\t";
    user_file << ptr->mobile << "\t";
    user_file << ptr->blood << endl;
    user_file.close();
    free(ptr);
    counter--;
}

int searchNode(string blood)
{
   ListNode *current = Head;
   int tempc,flag=0;
   tempc = counter;
   while(tempc--)
   {
       if(current->blood==blood)
       {
           flag=1;
           cout << current->name << "\t";
           cout << current->id << "\t";
           cout << current->email << "\t";
           cout << current->mobile << "\t";
           cout << current->blood << endl << endl;
       }
       current = current->next;
   }

   if(flag==0)
        cout << endl << "No donor found" << endl;
}

void title()
{
    cout << "\t\t\t\t*****************************************" << endl;
    cout << "\t\t\t\t*                                       *" << endl;
    cout << "\t\t\t\t*             ULAB BLOOD BANK           *" << endl;
    cout << "\t\t\t\t*                                       *" << endl;
    cout << "\t\t\t\t*****************************************" << endl << endl << endl;
    cout << "To open the application : Enter 1" << endl;
    cout << "To exit the application : Enter 0" << endl;
    cout << "---------------------------------" << endl << endl;
    cout << "Enter your choice : ";
}

void message()
{
    cout << endl << "To sign up for a new account  : Enter 1" << endl;
    cout << "To log in to existing account : Enter 0" << endl;
    cout << "---------------------------------" << endl << endl;
    cout << "Enter your choice : ";
}

//user program stack
struct node
{
    string data;
    struct node* next;
};

node *top = 0;

void push(string x)
{
    node *newnode = new node;
    newnode->data = x;
    newnode->next = top;
    top = newnode;
    cout << endl << x << " account is created successfully." << endl << endl;
}

void totalnodeuserid()
{
    int usercount = 0;
    ifstream  myfile("Signed_Up_User_id.txt");
    string line;
    cout << "Signed Up ID : " << endl;
    while(getline(myfile,line))
    {
        cout << line << endl;
        usercount++;
    }
    cout << endl << "Signed Up ID Number : " << usercount << endl;
}

void totalnodeloginid()
{
    int logincount = 0;
    ifstream  myfile("Logged_In_User_id.txt");
    string line;
    cout << "Logged In ID : " << endl;
    while(getline(myfile,line))
    {
        cout << line << endl;
        logincount++;
    }
    cout << endl << "Logged In ID Number : " << logincount << endl;
}

void totaldonornumber()
{
    int donor = 0;
    ifstream  myfile("Donor_lists.txt");
    string line;
    while(getline(myfile,line))
    {
        donor++;
    }
    cout << "Donor Number : " << donor << endl;
}

void totaldonorlist()
{
    ifstream  myfile("Donor_lists.txt");
    string line;
    cout << "Donor Details : " << endl;
    while(getline(myfile,line))
    {
        cout << line << endl;
    }
    cout << endl;
}

void totalremoveddonornumber()
{
    int donor = 0;
    ifstream  myfile("Removed_Donor_lists.txt");
    string line;
    while(getline(myfile,line))
    {
        donor++;
    }
    cout << "Removed Donor Number : " << donor << endl;
}

void totalremoveddonorlist()
{
    ifstream  myfile("Removed_Donor_lists.txt");
    string line;
    cout << "Donor Details : " << endl;
    while(getline(myfile,line))
    {
        cout << line << endl;
    }
}

bool signup(string userid)
{
    ifstream  myfile("Signed_Up_User_id.txt");
    string line;

    bool found = false;
    while(getline(myfile,line ) && !found)
    {
        if(line.find(userid) != string::npos)
        {
            found = true;
            myfile.close();
            return false;
        }
    }

    if (!found)
    {
        myfile.close();
        return true;
    }
}

void bubblesort()
{
    ListNode *temphead;
	int tempid,tempmobile,countValue;
	string tempname,tempemail,tempblood;
	for (int i=0; i<counter-1; i++)
	{
	    temphead = Head;
	    countValue = 0;
		for (int j=0; j<counter-1-i; j++)
		{
			if (temphead->id > temphead->next->id)
			{
				tempid = temphead->id;
				temphead->id = temphead->next->id;
				temphead->next->id = tempid;

				tempname = temphead->name;
				temphead->name = temphead->next->name;
				temphead->next->name = tempname;

				tempmobile = temphead->mobile;
				temphead->mobile = temphead->next->mobile;
				temphead->next->mobile = tempmobile;

				tempemail = temphead->email;
				temphead->email = temphead->next->email;
				temphead->next->email = tempemail;

				tempblood = temphead->blood;
				temphead->blood = temphead->next->blood;
				temphead->next->blood = tempblood;
				countValue++;
			}
			temphead = temphead->next;
		}
		if(countValue==0)
        {
            break;
        }
	}
	showlist();
}

//main program
int main()
{
    title();
    int app,login,userid;
    string blood,sign;
    cin >> app;
    while(app!=0 && app!=1)
    {
        cout << "ERROR!!! You have entered invalid key." << endl << endl;
        cout << "Enter your choice : ";
        cin >> app;
    }

    if(app==0)
    {
        cout << endl << "Exit Successfully!!!" << endl;
        return -1;
    }
    else
    {
        cout << endl;
        //sign up or login
        User:
            message();
            cin >> login;

            while(login!=0 && login!=1)
            {
                cout << "ERROR!!! You have entered invalid key." << endl << endl;
                cout << "Enter your choice : ";
                cin >> login;
            }

            if(login==1)
            {
                user_file.open("Signed_Up_User_id.txt",ios::out|ios::app);
                cout << endl << "Enter a new ULAB ID : ";
                fflush(stdin);
                getline(cin,sign);
                if(signup(sign)==false)
                {
                    cout << endl << "ID already exists!!!" << endl;
                    goto User;
                }
                push(sign);
                user_file << sign << endl;
                user_file.close();
                goto User;
            }

            else
            {
                cout << endl << "Enter your ULAB ID : ";
                fflush(stdin);
                getline(cin,sign);
                if(signup(sign)==true)
                {
                    cout << endl << "ID not found!!!" << endl;
                    goto User;
                }
                user_file.open("Logged_In_User_id.txt",ios::out|ios::app);
                user_file << sign << endl;
                user_file.close();

                //main program
                int n,mainMenu,insertionMenu,deletionMenu,id;
                ListNode *current;
                mainMenu:
                    cout << endl;
                    cout << "\t\t\t\t--------------------" << endl;
                    cout << "\t\t\t\t      MAIN MENU     " << endl;
                    cout << "\t\t\t\t--------------------" << endl << endl;
                    cout << "Enter 1  : Create list of donor details" << endl;
                    cout << "Enter 2  : Insertion of a donor details" << endl;
                    cout << "Enter 3  : Deletion of a donor details" << endl;
                    cout << "Enter 4  : Searching for a donor" << endl;
                    cout << "Enter 5  : Displaying all donor lists" << endl;
                    cout << "Enter 6  : Displaying total signed up ID" << endl;
                    cout << "Enter 7  : Displaying total logged in ID" << endl;
                    cout << "Enter 8  : Displaying total Donor number" << endl;
                    cout << "Enter 9  : Displaying all donor list after sorting" << endl;
                    cout << "Enter 10 : Exit" << endl << endl;

                    cout << "Enter your choice : ";
                    cin >> mainMenu;
                    while(mainMenu!=1 && mainMenu!=2 && mainMenu!=3 && mainMenu!=4 && mainMenu!=5 && mainMenu!=6 && mainMenu!=7 && mainMenu!=8 && mainMenu!=9 && mainMenu!=10)
                    {
                        cout << "ERROR!!! Please select a valid key." << endl << endl;
                        cout << "Enter your choice : ";
                        cin >> mainMenu;
                    }

                    switch(mainMenu)
                    {
                    case 1:
                        cout << endl << "How many donor details you will enter initially(in number) : ";
                        cin >> n;
                        while(n<=0)
                        {
                            cout << "ERROR!!! You have to enter a positive integer number." << endl << endl;
                            cout << "How many donor details you will enter initially(in number) : ";
                            cin >> n;
                        }
                        CreateList(n);
                        goto mainMenu;
                    case 2:
                        cout << endl;
                        cout << "\t\t\t\t--------------------" << endl;
                        cout << "\t\t\t\t   INSERTION MENU   " << endl;
                        cout << "\t\t\t\t--------------------" << endl << endl;
                        cout << "Enter 1 : Insert a donor details at beginning" << endl;
                        cout << "Enter 2 : Insert a donor details at given position" << endl;
                        cout << "Enter 3 : Insert a donor details at end" << endl << endl;
                        cout << "Enter your choice : ";
                        cin >> insertionMenu;
                        while(insertionMenu!=1 && insertionMenu!=2 && insertionMenu!=3)
                        {
                            cout << "ERROR!!! Please select a valid option." << endl << endl;
                            cout << "Enter your choice : ";
                            cin >> insertionMenu;
                        }
                        switch(insertionMenu)
                        {
                        case 1:
                            insertFirst();
                            goto mainMenu;
                        case 2:
                            insertGivenPosition();
                            goto mainMenu;
                        case 3:
                            insertEnd();
                            goto mainMenu;
                        }
                    case 3:
                        cout << endl;
                        cout << "\t\t\t\t--------------------" << endl;
                        cout << "\t\t\t\t    DELETION MENU   " << endl;
                        cout << "\t\t\t\t--------------------" << endl << endl;
                        cout << "Enter 1 : Delete a donor details from beginning" << endl;
                        cout << "Enter 2 : Delete a donor details from given position" << endl;
                        cout << "Enter 3 : Delete a donor details from end" << endl;
                        cout << "Enter 4 : Delete a donor details based on ULAB ID" << endl << endl;
                        cout << "Enter your choice : ";
                        cin >> deletionMenu;
                        while(deletionMenu!=1 && deletionMenu!=2 && deletionMenu!=3 && deletionMenu!=4)
                        {
                            cout << "ERROR!!! Please select a valid key." << endl << endl;
                            cout << "Enter your choice : ";
                            cin >> deletionMenu;
                        }
                        switch(deletionMenu)
                        {
                        case 1:
                            deleteFirst();
                            goto mainMenu;
                        case 2:
                            deleteGivenPosition();
                            goto mainMenu;
                        case 3:
                            deleteEnd();
                            goto mainMenu;
                        case 4:
                            cout << endl << "Enter the ULAB ID you want to delete : ";
                            cin >> id;
                            if(isempty() == true)
                            {
                                cout << "List is Empty!!!" << endl;
                                goto mainMenu;
                            }
                            else
                            {
                                current = Head;
                                while(current->id != id)
                                {
                                    if(current->next == NULL)
                                    {
                                        cout << endl << "ID not found!!!" << endl;
                                        goto mainMenu;
                                    }
                                    else
                                    {
                                        previous = current;
                                        current = current->next;
                                    }
                                }
                                deleteBasedonStudentID(current);
                                goto mainMenu;
                            }
                        }
                    case 4:
                        cout << endl << "Enter the Blood group you want to search : ";
                        fflush(stdin);
                        getline(cin,blood);
                        if(isempty() == true)
                        {
                            cout << "List is Empty!!!" << endl;
                            goto mainMenu;
                        }
                        else
                        {
                            searchNode(blood);
                            goto mainMenu;
                        }
                    case 5:
                        cout << endl << "From Running Program : " << endl;
                        showlist();
                        cout << endl << "From File Reading : " << endl;
                        totaldonornumber();
                        totaldonorlist();
                        cout << endl << "From File Reading : " << endl;
                        totalremoveddonornumber();
                        totalremoveddonorlist();
                        goto mainMenu;
                    case 6:
                        totalnodeuserid();
                        goto mainMenu;
                    case 7:
                        totalnodeloginid();
                        goto mainMenu;
                    case 8:
                        cout << endl << "From Running program : " << endl << "Donor Number : " << counter;
                        cout << endl << "From File Reading : " << endl;
                        totaldonornumber();
                        cout << endl << "From File Reading : " << endl;
                        totalremoveddonornumber();
                        goto mainMenu;
                    case 9:
                        bubblesort();
                        goto mainMenu;
                    case 10:
                        return -1;
                    }
                }
        }
    return 0;
}
