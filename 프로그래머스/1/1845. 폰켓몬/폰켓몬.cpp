#include <vector>
#include <map>
#include <iostream>

using namespace std;

int solution(vector<int> nums)
{
    map<int, int> check;
    int ans = 0;
    
    for (int i=0; i<nums.size(); i++) {
        check[nums[i]]++;
    }
    
    int half = nums.size() / 2;
    if (check.size() <= half) return check.size();
    else {return half;}
    
}