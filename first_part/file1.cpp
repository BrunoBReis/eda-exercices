#include <iostream>
#include <string>  // type string
#include <map>     // dictionary library
#include <vector>  // dinamic list library
#include <fstream> // files library
using namespace std;

// Global variables
const string file_name = "song.txt";

// functons
vector<string> read_file(string file_name);
void show_vector(vector<string> vector);
vector<string> word_breaker(vector<string> vector);

int main()
{
    vector<string> list_words = read_file(file_name);
    // show_vector(list_words);
    word_breaker(list_words);

    return 0;
}

vector<string> read_file(string file_name)
{
    ifstream file;
    file.open(file_name);

    if (file.is_open())
    {
        string word;
        vector<string> name_list;
        while (getline(file, word))
        {
            name_list.push_back(word);
        }
        file.close();
        return name_list;
    }
    else
    {
        cout << "File was not found." << endl;
        exit(0);
    }
}

void show_vector(vector<string> vector)
{
    for (int i = 0; i < vector.size(); i++)
    {
        cout << vector[i] << endl;
    }
}

vector<string> word_breaker(vector<string> list)
{
    vector<string> new_list;
    for (int i = 0; i < list.size(); i++)
    {
        string name;
        name = list[i];
        cout << i << name << endl;
    }
    return new_list;
}