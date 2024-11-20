#include    <iostream>
#include <vector>

using namespace std;

int visited[1001];
vector<int> v[1001];

void dfs(int x)
{
    visited[x] = 1;
    for(int tmp : v[x])
    {
        if(visited[tmp] == 0)
            dfs(tmp);
    }

}

int main()
{
    int n, m;
    int a, b;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    int count = 0;
    for (int i = 1; i <= n; i++)
        if (visited[i] == 0)
        {
            count++;
            dfs(i);
        }
    cout << count;
}
