#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

// Max number of candidates
#define MAX 9

// preferences[i][j] is number of voters who prefer i over j
int preferences[MAX][MAX];

// locked[i][j] means i is locked in over j
bool locked[MAX][MAX];

// Each pair has a winner, loser
typedef struct
{
    int winner;
    int loser;
} pair;

// Array of candidates
string candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];

int pair_count;
int candidate_count;

// Function prototypes
bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void quick_sort(pair arr[], int low, int high);
int partition(pair arr[], int low, int high);
void lock_pairs(void);
bool dfs(int node, bool visited[], bool recStack[]);
bool creates_cycle(int winner, int loser);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: tideman [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i] = argv[i + 1];
    }

    // Clear graph of locked in pairs
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            locked[i][j] = false;
        }
    }

    pair_count = 0;
    int voter_count = get_int("Number of voters: ");

    // Query for votes
    for (int i = 0; i < voter_count; i++)
    {
        // ranks[i] is voter's ith preference
        int ranks[candidate_count];

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            if (!vote(j, name, ranks))
            {
                printf("Invalid vote.\n");
                return 3;
            }
        }

        record_preferences(ranks);

        printf("\n");
    }

    add_pairs();
    sort_pairs();
    lock_pairs();
    print_winner();
    return 0;
}

// Update ranks given a new vote
bool vote(int rank, string name, int ranks[])
{
    for(int i=0; i<candidate_count; i++){
        if(strcmp(candidates[i], name) == 0){
            ranks[rank] = i;
            return true;
        }
    }
    return false;
}

// Update preferences given one voter's ranks
void record_preferences(int ranks[])
{
    for(int i=0; i<candidate_count; i++){
        for(int j=i+1; j<candidate_count; j++){
            preferences[ranks[i]][ranks[j]]++;
        }
    }
    return;
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    //global variable
    pair_count=0;
    for(int i=0; i<candidate_count; i++){
        for(int j=0; j<candidate_count; j++){
            if(i != j && preferences[i][j] > preferences[j][i]){
                pairs[pair_count].winner = i;
                pairs[pair_count].loser = j;
                pair_count++;
            }
        }
    }
    return;
}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
    quick_sort(pairs, 0, pair_count - 1);
    return;
}

//HELPER FUNCTIONS TO SORT PAIRS - helper function1
void quick_sort(pair arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quick_sort(arr, low, pi - 1);
        quick_sort(arr, pi + 1, high);
    }
}

//HELPER FUNCTIONS TO SORT PAIRS - helper function2
int partition(pair arr[], int low, int high) {
    pair pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (preferences[arr[j].winner][arr[j].loser] > preferences[pivot.winner][pivot.loser]) {
            i++;
            pair temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    pair temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return (i + 1);
}

// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
    for (int i = 0; i < pair_count; i++)
    {
        if (!creates_cycle(pairs[i].winner, pairs[i].loser))
        {
            locked[pairs[i].winner][pairs[i].loser] = true;
        }
    }
    return;
}

// Check if locking a pair creates a cycle - helper function3
bool creates_cycle(int winner, int loser)
{
    bool visited[MAX] = { false };
    bool recStack[MAX] = { false };

    locked[winner][loser] = true;

    for (int i = 0; i < candidate_count; i++)
    {
        if (dfs(i, visited, recStack))
        {
            locked[winner][loser] = false;
            return true;
        }
    }

    locked[winner][loser] = false;
    return false;
}


// Check for cycles using DFS  - helper function4
bool dfs(int node, bool visited[], bool recStack[])
{
    if (!visited[node])
    {
        visited[node] = true;
        recStack[node] = true;

        for (int i = 0; i < candidate_count; i++)
        {
            if (locked[node][i])
            {
                if (!visited[i] && dfs(i, visited, recStack))
                {
                    return true;
                }
                else if (recStack[i])
                {
                    return true;
                }
            }
        }
    }
    recStack[node] = false;
    return false;
}

// Print the winner of the election
void print_winner(void)
{
    for (int i = 0; i < candidate_count; i++)
    {
        bool source = true;
        for (int j = 0; j < candidate_count; j++)
        {
            if (locked[j][i])
            {
                source = false;
                break;
            }
        }
        if (source)
        {
            printf("%s\n", candidates[i]);
            return;
        }
    }
    return;
}
