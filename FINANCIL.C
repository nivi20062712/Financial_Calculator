#include <stdio.h>
#include <math.h>

// ===== Global Variables =====
float income, savings;
float invest_mf, invest_gold, invest_equity, invest_us;
int years;

// ===== Function Declarations =====
void financialPlan();
void lumpSumCalculator();
void sipCalculator();
float calculateSIP(float monthly_investment, float annual_rate, int years, const char name[]);

// ===== Main Function =====
int main() {
    int choice;

    printf("\n========== FINANCIAL CALCULATOR ==========\n");
    printf("1. Financial Plan\n");
    printf("2. Future Value (Lump Sum)\n");
    printf("3. SIP Calculator\n");
    printf("==========================================\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            financialPlan();
            break;
        case 2:
            lumpSumCalculator();
            break;
        case 3:
            sipCalculator();
            break;
        default:
            printf("\nInvalid choice! Please try again.\n");
    }

    printf("\n==========================================\n");
    printf("This is a rough estimation based on average returns.\n");
    printf("All investments are subject to market risks.\n");
    printf("Thank you for using our calculator!\n");
    printf("==========================================\n");

    return 0;
}

// ===== Function 1 – Financial Plan =====
void financialPlan() {
    int option;
    float exp;
    float pct_mf, pct_gold, pct_equity, pct_us, total_pct;

    printf("\nEnter Monthly Income (Rs): ");
    scanf("%f", &income);

    exp = (income * 60) / 100;
    savings = (income * 40) / 100;

    printf("\nExpenses (60%%): Rs %.2f", exp);
    printf("\nSavings & Investments (40%%): Rs %.2f\n", savings);

    printf("\n1. Auto Split (default ratios)");
    printf("\n2. Custom Allocation");
    printf("\nSelect (1/2): ");
    scanf("%d", &option);

    if (option == 1) {
        invest_mf = (savings * 50) / 100;
        invest_gold = (savings * 20) / 100;
        invest_equity = (savings * 20) / 100;
        invest_us = (savings * 10) / 100;
    } 
    else if (option == 2) {
        printf("\nEnter custom allocation percentages:\n");
        printf("Mutual Funds: ");
        scanf("%f", &pct_mf);
        printf("Gold: ");
        scanf("%f", &pct_gold);
        printf("Equity: ");
        scanf("%f", &pct_equity);
        printf("US Stocks: ");
        scanf("%f", &pct_us);

        total_pct = pct_mf + pct_gold + pct_equity + pct_us;
        if (total_pct != 100) {
            printf("\nError: Percentages must add up to 100! (You entered %.2f)\n", total_pct);
            return;
        }

        invest_mf = (savings * pct_mf) / 100;
        invest_gold = (savings * pct_gold) / 100;
        invest_equity = (savings * pct_equity) / 100;
        invest_us = (savings * pct_us) / 100;
    } 
    else {
        printf("\nInvalid selection.\n");
        return;
    }

    printf("\n===== Investment Allocation =====\n");
    printf("Mutual Funds : Rs %.2f\n", invest_mf);
    printf("Gold         : Rs %.2f\n", invest_gold);
    printf("Equity       : Rs %.2f\n", invest_equity);
    printf("US Stocks    : Rs %.2f\n", invest_us);

    printf("\nWould you like to calculate:\n1. Lump Sum\n2. SIP\nOther to Exit\nEnter choice: ");
    scanf("%d", &option);

    if (option == 1) lumpSumCalculator();
    else if (option == 2) sipCalculator();
}

// ===== Function 2 – Lump Sum Calculator =====
void lumpSumCalculator() {
    if (invest_mf == 0 && invest_gold == 0 && invest_equity == 0 && invest_us == 0) {
        printf("\nEnter your investment values manually:\n");
        printf("Mutual Funds (Rs): ");
        scanf("%f", &invest_mf);
        printf("Gold (Rs): ");
        scanf("%f", &invest_gold);
        printf("Equity (Rs): ");
        scanf("%f", &invest_equity);
        printf("US Stocks (Rs): ");
        scanf("%f", &invest_us);
    }

    printf("\nEnter number of years: ");
    scanf("%d", &years);

    float fv_mf = invest_mf * pow((1 + 0.13), years);
    float fv_gold = invest_gold * pow((1 + 0.09), years);
    float fv_equity = invest_equity * pow((1 + 0.15), years);
    float fv_us = invest_us * pow((1 + 0.10), years);
    float total_fv = fv_mf + fv_gold + fv_equity + fv_us;

    printf("\n===== Future Value After %d Years =====\n", years);
    printf("Mutual Funds : Rs %.2f\n", fv_mf);
    printf("Gold         : Rs %.2f\n", fv_gold);
    printf("Equity       : Rs %.2f\n", fv_equity);
    printf("US Stocks    : Rs %.2f\n", fv_us);
    printf("------------------------------------------\n");
    printf("Total Future Value: Rs %.2f\n", total_fv);
    printf("------------------------------------------\n");
}

// ===== Function 3 – SIP Calculator =====
void sipCalculator() {
    printf("\n===== SIP CALCULATOR =====\n");
    printf("Enter monthly investment (Rs):\n");
    printf("Mutual Funds: ");
    scanf("%f", &invest_mf);
    printf("Gold: ");
    scanf("%f", &invest_gold);
    printf("Equity: ");
    scanf("%f", &invest_equity);
    printf("US Stocks: ");
    scanf("%f", &invest_us);

    printf("Enter number of years: ");
    scanf("%d", &years);

    float total_invested = 0, total_future_value = 0;

    if (invest_mf > 0) {
        total_future_value += calculateSIP(invest_mf, 12, years, "Mutual Funds");
        total_invested += invest_mf * years * 12;
    }
    if (invest_gold > 0) {
        total_future_value += calculateSIP(invest_gold, 9, years, "Gold");
        total_invested += invest_gold * years * 12;
    }
    if (invest_equity > 0) {
        total_future_value += calculateSIP(invest_equity, 13, years, "Equity");
        total_invested += invest_equity * years * 12;
    }
    if (invest_us > 0) {
        total_future_value += calculateSIP(invest_us, 10, years, "US Stocks");
        total_invested += invest_us * years * 12;
    }

    float total_profit = total_future_value - total_invested;

    printf("\n==========================================\n");
    printf(" TOTAL INVESTMENT : Rs %.2f\n", total_invested);
    printf(" TOTAL FUTURE VALUE: Rs %.2f\n", total_future_value);
    printf(" TOTAL PROFIT      : Rs %.2f\n", total_profit);
    printf("==========================================\n");
}

// ===== SIP Calculation Function =====
float calculateSIP(float monthly_investment, float annual_rate, int years, const char name[]) {
    int n = years * 12;
    float monthly_rate = annual_rate / 100 / 12;
    float future_value = monthly_investment * (pow((1 + monthly_rate), n) - 1) * (1 + monthly_rate) / monthly_rate;
    float total_invested = monthly_investment * n;
    float profit = future_value - total_invested;

    printf("\n--- %s ---\n", name);
    printf("Total Invested : Rs %.2f\n", total_invested);
    printf("Future Value   : Rs %.2f\n", future_value);
    printf("Profit         : Rs %.2f\n", profit);

    return future_value;   // return FV for total calculation
}


