#include <iostream>
#include <fstream>

using namespace std;

void load_data(string directory)
{
    ifstream movies(directory+"/movies.csv");
    ifstream people(directory+"/people.csv");
    ifstream stars(directory+"/stars.csv");
    
    if(!movies)
    {
        cout << "Cannot open file.\n";
        exit(1);
    }

    if(!people)
    {
        cout << "Cannot open file.\n";
        exit(1);
    }

    if(!stars)
    {
        cout << "Cannot open file.\n";
        exit(1);
    }

    movies.close();
    people.close();
    stars.close();
}

int main(int argc, char *argv[])
{
    if(argc > 2)
    {
        cout << "Usage: ./degrees [directory]" << endl;
        exit(1);
    }

    string directory;

    if(argv[1] == NULL)
    {
        directory = "large";
    }
    else
    {
        directory = argv[1];
    }

    cout << "Loading data......" << endl;
    load_data(directory);
    
}