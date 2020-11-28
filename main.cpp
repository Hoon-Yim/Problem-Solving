#include <iostream>
#include <string>
#include <deque>

// TODOS:
// Make a function to extract integers from random string
// Make the main function

std::deque<int> deque;

inline void extract(std::string str)
{
    int temp = 0;
    for(int i = 1; i < str.length(); ++i)
    {
        if(str[i] >= '0' && str[i] <= '9')
            temp = temp * 10 + (static_cast<int>(str[i]) - 48);
        else if((str[i] == ',' || i + 1 == str.length()) && temp != 0)
        {
            deque.push_back(temp);
            temp = 0;
        }
    }
}

void AC(int testcase)
{
    for(int i = 0; i < testcase; ++i)
    {
        deque.clear();
        std::string option; std::cin >> option;
        int size; std::cin >> size;
        std::string nums; std::cin >> nums; extract(nums);
        bool reverse = false, error = false;

        for(char j : option)
        {
            if(j == 'R')
                reverse = !reverse;
            else if(j == 'D')
            {
                if(deque.empty())
                {
                    error = true;
                    break;
                }
                if(reverse) deque.pop_back();
                else deque.pop_front();
            }
        }

        if(error)
            std::cout << "error\n";
        else if(deque.empty())
            std::cout << "[]\n";
        else if(reverse)
        {
            std::cout << "[";
            while(deque.size() > 1)
            {
                std::cout << deque.back() << ',';
                deque.pop_back();
            }
            std::cout << deque.back() << "]\n";
        }
        else
        {
            std::cout << "[";
            while(deque.size() > 1)
            {
                std::cout << deque.front() << ',';
                deque.pop_front();
            }
            std::cout << deque.front() << "]\n";
        }
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr); std::cout.tie(nullptr);

    int testcase; std::cin >> testcase;
    AC(testcase);
}
