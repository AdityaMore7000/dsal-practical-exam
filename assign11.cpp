#include <iostream>
#include <fstream>
#include <string>
using namespace std;


int main(){
    fstream MyFile;

    MyFile.open("./file2.txt",ios::app);

    if(!MyFile){
        cout<<"\nError in Opening the File\n";
    }
    else{
        cout<<"\nFile opened Successfully\n";
        
        int n;
        cout<<"Enter the no. of students: ";
        cin>>n;

        for(int i=0;i<n;i++){
            string name;
            int roll_no;
            cout<<"\nEnter the name: ";
            cin>>name;
            cout<<"\nEnter the roll no: ";
            cin>>roll_no;
            MyFile<<name<<"\t"<<roll_no<<endl;
        }
        MyFile.close();
    }

    char choice;
    cout<<"\nDo u want to Delete File? ";
    cin>>choice;
    if(choice == 'y'){
        remove("./file2.txt");
        cout<<"\nFile Deleted Successfully\n";

    }

    char choice2;
    cout<<"\nDo u want to Display the contents of File? ";
    cin>>choice2;
    if(choice2=='y'){

        string displayName, record;
        cout << "\nEnter the name of the student whose information you want : ";
        cin >> displayName;

        MyFile.open("./file2.txt",ios::in);
        if(!MyFile){
            cout<<"\nError in Opening the File\n";
        }
        else{
            cout<<"\nFile opened Successfully\n";

            while(getline(MyFile,record)){
                if(record.substr(0, displayName.length()) == displayName){
                    cout << "Details of student : " << record << endl;
                    break;
                }
            }

            MyFile.close();
        }
    }
  

  return 0;
}
