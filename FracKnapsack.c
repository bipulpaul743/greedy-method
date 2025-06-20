#include<stdio.h>
#include<string.h>
struct item {
    char id;
    double profit;
    double weight;
};
struct item x[] = {{'A',10,2},{'B',5,3},{'C',15,5},{'D',7,7},{'E',6,1},{'F',18,4},{'G',3,1}};
int n = 7;
struct item original[7];
void bubble() {
    for(int i=0; i<n-1; i++) {
        for(int j=0; j<n-1-i; j++) {
            if(x[j].profit/x[j].weight < x[j+1].profit/x[j+1].weight) {
                struct item temp = x[j];
                x[j] = x[j+1];
                x[j+1] = temp;
            }
        }
    }
}
void display() {
    for(int i=0; i<n; i++) {
        printf("(%c,%.lf,%.lf)  ",x[i].id,x[i].profit,x[i].weight);
    }
    printf("\n");
}
int M = 15;
double y[20] = {0.0};
double solution[20] = {0.0}; // solution[i]: fractional part in original order
void FracKnapsack() {
    int w = M;
    double profit = 0.0;
    int i;
    for(i=0; i<n; i++) {
        if(x[i].weight > w) break;
        y[i] = 1.0;
        w = w-x[i].weight;
    }
    if(i < n) y[i] = w/x[i].weight;

    // Map y[i] (sorted) to original index
    for(int i = 0; i < n; i++) {
        for(int k = 0; k < n; k++) {
            if(x[i].id == original[k].id) {
                solution[k] = y[i];
                break;
            }
        }
    }
    
    for(i=0; i<n; i++) {
        if(y[i] != 0.0) {
            printf("%c -> %.4lf\n",x[i].id,y[i]*x[i].profit);
        }
        profit = profit+y[i]*x[i].profit;
    }
    printf("Total Profit = %lf\n",profit);
    printf("Solution vector = < ");
    for(i=0; i<n; i++) {
        printf("%.2f",solution[i]);
        if(i != n-1) printf(", ");
    }
    printf(" >");
}
int main() {
    memcpy(original, x, sizeof(x));
    
    printf("Original array: ");
    display();
    bubble();
    printf("Sorted by Profit / weight: ");
    display();
    FracKnapsack();

    return 0;
}