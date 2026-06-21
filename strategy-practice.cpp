// startegy pattern - robot problem 

#include <bits/stdc++.h>
using namespace std;

// abstract classes
class talkrobots{
public:
    virtual void talk() =0;
    virtual ~talkrobots() = default;
};
class walkrobots{
public:
    virtual void walk()=0;
    virtual ~walkrobots() = default;
};
class flyrobots{
public:
    virtual void fly()=0;
    virtual ~flyrobots() = default;
};


//abstract classes derived classes(robot types)
class talkingrobo: public talkrobots{
public:
    void talk() override {
        cout<<"I am talking robo"<<endl;
    }
};
class walkingrobo: public walkrobots{
public:
    void walk() override {
        cout<<"I am Walking robo"<<endl;
    }
};
class runningrobo: public walkrobots{
public:
    void walk() override {
        cout<<"I am running robo"<<endl;
    }
};
class flyingrobo:public flyrobots{
public:
    void fly() override {
        cout<<"I am flying robo"<<endl;
    }
};
class flyingjetrobo:public flyrobots{
public:
    void fly() override {
        cout<<"I am Jet flying robo"<<endl;
    }
};




// Main robot class ( Client)
class robot{
public:
    talkrobots* tr;
    walkrobots* wr;
    flyrobots* fr;
    
    robot(talkrobots* trr , walkrobots* wrr , flyrobots* frr){
        if(trr!=nullptr){
            tr=trr;
        }
        if(wrr!=nullptr){
            wr=wrr;
        }
        if(frr!=nullptr){
            fr=frr;
        }
    }
    void talk(){
        if(tr) tr->talk();
        else cout<<"Cannot talk"<<endl;
    }
    void walk(){
        if(wr) wr->walk();
        else cout<<"Cannot walk"<<endl;
    }
    void fly(){
        if(fr) fr->fly();
        else cout<<"Cannot fly"<<endl;
    }
};





int main() {
    robot* r = new robot(
        nullptr,
        new runningrobo(),
        new flyingjetrobo()
    );
    r->talk();
    r->fly();
    r->walk();

    return 0;
}