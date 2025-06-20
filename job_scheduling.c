#include<stdio.h>
#include<stdbool.h>
#include<string.h>
struct item {
    char id;
    double profit;
    double deadline;
};
struct item x[] = {{'A',100,2},{'B',19,1},{'C',27,2},{'D',25,1},{'E',15,3}};
int n = 5;

struct item original[5]; // To store original job order

void bubble() {
    for(int i=0; i<n-1; i++) {
        for(int j=0; j<n-1-i; j++) {
            if(x[j].profit < x[j+1].profit) {
                struct item temp = x[j];
                x[j] = x[j+1];
                x[j+1] = temp;
            }
        }
    }
}
void display() {
    for(int i=0; i<n; i++) {
        printf("(%c,%.lf,%.lf)  ",x[i].id,x[i].profit,x[i].deadline);
    }
    printf("\n");
}
int maxDeadline = 0;
int getMaxDeadline() {
    for(int i=0; i<n; i++) {
        if(x[i].deadline > maxDeadline) {
            maxDeadline = x[i].deadline;
        }
    }
    printf("MaxDeadline = %d",maxDeadline);
    return maxDeadline;
}
void jobScheduling() {
    int maxD = getMaxDeadline();
    bool slot[maxD+1];
    char y[maxD+1];
    double v[20] = {0.0};
    // for(int i=0; i<n; i++) v[i] = 0.0; // init to 0
    double profit = 0.0;
    int i;
    for(i=1; i<=maxD; i++) {
        slot[i] = false;
        // y[i] = 0;
    }
    for(i=0; i<n; i++) {
        for(int j=x[i].deadline; j>=1; j--) {
            if(slot[j] == false) {
                profit = profit + x[i].profit;
                slot[j] = true;
                y[j] = x[i].id;

                // Find index in original array
                for(int k = 0; k < n; k++) {
                    if(x[i].id == original[k].id) {
                        v[k] = 1.0;
                        break;
                    }
                }
                break;
            }
        }
    }
    printf("\nScheduled Jobs : ");
    for(i=1; i<=maxD; i++) {
        // if(slot[i]) {
            printf("%C ",y[i]);
        // }
    }
    printf("\nTotal profit = %.2lf\n",profit);
    printf("Solution vector = < ");
    for(i=0; i<n; i++) {
        printf("%.2f",v[i]);
        if(i != n-1) printf(", ");
    }
    printf(" >");
}
int main() {
    memcpy(original, x, sizeof(x)); // Save original job order

    printf("Original Jobs: ");
    display();
    bubble();
    printf("Sorted by Profit: ");
    display();
    jobScheduling();

    return 0;
}