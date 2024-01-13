# include <iostream>
# include <fstream>
# include <cstring>

using namespace std;

int main()
{
    char data[100];
    int sum = 0;

    ifstream infile; 
    infile.open("numberdata.txt");
    
    while(!infile.eof())
    {
        infile >> data;
        sum += stoi(data);
    }  
    
    cout << sum << endl;

    return 0;
}
