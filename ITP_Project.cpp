#include <iostream>
#include "clui.h"
using namespace std;
int main_menu()
{
    clear_screen();
    cout << "Here's a list of things you can do:" << endl;
    cout << "1)add a new task" << endl;
    cout << "2)see all tasks" << endl;
    cout << "3)exit" << endl;
    cout << endl;
    cout << "What do you want to do? enter the number:";
    int number;
    cin >> number;
    clear_screen();
    return number;
}
struct time
{
    int year;
    int month;
    int day;
};
struct task
{
    char title[100];
    char description[400];
    int importance;
    time deadline;
};
task *new_task()
{
    task *kaar = new task;
    cout << "Enter the title: ";
    cin.ignore();
    cin.getline((*kaar).title, 100);
    clear_screen();
    cout << "Enter the description: ";
    cin.getline((*kaar).description, 400);
    clear_screen();
    cout << "Enter the importance: ";
    cin >> (*kaar).importance;
    clear_screen();
    cout << "Enter deadline year: ";
    cin >> (*kaar).deadline.year;
    clear_screen();
    cout << "Enter deadline month: ";
    cin >> (*kaar).deadline.month;
    clear_screen();
    cout << "Enter deadline day: ";
    cin >> (*kaar).deadline.day;
    clear_screen();
    cout << " task added successfully";
    delay(2000);
    return kaar;
}
void insertion_Sort(task *array[], int size)
{
    task *key;
    for (int i = 1; i < size; ++i)
    {
        key = array[i];
        int j = i - 1;
        while (j >= 0 && (*array[j]).importance > (*key).importance)
        {
            array[j + 1] = array[j];
            j = j - 1;
        }
        array[j + 1] = key;
    }
}
int show_all_tasks(task *array[], int size)
{
    insertion_Sort(array, size);
    int cols = get_window_cols();
    clear_screen();
    cursor_to_pos(1, cols / 4);
    cout << "title";
    cursor_to_pos(1, cols / 2);
    cout << "importance";
    cursor_to_pos(1, 3 * cols / 4);
    cout << "deadline" << endl;
    for (int i = 0; i < size; ++i)
    {
        cursor_to_pos(i + 2, 1);
        cout << i + 1;
        int j = size - 1 - i;
        cursor_to_pos(i + 2, cols / 4);
        cout << (*array[j]).title;
        cursor_to_pos(i + 2, cols / 2);
        cout << (*array[j]).importance;
        cursor_to_pos(i + 2, 3 * cols / 4);
        cout << (*array[j]).deadline.year << "/" << (*array[j]).deadline.month << "/" << (*array[j]).deadline.day << endl;
    }
    cout << endl;
    cout << endl;
    cout << "if you want to see a task, enter its number here(enter 0 for going back to main menu) : ";
    int number;
    cin >> number;
    return number;
}
char show_one_task(task *kaar)
{
    clear_screen();
    cout << "title : " << (*kaar).title << endl;
    cout << "importance : " << (*kaar).importance << endl;
    cout << "description : " << (*kaar).description << endl;
    cout << "deadline : " << (*kaar).deadline.year << "/" << (*kaar).deadline.month << "/" << (*kaar).deadline.day << endl;
    cout << endl;
    cout << endl;
    cout << "if you want to delete this task, enter 'd' (ente 'b' for going to back menu) : ";
    char c;
    cin >> c;
    return c;
}
void delete_task(task *arrey[], int &size, int n)
{
    delete arrey[n - 1];
    for (int i = n - 1; i < size; ++i)
        arrey[i] = arrey[i + 1];
    --size;
    cout << "task was deleted";
    delay(2000);
}
int main()
{
    task *tasks[500];
    int i = 0;
    int size = 0;
    int j;
    while (true)
    {
        switch (main_menu())
        {
        case 1:
            tasks[i] = new_task();
            ++size;
            ++i;
            break;
        case 2:
            j = show_all_tasks(tasks, size);
            while (j != 0)
            {
                if (show_one_task(tasks[size - j]) == 'd')
                    delete_task(tasks, size, size + 1 - j);
                j = show_all_tasks(tasks, size);
            }
            break;
        case 3:
            for (int k = 0; k < size; ++k)
                delete tasks[k];
            return 0;
            break;
        }
    }
}