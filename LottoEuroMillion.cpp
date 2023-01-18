#include "iostream"
#include "ctime"
#include "cstdlib"
#include "vector"
#include "fstream"
#include "limits"

// const auto MaxIgnore = std::numeric_limits<std::streamsize>::max();

//Using Vector to check if the number is the same after new assigned
bool isInVec(unsigned int key, std::vector<unsigned int> tempVec){
    for(int i = 0; i < tempVec.size(); i++){
        if(key == tempVec.at(i)){
            return true;
        }
    }
    return false;
}


//Bool check OutOfbound user input number that have to be large then 1 and not out of range
bool outOfBounds(unsigned int userInput, unsigned int range){
    if(userInput < 1 || userInput > range){
        return true;
        }
    return false;
}

// Testing
// bool isNotNumber(unsigned int userInput){
//     while(!(std::cin >> userInput)){
//         std::cin.clear();
//         std::cin.ignore(MaxIgnore, '\n');
//         std::cout << "invalid";
//         return true;
//     }
//     return false;
// }

//Function to print out array of number
void printArr(unsigned int arr[], unsigned int size) {
    for(int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
}

//Function for printing out array of number to another file
// void printArrToFile(unsigned int arr[], unsigned int size, std::ofstream &file){
//     for(int i = 0; i < size; i++){
//         file << arr[i] << " ";
//     }
// }


int main() {
   
//Initialize 
    const unsigned int winSIZE = 7;
    const unsigned int luckySIZE = 2;
    unsigned int winNums[winSIZE];
    unsigned int userNums[winSIZE];
    unsigned int mainBallRange = 50;
    unsigned int luckyBallRange = 12;

    // std::ofstream outfile("winNums.txt");

    //Initialize Vector to store number
    std::vector<unsigned int> temp;
    std::vector<unsigned int> winTemp;

    
    //Seed random number to time so that the number is randomized
    std::srand((unsigned int) (std::time(nullptr)));

    //Loop through winSIZE of 5 then assign random number ranging from 1-50
    for(int i = 0; i < winSIZE - 2 ; i++) {
        winNums[i] = rand() % 50 + 1;
        //checking if number is in vector or not if it is, assign new random number
        while(isInVec(winNums[i], temp)){
            winNums[i] = rand() % 50 + 1;
        }
        //then push the number into vector
        winTemp.push_back(winNums[i]);
    }
    //assign random lucky number ranging from 1-12
    winNums[winSIZE - 2] = rand() % 12 + 1;
    winNums[winSIZE - 1] = rand() % 12 + 1;
    //checking if number is equal to the other lucky number if it is, assign new random number
    while(winNums[winSIZE - 1] == winNums[winSIZE - 2]){
        winNums[winSIZE - 1] = rand() % 12 + 1;
    }

    std::cout<< "Winning Number: ";
    printArr(winNums, winSIZE);
    std::cout << "\n";
    // printArrToFile(winNums, winSIZE, outfile);


    std::cout << "Please Enter 5 unique numbers ranging from 1-50 and 2 lucky numbers ranging from 1-12" << "\n";
    //Loop through winSIZE of 5 then get userInput for the first 5 number 
    for(int i = 0; i < winSIZE; i++){
        std::cout << "Number " << i + 1 << ": ";
        std::cin >> userNums[i];

        //when winSIZE is 6 and 7 it is a lucky number so we change range to 1-12
        if(i == winSIZE - 2){
            mainBallRange = luckyBallRange;
        }
        if(i == winSIZE - 1){
            mainBallRange = luckyBallRange; 
        }
        //while loop to check if userInput number is the same or out of bound then let user re-input the number
        while(isInVec(userNums[i], temp) || outOfBounds(userNums[i], mainBallRange)){
            std::cout<< "please do not enter duplicate or out of range number" << "\n";
            std::cout<< "please re-enter choice " << i + 1 <<": ";
            std::cin>>userNums[i];
        }
       
       //Push userInput to vector
        temp.push_back(userNums[i]);
    }
    printArr(userNums, winSIZE);
}