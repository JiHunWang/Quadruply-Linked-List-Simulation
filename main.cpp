/*
 * CS109 Project
 * Created by Ji Hun Wang
 * Copyright 2019. All rights reserved.
 *
 * This C++ program creates a quadruply linked list containing 16 nodes, and use random probabilistic distribution
 * to determine characters and to which direction next Node pointer should move.
 */

#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <random>
#include <unordered_map>
#include <fstream>
#include <ctime>
#include "time.h"
#include "linked_list.h"
using namespace std;

char frequencyChar(int prob, vector<char>& table);
vector<char> charTable();
void initializeWordTable(Node*& head);
void fillWordTable(Node*& head, vector<char>& table, default_random_engine &dre1, default_random_engine &dre2);
void printWordTable(Node* head);
vector<vector<char>> wordTableToVec(Node* head);
vector<string> allFourLetterWords(vector<vector<char>>& wordVec);


char frequencyChar(int prob, vector<char>& table) {
    random_shuffle(table.begin(), table.end());
    return table[prob];
}

/**
 * Initializes an array based on English Letter Frequency (sample of 40,000 words)
 */
vector<char> charTable() {
    unordered_map<char, int> charFreq;
    vector<char> letters = {'e', 't', 'a', 'o', 'i', 'n', 's', 'r', 'h', 'd', 'l', 'u', 'c', 'm', 'f', 'y', 'w', 'g', 'p', 'b', 'v', 'k', 'x', 'q', 'j', 'z'};
    vector<int> frequency = {1202, 910, 812, 768, 731, 695, 628, 602, 592, 432, 398, 288, 271, 261, 230, 211, 209, 203, 182, 149, 111, 69, 17, 11, 10, 7};
    for (int i = 0; i < letters.size(); i++) {
        charFreq.insert(make_pair(letters[i], frequency[i]));
    }
    vector<char> table;
    for (char ch = 'a'; ch <= 'z'; ch++) {
        for (int i = 0; i < charFreq[ch]; i++) {
            table.push_back(ch);
        }
    }
    return table;
}

void initializeWordTable(Node*& head) {
    
    Node *n1 = new Node();
    Node *n2 = new Node();
    Node *n3 = new Node();
    Node *n4 = new Node();
    Node *n5 = new Node();
    Node *n6 = new Node();
    Node *n7 = new Node();
    Node *n8 = new Node();
    Node *n9 = new Node();
    Node *n10 = new Node();
    Node *n11 = new Node();
    Node *n12 = new Node();
    Node *n13 = new Node();
    Node *n14 = new Node();
    Node *n15 = new Node();
    Node *n16 = new Node();
    n1->c = '-';
    n2->c = '-';
    n3->c = '-';
    n4->c = '-';
    n5->c = '-';
    n6->c = '-';
    n7->c = '-';
    n8->c = '-';
    n9->c = '-';
    n10->c = '-';
    n11->c = '-';
    n12->c = '-';
    n13->c = '-';
    n14->c = '-';
    n15->c = '-';
    n16->c = '-';
    
    n1->right = n2;
    n2->left = n1;
    n2->right = n3;
    n3->left = n2;
    n3->right = n4;
    n4->left = n3;
    
    n5->right = n6;
    n6->left = n5;
    n6->right = n7;
    n7->left = n6;
    n7->right = n8;
    n8->left = n7;
    
    n9->right = n10;
    n10->left = n9;
    n10->right = n11;
    n11->left = n10;
    n11->right = n12;
    n12->left = n11;
    
    n13->right = n14;
    n14->left = n13;
    n14->right = n15;
    n15->left = n14;
    n15->right = n4;
    n16->left = n15;
    
    n1->below = n5;
    n5->above = n1;
    n2->below = n6;
    n6->above = n2;
    n3->below = n7;
    n7->above = n3;
    n4->below = n8;
    n8->above = n4;
    
    n5->below = n9;
    n9->above = n5;
    n6->below = n10;
    n10->above = n6;
    n7->below = n11;
    n11->above = n7;
    n8->below = n12;
    n12->above = n8;
    
    n9->below = n13;
    n13->above = n9;
    n10->below = n14;
    n14->above = n10;
    n11->below = n15;
    n15->above = n11;
    n12->below = n16;
    n16->above = n12;
    
    head = n1;
}

void fillWordTable(Node*& head, vector<char>& table, default_random_engine &dre1, default_random_engine &dre2) {
    
    short nodeFilledIn = 0;
    Node* curr = head;
    
    while (nodeFilledIn <= 16) {
        uniform_int_distribution<int> distribution_character(0, 9998);
        int character_prob = distribution_character(dre1);
        
        if (curr->c == '-') {
            curr->c = frequencyChar(character_prob, table);
            nodeFilledIn++;
        }
        
        if (nodeFilledIn == 16) break;
        
        uniform_real_distribution<double> distribution_direction(0.0, 1.0);
        double direction_prob = distribution_direction(dre2);
        
        if (direction_prob > 0 && direction_prob < 0.25 && curr->left) {
            curr = curr->left;
        } else if (direction_prob > 0.25 && direction_prob < 0.5 && curr->right) {
            curr = curr->right;
        } else if (direction_prob > 0.5 && direction_prob < 0.75 && curr->below) {
            curr = curr->below;
        } else if (direction_prob > 0.75 && direction_prob < 1 && curr->above) {
            curr = curr->above;
        }
    }
}

