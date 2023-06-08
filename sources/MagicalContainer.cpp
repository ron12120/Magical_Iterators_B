#include "MagicalContainer.hpp"
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;
namespace ariel
{
    void MagicalContainer::addElement(int number)
    {
        // ading element that already in the continer
        auto apper = find(numbers.begin(), numbers.end(), number);
        if (apper != numbers.end())
            return;
        // the first element in the container
        if (numbers.size() == 0)
            numbers.push_back(number);
        else
        {
            auto it = numbers.begin();
            while (it != numbers.end() && *it < number)
            {
                ++it;
            }
            // Insert the new element at the right position
            numbers.insert(it, number);
        }
        primes.clear();
        for (size_t i = 0; i < numbers.size(); ++i)
        {
            if (isprime(numbers[i]))
            {
                primes.push_back(&numbers[i]);
            }
        }
    }
    void MagicalContainer::removeElement(int number)
    {
        auto remove = find(numbers.begin(), numbers.end(), number);
        if (remove != numbers.end())
        {
            numbers.erase(remove);
            primes.clear();
            for (auto num : numbers)
            {
                if (isprime(number))
                    primes.push_back(&(number));
            }
        }
        else
            throw runtime_error("can't remove number that not have in the container");
    }
    size_t MagicalContainer::size() const
    {
        return numbers.size();
    }
    bool MagicalContainer::isprime(int num)
    {
        if (num <= 1)
            return false;

        int sqrtNumber = sqrt(num);
        for (int i = 2; i <= sqrtNumber; ++i)
        {
            if (num % i == 0)
                return false;
        }

        return true;
    }
    int MagicalContainer::operator[](size_t index) const
    {
        if (index >= numbers.size())
        {
            throw std::out_of_range("Index out of range");
        }
        return numbers[index];
    }

    //////////////////////////////////////////////////////////////////////////////////
    // AscendingIterator
    MagicalContainer::AscendingIterator::AscendingIterator(const AscendingIterator &itasc): contianer(itasc.contianer),index(itasc.index)
    {}
    MagicalContainer::AscendingIterator::AscendingIterator(MagicalContainer &magicont) : contianer(magicont), index(0) {}

    MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::begin()
    {
        AscendingIterator ans(contianer);
        return ans;
    }
    MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::end()
    {
        AscendingIterator ans(contianer);
        ans.index = contianer.size();
        return ans;
    }

    MagicalContainer::AscendingIterator& MagicalContainer::AscendingIterator::operator++()
    {
        if (index == contianer.numbers.size())
            throw runtime_error("can't do increment over the last element");
        index++;
        return *this;
    }
    MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::operator=(const AscendingIterator &itc)
    {
        if (&contianer != &itc.contianer)
            throw runtime_error("cant placement two iterator withe differant contianer");
        index = itc.index;
        return *this;
    }
    int MagicalContainer::AscendingIterator::operator*() const
    {
        if (index == contianer.size())
            throw runtime_error("can't do increment over the last element");
        return contianer[index];
    }
    bool MagicalContainer::AscendingIterator::operator!=(const AscendingIterator &itasc) const
    {
        return index != itasc.index;
    }
    bool MagicalContainer::AscendingIterator::operator==(const AscendingIterator &itasc) const
    {
        return index == itasc.index;
    }
    bool MagicalContainer::AscendingIterator::operator>(const AscendingIterator &itasc) const
    {
        return index > itasc.index;
    }
    bool MagicalContainer::AscendingIterator::operator<(const AscendingIterator &itasc) const
    {
        return index< itasc.index;
    }

    //////////////////////////////////////////////////////////////////////////////////
    // SideCroddIterator
    MagicalContainer::SideCrossIterator::SideCrossIterator(const SideCrossIterator &itc) : contianer(itc.contianer),index(itc.index){}
    MagicalContainer::SideCrossIterator::SideCrossIterator(MagicalContainer &magicont) : contianer(magicont), index(0)
    {
    }

    MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::begin()
    {
        SideCrossIterator ans(contianer);
        return ans;
    }
    MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::end()
    {
        SideCrossIterator ans(contianer);
        ans.index=contianer.numbers.size();
        return ans;
    }

    MagicalContainer::SideCrossIterator& MagicalContainer::SideCrossIterator::operator++()
    {
        if (index==this->end().index)
            throw runtime_error("can't do increment over the last element");
        index++;
        return *this;
    }
    MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::operator=(const SideCrossIterator &itc)
    {
        if (&contianer != &itc.contianer)
            throw runtime_error("cant placement two iterator withe differant contianer");
        index=itc.index;
        return *this;
        
    }
    int MagicalContainer::SideCrossIterator::operator*()
    {
        size_t pos;
        if(index%2==0){
            pos=index/2;
        }
        else{
            pos=contianer.size()-1-((index-1)/2);
        }
        return contianer.numbers[pos];
    }
    bool MagicalContainer::SideCrossIterator::operator!=(const SideCrossIterator &itc) const
    {
        return index!= itc.index;
    }
    bool MagicalContainer::SideCrossIterator::operator==(const SideCrossIterator &itc) const
    {
        return index == itc.index;
    }
    bool MagicalContainer::SideCrossIterator::operator>(const SideCrossIterator &itc) const
    {
        return index > itc.index;
    }
    bool MagicalContainer::SideCrossIterator::operator<(const SideCrossIterator &itc) const
    {
        return index < itc.index;
    }
    //////////////////////////////////////////////////////////////////////////////////
    // PrimeIterator

    MagicalContainer::PrimeIterator::PrimeIterator(MagicalContainer &magicont) : contianer(magicont), index(0) {}
    MagicalContainer::PrimeIterator::PrimeIterator(const PrimeIterator &itpr) : contianer(itpr.contianer), index(itpr.index){}
    MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::begin()
    {
        PrimeIterator ans(contianer);
        return ans;
    }
    MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::end()
    {
        PrimeIterator ans(contianer);
        ans.index = (contianer.primes.size());
        return ans;
    }
    MagicalContainer::PrimeIterator& MagicalContainer::PrimeIterator::operator++()
    {
        if (index == contianer.primes.size())
            throw runtime_error("can't do increment over the last element");
        index++;
        return *this;
    }
    MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::operator=(const PrimeIterator &itpr)
    {
        if (&contianer != &itpr.contianer)
            throw runtime_error("cant placement two iterator withe differant contianer");
        index = itpr.index;
        return *this;
    }
    int MagicalContainer::PrimeIterator::operator*() const
    {
        if (index >= contianer.primes.size())
        {
            throw std::out_of_range("Iterator out of range");
        }
        return *(contianer.primes[index]);
    }
    bool MagicalContainer::PrimeIterator::operator!=(const PrimeIterator &itpr) const
    {
        if (contianer.size() == 0 && itpr.contianer.size() == 0)
            return true;
        return index!=itpr.index;
    }
    bool MagicalContainer::PrimeIterator::operator==(const PrimeIterator &itpr) const
    {
        if (contianer.size() == 0 && itpr.contianer.size() == 0)
            return true;
        return  index==itpr.index;
    }
    bool MagicalContainer::PrimeIterator::operator>(const PrimeIterator &itpr) const
    {
        if (contianer.size() == 0 && itpr.contianer.size() == 0)
            return true;
        return index>itpr.index;
    }
    bool MagicalContainer::PrimeIterator::operator<(const PrimeIterator &itpr) const
    {
        if (contianer.size() == 0 && itpr.contianer.size() == 0)
            return true;
        return  index<itpr.index;
    }
}
