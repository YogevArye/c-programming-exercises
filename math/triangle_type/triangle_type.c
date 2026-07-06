#include "triangle_type.h"

int TriangleType(unsigned angle_a, unsigned angle_b) {
   int result = 0;
   const unsigned angle_90 = 90;
   const unsigned angle_c = 180 - (angle_a + angle_b);
   
   if (angle_a == 0 || angle_b == 0 || angle_a + angle_b >= 180) {
        return -1;  
   }
   
   if (angle_a == angle_90 || angle_b == angle_90 || angle_c == angle_90) {
        result += 1;
   }
   
   if (angle_a == angle_b || angle_a == angle_c|| angle_b == angle_c) {
      result += 2;
   }
   
   return result;
}