void printWordTable(Node* head) {
    Node* curr = head;
    cout << curr->c << " - ";
    cout << curr->right->c << " - ";
    cout << curr->right->right->c << " - ";
    cout << curr->right->right->right->c << " - " << endl;
    curr = head->below;
    cout << curr->c << " - ";
    cout << curr->right->c << " - ";
    cout << curr->right->right->c << " - ";
    cout << curr->right->right->right->c << " - " << endl;
    curr = head->below->below;
    cout << curr->c << " - ";
    cout << curr->right->c << " - ";
    cout << curr->right->right->c << " - ";
    cout << curr->right->right->right->c << " - " << endl;
    curr = head->below->below->below;
    cout << curr->c << " - ";
    cout << curr->right->c << " - ";
    cout << curr->right->right->c << " - ";
    cout << curr->right->right->right->c << " - " << endl;
}

vector<vector<char>> wordTableToVec(Node* head) {
    vector<vector<char>> vec;
    
    Node* curr = head;
    vector<char> firstRow;
    firstRow.push_back(curr->c);
    firstRow.push_back(curr->right->c);
    firstRow.push_back(curr->right->right->c);
    firstRow.push_back(curr->right->right->right->c);
    vec.push_back(firstRow);
    curr = head->below;
    
    vector<char> secondRow;
    secondRow.push_back(curr->c);
    secondRow.push_back(curr->right->c);
    secondRow.push_back(curr->right->right->c);
    secondRow.push_back(curr->right->right->right->c);
    vec.push_back(secondRow);
    curr = head->below->below;
    
    vector<char> thirdRow;
    thirdRow.push_back(curr->c);
    thirdRow.push_back(curr->right->c);
    thirdRow.push_back(curr->right->right->c);
    thirdRow.push_back(curr->right->right->right->c);
    vec.push_back(thirdRow);
    curr = head->below->below->below;
    
    vector<char> fourthRow;
    fourthRow.push_back(curr->c);
    fourthRow.push_back(curr->right->c);
    fourthRow.push_back(curr->right->right->c);
    fourthRow.push_back(curr->right->right->right->c);
    vec.push_back(fourthRow);
    
    return vec;
}

vector<string> allFourLetterWords(vector<vector<char>>& wordVec) {
    vector<string> fourLetterWords;
    for (auto i = 0; i <= 3; i++) {
        string s1;
        s1.push_back(wordVec[i][0]);
        s1.push_back(wordVec[i][1]);
        s1.push_back(wordVec[i][2]);
        s1.push_back(wordVec[i][3]);
        fourLetterWords.push_back(s1);
        
        string s2;
        s2.push_back(wordVec[i][3]);
        s2.push_back(wordVec[i][2]);
        s2.push_back(wordVec[i][1]);
        s2.push_back(wordVec[i][0]);
        fourLetterWords.push_back(s2);
        
        string s3;
        s3.push_back(wordVec[0][i]);
        s3.push_back(wordVec[1][i]);
        s3.push_back(wordVec[2][i]);
        s3.push_back(wordVec[3][i]);
        fourLetterWords.push_back(s3);
        
        string s4;
        s4.push_back(wordVec[3][i]);
        s4.push_back(wordVec[2][i]);
        s4.push_back(wordVec[1][i]);
        s4.push_back(wordVec[0][i]);
        fourLetterWords.push_back(s4);
    }
    return fourLetterWords;
}

int main(int argc, const char *argv[]) {
    int numOfTimesRan = 0;
    unordered_map<short, int> totalFrequency;
    
    /* For simulation purposes, in this video recording, we will run 500 sample runs */
    while (++numOfTimesRan <= 500) {
    
        if (numOfTimesRan % 50 == 0) cout << numOfTimesRan << endl;
        
        vector<char> table = charTable();
        Node* head = nullptr;
        initializeWordTable(head);
        default_random_engine dre1;
        default_random_engine dre2;
        dre1.seed((unsigned int)time(NULL));
        dre2.seed((unsigned int)time(NULL));
        fillWordTable(head, table, dre1, dre2);
        vector<vector<char>> wordVec = wordTableToVec(head);
        vector<string> fourLetterWords = allFourLetterWords(wordVec);
        
        unsigned int numWords = 0;
        string line;
        ifstream file("words.txt");
        
        while (getline(file, line)) {
            if (line.size() == 5) {
                line = line.substr(0, 4);
                for (int i = 0; i < fourLetterWords.size(); i++) {
                    if (line == fourLetterWords[i]) numWords++;
                }
            }
            if (numWords == 16) break;
        }
        
        if (totalFrequency.count(numWords) == 0) {
            totalFrequency[numWords] = 1;
        } else {
            totalFrequency[numWords]++;
        }
    }
    
    for (short i = 0; i <= 16; i++) {
        cout << "i = " << i << " numWords: " << totalFrequency[i] << endl;
    }
    
    return 0;
}
