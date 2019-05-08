/**
 * Implements Game of Fifteen (generalized to d x d).
 *
 * Usage: fifteen d
 *
 * whereby the board's dimensions are to be d x d,
 * where d must be in [DIM_MIN,DIM_MAX]
 *
 */

#define _XOPEN_SOURCE 500

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// constants
#define DIM_MIN 3
#define DIM_MAX 9

// ansi escape sequence to print grid color
// replace the number beteen [ and m with 31 for red, 32 for green, 33 for brown,
// 34 for blue, 35 for purple, 36 for cyan, 37 for gray
#define COLOR "\033[01;32m"

// board
int board[DIM_MAX][DIM_MAX];

// dimensions
int d;

// saved locations of the blank tile
int blank_row;
int blank_col;

// prototypes
void clear(void);
void greet(void);
void init(void);
void draw(void);
bool move(int tile);
bool won(void);
void swap(int *a, int *b);
void print_grid_row(int d);
void print_tile(int tile);

int main(int argc, string argv[])
{
    // ensure proper usage
    if (argc != 2)
    {
        printf("Usage: fifteen d\n");
        return 1;
    }

    // ensure valid dimensions
    d = atoi(argv[1]);
    if (d < DIM_MIN || d > DIM_MAX)
    {
        printf("Board must be between %i x %i and %i x %i, inclusive.\n",
            DIM_MIN, DIM_MIN, DIM_MAX, DIM_MAX);
        return 2;
    }

    // open log
    FILE *file = fopen("log.txt", "w");
    if (file == NULL)
    {
        return 3;
    }

    // greet user with instructions
    greet();

    // initialize the board
    init();

    // accept moves until game is won
    while (true)
    {
        // clear the screen
        clear();

        // draw the current state of the board
        draw();

        // log the current state of the board (for testing)
        for (int i = 0; i < d; i++)
        {
            for (int j = 0; j < d; j++)
            {
                fprintf(file, "%i", board[i][j]);
                if (j < d - 1)
                {
                    fprintf(file, "|");
                }
            }
            fprintf(file, "\n");
        }
        fflush(file);

        // check for win
        if (won())
        {
            printf("ftw!\n");
            break;
        }

        // prompt for move
        printf("Tile to move: ");
        int tile = get_int();

        // quit if user inputs 0 (for testing)
        if (tile == 0)
        {
            break;
        }

        // log move (for testing)
        fprintf(file, "%i\n", tile);
        fflush(file);

        // move if possible, else report illegality
        if (!move(tile))
        {
            printf("\nIllegal move.\n");
            usleep(500000);
        }

        // sleep thread for animation's sake
        usleep(50000);
    }

    // close log
    fclose(file);

    // success
    return 0;
}

/**
 * Clears screen using ANSI escape sequences.
 */
void clear(void)
{
    printf("\033[2J");
    printf("\033[%d;%dH", 0, 0);
}

/**
 * Greets player.
 */
void greet(void)
{
    clear();
    printf("WELCOME TO GAME OF FIFTEEN\n");
    usleep(2000000);
}

/**
 * Initializes the game's board with tiles numbered 1 through d*d - 1
 * (i.e., fills 2D array with values but does not actually print them).
 */
void init(void)
{
    int count = 0;
    for(int i = 0; i < d; i++)
    {
        for(int j = 0; j < d; j++)
        {
            count++;
            board[i][j] = (d*d) - count; // fill the borad with numbers in reverse order
        }

        if (d%2 == 0) // Special condition in case d is even (swap the tiles number 1 and number 2)
        {
            int temp = 0;
            temp = board[d-1][d-2];
            board[d-1][d-2] = board[d-1][d-3];
            board[d-1][d-3] = temp;
        }

    }
}

/**
 * Prints the board in its current state.
 */
void draw(void)
{
    int count = 0;
    for (int i = 0; i < d; i++)
    {
        for (int j = 0; j < d; j++)
        {
            count++;
            if (board[i][j] > 0)
            {
            printf("\033[01;32m|%2d ", board[i][j]); // '\033[01;32m' will print in green color
            }
            else if (board[i][j] == 0)
            {
                printf("| _ "); // print the blank tile
            }
        }
        printf("\n____________\n\n"); // print the space and the devider between the rows
    }
}

/**
 * If tile borders empty space, moves tile and returns true, else
 * returns false.
 */
bool move(int tile)
{
    if (tile < 1 || tile > (d*d) - 1) // check if the user wants to move the blank tile or a tile that is not on the board
    {
        return false;
    }
    else
    {
        for (int i = 0; i < d; i++)
        {
            for (int j = 0; j < d; j++)
            {
                if (tile == board[i][j])
                {
                    if (i+1 < d && board[i+1][j] == 0) // move the blank tile left and check if the location [i+1] is on the board
                    {
                        int swap = board[i][j];
                        board[i][j] = board[i+1][j];
                        board[i+1][j] = swap;
                        return true;
                    }
                    else if (i-1 >= 0 && board[i-1][j] == 0) // move the blank tile right and check if the location [i-1] is on the board
                    {
                        int swap = board[i][j];
                        board[i][j] = board[i-1][j];
                        board[i-1][j] = swap;
                        return true;
                    }
                    else if (j+1 < d && board[i][j+1] == 0) // move the blank tile down and check if the location [j+1] is on the board
                    {
                        int swap = board[i][j];
                        board[i][j] = board[i][j+1];
                        board[i][j+1] = swap;
                        return true;
                    }
                    else if (j-1 >= 0 && board[i][j-1] == 0) // move the blank tile up and check if the location [j-1] is on the board
                    {
                        int swap = board[i][j];
                        board[i][j] = board[i][j-1];
                        board[i][j-1] = swap;
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

/**
 * Returns true if game is won (i.e., board is in winning configuration),
 * else false.
 */
bool won(void)
{
    int count = 1; // The counter will make sure the numbers are in order
    for (int i = 0; i < d; i++)
    {
        for (int j = 0; j < d; j++)
        {
            if (board[i][j] != 0 && board[i][j] != count) // Check if the current tile isn't the blank tile and if the tile doesn't match the count (if the tile matches the count, it means that the numbers are in order)
            {
               return false; // The numbers are not in order! The game continues!
            }
            count++; // Check if the next tile is in order
        }
    }
    return true; // If all the numbers are in order, the game is won!
}
