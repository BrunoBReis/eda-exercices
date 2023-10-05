#include <iostream>
#include <string>  // type string
#include <map>     // dictionary library
#include <vector>  // dinamic list library
#include <fstream> // files library
#include <sstream> //
using namespace std;

// Global variables
const string file_name = "song.txt";

// functons
vector<string> read_file(string file_name);
void show_vector(vector<string> vector);
vector<string> word_breaker(vector<string> vector);
void tokenize(const string &str, const char delim, vector<string> &list);
vector<string> final_list(vector<string> list);
string upper_string(string word);
bool word_verifier(string word, string word_to_verify);
bool verify_word_in_database(vector<string> name_list, string new_word);

int main()
{
    vector<string> list_words = read_file(file_name);
    show_vector(list_words);
    cout << "----------------" << endl;
    vector<string> breaked_list = word_breaker(list_words);
    show_vector(breaked_list);
    cout << "----------------" << endl;
    vector<string> new_list = final_list(breaked_list);
    show_vector(new_list);

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
        cout << i << " " << vector[i] << endl;
    }
}

vector<string> word_breaker(vector<string> list)
{
    vector<string> new_list;
    for (int i = 0; i < list.size(); i++)
    {
        tokenize(list[i], ' ', new_list);
    }
    return new_list;
}

void tokenize(const string &str, const char delim, vector<string> &list)
{
    stringstream ss(str);
    string s;

    while (getline(ss, s, delim))
    {
        // tratar a virgula aqui
        list.push_back(s);
    }
}

vector<string> final_list(vector<string> list)
{
    vector<string> new_list;
    for (int i = 0; i < list.size(); i++)
    {
        if (verify_word_in_database(new_list, list[i]))
        {
            if (list[i].size() > 3)
            {
                // for (int j = 0; j < list[i].size(); j++)
                // {
                //     if (list[i][j] == ',')
                //     {
                //         break;
                //     }
                //     new_list.push_back(list[i]);
                // }
                new_list.push_back(list[i]);
            }
            else
            {
                continue;
            }
        }

        continue;
    }

    return new_list;
}

string upper_string(string word)
{
    for (int i = 0; i < word.length(); i++)
    {
        word[i] = toupper(word[i]);
    }

    return word;
}

bool word_verifier(string word, string word_to_verify)
{
    word = upper_string(word);
    word_to_verify = upper_string(word_to_verify);

    if (word.length() == word_to_verify.length())
    {
        int words_lenght = word.length();
        int tries;
        for (int i = 0; i < words_lenght; i++)
        {
            if (word[i] != word_to_verify[i])
            {
                return false;
            }
            else
            {
                continue;
            }
        }
        return true;
    }
    else
    {
        return false;
    }
}

bool verify_word_in_database(vector<string> name_list, string new_word)
{

    for (int i = 0; i < name_list.size(); i++)
    {
        if (word_verifier(new_word, name_list[i]))
        {
            return false;
        }
    }
    return true;
}