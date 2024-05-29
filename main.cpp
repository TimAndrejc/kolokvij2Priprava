#include <iostream>
#include "Date.h"
#include "Fuel.h"

using namespace std;

bool sortByPrice(const Fuel &f1, const Fuel &f2) {
    return f1.getPrice() > f2.getPrice();
}

bool ascendingPricesPerLiter(const Fuel &refuel1, const Fuel &refuel2) {
    return refuel1.getPrice() < refuel2.getPrice();
}

bool descendingPricesPerLiter(const Fuel &refuel1, const Fuel &refuel2) {
    return refuel1.getPrice() > refuel2.getPrice();
}


int main() {
    vector<Fuel> fuel;
    try {
        fuel = Fuel::LoadFromFile("refuel.csv");
    } catch (FileNotFoundException &e) {
        cout << e.what();
    }
    fuel.emplace_back(Date(1, 5, 2024), 2300, 42.20, "Benzene", 23.22);
    fuel.emplace_back(Date(2, 6, 2025), 2300, 42.20, "Benzene", 23.23);
    Fuel::SortRefuels(fuel, descendingPricesPerLiter);
    cout << fuel;
    //Fuel::saveToFile(fuel, "neki.csv");
    //cout << Fuel::avgPricePerLiter(3, 1.23, 1.23, 1.23);

}
