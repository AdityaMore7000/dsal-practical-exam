#include <bits/stdc++.h>
#include <fstream>
using namespace std;
fstream myfile;
class stud
{
public:
    int roll;
    string name;
};
void insert(stud st)
{
    myfile.open("./vedya.txt", ios::app);
    if (!myfile)
    {
        cout << "Error\n";
    }
    else
    {
        cout << "Enter name:\n";
        cin >> st.name;
        cout << "Enter roll number:\n";
        cin >> st.roll;
        myfile << st.name <<"  :-  "<< st.roll << '\n';
        myfile.close();
    }
}
void search(string name)
{
    myfile.open("./vedya.txt", ios::in);
    if (!myfile)
        cout << "arey vedya\n";
    else
    {
        string record;
        while (getline(myfile, record))
        {
            if (record.substr(0, name.length()) == name)
            {
                cout << record << "\n";
                return;
            }
        }
        cout << "Record not found\n";
        myfile.close();
    }
}
void display()
{
    myfile.open("./vedya.txt", ios::in);
    string record;
    if (!myfile)
        cout << "Arey vedya\n";
    else
    {
        while (getline(myfile, record))
        {
            cout << record << '\n';
        }
    }
    myfile.close();
}
int main()
{
    bool flag = 0;
    cin>>flag;
    stud first;
    stud second;
    stud third;
    insert(first);
    insert(second);
    insert(third);
    display();
    search("a");
    cout<<"Enter flag:\n";
    if(flag)
    remove("./vedya.txt");
}