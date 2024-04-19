#include <iostream>
#include <vector>
#include <string>

using namespace std;

void alphabet_split(int, vector<vector<char>>&);
void next_split(string, vector<vector<char>>&, vector<vector<char>>&);
string final_word(string, string, vector<vector<char>>);
void print_group(vector<vector<char>>);


int main()
{
    int length;

    cout << "Hello I will guess your name. How many letters is your name?\n>>";
    cin >> length;

    int row = 26/length;

    vector<vector<char>> first_split, second_split;

    alphabet_split(row,first_split);

    print_group(first_split);

    string first_response, second_response;

    cout << "Based on the row, type the corresponding number for each letter of your name.\n>>";

    cin >> first_response;

     //group the letters into corresponding rows;
    next_split(first_response, first_split, second_split);
    

    cout << "Again, type the corresponding number for each letter.\n>>";
    cin >> second_response;

    string name = final_word(first_response, second_response, second_split);

    cout << "Hello " << name << " :)." << endl;
    
    return 0;


}

//make an alphabet split based on the number of letters in word.
void alphabet_split(int row, vector<vector<char>> &group)
{
    vector<char> alphabet = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 
                            'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 
                            'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

    int size = alphabet.size();

    int column = size/row;
    vector<char> sub_group;
    int count = 0;
    
    for(int i = 0; i <= row ; i++)
    {
        for(int j = 0; j < column; j++)
            {
                count > 25 ? sub_group.push_back('0') : sub_group.push_back(alphabet[count]);
                count++;
            }

        group.push_back(sub_group);
        sub_group = {};
        
    }
    
}

//populate and display the second_split vector based on the response
void next_split(string response, vector<vector<char>> &first_split, vector<vector<char>> &second_split)
{
    

    for(int i = 0; i < response.length(); i++)
    {
        int position = static_cast<int>(response[i]) - 49;
        second_split.push_back(first_split[position]);
    }

    int row = second_split[0].size();

    //display a transposed second_split vector
    for(int i = 0; i < row; i++)
    {
        
        cout << i + 1 << "\t";
        for(int j = 0; j < response.length(); j++){cout << "\t" << second_split[j][i] << "\t";}
        cout << endl;
        
    }

}


string final_word(string first_response, string second_response, vector<vector<char>> second_input)
{
    int row = first_response.length();
    int column = second_response.length();
    string name;

    for(int i = 0; i < row; i ++)
    {
        int position = static_cast<int>(second_response[i]) - 49;
        name = name + second_input[i][position];
    }

    return name;

}


//print the letters with each group per line
void print_group(vector<vector<char>> group)
{
    int group_size = group.size();
    int row = 1;

    for(int i = 0; i < group_size; i++)
    {
        
        int sub_group_size = group[i].size();
        cout << row << "\t";
        for(int j = 0; j < sub_group_size; j++)
        {
            
            cout << group[i][j] << "\t";
        }

        row++;
        cout << endl;
    }
    
}
    