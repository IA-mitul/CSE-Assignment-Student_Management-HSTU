#include<bits/stdc++.h>
#include<windows.h>
using namespace std;
class student_info {
    private:
        string name;
        int id;
        string dept;
        int session;
    public:
        void setData(string name,int id,string dept,int session){
            this->name=name;
            this->id=id;
            this->dept=dept;
            this->session=session;

                ofstream outfile("Student_Information.txt",ios::app);
            if(!outfile){
                cout<<"\tError : File can't open."<<endl;
            }
            else{
                outfile<<this->id<<" : "<<this->name<<" : "<<this->dept<<" : "<<this->session<<endl;
                cout<<"\tInformation is added."<<endl;
            }
            outfile.close();

            
            Sleep(1500);
        }

};
void New_Student(student_info si){
    string name;
    int id;
    string dept;
    int session;
        system("cls");
            cout<<"\tEnter Student Name: ";
            getline(cin,name);


            cout << "\tEnter Student id : ";
            cin >> id;

            cout << "\tEnter Department Name : ";
            cin>>dept;

            cout << "\tEnter Session : ";
            cin >> session;

            si.setData(name,id,dept,session);
            Sleep(1000);
}
void display_info(){
    system("cls");
    int s_id;
    cout<<"Enter student id : ";
    cin>>s_id;
    cin.ignore();

    ifstream infile("Student_Information.txt");
    if(!infile){
        cout<<"Error : File can't open"<<endl;
    }
    
    string line;
    bool found=false;
    while(getline(infile,line)){
        stringstream s_s;
        s_s<<line;
        int userID,userSession;
        string userName,userDept;
        char delimiter;
        s_s>>userID>>delimiter;
        getline(s_s,userName,delimiter);
        s_s>>userDept>>delimiter>>userSession;
        if(s_id==userID){
            found=true;
                cout<<"\tName : "<<userName<<endl;
                cout<<"\tID : "<<userID<<endl;
                cout<<"\tDepartment : "<<userDept<<endl;
                cout<<"\tSession : "<<userSession<<endl;
                Sleep(5000);
            break;
        }
        }
    if(!found){
        cout<<"\tStudent information don't exist.";
    }
    infile.close();

}

int main(){
    student_info s1;
    bool exit=false;
    while(!exit){
    system("cls");
    cout<<"\tStudent Management -- HSTU"<<endl;
    cout<<"\t___________________________"<<endl<<endl;
    int choice;
    cout<<"\t1. Add New Student Information."<<endl;
    cout<<"\t2. View Student Profile."<<endl;
    cout<<"\t3. Exit."<<endl;
    cout<<"\tEnter your Choice : ";
    cin>>choice;
    cin.ignore();

    if(choice==1){
        New_Student(s1);
    }
    else if(choice==2){
        display_info();
    }
    else if(choice==3){
        system("cls");
        exit=true;
        cout<<"Thanks for visiting"<<endl;
        Sleep(2000);
    }
    else{
    cout<<"Enter a valid option.";
    }

    Sleep(1000);
    }



    return 0;
}