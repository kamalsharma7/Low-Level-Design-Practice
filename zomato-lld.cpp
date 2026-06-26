#include<bits/stdc++.h>
#include<mutex>
using namespace std;


class MenuItem{
public:
    int code;
    string name;
    double price;

    MenuItem(int code1 , string name1 , double price1){
        code=code1;
        name=name1;
        price=price1;
    }
};

class Restaurant{ 
public:
    int id;
    string name;
    string address;
    vector<MenuItem> menu;

    Restaurant(int id1,string name1 , string address1 , vector<MenuItem> &menu1){
        id=id1;
        name=name1;
        address=address1;
        menu=menu1;
    }

    bool operator==(const Restaurant& other) const{
        return id==other.id;
    }
};

// Singleton class
// singleton should also prevent copy constructor and assignment operatoryr
class RestaurantManager{
private:
    static RestaurantManager* instance;
    static mutex mtx;
    vector<Restaurant> restaurants;

    RestaurantManager(){
        restaurants={};
    }
public:
    static RestaurantManager* getinstance(){
        if(instance==nullptr){
            lock_guard<mutex> lock(mtx);
            if(instance==nullptr){
                instance= new RestaurantManager();
            }
        }
        return instance;
    }

    void addRestaurant(int id ,string name , string address ,vector<MenuItem> menu){
        Restaurant new_res(id,name,address,menu);
        restaurants.push_back(new_res);
        return;
    }
    void deleteRestaurant(Restaurant res){
        auto it = find(restaurants.begin(),restaurants.end(),res);
        if(it!=restaurants.end()){
           restaurants.erase(it);
        }
        return;
    }

    void listRestaurants(){
        for(Restaurant it : restaurants){
            cout<<"restaurtant id - "<<it.id<<endl;
            cout<<"restaurtant name - "<<it.name<<endl;
            cout<<"restaurtant address - "<<it.address<<endl;
            cout<<"Menu-"<<endl;
            for(MenuItem dish : it.menu){
                cout<<"dish - "<<dish.name<<" and price - "<<dish.price<<endl;
            }
            cout<<endl;
        }
        return;
    }
};

RestaurantManager* RestaurantManager::instance = nullptr;
mutex RestaurantManager::mtx;

int main(){
    RestaurantManager* RM1 = RestaurantManager::getinstance();
    RM1->addRestaurant(1,"Barista","cyberhub",{MenuItem(1,"cold coffee" , 270.00) , MenuItem(2,"samosa" , 80.00)});
    RM1->addRestaurant(1,"Haldiram","Ambience mall",{MenuItem(1,"chole bhature" , 300.00) , MenuItem(2,"Aloo tikki" , 140.00)});

    RM1->listRestaurants();
    return 0;
}