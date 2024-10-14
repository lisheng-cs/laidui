/*
 * @Descripttion:
 * @Author: laidui
 * @version:
 * @Date: 2024-10-13 00:18:48
 * @LastEditors: lai dui
 * @LastEditTime: 2024-10-13 23:11:45
 */
#include <iostream>

using namespace std;
typedef struct Node
{
    double val;
    int e;
    struct Node *next;
    Node(double a, int b)
    {
        val = a, e = b;
    }
} *node;
node head = nullptr;
double get(string s)
{
    double ans = 0;
    double e = 0.1;
    bool is_float = false;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '.')
        {
            is_float = true;
            continue;
        }
        if (!is_float)
        {
            ans = ans * 10 + (s[i] - '0');
        }
        else
        {
            ans = ans + (s[i] - '0') * e;
            e = e * 0.1;
        }
    }
    return ans;
}
void add(double a, int b)
{
    for (node p = head; p; p = p->next)
    {
        if (p->e == b)
        {
            p->val += a;
            return;
        }
    }
    node tmp = new Node(a, b);
    if (!head)
    {
        head = tmp;
    }
    else
    {
        tmp->next = head->next;
        head->next = tmp;
    }
}
void t_sort()
{
    for (node p = head; p; p = p->next)
    {
        node tmp = p;
        for (node q = p->next; q; q = q->next)
        {
            if (tmp->e > q->e)
            {
                tmp = q;
            }
        }
        swap(p->val, tmp->val);
        swap(p->e, tmp->e);
    }
}
void print()
{
    for (node p = head; p; p = p->next)
    {
        cout << p->val << ' ' << p->e << '\n';
    }
    cout << '\n';
}
void solve()
{
    bool is_first = true;
    int cnt = 0;
    while (1)
    {
        string s;
        getline(cin, s);
        if (s == "#")
        {
            cnt++;
        }
        else
        {
            int idx = s.find(' ');
            double a = get(s.substr(0, idx));
            int b = get(s.substr(idx + 1, (int)s.size()));
            // cout << "*" << a << '*' << b << '\n';
            if (cnt)
            {
                a = -a;
            }
            add(a, b);
        }
        if (cnt == 3)
        {
            break;
        }
    }
    t_sort();
    print();
}
int main()
{
    solve();
    return 0;
}