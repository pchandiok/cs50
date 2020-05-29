#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct
{
    string name;
    int votes;
}
candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes
bool vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
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
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int voter_count = get_int("Number of voters: ");

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        // Check for invalid vote
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }

    // Display winner of election
    print_winner();
}

// Update vote totals given a new vote
bool vote(string name)
{
    // Adds candidates votes
    for(int i=0, n=candidate_count-1;i<=n;i++)
    {
	    if((strcmp(name, candidates[i].name))==0)
	    {
		    candidates[i].votes += 1;
		    return true;
	    }
    }

    return false;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    // TODO
    char *name[candidate_count];
    int winner_count=0;
    int largest = candidates[0].votes;

//Searches for the largest number in the vote count and assign it to largest
    for(int j=0;j<=candidate_count-1;j++)
    {
        if(candidates[j].votes > largest)
        {
            largest = candidates[j].votes;
        }
    }

//Adds the winner or winners in the name array
    for(int i=0,n=candidate_count-1;i<=n;i++)
    {
        if(candidates[i].votes == largest)
        {
            name[winner_count] = candidates[i].name;
            winner_count++;
        }
    }

//display the list of winners
    for(int i=0;i<winner_count;i++)
    {
        printf("%s\n", name[i]);
    }

    return;
}

