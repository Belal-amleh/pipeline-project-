inline void calStallForwarding();


// forwarding  method that push the instruction in MIPS Stages 
 /*
    -2: Empty
    -1: stall
     0: "IF",
     1: "ID",
     2: "EX",
     3: "MEM",
     4: "WB",
     
*/
inline void calStallForwarding() {

    stallForwarding.assign(InstructionNumber,{});

    for(int i = 0 ; i < InstructionNumber ; ++i){
        for(int j = 0 ; j < i ; ++j)
          stallForwarding[i].push_back(-2);
        
          for(int j = 0 ; j < 5 ; ++j)
           stallForwarding[i].push_back(j);
           while((int)stallForwarding[i].size() < 5 + InstructionNumber - 1){
            stallForwarding[i].push_back(-2);
           }
    }
}