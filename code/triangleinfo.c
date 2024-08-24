#include <stdio.h>
#include <math.h>


float calc_s(float num1, float num2, float num3) {
    float sum_of_sides = num1 + num2 + num3;
    float num = sum_of_sides / 2;
    return num;
}

float hurons_formula(float s, float a, float b, float c) {
    float smina = s - a;
    float sminb = s - b;
    float sminc = s - c;

    float stimesall = s * smina * sminb * sminc;

    float area = sqrt(stimesall);

    return area;
}

int is_valid_triangle(int side1, int side2, int side3) {
    int largest_side = side1;

    if(side2 > largest_side){
        largest_side = side2;
    }

    if(side3 > largest_side){
        largest_side = side3;
    }

    //I dont know which side is the largest before so all the sides without the largest one is the
    //sum of the two smaller sides which needs to be smaller than the largest for the triangle to be valid
    if((side1 + side2 + side3) - largest_side < largest_side) {
        return 0;
    }

    return 1;
}

int is_scalene(int side1, int side2, int side3){
    //No sides are equal is scalene
    if(side1 != side2 && side2 != side3 && side1 != side3) return 1;
    return 0;
}

int is_isosceles(int side1, int side2, int side3){
    //Any sides are equal is isosceles
    if(side1 == side2 || side2 == side3 || side1 == side3) return 1;
    return 0;
}

int is_equilateral(int side1, int side2, int side3){
    //All sides are equal is equilateral
    if(side1 == side2 && side2 == side3 && side1 == side3) return 1;
    return 0;
}

int main(int argc, char *argv[]) {

    int side1, side2, side3;

    printf("Enter Side 1: ");
    scanf("%d", &side1);
    printf("You Entered %d\n", side1);

    printf("Enter Side 2: ");
    scanf("%d", &side2);
    printf("You Entered %d\n", side2);

    printf("Enter Side 3: ");
    scanf("%d", &side3);
    printf("You Entered %d\n", side3);

    if(!is_valid_triangle(side1, side2, side3)){
        printf("Impossible");
        return 0;
    }

    if(is_equilateral(side1, side2, side3)) printf("equilateral\n");
    if(is_isosceles(side1, side2, side3)) printf("isosceles\n");
    if(is_scalene(side1, side2, side3)) printf("scalene\n");


    float s = calc_s(side1, side2, side3);
    float area = hurons_formula(s, side1, side2, side3);

    printf("area: %f\n", area);


    return 0;
}

