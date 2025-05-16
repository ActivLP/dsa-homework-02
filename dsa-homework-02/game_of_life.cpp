#include "game_of_life.h"
#include <ctime>     

game_of_life::game_of_life()
{
    srand(time(nullptr));

    for (unsigned int i = 0; i < ROWS; i++)
    {
        for (unsigned int j = 0; j < COLS; j++)
        {
            _generation[i][j] = rand() % 4 == 0; // 25% chance living organism in cell
        }
    }
}

bool game_of_life::cell_taken(int i, int j)
{
    if (i < 0 || i >= (int)ROWS || j < 0 || j >= (int)COLS) return false; // quick check limits

    return _generation[i][j];
}

void game_of_life::draw()
{
    for (unsigned int i = 0; i < ROWS; i++)
    {
        for (unsigned int j = 0; j < COLS; j++)
        {
            cout << (_generation[i][j] ? '*' : '-');
        }
        cout << endl;
    }
}

void game_of_life::next_generation()
{
    for (unsigned int i = 0; i < ROWS; i++)
    {
        for (unsigned int j = 0; j < COLS; j++)
        {
            int alive_neighbors = 0;

            for (int m = -1; m <= 1; m++)
            {
                for (int n = -1; n <= 1; n++)
                {
                    if (m == 0 && n == 0) continue; // skip the actual cell bc we don't care about
                    if (cell_taken(i + m, j + n)) ++alive_neighbors;
                }
            }

            if (_generation[i][j])
            {
                _next_generation[i][j] = (alive_neighbors == 2 || alive_neighbors == 3);
            }
            else { _next_generation[i][j] = (alive_neighbors == 3); }
        }
    }

    // apply next gen
    for (unsigned int i = 0; i < ROWS; i++)
    {
        for (unsigned int j = 0; j < COLS; j++)
        {
            _generation[i][j] = _next_generation[i][j];
        }
    }
}
