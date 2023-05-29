#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int INF = 1e9;
// Define the problem
int n;                    // Number of cities
vector<vector<int>> dist; // Distance between cities
// Define the state
struct State
{
    int cost;
    int city;
    vector<int> path;

    bool operator<(const State &other) const
    {
        return cost > other.cost;
    }
};
// Define the heuristic function
int heuristic(vector<bool> &visited, int city)
{
    int min_dist = INF;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            min_dist = min(min_dist, dist[city][i]);
        }
    }
    return min_dist;
}
// A* algorithm
int tsp_a_star(int start_city, vector<int> &path)
{
    priority_queue<State> pq;
    pq.push({0, start_city, {start_city}});
    while (!pq.empty())
    {
        State cur = pq.top();
        pq.pop();
        if (cur.path.size() == n)
        {
            path = cur.path;
            path.push_back(start_city);
            return cur.cost + dist[cur.city][start_city];
        }
        vector<bool> visited(n);
        for (int c : cur.path)
        {
            visited[c] = true;
        }
        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                int h = heuristic(visited, i);
                int new_cost = cur.cost + dist[cur.city][i] + h;
                vector<int> new_path = cur.path;
                new_path.push_back(i);
                pq.push({new_cost, i, new_path});
            }
        }
    }
    return -1; // No solution
}
// Print the path of vertices
void print_path(const vector<int> &path)
{
    for (int i = 0; i < path.size(); i++)
    {
        cout << path[i] + 1;
        if (i != (path.size() - 1))
            cout << " -> C";
    }
    cout << endl;
}
int main()
{
    cout << "Enter the number of cities: ";
    cin >> n;
    cout << "\nEnter the distance matrix:" << endl;
    dist.resize(n, vector<int>(n));
    cout << "TO: "
         << "     ";
    for (int i = 0; i < n; i++)
    {
        cout << "C" << i + 1 << "  ";
    }
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "from C" << i + 1 << "  ";
        for (int j = 0; j < n; j++)
        {
            cin >> dist[i][j];
        }
    }
    int start_city = 0;
    vector<int> path;
    int ans = tsp_a_star(start_city, path);
    cout << "\nShortest path vertices: C";
    print_path(path);
    cout << "Shortest path length: " << ans << endl;
    return 0;
}
