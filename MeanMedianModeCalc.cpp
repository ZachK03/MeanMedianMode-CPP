#include <iostream>
#include <vector>
#include <string>
#include <bits/stdc++.h>

void CreateHeaderText(std::string text);
void CreateDividerText();
void CreateErrorText(std::string text);
bool GetBoolUserInput(std::string text);

void getMeanOfData(std::vector<float> vector);
void getMedianOfData(std::vector<float> vector);
void getMaxMinOfData(std::vector<float> vector);

int main() {
    std::cout << "\n\n\n\n";
    std::cout << 3/2 << "\n";
    CreateHeaderText("Mean Median Mode Calculator");
    bool isRunning = true;
    int newInput;
    std::vector<float> dataValues;
    std::cout << "Enter -1 to finish entering data.\n";
    do {
        newInput = 0;
        dataValues = {};
        while (newInput != -1) {
            std::cout << "Input a number: ";
            std::cin >> newInput;
            if(newInput != -1) {
                dataValues.push_back(newInput);
            }
        }
        std::sort(dataValues.begin(),dataValues.end());
        
        CreateDividerText();
        std::cout << "Size of data set: " << dataValues.size() << "\n";
        getMeanOfData(dataValues);
        getMedianOfData(dataValues);
        getMaxMinOfData(dataValues);
        CreateDividerText();
        if(!(GetBoolUserInput("Use tool again? Y/N\n"))) {
            isRunning = false;
        }
    } while (isRunning);

    return 0;
}

void getMeanOfData(std::vector<float> vector) {
    float total = 0;
    for (float entry : vector) {
        total += entry;
    }
    total = total / vector.size();
    std::cout << "Mean of data is: " << total << "\n";
}

void getMedianOfData(std::vector<float> vector) {
    if(vector.size() % 2 == 0) {
        //Even, must use average of both middle numbers
        float data = 0;
        data += vector[vector.size() / 2];
        data += vector[(vector.size() / 2) - 1];
        std::cout << "Median of data is: " << data/2 << "\n";
    } else {
        //Odd, use middle number
        std::cout << "Median of data is: " << vector[vector.size() / 2] << "\n";
    }
}

void getMaxMinOfData(std::vector<float> vector) {
    float min;
    float max;
    for (float data : vector)
    {
        if(!min) {
            min = data;
        }
        if(!max) {
            max = data;
        }
        if(min > data) 
            min = data;

        if(max < data)
            max = data;
    }
    std::cout << "Minimum value is: " << min << "\n";
    std::cout << "Maximum value is: " << max << "\n";
};

void CreateHeaderText(std::string text) {
    for (int i = 0; i < text.size(); i++) {
        std::cout << "=";
    }
    std::cout << "\n" << text << "\n";
    for (int i = 0; i < text.size(); i++) {
        std::cout << "=";
    }
    std::cout << "\n";
}

void CreateDividerText() {
    for (int i = 0; i < 20; i++) {
        std::cout << "=";
    }
    std::cout << "\n";
}

void CreateErrorText(std::string text) {
    std::string errorText = "[ERROR] : ";
    errorText += text;
    CreateHeaderText(errorText);
}

bool GetBoolUserInput(std::string text) {
    char input;
    while (toupper(input) != 'Y' && toupper(input) != 'N') {
        std::cout << text;
        std::cin >> input;
    }
    if(toupper(input) == 'Y') {
        return true;
    } else {
        return false;
    }
}