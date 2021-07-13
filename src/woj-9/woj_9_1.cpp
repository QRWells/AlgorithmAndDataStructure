#include <algorithm>
#include <cassert>
#include <chrono>
#include <iostream>
#include <string>
#include <random>
#include <unordered_map>
#include <vector>

std::vector<int> EditDistance(const std::string &query, const std::string &text, int k)
{
    size_t m = query.size(), n = text.size();
    std::vector<int> result;
    std::vector<int> prev(m + 1, 0);
    for (size_t i = 0; i < m; i++)
    {
        prev[i + 1] = prev[i] + 1;
    }
    std::vector<int> next(m + 1, 0);
    for (size_t j = 0; j < n; j++)
    {
        for (size_t i = 0; i < m; i++)
        {
            if (query[i] == text[j])
            {
                next[i + 1] = prev[i];
            }
            else
            {
                next[i + 1] = std::min({prev[i] + 1, prev[i + 1] + 1, next[i] + 1});
            }
        }
        if (next[m] <= k)
        {
            result.push_back(j);
        }
        prev.swap(next);
    }
    return result;
}

std::vector<int> EditDistanceBitVector(const std::string &query, const std::string &text, int k)
{
    size_t m = query.size(), n = text.size();
    std::vector<int> result;
    std::unordered_map<char, uint64_t> peq;
    for (size_t i = 0; i < m; i++)
    {
        peq[query[i]] |= uint64_t(1) << i;
    }
    uint64_t pv = ~uint64_t(0);
    uint64_t mv = 0;
    int score = m;
    for (size_t j = 0; j < n; j++)
    {
        uint64_t eq = peq.find(text[j]) != peq.end() ? peq[text[j]] : 0;
        uint64_t xv = eq | mv;
        uint64_t xh = (((eq & pv) + pv) ^ pv) | eq;
        uint64_t ph = mv | ~(xh | pv);
        uint64_t mh = pv & xh;
        if ((ph & (1 << (m - 1))) != 0)
        {
            score++;
        }
        else if ((mh & (1 << (m - 1))) != 0)
        {
            score--;
        }
        ph <<= 1;
        mh <<= 1;
        pv = mh | ~(xv | ph);
        mv = ph & xv;
        if (score <= k)
        {
            result.push_back(j);
        }
    }
    return result;
}

std::string generate_random_string(size_t size)
{
    const char alphabets[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    std::string s(size, 'A');
    std::random_device rng;
    for (int i = 0; i < size; i++)
    {
        s[i] = alphabets[rng() % 26];
    }
    return s;
}

int main()
{
    std::string query = generate_random_string(64);
    std::string text = generate_random_string(10000);

    int k = 2;
    int exec_count = 1000;
    std::chrono::system_clock::time_point start, end;
    double elapsed;
    std::vector<int> result, result_bit_vector;

    start = std::chrono::system_clock::now();
    for (int i = 0; i < exec_count; i++)
    {
        result = EditDistance(query, text, k);
    }
    end = std::chrono::system_clock::now();
    elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
    std::cout << elapsed / 1000 / exec_count << " msec" << std::endl;

    start = std::chrono::system_clock::now();
    for (int i = 0; i < exec_count; i++)
    {
        result_bit_vector = EditDistanceBitVector(query, text, k);
    }
    end = std::chrono::system_clock::now();
    elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
    std::cout << elapsed / 1000 / exec_count << " msec" << std::endl;

    assert(result == result_bit_vector);
}