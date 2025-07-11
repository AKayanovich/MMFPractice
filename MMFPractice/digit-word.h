#pragma once

#include <iostream>
#include <cstring>
using namespace std;

int word() {
    
    char digits[9][10] = {
        "ONE", "TWO", "THREE", "FOUR", "FIVE",
        "SIX", "SEVEN", "EIGHT", "NINE"
    };

    cout << "Введите слово на английском из 15 символов в верхнем регистре" << endl;

    char word[16]; 
    cin >> word;

    int wordLen = strlen(word);

    for (int i = 0; i < 9; i++) {
        int digitLen = strlen(digits[i]);
        int wordIndex = 0;
        int digitIndex = 0;

        
        while (wordIndex < wordLen && digitIndex < digitLen) {
            if (word[wordIndex] == digits[i][digitIndex]) {
                digitIndex++;
            }
            wordIndex++;
        }

        if (digitIndex == digitLen) {
            cout << digits[i] << endl;
            return 0;
        }
    }

    cout << "NO" << endl;
    return 0;
}