#include <algorithm>
#include <bitset>
#include <fstream>
#include <iostream>
#include <unordered_map>
#include <vector>

std::bitset<8> check(std::vector<std::bitset<15>> & H,std:: bitset<15> bsi) {
  std::bitset<8> result(0);
  for(int j = 0 ; j <= 7 ; ++j){
    result[j] = (H[j]&bsi).count()%2;
  }
  return result;
}

std::bitset<8> check_int(std::vector<std::bitset<15>> & H,int i) {
  std::bitset<15> bsi(i);
  return check(H,bsi);
}

void find_codewords_print_to_file(std::vector<std::bitset<15>> & H, std::fstream & cws) {
  std::bitset<8> res;
  for(int i = 0b0000000000000 ; i <= 0b111111111111111 ; ++i) {
    res = check(H,i);
    if (res.none()){
      cws << std::bitset<15>(i) << '\n';
    }
  }
}


int main(){
  std::fstream cws("codewords",cws.out);
  if(!cws.is_open()){
    std::cout << "codewords cannot be opened\n";
    return -1;
  }
  std::vector<std::bitset<15>> H(8);
  H[0]=std::bitset<15>("100010011010111");//M=10011 
  H[1]=std::bitset<15>("010011010111100");//0001 a0 
  H[2]=std::bitset<15>("001001101011110");//0010 a1 
  H[3]=std::bitset<15>("000100110101111");//0100 a2 
  H[4]=std::bitset<15>("100011000110001");
  H[5]=std::bitset<15>("000110001100011");
  H[6]=std::bitset<15>("001010010100101");//1000 a3 
  H[7]=std::bitset<15>("011110111101111");

  /*H[4]=std::bitset<15>("101101101101101");//0011 a4 
  H[5]=std::bitset<15>("011011011011011");//0110 a5 
  H[6]=std::bitset<15>("011011011011011");//1100 a6 
  H[7]=std::bitset<15>("000000000000000");*///1011 a7 
                		          //0101 a8 
			                  //1010 a9 
                 	                  //0111 a10
                                          //1110 a11
	                                  //1111 a12
	                                  //1101 a13
	                                  //1001 a14
  std::unordered_map<std::bitset<8>,int> error_map;
  {
    std::bitset<15> error(1);
    for(int i = 0; i<= 13; ++i) {
      error.reset();
      error[i]=1;
      for(int k = i+1; k<=14; ++k) {
	error[k]=1;
	std::cout << "checking " << error << '\n';
	error_map[check(H,error)]+=1;
	error[k]=0;
      }
    }
  }
  for(auto x: error_map) {
    std::cout << x.first << " : " << x.second << '\n';
  }
  cws.close();
}
