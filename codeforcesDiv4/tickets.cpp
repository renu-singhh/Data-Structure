#include <iostream>
using namespace std;

int countWinnerTriplets(int totalParticipants, int tickets[])
{
    int count = 0;

    for (int i = 0; i < totalParticipants - 2; i++)
    {
        for (int j = i + 1; j < totalParticipants - 1; j++)
        {
            for (int k = j + 1; k < totalParticipants; k++)
            {
                if (tickets[i] < tickets[j] && tickets[j] < tickets[k])
                {
                    count++;
                }
            }
        }
    }

    return count;
}

int main()
{
    int totalParticipants;
    cin >> totalParticipants;

    int tickets[totalParticipants];
    for (int i = 0; i < totalParticipants; i++)
    {
        cin >> tickets[i];
    }

    int result = countWinnerTriplets(totalParticipants, tickets);

    cout << result << endl;

    return 0;
}