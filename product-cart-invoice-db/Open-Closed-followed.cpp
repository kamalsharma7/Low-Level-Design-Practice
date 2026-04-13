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
public:
    vector<product*> cartlist;

    void addproduct(product* product){
        cartlist.push_back(product);
        cout<<"product-"<<product->name<<" added sucessfully in cart"<<endl;
    }
    
    void calculatetotalprice(){
        int total_price =0;
        for(auto it:cartlist){
            total_price+=it->price;
        }
        cout<<"total price is-"<<total_price<<endl;
    }
};

class InvoicePrinter{
public:
    
    void invoicedao(Cart* cart){
        for(int i=0;i<(cart->cartlist).size();i++){
            cout<<"Invoice print for product - "<<(cart->cartlist)[i]->name<<" and price is -"<<(cart->cartlist)[i]->price<<endl;
        }
    }
};

class SaveDbDao{
public:
    
    virtual void savedbdao(Cart* cart){
        for(int i=0;i<(cart->cartlist).size();i++){
            cout<<"Product is successfully saved in db-"<<(cart->cartlist)[i]->name << "and price- "<< (cart->cartlist)[i]->price<<endl;
    }
}
};

class SaveMongoDao : public SaveDbDao{
  void savedbdao(Cart* cart) override {
      for(int i=0;i<(cart->cartlist).size();i++){
        cout<<"save in Mongo-db product -"<<(cart->cartlist)[i]->name<<endl;
      }
  }  
};

class SaveSQLDao : public SaveDbDao{
  void savedbdao(Cart* cart) override {
      for(int i=0;i<(cart->cartlist).size();i++){
        cout<<"save in SQL-db product -"<<(cart->cartlist)[i]->name<<endl;
      }
  }  
};


int main() {
    
    Cart cart1;
    cart1.addproduct(new product("perfume",400));
    cart1.addproduct(new product("dryer",1000));
    cart1.addproduct(new product("bag",1500));
    
    cart1.calculatetotalprice();
    
    InvoicePrinter invoice;
    invoice.invoicedao(&cart1);

    SaveDbDao* dbdao = new SaveMongoDao();
    dbdao->savedbdao(&cart1);
    
    SaveDbDao* dbdao2 = new SaveSQLDao();
    dbdao2->savedbdao(&cart1);
    
    return 0;
}    