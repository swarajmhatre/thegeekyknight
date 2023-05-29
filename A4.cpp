#include <iostream>
#include <vector>
using namespace std;
class NQueensProblem
{
private:
    int n;
    vector<int> board;
    vector<vector<int>> solutions;

public:
    NQueensProblem(int size) : n(size), board(size, -1) {}

    vector<vector<int>> solveBacktracking()
    {
        solveBacktrackingHelper(0);
        return solutions;
    }

private:
    void solveBacktrackingHelper(int col)
    {
        if (col >= n)
        {
            solutions.push_back(board);
            return;
        }

        for (int row = 0; row < n; row++)
        {
            if (isSafe(row, col))
            {
                board[col] = row;
                solveBacktrackingHelper(col + 1);
                board[col] = -1;
            }
        }
    }

    bool isSafe(int row, int col)
    {
        for (int i = 0; i < col; i++)
        {
            if (board[i] == row || board[i] - row == i - col || board[i] - row == col - i)
            {
                return false;
            }
        }
        return true;
    }
};

int main()
{
    int n = 0;
    // Example usage for n = 4
    cout << "ENter the number of queens: ";
    cin >> n;

    NQueensProblem problem(n);
    vector<vector<int>> solutions = problem.solveBacktracking();

    cout << "Solutions:\n";
    for (const auto &solution : solutions)
    {
        for (int row = 0; row < n; row++)
        {
            for (int col = 0; col < n; col++)
            {
                if (solution[col] == row)
                {
                    cout << "Q ";
                }
                else
                {
                    cout << "- ";
                }
            }
            cout << '\n';
        }
        cout << '\n';
    }

    return 0;
}
