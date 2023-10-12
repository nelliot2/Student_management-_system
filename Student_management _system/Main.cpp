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
        cout << "1.Додати запис" << endl;
        cout << "2.Показати записи" << endl;
        cout << "3.Змінити записи" << endl;
        cout << "4.Пошук запису" << endl;
        cout << "5.Видалення запису" << endl;
        cout << "6.Вийти" << endl;
        cout << "=====================================" << endl;
        cout << "Виберіть опцію: "; std::cin >> choice;
        switch (choice)
        {
        case 1:
            do 
            {
                insert();
                cout << "Додати іншого студента (Y,N): ";
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
            cout << "Неправильно введені дані, спробуйте ще раз" << endl;
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
    cout << "\t\t\t Додайте інформацію про студента:" << endl;
    cout << "\t\t\t Введіть ім'я:"; cin >> name;
    cout << "\t\t\t Введіть Roll No.:"; cin >> roll_no;
    cout << "\t\t\t Введіть курс:"; cin >> course;
    cout << "\t\t\t Введіть електронну пошту:"; cin >> email_id;
    cout << "\t\t\t Введіть номер телефону:"; cin >> contact_no;
    cout << "\t\t\t Введіть адресу:"; cin >> adress;
    file.open("studentRecord.txt", ios::app | ios:: out);
    file << " " << name << " " << roll_no << " " << course << " " << email_id << " " << contact_no << " " << adress << "\n";
    file.close();
}
void Student::display()
{
    system("cls");
    fstream file;
    int total = 0;
    cout << " \t\t\t Записи про студентів" << endl;
    file.open("studentRecord.txt", ios::in);
    if (!file)
    {

        cout << "\t\t\t Немає інформації" << endl;
        file.close();
    }
    else
    {
        file >> name >> roll_no >> course >> email_id >> contact_no >> adress;
        while (!file.eof())
        {
            cout << "\n\t\t\t Студент номер " << total++ << endl;
            cout << "\n\t\t\t Ім'я: " << name << endl;
            cout << "\t\t\t Roll No.: " << roll_no << endl;
            cout << "\t\t\t Курс: " << course << endl;
            cout << "\t\t\t Електронна пошта: " << email_id << endl;
            cout << "\t\t\t Номер телефону: " << contact_no << endl;
            cout << "\t\t\t Адреса: " << adress << endl;
            file >> name >> roll_no >> course >> email_id >> contact_no >> adress;
            if (total == 0)
            {
                cout << "\t\t\t Немає інформації" << endl;
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
    cout << "\t\t\t\t Зміна данних студента:" << endl;
    file.open("studentRecord.txt", ios::in);
    if (!file)
    {
        file.close();
    }
    else
    {
        cout << "\t\t\t Введіть rollno студента дані якого хочете змінити:"; cin >> rollno;
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
                cout << "\t\t\t Додайте інформацію про студента:" << endl;
                cout << "\t\t\t Введіть ім'я:"; cin >> name;
                cout << "\t\t\t Введіть Roll No.:"; cin >> roll_no;
                cout << "\t\t\t Введіть курс:"; cin >> course;
                cout << "\t\t\t Введіть електронну пошту:"; cin >> email_id;
                cout << "\t\t\t Введіть номер телефону:"; cin >> contact_no;
                cout << "\t\t\t Введіть адресу:"; cin >> adress;
                file1 << " " << name << " " << roll_no << " " << course << " " << email_id << " " << contact_no
                    << " " << adress << "\n";
                found++;
            }
            file >> name >> roll_no >> course >> email_id >> contact_no >> adress;
            if (found == 0)
            {
                cout << "\t\t\t Не знайдено студента з подібним Roll.No" << endl;

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
        cout << "\t\t\t Немає даних" << endl;
    }
    else
    {
        cout << "\t\t\t Введіть Roll.no студента дані якого хочете знайти:"; cin >> rollno;
        file >> name >> roll_no >> course >> email_id >> contact_no >> adress;
        while (!file.eof())
        {
            if (rollno == roll_no)
            {
                cout << "\n\t\t\t Ім'я: " << name << endl;
                cout << "\t\t\t Курс: " << course << endl;
                cout << "\t\t\t Електронна пошта: " << email_id << endl;
                cout << "\t\t\t Номер телефону: " << contact_no << endl;
                cout << "\t\t\t Адреса: " << adress << endl;
                found++;
            }
            file >> name >> roll_no >> course >> email_id >> contact_no >> adress;
        }
        if (found == 0)
        {
            cout << "Студента з подібним Roll.no не існує" << endl;
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
    cout << "\t\t\t Видалення студента:" << endl;
    file.open("studentRecord.txt", ios::in);
    if (!file)
    {
        cout << "\t\t\t Немає даних" << endl;
    }
    else 
    {
        cout << "\t\t\t Введіть Roll.No студента якого ви хочете видалити: "; cin >> rollno;
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
            cout << "\t\t\t Не існує студента якого ви хочете видалити " << endl;
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

