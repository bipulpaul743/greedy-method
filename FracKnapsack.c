#include<stdio.h>
typedef struct item {
    char id;
    double profit;
    double weight;
}knapsack;
knapsack x[] = {{'A',10,2},{'B',5,3},{'C',15,5},{'D',7,7},{'E',6,1},{'F',18,4},{'G',3,1}};
int n = 7;
void bubble() {
    for(int i=0; i<n-1; i++) {
        for(int j=0; j<n-1-i; j++) {
            if(x[j].profit/x[j].weight < x[j+1].profit/x[j+1].weight) {
                knapsack temp = x[j];
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
int W = 15;
double y[20] = {0.0};
void FracKnapsack() {
    int M = W;
    double profit = 0.0;
    int i;
    for(i=0; i<n; i++) {
        if(M>0 && x[i].weight <= M) {
            y[i] = 1.0;
            M = M-x[i].weight;
        }
        else break;
    }
    if(i<n) y[i] = M/x[i].weight;
    //print
    for(i=0; i<n; i++) {
        if(y[i] != 0.0) {
            printf("%c -> %.4lf\n",x[i].id, y[i]*x[i].profit);
            profit = profit + x[i].profit*y[i];
        }
    }
    printf("Total Profit = %lf\n",profit);
}
int main() {
    display();
    bubble();
    display();
    FracKnapsack();

    return 0;
}