#include <bits/stdc++.h>
using namespace std;

class Documents{
public:
    int doc_id;
    string doc_name;
    string doc_path;
    
    Documents(int doc_id  , string doc_name , string doc_path){
        this->doc_id = doc_id;
        this->doc_name = doc_name;
        this->doc_path = doc_path;
    }
};

class User{
public:
    vector<Documents*> docs;
    string email;
    int user_id;
    
    User(string email , int user_id){
        this->email = email;
        this->user_id = user_id
    }
    
    void create_document(Document* doc){
        docs.push_back(doc);
        cout<<"document added successfully"<<doc->doc_name<<endl;
    }
};

class SharedDoc{
 public:
    int doc_id;
};

int main() {
    User* kamal = new User()
    Documents* resume = new Documents(1,"resume","aws/resume/kamal.pdf");

    kamal->create_document(resume)
    return 0;
}    