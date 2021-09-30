/*
    AUTHOR: BlueKnight
    STARTED: 2021-09-19 16:44:46
*/
#include <bits/stdc++.h>
#include <conio.h>
#include <windows.h>
#include <time.h>

using namespace std;

long long int fact(int n)
{
    if (n == 1 || n == 0)
    {
        return 1;
    }
    return n * fact(n - 1);
}
void gotoxy(int x, int y)
{
    COORD c = {x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}
void delay(int number_of_seconds)
{
    int milli_seconds = 1000 * number_of_seconds;
    clock_t start_time = clock();
    while (clock() < start_time + milli_seconds)
        ;
}
void loading()
{
    system("cls");
    system("Color 7A");
    gotoxy(30, 12);
    cout << "FINDING THE BEST ROUTE FOR YOU...";
    int x = 0;
    for (int i = 0; i <= 10; i++)
    {
        gotoxy(30 + x, 13);
        delay(1);
        cout << "_";
        x += 2;
        gotoxy(52, 13);
        cout << i << "0%";
    }
    gotoxy(35, 14);
    cout << "FINALIZING DECISION";
    cout << "...";
    delay(1);
    delay(2);
    gotoxy(50, 50);
    system("cls");
    system("Color 70");
}
int main()
{
    system("Color 70");
    cout << "Voyager's Guide" << endl;
    int n;
    cout << "\nEnter the number of Places you will have to visit: ";
    cin >> n;
    vector<pair<double, double>> coordinates(n);
    int counter = 0;
    for (auto &i : coordinates)
    {
        int x, y;
        cout << "Enter the 'x' coordinate of Place " << counter + 1 << ": ";
        cin >> x;
        cout << "Enter the 'y' coordinate of Place " << counter + 1 << ": ";
        cin >> y;
        i.first = x;
        i.second = y;
        counter++;
        cout << "\n";
    }
    loading();
    vector<int> store(n, 0);
    counter = 0;
    for (auto &i : store)
    {
        i += counter + 1;
        counter++;
    }
    vector<vector<int>> permutations(fact(n));
    do
    {
        vector<int> temp;
        for (auto i : store)
        {
            temp.push_back(i);
        }
        permutations.push_back(temp);
    } while (next_permutation(store.begin(), store.end()));
    vector<double> distances;
    for (int i = 0; i < permutations.size(); i++)
    {
        double tempx = 0, tempy = 0, dist = 0;
        for (int j = 0; j < permutations[i].size(); j++)
        {
            double abscissa = coordinates[permutations[i][j] - 1].first;
            double ordinate = coordinates[permutations[i][j] - 1].second;
            dist += sqrt(pow((abs(ordinate - tempy)), 2) + pow((abs(abscissa - tempx)), 2));
            tempx = abscissa;
            tempy = ordinate;
            if (j == 0)
            {
                dist = 0;
            }
        }
        if (dist == 0)
        {
            continue;
        }
        distances.push_back(dist);
    }
    sort(distances.begin(), distances.end());
    double min_dist = distances[0];
    for (int i = 0; i < permutations.size(); i++)
    {
        double tempx = 0, tempy = 0, dist = 0;
        for (int j = 0; j < permutations[i].size(); j++)
        {
            double abscissa = coordinates[permutations[i][j] - 1].first;
            double ordinate = coordinates[permutations[i][j] - 1].second;
            dist += sqrt(pow((abs(ordinate - tempy)), 2) + pow((abs(abscissa - tempx)), 2));
            tempx = abscissa;
            tempy = ordinate;
            if (j == 0)
            {
                dist = 0;
            }
        }
        if (dist == min_dist)
        {
            for (int j = 0; j < permutations[i].size(); j++)
            {
                double abscissa = coordinates[permutations[i][j] - 1].first;
                double ordinate = coordinates[permutations[i][j] - 1].second;
                if (j == 0)
                {
                    cout << "Start from Place " << permutations[i][j] << endl;
                    cout << "Coordinates: (" << abscissa << ", " << ordinate << ")" << endl;
                    delay(1);
                    cout << endl;
                    continue;
                }
                if (j != permutations[i].size() - 1)
                {
                    cout << "Then go to Place " << permutations[i][j] << endl;
                    cout << "Coordinates: (" << abscissa << ", " << ordinate << ")" << endl;
                    delay(1);
                    cout << endl;
                }
                else
                {
                    cout << "And Finally to Place " << permutations[i][j] << endl;
                    cout << "Coordinates: (" << abscissa << ", " << ordinate << ")" << endl;
                    delay(1);
                    cout << endl;
                }
            }
            break;
        }
    }
    getch();
    return 0;
}
/*
    AUTHOR: BlueKnight
    ENDED: 2021-09-20 00:52:40
*/