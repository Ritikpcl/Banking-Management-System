                  
                                      /*  BANK MANAGEMENT SYSTEM  */
    

#include <iostream>
#include <conio.h>
using namespace std; 

class User{
    string name, ID, address;
    int contact, cash ,icash;
    int record1[100];
    int record2[100];
    int record3[100]={0};
    int top1=-1;
    int top2=-1;
    int top3=-1;
    User *next;
    public:
    void Options();
    void User_data();
    void Display();
    void Update_data();
    void search();
    void Transactions();
    void Delete_acc();
    void Mini_statement();
};
User *head = NULL;
User *tail = NULL;
string id;
int total = 0;

int main(){
    User u;
    u.Options();
    return 0;
}

void User ::Options(){
    char ch;
    cout <<"!!.....BANK MANAGEMENT SYSTEM.....!!   "<<endl;
    while (1){
        cout <<endl<< "!!...Choose Option...!!" << endl;
        cout << "1. Create new account" << endl;
        cout << "2. View User list" << endl;
        cout << "3. Update information of an existing account" << endl;
        cout << "4. Check the details of an existing account" << endl;
        cout << "5. Perform transaction" << endl;
        cout << "6. Remove an existing account" << endl;
        cout << "7. View Mini Statement " << endl;
        cout << "8. Exit" << endl;
        ch = getch();
        system("CLS");

        switch (ch){
        case '1':
            User::User_data();
            break;

        case '2':
            if (total == 0)
            cout << "No data is entered" << endl;
            else
            User::Display();
            break;

        case '3':
            if (total == 0)
            cout << "No data is entered" << endl;
            else
            User::Update_data();
            break;

        case '4':
            if (total == 0)
            cout << "No data is entered" << endl;
            else
            User::search();
            break;

        case '5':
            if (total == 0)
            cout << "No data is entered" << endl;
            else
            User::Transactions();
            break;

        case '6':
            if (total == 0)
            cout << "No data is entered" << endl;
            else
            User::Delete_acc();
            break;
        case '7':
            if (total == 0)
            cout << "No data is entered" << endl;
            else
            User::Mini_statement();
            break;

        case '8':
            exit(0);
            break;

        default:
            cout << "Invalid input" << endl;
            break;
        }
    }
}

void User::User_data(){
    User *newuser = new User;
    newuser->next = NULL;

    if (head == NULL && tail == NULL){head = tail = newuser;}
    else{tail->next = newuser;}
        tail = newuser;

        cout << "Enter data of User " << total + 1 << endl;
        cout << "Enter name: ";
        cin >> newuser->name;
        cout << "ID: ";
        cin >> newuser->ID;
        cout << "Address: ";
        cin >> newuser->address;
        cout << "Contact: ";
        cin >> newuser->contact;
        cout << "Total Cash: ";
        cin >> newuser->cash;
        cout << "Creating account ";
        cout << endl<< "Your account created successfully .... !! "<<endl<<endl;
        newuser->icash = newuser->cash;
        total++;
}

void User::Display(){
    User *temp;
    temp = head;
    int i = 0;

    while (temp != NULL){
        cout << "Data of User " << ++i << endl;
        cout << "Name: " << temp->name << endl;
        cout << "ID: " << temp->ID << endl;
        cout << "Address: " << temp->address << endl;
        cout << "Contact: " << temp->contact << endl;
        cout << "Cash: " << temp->cash << endl<<endl<<endl;
        temp = temp->next;
    }
}

void User::Update_data(){
    cout << "Enter id of User whose data you want to Update " << endl;
    cin >> id;

    User *temp;
    temp = head;
    int i = 0;

    while (temp != NULL){
        if (id == temp->ID){
            cout << "Previous data" << endl;
            cout << "Data of User " << ++i << endl;
            cout << "Name: " << temp->name << endl;
            cout << "ID: " << temp->ID << endl;
            cout << "Address: " << temp->address << endl;
            cout << "Contact: " << temp->contact << endl;
            cout << "Cash: " << temp->cash << endl;
            cout << "\nEnter new data" << endl;
            cout << "Enter name: ";
            cin >> temp->name;
            cout << "ID: ";
            cin >> temp->ID;
            cout << "Address: ";
            cin >> temp->address;
            cout << "Contact: ";
            cin >> temp->contact;
            cout << "Total Cash: ";
            cin >> temp->cash;
            break;
        }
        temp = temp->next;

        if (i == total - 1)
        cout << "No such record found" << endl;
    }
}

