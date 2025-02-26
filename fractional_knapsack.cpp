#include<bits/stdc++.h>
using namespace std;
class Product
{
    public:
    int price;
    int weight;
    double ratio;
};
int main()
{
    int capacity;
    cout << "Enter the capacity: ";
    cin >> capacity;
    int n;
    cout << "Enter number of products: ";
    cin >> n;
    Product product[n];
    cout << "Enter price and weight of each product: ";
    for(int i = 0; i < n; i++)
    {
        cin >> product[i].price >> product[i].weight;
        product[i].ratio = (double)product[i].price / product[i].weight;
    }
    for(int i = 0; i < n - 1; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            if(product[i].ratio < product[j].ratio)
            {
                swap(product[i], product[j]);
            }
        }
    }
    double total_price = 0;
    for(int i = 0; i < n; i++)
    {
        if(capacity >= product[i].weight)
        {
            capacity -= product[i].weight;
            total_price += product[i].price;
        }
        else
        {
            total_price += (double)capacity * product[i].ratio;
            break;
        }
    }
    cout << "Total price: " << total_price << '\n';
    return 0;
}