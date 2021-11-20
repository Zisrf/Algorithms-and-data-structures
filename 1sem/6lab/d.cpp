#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

map<string, int> index;

int main()
{
    ifstream cin("quack.in");
    ofstream cout("quack.out");

    queue<unsigned short> q;
    vector<unsigned short> r(26);

    vector<string> comand;
    string cmd;
    int i = 0;
    while (cin >> cmd)
    {
        if (cmd[0] == ':')
            index[cmd.substr(1, cmd.size() - 1)] = i;
        comand.push_back(cmd);
        ++i;
    }

    unsigned short x, y;
    for (i = 0; i < comand.size();)
    {
        cmd = comand[i];
        switch (cmd[0])
        {
        case '+':
            x = q.front();
            q.pop();
            y = q.front();
            q.pop();
            q.push(x + y);
            break;
        case '-':
            x = q.front();
            q.pop();
            y = q.front();
            q.pop();
            q.push(x - y);
            break;
        case '*':
            x = q.front();
            q.pop();
            y = q.front();
            q.pop();
            q.push(x * y);
            break;
        case '/':
            x = q.front();
            q.pop();
            y = q.front();
            q.pop();
            if (y != 0)
                q.push(x / y);
            else
                q.push(0);
            break;
        case '%':
            x = q.front();
            q.pop();
            y = q.front();
            q.pop();
            if (y != 0)
                q.push(x % y);
            else
                q.push(0);
            break;
        case '>':
            r[cmd[1] - 'a'] = q.front();
            q.pop();
            break;
        case '<':
            q.push(r[cmd[1] - 'a']);
            break;
        case 'P':
            if (cmd.size() == 1)
            {
                cout << q.front() << endl;
                q.pop();
            }
            else
            {
                cout << r[cmd[1] - 'a'] << endl;
            }
            break;
        case 'C':
            if (cmd.size() == 1)
            {
                cout << (char)(q.front() % 256);
                q.pop();
            }
            else
            {
                cout << (char)(r[cmd[1] - 'a'] % 256);
            }
            break;
        case ':':
            break;
        case 'J':
            i = index[cmd.substr(1, cmd.size() - 1)];
            continue;
        case 'Z':
            if (r[cmd[1] - 'a'] == 0)
            {
                i = index[cmd.substr(2, cmd.size() - 2)];
                continue;
            }
            break;
        case 'E':
            if (r[cmd[1] - 'a'] == r[cmd[2] - 'a'])
            {
                i = index[cmd.substr(3, cmd.size() - 3)];
                continue;
            }
            break;
        case 'G':
            if (r[cmd[1] - 'a'] > r[cmd[2] - 'a'])
            {
                i = index[cmd.substr(3, cmd.size() - 3)];
                continue;
            }
            break;
        case 'Q':
            cin.close();
            cout.close();
            return 0;
        default:
            q.push(atoi(cmd.data()));
            break;
        }
        ++i;
    }

    cin.close();
    cout.close();
    return 0;
}