//ZOMATO- FOOD DELIEVERY APP

/*
Core Functional Requirements
Users can search restaurants.
Users can view menus.
Users can add items to cart.
Users can place orders.
Users can make payments.
Restaurants can accept/reject orders.
Delivery partners can deliver orders.
Users can track orders.
Users can rate restaurants and delivery partners.


Multiple addresses per user?
Home / Office / Other addresses?

Cart management
Can cart contain items from multiple restaurants?
What if restaurant changes menu price after item is added?



Order Lifecycle
Design order states.
What states can an order have?
Can order be cancelled?
Can restaurant cancel?


Payment
COD?
UPI?
Wallet?
Refund support?


Notification
Need notifications through:
SMS
Email
Push Notification
How will you design it?


Delivery Assignment
Need multiple assignment algorithms:
Nearest Driver
Highest Rated Driver
Least Busy Driver
How will you support this?

Restaurant Search
Need different search strategies:
By Cuisine
By Rating
By Distance
How will you design?
*/


#include<bits/stdc++.h>
#include<mutex>
using namespace std;


class MenuItem{
public:
    int code;
    string name;
    double price;
};

class Restaurant{ 
public:
    int id;
    string name;
    string address;
    vector<MenuItem> menu;
};

// Singleton class
// singleton should also prevent copy constructor and assignment operatoryr
class RestaurantManager{
private:
    static RestaurantManager* instance;
    static mutex mtx;

    RestaurantManager(){
        restaurants={};
    }
public:
    vector<Restaurant> restaurants;

    static RestaurantManager* getinstance(){
        if(instance==nullptr){
            lock_guard<mutex> lock(mtx);
            if(instance==nullptr){
                instance= new RestaurantManager();
            }
        }
        return instance;
    }

    void addRestaurant(Restaurant res){
        restaurants.push_back(res);
    }
    void deleteRestaurant(Restaurant res){
        auto it = find(restaurants.begin(),restaurants.end(),res);
        if(it!=restaurants.end()){
            restaurants.erase(it);
        }
    }
};

// why this cannot be inside int main()?
RestaurantManager* RestaurantManager::instance = nullptr;
mutex RestaurantManager::mtx;

int main(){
    RestaurantManager* RM1 = RestaurantManager::getinstance();
    RestaurantManager* RM2 = RestaurantManager::getinstance();
    cout<<(RM1==RM2)<<endl;
    return 0;
}