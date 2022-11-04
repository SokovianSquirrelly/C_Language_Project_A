/*
 ============================================================================
 Name        : W06_Final_Project_Part_I
 Author      : Collin Squires
 Description : This first part of my final project is a geometric calculator.
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define PI 3.14159;

typedef struct RightTriangle
{
    float sideA;
    float sideB;
    double hypotenuse;
    double area;
    struct triangle* triangle;
} RightTriangle;

void calculateHypotenuse(RightTriangle* triangle)
{
    float firstSum = pow(triangle->sideA, 2) + pow(triangle->sideB, 2);
    triangle->hypotenuse = sqrt(firstSum);
}

void calculateTriangleArea(RightTriangle* triangle)
{
    triangle->area = (triangle->sideA * triangle->sideB) / 2;
}

typedef struct Circle
{
    float radius;
    double circumference;
    double area;
    struct circle* circle;
} Circle;


void calculateCircumference(Circle* circle)
{
    circle->circumference = (circle->radius * 2) * PI;
}

void calculateCircleArea(Circle* circle)
{
    circle->area = pow(circle->radius, 2) * PI;
}

typedef struct Cube
{
    float edgeLength;
    double volume;
    double surfaceArea;
    struct cube* cube;
} Cube;

void calculateCubeVolume(Cube* cube)
{
    cube->volume = pow(cube->edgeLength, 3);
}

void calculateCubeSurface(Cube* cube)
{
    cube->surfaceArea = pow(cube->edgeLength, 2) * 6;
}

typedef struct Sphere
{
    float radius;
    double surfaceArea;
    double volume;
    struct sphere* sphere;
} Sphere;

void calculateSphereSurface(Sphere* sphere)
{
    sphere->surfaceArea = 4 * pow(sphere->radius, 3) * PI;
}

void calculateSphereVolume(Sphere* sphere)
{
    sphere->volume = (sphere->surfaceArea / 3);
}

int main()
{
    printf("Welcome to the geometric calculator!");
    int choice = -1;
    while (choice != 0)
    {
        printf("Please select an option.\n");
        printf("  1) Calculate a right triangle's hypotenuse and area\n");
        printf("  2) Calculate a circle's circumference and area\n");
        printf("  3) Calculate a cube's volume and surface area\n");
        printf("  4) Calculate a sphere's volume and surface area\n");
        printf("  0) Quit\n");
        printf("Selection: ");
        scanf("%d", &choice);
        printf("\n");

        switch (choice)
        {
            case 0:
                printf("Thanks for your participation!\n");
                break;

            case 1:
                struct RightTriangle* triangle = malloc(sizeof(RightTriangle));
                printf("Enter the length of side A: ");
                scanf("%f", &triangle->sideA);
                printf("Enter the length of side B: ");
                scanf("%f", &triangle->sideB);

                calculateHypotenuse(triangle);
                calculateTriangleArea(triangle);

                printf("Your triangle has a hypotenuse of %f", triangle->hypotenuse);
                printf(" and an area of %f.\n", triangle->area);
                printf("\n");

                free(triangle);
                break;

            case 2:
                struct Circle* circle = malloc(sizeof(Circle));
                printf("Enter the radius: ");
                scanf("%f", &circle->radius);
            
                calculateCircumference(circle);
                calculateCircleArea(circle);

                printf("Your circle has a circumference of %f", circle->circumference);
                printf(" and an area of %f.\n", circle->area);
                printf("\n");

                free(circle);
                break;

            case 3:
                struct Cube* cube = malloc(sizeof(Cube));
                printf("Enter the edge length: ");
                scanf("%f", &cube->edgeLength);

                calculateCubeSurface(cube);
                calculateCubeVolume(cube);

                printf("Your cube has a surface area of %f", cube->surfaceArea);
                printf(" and a volume of %f.\n", cube->volume);
                printf("\n");

                free(cube);
                break;

            case 4:
                struct Sphere* sphere = malloc(sizeof(Sphere));
                printf("Enter the radius: ");
                scanf("%f", &sphere->radius);

                calculateSphereSurface(sphere);
                calculateSphereVolume(sphere);

                printf("Your sphere has a surface area of %f", sphere->surfaceArea);
                printf(" and a volume of %f.\n", sphere->volume);
                printf("\n");

                free(sphere);
                break;

            default:
                printf("That isn't a valid input.\n\n");
                break;
        }
    }

    return EXIT_SUCCESS;
}