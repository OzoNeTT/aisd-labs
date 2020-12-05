#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>


int mod(std::string num, int a)
{
    int res = 0;
    for (int i = 0; i < num.length(); i++)
        res = (res*10 + (int)num[i] - '0') %a;
    return res;
}

std::string findSum(std::string str1, std::string str2)
{
    if (str1.length() > str2.length())
        swap(str1, str2);
    std::string str = "";
    int n1 = str1.length(), n2 = str2.length();
    reverse(str1.begin(), str1.end());
    reverse(str2.begin(), str2.end());
    int carry = 0;
    for (int i=0; i<n1; i++)
    {
        int sum = ((str1[i]-'0')+(str2[i]-'0')+carry);
        str.push_back(sum%10 + '0');
        carry = sum/10;
    }
    for (int i=n1; i<n2; i++)
    {
        int sum = ((str2[i]-'0')+carry);
        str.push_back(sum%10 + '0');
        carry = sum/10;
    }
    if (carry)
        str.push_back(carry+'0');
    reverse(str.begin(), str.end());
    return str;
}

bool isSmaller(std::string str1, std::string str2)
{
    int n1 = str1.length(), n2 = str2.length();
    if (n1 < n2)
        return true;
    if (n2 < n1)
        return false;
    for (int i=0; i<n1; i++)
        if (str1[i] < str2[i])
            return true;
        else if (str1[i] > str2[i])
            return false;
    return false;
}

std::string findDiff(std::string str1, std::string str2)
{
    if (isSmaller(str1, str2))
        swap(str1, str2);
    std::string str = "";
    int n1 = str1.length(), n2 = str2.length();
    reverse(str1.begin(), str1.end());
    reverse(str2.begin(), str2.end());
    int carry = 0;
    for (int i=0; i<n2; i++)
    {
        int sub = ((str1[i]-'0')-(str2[i]-'0')-carry);
        if (sub < 0)
        {
            sub = sub + 10;
            carry = 1;
        }
        else
            carry = 0;
        str.push_back(sub + '0');
    }
    for (int i=n2; i<n1; i++)
    {
        int sub = ((str1[i]-'0') - carry);
        if (sub < 0)
        {
            sub = sub + 10;
            carry = 1;
        }
        else
            carry = 0;
        str.push_back(sub + '0');
    }
    reverse(str.begin(), str.end());
    return str;
}

int main(int argc, char* argv[]) {
    std::string inp;
    std::vector<std::string> vec;
    std::string input(argv[1]);
    std::string output(argv[2]);
    std::ifstream file(input);
    std::string sum1 = "0";
    std::string sum2 = "0";
    std::vector<std::string> vecMinus;
    std::vector<std::string> vecPlus;
    if(file.is_open()) {
        while (std::getline(file, inp)) {
            if(inp != "") {
                if(inp[0] == '-')
                    vecMinus.push_back(inp.erase(0,1));
                else
                    vecPlus.push_back(inp);
            }
        }
        file.close();
    }
    for(auto &n : vecPlus)
        sum1 = findSum(sum1, n);
    for(auto &n : vecMinus)
        sum2 = findSum(sum2, n);
    std::string res = findDiff(sum1, sum2);
    std::ofstream file2(output);
    if (file2.is_open())
    {
        int ress = mod(res, 256);

        if (sum2.length() > sum1.length()){
            ress = 256 - ress;
        }
        file2 << ress;
        file2.close();
    }
    return 0;
}
