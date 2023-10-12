#include <vector>
#include <iostream>
#include <cstdlib> 
#include <Windows.h>
#include <fstream>
#include <conio.h>
using namespace std;
class Student
{
private:
    string name, roll_no, course, adress, email_id, contact_no;
public:
    void menu();
    void insert();
    void display();
    void modify();
    void search();
    void deleted();
};
void Student::menu()
{
    {
        menustart:
        system("cls");
        char x;
        int choice;
        cout << "Student Management System" << endl;
        cout << "1.������ �����" << endl;
        cout << "2.�������� ������" << endl;
        cout << "3.������ ������" << endl;
        cout << "4.����� ������" << endl;
        cout << "5.��������� ������" << endl;
        cout << "6.�����" << endl;
        cout << "=====================================" << endl;
        cout << "������� �����: "; std::cin >> choice;
        switch (choice)
        {
        case 1:
            do 
            {
                insert();
                cout << "������ ������ �������� (Y,N): ";
                cin >> x;
            } while (x == 'y' || x == 'Y');
            break;
        case 2:
            display();
            break;
        case 3:
            modify();
            break;
        case 4:
            search();
            break;
        case 5:
            deleted();
            break;
        case 6:
            exit(0);
            break;
        default:
            cout << "����������� ������ ���, ��������� �� ���" << endl;
                break;
        }
        _getch();
        goto menustart;
    };
}
void Student::insert() // add student details
{
    system("cls");
    fstream file;
    cout << "\t\t\t ������� ���������� ��� ��������:" << endl;
    cout << "\t\t\t ������ ��'�:"; cin >> name;
    cout << "\t\t\t ������ Roll No.:"; cin >> roll_no;
    cout << "\t\t\t ������ ����:"; cin >> course;
    cout << "\t\t\t ������ ���������� �����:"; cin >> email_id;
    cout << "\t\t\t ������ ����� ��������:"; cin >> contact_no;
    cout << "\t\t\t ������ ������:"; cin >> adress;
    file.open("studentRecord.txt", ios::app | ios:: out);
    file << " " << name << " " << roll_no << " " << course << " " << email_id << " " << contact_no << " " << adress << "\n";
    file.close();
}
void Student::display()
{
    system("cls");
    fstream file;
    int total = 0;
    cout << " \t\t\t ������ ��� ��������" << endl;
    file.open("studentRecord.txt", ios::in);
    if (!file)
    {

        cout << "\t\t\t ���� ����������" << endl;
        file.close();
    }
    else
    {
        file >> name >> roll_no >> course >> email_id >> contact_no >> adress;
        while (!file.eof())
        {
            cout << "\n\t\t\t ������� ����� " << total++ << endl;
            cout << "\n\t\t\t ��'�: " << name << endl;
            cout << "\t\t\t Roll No.: " << roll_no << endl;
            cout << "\t\t\t ����: " << course << endl;
            cout << "\t\t\t ���������� �����: " << email_id << endl;
            cout << "\t\t\t ����� ��������: " << contact_no << endl;
            cout << "\t\t\t ������: " << adress << endl;
            file >> name >> roll_no >> course >> email_id >> contact_no >> adress;
            if (total == 0)
            {
                cout << "\t\t\t ���� ����������" << endl;
            }
        }
    }
    file.close();

}
void Student::modify()
{
    system("cls");
    fstream file, file1;
    string rollno;
    int found = 0;
    cout << "\t\t\t\t ���� ������ ��������:" << endl;
    file.open("studentRecord.txt", ios::in);
    if (!file)
    {
        file.close();
    }
    else
    {
        cout << "\t\t\t ������ rollno �������� ��� ����� ������ ������:"; cin >> rollno;
        file1.open("Record.txt", ios::app | ios::out);
        file >> name >> roll_no >> course >> email_id >> contact_no >> adress;
        while (!file.eof())
        {
            if (rollno != roll_no)
            {
                file1 << " " << name << " " << roll_no << " " << course << " " << email_id << " " << contact_no
                    << " " << adress << "\n";
                 
            }
            else
            {
                cout << "\t\t\t ������� ���������� ��� ��������:" << endl;
                cout << "\t\t\t ������ ��'�:"; cin >> name;
                cout << "\t\t\t ������ Roll No.:"; cin >> roll_no;
                cout << "\t\t\t ������ ����:"; cin >> course;
                cout << "\t\t\t ������ ���������� �����:"; cin >> email_id;
                cout << "\t\t\t ������ ����� ��������:"; cin >> contact_no;
                cout << "\t\t\t ������ ������:"; cin >> adress;
                file1 << " " << name << " " << roll_no << " " << course << " " << email_id << " " << contact_no
                    << " " << adress << "\n";
                found++;
            }
            file >> name >> roll_no >> course >> email_id >> contact_no >> adress;
            if (found == 0)
            {
                cout << "\t\t\t �� �������� �������� � ������� Roll.No" << endl;

            }
        }
        file1.close();
        file.close();
        remove("studentRecord.txt");
        rename("Record.txt", "studentRecord.txt");


    }
}
void Student::search()
{
    system("cls");
    fstream file;
    string rollno;
    int found = 0;
    file.open("studentRecord.txt", ios::in);
    if (!file)
    {
        cout << "\t\t\t ���� �����" << endl;
    }
    else
    {
        cout << "\t\t\t ������ Roll.no �������� ��� ����� ������ ������:"; cin >> rollno;
        file >> name >> roll_no >> course >> email_id >> contact_no >> adress;
        while (!file.eof())
        {
            if (rollno == roll_no)
            {
                cout << "\n\t\t\t ��'�: " << name << endl;
                cout << "\t\t\t ����: " << course << endl;
                cout << "\t\t\t ���������� �����: " << email_id << endl;
                cout << "\t\t\t ����� ��������: " << contact_no << endl;
                cout << "\t\t\t ������: " << adress << endl;
                found++;
            }
            file >> name >> roll_no >> course >> email_id >> contact_no >> adress;
        }
        if (found == 0)
        {
            cout << "�������� � ������� Roll.no �� ����" << endl;
        }
        file.close();
    }
}
void Student::deleted()
{
    system("cls");
    fstream file1, file;
    string rollno;
    int found = 0;
    cout << "\t\t\t ��������� ��������:" << endl;
    file.open("studentRecord.txt", ios::in);
    if (!file)
    {
        cout << "\t\t\t ���� �����" << endl;
    }
    else 
    {
        cout << "\t\t\t ������ Roll.No �������� ����� �� ������ ��������: "; cin >> rollno;
        file1.open("Record.txt", ios::app | ios::out);
        file >> name >> roll_no >> course >> email_id >> contact_no >> adress;
        while(!file.eof())
        {
            found++;
            if (rollno != roll_no)
            {
                
                file1 << " " << name << " " << roll_no << " " << course << " " << email_id << " " << contact_no << " " << adress << "\n";

            }
            file >> name >> roll_no >> course >> email_id >> contact_no >> adress;
            
        }
        if (found == 0)
        {
            cout << "\t\t\t �� ���� �������� ����� �� ������ �������� " << endl;
        }
    }
    file1.close();
    file.close();
    remove("studentRecord.txt");
    rename("Record.txt", "studentRecord.txt");

}
int main()
{        
    SetConsoleOutputCP(1251);
    Student student;
    student.menu();
}

