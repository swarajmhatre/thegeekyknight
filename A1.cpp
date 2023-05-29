#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_map>
using namespace std;
// function to add an edge to the graph
void add_edge(vector<vector<int>> &adj_list, int u, int v)
{
  adj_list[u].push_back(v);
  adj_list[v].push_back(u); // for undirected graph
}
// BFS traversal of the graph
void bfs(vector<vector<int>> &adj_list, int start_node, int search_node)
{
  vector<bool> visited(adj_list.size(), false);
  queue<int> q;
  unordered_map<int, int> parent;
  visited[start_node] = true;
  parent[start_node] = -1;
  q.push(start_node);
  while (!q.empty())
  {
    int node = q.front();
    q.pop();
    for (int neighbor : adj_list[node])
    {
      if (!visited[neighbor])
      {
        visited[neighbor] = true;
        parent[neighbor] = node;
        q.push(neighbor);
      }
    }
  }
  if (!visited[search_node])
  {
    cout << "Search node not found" << endl;
    return;
  }
  vector<int> path;
  int node = search_node;
  while (node != -1)
  {
    path.push_back(node);
    node = parent[node];
  }
  cout << "BFS path from start node to search node: ";
  for (int i = path.size() - 1; i >= 0; i--)
  {
    cout << path[i] << " ";
  }
  cout << endl;
}
// DFS traversal of the graph
void dfs(vector<vector<int>> &adj_list, int start_node, int search_node)
{
  vector<bool> visited(adj_list.size(), false);
  stack<int> s;
  unordered_map<int, int> parent;
  visited[start_node] = true;
  parent[start_node] = -1;
  s.push(start_node);
  while (!s.empty())
  {
    int node = s.top();
    s.pop();
    for (int neighbor : adj_list[node])
    {
      if (!visited[neighbor])
      {
        visited[neighbor] = true;
        parent[neighbor] = node;
        s.push(neighbor);
      }
    }
  }
  if (!visited[search_node])
  {
    cout << "Target node not found" << endl;
    return;
  }
  vector<int> path;
  int node = search_node;
  while (node != -1)
  {
    path.push_back(node);
    node = parent[node];
  }
  cout << "DFS path from start node to Target node: ";
  for (int i = path.size() - 1; i >= 0; i--)
  {
    cout << path[i] << " ";
  }
  cout << endl;
}
int main()
{
  vector<vector<int>> adj_list;
  int n;
  cout << "Enter number of nodes in the graph: ";
  cin >> n;
  adj_list.resize(n);
  int m;
  cout << "Enter number of edges in the graph: ";
  cin >> m;
  int u, v;
  for (int i = 0; i < m; i++)
  {
    cout << "Enter the endpoints of edge " << i + 1 << ": ";
    cin >> u >> v;
    add_edge(adj_list, u, v);
  }
  int choice;
  choice = 1;
  vector<int> dfs_path, bfs_path;
  while (choice != 0)
  {
    cout << " Enter 0 to exit \n Enter 1 to perform DFS and 2 to perform BFS: ";
    cin >> choice;
    if (choice == 0)
    {
      cout << "\n exit";
      return 0;
    }
    int start_node = 0;
    int search_node;
    cout << "Enter the node to search i.e.Target: ";
    cin >> search_node;
    vector<int> path;
    if (choice == 1)
    {
      cout << "DFS traversal: ";
      dfs(adj_list, start_node, search_node);
    }
    else if (choice == 2)
    {
      cout << "BFS traversal: ";
      bfs(adj_list, start_node, search_node);
    }
    else
    {
      cout << "Invalid choice" << endl;
      return 1;
    }
    bool found = false;
    for (int i = 0; i < adj_list.size(); i++)
    {
      if (i == search_node)
      {
        found = true;
        break;
      }
    }
    if (found)
    {
      cout << "Vertex " << search_node << " found in the graph" << endl;
    }
    else
    {
      cout << "Vertex " << search_node << " not found in the graph" << endl;
    }
  }

  return 0;
}
