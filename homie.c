#include <assert.h>
#include <stdint.h>
// #include <refinedc.h>
// #include <talloc.h>
// #include <refinedc_malloc.h>

[[rc::parameters("nx : nat", "ny : nat", "nz : nat")]]
[[rc::args("nx @ int<u32>", "ny @ int<u32>", "nz @ int<u32>")]]
[[rc::requires("{nx + ny ≤ max_int u32}", "{(nx + ny) + nz ≤ max_int u32}")]]
[[rc::returns("{nx + ny + nz} @ int<u32>")]]
unsigned int add3(unsigned int x, unsigned int y, unsigned int z){
  unsigned int r = x + y;
  return r + z;
}


struct [[rc::refined_by("r : nat", "g : nat", "b : nat")]] color {
  [[rc::field("r @ int<u8>")]]
  uint8_t r;

  [[rc::field("g @ int<u8>")]]
  uint8_t g;

  [[rc::field("b @ int<u8>")]]
  uint8_t b;
};


[[rc::parameters("r : nat", "g : nat", "b : nat")]]
[[rc::args("r @ int<u8>", "g @ int<u8>","b @ int<u8>")]]
[[rc::returns("{(r, g, b)} @ color")]]
struct color rgb(uint8_t r, uint8_t g, uint8_t b) {
  return (struct color){ .r = r, .g = g, .b = b };
}


[[rc::returns("{0} @ int<i32>")]]
int main(){
  unsigned int a;

  a = add3(1, 2, 3);
  assert(a == 6u);

  a = add3(a, a, a);
  assert(a == 18u);
  
  return 0;
}
