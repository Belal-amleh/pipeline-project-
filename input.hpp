inline void Input();

inline void Input(){

    //I Assume Max Instruction Count = 512 Instruction 
    // So i check if the number of Instruction is less than the max Instrcution Number 
    while(true){
        cout <<"Enter The  Number of instruction : ";
        cin >> InstructionNumber ;
        
        if(InstructionNumber > maxInstructionNumber)
        cout << "You Enter a Wrong number of instructions , please try again later " << endl;
        else
        break;
    }
    cin.ignore();

    // resizing the input vector to number of Inst 
    input.assign(InstructionNumber , {0,0,0});
     
    // lamda Function that check if the char is dig or not 
    auto isDig = [&](char x )
    {
        return x>= '0' && x<='9';
    };
    // reading the user input from the console 
    for(int i = 0 ; i < InstructionNumber ; ++i){
        string temp ;
        cout << "instruction #" << i+1  << ": " ;
        getline(cin,temp);
        
       // Clear string from whitespaces and dollars sign and commas to get the instruction number as a integer value 
       temp.erase( remove_if(temp.begin(),temp.end(),[] (auto c){return c=='$'|| c==',' || isspace(c);} ), temp.end()) ;        
        string temp1 ;
        //this for read reg number so i assumed that - for Ri : i is the Reg number that i wanna to check in the Dep 
       for(int i = 0 ; i < temp.size() ; ++i)
       {

          if( isDig(temp[i])){
           temp1.push_back(temp[i]);
          } 
       }
       
       input[i].dist = temp1[0] - '0';
       input[i].source1 = temp1[1] - '0';
       input[i].source2 = temp1[2] - '0';
    
    }
    

}

