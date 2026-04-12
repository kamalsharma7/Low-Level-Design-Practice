#include <bits/stdc++.h>
using namespace std;

class product{
public:
    string name;
    int price;
    
    product(string name , int price){
        this->name=name;
        this->price =price;
    }
};

class Cart{
private:
    vector<product*> cartlist;
public:
    void addproduct(product* product){
        cartlist.push_back(product);
        cout<<"product-"<<product->name<<" added sucessfully in cart"<<endl;
    }
    
    void invoicedao(){
        for(int i=0;i<cartlist.size();i++){
            cout<<"Invoice print for product - "<<cartlist[i]->name<<" and price is -"<<cartlist[i]->price<<endl;
        }
    }
    
    void savedbdao(){
        cout<<"all the items are successfully saved in db";
    }
};

int main() {
    //product p("acer",8000);
    //cout<<"price is-"<<p.price<<" and name is-"<<p.name;
    
    Cart cart1;
    cart1.addproduct(new product("perfume",400));
    cart1.addproduct(new product("dryer",1000));
    cart1.addproduct(new product("bag",1500));
    
    cart1.invoicedao();
    
    cart1.savedbdao();
    
    return 0;
}    