#include <bits/stdc++.h>
#include <ostream>
using namespace std;
// making user class with his features
class User {
private:
    int id;
    string username;
    string pass;
    double balance;
public:
    // empty constructor
    User() {}
    // paramterize constructor
    User(int id, const string &username, const string &pass, double balance)
    : id(id), username(username), pass(pass), balance(balance) {}
    // setters and getters functions
    void setId(int id) {
        User::id = id;
    }
    void setUsername(const string &username) {
        User::username = username;
    }
    void setPass(const string &pass) {
        User::pass = pass;
    }
    void setBalance(double balance) {
        User::balance = balance;
    }
    int getId() const {
        return id;
    }
    const string &getUsername() const {
        return username;
    }
    const string &getPass() const {
        return pass;
    }
    double getBalance() const {
        return balance;
    }
    // functions to deal with withdrawing and deposting.
    void withdraw(double w) {
        if (w <= balance) { balance -= w; }
        else { cout << "Can't withdraw this value" << endl; }
    }
    void depost(double d) {
        balance += d;
        cout << "Current balance is: " << balance << endl;
    }
    // input Output && friend operators (operator overloading)
    friend ostream &operator<<(ostream &os, const User &user) {
        os << "id: " << user.id << " username: " << user.username
        << " pass: " << user.pass << " balance: " << user.balance<<endl;
        return os;
    }
    friend istream &operator>>(istream &is, User &user) {
        cout<<"id: "; is>>user.id;
        cout<<"username: "; is>>user.username;
        cout<<"pass: "; is>>user.pass;
        cout<<"balance: "; is>>user.balance;
        return is;
    } };
// making utility class for features.
class Utility
{
private:
    char *file;
    ofstream ofile;
    ifstream ifile;
    fstream iofile;
    User u;
public:
    Utility(char *file) : file(file) {
        cout<<"ATM System\n";
    }
    void insert()    // inserting data
{
        ofile.open(file, ios::app | ios::binary);
      cin>>u;
      ofile.write((char *)(&u) ,sizeof(u));
      ofile.close();
    }
    void read()    // reading(reporting) data
    {
        ifile.open(file);;
        while(ifile.read((char *)(&u), sizeof(u)))
        {
            if(u.getId()>0)cout<<u<<endl;
        }
    }
    void search(int id)    // searching for data
      {
        bool flag = 0;
        ifile.open(file);
        while(ifile.read((char *)(&u), sizeof(u)))
        {
            if(u.getId() == id && u.getId()>0){
            flag = 1;
            cout<<u<<endl;
            }
        }
        if (flag == false)cout<<"User not found\n";
        ifile.close();
    }
    void update(int id)    // updating data

    {   bool flag = 0;
        iofile.open(file,ios::in|ios::out|ios::binary);
        while(iofile.read((char *)(&u), sizeof(u))) {
            if (u.getId() == id && u.getId()>0) {
                flag = 1;
                cout << "Old Data: ";
                cout << u;
                cout << "New Data: ";
                cin >> u;
                int sz = -1 * sizeof(u);
                iofile.seekp(sz, ios::cur);
                iofile.write((char *)(&u), sizeof(u));
            }
        }
        if (flag == false)cout<<"User not found\n";
        else cout<<"User updated";
        ifile.close();
    }
    void Delete(int id)    // Deleting data
    {   bool flag = 0;
        iofile.open(file,ios::in|ios::out|ios::binary);
        while(iofile.read((char *)(&u), sizeof(u))) {
            if (u.getId() == id && u.getId()>0) {
                flag = 1;
                cout << "Old Data: ";
                cout << u;
                int sz = -1 * sizeof(u);
                iofile.seekp(sz, ios::cur);
                iofile.write((char *)(&u), sizeof(u));
            }
        }
        if (flag == false)cout<<"User not found\n";
        else cout<<"User Deleted: ";
        ifile.close();
    }
    // destructor
    ~Utility() {
        cout<<"  ::Thanks for using ATM System\n";
        delete file;
    }
};
int main ()
{
    // System Interface.
    Utility userUtility("userData.txt");
    cout<<"1- to insert new user\n";
    cout<<"2- to Report all users\n";
    cout<<"3- to update user\n";
    cout<<"4- to delete user\n";
    cout<<"--> ";
    int x; cin>>x;
    // exception handling (using try catch method).
    try{
        if (x<=0 || x>=5)
        throw "Enter Number from 1 to 4";
        else{
    int id;
    switch (x){
        case 1:
            userUtility.insert();
            break;
        case 2:
            userUtility.read();
            break;
        case 3:
            cout<<"Enter ID:"; cin>>id;
            userUtility.update(id);
            break;
        case 4:
            cout<<"Enter ID:"; cin>>id;
            userUtility.Delete(id);
            break;
    } } }
    catch (const char *e){cout<<e<<endl;}
    return 0;
}