void User::search(){
    cout << "Enter id of student those data you want to search" << endl;
    cin >> id;
    User *temp;
    temp = head;

    while (temp != NULL){
        int i = 0;
        if (id == temp->ID){
            cout << "Name: " << temp->name << endl;
            cout << "ID: " << temp->ID << endl;
            cout << "Address: " << temp->address << endl;
            cout << "Contact: " << temp->contact << endl;
            cout << "Cash: " << temp->cash << endl;
            break;
        }
        temp = temp->next;
        i++;

        if (i == total)
        cout << "No such record found" << endl;
    }
}

void User::Transactions(){
    int cash;
    char ch;
    cout << "Enter id of user whose data you want to transaction" << endl;
    cin >> id;
    User *temp;
    temp = head;

    while (temp != NULL){
        int i = 0;
        if (id == temp->ID){
            cout << "Name: " << temp->name << endl;
            cout << "Address: " << temp->address << endl;
            cout << "Contact: " << temp->contact << endl;
            cout << "Existing Cash " << temp->cash << endl<<endl;
            cout << "Press 1 to deposit" << endl;
            cout << "Press 2 to withdraw" << endl;
            ch = getch();
            switch (ch){
            case '1':
                cout << "How much cash you want to deposit ?" << endl;
                cin >> cash;
                temp->cash += cash;
                (temp->top1)++;(temp->top2)++;(temp->top3)++;
                temp->record1[temp->top1] = 1;
                temp->record2[temp->top2] = cash;
                temp->record3[temp->top3] = temp->cash;
                cout << "Your new cash is " << temp->cash << endl;
                break;
            case '2':
            back:
                cout << "How much cash you want to withdraw ?" << endl;
                cin >> cash;
                if (cash > temp->cash){
                    cout << "Your existing cash is just " << temp->cash << endl;
                    goto back;
                }
                temp->cash -= cash;
                (temp->top1)++;(temp->top2)++;(temp->top3)++;
                temp->record1[temp->top1] = 0;
                temp->record2[temp->top2] = cash;
                temp->record3[temp->top3] = temp->cash;
                cout << "Your new cash is " << temp->cash << endl;
                break;
            default:
                cout << "Invalid input" << endl;
                break;
            }
            break;
        }
        temp = temp->next;

        if (i == total - 1)
        cout << "No such record found" << endl;

        i++;

    }
}

void User::Delete_acc(){
    char ch;
    cout << "Press 1 to remove specific record" << endl;
    cout << "Press 2 to remove full record" << endl;
    ch = getch();
    switch (ch){
    case '1':
        cout << "Enter id of the user whose data you want to remove" << endl;
        cin >> id;
        User *temp;
        temp = head;
        while (temp != NULL){
            int i = 0;
            if (id == temp->ID){
                User *del;
                del = head;

                if(temp == head){
                    head = head->next;
                    free(temp);
                }
                else{
                while (del->next != temp)
                {
                    del = del->next;
                }
                del->next = temp->next;
                free(temp);
                }
                total--;
                cout << "Your required data is deleted" << endl;
                break;
            }
            temp = temp->next;

            if (i == total - 1)
            cout << "No such record found" << endl;

            i++;
        }
        break;

    case '2':
        total = 0;
        cout << "All record is deleted" << endl;
        break;

    default:
        cout << "Invalid Input" << endl;
        break;
    }
}

void User :: Mini_statement()
{
    cout << "Enter id of the user whose statement you want " << endl;
    cin >> id;
    User *temp;
    temp = head;

    while (temp != NULL){
        int i = 1;
        if (id == temp->ID){
            int x = temp->top1;
            int y = temp->top2;
            int z = temp->top3;
            cout << "Name: " << temp->name << endl;
            while(x > 0 && y > 0){
            if(temp->record1[x] == 1){
            cout << i << " |  Cash  : " <<temp->record3[z-1]<<  " |  Deposit  : "<< temp->record2[y] << " | Total : "<<temp->record3[z]<< endl;
            x--;y--;z--;i++;
            }
            else{
            cout << i << " |  Cash  : " << temp->record3[z-1] << " | Withdrawl : "<<temp->record2[y]<< " | Total : "<<temp->record3[z]<< endl;
            x--;y--;z--;i++;
            }
            }
            cout << i << " |  Cash  : " << temp->icash <<  " |  Deposit  : "<< temp->record2[y] << " | Total : "<<temp->record3[z]<< endl;
            break;
        }
        temp = temp->next;
        i++;

        if (i-1 == total)
        cout << "No such record found" << endl;
    }
}


