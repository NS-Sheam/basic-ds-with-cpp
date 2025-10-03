#include <bits/stdc++.h>
using namespace std;

class Student
{
public:
    string name;
    int roll;
    int marks;
    Student(string name, int roll, int marks)
    {
        this->name = name;
        this->roll = roll;
        this->marks = marks;
    }
};

class cmp
{
public:
    bool operator()(Student l, Student r)
    {
        if (l.marks == r.marks)
            return l.roll > r.roll;
        return l.marks < r.marks;
    }
};

int main()
{

    priority_queue<Student, vector<Student>, cmp> pq;
    int n;
    cin >> n;
    while (n--)
    {
        string name;
        int roll, marks;
        cin >> name >> roll >> marks;

        Student s(name, roll, marks);
        pq.push(s);
    }

    int q;
    cin >> q;
    while (q--)
    {
        int x;
        cin >> x;
        if (x == 0)
        {
            string s;
            int r, m;
            cin >> s >> r >> m;
            Student st(s, r, m);
            pq.push(st);
            Student cur = pq.top();
            cout << cur.name << " " << cur.roll << " " << cur.marks << endl;
        }
        else if (x == 1)
        {
            if (pq.empty())
                cout << "Empty" << endl;
            else
            {
                Student cur = pq.top();
                cout << cur.name << " " << cur.roll << " " << cur.marks << endl;
            }
        }
        else if (x == 2)
        {
            if (pq.empty())
                cout << "Empty" << endl;
            else
            {
                pq.pop();
                if (pq.empty())
                    cout << "Empty" << endl;
                else
                {
                    Student cur = pq.top();
                    cout << cur.name << " " << cur.roll << " " << cur.marks << endl;
                }
            }
        }
    }

    return 0;
}