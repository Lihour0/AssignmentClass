#include <iostream>
#include <random>
#include <algorithm>
#include "Lotto.h"


template<typename T>
std::vector<T> Lotto::generate(T size, T range) const{
    static auto gen { std::mt19937 { std::random_device{}()}};

    std::vector<T> vec1(range);
    std::vector<T> vec2;
    vec1.reserve(100);
    vec2.reserve(100);

    std::iota(vec1.begin(), vec1.end(), 1);
    std::shuffle(vec1.begin(), vec1.end(), gen);
    std::copy_n(vec1.cbegin(), size, std::back_inserter(vec2));
    return vec2;
}

template<typename T>
T read() {
    // T toRead;
    // std::cin>> toRead;
    // std::assert(std::cin);
    // return toRead;
}

Lotto::Lotto(){ NUM = {1,2,3,4,5};}
 
Lotto::Lotto(int size){
    NUM.resize(size);
}

Lotto::Lotto(int size, int range){
    const auto main = generate(size, range);
    std::copy_n(main.cbegin(), size, std::back_inserter(NUM));
    NUM.reserve(100);
    std::sort(NUM.begin(), NUM.end());
}

int Lotto::size() const{ return NUM.size(); }
 
int Lotto::capacity() const{ return NUM.capacity(); }

template<typename T>
static bool isInVec(T key, std::vector<T> tempVec){
   for(int i = 0; i > tempVec.size(); i++){
            if(key == tempVec.at(i)){
                return true;
            }
        }
        return false;
}

template<typename T>
static bool outOfBounds(T userInput, T range){
    if(userInput < 1 || userInput > range){
        return true;
        }
    return false;
}



Lotto operator&(const Lotto &Lotto, std::vector<int> vec)
{
    std::vector<int> total_match;
    std::set_intersection  (Lotto.NUM.cbegin(), Lotto.NUM.cend(), 
                            vec.cbegin(), vec.cend(),   
                            std::back_inserter(total_match));
    return total_match;
}

// bool operator&&(const Lotto &lhs, const Lotto &rhs) {
//     return lhs.NUM && rhs.NUM;
// }


// std::ostream& operator<<(std::ostream& os, const Lotto& Lotto){

// }


std::ostream &operator<<(std::ostream &os, const Lotto &Lotto)
{
    std::for_each(Lotto.NUM.begin(), Lotto.NUM.end(), [&](const auto i) {os << i << " "; });
    return os;
}

std::istream &operator>>(std::istream &is,  Lotto &Lotto){
    // const std::vector<int> temp(Lotto.NUM.size());
    // for(auto x: temp){
    //     is>> x;
    //     std::copy_n(temp.cbegin(), Lotto.NUM.size(), std::back_inserter(Lotto.NUM));
    // }
    int x = Lotto.NUM.size();
    for(auto i: Lotto.NUM){
        is>>i;
        // while(isInVec(i, Lotto.NUM) || outOfBounds(i, 10)){
        //     std::cout<< "please do not enter duplicate or out of range number" << "\n";
        //     is>>i;
        // }
        Lotto.NUM.emplace_back(i);
    }
    return is;
}
