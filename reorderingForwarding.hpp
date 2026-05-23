
inline void calReorderingForwarding();



 // Reordaring forwarding  method that push the instruction in MIPS Stages 
 /*
    -2: Empty
    -1: stall
     0: "IF",
     1: "ID",
     2: "EX",
     3: "MEM",
     4: "WB",
     
*/

inline void calReorderingForwarding(){
    
    reorderingForwarding.assign(InstructionNumber,{});

    for(int i = 0 ; i < InstructionNumber ; ++i){
        for(int j = 0 ; j < i; ++j)
            reorderingForwarding[i].push_back(-2);
        
        for(int j = 0 ; j < 5 ; ++j)
            reorderingForwarding[i].push_back(j);
        while((int)reorderingForwarding[i].size() < 5 + InstructionNumber - 1 ){
            reorderingForwarding[i].push_back(-2);
        }
        
    }

    order.assign(InstructionNumber , 0);
    iota(order.begin(), order.end(),1);


}