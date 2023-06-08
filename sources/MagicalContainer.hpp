#pragma once
#include <vector>
using namespace std;
namespace ariel
{
    class MagicalContainer
    {
    private:
        vector<int> numbers;
        vector<int *> primes;

    public:
        MagicalContainer() = default;
        void addElement(int number);
        size_t size() const;
        void removeElement(int number);
        bool isprime(int num);
        int operator[](size_t index) const;

        class AscendingIterator 
        {
            size_t index;
            MagicalContainer &contianer;

        public:
            AscendingIterator();
            AscendingIterator(const AscendingIterator &itasc);
            AscendingIterator(MagicalContainer &magicont);
            AscendingIterator begin();
            AscendingIterator end();
            AscendingIterator& operator++();
            AscendingIterator operator=(const AscendingIterator &itasc);
            int operator*() const;
            bool operator!=(const AscendingIterator &itasc) const;
            bool operator==(const AscendingIterator &itasc) const;
            bool operator>(const AscendingIterator &itasc) const;
            bool operator<(const AscendingIterator &itasc) const;
            ~AscendingIterator() = default;
        };
        class SideCrossIterator 
        {
            MagicalContainer &contianer;
            size_t index;
        public:
            SideCrossIterator();
            SideCrossIterator(const SideCrossIterator &itc);
            SideCrossIterator(MagicalContainer &magicont);
            SideCrossIterator begin();
            SideCrossIterator end();
            SideCrossIterator& operator++();
            SideCrossIterator operator=(const SideCrossIterator &itc);
            int operator*();
            bool operator!=(const SideCrossIterator &itc) const;
            bool operator==(const SideCrossIterator &itc) const;
            bool operator>(const SideCrossIterator &itc) const;
            bool operator<(const SideCrossIterator &itc) const;
            ~SideCrossIterator()= default;
        };
        class PrimeIterator 
        {
        private:
            size_t index;
            MagicalContainer &contianer;

        public:
            PrimeIterator();
            PrimeIterator(const PrimeIterator &itpr);
            PrimeIterator(MagicalContainer &magicont);
            PrimeIterator begin();
            PrimeIterator end();
            PrimeIterator& operator++();
            PrimeIterator operator=(const PrimeIterator &itpr);
            int operator*() const;
            bool operator!=(const PrimeIterator &itpr) const;
            bool operator==(const PrimeIterator &itpr) const;
            bool operator>(const PrimeIterator &itpr) const;
            bool operator<(const PrimeIterator &itpr) const;
            ~PrimeIterator()= default;
        };
    };

}

