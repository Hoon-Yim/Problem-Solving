#include <iostream>
#include <deque>

void spinning(int num, int testcase)
{
    std::deque<int> deque;
    int count = 0;

    for(int i = 1; i <= num; ++i)
        deque.push_back(i);

    for(int i = 0; i < testcase; ++i)
    {
        int index = 0;
        int target; std::cin >> target;

        for(int j = 0; j < deque.size(); ++j)
        {
            if(deque[j] == target)
            {
                index = j;
                break;
            }
        }

        if(index < deque.size() - index)
        {
            while(true)
            {
                if(deque.front() == target)
                {
                    deque.pop_front();
                    break;
                }

                ++count;
                deque.push_back(deque.front());
                deque.pop_front();
            }
        }
        else
        {
            while(true)
            {
                if(deque.front() == target)
                {
                    deque.pop_front();
                    break;
                }
                ++count;
                deque.push_front(deque.back());
                deque.pop_back();
            }
        }
    }

    std::cout << count << "\n";
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int num, testcase; std::cin >> num >> testcase;
    spinning(num, testcase);
}