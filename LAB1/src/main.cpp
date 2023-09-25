//#include <iostream>
//
//#include "BitArray.h"
//
//int main(int argc, char * argv[]) {
//
//    BitArray bitArray;
//
//    bitArray.push_back(true);
//    bitArray.push_back(false);
//    bitArray.push_back(true);
//    bitArray.push_back(true);
//    bitArray.push_back(true);
//    bitArray.push_back(false);
//    bitArray.push_back(true);
//    bitArray.push_back(false);
//    bitArray.push_back(true);
//
//
//    BitArray bitArray1;
//
//    bitArray1 = BitArray(bitArray);
//
//    bitArray1.push_back(false);
//
//    std::cout << bitArray.to_string() << std::endl;
//    std::cout << bitArray1.to_string() << std::endl;
//
//    std::cout << bitArray.count() << std::endl;
//    std::cout << bitArray.any() << std::endl;
//    std::cout << bitArray.none() << std::endl;
//
//    BitArray bitArray2 = BitArray(4, 32);
//
//    std::cout << bitArray2.to_string() << std::endl;
//
//    bitArray2.push_back(true);
//
//    std::cout << bitArray2.to_string() << std::endl;
//
//    bitArray2.set(10, true);
//
//    std::cout << bitArray2.to_string() << std::endl;
//    std::cout << bitArray2[10] << std::endl;
//    std::cout << bitArray2[9] << std::endl;
//
//    std::cout << (~bitArray2).to_string() << std::endl;
//
//    return 0;
//}
