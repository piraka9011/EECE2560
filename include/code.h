//
// Created by piraka9011 on 1/15/17.
//

#ifndef CODE_H
#define CODE_H

#include <vector>
#include <cstdlib>

class code {

private:
    int n;  // Length
    int m;  // Range

public:
    // Constructor
    code(int n, int m){
        this->n = n;
        this->m = m;
    }
    // Destructor
    ~code(){}

    // Inits code randomly
    void randomInit(){
        std::vector<int> secretCode;
        for (int i = 0; i < n; i++)
            secretCode.push_back(rand() % m);
    }

    // returns the number of correct digits in the correct location
    int checkCorrect(code codeArg){

    }

    // returns the number of correct digits in the incorrect location
    int checkIncorrect(code codeArg){

    }
};


#endif //CODE_H
