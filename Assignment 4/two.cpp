
#include <iostream>
using namespace std;
int size;
struct queue
{
    int data;
    struct queue *next;
} * front, *rear;
typedef struct queue queue;
void enqueue(int data)
{
    queue *new_node;
    new_node = new queue;
    new_node->data = data;
    if (front == NULL && rear == NULL)
    {
        front = rear = new_node;
        size++;
        new_node->next = NULL;
    }
    else
    {
        rear->next = new_node;
        new_node->next = NULL;
        rear = new_node;
        size++;
        cout << "Data added" << endl;
    }
}
void dequeue()
{
    if (front == NULL)
    {
        cout << "Queue is empty";
    }
    int data;
    data = front->data;
    queue *temp;
    temp = front;
    temp = temp->next;
    delete (front);
    front = temp;
    size--;
    cout << "Dequeue element=>" << data << endl;
}
void display()
{
    queue *f, *r;
    f = front;
    r = rear;
    if (f == NULL && r == NULL)
    {
        cout << "empty queue" << endl;
    }
    while (f != r)
    {
        cout << f->data << "=>";
        f = f->next;
    }
    cout << f->data << "=>NULL" << endl;
}
int main()
{
    int choice = 1, data;
    //  front =new queue;
    // rear= new queue;
    while (1)
    {
        cout << endl
             << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. Display" << endl;
        cout << "4. Size" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice";
        cin >> choice;
        switch (choice)
        {

        case 1:
            cout << "Enter the data";
            cin >> data;
            enqueue(data);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            cout << "Size of linked list=" << size;
            break;
        case 0:
            exit(0);
            break;
        default:
            cout << "Invalid case" << endl;
            break;
        }
    }
}