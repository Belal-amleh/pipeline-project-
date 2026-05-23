#include <fstream>
#include <string>

using namespace std;

// function to check the dep of the instructions 
inline void WriteDepstype() {

    ofstream out("Dep.txt");
  
    out << "===== Dependency Analysis ===============\n";
   

    int n = input.size();
    bool RAW = 0 , WAW = 0 , WAR = 0 ;

    for (int i = 0; i < n; ++i) {
        out << "I" << (i+1) << ": R"
            << input[i].dist << " R"
            << input[i].source1 << " R"
            << input[i].source2 << "\n";
    }

    out << endl;

    for (int i = 0; i < n; ++i) {
        int dA = input[i].dist;
        int a1 = input[i].source1;
        int a2 = input[i].source2;

        for (int j = i + 1; j < n; ++j) {
            int dB = input[j].dist;
            int b1 = input[j].source1;
            int b2 = input[j].source2;

            // RAW:
            if (b1 == dA || b2 == dA) {
                RAW = 1 ;
                out << "I" << (j+1) << " depends on I" << (i+1)
                    << " (RAW) on  R" << dA << "\n";
            }

            // WAR:
            if (a1 == dB || a2 == dB) {
                WAR=1;
                out << "I" << (j+1) << " and I" << (i+1)
                    << " (WAR) on R" << dB << "\n";
            }

            // WAW:
            if (dA == dB) {
                WAR =1 ;
                out << "I" << (j+1) << " and I" << (i+1)
                    << " (WAW) on  R" << dA << "\n";
            }
        }
    }
    if(!WAW && !WAR && !RAW )
    out<< "NO Dependencies  " << endl;
    out.close();

}
