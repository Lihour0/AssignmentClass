#pragma once
#include <vector>
#include <iterator>

class Lotto{
private:

    std::vector<int> NUM;

    template<typename T>
    std::vector<T> generate(T num, T finish) const;

    template<typename T>
    T read(){};

    template<typename T>
    Lotto(const std::vector<T>& n): NUM(n) {};
    
    friend Lotto operator&(const Lotto& Lotto, std::vector<int> vec);

    // friend bool operator&&(const Lotto& lhs, const Lotto& rhs) ;

public:
   

    Lotto() ;

    Lotto(int size);
    
    Lotto(int size, int range);


    int size() const;

    int capacity() const;

    template<typename T>
    static bool isInVec(T key, std::vector<T> tempVec);

    template<typename T>
    static bool outOfBounds(T userInput, T range);
    
    // template<typename T>
    // friend std::istream& operator>>(std::istream& is, const LottoGen& Lotto){

    //     std::for_each(Lotto.NUM.begin(), Lotto.NUM.end(), [&](auto i) {Lotto.NUM.push_back(i)};);
    //     return is;
    // }


    friend std::ostream& operator<<(std::ostream& os, const Lotto& Lotto);

    friend std::istream& operator>>(std::istream& os,  Lotto& Lotto);

};

//bool check array to check if the number is inside vector when pushed if it is the same
//assign new number 
// template<typename T>
// bool isInVec(T key, std::vector<T> tempVec){};


// //Bool check OutOfbound user input number that have to be larger then 1 and not out of range
// template<typename T>
// bool outOfBounds(T userInput, T range){};

//Function to print out array of number
// template<typename T>
// void printArr(T arr[], T size) {};

// //cin only number if not number clear and ignore
// void inputNumOnly(){} ;


