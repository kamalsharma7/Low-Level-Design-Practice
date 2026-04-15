// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

class doceditor{
 public:
    vector<string> docelements;
    
    void addText(string element){
        docelements.push_back(element);
    }
    void addImage(string element){
        docelements.push_back(element);
    }
    string renderDoc(){
        string result;
        for(string it : docelements){
            if(it.size()>4 && it.substr(it.size()-4)==".jpg"){
                result+="Image is "+ it +"\n";
                //cout<<"Image: "<<it<<endl;
            }
            else{
                result+=it+"\n";
                //cout<<it<<endl;
            }
        }
        return result;
    }
    
    void savetofile(){
        ofstream file("document.txt");
        if(file.is_open()){
            file<<renderDoc();
            file.close();
        }
        else{
            throw runtime_error("file not opening");
        }
    }
};


int main() {
    doceditor docobj;
    docobj.addText("hello");
    docobj.addImage("this is image path.jpg");
    docobj.addText("hello");
    cout<<docobj.renderDoc();
    
    return 0;
}