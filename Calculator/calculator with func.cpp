#include <bits/stdc++.h>
using namespace std;
void inputnumbers(double &num1 , double &num2)
{
    while (true)
    {
    num1 = num2 =0;
    cout<<" \t\t\t\t\t Enter the two numbers please "<<endl;
    cin>>num1>>num2;
    if (cin.fail())
    {
        cout<<" \t\t\t\t\t Error,Enter two integer numbers please "<<endl;
        cin.clear();
        cin.ignore(10000,'\n');
    }
    else
        break;
    }
}
int menuioptions(int &choice)
{
    bool flag = true;
    while (flag)
    {
        choice=0;
    cout<<" \t\t\t\t\t 1. operation (+) "<<endl;
    cout<<" \t\t\t\t\t 2. operation (-) "<<endl;
    cout<<" \t\t\t\t\t 3. operation (*) "<<endl;
    cout<<" \t\t\t\t\t 4. operation (/) "<<endl;
    cout<<" \t\t\t\t\t 5. Enter the two numbers again"<<endl;
    cin>>choice;
    if (cin.fail())
    {
        cout<<" \t\t\t\t\t Enter valid number please "<<endl;
        cin.clear ();
        cin.ignore(10000,'\n');
    }
    else{
        return choice;
        flag = false;
}
}
}
bool addingfunc(double num1,double num2,double &result)
{
    result = num1 + num2 ;
    return true;
}
bool subfunc(double num1,double num2,double &result)
{
    result = num1 - num2 ;
    return true;
}
bool multifunc(double num1,double num2,double &result)
{
    result = num1 * num2 ;
    return true;
}
bool dividfunc(double num1,double num2,double &result)
{
    if (num2 == 0)
        {
        cout<<"Error , can't divide by zero "<<endl;
        return false;
        }
        else
    {
    result = num1 / num2 ;
    return true;
    }
}
void calculator()
{
    double num1 =0, num2=0 , result=0;
    int choice =0;
    bool finished  = false ;
    while (!finished)
    {
        inputnumbers(num1,num2);
        menuioptions(choice);
        if (choice == 5)        continue;
        if (choice == 1)
            finished = addingfunc(num1,num2,result);
        if (choice == 2)
            finished = subfunc(num1,num2,result);
        if (choice == 3)
            finished = multifunc(num1,num2,result);
        if (choice == 4)
            finished = dividfunc(num1,num2,result);
        if (finished)
            cout<<"The Result is "<<result<<endl;
    }

}
int main ()
{
    cout<<" \t\t\t\t\t*** WELCOME TO THE CALCULATOR ***\n\n\n "<<endl;
    calculator();
    return 0;
}
