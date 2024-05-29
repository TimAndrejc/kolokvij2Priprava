#include <iostream>
#include "Date.h"
#include "Fuel.h"

using namespace std;

bool sortByPrice(const Fuel &f1, const Fuel &f2) {
    return f1.getPrice() > f2.getPrice();
}

int main() {
    vector<Fuel> fuel = Fuel::LoadFromFile("refuel.csv");
    /*fuel.emplace_back(Date(1, 5, 2024), 2300, 42.20, "Benzene", 23.22);
    fuel.emplace_back(Date(2, 6, 2025), 2300, 42.20, "Benzene", 23.23);
    cout << fuel[0].toString();
    Fuel::SortRefuels(fuel, sortByPrice);
    cout << fuel[0].toString();
    Fuel::saveToFile(fuel, "neki.csv");*/

}
