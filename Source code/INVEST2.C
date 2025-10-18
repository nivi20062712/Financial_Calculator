#include <stdio.h>
#include <math.h>

// ===== Global Variables =====
float inc, sav;
float mf, gd, eq, ut;
float ptmf, ptgd, pteq, ptut;
float vmf, vgd, veq, vut, vtotal;
int years;

// ===== Function Declarations =====
void financialPlan();
void lumpsum();
void sip();
void calculateSIP(float p, float rate, int years, char name[]);  //Function prototype

int main()
{
    int choice;

    printf("$ FINANCIAL CALCULATOR $\n");
    printf("1. FINANCIAL PLAN\n");
    printf("2. FUTURE VALUE (LUMP SUM)\n");
    printf("3. SIP CALCULATOR\n");
    printf("Select your choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
	financialPlan();
	break;

    case 2:
	lumpsum();
	break;

    case 3:
    float total;
	printf("Enter monthly investment in Mutual Fund: Rs");
	scanf("%f", &mf);
	printf("Enter monthly investment in Gold: Rs");
	scanf("%f", &gd);
	printf("Enter monthly investment in Equity: Rs");
	scanf("%f", &eq);
	printf("Enter monthly investment in US stocks: Rs");
	scanf("%f", &ut);

	printf("Enter the number of years: ");
	scanf("%d", &years);
    if(mf!=0){
	calculateSIP(mf, 12, years, "Mutual Funds");
    }
    if(gd!=0){
	calculateSIP(gd, 9, years, "Gold");
    }
    if(eq!=0){
	calculateSIP(eq, 13, years, "Equity");
    }
    if(ut!=0){
	calculateSIP(ut, 10, years, "US Stocks");
    }
	printf("\n\n");
	printf("This is a rough calculation based on average returns.\nThis is for you to understanding purpose.");
	printf("\nThese things are subjected to market risk.");
	printf("\n\nTHANK YOU FOR USING OUR CALCULATOR!!");
	break;

    default:
	printf("Invalid choice\n");
    }

    return 0;
}

// ===== Function 1 – Financial Plan =====
void financialPlan()
{
    int selection, num;
    float exp, total;

    printf("\nEnter Monthly Income: ");
    scanf("%f", &inc);

    exp = (inc * 60) / 100;
    sav = (inc * 40) / 100;

    printf("EXPENSES (60%%): %.2f\n", exp);
    printf("SAVINGS & INVESTMENTS (40%%): %.2f\n\n", sav);

    printf("1. Auto split\n2. Custom allocation\n");
    printf("Select (1/2): ");
    scanf("%d", &selection);

    if (selection == 1)
    {
	printf("\n===== INVESTMENT SPLIT =====\n");
	mf = (sav * 50) / 100;
	gd = (sav * 20) / 100;
	eq = (sav * 20) / 100;
	ut = (sav * 10) / 100;
    }
    else if (selection == 2)
    {
	printf("\n===== PERSONAL ALLOCATIONS =====\n");
	printf("Enter your percentage for Mutual Funds: ");
	scanf("%f", &ptmf);
	printf("Enter your percentage for Gold: ");
	scanf("%f", &ptgd);
	printf("Enter your percentage for Equity: ");
	scanf("%f", &pteq);
	printf("Enter your percentage for US Stocks: ");
	scanf("%f", &ptut);

	total = ptmf + ptgd + pteq + ptut;

	if (total != 100)
	{
	    printf("\nError: Investment percentages must add up to 100 (You entered %.2f).\n", total);
	    return;
	}

	mf = (sav * ptmf) / 100;
	gd = (sav * ptgd) / 100;
	eq = (sav * pteq) / 100;
	ut = (sav * ptut) / 100;
    }

    printf("\n===== INVESTMENT ALLOCATION =====\n");
    printf("Mutual Funds: %.2f\n", mf);
    printf("Gold        : %.2f\n", gd);
    printf("Equity      : %.2f\n", eq);
    printf("US Stocks   : %.2f\n", ut);

    printf("\n1. Calculate Lumpsum or 2. SIP Calculator (1/2 or other to exit): ");
    scanf("%d", &num);

    if (num == 1)
	lumpsum();
    else if (num == 2)
	sip();
    else
	printf("\n\nTHANK YOU FOR USING OUR CALCULATOR!!");
}

// ===== Function 2 – Lumpsum =====
void lumpsum()
{
    if (mf == 0 && gd == 0 && eq == 0 && ut == 0)
    {
	printf("\n\nPlease enter your investment values manually\n");
	printf("Mutual Funds: ");
	scanf("%f", &mf);
	printf("Gold: ");
	scanf("%f", &gd);
	printf("Equity: ");
	scanf("%f", &eq);
	printf("US Stocks: ");
	scanf("%f", &ut);
    }

    printf("\n===== FUTURE VALUE CALCULATOR =====\n");
    printf("Enter the number of years: ");
    scanf("%d", &years);

    vmf = mf * pow((1 + 0.13), years);
    vgd = gd * pow((1 + 0.09), years);
    veq = eq * pow((1 + 0.15), years);
    vut = ut * pow((1 + 0.10), years);
    vtotal = vmf + vgd + veq + vut;

    printf("\nThe value of investments after %d years\n", years);
    printf("Mutual Funds: %.2f\n", vmf);
    printf("Gold        : %.2f\n", vgd);
    printf("Equity      : %.2f\n", veq);
    printf("US Stocks   : %.2f\n", vut);
    printf("==============================\n");
    printf("Total Future Value: %.2f\n", vtotal);
    printf("==============================\n");
    printf("\n\n");
	printf("This is a rough calculation based on average returns.\nThis is for you to understanding purpose.");
	printf("\nThese things are subjected to market risk.");
	printf("\n\nTHANK YOU FOR USING OUR CALCULATOR!!");
}

// ===== Function 3 – SIP =====
void sip()
{
    printf("\n===== SIP CALCULATOR =====\n");
    printf("Enter monthly investment in Mutual Fund: Rs");
    scanf("%f", &mf);
    printf("Enter monthly investment in Gold: Rs");
    scanf("%f", &gd);
    printf("Enter monthly investment in Equity: Rs");
    scanf("%f", &eq);
    printf("Enter monthly investment in US Stocks: Rs");
    scanf("%f", &ut);
    printf("Enter the number of years: ");
    scanf("%d", &years);

    calculateSIP(mf, 12, years, "Mutual Funds");
    calculateSIP(gd, 9, years, "Gold");
    calculateSIP(eq, 13, years, "Equity");
    calculateSIP(ut, 10, years, "US Stocks");
    printf("\n\n");
   	printf("This is a rough calculation based on average returns.\nThis is for you to understanding purpose.");
	printf("\nThese things are subjected to market risk.");
	printf("\n\nTHANK YOU FOR USING OUR CALCULATOR!!");
    
}

// ===== SIP Calculation Function =====
void calculateSIP(float p, float rate, int years, char name[])
{
    int n = years * 12;
    float r = rate / 100.0;
    float fv, total_investment, profit;

    fv = p * (pow((1 + r / 12), n) - 1) / (r / 12) * (1 + r / 12);
    total_investment = p * n;
    profit = fv - total_investment;

    printf("\n--- %s Investment ---", name);
    printf("\nTotal Investment: Rs%.2f", total_investment);
    printf("\nFuture Value: Rs%.2f", fv);
    printf("\nProfit: Rs%.2f\n", profit);
    
    
}