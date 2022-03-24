#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

bool is_valid(string str)
{
    if(str[0] == 'X' || str[0] == 'Y' || str[0] == 'Z')
    {
        str = str.erase(0,1);
        try
        {
            int t = atoi(str.c_str());
        }
        catch (exception e)
        {
            return false;
        }
        return true;
    }
    else
        return false;
}

int main()
{
   vector<int> P;
   char chr[256];
   string input;
   ifstream ifile;
   ifile.open("D:\\input.txt");
   if (!ifile.is_open())
          cout << "File is not opened\n";
   else{
   ifile.getline(chr,256,'\n');
   input += chr;
   string temp;
   for(int i = 0 ; i < input.size(); i++)
   {
        if(input[i] != ' ')
        {
            temp += input[i];
        }
        else
        {
            P.push_back(atoi(temp.c_str()));
            temp = "";
        }
   }
   P.push_back(atoi(temp.c_str()));

   int x,y,z;
   while(!ifile.eof())
   {
        ifile.getline(chr,256,'\n');
        input = chr;
        temp = "";
        for(int i = 0 ; i < input.size(); i++)
        {
             if(input[i] != ';')
             {
                 temp += input[i];
             }
             else
             {
                 if(!is_valid(temp))
                 {
                    cout << P[0] << " " << P[1] << " " << P[2] << endl;
                    cout << "ERROR CODE";
                    return 0;
                 }
                 if(temp[0] == 'X')
                 {
                     temp = temp.erase(0,1);
                     x = atoi(temp.c_str());
                 }
                 else if(temp[0] == 'Y')
                 {
                     temp = temp.erase(0,1);
                     y = atoi(temp.c_str());
                 }
                 else if(temp[0] == 'Z')
                 {
                     temp = temp.erase(0,1);
                     z = atoi(temp.c_str());
                 }
                 temp = "";
             }
        }
        P[0] += x; P[1] += y; P[2] += z;

   }
   ifile.close();
   }
   cout << P[0] << " " << P[1] << " " << P[2] << endl;
   //cout << P.x << " " << P.y << " " << P.z;
}
