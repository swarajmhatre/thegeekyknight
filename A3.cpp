#include <algorithm>
#include <iostream>
using namespace std;
// A structure to represent a job
struct Job
{
    char id;    // Job Id
    int dead;   // Deadline of job
    int profit; // Profit if job is over before or on deadline
};
// Comparator function for sorting jobs
bool comparison(Job a, Job b)
{
    return (a.profit > b.profit);
}
// Returns maximum profit from jobs
void printJobScheduling(Job arr[], int n)
{
    // Sort all jobs according to decreasing order of profit
    sort(arr, arr + n, comparison);
    int result[n]; // To store result (Sequence of jobs)
    bool slot[n];  // To keep track of free time slots
    // Initialize all slots to be free
    for (int i = 0; i < n; i++)
    {
        slot[i] = false;
    }
    // Iterate through all given jobs
    for (int i = 0; i < n; i++)
    {

        // Find a free slot for this job (Note that we start
        // from the last possible slot)
        for (int j = min(n, arr[i].dead) - 1; j >= 0; j--)
        {
            // Free slot found
            if (slot[j] == false)
            {
                result[j] = i;  // Add this job to result
                slot[j] = true; // Make this slot occupied
                break;
            }
        }
    }
    // Print the result
    cout << "Job sequence for maximum profit: ";
    for (int i = 0; i < n; i++)
    {
        if (slot[i])
        {
            cout << arr[result[i]].id << " ";
        }
    }
    cout << endl;
}
// Driver's code
int main()
{
    int n;
    cout << "Enter the number of jobs: ";
    cin >> n;
    Job arr[n];
    cout << "Enter details for job: " << endl;
    cout << "\tId Dl Pr \n ";
    for (int i = 0; i < n; i++)
    {
        cout << "Job " << i << ": ";
        cin >> arr[i].id;
        cin >> arr[i].dead;
        cin >> arr[i].profit;
    }
    int choice;
    do
    {
        cout << "\nMenu:\n1. Print job sequence for maximum profit\n 2. Add a new job\n3. Exit\nEnter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            printJobScheduling(arr, n);
            break;
        case 2:
            cout << "Enter details for new job: " << endl;
            cout << "Id: ";
            cin >> arr[n].id;
            cout << "Deadline: ";
            cin >> arr[n].dead;
            cout << "Profit: ";
            cin >> arr[n].profit;
            n++;
            break;
        case 3:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice. Try again." << endl;
            break;
        }
    } while (choice != 3);
    return 0;
}