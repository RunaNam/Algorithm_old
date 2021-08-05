using namespace std;

vector<int> key;
int T, n, d;

void find_friend()
{
    for (int i = 0; i < n; i++)
    {
        key.push_back(i);
    }
}

int main(int argc, char **argv)
{
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        cin >> n;
        find_friend();
        for (int j = 0; j < n; j++)
        {
            cin >> d;
            auto it = find(key.begin(), key.end(), d + j);
            if (it != key.end())
            {
                key.erase(it);
            }
            else if (j + d < n && find(key.begin(), key.end(), j) != key.end())
            {
                it = find(key.begin(), key.end(), j);
                key.erase(it);
            }
        }
        cout << "Case #" << i + 1 << "\n";
        for (int i = 0; i < key.size(); i++)
        {
            cout << key[i] << '\n';
        }
        key.clear();
        cout << '\n';
    }

    return 0;
}