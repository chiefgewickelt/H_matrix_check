#include "finite_field.hpp"
/*
#include <iostream>
#include <cmath>

size_t two_to_the(size_t e){
  size_t result = 1;
  for(int i = 0 ; i < e; ++i) {
    result*=2;
  }
  return result;
}
template<size_t N>
std::bitset<N> shift_and_xor(std::bitset<N> a, std::bitset<N+1> gp) {
  a<<=1;
  int i = 0;
  for(auto& x : a) {
    x ^= gp[++i];
  }
  return a;
};

template <size_t L>
void Finite_Field<L>::show_alphas() {
  int i = -1;
  for(auto x : alphas){
    std::cout << "alpha " << (++i) << " : " << x << '\n'; 
  }
};

/*template <size_t L>
void Finite_Field<L>::generate_alphas(std::bitset<L> gp){
  alphas.resize(two_to_the(L)-1);
  alphas[0] = std::bitset<L-1>(1);
  for(int i = 1 ; i < alphas.size(); ++i) {
    alphas[i] = shift_and_xor(alpha[i-1],gp);
  }
  };*/
/*
template <size_t L>
Finite_Field<L>::Finite_Field(std::bitset<L> generator_polonomial) {
  alphas.resize(two_to_the(L)-1);
  alphas[0] = std::bitset<L-1>(1);
  for(int i = 1 ; i < alphas.size(); ++i) {
    alphas[i] = shift_and_xor(alphas[i-1],generator_polonomial);
  }
  };*/
