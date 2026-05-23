#include<filesystem>
#include<algorithm>
#include<iostream>
#include<cstdlib> 
#include<numeric>
#include<fstream>
#include<string>
#include<vector>
#include<ranges>
#include<cctype>
#include<map>

#define endl '\n'
using namespace std;

const int maxInstructionNumber = 512;
int InstructionNumber ;

// A component  for the input  [Dist , Source1 , Source2 ]
struct comp{
    int dist ;
    int source1 ;
    int source2 ;
}; 

// This map is for R fromat isntructions operations 
const map<string , int> op = {{"add",1} , {"sub", 1} , {"and" , 1} , {"or", 1}, {"slt",1}};

vector<comp> input ; // input vector for handling Reg number 

//2D vectors for handling the two ways of instructions 
vector<vector<int>> stallForwarding;
vector<vector<int>> reorderingForwarding;

vector<int> order ; // The instrcutions ordering

//Header Files
#include"input.hpp"
#include "stallForwarding.hpp"
#include "reorderingForwarding.hpp"
#include"Dep.hpp" 

int main()
{
    
    
    Input();
    WriteDepstype();
    calStallForwarding();
    
    ofstream out("StallForwarding.txt");
    for(int i = 0 ; i < InstructionNumber ; ++i){

        for(int j = 0 ; j < stallForwarding[0].size(); ++j)
         out << stallForwarding[i][j] << " ";
        
      out << endl;
    }

    out.close();
    out.open("speedUp1.txt");
    out << "Speed Up = " << (5.f * InstructionNumber) / (InstructionNumber + 4)  << endl;
    out.close();

    calReorderingForwarding();
    ofstream out1("reorderingForwarding.txt");

    for(int i = 0 ; i  < InstructionNumber ; ++i){

        for(int j = 0 ; j < reorderingForwarding[0].size(); ++j)
         out1  << reorderingForwarding[i][j] << " ";

      out1 << endl;
    }
    out1.close();

     ofstream outputFile("order.txt");
        for (int i = 0; i < InstructionNumber; ++i) {
            outputFile << "I" << order[i] << endl;
     }

     
     outputFile << endl;
     outputFile.close();
     out1.open("speedUp2.txt");
     out1 << "Speed Up = " << (5.f * InstructionNumber) / (InstructionNumber + 4)  << endl;
     out1.close();
     
     //Python script to run  Visualization file from main 
    const string py_file = "visuals.py";   

    // Pass current working directory 
    string workdir = std::filesystem::current_path().string();

#ifdef _WIN32
    string cmd = "py \"" + py_file + "\" \"" + workdir + "\"";
#else
    string cmd = "python3 \"" + py_file + "\" \"" + workdir + "\"";
#endif

    cout << "Running visualization: " << cmd << endl;
    cout.flush();

    int rc = system(cmd.c_str());
    if (rc != 0) {
        cerr << "Visualization failed. Exit code = " << rc << endl;
    }

    return 0 ;
}