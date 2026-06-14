#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include<map>
using namespace std;
struct Book {
    string id;
    string title;
    string author;
    string year;
    string rating;
};
int main() {
    ifstream file("books.txt");            //SORT BY TITLE AND RATING.                
    ofstream output("output.txt");          // 102|Introduction to Algorithms|CLRS|2020|4.9 
    if (!file) {                             // 103|Graph Theory Basics|Bondy|2017|4.2
        cerr << "File not found";            //101|Data Structures and Algorithms|Mark Weiss|2018|4.5
        return 0;
    }
    vector<Book> v;
    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string temp;
        Book b;
        getline(ss, b.id, '|');
        getline(ss, b.title, '|');
        getline(ss, b.author, '|');
        getline(ss, b.year, '|');
        getline(ss, b.rating, '|');
        v.push_back(b);
    }
    sort(v.begin(), v.end(), [](const Book &a, const Book &b) {     //CUSTOM COMPARATOR
    return a.title < b.title;
    });             
    for (auto &b : v) {
        cout<< b.title << " | "
             << b.id << " | "
             << b.author << " | "
             << b.year << " | "
             << b.rating << endl;
    }
    sort(v.begin(), v.end(), [](const Book &a, const Book &b) {
    return a.rating > b.rating;
    });
    cout<<endl;
    for (auto &b : v) {
        cout<< b.title << " | "
             << b.id << " | "
             << b.author << " | "
             << b.year << " | "
             << b.rating << endl;
    }
    //------------------------------------------------------//
    cout<<"enter substring:";    //1st pattern match
    string str;
    cin>>str;
    int p = str.size();
    for(int i=0;i<v.size();i++){
        string text;
        text = v[i].title;
        int t = text.size();

        for(int i=0;i<t-p+1;i++){
           string temp= text.substr(i,p);
           if(temp==str){
            cout<<text<<endl;
            break;
           }
        }
    }
    cout<<endl;
    cout<<"Enter ID:";
    string b_id;
    cin>>b_id;
    for(int i=0;i<v.size();i++){
        if(v[i].id==b_id) cout<<v[i].id<<" "<<v[i].title<<" "<<v[i].author<<" "<<v[i].rating<<" "<<v[i].year<<endl;
    }
     //----------------------------------//
    ifstream file2("citations.txt");       //RECOMENDATION LIST(Graph)
    int n= v.size(); //101 102  //101 103 //102 103
    vector<vector<int>>v2(n,vector<int>(n,0));
    string line2;
    while(getline(file2,line2)){
        stringstream ss(line2);
        int a,b;
        while(ss>>a>>b){
            int x = a-101; 
            int y = b-101;
            v2[x][y] = 1;  //adjacency
            v2[y][x] = 1;
        }
    }
    cout<<"WHICH BOOK DO YOU LIKE:\n";
    int id2;
    cin>>id2;
    int inx = id2-101;
    for(int i=0;i<v2[inx].size();i++){
        if(v2[inx][i]==1){
            cout<<101+i<<" ";
        }
    }
    //----------------------//
    cout<<"Enter 2 sentences:\n";  //LCS
    string sen1,sen2;
    cin>>sen1>>sen2;
    int s1 = sen1.size();
    int s2 = sen2.size();
    vector<vector<int>>lcs(s1+1,vector<int>(s2+1,0));
    for(int i=0;i<s1;i++){
        for(int j=0;j<s2;j++){
            if(sen1[i]==sen2[j]){
                lcs[i+1][j+1] = 1+lcs[i][j];
            }
            else{
                lcs[i+1][j+1] = max(lcs[i+1][j],lcs[i][j+1]);
            }
        }
    }
    cout<<lcs[s1][s2];
//------------//
    fstream file3("users.txt");  //HASTABLE
    unordered_map<string,string>mp;
    while(getline(file3,line)){
        stringstream ss(line);
        string num;
        string key,val;
        getline(ss,num,'|');
        getline(ss,key,'|');
        getline(ss,val,'|');
        mp[key]=val;
    }
    cout<<"Enter a key:\n";
    string ki;
    cin>>ki;
    cout<<mp[ki];
    return 0;
}
